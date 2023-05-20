import assignment3.*;

public class MainRun {
    public static boolean fequal(double v1, double v2) {
        return Math.abs(v1 - v2) <= 1e-5;
    }

    public static void ArrayListTest() {
        MyArrayList<Integer> myArrayList = new MyArrayList<>();
        myArrayList.add(1);
        myArrayList.add(2);
        myArrayList.add(3);
        if (myArrayList.get(0) != 1 || myArrayList.get(1) != 2 || myArrayList.get(2) != 3) {
            System.out.println("MyArrayList Problem with add or get");
        }
        if (myArrayList.size() != 3) {
            System.out.println("MyArrayList Problem with size");
        }
        if (myArrayList.index(2) != 1) {
            System.out.println("MyArrayList Problem with index");
        }
        myArrayList.remove(2);
        if (myArrayList.get(0) != 1 || myArrayList.get(1) != 3 || myArrayList.size() != 2 || myArrayList.index(2) != -1) {
            System.out.println("MyArrayList Problem with remove");
        }
        myArrayList.add(3);
        if (myArrayList.count(3) != 2) {
            System.out.println("MyArrayList problem with count");
        }
    }

    public static void SetTest() {
        MySet<Integer> set1 = new MySet<>();
        MySet<Integer> set2 = new MySet<>();
        set1.add(1);
        set1.add(1);
        if (!set1.contains(1) || set1.contains(4)) {
            System.out.println("MySet problem with contains");
        }
        set1.add(2);
        set1.add(3);
        set2.add(3);
        set2.add(4);
        set2.add(5);
        if (set1.size() != 3 || set2.size() != 3) {
            System.out.println("MySet Problem with size");
        }
        MySet<Integer> set3 = new MySet<>(new Integer[]{1, 2,3});
        if (!set3.equals(set1)) {
            System.out.println("MySet Problem with equals");
        }
        MySet<Integer> union = new MySet<>(new Integer[]{1, 2, 3, 4, 5});
        MySet<Integer> intersection = new MySet<>(new Integer[]{3});
        MySet<Integer> difference = new MySet<>(new Integer[]{5, 4});
        MySet<Integer>uniuni=set1.union(set2);
        if (!set1.union(set2).equals(union)) {
            System.out.println("MySet problem with union");
        }
        if (!set2.difference(set1).equals(difference)) {
            System.out.println("MySet problem with difference");
        }
        if (!set1.intersection(set2).equals(intersection)) {
            System.out.println("MySet problem with intersection");
        }
        set1.remove(3);
        if (set1.contains(3) || set1.size() != 2) {
            System.out.println("MySet Problem with remove");
        }
    }

    public static void PersonRegistryTest() {
        PersonRegistry pr = new PersonRegistry();
        pr.add(new Person("a", 1, 1));
        pr.add(new Person("b", 2, 2));
        if (pr.maxAge() != 2) {
            System.out.println("PersonRegistry problem with maxAge");
        }
        if (!fequal(pr.meanLuckyNumber(), 1.5)) {
            System.out.println("PersonRegistry problem with maxAge");
        }
        MyArrayList<String> uniqueNames = pr.uniqueNames();
        if (uniqueNames.count("a") != 1 || uniqueNames.count("b") != 1) {
            System.out.println("PersonRegistry problem with uniqueNames");
        }
        pr.add(new Person("a", 1, 1));
        if(pr.count(new Person("a", 1, 1))!=2){
            System.out.println("PersonRegistry problem with count");
        }

    }
    public static void myTest(){
        String[] arr=null;
       // arr[1]="hello";
       // arr[0]="hi";
        MySet<String> set=new MySet<String>(arr);
        System.out.println();
    }


    public static void main(String[] args) {
        ArrayListTest();
        SetTest();
       PersonRegistryTest();
        myTest();
    }
}
