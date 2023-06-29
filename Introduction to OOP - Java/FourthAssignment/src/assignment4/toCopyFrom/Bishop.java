package assignment4.toCopyFrom;
import static assignment4.Constants.*;
import java.util.ArrayList;

public class Bishop extends Piece{
    Bishop(Position position, Constants.PieceColor color) {super(position, color);}

    @Override
    public char getMarker() {return 'B';}

    @Override
    public ArrayList<Move> getPossibleMoves(Board board) {
        ArrayList<Move> possibleMoves = new ArrayList<>();
        Piece[][] matrix = board.getUnderlyingMatrix();
        int currRow = this.getPosition().getRow();
        int currCol = this.getPosition().getCol();
        int size = board.getBoardSize();

        // get left upper slant moves:
        int _currRow = currRow, _currCol = currCol;
        while (true) {
            if (_currCol - 1 >= 0 && _currRow - 1 >= 0) {
                if (matrix[_currRow - 1][_currCol - 1] == null) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(_currRow - 1, _currCol - 1)));
                    _currRow--;
                    _currCol--;
                } else if (getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[_currRow - 1][_currCol - 1].getColor())) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(_currRow - 1, _currCol - 1)));
                    break; // cant keep adding
                } else break;
            } else break;
        }
        // left downwards slant moves:
        _currRow = currRow;
        _currCol = currCol;
        while (true) {
            if (_currRow + 1 <= board.getBoardSize() - 1 && _currCol - 1 >= 0) {
                if (matrix[_currRow + 1][_currCol - 1] == null) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(_currRow + 1, _currCol - 1)));
                    _currRow++;
                    _currCol--;
                } else if (getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[_currRow + 1][_currCol - 1].getColor())) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(_currRow + 1, _currCol - 1)));
                    break;
                } else break;
            } else break;
        }
        // right upwards slant moves:
        _currRow = currRow;
        _currCol = currCol;
        while (true) {
            if (_currRow - 1 >= 0 && _currCol + 1 <= board.getBoardSize() - 1) {
                if (matrix[_currRow - 1][_currCol + 1] == null) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(_currRow - 1, _currCol + 1)));
                    _currRow--;
                    _currCol++;
                } else if (getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[_currRow - 1][_currCol + 1].getColor())) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(_currRow - 1, _currCol + 1)));
                    break;
                } else break;
            } else break;
        }
        // right downward slant moves:
        _currRow = currRow;
        _currCol = currCol;
        while (true) {
            if (_currRow + 1 <= board.getBoardSize() - 1 && _currCol + 1 <= board.getBoardSize() - 1) {
                if (matrix[_currRow + 1][_currCol + 1] == null) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(_currRow + 1, _currCol + 1)));
                    _currRow++;
                    _currCol++;
                } else if (getColorMarker(matrix[currRow][currCol].getColor()) != getColorMarker(matrix[_currRow + 1][_currCol + 1].getColor())) {
                    possibleMoves.add(new Move(this.getPosition(), new Position(_currRow + 1, _currCol + 1)));
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
