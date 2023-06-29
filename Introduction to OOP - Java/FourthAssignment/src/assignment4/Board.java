package assignment4;

import java.util.ArrayList;
import java.util.Arrays;
import static assignment4.Constants.*;

public class Board {
    private Piece[][] matrix;
    ArrayList<Piece> pieceArrayList;

    public Board(){
        this.matrix=new Piece[7][7];
        pieceArrayList=new ArrayList<>();

    }

    public Board(int size){
        this.matrix=new Piece[size][size];
        pieceArrayList=new ArrayList<>();
    }

    public Board(Piece[][]board){
        this.matrix=new Piece[board.length][board[0].length];
        pieceArrayList=new ArrayList<>();
        for(int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                this.matrix[i][j] = board[i][j];
                if(board[i][j] != null)
                    this.pieceArrayList.add(board[i][j]);
            }
        }
    }
    public ArrayList<Piece> getPieces(PieceColor color){
        ArrayList<Piece> rtrnList=new ArrayList<>();
        for(Piece i:pieceArrayList)
            if(i!=null)
                if(i.getColor().equals(color))
                    rtrnList.add(i);
        return rtrnList;
    }
    public Piece getPiece(Position position){
        if(position.getCol()>=matrix.length||position.getCol()<0)
            return null;
        if(position.getRow()>=matrix.length||position.getRow()<0)
            return null;
        if(matrix[position.getRow()][position.getCol()] != null)
            return matrix[position.getRow()][position.getCol()];
        return null;
    }
    public void addPiece(Piece piece){
        if(piece != null) {
            this.matrix[piece.getPosition().getRow()][piece.getPosition().getCol()] = piece;
            this.pieceArrayList.add(piece);
        }
    }
    public void removePiece(Position position){
        Piece tmp=matrix[position.getRow()][position.getCol()];
        if(tmp==null)
            return;
        matrix[position.getRow()][position.getCol()]=null;
        pieceArrayList.remove(tmp);
    }
    public void updatePosition(Position oldPos,Position newPos){
        int oldRow = oldPos.getRow();
        int oldCol = oldPos.getCol();
        Piece tmp = this.matrix[oldPos.getRow()][oldPos.getCol()];
        if(tmp instanceof Tank)
            ((Tank) tmp).setCooldown(((Tank) tmp).getCooldown() -1);
        Piece toPiece = this.matrix[newPos.getRow()][newPos.getCol()];
        if(toPiece != null) {
            if (getColorMarker(toPiece.getColor()) != getColorMarker(tmp.getColor())) {
                this.removePiece(newPos);
                this.matrix[newPos.getRow()][newPos.getCol()] = null;
            }
            else return;
        }
        tmp.setPosition(newPos);

        this.matrix[oldRow][oldCol] = null;
        this.matrix[newPos.getRow()][newPos.getCol()] = tmp;
        if(verifyPromotion(matrix[newPos.getRow()][newPos.getCol()]))
            promote(matrix[newPos.getRow()][newPos.getCol()]);
    }
    public int getPieceCount(PieceColor pieceColor){
       return getPieces(pieceColor).size();
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
        if(row == this.matrix.length -1 )
            return true;
        else
            return false;
    }
    public void promote(Piece piece){
        if (verifyPromotion(piece)){
            Position position = piece.getPosition();
            PieceColor pieceColor = piece.getColor();;
            pieceArrayList.remove(piece);
            piece = new Tank(position,pieceColor);
            matrix[position.getRow()][position.getCol()] = piece;
            pieceArrayList.add(piece);
        }
        else throw new IllegalArgumentException();
    }

    public Piece[][] getUnderlyingMatrix() {
        return this.matrix;
    }
    public int getBoardSize(){
        return this.matrix.length;
    }
    public ArrayList<Piece> getPieceArrayList(){
        return this.pieceArrayList;
    }

    public boolean equals(Object obj){
        if(obj==this)
            return true;
        if(obj.getClass()!=Board.class)
            return false;
        Board tempBoard =(Board) (obj);
        Piece[][] other = tempBoard.getUnderlyingMatrix();

        if(matrix.length != other.length || matrix[0].length != other[0].length) return false;
        int sizeRow = matrix.length;
        int sizeCol = matrix[0].length;
        for(int i = 0; i < sizeRow; i++)
            for(int j = 0; j < sizeCol; j++) {
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
}
