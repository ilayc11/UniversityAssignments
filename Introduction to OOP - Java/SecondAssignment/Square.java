package assignment2;

public class Square extends Polygon {
    public Square(Point[] points, String name) {
        super(points, name);
    }

    @Override
    public double calcArea() {
        if(this.getNumOfPoints()!=4)
            return 0;
        Point a1=this.getPointAt(0);
        Point a2=this.getPointAt(1);
        double dis=a1.distance(a2);
        return dis*dis;
    }

    @Override
    public double calcCircumference() {
        if(this.getNumOfPoints()<4)
            return 0;
        Point a1=this.getPointAt(0);
        Point a2=this.getPointAt(1);
        return a1.distance(a2)*4;
    }

    @Override
    public boolean equals(Object other) {

        return super.equals(other);
    }
}
