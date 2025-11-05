// Selection sort

#include <iostream>
using namespace std;

// select the min//sorted | unsorted.

int printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int printArrayChar(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // int arr[] = {
    //     2,
    //     6,
    //     2,
    //     5,
    //     2,
    //     7,
    //     0,
    //     35,
    // }; // constant space as we are not changing the size of arr by taking input from user hence when something is not changing after compilation then it means it is constant space and not considered in auxilaiary. ..Auxiliary space is O(1) not O(size) //total space count even non changing then it may affect.//if we declare before as contant the processor will need not to create space while processing becuase spaces are created with this declaration at the time of compilation.

    // arr[100]; // O(1) space complexity; even when taking input from user
    // cout << "Enter the array elements:";
    // for (int i = 0; i < 3; i++)
    // {
    //     cin >> arr[i];
    // }

    char arr[] = {
        'a', 'd', 'w', 'e', 'a'};

    int minIndex, n = sizeof(arr) / sizeof(arr[0]);

    // printArray(arr, n);
    printArrayChar(arr, n);

    for (int i = 0; i < n - 1; i++)
    { // we don't compare any more if we are at last index hence range is n-1.
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }

        // spcae complexity O(1) for i, j and min index. We simple make space for 3 varables hence auxiliary space complexity is (3) constant 1.
        // Total space=n+1//n is size for array and then constant spa ce made new as same in auxiliary.

        // even when already sorted , we need to do all comparisons hence in best case also , we have time complexity = O(n ^2)

        // worst case when all in decending order.
    }

    // printArray(arr, n);
    printArrayChar(arr, n);

    // iot is capable of sorting even char, only secify it first.
    // a d w e a
    // a a d e w

    // we can have also done it by sending the max to the back only set maxIndex to the last index//check loop in opposite direction

    int arrMax[] = {
        2,
        6,
        2,
        5,
        2,
        7,
        0,
        35,
    };


    cout<<endl;

    int maxIndex;
    n = sizeof(arrMax) / sizeof(arrMax[0]);
    printArray(arrMax, n);

    // cout<<endl;

    for (int i = n - 1; i > 0; i--)
    { // we don't compare any more if we are at last index hence range is n-1.
        maxIndex = i;
        for (int j = 0; j < i; j++)
        {
            if (arrMax[j] > arrMax[maxIndex])
            {
                maxIndex = j;
            }
        }

        if (maxIndex != i)
        {
            swap(arrMax[i], arrMax[maxIndex]);
        }

        // spcae complexity O(1) for i, j and min index. We simple make space for 3 varables hence auxiliary space complexity is (3) constant 1.
        // Total space=n+1//n is size for array and then constant spa ce made new as same in auxiliary.

        // even when already sorted , we need to do all comparisons hence in best case also , we have time complexity = O(n ^2)

        // worst case when all in decending order.

        // printArray(arrMax, n);
    }

    printArray(arrMax, n);

    return 0;
}