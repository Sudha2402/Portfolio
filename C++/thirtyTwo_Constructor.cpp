#include <iostream>
using namespace std;

// When object is made , it is not initialized with any value hence we need to set it with constructor for good coding.

// It is necessary to initilize for creating a good object.

// as same name hence , it points to the nearest scope value hence both points to parameter not the attribute.

// here in this case it creats new space by itself and this value is put there, not valid.

// to solve this problem , we use this pointer which points to object

// this stores object address. means this is a pointer.hence we can access like a pointer.

// now this is sending the address. hence it points to attribute.

// constructor is called everytime by itself//this is bydefault same value for every object. hence we use constructor initializer.

class Customer
{
public:
    int AccountNum;
    string Name;
    int balance;
    int *loan; // we want to dynamically allocate this value

    int *reservedArrayInHeap; // if we any space to be reserved in advance so that when long program runs, we don't face the problem in between due to lack of storage

    string address;
    int order;

    // by default it makes a constructor, a kind of function with no return type
    Customer()
    { // for this to  work when object is created, it must be public
        // empty constructor created by compiler if explicity with same classname, a function is made

        reservedArrayInHeap = new int(100); // reserved 100 int size and if not able to allocate then it shows error.and saved my time

        cout << "Constructor is called" << endl;

        AccountNum = 123; // it will set it bydefault for all objects, hence only in case of default but actually, all can't be with this same value //here as not local scope value with same parameter, hence not creates problem,
    };

    // Parameterized constructor
    Customer(int AccountNum, string Name, int balance)
    {
        // AccountNum = AccountNum; // this refers to local scope not the attribute, for pointing to attribute , we need to use pointer

        this->AccountNum = AccountNum;
        (*this).Name = Name;
        this->balance = balance;
    }

    // constructor overloading
    Customer(string Name, int balance)
    {
        (*this).Name = Name;
        this->balance = balance;
    }

    void display()
    {
        cout << AccountNum << " " << Name << " " << balance << endl; // if not defined for an object then gives garbage value
    }

    // Inline COnstructor
    // inline Customer(string Name, int balance,int accountNum) : this->Name(Name)//this not valude here in inline//same name error
    inline Customer(string N, int b, int a) : Name(N), balance(b), AccountNum(a) {}

    // constructor helps in arranging the resources in advance so that we don't face problem in run time.

    // here we we want space of 100 array size, then we can initialize it in construct, if available then it gives no error but if no resources can be s=assigned then it saves time by giving error at start.

    // copy  constructor
    Customer(Customer *B)
    { // pass by reference with the help of pointer, we could have directly used & also //if reference is not passed then copy will keep searching as it itself need copy.
        Name = B->Name;
        AccountNum = B->AccountNum;
        balance = B->balance;
    }

    Customer(Customer &B)
    { // pass by reference with the help of pointer, we could have directly used & also
        Name = B.Name;
        AccountNum = B.AccountNum;
        balance = B.balance;
    }

    // Customer(string name,int loan)
    Customer(string name, string address, int lo, int order)
    {
        this->address = address;
        this->Name = Name;
        // the loan passed has to be allocated dynamically

        // this->loan=new int;//loan dynamically creates int datatype.
        // if different name then parameter, we could have used

        loan = new int; // since same name hence we need to use pointer this.//loan keeps address of dynamically created int space.

        *loan = lo; // loan pointer jis storage par point kar raha h vaha lo value dal do.

        this->order = order;

        cout << "constructor" << order << " is called" << endl;
    }

    // deconstructor
    ~Customer()
    {
        // deconstructor made by compiler to remove all dynamicaqlly alloted memory at the end.
        cout << "destructor" << order << " is called" << endl;

        // delete loan; // as loan is not alloted in all hence , it is showing error for other objects without loan defined deconstructor //

        // deconstructor are in reverse order beacuse it may be possible that previous object is used ny next constructor. //constructors are called in order
    }
};

int main()
{

    Customer c1;
    // cout<<"Constructor"<<endl;//meaningless object

    cout << c1.AccountNum << endl; // 123
    c1.display();                  // 123  1994058320//garbage value for not initialized.

    Customer C2(123, "Sudha", 0); // meaning ful object with initialization
    cout << C2.Name << endl;      // Sudha

    C2.display();

    Customer C4(13, "Sana", 1021);
    C4.display(); // 13 Sana 1021

    Customer C3("Shanaya", 90);
    C3.display();

    // Customer(string Name, int balance,int accountNum)
    Customer C5("Shanaya", 0, 344);
    C5.display();

    Customer customerInline("John Doe", 5000, 12345); // as per inline//12345 John Doe 5000

    customerInline.display();

    // dynamically allocate memory to the object
    Customer *customer2 = new Customer("Jane Smith", 3000, 67890);
    // Don't forget to delete later!
    delete customer2;

    // to copy the data of customer2 in customer3
    Customer customer3(customerInline); // 12345 John Doe 5000 //copy object customerInline data to customer3 object.
    cout << endl;
    customer3.display();

    // If we want to create copt constructor then we can do that
    Customer customer4(customer3); // I will myself create copy constructor
    customer4.display();

    // or we can use copy contructor with = sign also
    Customer customer5; // it will call empty constructor as no param passed.
    customer5 = customer4;
    customer5.display(); // 12345 John Doe 5000

    // destructor need's not to be called, it is callled automatically.

    Customer customerDec("Deca", "lucknow", 300000, 1), customerDec2("Deca", "lucknow", 300000, 2), customerDec3("Deca", "lucknow", 300000, 3);
    customerDec.display();

    // if object is dynamically alloted, then deconstructor is used to delete it.

    Customer *CustomDyn = new Customer; // dynamically created the object. For this deconstructor need to be called.
    CustomDyn->Name = "hello";
    CustomDyn->display(); // 123 hello 3000

    cout << "Address is: " << &CustomDyn << endl; // 0x61fa78

    delete CustomDyn; // calls the destructor for this dynamically allocated variable.
    // destructor0 is called

    cout << "Address is: " << &CustomDyn << endl; // 0x61fa78

    // destructor takes place in reverse order.

    
}