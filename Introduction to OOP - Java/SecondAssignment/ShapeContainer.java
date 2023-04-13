package assignment2;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Objects;

public class ShapeContainer implements Iterable<Shape> {
    public class ShapeContainerIterator implements Iterator<Shape> {
        int nextIndex=0;
        @Override
        public boolean hasNext() {
        return nextIndex<shapes.length&&shapes[nextIndex]!=null;
        }

        @Override
        public Shape next() {
            if(!hasNext())
               return null;
            Shape ans=shapes[nextIndex];
            nextIndex++;
            return ans;
        }
    }

    public static class NameComparator implements Comparator<Shape> {
        @Override
        public int compare(Shape o1, Shape o2) {
            if(o1!=null&&o2==null)
                return -1;
            if(o1==null&&o2!=null)
                return 1;
            if(o1 == o2)
                return 0;
            if(o1.getName()!=null&&o2.getName()==null)
                return -1;
            if(o1.getName()==null&&o2.getName()!=null)
                return 1;
            if(o1.getName()==null&&o2.getName()==null)
                return 0;
            return (o1.getName().compareTo(o2.getName()));
        }
    }

    public static class CircumferenceComparator implements Comparator<Shape> {
        @Override
        public int compare(Shape o1, Shape o2) {
            if(o1!=null&&o2==null)
                return -1;
            if(o1==null&&o2!=null)
                return 1;
            if(o1 == o2)
                return 0;
            return Double.compare(o1.calcCircumference(), o2.calcCircumference());
        }
    }

    public static class EdgeComparator implements Comparator<Shape> {
        @Override
        public int compare(Shape o1, Shape o2) {
            if(o1!=null&&o2==null)
                return -1;
            if(o1==null&&o2!=null)
                return 1;
            if(o1 == o2)
                return 0;
            if(Double.compare(o1.getLeftMostX(), o2.getLeftMostX())==0)
                return Double.compare(o1.getUpperMostY(), o2.getUpperMostY());
            else return Double.compare(o1.getLeftMostX(), o2.getLeftMostX());
        }
    }

    private Shape[] shapes;

    public ShapeContainer() {
        this.shapes=new Shape[1];
    }

    public ShapeContainer(Shape[] shapes) {
        this.shapes=shapes;
    }

    public Shape[] getShapes(){
        return shapes;
    }

    public void addShape(Shape newShape) {
        if(newShape==null)
            return;
        if(shapes[shapes.length-1]!=null) {
            Shape[] tmp = new Shape[this.shapes.length * 2];
            for (int i = 0; i < shapes.length; i++)
                tmp[i] = shapes[i];
            tmp[shapes.length] = newShape;
            shapes = tmp;
            return;
        }
        for(int i=0;i<shapes.length;i++)
            if(shapes[i]!=null)
                continue;
            else {
                shapes[i] = newShape;
                break;
            }
    }

    public int contains(Shape shape) {
        for(int i=0;i<shapes.length;i++) {
            if (shapes[i]==null&&shape==null)
                return i;
            else if (shapes[i]==null||shape==null)
                continue;
            else if (shapes[i].equals(shape))
                return i;
        }
        return -1;
    }

    public double calcAllCircumference() {
    double sum=0;
    for(int i=0;i<shapes.length;i++)
        if(shapes[i]!=null)
            sum+=shapes[i].calcCircumference();
    return sum;
    }

    public double calcCircleArea() {
        double sum=0;
        for(int i=0;i<shapes.length;i++)
            if(shapes[i] instanceof Circle)
                sum+=shapes[i].calcArea();
        return sum;
    }

    public double calcPolygonArea() {
        double sum=0;
        for(int i=0;i<shapes.length;i++)
            if(shapes[i] instanceof Polygon)
                sum+=shapes[i].calcArea();
        return sum;
    }

    public void sort(Comparator<Shape> comparator) {
       if(comparator==null)
           return;
        Arrays.sort(shapes,comparator);
    }

    @Override
    public Iterator<Shape> iterator() {
        return new ShapeContainerIterator();
    }
}
