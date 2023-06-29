package assignment4.toCopyFrom;
import static assignment4.Constants.*;

import java.util.ArrayList;

public class Board {
    private Piece[][] matrix;
    private ArrayList<Piece> BoardPieces;

    public Board() {
        this.matrix = new Piece[7][7];
        this.BoardPieces = new ArrayList<>();
    }

    public Board(int size) {
        this.matrix = new Piece[size][size];
        this.BoardPieces = new ArrayList<>();}

    public Board(Piece[][] board){
        this.BoardPieces = new ArrayList<>();
        this.matrix = new Piece[board.length][board.length];
        for(int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                this.matrix[i][j] = board[i][j];
                if(board[i][j] != null)
                    this.BoardPieces.add(board[i][j]);
            }
        }
    }

    private ArrayList<Piece> getBoardPieces() {return this.BoardPieces;}


    public ArrayList<Piece> getPieces(PieceColor pieceColor){
        ArrayList<Piece> res = new ArrayList<>();
        for(Piece piece : getBoardPieces())
            if(piece != null)
                if(piece.getColor().equals(pieceColor))
                    res.add(piece);
        return res;
    }

    public Piece getPiece(Position position){
        if(position.getRow() < 0 || position.getCol() < 0 || position.getRow() >= matrix.length || position.getCol() >= matrix.length)
            return null;
        Piece[][] matrix = this.getUnderlyingMatrix();
        if(matrix[position.getRow()][position.getCol()] != null)
            return matrix[position.getRow()][position.getCol()];
        return null;
    }

    public void addPiece(Piece piece){
        if(piece != null) {
            this.matrix[piece.getPosition().getRow()][piece.getPosition().getCol()] = piece;
            this.BoardPieces.add(piece);
        }
    }

    public void removePiece(Position position){
        int col = position.getCol();
        int row = position.getRow();
        Piece currPiece = this.matrix[row][col];

        // first remove the Piece from BoardPieces :
        if(currPiece == null)
            return;
        this.BoardPieces.remove(currPiece);

        // finally, remove the Piece from the board :
        this.matrix[row][col] = null;
    }

    public void updatePosition(Position oldPos, Position newPos){
        int oldRow = oldPos.getRow();
        int oldCol = oldPos.getCol();
        Piece currPiece = this.matrix[oldRow][oldCol];
        if(currPiece instanceof Tank)
            ((Tank) currPiece).setCooldown(((Tank) currPiece).getCooldown() -1);
        Piece toPiece = this.matrix[newPos.getRow()][newPos.getCol()];
        if(toPiece != null) {
            if (getColorMarker(toPiece.getColor()) != getColorMarker(currPiece.getColor())) {
                this.removePiece(newPos);
                this.matrix[newPos.getRow()][newPos.getCol()] = null;
            }
            else return; // if same color, can't move to newPos
        }
        currPiece.setPosition(newPos);

        this.matrix[oldRow][oldCol] = null;

        // update the Board as well :
        int newRow = newPos.getRow();
        int newCol = newPos.getCol();
        this.matrix[newRow][newCol] = currPiece;
        if(verifyPromotion(matrix[newRow][newCol]))
            promote(matrix[newRow][newCol]);
    }

    public int getPieceCount(PieceColor pieceColor){
        int counter = 0;
        ArrayList<Piece> pieces = getPieces(pieceColor);
        if(pieces.isEmpty())
            return 0;
        for(Piece piece : pieces)
            if(getColorMarker(piece.getColor()) == (getColorMarker(pieceColor)))
                counter++;
        return counter;
    }

    public boolean verifyPromotion(Piece piece){
        int col = piece.getPosition().getCol();
        int row = piece.getPosition().getRow();
        char pieceColor = getColorMarker(piece.getColor());
        if(!(piece instanceof Pawn))
            return false;
        if(pieceColor == 'W') {
            if (row == 0)
                return true;
            else
                return false;
        }
        // else, color is Black :
        if(row == this.matrix.length -1 )
            return true;
        else
            return false;
    }

    public void promote(Piece piece){
        if (verifyPromotion(piece)){
            Position position = piece.getPosition();
            PieceColor pieceColor = piece.getColor();;
            BoardPieces.remove(piece);
            piece = new Tank(position,pieceColor);
            matrix[position.getRow()][position.getCol()] = piece;
            BoardPieces.add(piece);
        }
        else throw new IllegalArgumentException();
    }

    public int getBoardSize() {return getUnderlyingMatrix().length;}

    @Override
    public boolean equals(Object obj){
        if(obj == null)
            return false;
        if(this == obj)
            return true;
        if(!(obj instanceof Board))
            return false;
        Board tempBoard =(Board) (obj);
        Piece[][] other = tempBoard.getUnderlyingMatrix();
        if(matrix.length != other.length || matrix[0].length != other[0].length) return false;
        int size = matrix.length;
        int _size = matrix[0].length;
        for(int i = 0; i < size; i++)
            for(int j = 0; j < _size; j++) {
                if(matrix[i][j] == null && other[i][j] != null)
                    return false;
                if(matrix[i][j] != null && other[i][j] == null)
                    return false;
                if(matrix[i][j] == null && other[i][j] == null)
                    continue;
                if (!matrix[i][j].equals(other[i][j]))
                    return false;
            }
        return true;
    }

    public Piece[][] getUnderlyingMatrix() {
        return this.matrix;
    }
}
