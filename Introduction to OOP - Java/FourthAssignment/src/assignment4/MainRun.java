package assignment4;

import static assignment4.Constants.*;

import assignment4.*;

import java.util.ArrayList;

public class MainRun {

    public static void boardMain() {
        Board b = new Board();
        System.out.println("Board size: " + b.getBoardSize());
        b = new Board(5);
        System.out.println("Board size: " + b.getBoardSize());
        Piece[][] matrix = new Piece[3][3];
        b = new Board(matrix);
        System.out.println("Board size: " + b.getBoardSize());
        Position p1 = new Position(0, 0);
        Position p2 = new Position(1, 0);
        b.addPiece(new Pawn(p1, BLACK));
        System.out.println("Piece at (0,0): " + b.getPiece(p1));
        System.out.println("Piece at (1,0): " + b.getPiece(p2));
        b.updatePosition(p1, p2);
        System.out.println("Piece at (0,0): " + b.getPiece(p1));
        System.out.println("Piece at (1,0): " + b.getPiece(p2));
        b.addPiece(new Pawn(p1, WHITE));
        //b.addPiece(new Bishop(new Position(1,1), BLACK));
        //System.out.println("bla");

        //System.out.println(b.getUnderlyingMatrix()[1][1].getPossibleMoves(b).size());
        //System.out.println("bla");
        System.out.println("White pieces: " + b.getPieces(WHITE));
        System.out.println("Black pieces: " + b.getPieces(BLACK));
        b.removePiece(p1);
        b.removePiece(p2);
        System.out.println("# of black pieces: " + b.getPieceCount(BLACK));
        Pawn promotable = new Pawn(new Position(0, 0), WHITE);
        b.addPiece(promotable);
        System.out.println(b.verifyPromotion(promotable));
        //System.out.println(b.BoardPieces.size());
        b.promote(promotable);
        //System.out.println(b.BoardPieces.size());
        //System.out.println(b.equals(new Board()));
        System.out.println(b.getUnderlyingMatrix()[0][0]);
    }

    public static void moveMain() {
        Position p1 = new Position(0, 0);
        Position p2 = new Position(1, 1);
        Position p3 = new Position(1, 1);
        Board b = new Board();
        b.addPiece(new Pawn(p1, BLACK));
        Move m = new Move(p1, p2);
        System.out.println("Move start position: " + m.getStartPos());
        System.out.println("Move end position: " + m.getEndPos());
        m.updateBoard(b);
        System.out.println("Piece at (0,0): " + b.getPiece(p1));
        System.out.println("Piece at (1,1): " + b.getPiece(p2));
        System.out.println(m.equals(new Move(p1, p2)));
        //System.out.println(p2.getRow() + "," + p2.getCol());
        //System.out.println(p3.getRow() + "," + p3.getCol());
        System.out.println(m.equals(new Move(p2, p3)));
    }

    public static void pawnMain() {
        // While each piece type needs to be implemented accordingly, we will test the general methods on pawn.
        // Be encouraged to add your own tests!
        Piece piece = new Pawn(new Position(1, 1), WHITE);
        System.out.println("Pawn marker: " + piece.getMarker());
        System.out.println("Pawn color: " + piece.getColor());
        System.out.println("Pawn position: " + piece.getPosition());
        piece.setPosition(new Position(0, 1));
        System.out.println("Pawn new position: " + piece.getPosition());
        System.out.println("Pawn string form: " + piece);
        Board b = new Board();
        b.addPiece(piece);
        Piece piece1 = new Bishop(new Position(1,0),WHITE);
        b.addPiece(piece1);
        System.out.println("# of possible moves: " + piece.getPossibleMoves(b).size());
        //System.out.println(piece.getPossibleMoves(b).get(0).endingPos);
        //System.out.println(piece.getPossibleMoves(b).get(1).endingPos);
        //System.out.println(piece.getPossibleMoves(b).get(2).endingPos);
        System.out.println("# of possible moves: " + piece1.getPossibleMoves(b).size());
        Pawn promotedPawn = new Pawn(new Position(0,0),WHITE);
        b.addPiece(promotedPawn);
        System.out.println(b.verifyPromotion(promotedPawn));
        b.promote(promotedPawn);
        System.out.println(promotedPawn);
    }

    public static void tankMain() {
        Board board = new Board();
        Pawn pawn = new Pawn(new Position(1,1),WHITE);
        Tank t = new Tank(new Position(3, 3), BLACK);
        board.addPiece(t);
        board.addPiece(pawn);
        System.out.println("Tank initial cooldown: " + t.getCooldown());
        t.setCooldown(1);
        System.out.println("Tank cooldown after change: " + t.getCooldown());
        System.out.println(t.getPossibleMoves(board).size());
        t.setCooldown(0);
        System.out.println(t.getPossibleMoves(board).size());
        System.out.println(board.getPieceCount(WHITE));
        TankEatMove tankEatMove = new TankEatMove(new Position(3,3), new Position(1,1));
        tankEatMove.updateBoard(board);
        System.out.println(board.getPieceCount(WHITE));
        System.out.println(t.getPosition().getRow() + "," + t.getPosition().getCol());
        System.out.println(t.getCooldown());
        Move move = new Move(t.getPosition(), new Position(2,2));
        move.updateBoard(board);
        System.out.println(t.getCooldown());
        System.out.println(t.getPosition().getRow() + "," + t.getPosition().getCol());

    }

    public static void bishopMain(){
        Board board = new Board();
        Bishop b = new Bishop(new Position(3,3), WHITE);
        Pawn p = new Pawn(new Position(2,2),WHITE);
        Pawn p1 = new Pawn(new Position(2,4),WHITE);
        Pawn p2 = new Pawn(new Position(4,4),BLACK);
        Pawn p3 = new Pawn(new Position(4,2),BLACK);
        board.addPiece(b);
        board.addPiece(p);
        board.addPiece(p1);
        board.addPiece(p2);
        board.addPiece(p3);
       // Move move = new Move(new Position(3,3), new Position(4,2));
      //  move.updateBoard(board);
        System.out.println(b.getPossibleMoves(board).size());
        System.out.println(board.getPieceCount(BLACK));
        System.out.println(board.getPieceCount(WHITE));
        //b.setPosition();

        Board secondBoard = new Board(3);
        Bishop b2 = new Bishop(new Position(0,2),BLACK);
        Pawn _p2 = new Pawn(new Position(1,1),WHITE);
        Pawn _p3 = new Pawn(new Position(2,0),WHITE);

        secondBoard.addPiece(b2);
        secondBoard.addPiece(_p2);
        secondBoard.addPiece(_p3);
        //System.out.println(b2.getPossibleMoves(secondBoard).size());
        System.out.println(b2.getPosition().getRow() + " , " + b2.getPosition().getCol());

        Move move = new Move(new Position(0,2), new Position(1,1));
        //move.updateBoard(secondBoard);
        //System.out.println(b2.getPosition().getRow() + " , " + b2.getPosition().getCol());
        //System.out.println(_p2.getPosition().getRow() + " , " + _p2.getPosition().getCol());
        System.out.println(secondBoard.getPieceCount(WHITE));
        Move move2 = new Move(new Position(2,0), new Position(1,1));
        //System.out.println(secondBoard.getPieceCount(BLACK));
        //move2.updateBoard(secondBoard);
        System.out.println(secondBoard.getPieceCount(BLACK));
        System.out.println(secondBoard.getPieceCount(WHITE));
        Position pos = new Position(_p2.getPosition());
        System.out.println(secondBoard.getPiece(pos));
        secondBoard.removePiece(_p2.getPosition());
        System.out.println(secondBoard.getPieceCount(WHITE));
        System.out.println(secondBoard.getPiece(pos));
        System.out.println("DONE");
    }

    static void knightMain(){
        Board board = new Board();
        Knight knight = new Knight(new Position(3,3),WHITE);
        Pawn pawn = new Pawn(new Position(1,4),BLACK);
        board.addPiece(knight);
        board.addPiece(pawn);
        System.out.println(knight.getPossibleMoves(board).size());

    }
    static void testt(){
        Board board = new Board();
        Knight knight = new Knight(new Position(0,0),WHITE);
        Pawn pawn1 = new Pawn(new Position(1,4),BLACK);
        Pawn pawn2 = new Pawn(new Position(1,2),BLACK);
        Pawn pawn3 = new Pawn(new Position(0,3),BLACK);
        Pawn pawn4 = new Pawn(new Position(5,5),WHITE);
        Pawn pawn5 = new Pawn(new Position(4,3),WHITE);
        board.addPiece(pawn1);board.addPiece(pawn2);board.addPiece(pawn3);board.addPiece(pawn4);board.addPiece(pawn5);
        board.addPiece(knight);
        Tank tank = new Tank(new Position(3,3),BLACK);
        board.addPiece(tank);
        System.out.println(tank.getPossibleMoves(board).size());
        System.out.println(tank.getPossibleMoves(board).get(0).endingPos.getRow() + "," +tank.getPossibleMoves(board).get(0).endingPos.getCol());
        System.out.println(tank.getPossibleMoves(board).get(1).endingPos.getRow() + "," +tank.getPossibleMoves(board).get(1).endingPos.getCol());
        System.out.println(tank.getPossibleMoves(board).get(2).endingPos.getRow() + "," +tank.getPossibleMoves(board).get(2).endingPos.getCol());
        System.out.println(tank.getPossibleMoves(board).get(3).endingPos.getRow() + "," +tank.getPossibleMoves(board).get(3).endingPos.getCol());
        System.out.println(tank.getPossibleMoves(board).get(4).endingPos.getRow() + "," +tank.getPossibleMoves(board).get(4).endingPos.getCol());
        if(tank.getPossibleMoves(board).get(3) instanceof TankEatMove)
            System.out.println("Suiiiii");
    }

    public static void main(String[] args) {
        /*
        System.out.println("---Board Testing---");
        boardMain();
        System.out.println("---Move Testing---");
        moveMain();
        System.out.println("---Piece (Pawn) Testing---");
        pawnMain();

        System.out.println("---Tank Testing---");
        tankMain();

        System.out.println("---Bishop Testing---");
        bishopMain();
        System.out.println("---Knight Testing---");
        knightMain();

         */
        testt();
    }
}