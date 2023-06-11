package assignment4;

import java.util.ArrayList;
import java.util.Arrays;
import static assignment4.Constants.*;

public class Board {
    private Piece[][] matrix;
    ArrayList<Piece> pieceArrayList=new ArrayList<>();

    public Board(){
        this.matrix=new Piece[7][7];
    }
    public Board(int size){
        this.matrix=new Piece[size][size];
    }
    public Board(Piece[][]board){
        int size=getBoardSize();
        this.matrix=new Piece[size][size];
        for (Piece[]y:matrix)
            pieceArrayList.addAll(Arrays.asList(y));
    }
    public ArrayList<Piece> getPieces(PieceColor color){
        ArrayList<Piece> rtrnList=new ArrayList<>();
        for(Piece i:pieceArrayList)
            if(getColorMarker(i.getColor())==getColorMarker(color))
                rtrnList.add(i);
        return rtrnList;
    }
    public Piece getPiece(Position position){
        if(position.getCol()>=matrix.length||position.getCol()<0)
            return null;
        if(position.getRow()>=matrix.length||position.getRow()<0)
            return null;
        if(matrix[position.getRow()][position.getCol()]==null)
            return null;
        return matrix[position.getRow()][position.getCol()];
    }
    public void addPiece(Piece piece){
        matrix[piece.getPosition().getRow()][piece.getPosition().getCol()]=piece;
        pieceArrayList.add(piece);
    }
    public void removePiece(Position position){
        Piece tmp=matrix[position.getRow()][position.getCol()];
        if(tmp==null)
            return;
        matrix[position.getRow()][position.getCol()]=null;
        pieceArrayList.remove(tmp);
    }
    public void updatePosition(Position oldPos,Position newPos){
        Piece tmp=matrix[oldPos.getRow()][oldPos.getCol()];
        if(tmp==null)
            return;
        matrix[oldPos.getRow()][oldPos.getCol()]=null;
        tmp.setPosition(newPos);
        matrix[newPos.getRow()][newPos.getCol()]=tmp;

    }
    public int getPieceCount(PieceColor pieceColor){
        int sum=0;
        for(Piece i:pieceArrayList)
            if(getColorMarker(i.getColor())==getColorMarker(pieceColor))
                sum++;
        return sum;
    }
    public boolean verifyPromotion(Piece piece){
        if(piece.color==PieceColor.White&&piece.getPosition().getRow()==0&&piece.getClass()== Pawn.class)
            return true;
        return piece.color == PieceColor.Black && piece.getPosition().getRow() == getBoardSize() - 1&&piece.getClass()== Pawn.class;
    }
    public void promote(Piece piece){
        if(!verifyPromotion(piece))
            throw new IllegalArgumentException();
        Pawn tmp=new Pawn(piece); //TODO
        Tank tmp=new Tank();
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
        if(getBoardSize()!=((Board) obj).getBoardSize())
            return false;
        if((((Board) obj).getPieceArrayList()==null&&this.pieceArrayList!=null)
            return false;
        for(Piece i:pieceArrayList)
            if(!((Board) obj).getPieceArrayList().contains(i))
                return false;
    }
}
