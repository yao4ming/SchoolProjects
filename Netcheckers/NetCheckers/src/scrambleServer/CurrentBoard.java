package scrambleServer;

import javax.xml.bind.annotation.XmlRootElement;

/**
 *  NEW
 *  POJO representing necessary data to represent current state of board
 */
@XmlRootElement(name = "currentboard")
public class CurrentBoard {
    boolean moved;
    boolean gameOver;
    boolean doubleJump;

    public boolean isDoubleJump() {
        return doubleJump;
    }

    public void setDoubleJump(boolean doubleJump) {
        this.doubleJump = doubleJump;
    }

    int currentPlayer;
    boolean[][] occupied;
    boolean[][] playerOne;
    boolean[][] king;

    public boolean[][] isPlayerOne() {
        return playerOne;
    }

    public void setPlayerOne(boolean[][] playerOne) {
        this.playerOne = playerOne;
    }

    public boolean[][] isOccupied() {
        return occupied;
    }

    public void setOccupied(boolean[][] occupied) {
        this.occupied = occupied;
    }

    public boolean[][] isKing() {
        return king;
    }

    public void setKing(boolean[][] king) {
        this.king = king;
    }

    public int getCurrentPlayer() {
        return currentPlayer;
    }

    public void setCurrentPlayer(int currentPlayer) {
        this.currentPlayer = currentPlayer;
    }

    public boolean isGameOver() {
        return gameOver;
    }

    public void setGameOver(boolean gameOver) {
        this.gameOver = gameOver;
    }

    public boolean isMoved() {
        return moved;
    }

    public void setMoved(boolean moved) {
        this.moved = moved;
    }

}
