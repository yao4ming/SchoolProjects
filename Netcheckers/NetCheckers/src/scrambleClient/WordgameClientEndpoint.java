package scrambleClient;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.*;
import java.util.concurrent.CountDownLatch;
import java.util.logging.Logger;
import java.net.URI;
import java.net.URISyntaxException;

import javax.swing.*;
import javax.websocket.*;

import org.glassfish.tyrus.client.ClientManager;
import scrambleServer.CurrentBoard;


/**
 * NEW
 * Client is a window that contains the view and listens for user action
 * Client connects to server endpoint using websocket protocol
 * Once connection has been established client obtains a reference to the session
 * Listen for user click and release coordinates
 * After obtaining release location, init POJO with that data and send to server
 * Once a message has been received (if firstmessage, init view)
 * use POJO sent by server to check move was successful
 * if successful update view and change player turn if double jump is not possible
 */
@ClientEndpoint(encoders = {MoveMessageEncoder.class}, decoders = {BoardDecoder.class})
public class WordgameClientEndpoint extends JFrame implements MouseListener{
 
    private static CountDownLatch latch;
    private Logger logger = Logger.getLogger(this.getClass().getName());

    private CheckerboardCanvas cbCanvas;    //reference to view
    private int canvasTopInset;			// distance Canvas is placed from the top
    MoveMessage move;                    //obj to be encoded and sent to server

    Session currSession;            //ref to current connection to server, used to send message to server

    private int currentPlayer;
    private int PLAYER1 = 1;
    private int PLAYER2 = 2;
    boolean firstMessage = true;    //used as flag to init board

    /**
     * NEW
     * Set up window
     * @param board - current state of board used to init view
     */
    public void init(CurrentBoard board) {
        setSize(420,450);
        setResizable(false);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);


        cbCanvas = new CheckerboardCanvas(board);   //pass board data to view
        add(cbCanvas);  //add checkboard to window

        move = new MoveMessage();   //obj to hold starting and ending pos of moving piece

        addMouseListener(this); //add myself as mouselistner

        currentPlayer = PLAYER1;
        move.setCurrentPlayer(currentPlayer);
        setTitle("Player One's Turn");

        setVisible(true);
        canvasTopInset = getInsets().top;

    }
    @OnOpen
    public void onOpen(Session session) {
        logger.info("Connected ... " + session.getId());
        currSession = session;
    }

    /**
     * NEW
     * called every time server sends a message
     * if first message initalize starting view
     * else if move was successful update view and game state accordingly
     * @param board - - current state of board used to update view
     * @param session - current condition
     */
    @OnMessage
    public void onMessage(CurrentBoard board, Session session) {
        if(firstMessage){
            init(board);
            firstMessage = false;
        }
        else{
            if(board.isMoved()) {       //move was successful
                cbCanvas.update(board);     //update view

                //change player turn if multiple jumps arent possible
                if(!board.isDoubleJump()) {
                    currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
                    move.setCurrentPlayer(currentPlayer);
                }

                if (board.isGameOver()) {
                    setTitle("Game over");
                } else {
                    if (currentPlayer == PLAYER1)
                        setTitle("Player One's move");
                    else
                        setTitle("Player Two's move");
                }
            }
            else
                logger.info("Move unsuccessful");
        }

    }
 
    @OnClose
    public void onClose(Session session, CloseReason closeReason) {
        logger.info(String.format("Session %s close because of %s", session.getId(), closeReason));
        latch.countDown();
    }

    /**
     * NEW
     * init POJO with mouse pressed x,y coordinates
     * @param e
     */
    @Override
    public void mousePressed(MouseEvent e) {
        int fromRow = cbCanvas.getRow(e.getY()-canvasTopInset);	// need to be very precise about location of mouse; this accounts for the header/titlebar
        int fromCol = cbCanvas.getCol(e.getX());
        move.setFromCol(fromCol);   //set fromCol pos
        move.setFromRow(fromRow);   //set fromRow pos
        System.err.println("Mouse Pressed: " + fromRow + "-" + fromCol);
    }

    /**
     * NEW
     * init POJO with mouse release x,y coordinates
     * send POJO to server
     * @param e
     */
    @Override
    public void mouseReleased(MouseEvent e) {
        int toRow = cbCanvas.getRow(e.getY()-canvasTopInset);
        int toCol = cbCanvas.getCol(e.getX());
        move.setToRow(toRow);
        move.setToCol(toCol);
        System.err.println("Mouse Released: " + toRow + "-" + toCol);
        //notify server of user action
        sendMove();
    }

    public void sendMove() {
        try {
            currSession.getBasicRemote().sendObject(move);
        } catch (IOException e1) {
            e1.printStackTrace();
        } catch (EncodeException e1) {
            System.out.println("encode error");
        }
    }


    public void mouseClicked(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}

    public static void main(String[] args) {
        latch = new CountDownLatch(1);
 
        ClientManager client = ClientManager.createClient();
        try {
            client.connectToServer(WordgameClientEndpoint.class, new URI("ws://localhost:8025/websockets/game"));
            latch.await();
 
        } catch (DeploymentException| URISyntaxException | InterruptedException | IOException  e) {
            throw new RuntimeException(e);
        }
    }
}

