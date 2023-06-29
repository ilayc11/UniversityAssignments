package assignment4;
import java.util.ArrayList;

import static assignment4.Constants.getColorMarker;


public class Tank extends Piece {
    private int cooldown;
    Tank(Position position,Constants.PieceColor color){
        super(position,color);
        this.cooldown=0;
    }
    public int getCooldown(){return this.cooldown;}
    public void setCooldown(int cooldown){this.cooldown=cooldown;}

    @Override
    public char getMarker() {
        return 'T';
    }

    @Override
    public ArrayList<Move> getPossibleMoves(Board board) {
        ArrayList<Move> possibleMoves = new ArrayList<>();
        Piece[][] matrix = board.getUnderlyingMatrix();
        int currRow = this.getPosition().getRow();
        int currCol = this.getPosition().getCol();

        // check all 8 direction

        if(currRow - 1 >=0 && currCol - 1 >=0){
            if(matrix[currRow-1][currCol-1] != null && getCooldown() == 0)
                if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow -1][currCol-1].getColor()))
                    possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow -1, currCol -1)));
            if(matrix[currRow-1][currCol-1] == null) {
                if(matrix[currRow -2][currCol-2] != null && getCooldown() == 0)
                    if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow -2][currCol-2].getColor()))
                        possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow -2, currCol -2)));
            }
        }

        if(currRow - 1 >=0){
            if(matrix[currRow-1][currCol] != null && getCooldown() == 0)
                if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow -1][currCol].getColor()))
                    possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow -1,currCol)));
            if(matrix[currRow-1][currCol] == null) {
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow - 1, currCol)));
                if(matrix[currRow -2][currCol] != null && getCooldown() == 0)
                    if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow -2][currCol].getColor()))
                        possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow -2, currCol)));
            }
        }

        if(currRow - 1 >=0 && currCol + 1 <= board.getBoardSize()-1){
            if(matrix[currRow-1][currCol+1] != null && getCooldown() == 0)
                if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow-1][currCol+1].getColor()))
                    possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow -1, currCol +1)));
            if(matrix[currRow-1][currCol+1] == null) {
                if(matrix[currRow-2][currCol+2] != null && getCooldown() == 0)
                    if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow-2][currCol+2].getColor()))
                        possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow -2, currCol +2)));
            }
        }

        if(currCol - 1 >=0){
            if(matrix[currRow][currCol-1] != null && getCooldown() == 0)
                if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow][currCol -1].getColor()))
                    possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow, currCol -1)));
            if(matrix[currRow][currCol-1] == null) {
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow, currCol - 1)));
                if(matrix[currRow][currCol -2] != null && getCooldown() == 0)
                    if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow][currCol -2].getColor()))
                        possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow, currCol -2)));
            }
        }

        if(currCol + 1 <= board.getBoardSize()-1){
            if(matrix[currRow][currCol+1] != null && getCooldown() == 0)
                if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow][currCol +1].getColor()))
                    possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow, currCol +1)));
            if(matrix[currRow][currCol+1] == null) {
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow, currCol + 1)));
                if(matrix[currRow][currCol +2] != null && getCooldown() == 0)
                    if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow][currCol +2].getColor()))
                        possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow, currCol +2)));
            }
        }

        if(currRow + 1 <= board.getBoardSize()-1 && currCol - 1 >=0 ){
            if(matrix[currRow +1][currCol -1] != null && getCooldown() == 0)
                if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow +1][currCol -1].getColor()))
                    possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow +1, currCol -1)));
            if(matrix[currRow+1][currCol-1] == null) {
                if(matrix[currRow +2][currCol -2] != null && getCooldown() == 0)
                    if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow +2][currCol -2].getColor()))
                        possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow +2, currCol -2)));
            }
        }

        if(currRow + 1 <= board.getBoardSize() -1){
            if(matrix[currRow +1][currCol] != null && getCooldown() == 0)
                if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow +1][currCol].getColor()))
                    possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow +1, currCol)));
            if(matrix[currRow+1][currCol] == null) {
                possibleMoves.add(new Move(this.getPosition(), new Position(currRow + 1, currCol)));
                if(matrix[currRow +2][currCol] != null && getCooldown() == 0)
                    if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow +2][currCol].getColor()))
                        possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow +2, currCol)));
            }
        }

        if(currRow + 1 <= board.getBoardSize() -1 && currCol + 1 <= board.getBoardSize()-1){
            if(matrix[currRow +1][currCol +1] != null && getCooldown() == 0)
                if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow +1][currCol +1].getColor()))
                    possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow +1, currCol +1)));
            if(matrix[currRow+1][currCol+1] == null) {
                if(matrix[currRow +2][currCol +2] != null && getCooldown() == 0)
                    if(getColorMarker(this.getColor()) != getColorMarker(matrix[currRow +2][currCol +2].getColor()))
                        possibleMoves.add(new TankEatMove(this.getPosition(), new Position(currRow +2, currCol +2)));
            }
        }
        return possibleMoves;

    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;
        if(obj instanceof Tank){
            Tank other = (Tank) obj;
            return getColorMarker(other.getColor()) == getColorMarker(this.getColor()) && this.getPosition().equals(other.getPosition()) && this.getCooldown() == other.getCooldown();

        }
        return false;
    }

}