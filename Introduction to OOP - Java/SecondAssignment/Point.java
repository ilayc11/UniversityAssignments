package assignment2;

public class Point {
    private double x;
    private double y;

    public Point() {
        this.x = 0;
        this.y = 0;
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Point(Point other) {
        if (other != null) {
            this.x = other.x;
            this.y = other.y;
        }
        else{
            this.x=0;
            this.y=0;
        }
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public void shift(double xShift, double yShift) {
        this.x += xShift;
        this.y += yShift;
    }

    public double distance(Point other) {
        if(other==null)
            return 0;
        return Math.hypot(Math.abs(this.x - other.getX()), Math.abs(this.y - other.getY()));
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point point = (Point) o;
        return (point.getX() == this.x && point.getY() == this.y);
    }

    @Override
    public String toString() {
        return "<" + x + "," + y + ">";
    }
}
