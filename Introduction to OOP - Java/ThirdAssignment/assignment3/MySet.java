package assignment3;


import java.io.Serializable;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class MySet<T extends Serializable> implements Serializable,Iterable<T> {
    public class MySetIterator implements Iterator<T> {
        int nextIndex=0;
        @Override
        public boolean hasNext() {
            return nextIndex<set.size()&&set.get(nextIndex)!=null;
        }

        @Override
        public T next() {
            if(!hasNext())
                throw new NoSuchElementException();
            T ans=set.get(nextIndex);
            nextIndex++;
            return ans;
        }
    }
    public Iterator<T> iterator() {
        return new MySetIterator();
    }
    private MyArrayList<T> set=null;

    public MySet(){
        this.set=new MyArrayList<>();
    }
    public MySet(Iterable<? extends T> collection){
        Iterator<? extends T> iter= collection.iterator();
        while(iter.hasNext()) {
            try {
                T nextObject = iter.next();
                if (set.index(nextObject)==-1)
                    set.add(nextObject);

            } catch (Exception e) {
            }
        }
    }
    public MySet(T [] arr){
        if(arr==null||arr.length == 0) {
            this.set = new MyArrayList<>();
            return;
        }
        this.set=new MyArrayList<>();
        for(int i=0;i< arr.length;i++){
            if(set.index(arr[i])==-1&&arr[i]!=null)
                set.add(arr[i]);
        }
    }
    public void add(T element){
        if(set.index(element)==-1)
            set.add(element);
    }
    public boolean contains(T element){
        if(element==null) {
            if (set.get(set.size() - 1) == null)
                return true;
            else
                return false;
        }

        if (set.index(element)!=-1)
            return true;
        else
            return false;
    }
    public int size(){
        return set.size();
    }
    public void remove(T element){
        if(element==null)
            return;
        for(int i =0;i<set.size();i++){
            T tmp=set.get(i);
            if(element==tmp||tmp.equals(element))
                set.remove(element);
        }
    }
    public MySet<T> union(MySet<T> other){
    MySet<T>tmp;

    if(other==null) {
        tmp = new MySet<>();
        Iterator<T> iter=new MySetIterator();
        while(iter.hasNext()) {
            try {
                T nextObject = iter.next();
                if (tmp.set.index(nextObject) == -1)
                    tmp.add(nextObject);
            } catch (Exception e) {
            }
        }
        return tmp;
    }
    tmp=new MySet<>();
    for(int i=0;i<set.size();i++) {
        if (tmp.set.index(this.set.get(i)) == -1 && set.get(i) != null)
            tmp.add(this.set.get(i));
    }
    for(int i=0;i<other.size();i++) {
            if(tmp.set.index(other.set.get(i))==-1&&other.set.get(i)!=null)
            tmp.add(other.set.get(i));
        }
    return tmp;
    }

    public MySet<T> intersection(MySet<T> other){
        if(other==null)
            return null;
        MySet<T>tmp=new MySet<>();
        for(int i=0;i<set.size();i++){
            if(other.contains(set.get(i)))
                tmp.add(set.get(i));
        }
        return tmp;
    }
    public MySet<T> difference(MySet<T> other){
        MySet<T> tmp=new MySet<>();
        if(other==null)
            for(int i=0;i<set.size();i++) {
                tmp.add(set.get(i));
                return tmp;
            }
    for(int i=0;i<set.size();i++)
        if(!other.contains(set.get(i)))
            tmp.add(set.get(i));
    return tmp;
    }
    public boolean equals(MySet<T> other){
        if(other==null)
            return false;
        if(other.size()!=set.size())
            return false;
        for(int i=0;i<set.size();i++)
            if(!other.contains(set.get(i)))
                return false;
        return true;
    }
}
