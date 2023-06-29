package assignment4;

import java.util.ArrayList;
import static assignment4.Constants.*;


public class Knight extends Piece {
    Knight(Position position,Constants.PieceColor color){
        super(position,color);
    }

    @Override
    public char getMarker() {
        return 'N';
    }

    @Override
    public ArrayList<Move> getPossibleMoves(Board board) {
        ArrayList<Move> possibleMoves = new ArrayList<>();
        Piece[][] matrix = board.getUnderlyingMatrix();
        int currRow = this.getPosition().getRow();
        int currCol = this.getPosition().getCol();
        int size = board.getBoardSize();

        // check every 8 possible routes :
        if(currRow - 2 >=0 && currCol - 1 >= 0){
            if(matrix[currRow- 2][currCol -1] == null)
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow -2, currCol -1)));
            else if (getColorMarker(this.getColor()) != getColorMarker(matrix[currRow -2][currCol -1].getColor()))
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow -2, currCol -1)));
        }
        if(currRow - 2 >=0 && currCol + 1 <= board.getBoardSize() -1){
            if(matrix[currRow- 2][currCol +1] == null)
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow -2, currCol +1)));
            else if (getColorMarker(this.getColor()) != getColorMarker(matrix[currRow -2][currCol +1].getColor()))
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow -2, currCol +1)));
        }
        if(currRow - 1 >=0 && currCol + 2 <= board.getBoardSize() -1){
            if(matrix[currRow- 1][currCol +2] == null)
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow -1, currCol +2)));
            else if (getColorMarker(this.getColor()) != getColorMarker(matrix[currRow -1][currCol +2].getColor()))
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow -1, currCol +2)));
        }
        if(currRow +1 <= board.getBoardSize() -1 && currCol +2 <= board.getBoardSize() -1){
            if(matrix[currRow +1][currCol +2] == null)
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow +1, currCol +2)));
            else if (getColorMarker(this.getColor()) != getColorMarker(matrix[currRow +1][currCol +2].getColor()))
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow +1, currCol +2)));
        }
        if(currRow +2 <= board.getBoardSize() -1 && currCol +1 <= board.getBoardSize() -1){
            if(matrix[currRow +2][currCol +1] == null)
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow +2, currCol +1)));
            else if (getColorMarker(this.getColor()) != getColorMarker(matrix[currRow +2][currCol +1].getColor()))
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow +2, currCol +1)));
        }
        if(currRow +2 <= board.getBoardSize() -1 && currCol - 1 >= 0){
            if(matrix[currRow +2][currCol -1] == null)
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow +2, currCol -1)));
            else if (getColorMarker(this.getColor()) != getColorMarker(matrix[currRow +2][currCol -1].getColor()))
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow +2, currCol -1)));
        }
        if(currRow +1 <= board.getBoardSize() -1 && currCol -2 >= 0){
            if(matrix[currRow +1][currCol -2] == null)
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow +1, currCol -2)));
            else if (getColorMarker(this.getColor()) != getColorMarker(matrix[currRow +1][currCol -2].getColor()))
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow +1, currCol -2)));
        }
        if(currRow -1 >= 0 && currCol -2 >= 0){
            if(matrix[currRow -1][currCol -2] == null)
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow -1, currCol -2)));
            else if (getColorMarker(this.getColor()) != getColorMarker(matrix[currRow -1][currCol -2].getColor()))
                possibleMoves.add(new Move(this.getPosition(),new Position(currRow -1, currCol -2)));
        }
        return possibleMoves;
    }

    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj instanceof Knight){
            Knight other = (Knight) obj;
            return getColorMarker(this.getColor()) == getColorMarker(other.getColor()) && other.getPosition().equals(this.getPosition());
        }
        return false;
    }
}
