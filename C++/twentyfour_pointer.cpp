// Double Pointer and Multiple Pointers in C++

#include <iostream>
using namespace std;

// for n time *** pointer , it has n-1 pointer and and last points to int datatype.//the very last pointer

void five(char *str1, char *str2)
{
    while (*str1 = *str2) //this will copy whole str2 to str1 until \0 is found in both  to break this while loop. hence even if str1 has more characters and str2 has less then rest empty characters will be used to replace rest str1 characters
    {
        str1++;
        str2++;
    }
}

int four(int x, int *py, int **ppz)
{

    //  cout<< " x"<<x<<" py : "<<*py<<" **ppz"<<**ppz<<endl;

    // x=4,py=address of 4, ppz address of py
    int y, z;
    **ppz += 1;
    z = **ppz; // x has varaible value not any address storeage hence not affect x//it affects the value at that address//z=5
    // cout<< " "<<x<<" "<<" here"<<z<<endl;//x has no address storage whose value will be updated. here x is a variable which has a value and it not points to the any address predefined hence x remains unaffected of it's value
    *py += 2; //
    y = *py;  // y=7

    x += 3;           // x=7
    return x + y + z; // 7+7+5
}

void second(int *p1, int *p2)
{
    p1 = p2; // now p1 has address of p2
    *p1 = 2; // it will update p2 pointed value j, to 2
}

void fun(int *pre)
{
    // pre++;//address updated t0 pointer.
    // cout<<pre<<endl;//0x61ff0c
    // value can't be updated like//*pre++//error

    *pre = *pre + 1; // 11//value updated
}

void dobfun(int **pre)
{

    **pre = **pre + 1; // 12//value updated
}

int main()
{
    int a = 10;
    int *p = &a; // single pointer
    cout << a << endl;
    cout << p << endl;     // 0x61ff08
    cout << p + 1 << endl; // it will add address sizes //0x61ff0c //it has become 13 from 8 by adding 4.

    cout << p << endl; // no change  // 0x61ff08

    int **ptr = &p; // double pointer // Here is debug: we have created a pointer *ptr and this ptr is pointing a pointer hence * is added in front of it and the pointer it is pointing is point to an int datatype.

    cout << ptr << endl;   // 0x61ff04
    cout << &p << endl;    // 0x61ff04
    cout << *ptr << endl;  // address of p //0x61ff08
    cout << **ptr << endl; // 10

    *ptr = *ptr + 1; // 0x61ff0c

    cout << p << endl;     // changes from  0x61ff08 to 0x61ff0c
    cout << a << endl;     // 10
    cout << **ptr << endl; // 6422276 //random value as adrress of p

    // to recheck back we converting it here
    *ptr = *ptr - 1;
    cout << p << endl; // 0x61ff08
    fun(p);
    cout << a << endl; // 11

    dobfun(ptr);

    cout << a << endl; // 12

    // triple pointer
    int ***ptri = &ptr;
    cout << ptri << endl;    // 0x61ff00
    cout << *ptri << endl;   // 0x61ff04//same as address of ptr as it is pointed.
    cout << **ptri << endl;  // 0x61ff08
    cout << ***ptri << endl; // 12

    // for mdifying with pointer
    // *p=*p+1;
    // **p1=**p1+1;
    // **p2=**p2+1;
    // any way to use to modify the value

    // we can make four pointer.

    // Gate question to find the output
    // 1.

    char c[] = "GATE2024";
    char *pc = c;
    cout << pc + pc[3] - pc[1]; // find it ? p holds the address, p[3] is E and p[1] is G then convert *(p+3*size)// hence 4    then add base address. //hence it will move to next 4 element//2 address is base address, as character cout get the base address means it will print until it gets null character means upto end.

    // optput: 2024

    cout << endl;

    // problem 2
    int i = 0, j = 1;
    second(&i, &j);
    cout << i << " " << j << endl; // 0 2

    // problem 3
    int *ptrtry;
    int xtry = 0;
    ptrtry = &xtry;
    int ytry = *ptrtry;                  // 0
    *ptrtry = 1;                         // xtry=1
    cout << xtry << " " << ytry << endl; // 1 0

    //  problem 4
    int a4 = 5, b4 = 10;
    int &name4 = a4; // it means name is a variable which also points to address value a4. a4 and name4 have same location
    int *ptr4 = &a4;
    (*ptr4)++;                       // a4=6
    ptr4 = &b4;                      // 10 address
    *ptr4 = *ptr4 + 5;               // 10+5//15
    name4 += 5;                      // a4=6+5=11
    cout << a4 << " " << b4 << endl; // 11 15

    // problem 5
    int c5, *b5, **a5;
    c5 = 4;
    b5 = &c5;
    a5 = &b5; // all are connected pointers
    cout << four(c5, b5, a5) << endl;

    // problem 6
    // string copy code
    // char string1[] = "kriti";
    char string1[] = "Shanaya";
    char string2[] = "Sudha";
    // char *first=string1;//we could have passed first and second also
    five(string1, string2);
    cout << string1 << endl;//Sudha
}