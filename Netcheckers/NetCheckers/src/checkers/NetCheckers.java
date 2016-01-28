package checkers;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;


public class NetCheckers extends JFrame implements MouseListener {

	private CheckerboardCanvas cbCanvas; //reference to view
	private CheckerBoard board;          //reference to model
	private int canvasTopInset;			// distance Canvas is placed from the top

	private int fromRow, fromCol;		// Where the checker is moving from

	private int currentPlayer;			// id of the current player

	public NetCheckers() {

		super("NetCheckers");
		setSize(450,450);
		setResizable(false);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(EXIT_ON_CLOSE);

        board = new CheckerBoard();
        cbCanvas = new CheckerboardCanvas(board);
        add(cbCanvas);
        addMouseListener(this);

		currentPlayer=Square.PlayerOne;
		setTitle("Player One's Turn");

		setVisible(true);
		canvasTopInset = getInsets().top;

	}

	/**
	Gets the pixel location of the mouse click and turns it into the
	row and column in the grid of the checker location.
	@param e the mouse event that just occurred
	 */
	public void mousePressed(MouseEvent e)
	{
		fromRow = cbCanvas.getRow(e.getY()-canvasTopInset);	// need to be very precise about location of mouse; this accounts for the header/titlebar
		fromCol = cbCanvas.getCol(e.getX());
	}

	/**

	Attempts to move piece from mouse-press location to mouse-release location. If the move is valid, 
	advances the game.

	@param e the mouse event that just occurred
	 */

	public void mouseReleased(MouseEvent e) {

		int toRow = cbCanvas.getRow(e.getY()-canvasTopInset); // adjust coordinates to account for the checkerboard's location
		int toCol = cbCanvas.getCol(e.getX());


        //manipulate model data
		if (board.canMoveFrom(currentPlayer,fromRow,fromCol)) { //if move is possible
            System.err.println("Mouse Pressed: " + fromRow + "-" + fromCol);
            System.err.println("Mouse Released: " + toRow + "-" + toCol);
			if (board.move(fromRow, fromCol, toRow, toCol)) {		// if the move was successful

                //test if double jump is possible and set it accordingly
                //change the player if multiple jumps not possible
                if(board.canDoubleJump(toRow, toCol))
                    board.DOUBLEJUMP = true;
                else {
                    currentPlayer = (currentPlayer == Square.PlayerOne) ? Square.PlayerTwo : Square.PlayerOne;
                    board.DOUBLEJUMP = false;
                }

				if (board.gameOver()) {
					setTitle("Game over");
				} else {
					if (currentPlayer == Square.PlayerOne)
						setTitle("Player One's move");
					else
						setTitle("Player Two's move");
				}
			}
		}
        else
            System.out.println("Not your turn or invalid move");
    }


	// not used
	public void mouseDragged(MouseEvent e) {}
	public void mouseEntered(MouseEvent e) {}
	public void mouseExited(MouseEvent e) {}
	public void mouseClicked(MouseEvent e) {}
	public void mouseMoved(MouseEvent e) {}

/**
 * Run the game
 * @param args Unused.
 */

	public static void main(String[] args) {

		EventQueue.invokeLater(
				new Runnable() {
					@Override
					public void run() {
						NetCheckers game = new NetCheckers();

					}
				});
	}
}