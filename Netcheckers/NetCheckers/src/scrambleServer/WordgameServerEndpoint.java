package scrambleServer;

import scrambleClient.Message;
import scrambleClient.MoveMessage;

import java.io.IOException;
import java.util.logging.Logger;

import javax.websocket.*;
import javax.websocket.server.ServerEndpoint;

/**
 * NEW
 * Receive connections from clients
 * Handle communication with clients
 * Detect connection close
 * Multiple instances for multiple connections
 */
@ServerEndpoint(value = "/game",
        encoders = {CurrentBoardEncoder.class},
        decoders = {MessageDecoder.class})
public class WordgameServerEndpoint {
 
    private Logger logger = Logger.getLogger(this.getClass().getName());
    CheckerModel model;             //game data
    CurrentBoard currentBoard;      //data to be encoded and sent to client
    static int numOfClients = 0;

    /**
     * NEW
     * Counts the number of client connections
     * Instantiate model and starting board
     * Send client starting board
     * @param session
     * @throws IOException
     * @throws EncodeException
     */
    @OnOpen
    public void onOpen(Session session) throws IOException, EncodeException {
        numOfClients++;
        logger.info("Connected ... " + session.getId());
        logger.info("Connection to " + numOfClients + " client");

        model = new CheckerModel();
        currentBoard = new CurrentBoard();

        session.getBasicRemote().sendObject(board());
        //is client player one or two
//        switch (numOfClients){
//            case 1:
//                currentBoard.setCurrentPlayer(1);
//                break;
//            case 2:
//                currentBoard.setCurrentPlayer(2);
//                break;
//            default:
//                currentBoard.setCurrentPlayer(0);
//        }

    }
 
    @OnMessage
    public CurrentBoard onMessage(Message message, Session session) throws IOException, EncodeException {
        if(message instanceof MoveMessage){

            //obtain client data
            int currentPlayer = ((MoveMessage) message).getCurrentPlayer();
            int fromRow = ((MoveMessage) message).getFromRow();
            int fromCol = ((MoveMessage) message).getFromCol();
            int toRow = ((MoveMessage) message).getToRow();
            int toCol = ((MoveMessage) message).getToCol();

            if(model.canMoveFrom(currentPlayer, fromRow, fromCol)){     //if move was possible
                if(model.move(fromRow, fromCol, toRow, toCol)) {          //if move was successful

                    //test if double jump is possible and set it accordingly
                    if(model.canDoubleJump(toRow, toCol))
                        model.canDoubleJump = true;
                    else
                        model.canDoubleJump = false;

                    if(model.gameOver())
                        currentBoard.setGameOver(true);
                    currentBoard.setMoved(true);
                    return board();
                }
                System.out.println("did not move");
            }
            currentBoard.setMoved(false);
        }
        return board();

    }
 
    @OnClose
    public void onClose(Session session, CloseReason closeReason) {
        logger.info(String.format("Session %s closed because of %s", session.getId(), closeReason));
        numOfClients--;
    }

    /**
     * NEW
     * Initalize POJO with current state of board and send to client
     * @return current state of board
     * @throws IOException
     * @throws EncodeException
     */
    private CurrentBoard board() throws IOException, EncodeException {

        //obtain current board state to init POJO
        boolean[][] player = new boolean[model.BOARD_SIZE][model.BOARD_SIZE];
        boolean[][] occupied = new boolean[model.BOARD_SIZE][model.BOARD_SIZE];
        boolean[][] king = new boolean[model.BOARD_SIZE][model.BOARD_SIZE];
        for(int row = 0; row < model.getBoard().length; row++){
            for(int col = 0; col < model.getBoard()[row].length; col++) {
                player[row][col] = model.isPlayerOne(row, col);
                occupied[row][col] = model.squareIsOccupied(row, col);
                king[row][col] = model.squareHoldsKing(row,col);
            }
        }
        currentBoard.setDoubleJump(model.canDoubleJump);
        currentBoard.setPlayerOne(player);
        currentBoard.setKing(king);
        currentBoard.setOccupied(occupied);
        return currentBoard;
    }

}