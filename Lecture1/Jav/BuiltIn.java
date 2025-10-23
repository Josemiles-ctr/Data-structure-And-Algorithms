package Lecture1.Jav;

public class BuiltIn {
    /*Primitive types */
    byte b;          // 1 byte
    short s;         // 2 bytes
    int i;           // 4 bytes
    long l;          // 8 bytes
    float f;        // 4 bytes
    double d;       // 8 bytes
    char c;         // 2 bytes
    boolean bool;   // 1 bit    

    /*Reference types */
    String str;     
    Object obj;     

    /*Reference types */
    class Student {
        String name;
        int age;
        String courseUnit;
    }

    /*Enums*/
    enum Week {Mon, Tue, Wed, Thur, Fri, Sat, Sun;}

    /*Interfaces*/
    interface BuiltInInterface {
        void display();
    }

    /*Arrays*/
    int[] numbers = new int[10];
    String[] names = new String[5];

}
