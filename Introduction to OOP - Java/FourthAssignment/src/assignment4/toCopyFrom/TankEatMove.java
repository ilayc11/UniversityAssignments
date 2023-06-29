package assignment4.toCopyFrom;

public class TankEatMove extends Move {

    public TankEatMove(Position startPos, Position endPos) {super(startPos, endPos);}

    @Override
    public void updateBoard(Board board){
        Piece[][] matrix = board.getUnderlyingMatrix();
        Tank currPiece = (Tank)matrix[getStartPos().getRow()][getStartPos().getCol()];
        currPiece.setCooldown(2);
        board.removePiece(endingPos);
        matrix[endingPos.getRow()][endingPos.getCol()] = null;
    }
}
