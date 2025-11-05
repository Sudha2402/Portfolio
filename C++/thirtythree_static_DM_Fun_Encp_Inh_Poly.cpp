#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// static data
// static member function.
// const keyword.//not update the data
// Encapsulation
// Abstraction
// access modifier public,protected, private
// Inheritance
// // types of inheritance
// single inheritance(one parent one child)eg Human and student.

// first parent constructor is called.
// descructor is from child to parent.

// multilevel inheritance

// multiple inheritance
// hirarchial inheritance
// hybrid inheritance
// Multipath Inheritance

//
// Polymorphism
//
// function overloading

//
// const keyword in C++ enforces immutability//, ensuring that a variable, pointer, reference, or member function cannot modify certain data. It is a powerful tool for:
// Safety: Preventing accidental modifications.
// Clarity: Expressing design intent (e.g., "this value should not change").
// Optimization: Enabling compiler optimizations.
//

const int MAX_USERS = 100; // Must be initialized
// MAX_USERS = 200;         // Error: Cannot modify

class Customer
{
    int AccNo;
    string Name;
    int Balance;

    static int total_bal;

    // public:                   // if public not written then it will be not accessable outside, and not even in display, becuase static are not created with object//we can use statci function , which access static easily.
    static int total_Acc; // shared by all object created.

    // Customer::Customer(int a, std::__cxx11::string b, int c)" (declared at line 13) is inaccessible, hence we need to use public constructor

public:
    Customer(int a, string b, int c)
    {
        AccNo = a;
        Name = b;
        Balance = c;
        total_Acc++;
        total_bal += Balance;
    }

    void display()
    {
        cout << AccNo << " " << Name << " " << Balance << " " << total_Acc << endl;
    }

    void display_total()
    {
        cout << total_Acc << endl; // accessable only when total_Acc public.//creates error when not public total_Acc. //it works without total_Acc public
    }

    static void staticDisplay()
    {
        cout << "Total account: " << total_Acc << endl; // accessable even when total_Acc is not public.

        // but here static function can access only statci not others like name, etc

        cout << "Total balance: " << total_bal << endl; // as initialized with 0 hence , take 0 value
    }

    void deposit(int amount)
    {
        if (amount > 0)
        {
            total_bal += amount;
            Balance += amount;
        }
    }
    void withdraw(int amount)
    {
        if (amount > 0 && Balance >= amount)
        {
            total_bal -= amount;
            Balance -= amount;
        }
    }
};

// for intitializing total_Acc
int Customer::total_Acc = 0; // intitialize it from zero. //:: (Scope Resolution Operator), Specifies that total_Acc belongs to the Customer class.Required because static members are not bound to a specific object.//resolutuion// // Mandatory definition outside the class//Allocates Memory for total_Acc (static members don’t get memory automatically like normal members).

int Customer::total_bal = 0; // if not present then it shows undefined reference to `Customer::total_bal'

//
//
// Encapsulation
//
//
class EncapUsers
{

    // private data prevented from direct access
    int userNum;
    string Name;
    int age;
    int salary;

public:
    // constructor
    EncapUsers(int a, string b, int c, int s)
    {
        userNum = a;
        Name = b;
        // age = c;
        salary = s;

        // here instead of directly updating, we could have used check functions inside this also

        setAge(c);
    }

    void display()
    {
        cout << userNum << " " << Name << " " << age << " " << salary << endl;
    }

    void setAge(int age)
    {
        if (age >= 0 && age <= 100)
        {
            this->age = age;
        }
        else
        {
            cout << "invalid age\n";
        }
    }
};

// Simple inheritance has one parent and one child.

// Multilevel Inheritance
// inheritant in form of chain.

// person <- Employee <- Manager (all connected)

class person
{
protected:
    string name;
    int age;

    person()
    {
        cout << "Person constructor is called" << endl;
    }

    person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

class teacherHu : public person
{
    // as parents are protected then it will also be inherited as protected not the public.

protected:
    string subject;
    int salary;

    // it will call parent constructor first hence always use a default constructor or pass the constructor parameter from here.
    teacherHu(string name, int age, string subject, int salary)
    {
        this->name = name;
        this->age = age;
        this->subject = subject;
        this->salary = salary;

        cout << "teacher constructor is called" << endl;
    }
};

class principaHu : public teacherHu
{

protected:
    string school;

public:
    principaHu(string name, int age, string subject, int salary, string school) : teacherHu(name, age, subject, salary)
    {
        this->name = name;
        this->age = age;
        this->subject = subject;
        this->salary = salary;
        this->school = school;

        cout << "principal constructor is called" << endl;
    }

    void display()
    {
        cout << name << " " << age << " " << subject << " " << salary << " " << school << endl;
    }
};

// Multiple inheritance
// many parent and one child.
// I am a youtuber, i am teacher ,Engineer , i am coder//all property in this person

class engineer
{
protected:
    string special;
    engineer()
    {
        cout << "I am a engineer: " << special << endl;
    }
};

class youtuber
{
protected:
    string subscriber;
    youtuber()
    {
        cout << "I am a  youtuber: " << subscriber << endl;
    }
};

class coder : public engineer, public youtuber
{

    string name;

public:
    coder(string name, string special, string subscriber)
    {
        this->name = name;
        this->special = special;
        this->subscriber = subscriber;
    }

    void display()
    {
        cout << name << " " << special << " " << subscriber << endl;
    }
};

// here modifier is inherited by many hence it is called hierarchial inheritance. One parent and many child

class modifier
{
private:
    int privateVar;
    // function in private are not accessable to main

protected:
    int protectedVar; //// function in protected are not accessable to main

public:
    int publicVar;

    modifier()
    {
        // default constructor helps in making constructor directlr in child class
    }

    // constructor must be public
    modifier(int a, int b, int c)
    {
        privateVar = a;
        protectedVar = b;
        publicVar = c;
    }

    void display()
    {
        // access all within the class
        cout << privateVar << " " << protectedVar << " " << publicVar << endl;
    }
};

class modifierChild1 : public modifier
{
    // we can access, Parent access is greater access, we can decrement the access but not increment. Public in parent can be converted to private and protected in child but protected in parent can't be converted to public in child. Private in parent can't be protected or public in main and even private because privated can be inherited at all.

public:
    // constructor
    // modifierChild1(int a, int b, int c)
    // {
    //     // let's access
    //     // privateVar = a;//error as private can't be access from outside, even in derived

    //     protectedVar = b; // accessable
    // cout<< protectedVar<<endl;//not even this way can be printed, we need to use function

    //     publicVar = c;    // accessable.

    //     // we can call/inherit display() public function also with this object name.
    // }

    // above way of constructor not works as such constructor not present in base case.

    // we can use inline function but construct are in base class only

    modifierChild1(int a, int b, int c) : modifier(a, b, c) {}; // modifier(a,b,c) is base constructor //parent class constructor is called first, if you don't want to pass this data then use default constructor in parent class.

    // this is inline constructor and it will call the base class construct as param passes in property(varaible), here param is passed to base constructor

    void fun(int a, int b, int c)
    {
        protectedVar = a; // it sets
        publicVar = b;
        //  privateVar = c;//error as private not accessable in derived

        cout << protectedVar << endl; // valid, but we can't write this in same way.
    }
};

class modifierChild2 : protected modifier
{
    // every property inherited will be traed as protected, priavate can't be inherited. This class can't be used in main but can be inderived.'

    string name; // here it is private for this

    void fun(int a, int b, int c)
    {
        protectedVar = a; // it sets
        publicVar = b;
        //  privateVar = c;//error as private not accessable in derived

        cout << protectedVar << endl; // valid, but we can't write this in same way.
    }

    // // constr not valid in derived id no default modifier present, only inline and pass it to main class

public:
    modifierChild2(string name, int publicVar, int protectedVar)
    {

        this->name = name;
        this->publicVar = publicVar;
        this->protectedVar = protectedVar;

        // here have access to use all possible from parent and from this class.
    }

    void display()
    {
        cout << name << " " << protectedVar << endl;
    }
};

class modifierChild3 : private modifier
{

    // make everything private whatever it inherits.
};

// hierarchical inheritance
class Human
{
protected:
    string name;
    int age;

public:
    Human(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};

class student : public Human
{
    int rollNo;
    int fees;

public:
    student(string name, int age, int rollNo, int fees) : Human(name, age)
    {
        // as it is child constructor , but before this we need to call parent constructor, just like inline ,here parent constructor  Human(name,age) is called first than it is appended here like this class constructor

        this->name = name;
        this->age = age;
        this->rollNo = 1;
        this->fees = 100;
    }
};

class teacher : public Human
{
    int salary;
    int experience;
};

// hybrid
class studentHybrid
{

public:
    void print()
    {
        cout << "I am student\n";
    }
};

class MaleHybrid
{
public:
    void Maleprint()
    {
        cout << "I am Male\n";
    }
};

class FemaleHybrid
{
public:
    void Femaleprint()
    {
        cout << "I am female\n";
    }
};

class girl : public studentHybrid, public FemaleHybrid
{
public:
    void girlPrint()
    {
        cout << "I am girl\n";
    }
};

class boy : public studentHybrid, public MaleHybrid
{
public:
    void boyPrint()
    {
        cout << "I am boy\n";
    }
};

// Multipath Inheritance

// we can take example of human, teacher, student, girl as merger of teacher and student

// hierarchical inheritance
class HumanMultiPath
{
protected:
    string name;
    int age;

public:
    HumanMultiPath()
    {
    }
    HumanMultiPath(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};

class studentMultiPath : public virtual HumanMultiPath
{
    int rollNo;
    int fees;

public:
    studentMultiPath()
    {
    }
    studentMultiPath(string name, int age, int rollNo, int fees) : HumanMultiPath(name, age)
    {
        // as it is child constructor , but before this we need to call parent constructor, just like inline ,here parent constructor  HumanMultiPath(name,age) is called first than it is appended here like this class constructor

        this->name = name;
        this->age = age;
        this->rollNo = 1;
        this->fees = 100;
    }
};

class teacherMultiPath : public virtual HumanMultiPath
{
    int salary;
    int experience;
};

class girlMultiPath : public studentMultiPath, public teacherMultiPath
{
public:
    string country;
    girlMultiPath(string name, int age, int rollNo, int fees, int salary, int experience, string country)
    {

        // this->name=name;//it showing error as name is ambigous, hence we will add virtual keyword to create oly one copy of name in child at the time of combining //hence virtual human is used instead of only human

        this->name = name; // no more error//human passed functions have become virtual
        this->age = age;

        this->country = country;
    }
};

//
//
//
// Polymorphism
//
//
//

// function overloading
class Area
{

public:
    int calculate(int a)
    {
        return 3.14 * a * a;
    }

    int calculate(int a, int b)
    {
        return a * b;
    }
};

//
// Operator overloading
//
// + used for addition and + is also used for concatenamtion. Hence it is operator overloading
// operator overloading done in class in the same way

class complex
{
    int real, img;

public:
    complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    complex()
    {
        // empty for creating ans constructor in this operator overlaod  //also helpful in storing the ans
    }

    void display()
    {
        cout << real << "+i" << img << endl;
    }

    // for adding two complex numbers, we can create operator overloding

    complex operator+(complex &C) // complex is return type
    {                             // here if we want C1+C2 then we can think that C is outside passed and C inside the parameter . C param is object of same class type hence it can access private data real and img.
        // this->real = real + C.real; // c.real accessable as object of same class
        // this->img = img + C.img;

        // using this will update the actual C, here we use the stored variable ans

        // C.img=123;//updated as actual com2 is passes//C2 address is passed

        complex ans; // for this we need ampty constructor
        ans.real = real + C.real;
        ans.img = img + C.img;

        return ans;
    }
};

//
//
//
//
// Virtual
//
//
class Animal
{
public:
    // parent animal pointer can store the child class address.
    // void speak(){
    //     cout<<"huhu"<<endl;
    // }

    // we will set it to virtual to decide the function at run time
    // void virtual speak()
    // {
    //     cout << "huhu" << endl;
    // }

    // here huhu will be printed in speak function becuae, at the compilt ime p pointer points to animal return type , P chagesd to new dog type hence it is done in run time as heap memory required. then compiler checks the p spaeck, hence it decides as currently animal is pointed hence it stores that animal speak to be called.

// here if we don't want to let to create object of this parent class as animal not speak particular sound, hence we can prevent using pure virtual initialized with 0 //this virtual function must be in all child ,

  void virtual speak()=0;//pure virtual fuction



};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "bark" << endl;
    }

    void kid()
    { // this function can't be called with animal pointer as this fuction is not present in animal class
        cout << "poppy" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Mew" << endl;
    }

    // if child class function overwrites the parent child fucntion at the time of calling, then we can store it's address in pointer and check all objects at the same time.

    // parent class pointer is beneficiall as all child class fucntion can overwrite it as per requirement and we don't need to call the function for each child one by one, we can simply use the loop .
};

int main()
{

    Customer c1(11, "c1", 435);
    c1.display(); // 11 c1 435 1 //upto this only one 1 is created hence count is 1
    Customer c2(21, "c2", 4353);
    c2.display();

    Customer c3(31, "c3", 43533);

    c1.display(); // keepin here return 3 for toalcount and it is static
    c2.display();
    c3.display();

    // cout << total_Acc << endl;
    // cout << Customer::total_Acc << endl;

    c3.display_total(); // 3

    // Customer::total_Acc = 8; // as initializer is changed, it will show different value as per startng from this and onward. //inittilizer can be changed only when public total_Acc else shows error

    Customer c4(41, "c4", 435303);

    c4.display_total(); // 9 //4 when no initilizer and private

    c4.staticDisplay();
    Customer::staticDisplay(); // 4

    Customer c5(51, "c5", 4000);

    Customer::staticDisplay();
    c5.deposit(800);

    Customer::staticDisplay();
    c5.withdraw(200);
    Customer::staticDisplay();

    // order of command matters

    // encapsulation
    // putting all data(variable) and information(function) at one class place
    //
    EncapUsers E1(1, "Sudha", 21, 2000);
    // cout<<E1.Name<<endl; //error as it is private
    // E1.age=-4;//if puvlic then it would heve updated.

    E1.display(); // 1 Sudha 21 2000
    // even passing with the constructor not checked the validity, hence intead of passing values in constructor and directly updating, we need to use function check.

    // we want to update later then we need to make seperate functions

    E1.setAge(10);  // 1 Sudha 10 2000//
    E1.setAge(-15); // invalid age//not update and old age remains
    E1.display();

    EncapUsers E2(1, "Sud", -22, 2000); // 1 Sud 0 2000//as invalid age hence it will set it 0.
    E2.display();

    // Abstraction
    // hiding unnecessary details from the user only function user need to call from the class.
    // update age is a function , we don't need to check the internal loding.

    // here when another file is present, then it will be able to see the main content , class code is not shown in another file.

    // ideal code has everything in class instead of showing in main.

    //
    // modifier public,protected, private
    //
    modifier m1(1, 2, 3);
    m1.display(); // display is inside the class hence modify all.

    // external code in the main
    // m1.privateVar = 6;//invalid
    // m1.protectedVar = 6;//invalid access
    m1.publicVar = 8; // valid

    // for checking protected, we need to create a derived class.

    // Inheritance //hierarchial inheritance
    modifierChild1 mc1(5, 6, 7);
    // checkDerivedProperty c1(5, 6, 7);
    mc1.display();                 // 5 6 7 //here we managed to access
    cout << mc1.publicVar << endl; // only public accessable//7

    mc1.fun(10, 11, 12);
    mc1.display(); // 5 10 11 //only able to change public and protect from derived fuction as it has nly access to that.

    modifierChild2 mc2("Sudha", 19, 20);
    mc2.display(); // it is also inherited as proteced.from parent // hence we  refined it in protected inherited with public function

    // private can't be even inherited.

    // types of inheritance
    // single inheritance

    // student(string name, int age, int rollNo, int fees) : Human(name, age)
    student s1("Shanaya", 21, 115, 100);
    s1.display(); // Shanaya 21

    // multilevel inheritance
    principaHu MultiLevel("Sudha", 21, "CSE", 200, "LU");
    MultiLevel.display();

    // multiple inheritance has many parents and one child
    coder MultipleInh("Sudha", "CSE", "100");
    MultipleInh.display(); // Sudha CSE 100

    // Hierarchical Inheritance//one parent , multiple child inherit
    // Human(parent) and Student, teacher, staff are child
    // we have covered above in form if Modifier

    // Hybrid inheritance
    // Combination all makes hybrid inheritance
    // like suppose we are using multiple + heirarchical inheritacne.

    // Male inherited by boy,
    // Female inherited by girl.
    // girl and boy are child of student(hirarchila)

    // boys is male and student both hence multiple.

    girl g1;
    g1.girlPrint();
    boy b12;
    b12.Maleprint();
    b12.print();
    b12.boyPrint();

    // Multipath Inheritance
    // when same name and function travel through different path then multiple copy of same is formed.hence it creates confusion.

    // human
    // youtuber ,  Engineer both inherited Human
    // Coder is child of both youtuber ,  Engineer
    // here all attributeas nad dunction from human travel to both youtuber ,  Engineer hence when merge then contains dublicate, hence we use virtual to prevent multiple copies of the same.

    girlMultiPath GM("Sudha", 21, 115, 100, 1000, 2, "India");
    GM.display(); // Sudha 21

    //
    //
    //
    //
    // Polymorphism
    //
    //
    // function overloading
    Area A1, A2;
    cout << A1.calculate(4) << endl;    // 50 //area of cirlce
    cout << A2.calculate(4, 7) << endl; // 28//area of sq
    // cout<<A2.calculate("4")<<endl;//error as not string param defined

    //
    //
    // Operator overloading
    //
    //
    complex com1(2, 5);
    com1.display();
    complex com2(3, 9);
    com2.display();
    complex com3 = com1 + com2; // it is takes as com1 first creates object com1 with it's data, then it access com2 , as + is used in between hence we need operator overloading + to specify that if same class object type is shared with this operator than perform that perticular fucntion //com1(com2) //it gives return tye of complex only //but it is not exactly, here com2 is not updated but it has direct acces to be updated.

    // com3.display();
    // com2.display();//
    // com1.display(); //com1 is update with this update

    com3.display();
    com2.display();
    com1.display(); ////not updates when ans empty variable used instead of this.

    //
    //
    //
    // Virtual keyword
    //
    // virtual keyword help to decide the function at run time with the address it contians
    Animal *virt;
    virt = new Dog();
    virt->speak(); // huhu

    // for letting the actual runtime address stored in the pointer to speak, than add virtual before speak function in parent to let it decide at the run time
    // bark after adding virtual

    // for printing bark we cout have simply used direct call like
    Dog Dg;
    Dg.speak();

    // ya it woul have worked but what if we have many objects child of parent , in that case making new object again and agian will be not beneficial, hence we use pointer of parent class and child class with same name overwrites it.

    // eg
    // let's create a vector storing the address of all child class of animal
    vector<Animal *> addr; // here a vector is created that stores the addresss, and of animal type

    addr.push_back(new Dog()); // it stores address of child class
    addr.push_back(new Cat());
    addr.push_back(new Dog());
    addr.push_back(new Cat());
    addr.push_back(new Dog());
    addr.push_back(new Cat());

    // here we created mutiple object , now we want to produce the soun

    Animal *p;

    for (int i = 0; i < addr.size(); i++)
    {

        addr[i]->speak(); // address point object and run function in that object

        // we could have used animal pointer also
        // p = addr[i];
        // p->speak();
    }

    return 0;
}