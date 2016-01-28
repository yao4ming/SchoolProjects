package scrambleClient;

import javax.xml.bind.annotation.XmlRootElement;

/**
 * NEW
 * This is the object to be encoded and sent to the server
 * Contains starting pos (fromRow, fromCol) and ending pos (toRow, toCol) used by model
 */
@XmlRootElement (name="movemessage")
public class MoveMessage extends Message{
    int fromRow;
    int fromCol;
    int toRow;
    int toCol;
    int currentPlayer;

    public int getCurrentPlayer() {
        return currentPlayer;
    }

    public void setCurrentPlayer(int currentPlayer) {
        this.currentPlayer = currentPlayer;
    }

    public int getFromRow() {
        return fromRow;
    }

    public void setFromRow(int fromRow) {
        this.fromRow = fromRow;
    }

    public int getFromCol() {
        return fromCol;
    }

    public void setFromCol(int fromCol) {
        this.fromCol = fromCol;
    }

    public int getToRow() {
        return toRow;
    }

    public void setToRow(int toRow) {
        this.toRow = toRow;
    }

    public int getToCol() {
        return toCol;
    }

    public void setToCol(int toCol) {
        this.toCol = toCol;
    }
}
