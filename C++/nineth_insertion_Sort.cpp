// bubble sort.

#include <iostream>
using namespace std;

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

    for (int i = 1; i < n; i++)
    {

        key = arr[i];
        j = i - 1;
        // for(j=i-1;j>=0;j--)//not good
        // for (j = i - 1; j >= 0 && arr[j] > key; j--) //both this and while is same.
        while (arr[j] > key && j >= 0)
        {
            // swap(arr[j], arr[j + 1]);
            // insted of swapping we can just right shift it// 3 assignments per swap (inefficient for shifting).
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        printArray(arr, n);
    }

    printArray(arr, n);

    // Space complexity is O(1) as constant spce for i, j and key and arr

    // Best omega(n-1) comparisions;//1 to n-1 swap or shifting possible 
    // worst case: O(n^2)
    // avg:n^2 = theta(n2);




    // Insertion sort can also be done in decreasing order.//we can have max first instead of min.
// swapping as per max


    return 0;
}