package assignment4.toCopyFrom;

public class Constants {
    enum PieceColor {
        White,
        Black
    }

    public final static PieceColor WHITE = PieceColor.White;
    public final static PieceColor BLACK = PieceColor.Black;

    public static char getColorMarker(PieceColor color) {
        return color == WHITE ? 'W' : 'B';
    }
}
