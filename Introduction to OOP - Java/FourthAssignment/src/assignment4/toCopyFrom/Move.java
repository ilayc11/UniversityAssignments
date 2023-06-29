package assignment4.toCopyFrom;
import static assignment4.Constants.*;


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
        /*
        Piece[][] matrix = board.getUnderlyingMatrix();
        Piece currPiece = matrix[getStartPos().getRow()][getStartPos().getCol()];
        if(currPiece != null){
            currPiece.setPosition(endingPos);
            matrix[getEndPos().getRow()][getEndPos().getCol()] = currPiece;
            matrix[getStartPos().getRow()][getStartPos().getCol()] = null;
        }

         */
    }

    @Override
    public boolean equals(Object obj){
        Move other = (Move)obj;
        return (this.getStartPos().equals(other.getStartPos())) && (this.getEndPos().equals(other.getEndPos()));
    }
}
