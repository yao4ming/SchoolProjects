package scrambleClient;


import scrambleServer.CurrentBoard;
import javax.swing.*;
import java.awt.*;


/**
 * NEW
 * References the current state of the board for drawing
 */
public class CheckerboardCanvas extends JPanel {

    private static final int BOARD_BORDER = 5;		// width of the border around the board
    private static final int SQUARE_SIZE = 50;		// dimension of one square on the grid
    private static final int BOARD_SIZE = 8;        // dimension of board

    private static final int SQUARE_BORDER = 8;		// width of the border between a checker and its square
    private static final int DIAMETER = SQUARE_SIZE - (2 * SQUARE_BORDER);	// diamter of a checker-piece

    private static final int KING_RING = (int) SQUARE_BORDER/2;		// width of the "decorating ring" indicating a piece is a king

    private static final Color PLAYER_ONE = Color.GREEN;
    private static final Color PLAYER_TWO = Color.WHITE;
    private static final Color KING = Color.YELLOW;

    CurrentBoard board;     //ref to current state of board


    /**
     *	Creates the view background to white and takes in a observable(Subject) that the Canvas will register with
     */
    public CheckerboardCanvas(CurrentBoard board)
    {
        this.board = board;
        setBackground(Color.white);
        setSize(new Dimension(BOARD_SIZE*SQUARE_SIZE + 2*BOARD_BORDER,BOARD_SIZE*SQUARE_SIZE + 2*BOARD_BORDER));
        setMinimumSize(new Dimension(BOARD_SIZE*SQUARE_SIZE + 2*BOARD_BORDER,BOARD_SIZE*SQUARE_SIZE + 2*BOARD_BORDER));
    }

    /**
     * NEW
     * reinitalize board to the current state of board
     * repaints the view according to the current state of board
     */
    public void update(CurrentBoard board) {
        this.board = board;
        repaint();
    }

    /**
     * NEW
     *	Draws the checker board -- the 'major' method of this class
     *  Use the POJO from server for board data
     *	@param g the graphics object to draw with
     */
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);

        // Draw the board - Red & Black squares (top left corner is red)
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                //RED if both row and col are even or odd
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

        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {

                if (board.isOccupied()[row][col]) {

                    int x = BOARD_BORDER + (col * SQUARE_SIZE) + SQUARE_BORDER;
                    int y = BOARD_BORDER + (row * SQUARE_SIZE) + SQUARE_BORDER;		// find coordinates of top-left corner of checker-piece

                    if (board.isKing()[row][col]) {
                        g.setColor(KING);
                        g.fillOval(x-KING_RING, y-KING_RING, DIAMETER+(2*KING_RING), DIAMETER+(2*KING_RING));	// draw larger yellow circle to 'ring' the king
                    }

                    if (board.isPlayerOne()[row][col]) {
                        g.setColor(PLAYER_ONE);
                        g.fillOval(x, y, DIAMETER, DIAMETER);
                    }
                    else {
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


}
