package assignment4.toCopyFrom;
import java.util.ArrayList;

import static assignment4.Constants.*;

public abstract class Piece {
    private Position PiecePos;
    private PieceColor PieceColor;

    Piece(Position position, PieceColor color){
        this.PiecePos = position;
        this.PieceColor = color;
    }

    public abstract char getMarker();
    public abstract ArrayList<Move>   getPossibleMoves(Board board);

    public void setPosition(Position position){
        this.PiecePos = position;
        this.PiecePos.setRow(position.getRow());
        this.PiecePos.setCol(position.getCol());
    }

    public PieceColor getColor() {return this.PieceColor;}

    public Position getPosition() {return this.PiecePos;}

    @Override
    public String toString(){
        return this.getMarker() + "(" + this.getPosition().getRow() + "," + this.getPosition().getCol() + ")" + this.getColor().toString().charAt(0);
    }
}
