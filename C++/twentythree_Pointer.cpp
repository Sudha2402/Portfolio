#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Pointer in C++

// pointer in array
// pointer in char

// pass by pointer

// pass by pointer

// Note: for simplicity use the following only in prefereed way
// for vect, string - reference helps using & in function
// for int arr, char - pointer helps.




void swapFun(int *a, int *b)
{ // p[] //we can have done with pass by reference also.

    cout << a << " " << b << endl; // 0x61feb4 0x61feb0
    int temp = *a;
    *a = *b;
    *b = temp;
}

//
void doublearr(int arrDoub[], int size) // pass by refernce must take size
// void doublearr(int *arrDoub)
{

    // cout<<sizeof(arrDoub) / sizeof(arrDoub[0])<<endl;//it will alway take 1 hence size need to be passed in passs by reference
    for (int i = 0; i < size; i++)
    {
        arrDoub[i] *= 2;
        cout << "inside" << endl;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arrDoub[i] << " ";
    }

    cout << endl;
}

// using pointer
// void doublearrPointer(int *arrDoub)//it also works
void doublearrPointer(int arrDoub[]) // it also works
{
    //   we always need to pass the size in case of iteration in array //method to find will always return 1.

    for (int i = 0; i < 7; i++)
    {
        arrDoub[i] *= 2; // works
        // *(arrDoub + i) *= 2;//works
        cout << "inside" << endl;
    }

    for (int i = 0; i < 7; i++)
    {
        cout << arrDoub[i] << " "; // 8 12 16 8 20 32 28
    }

    cout << endl;
}

void Update(int *varUp)
{
    // *varUp = varUp +7;error as normal tring to store in ptr
    *varUp = *varUp + 7;
}

void pass(vector<int> &v)
{
    for (int i = 0; i < 5; i++)
    {
        v[i] = 7;
    }
}

int main()
{

    int a = 10;
    float b = 30;
    int c = 70;
    int *ptr = &a;
    float *ptr2 = &b;

    cout << ptr << endl;         // 0x61ff04//address where a is stored
    cout << *ptr << endl;        // 10//value of a
    cout << sizeof(ptr) << endl; // 4 byte//always as 4GB uses 32 bit address

    //  ptr=b;//error
    // ptr = &b;//as b is float hence it can't be assigned and updated

    ptr = &c; // int pointer can be updated with int type variable.

    cout << ptr << endl;  // 0x61ff04
    cout << *ptr << endl; // 30

    cout << sizeof(ptr2) << endl; // 4//4 byte

    // how to store the address of an array.

    int arr[] = {4, 2, 6, 3, 5, 2};

    // to prit all its value using pointer.
    // arr[i]=*(arr+i)= *(arr+ i*size of data)//arr is base address

    cout << sizeof(arr) << endl; // 24 // 4*6 as 6 data and each int of 4 bytes

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " "; // 4 2 6 3 5 2
    }
    cout << endl;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << *(arr + i) << " "; // 4 2 6 3 5 2// // i+arr works, hence
    }
    cout << endl;

    cout << arr << endl;   // 0x61fed8
    cout << &*arr << endl; // same as arr//0x61fed8//*arr give value and & gives that value address.

    // Print the address
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << (arr + i) << " "; // 0x61fed8 0x61fedc 0x61fee0 0x61fee4 0x61fee8 0x61feec
    }
    cout << endl;

    // Print the vlaue using extra pointer.
    int *ptr3 = arr;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << *(ptr3 + i) << " "; // 4 2 6 3 5 2
        // cout<<ptr[i]<<" ";//4 2 6 3 5 2//same same
    }
    cout << endl;

    // Print the address using extra pinter
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {

        cout << ptr3 << " "; //
        ptr3++;              // ptr2=ptr2+1//also evaluated in same way.//0x61fecc 0x61fed0 0x61fed4 0x61fed8 0x61fedc 0x61fee0 //points to next adrees

        // ptr-- is alsoclaculated this way //ptr- i*size of data
    }
    cout << endl;

    ptr3 = arr; // bring it back to start as in above we incremented and updated together.

    // ptr+3//also works but make sure not to get out of range

    cout << ptr3 << endl;     // 0x61fee4
    cout << ptr3 + 1 << endl; // 0x61fee8//moved 4 step forward
    cout << ptr3 - 1 << endl; // 0x61fee0 //move 4 step back

    // we can also print it's value
    cout << *ptr3 << endl;       // 4
    cout << *(ptr3 + 1) << endl; // 2//moved 4 bitsstep forward
    ptr3++;                      // 4 to 2 then in next line back
    cout << *(ptr3 - 1) << endl; // 4

    // note since we setted. ptr3=arr but it does not means if we increasement ptr, then arr can also be incremented, no arr value is fixed.
    // arr++ and arr-- worng //ptr++ and ptr-- alowed. //base address of arr is never removed or changes.

    // arr++;//arror as address can't be update from symbol table only value is updateable.
    cout << arr << endl;

    char arrC[5] = {'1', '7', '3', '4'};
    // for(int i=0;i<sizeof(arrC)/sizeof(arrC[0])){
    // error
    // }

    cout << arrC << endl; // 1234 //only this is enough to print char characters array

    // char *charPointer=&arrC;//error as arrC is alread an adress not thevalue
    char *charPointer = arrC;           // ok
    cout << charPointer << endl;        // 1734
    cout << *charPointer << endl;       // 1
    cout << &*charPointer << endl;      // 1734//char never gives the address this way
    cout << *(charPointer + 1) << endl; // 7

    // char array
    char arrcharFull[5] = "1234"; // null will be taken at last index.//it is a way to write array.

    cout << arrcharFull << endl; // 1234//this used to print the whole array. It's implementation different, hence when arrcharFull should store address, it stores address but it is implimented such way that  if a value is present at that address then return it as output insted of address.  //it keep printing until null charaxter is found.

    // external pointer also prints the data whenever present at address.

    // To print address, we have a logic for it. //we use void pointer
    // here we are changing character type pointer to void pointer, hence as datatype is not known then it will print only address pointed insed of data as implimented in char.
    // this is called type casting from char to void

    cout << (void *)arrC << endl;        // 0x61fec3
    cout << (void *)charPointer << endl; // 0x61fec3

    cout << (void *)arrcharFull << endl; // 0x61febe

    // as no loop is need to print char array, it will keep printing until they find null character in array

    char name = 'a';
    cout << &name << endl;        // random value but not address
    cout << (void *)name << endl; // 0x61

    //  twentythree_Pointer.cpp:145:16: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
    //   cout<<(void*) name<<endl;

    // we can also store the address, the print it.
    char *addchar = &name;
    cout << addchar << endl;         // a1234//random data
    cout << *addchar << endl;        // a
    cout << (void *)addchar << endl; // 0x61feb9
    cout << (void *)&name << endl;   // 0x61feb9

    // Now one more way to do this without using void *, that is using static_cast

    // cout<<static_cast<void*>(name)<<endl;//error as name is not a ponter

    cout << static_cast<void *>(&name) << endl;   // no error as name adrress is kind of pointer is not a ponter//0x61feb9
    cout << static_cast<void *>(addchar) << endl; // no error as it is a pointer//0x61feb9

    int aSwap = 5, bSwap = 10;
    cout << &aSwap << " " << &bSwap << endl; // 0x61feb4 0x61feb0 //same address
    swapFun(&aSwap, &bSwap);
    cout << aSwap << " " << bSwap << " " << endl; // 10 5 //it has swapped now

    // function to double an array
    int arrDoub[] = {2, 3, 4, 2, 5, 8, 7};

    //  cout<<sizeof(arrDoub) / sizeof(arrDoub[0])<<endl;//7

    int size = sizeof(arrDoub) / sizeof(arrDoub[0]);

    for (int i = 0; i < size; i++)
    {
        cout << arrDoub[i] << " ";
    }
    cout << endl;

    // doublearr(arrDoub);
    // doublearr(arrDoub); //it pass only first index in array and size inside will be shown 0.

    doublearr(arrDoub, size);

    for (int i = 0; i < sizeof(arrDoub) / sizeof(arrDoub[0]); i++)
    {
        cout << arrDoub[i] << " ";
    }

    cout << endl;

    doublearrPointer(arrDoub);

    // Updating a variable
    int varUp = 10;
    Update(&varUp);
    cout << varUp << endl; // 17

    // pass by reference.
    int refre = 10;
    cout << &refre << endl;   // 0x61fe7c
    int &tempref = refre;     // note this //refre is taken as pointer &(*refre) //hence it works this way
    cout << tempref << endl;  // points the value
    cout << &tempref << endl; // points the same address as refre //0x61fe7c

    vector<int> v(5, 0);
    pass(v);

    for (int i = 0; i < 5; i++)
    {
        cout << v[i] << " "; // 7 7 7 7 7
    }
}
