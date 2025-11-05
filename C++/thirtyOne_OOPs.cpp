#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// OOPs concept

// Classes are datatype defined by user. //variable with this datatype is called object.

// Class has both attributes and functions.

// Attributes are varaible declared .

// classes are also called blueprint for object.

// alignment and padding

// static vs Dynamic Memory allocation

class student
{
    // by default all declarations are private hence can't be accessed from outside of the class
private: // by default, if you want you can use explicitly also //private can be used to protect the data//encryption //It is used in singup and login.
    int rollno, age;
    string name;
    string grade;

    // function getter and setter

public: // for accessing the function, public necessary
        // setter
    void setname(string n)
    {
        if (n == "")
        {
            cout << "Invalid Name" << endl;
            return;
        }
        // -it will storp it at very first before setting the value. //here this function helpful for one kind of data or for one object and access all together.
        name = n;
    }

    void setage(int ageVal)
    {
        if (ageVal < 0 || ageVal > 100)
        {
            return; // not let to work further
        }
        age = ageVal;
    }

    void setGrade(string gr)
    {
        grade = gr;
    }

    // getter
    void getName()
    {
        cout << name << endl;
    }

    int getAge()
    {
        return age;
    }

    // get grade only when user enters the pin
    string getGrade(int pin)
    {
        if (pin == 123)
        {
            return grade;
        }

        return "Invalid pin";
    }

}; //; is necessary

class studentPubic
{
public:
    int rollno, age;
    string name;
    string grade;
}; //; is necessary

class PaddingAlignment
{

    // int a;
    // int b;
    // char c;
    // char d;

    // aaaabbbbcd//10 should be the answer but as it is not divisible by largest datatype int=4, hence next nearest is 12 , 12 will be answer.

    // as int take multiple of 4, hence search for index which is multiple of 4 , this int will start store from it.

    // padding done for cycle to read it fastly.

    // Make sure to use right alignment to save space, greedy approch where we keep the largest at top then smaller datatype below it.

    // jo sabse bada dataype h vo answer ko divide karna chahiye, agar divide nahi karta toh vo nearst greater divisible is find out. here 9 is not divisible by 4 hence we search for nearest greater index that divide it.

    char a;
    int b;
    char c;

    // apppbbbbc//9 spaces, upgraded to 12 //p is padding, we are taking indexes as per multiple.
};

class DynamicSt
{
public:
    int rollno, age;
    string name;
    string grade;
};

int main()
{

    student s1;
    // s1.name="Sudha";//it is showing error as we are trying to use private bydefault variables
    student s2;
    // we use public setter function
    s2.setname("Shanaya");
    //  cout<<s2.name<<endl;//it will set but we can't access
    s2.setage(13);
    s2.setGrade("A+");

    // to get the values we need public getter function
    s2.getName();                      // Shanaya
    cout << s2.getAge() << endl;       // 13
    cout << s2.getGrade(123) << endl;  // A++
    cout << s2.getGrade(1234) << endl; // Invalid pin

    // student class is blue print, just imagination about how... but not exist in real world. An object with this class exist in physical world. Student s1. now s1 is something that exist.
    // a class has many object

    // class defines mera object kaise dikhega... Instagram users are objects.

    studentPubic sp;
    sp.name = "Sudha";
    sp.age = 21;
    sp.rollno = 115;
    sp.grade = "A";

    studentPubic sp2;
    sp2.name = "Sana";
    sp2.age = 20;
    sp2.rollno = 116;
    sp2.grade = "A+";

    cout << sp.age << endl;
    cout << sp2.age << endl;

    PaddingAlignment padAli;
    cout << "Size: " << sizeof(padAli) << endl; // Size: 12

    // to allocate memoty to the object of class datatype in heap

    DynamicSt *obj = new DynamicSt; // here it means that DynamicSt dataype value is present in heap and it is pointed by obj variable stored in static memory and as obj pointer is pointing to  DynamicSt datatype , hence it is written like this.

    // now we can access the attributes and function in class with the help pf pointer or arror
    (*obj).name = "Sudha"; // it means whereever pointer obj is pointing , get he name value to Sudha in it.

    // (*obj)->age=20;//wrong as pointer and arrow showing pointing is in same and used twice hence error//either use pointer or arrow as arrow also does the work of pointing

    obj->age = 20; // obj jaha point kar raha h usme age ki value 20 kar do

    cout << (*obj).name << endl; // Sudha
    cout << (obj)->name << endl; // Sudha
    cout << (*obj).age << endl;  // 20
    cout << obj->age << endl;    // 20

    return 0;
}
