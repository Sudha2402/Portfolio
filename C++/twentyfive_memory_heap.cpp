#include <iostream>
using namespace std;

// dynamic memory location in heap using new keyword.
// try to read from right to left for eay visualization

// 1D array dynamic memory allocation

// 2D array with the help of pointer

// 3D array in heap. here we need to create many twoD array to form 3D array.

int main()
{

    // to allocate heap memory for varaible.

    int *ptr = new int;
    cout << ptr << endl; // 0x871ee8
    *ptr = 5;
    cout << *ptr << endl; // 5

    float *ptrfloat = new float;
    cout << ptrfloat << endl; // 0x1101ef8
    *ptrfloat = 5.8;
    cout << *ptrfloat << endl; // 5.8

    // to create array in heap
    int n;
    cout << "Enter the size of heap array: ";
    // cin>>&n;//error//this is in c
    cin >> n;
    int *ptrarr = new int[n];

    for (int i = 0; i < n; i++)
    {
        // cin >> ptrarr[i];
        ptrarr[i]=i;
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << ptrarr[i] << " ";
    }
    cout << endl;

    // delete keyword
    delete ptr;
    delete ptrfloat;
    // delete []ptrarr;
    delete[] ptrarr;

    // 2D array with help of pointer. //5 row 3 col
    int **prtPointer = new int *[5]; // create array of 5 size that stores pointer and pointer points to int datatype. //hence double pointer is used  **prtPointer because two times pointing is happening in between.main data is array formed to visit it, forst from pointer array row and just back this pponter hence two time pointer

    for (int i = 0; i < 5; i++)
    {
        prtPointer[i] = new int[3]; // 1D array for each row
    }

    // to enter data in 2D array

    cout << "Enter the data in 2D array:\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // cin >> prtPointer[i][j]; // 1D array for each row  *(*(ptr+i)+j) //this is way to get data

            prtPointer[i][j]=i+j;
        }
        cout << endl;
    }

    // to print 2D data
    cout << "Print the data in 2D array:\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << prtPointer[i][j] << " \t "; // we use just like 2D static array
        }
        cout << endl;
    }

    // delete the heap data
    for (int i = 0; i < 5; i++)
    {
        delete[] prtPointer[i]; // 1D array for each row, it is used to access the address then specify that it is array datatype usinge [ ] after delete
    }

    delete[] prtPointer; // pointer array

    // 
    // 
    // 
    // 
    // 3D array in heap //5*4*3//3 2D, //we can ask this value from user also , just replace the variable where this dimension is written
    int ***ptrpointer3D = new int **[3]; // this way we think from right to left. we have to create 3 sheets, 3 size pointer storing each 2D address and each 2D has it's anonter point storage then that pointer access the data// we cantake idea of 3D pointer using this also
    //  *(*(*(ptr+k)+i)+j)//here after opening we got 3 pointers hence 3 pointers are used.

    // to create all 1 D possible in 3D
    for (int k = 0; k < 3; k++)
    {

        // below is for 2D
        ptrpointer3D[k] = new int *[5]; //this is as we neede dfor 2D pointer.
        // here we need to create 2D array pointer of 1D also

        for (int i = 0; i < 5; i++)
        {

            // create 1D array
            ptrpointer3D[k][i] = new int[4]; // this is good
        }
    }

    // for input the Data in 3D
    cout << "Enter the data in 3D :\n";

    for (int k = 0; k < 3; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                // create 1D array
                // cin >> ptrpointer3D[k][i][j];//it time taking, let's fill it by ourself
ptrpointer3D[k][i][j]=i+j+k;
                
            }
        }
    }

    cout << "Printing the data in 3D :\n";
    for (int k = 0; k < 3; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                // create 1D array
                cout << ptrpointer3D[k][i][j] << "\t"; // it opens from left to right// *(*(*(ptr+k)+i)+j)
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
    cout << endl;

    // deleting the heap data
    for (int k = 0; k < 3; k++)
    {
        for (int i = 0; i < 5; i++)
        {

            // create 1D array
            delete[] ptrpointer3D[k][i]; // delete 1 row only
        }

        delete[] ptrpointer3D[k]; //this we forgetted to create // ptrpointer3D[k] = new int *[5]; 
    }

    delete[] ptrpointer3D[3];

    return 0;
}