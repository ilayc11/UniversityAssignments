package assignment2;

import java.util.Arrays;

public abstract class Polygon extends Shape {
    private Point[] points;
    private int accessCounter;

    public Polygon(Point[] points, String name) {
        if (points == null)
            this.points = new Point[0];
        else if (name == null) {
            this.setName("");
        } else {
            this.points = new Point[points.length];
            for (int i = 0; i < points.length; i++)
                this.points[i] = new Point(points[i]);
            this.setName(name);
        }
    }

    public Point getPointAt(int index) {
        accessCounter++;
        return new Point(points[index]);
    }

    public int getAccessCounter() {
        return accessCounter;
    }

    public int getNumOfPoints() {
        return points.length;
    }

    @Override
    public double calcCircumference() {
        double sum=0;
        for(int i=0;i<points.length-1;i++)
            sum+=points[i].distance(points[i+1]);
        sum+=points[points.length-1].distance(points[0]);
        return sum;
    }

    @Override
    public double getLeftMostX() {
        double min=points[0].getX();
        for(int i=1;i<points.length;i++)
            if(points[i].getX()<min)
                min=points[i].getX();
        return min;
    }

    @Override
    public double getUpperMostY() {
        double max=points[0].getY();
        for(int i=1;i<points.length;i++)
            if(points[i].getY()>max)
                max=points[i].getY();
        return max;
    }

    @Override
    public void shift(double xShift, double yShift) {
        for(int i=0;i<points.length;i++)
            points[i].shift(xShift,yShift);
    }

    @Override
    public boolean equals(Object o) {
        boolean flag=false;
       if(!super.equals(o))
           return false;
        Polygon tmp=(Polygon) o;
        if(tmp.points.length!=this.points.length)
            return false;
        for(int i=0;i<points.length;i++) {
            for (int j = 0; j < points.length; j++) {
                flag=false;
                if (tmp.points[i].equals(((Polygon) o).points[j])) {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                return false;
        }
        return true;
    }
}
