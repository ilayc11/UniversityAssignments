package assignment4.toCopyFrom;
import static assignment4.Constants.*;
import java.util.ArrayList;

public class Pawn extends Piece {

    Pawn(Position position, Constants.PieceColor color) {
        super(position, color);
    }

    @Override
    public char getMarker() {
        return 'P';
    }

    @Override
    public ArrayList<Move> getPossibleMoves(Board board) {
        Move upwards, downwards, leftSlant, rightSlant;
        ArrayList<Move> possibleMoves = new ArrayList<>();
        Piece[][] matrix = board.getUnderlyingMatrix();
        Position currPosition = this.getPosition();
        int currRow = currPosition.getRow();
        int currCol = currPosition.getCol();
        if (getColorMarker(this.getColor()) == 'W') {
            if (currRow == 0) return possibleMoves;
            else { // move can be done
                if(currRow - 1 >= 0) {
                    if (matrix[currRow - 1][currCol] == null) {
                        upwards = new Move(currPosition, new Position(currRow - 1, currCol));
                        possibleMoves.add(upwards);
                    }
                }
                if (currCol - 1 >= 0 && currRow -1 >=0) {
                    if (matrix[currRow - 1][currCol - 1] != null)
                        if (getColorMarker(matrix[currRow - 1][currCol - 1].getColor()) == 'B') {
                        leftSlant = new Move(currPosition, new Position(currRow - 1, currCol - 1));
                        possibleMoves.add(leftSlant);
                    }
                }
                if (currCol + 1 <= board.getBoardSize() - 1 && currRow -1 >= 0) {
                    if (matrix[currRow - 1][currCol + 1] != null)
                        if (getColorMarker(matrix[currRow - 1][currCol + 1].getColor()) == 'B') {
                        rightSlant = new Move(currPosition, new Position(currRow - 1, currCol + 1));
                        possibleMoves.add(rightSlant);
                    }
                }
            }
            return possibleMoves;
        }
        // in case color is Black :
        if (currRow == matrix.length - 1) return possibleMoves;
        else { // move can be done
            if(currRow + 1 <= board.getBoardSize()-1) {
                if (matrix[currRow + 1][currCol] == null) {
                    downwards = new Move(currPosition, new Position(currRow + 1, currCol));
                    possibleMoves.add(downwards);

                }
            }
            if (currCol - 1 >= 0 && currRow + 1 <= board.getBoardSize() -1) {
                if (matrix[currRow + 1][currCol - 1] != null)
                    if (getColorMarker(matrix[currRow + 1][currCol - 1].getColor()) == 'W' ) {
                        leftSlant = new Move(currPosition, new Position(currRow + 1, currCol - 1));
                        possibleMoves.add(leftSlant);
                    }
            }
            if (currCol + 1 <= board.getBoardSize() - 1 && currRow + 1 <= board.getBoardSize() -1) {
                if (matrix[currRow + 1][currCol + 1] != null)
                    if (getColorMarker(matrix[currRow + 1][currCol + 1].getColor()) == 'W') {
                        rightSlant = new Move(currPosition, new Position(currRow + 1, currCol + 1));
                        possibleMoves.add(rightSlant);
                    }
            }
        }
        return possibleMoves;
    }

    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj instanceof Pawn){
            Pawn other = (Pawn) obj;
            return getColorMarker(other.getColor()) == getColorMarker(this.getColor()) && other.getPosition().equals(this.getPosition());
        }
    return false;
    }
}



