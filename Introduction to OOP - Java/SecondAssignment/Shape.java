package assignment2;

import java.util.Objects;

public abstract class Shape implements EdgePointer{
    private String name;

    public Shape(){
        name=null;
    }

    public Shape(String name) {

        if(name==null)
            this.name="";
        this.name= name;
    }


    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        if(name==null)
            this.name="";
        this.name = name;
    }

    public abstract double calcCircumference();

    public abstract double calcArea();

    public abstract void shift(double xShift, double yShift);

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Shape tmp=(Shape) o;
        if(Objects.equals(this.name, tmp.name))
            return true;
        return false;
    }
}
