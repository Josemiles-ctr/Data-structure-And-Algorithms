package Lecture1.Jav;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.TreeSet;

public class BuiltIn {
    /* built in data types in java */
    @SuppressWarnings("unused")
    public static void main(String[] args) {
        /* predefined data types */
        int a = 5; /* 4 bytes */
        float b = 5.5f; /* 4 bytes */
        double c = 5.55555; /* 8 bytes */
        char d = 'A'; /* 2 bytes */
        boolean e = true; /* 1 bit */

        /* non predefined data types */
        String name = "Josemiles"; /* object */
        Integer age = 25; /* object */
        Double gpa = 3.75; /* object */
        Character initial = 'J'; /* object */
        Long phone = 1234567890L; /* object */
        Byte byteValue = 100; /* object */
        Short shortValue = 1000; /* object */
        Float floatValue = 5.5f; /* object */

        /* Add more non-predefined data types as needed */
        ArrayList<String> list = new ArrayList<>(); /* object */
        HashMap<String, Integer> map = new HashMap<>(); /* object */
        LinkedList<Double> linkedList = new LinkedList<>(); /* object */
        Stack<String> stack = new Stack<>(); /* object */
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(); /* object */
        TreeSet<String> treeSet = new TreeSet<>(); /* object */
        HashSet<Double> hashSet = new HashSet<>(); /* object */
        LinkedHashMap<String, Integer> linkedHashMap = new LinkedHashMap<>(); /* object */

        /* User defined data types can be created using classes */
        class Person {
            String name;
            int age;

            Person(String name, int age) {
                this.name = name;
                this.age = age;
            }
        }

        interface Animal {
            void sound();
        }

    }
}
