package assignment4;

import java.util.ArrayList;
import static assignment4.Constants.*;


public class King extends Piece {
    King(Position position,Constants.PieceColor color){
        super(position,color);
    }

    @Override
    public char getMarker() {
        return 'K';
    }

    @Override
    public ArrayList<Move> getPossibleMoves(Board board) {
        ArrayList<Move> possibleMoves = new ArrayList<>();
        Piece[][] matrix = board.getUnderlyingMatrix();
        int currRow = this.getPosition().getRow();
        int currCol = this.getPosition().getCol();
        int size = board.getBoardSize();

        // check all 8 directions:
        if(currRow - 1 >=0 && currCol - 1 >=0){
            if(matrix[currRow-1][currCol-1] == null)
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow-1,currCol-1)));
            else if(getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[currRow-1][currCol-1].getColor()))
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow-1,currCol-1)));
        }
        if(currRow - 1 >=0){
            if(matrix[currRow-1][currCol] == null)
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow-1,currCol)));
            else if ((getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[currRow-1][currCol].getColor())))
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow-1,currCol)));
        }
        if(currRow - 1 >=0 && currCol + 1 <= board.getBoardSize()-1 ){
            if(matrix[currRow-1][currCol+1] == null)
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow-1,currCol+1)));
            else if(getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[currRow-1][currCol+1].getColor()))
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow-1,currCol+1)));
        }
        if(currCol - 1 >=0){
            if(matrix[currRow][currCol-1] == null)
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow,currCol-1)));
            else if(getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[currRow][currCol-1].getColor()))
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow,currCol-1)));
        }
        if(currCol + 1 <= board.getBoardSize()-1){
            if(matrix[currRow][currCol+1] == null)
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow,currCol+1)));
            else if (getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[currRow][currCol+1].getColor())) {
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow,currCol+1)));
            }
        }
        if(currRow + 1 <= board.getBoardSize()-1 && currCol - 1 >=0 ){
            if(matrix[currRow+1][currCol-1] == null)
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow+1,currCol-1)));
            else if (getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[currRow+1][currCol-1].getColor()))
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow+1,currCol-1)));
        }
        if(currRow + 1 <= board.getBoardSize() -1){
            if(matrix[currRow+1][currCol] == null)
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow+1,currCol)));
            else if (getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[currRow+1][currCol].getColor()))
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow+1,currCol)));
        }
        if(currRow + 1 <= board.getBoardSize() -1 && currCol + 1 <= board.getBoardSize()-1){
            if(matrix[currRow+1][currCol+1] == null)
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow+1,currCol+1)));
            else if (getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[currRow+1][currCol+1].getColor()))
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow+1,currCol+1)));
        }
        return possibleMoves;
    }

    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj instanceof King){
            King other = (King)obj;
            return getColorMarker(this.getColor()) == getColorMarker(other.getColor()) && other.getPosition().equals(this.getPosition());
        }
        return false;
    }
}
