#include <iostream>
// it is not included in header as we need to fix some bugs in it and it should be fixed by coder, hence compiler is not prebuilt with this.

using namespace std; // it remove the writing of std:: again and again

int main()
{

    std::cout << "Hello\n";
    std::cout << "C++\n";
    std::cout << "C++" << endl; // end line also works in the same mannner
    cout << "C++" << endl
         << 2 + 3 << endl;
    cout << 2 + 3 << endl; // it will perform operation

    int a = 2, b = 9;
    cout << a + b;

    char c = 's'; // only single quoute is allowed in char

    cout << endl
         << c << endl;

    float f = 43.43;
    double d = 3.1233;
    // long int li = 4343432434645;//too long for insertion

    bool bo = false; // 0
    cout << bo << endl;
    int g, e;

    cout << "enter a number:";
    cin >> g;
    cout << "enter a number:";
    cin >> e;
    cout << g + e << endl;

    cin >> g >> e;                             // extract from keyboard >>
    cout << "Sum of number:" << g + e << endl; // insert at the output

    // redeclaration error when same variable is declared again

    // type casting
    int aint = 34;
    char bchar = 'c';
    aint = bchar;
    cout << aint << endl; // 99
    int cint = 67;
    bchar = cint; // C //it is storing ascii value of 67 to store in char
    cout << bchar << endl;
    aint = 4433; // it can't be stored in ASCII as more size required than 8 bits, //hence data lost will happen
    bchar = aint;
    cout << bchar << endl; // bchar

    int package;
    cout << "Enter your package :";
    cin >> package;
    if (package > 1000000)
    {
        cout << "Accepted\n";
    }
    else
    {
        cout << "Rejected\n";
    }

    // vowels and consonent

    char character;
    cout << "Enter your character :";
    cin >> character;
    if (character == 'a' or character == 'b' or character == 'c' or character == 'd' or character == 'e')
    {
        cout << "vowel\n";
    }
    // else if( char(character)=)
    else
    {
        cout << "consonent\n";
    }

    // in most case we need to write else with enter a valid number

    for (int a = 1; a < 6; a++)
    {
        cout << "Sudha\n";
    }

    int times;
    cout << "Enter the number of times :";
    cin >> times;

    int count = 1;
    while (count <= times)
    {
        // cout << "Sudha\n";

        // cout << count*count<<"\n";

        if (count % 2 == 0)
        {
            cout << count << "\t";
        }

        count++;
    }

    // to print alphabets
    for (char i = 'A'; i <= 'z'; i++)
    { // here smal and caplock is different
        cout << i << "\t";
    }

    for (int i = 5; i > 0; i--)
    {
        cout << i << "\t";
    }

    //   print numbers with digit difference 3
    for (int a = 1; a < 101; a++)
    {
        if (int(a / 10) - int(a % 10) == 3 or int(a % 10) - int(a / 10) == 3)
        {
            cout << a << "\t";
        }
    }

    for (int a = 1; a < 101; a = a + 3)
    {

        cout << a << "\t";
    }

    // to calculate the power
    int number = 5;
    int power = 3;
    int count = 1;
    int result = number;
    while (count < power)
    {
        result *= number;
        count++;
    }

    cout << result;

    // sum of n natural number //101
    int sum = 0;

    for (int a = 1; a < 7; a++)
    {
        sum += a;
    }
    cout << sum;

    // factorial of a number//7
    int fact = 1;

    for (int a = 2; a <= 7; a++)
    {

        fact = a * fact;
    }
    cout << fact;

    // to check prime
    int numisPri = 70;
    if (numisPri <= 1)
    {
        cout << "Neither prime nor composite";
    }
    else if (numisPri == 2)
    {
        cout << "prime\n";
    }
    else
    {
        bool isPrime = 1; // efficient
        for (int i = 2; i * i <= numisPri; i++)
        {

            if (numisPri % i == 0)
            {
                cout << "not prime\n";
                isPrime = 0;
                break; // it terminates the for loop
            }
        }
        // if(isPrime==1){
        if (isPrime)
        {
            cout << " prime\n";
        }
    }

    //  fabonacci series
    int first = 0;
    cout << first << "\t";
    int second = 1;
    cout << second << "\t";
    int temp;
    int current;
    for (int i = 1; i <= 7 - 2; i++)
    {
        current = first + second;
        cout << current << "\t";
        temp = first;//not needede
        first = second;
        second = current;
    }
};
//
// } //any will work
