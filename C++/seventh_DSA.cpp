#include <iostream>
using namespace std;

int rotateArray(int arr[], int size)
{//note that this arr is not and array,it is pointer of the array at the passed address by arrpassed

    cout<<sizeof(arr)<<endl;//count the number od digits in address.. 8 bits or 4 bits hence returns 4 byte in 32 bits processor.otherwise 8 byte. in 64 bits processor.//it will not return the number of elements like size.

    // we can store the last element somewhere and start right shifting all one by one.
    int last = arr[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = last;
}

int fabonacciPosEle(int fabonacciPos)
{
    // int arr[fabonacciPos-1]={0}; // we will check at this index -1
    int arr[1000] = {0}; // we will check at this index -1
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i < fabonacciPos; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[fabonacciPos - 1];
}

int secondMax(int arr[], int size)
{
    int maxNum = INT32_MIN;
    int secondMax = INT32_MIN;
    // if we are given that range is from +ve then we can use return -1

    maxNum = -1;
    secondMax = -1;

    for (int i = 0; i < size; i++)
    {

        if (arr[i] > maxNum)
        {
            secondMax = maxNum;
            maxNum = arr[i];
        }
    }

    // we can have used inbulit max also//
    maxNum = INT32_MIN;
    secondMax = INT32_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxNum)
        {
            maxNum = arr[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != maxNum)
        {
            secondMax = max(arr[i], secondMax);
        }
    }

    return secondMax;
}

int reverse(int arr[], int size)
{ // here arr refernce/adress will be passed , hence no pointer needed
    for (int i = 0; i < size / 2; i++)
    {//swapping
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }

    // PrintArray(arr, size);//seventh_DSA.cpp:13:25: error: 'PrintArray' was not declared in this scope
}

int reverse2(int arr[], int size)
{ // here arr refernce will be passed , hence no pointer needed
    int i = 0;
    int j = size - 1;
    int temp;
    while (j > i)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        // note:  we have swap inbuilt function
        // swap(arr[i], arr[j]);

        i++;
        j--;
    }

    // PrintArray(arr, size);//seventh_DSA.cpp:13:25: error: 'PrintArray' was not declared in this scope
}

int PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Search(int arr[], int val, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    int arr[] = {3, 6, 3, 12, 5, 2, 5};
    // int min = INT16_MAX;// 32767
    // cout << min << endl;

    int min = INT32_MAX, minIndex, max = INT32_MIN, maxIndex; // 2147483647 //as per 32 bits required
    // cout << min << endl;
    // cout << sizeof(arr) << endl; // 28

    cout << sizeof(arr) / sizeof(int) << endl;    // 7
    cout << sizeof(arr) / sizeof(arr[0]) << endl; // 7//if datatype is not known

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            minIndex = i;
        }
        if (arr[i] > max)
        {
            max = arr[i];
            maxIndex = i;
        }
    }

    cout << min << endl;
    cout << minIndex << endl;
    cout << arr << endl; // 0x61fee8//base address
    // int minIndexAddress =(arr+minIndex*sizeof(int));//arr is of int* type hence can't be stored in int minIndexAddress
    int *minIndexAddress = (arr + minIndex * sizeof(int)); // arr is of int* type hence can't be stored in int minIndexAddress
    cout << minIndexAddress << endl;                       // 0x61ff34

    cout << max << endl;
    cout << maxIndex << endl;
    cout << arr << endl; // 0x61fee8//base address
    // int maxIndexAddress =(arr+maxIndex*sizeof(int));//arr is of int* type hence can't be stored in int maxIndexAddress
    int *maxIndexAddress = (arr + maxIndex * sizeof(int)); // arr is of int* type hence can't be stored in int maxIndexAddress
    cout << maxIndexAddress << endl;                       // 0x61ff34

    /*    int size;
    cout << "Enter the size of array" << endl;
    cin >> size;

    //  int arr2[size] = {0};//bad practice as it will create error in dynamic location hence variable size is not allocate in array, we decide the max limit as per data

    int arr2[100] = {0}; // initilize all with 0

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element at index " << i << " : ";
        cin >> arr2[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr2[i] << " ";
    }

    */

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int index = -1; // initialize
    cout << Search(arr, 32, 7) << endl;
    cout << Search(arr, 5, 7) << endl;
    cout << Search(arr, 3, 7) << endl;
    cout << Search(arr, 12, 7) << endl;

    // reverse array

    int arr3[10];
    for (int i = 6; i >= 0; i--)
    {
        cout << arr[i] << " "; //-1 if indexing is out of bound
        arr3[6 - i] = arr[i];
    }

    cout << endl;
    // arr=arr3;//address can't be assign to another address

    // free(arr); // attempt to free a non-heap object 'arr' [-Wfree-nonheap-object]

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    *arr = *arr3; // now array will point to the address of arr3//we need to remove this arr first.
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // 5 2 5 12 3 6 3
    // 5 6 3 12 5 2 5

    // without taking extra parameter
    // we can swap the indexes

    // reverse the array in its own place without extra array

    PrintArray(arr, 7); // 5 6 3 12 5 2 5
    reverse(arr, 7);
    PrintArray(arr, 7); // 5 2 5 12 3 6 5
    reverse2(arr, 7);
    PrintArray(arr, 7);

    cout << endl;
    // secondMax(arr, 7);
    cout << secondMax(arr, 7) << endl;

    // missing number
    // numbers upto 6 and size of array is one less than 6 means 5. Hence one number is missed and that can be any random number among 1 to 6
    // we can create a new aray and the value will become the index and will set it 1 and 0 if zero means missing
    int arrMain[] = {1, 4, 6, 3, 2};
    cout << "Main Array :";
    PrintArray(arrMain, 5);
    int checkMis[7] = {0};
    PrintArray(checkMis, 7);
    for (int i = 0; i < 5; i++) // taking from arrMain//indexing from 0 to 4//any more index will create garbage value error
    {
        checkMis[arrMain[i]] += 1; // one index back then it's value for not wasting number at zero index.//if range includes 0 to 6 then this not needed.
        // PrintArray(checkMis, 7);
    }
    PrintArray(checkMis, 7);

    int missing;
    for (int i = 1; i <= 6; i++)
    {
        cout << "printTry :" << i << endl;
        if (checkMis[i] == 0)
        {
            missing = i;
            break;
        }
    }

    cout << missing << endl;

    // here a more beautiful approch for this is possible using sum.and sum can be found only using total number 1 to 6 using n*n+1/2 then individual sum using the given array.//it is capable of solving in less time and having less time complexity //every element is unique and distinct.

    int sumArray = 0;
    for (int i = 0; i < 5; i++)
    {
        sumArray += arrMain[i];
    }

    missing = (6 * 7 / 2) - sumArray;
    cout << missing << endl;

    // find nth position element in fabonacci series using an array.
    int fabonacciPos;
    cout << "Enter the fabonacci Position :";
    cin >> fabonacciPos;
    cout << fabonacciPosEle(fabonacciPos) << endl;

    int arrRotMain[] = {1, 4, 6, 3, 2};
    PrintArray(arrRotMain, 5);
    rotateArray(arrRotMain, 5);
    PrintArray(arrRotMain, 5);

    // 2 1 4 6 3


    return 0;
}