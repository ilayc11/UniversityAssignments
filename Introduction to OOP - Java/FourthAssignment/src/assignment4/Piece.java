package assignment4;
import java.util.ArrayList;

import static assignment4.Constants.*;

public abstract class Piece {
    Position pos;
    PieceColor color;
    public Piece(Position position, PieceColor color){
        this.pos=position;
        this.color=color;
    }
    public abstract char getMarker();
    public abstract ArrayList<Move> getPossibleMoves(Board board);
    public void setPosition(Position position){
        this.pos=position;
        this.pos.setRow(position.getRow());
        this.pos.setCol(position.getCol());
    }
    public PieceColor getColor(){return this.color;}
    public Position getPosition(){return this.pos;}

    @Override
    public String toString(){
        return this.getMarker() + "(" + this.getPosition().getRow() + "," + this.getPosition().getCol() + ")" + this.getColor().toString().charAt(0);
    }
    public abstract boolean equals(Object o);

}
