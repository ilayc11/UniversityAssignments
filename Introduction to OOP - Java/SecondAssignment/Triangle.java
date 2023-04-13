package assignment2;

public class Triangle extends Polygon {
    public Triangle(Point[] points, String name) {
        super(points, name);
    }

    @Override
    public double calcArea() {
        if(this.getNumOfPoints()!=3)
            return 0;
        Point a1=this.getPointAt(0);
        Point a2=this.getPointAt(1);
        Point a3=this.getPointAt(2);
        return Math.abs(0.5*(a1.getX()*(a2.getY()-a3.getY())+a2.getX()*(a3.getY()-a1.getY())+a3.getX()*(a1.getY()-a2.getY())));
    }

    @Override
    public boolean equals(Object other) {

        return super.equals(other);
    }
}
