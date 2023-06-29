package assignment4;

public class Move {
    protected Position startingPos;
    protected Position endingPos;

    public Move(Position startPos, Position endPos){
        this.startingPos = startPos;
        this.endingPos = endPos;
    }

    public Position getStartPos(){return this.startingPos;}
    public Position getEndPos(){return this.endingPos;}

    public void updateBoard(Board board){
        board.updatePosition(this.startingPos,this.endingPos);
    }

    @Override
    public boolean equals(Object obj){
        Move other = (Move)obj;
        return (this.getStartPos().equals(other.getStartPos())) && (this.getEndPos().equals(other.getEndPos()));
    }
}
