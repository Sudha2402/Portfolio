#include <iostream>
using namespace std;


// binary search is example seen in dictionary
//  for now we will use insertion sort as this is efficient among these
// bubble sort.

int binSearchDec(int arr[], int size, int val, int min, int max)
{
    int mid;

    while (max >= min)
    {
        mid = min + (max - min) / 2;
        // cout << min << " " << mid << " " << max << endl;

        //  printArray(arr, size);//not defined in this function scpe

        if (arr[mid] == val)
        {
            return mid;
        }
        else if (arr[mid] > val)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }

    // printArray(arr, size);

    return -1;
}

int binarySearch(int arr[], int size, int val, int min, int max)
{

    // while (min <= max && max < size)
    // {//You're mixing recursion and iteration (using while and also calling binarySearch recursively). Stick to one approach. Here’s how to fix it for recursive:
    //     // int mid = (max - min) / 2;//
    //     int mid = min + (max - min) / 2;
    //     cout << min << " " << mid << " " << max << " " << endl;

    //     if (arr[mid] == val)
    //     {
    //         return mid;
    //     }
    //     else if (val < arr[mid])
    //     {

    //         max = mid - 1;
    //         min = min;
    //         binarySearch(arr, size, val, min, max);
    //     }
    //     else if (val > arr[mid])
    //     {
    //         min = arr[mid + 1];
    //         max = max;

    //         binarySearch(arr, size, val, min, max);
    //  Recursive Calls Without Return
    // hence use
    //  return binarySearch(arr, size, val, mid + 1, max);

    //     }
    //     else
    //     {
    //         return -1;
    //     }
    // }

    // //  while (min <= max && max < size)
    //  while (min <= max)
    // {//Unnecessary max < size Check

    //     int mid = min + (max - min) / 2;
    //     cout << min << " " << mid << " " << max << " " << endl;

    //     if (arr[mid] == val)
    //     {
    //         return mid;
    //     }
    //     else if (val < arr[mid])
    //     {

    //         max = mid - 1;
    //         min = min;

    //     }
    //     else if (val > arr[mid])
    //     {
    //         min = mid + 1;
    //         max = max;

    //     }
    //     // else
    //     // {
    //         // return -1;/The else { return -1; } is redundant (the loop condition already handles this). Move return -1 outside the loop.
    //     // }
    // }

    // using recursion//must have recall with return

    if (min >= max)
    {              // it is equal beacuse we are taking max as last index not the count.
        return -1; // Base case: value not found.
    }
    int mid = min + (max - min) / 2;
    // cout << min << " " << mid << " " << max << endl;

    if (arr[mid] == val)
    {
        return mid;
    }
    else if (val < arr[mid])
    {
        return binarySearch(arr, size, val, min, mid - 1);
    }
    else
    {
        return binarySearch(arr, size, val, mid + 1, max);//it wil recursively move back and end.
    }
}


// good way
int binarySearc2(int arr[], int size, int val, int min, int max)
{
    while (min <= max)
    {
        int mid = min + (max - min) / 2; // efficinet as it removes overflow due to addition beacuse division will give small value hence adding min
        // we can have done this using average also
        // int mid=(max + min) / 2;//overflow for storing number max+min, hence above in better to pass all test cases.

        cout << min << " " << mid << " " << max << endl;

        if (arr[mid] == val)
        {
            return mid;
        }
        else if (val < arr[mid])
        {
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }

    return -1; // Value not found.

}

int printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[] = {
        2,
        6,
        2,
        5,
        2,
        7,
        0,
        35,
    };

    int key, j, n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);

    // insertion sort
    for (int i = 1; i < n; i++)
    {

        key = arr[i];
        j = i - 1;

        while (arr[j] > key && j >= 0)
        {

            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        // printArray(arr, n);
    }

    printArray(arr, n);

    // Now array is sorted we can use binary search

    int val;
    cout << "Enter the element to search : ";
    cin >> val;

    cout << binarySearch(arr, n, val, 0, n - 1) << endl; // 0 and n-1 are the initial search bounds (start and end indices).

    // time complexity keep in the series as number of elements  to be searched in keep decreasing by 2.
    // here we calculate time complexity on the bases of array size and in each size we need to find mid hence 1 time it runs in one array size. At the end array size will become 1 after keep itself deviding halg. That last time size will be 1 hence 1= N/2^k . here k is the number of times it is needed to keep dividing N to reach to the answer of 1. this is array size comparision. hence K+1 steps needed.

    // we simple count how many mid is calculated and amound how many inputs . hence k+1 times mid is need to be find .

    // en sakka sum k+1 hoga kyuki har step me one time mid cal ho raha h. is k ki value nilane ke liya humne size ke according relation banaya. kyuki finlly size 1 hogi array ki.

    // binary search in an array of decreasing order.

    int arrDec[] = {9, 7, 5, 3, 2, 1};
    printArray(arrDec, n);
    cout << binSearchDec(arrDec, 6, val, 0, 5);

  

    return 0;
}