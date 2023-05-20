package assignment3;

import java.io.*;
import java.util.Iterator;

public class PersonRegistry {
    private boolean corrupted;
    private MyArrayList<Person> personList;
    private int maxAge = 0;

    public boolean isCorrupted() {
        return this.corrupted;
    }

    public PersonRegistry(String filePath) {
        personList=new MyArrayList<>();
        if (filePath.contains(".bin")) {
            try {
                ObjectInputStream ois = new ObjectInputStream(new FileInputStream(filePath));
                this.personList = (MyArrayList<Person>)ois.readObject();
                ois.close();
                for (int i = 0; i < personList.size(); i++)
                    if (personList.get(i).getAge() > maxAge)
                        maxAge = personList.get(i).getAge();

            } catch (Exception e) {
                corrupted = true;
            }

        } else {
            try {
                BufferedReader reader = new BufferedReader(new FileReader(filePath));
                String line = "";
                while ((line = reader.readLine()) != null) {
                    String[] data = line.split(",");
                    Person p = new Person(data[0], Integer.parseInt(data[1]), Double.parseDouble(data[2]));
                    if (p.getAge() > maxAge)
                        maxAge = p.getAge();
                    personList.add(p);
                }
                reader.close();
            } catch (Exception e) {
                corrupted = true;
            }
        }

    }

    public PersonRegistry() {
        personList = new MyArrayList<>();
        corrupted = false;
    }

    public PersonRegistry(Iterable<? extends Person> persons) {
        this.personList = new MyArrayList<>();
        Iterator<? extends Person> iter = persons.iterator();
        while (iter.hasNext()) {
            Person p = iter.next();
            if (p.getAge() > maxAge)
                maxAge = p.getAge();
            this.personList.add(p);
        }
    }

    public PersonRegistry(Person[] persons) {
        this.personList = new MyArrayList<>();
        for (int i = 0; i < persons.length; i++) {
            if (persons[i].getAge() > maxAge)
                maxAge = persons[i].getAge();
            personList.add(persons[i]);
        }
    }

    public void add(Person p) {
        if (p == null)
            return;
        if (p.getAge() > maxAge)
            this.maxAge = p.getAge();
        personList.add(p);
    }

    public Person get(int index) {
        if (index >= this.personList.size() || index < 0)
            throw new IndexOutOfBoundsException();
        return personList.get(index);
    }

    public boolean writeCSV(String filePath) {
        try {
            PrintWriter writer = new PrintWriter(new FileWriter(filePath));
            for (int i = 0; i < personList.size(); i++) {
                Person p=personList.get(i);
                String name=p.getName();
                String age=Integer.toString(p.getAge());
                String lucky=Double.toString(p.getLuckyNumber());
                writer.println(String.format("%s,%s,%s",name,age,lucky));
            }
            writer.close();

        }catch (Exception e){
            return false;
        }
    return true;
    }

    public int maxAge() {
        return maxAge;
    }

    public double meanLuckyNumber() {
        double sum = 0;
        for (int i = 0; i < personList.size(); i++) {
            sum += personList.get(i).getLuckyNumber();
        }
        return sum / personList.size();
    }

    public MyArrayList<String> uniqueNames() {
        MyArrayList<String> names = new MyArrayList<>();
        for (int i = 0; i < personList.size(); i++) {
            if (names.index(personList.get(i).getName()) == -1)
                names.add(personList.get(i).getName());
        }
        return names;
    }

    public int count(Person person) {
        int count = 0;
        for (int i = 0; i < personList.size(); i++) {
            if (personList.get(i).equals(person))
                count++;
        }
        return count;
    }
}
