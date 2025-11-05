#include <iostream>

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#include <exception>

// Exception handling//handle unexpected problem

class Customer
{
    int AccNo;
    string Name;
    int Balance;

public:
    Customer(int a, string b, int c)
    {
        AccNo = a;
        Name = b;
        Balance = c;
    }

    void display()
    {
        cout << AccNo << " " << Name << " " << Balance << " " << endl;
    }

    void deposit(int amount)
    {
        if (amount > 0)
        {
            Balance += amount;
            cout << "Amount is deposited successfully\n";
        }
        else
        {
            cout << "Amount is not valid\n";
        }

        // instead of handling with if else we can use try and catch as it is more readable and has different exaception defined
    }
    void withdraw(int amount)
    {
        if (amount > 0 && Balance >= amount)
        {

            Balance -= amount;
            cout << "Amount is withdrwn successfully\n";
        }
        else
        {
            cout << "balance is low\n";
        }
    }
};

// user defined error
class InvalidAmountError : public runtime_error
{
public:
    InvalidAmountError(const string &msg) : runtime_error(msg){};
};

class InsufficientBalanceError: public runtime_error{
    public:
    InsufficientBalanceError(const string &msg): runtime_error(msg){};
};

class CustomerTryCatch
{
    int AccNo;
    string Name;
    int Balance;

public:
    CustomerTryCatch(int a, string b, int c)
    {
        AccNo = a;
        Name = b;
        Balance = c;
    }

    void display()
    {
        cout << AccNo << " " << Name << " " << Balance << " " << endl;
    }

    void deposit(int amount)
    {
        if (amount < 0)
        {
            // throw "Amount is not valid\n"; // ternminates here and aything below this function is not called

            // whenever throw is found then , it terminates from there immediately that function hence further execution not happens and it comes to the catch part.

            // throw runtime_error("Amount is not valid\n"); // we can ourself define the run time error.

            // we can use user defined error also.
            throw InvalidAmountError("Amount is not valid user error\n");
        }

        Balance += amount;
        cout << "Amount is deposited successfully\n";

        // instead of handling with if else we can use try and catch as it is more readable and has different exaception defined

        // we could have diretl solve
    }
    void withdraw(int amount)
    {
        if (amount > 0 && Balance >= amount)
        {

            Balance -= amount;
            cout << "Amount is withdrwn successfully\n";
        }
        else
        {
            // throw "balance is low\n";     // terminates here and returns

            // throw runtime_error("balance is low\n");

              throw InsufficientBalanceError("balance is low user defined\n");

            cout << "terminated" << endl; // it is not even called as terminated from above line , other functions will work but this function will not work
        }
    }
};

// types of exception
// runtime error
// memory allocation error

// let's make how exception class occurs
// this exception class only for imagination

class exceptionTrailTexted
{ // in real exception is alloted like this.
protected:
    string msg;

public:
    // constructor
    exceptionTrailTexted(string msg)
    {
        this->msg = msg;
    }

    string what()
    {
        return msg;
    }

}; // this is only for Understanding that how Exception class looks like, here exception class name is renamed so that compiler keep taking the original one.

// we can imagine runtime error also, here runtime class is defined with slight name chage for compiler to not include this
class runtime_errorTrailTexted : public exceptionTrailTexted
{
public:
    runtime_errorTrailTexted(const string &msg) : exceptionTrailTexted(msg) {};
};

int main()
{
    Customer C1(1, "Sudha", 0);
    C1.display();
    C1.deposit(-12);
    C1.withdraw(23);

    CustomerTryCatch C2(1, "Sana", 0);
    C2.display();
    try
    {

        C2.deposit(-12);
        C2.withdraw(20);
    }
    // catch (const char *e{ // char string is return type, we are passing the pointer as point to string first char the print until \0 is found //const added so that we don't try to modify here as we are using either direct pointer or address
    catch (const runtime_error &e)
    { // on defining the runtime error , then it will throw object//hence we catch the address of object and also add const so that we do not update or change the message
        // cout << "Exception occured: " << e << endl;//in case of string
        cout << "Exception occured: " << e.what() << endl;
    }
    catch (const bad_alloc &e)
    {
        cout << "Exception occured: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Exception occured: " << endl; // in else cases
    }
    // such way is more readable.hence we use try , catch

    // exceptions

    int a, b;
    cin >> a >> b;
    if (b == 0)
    {
        cout << "divide by 0 error\n";
        return 0; // terminate the mqin here and further code not run/
    }

    int c = a / b;
    cout << c << endl;

    try
    {
        if (b == 0)
        {
            throw "divide by 0 error\n";
        }

        int c = a / b;
        cout << c << endl;
    }
    catch (const char *e)
    {
        cout << "Exception occured: " << e << endl;
    }

    // memory allocation error
    try
    {
        // int *p = new int  [100000000000000000]; // error //even when creating in my compiler,
        int *p = new int[10000000]; // error //even when creating
        cout << "memory allocated\n";
        delete[] p; // it returns a pointer onject as an error and object is exception //here exception is thrown even in build by compiler without we need to write it.
    }
    catch (const exception &e)
    { // we get first address of exception
        cout << "Exception occured due to in line 168: " << e.what() << endl;
    }
    // std: bad allocation show, which child class of exception throws the error, and it showns object of that class, hence we can write that class name also as that class object is thrown and it receives.

    // user defined error







    // whenever catch occurs it stop from there as here catch is in main function hence it will come out of main scope , means stops executing thereafter. Hence we can use function catch to let main execute.

    

    return 0;
}
