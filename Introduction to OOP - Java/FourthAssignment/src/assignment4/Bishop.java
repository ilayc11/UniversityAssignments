package assignment4;
import static assignment4.Constants.*;

import java.util.ArrayList;

public class Bishop extends Piece {
    Bishop(Position position,Constants.PieceColor color){
        super(position,color);
    }

    @Override
    public char getMarker() {
        return 'B';
    }

    @Override
    public ArrayList<Move> getPossibleMoves(Board board) {
        ArrayList<Move> possibleMoves = new ArrayList<>();
        Piece[][] matrix = board.getUnderlyingMatrix();
        int currRow = this.getPosition().getRow();
        int currCol = this.getPosition().getCol();
        int size = board.getBoardSize();

        int currRow2 = currRow, currCol2 = currCol;
        while (true) {
            if (currCol2 - 1 >= 0 && currRow2 - 1 >= 0) {
                if (matrix[currRow2 - 1][currCol2 - 1] == null) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(currRow2 - 1, currCol2 - 1)));
                    currRow2--;
                    currCol2--;
                } else if (getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[currRow2 - 1][currCol2 - 1].getColor())) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(currRow2 - 1, currCol2 - 1)));
                    break;
                } else break;
            } else break;
        }
        currRow2 = currRow;
        currCol2 = currCol;
        while (true) {
            if (currRow2 + 1 <= board.getBoardSize() - 1 && currCol2 - 1 >= 0) {
                if (matrix[currRow2 + 1][currCol2 - 1] == null) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(currRow2 + 1, currCol2 - 1)));
                    currRow2++;
                    currCol2--;
                } else if (getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[currRow2 + 1][currCol2 - 1].getColor())) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(currRow2 + 1, currCol2 - 1)));
                    break;
                } else break;
            } else break;
        }
        currRow2 = currRow;
        currCol2 = currCol;
        while (true) {
            if (currRow2 - 1 >= 0 && currCol2 + 1 <= board.getBoardSize() - 1) {
                if (matrix[currRow2 - 1][currCol2 + 1] == null) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(currRow2 - 1, currCol2 + 1)));
                    currRow2--;
                    currCol2++;
                } else if (getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[currRow2 - 1][currCol2 + 1].getColor())) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(currRow2 - 1, currCol2 + 1)));
                    break;
                } else break;
            } else break;
        }
        currRow2 = currRow;
        currCol2 = currCol;
        while (true) {
            if (currRow2 + 1 <= board.getBoardSize() - 1 && currCol2 + 1 <= board.getBoardSize() - 1) {
                if (matrix[currRow2 + 1][currCol2 + 1] == null) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(currRow2 + 1, currCol2 + 1)));
                    currRow2++;
                    currCol2++;
                } else if (getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[currRow2 + 1][currCol2 + 1].getColor())) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(currRow2 + 1, currCol2 + 1)));
                    break;
                } else break;
            } else break;
        }
        return possibleMoves;
    }

    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj instanceof Bishop){
            Bishop other = (Bishop) obj;
            return getColorMarker(other.getColor()) == getColorMarker(this.getColor()) && this.getPosition().equals(other.getPosition());
        }
        return false;
    }
}
