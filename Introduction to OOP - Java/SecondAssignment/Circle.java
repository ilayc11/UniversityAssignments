package assignment2;

import java.util.Objects;

public class Circle extends Shape implements Comparable<Circle> {
    private double radius;
    private Point center;

    public static final double PI = 3.14;

    public Circle() {
        this.radius=0;
        this.center=new Point();
    }

    public Circle(double radius, Point center, String name) {
        this.radius=radius;
        this.center=new Point(center);
        this.setName(name);
    }

    public Circle(Circle other) {
        if (other == null) {
            this.radius = 0;
            this.center = new Point();
        } else {
            this.radius = other.getRadius();
            this.center = new Point(other.getCenter());
            this.setName(other.getName());
        }
    }

    public double getRadius() {
        return radius;
    }

    public Point getCenter() {
        return center;
    }

    public void setRadius(double radius) {
        if(radius<0)
            this.radius=0;
        this.radius = radius;
    }

    public void setCenter(Point center) {
            this.center = new Point(center);
    }

    @Override
    public double calcCircumference(){
        if(radius==0)
            return 0;
        return 2*PI*radius;
    }

    @Override
    public double calcArea() {

        if(radius==0)
            return 0;
        return PI*radius*radius;
    }

    @Override
    public void shift(double xShift, double yShift) {
       this.center.shift(xShift,yShift);
    }

    @Override
    public int compareTo(Circle other) {
       if(other==null)
           return 1;
        if(Double.compare(this.radius, other.radius)==0)
            return this.getName().compareTo(other.getName());
        return Double.compare(this.radius, other.radius);
    }

    @Override
    public boolean equals(Object other) {
    if(!super.equals(other))
        return false;
    Circle tmp =(Circle) other;
    if(this.radius!= tmp.getRadius())
        return false;
    if(!this.getCenter().equals(tmp.getCenter()))
        return false;
    return true;

    }

    @Override
    public double getLeftMostX() {
        return this.center.getX()-this.radius;
    }

    @Override
    public double getUpperMostY() {
        return this.center.getY()+this.radius;
    }
}
