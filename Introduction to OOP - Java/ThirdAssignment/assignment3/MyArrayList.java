package assignment3;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.io.*;
public class MyArrayList<T extends Serializable> implements Serializable, Iterable<T> {

    public class MyArrayListIterator implements Iterator<T> {
        int nextIndex=0;
        @Override
        public boolean hasNext() {
            return nextIndex<arr.size()&&arr.get(nextIndex)!=null;
        }

        @Override
        public T next() {
            if(!hasNext())
                throw new NoSuchElementException();
            T ans=arr.get(nextIndex);
            nextIndex++;
            return ans;
        }
    }
    public Iterator<T> iterator() {
        return new MyArrayListIterator();
    }

    private SimpleArray<T> arr;

    public MyArrayList(){
        arr =new SimpleArray<>(1);
    }
    public MyArrayList(T [] arr){
        this.arr=new SimpleArray<>(arr);
    }
    public T get(int index){
        if(index<0||index>this.size()-1) {
            throw new IndexOutOfBoundsException();
        }
        return arr.get(index);
    }

    public int size(){
        int size=0;
        for (int i=0;i<arr.size();i++){
            if(arr.get(i)==null)
                break;
            size++;
        }
        return size;
    }

    public void add(T element){
        if(element==null)
            return;
        if(arr.get(arr.size()-1)!=null) {
            SimpleArray<T> tmp = new SimpleArray<>(arr.size() * 2);
            for (int i = 0; i < arr.size(); i++) {
                tmp.set(i, arr.get(i));
            }
            tmp.set(arr.size(),element);
            arr=tmp;
        }
        else{
            for (int i = 0; i < arr.size(); i++) {
                if(arr.get(i)==null) {
                    arr.set(i, element);
                    break;
                }
            }
        }
    }
    public void remove(T element){
        if(element==null)
            if(arr.get(arr.size()-1)!=null)
                throw new NoSuchElementException();

        boolean exist=false;
        for (int i = 0; i < arr.size(); i++) {
            if(arr.get(i)!=null&&(arr.get(i)==element||arr.get(i).equals(element))){
                exist=true;
                arr.set(i,null);
            }
        }
        if(!exist)
            throw new NoSuchElementException();
        T tmp;
        for(int i=0;i< arr.size()-1;i++){
            if(arr.get(i)==null){
                tmp=arr.get(i);
                arr.set(i, arr.get(i+1));
                arr.set(i+1,tmp);
            }
        }
    }
    public int index(T element){
        if(element==null)
            return -1;
        for(int i=0;i<this.size();i++){
            if(element==get(i)||element.equals(get(i)))
                return i;
        }
        return -1;
    }
    public int count(T element){
        int count=0;
        for(int i =0;i<this.size();i++){
            if(element==get(i)||element.equals(get(i)))
                count++;
        }
        return count;
    }
    public SimpleArray<T> getUnderlyingSimpleArray() {
        return this.arr;
    }

    public int capacity() {
        return this.arr.length();
    }


}
