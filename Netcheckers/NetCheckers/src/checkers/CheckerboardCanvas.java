package checkers;

import java.awt.*;
import java.util.Observable;
import java.util.Observer;

import javax.swing.JPanel;

/**
*
*This class implements a graphical view of a checkerboard. When its model is changed, it should be notified.
*
 */

public class CheckerboardCanvas extends JPanel implements Observer{

	private CheckerBoard model;

	private static final int BOARD_BORDER = 5;		// width of the border around the board
	private static final int SQUARE_SIZE = 50;		// dimension of one square on the grid

	private static final int SQUARE_BORDER = 8;		// width of the border between a checker and its square 
	private static final int DIAMETER = SQUARE_SIZE - (2 * SQUARE_BORDER);	// diamter of a checker-piece

	private static final int KING_RING = (int) SQUARE_BORDER/2;		// width of the "decorating ring" indicating a piece is a king

	private static final Color PLAYER_ONE = Color.GREEN;
	private static final Color PLAYER_TWO = Color.WHITE;
	private static final Color KING = Color.YELLOW;

	/**
	 *	Creates the view background to white
	 */
	public CheckerboardCanvas(CheckerBoard board)
	{
        this.model = board;
        model.addObserver(this);
		setBackground(Color.white);
		setSize(new Dimension(CheckerBoard.BOARD_SIZE*SQUARE_SIZE + 2*BOARD_BORDER,CheckerBoard.BOARD_SIZE*SQUARE_SIZE + 2*BOARD_BORDER));
		setMinimumSize(new Dimension(CheckerBoard.BOARD_SIZE*SQUARE_SIZE + 2*BOARD_BORDER,CheckerBoard.BOARD_SIZE*SQUARE_SIZE + 2*BOARD_BORDER));
		
	}

	/**
	 *	Draws the checker board -- the 'major' method of this class
	 *	@param g the graphics object to draw with
	 */
	public void paintComponent(Graphics g)
	{
        //delegate paint
		super.paintComponent(g);

		// Draw the board - Red & Black squares (top left corner is red)
		for (int row = 0; row < CheckerBoard.BOARD_SIZE; row++) {
			for (int col = 0; col < CheckerBoard.BOARD_SIZE; col++) {

				if ((row % 2 == 0 && col % 2 == 0) || (row % 2 != 0 && col % 2 != 0))
					g.setColor(Color.red);
				else
					g.setColor(Color.black);

				g.fillRect(BOARD_BORDER + (col * SQUARE_SIZE), 
						BOARD_BORDER + (row * SQUARE_SIZE), 
						SQUARE_SIZE, SQUARE_SIZE);
			}
		}

		// Draw the pieces wherever they are

		for (int row = 0; row < CheckerBoard.BOARD_SIZE; row++) {
			for (int col = 0; col < CheckerBoard.BOARD_SIZE; col++) {
                if (model.squareIsOccupied(row, col)) {

                    int x = BOARD_BORDER + (col * SQUARE_SIZE) + SQUARE_BORDER;
                    int y = BOARD_BORDER + (row * SQUARE_SIZE) + SQUARE_BORDER;        // find coordinates of top-left corner of checker-piece

                    if (model.squareHoldsKing(row, col)) {
                        g.setColor(KING);
                        g.fillOval(x - KING_RING, y - KING_RING, DIAMETER + (2 * KING_RING), DIAMETER + (2 * KING_RING));    // draw larger yellow circle to 'ring' the king
                    }
                    if (model.isPlayerOne(row, col)) {
                        g.setColor(PLAYER_ONE);
                        g.fillOval(x, y, DIAMETER, DIAMETER);

                    } else {
                        g.setColor(PLAYER_TWO);
                        g.fillOval(x, y, DIAMETER, DIAMETER);
                    }
                }
            }
		}
	}

	/**
	 *	Returns the grid row location knowing the pixel location within the board
	 *	@param rowPixels number of pixels down in the window
	 *	@return returns the checkerboard square row
	 */
	public int getRow(int rowPixels)
	{
		rowPixels -= BOARD_BORDER;
//		System.err.println("rowpixels  " + rowPixels);	// DEBUG
		return rowPixels / SQUARE_SIZE;
	}

	/**
	 *	Returns the grid column location knowing the pixel location within the board
	 *	@param colPixels number of pixels across in the window
	 *	@returns the checkerboard square column
	 */
	public int getCol(int colPixels)
	{
		colPixels -= BOARD_BORDER;
//		System.err.println("colpixels " + colPixels);	// DEBUG
		return colPixels / SQUARE_SIZE;
	}

    @Override
    public void update(Observable o, Object arg) {
        if(o instanceof CheckerBoard) repaint();
    }
}


