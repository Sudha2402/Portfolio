// bubble sort.

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
    // };


    // for making it adaptive to already sorted
    int arr[] = {
       0, 2 ,2, 2 ,5, 6 ,7 ,35
    };

    int minIndex, n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);

    int swapCase=0;//for making it efficient by counting swap, if no swap in first loop check then it is already in accending order.
    for (int i = n-1; i >0; i--)
    { // we don't compare any more if we are at last index hence range is n-1.

    
     
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j] ,arr[j+1]);
                swapCase=1;
            }


            //  cout<<"at i="<<i <<"and j=" <<j <<endl;

             printArray(arr, n);
          
        }
        if( !swapCase){
            break;
        }

       
    }

    printArray(arr, n);



    // Best omega(n-1) comparisions;
    // worst case: O(n^2)
    // avg:n^2 = theta(n2);


    // bubble sort in decreasing order by sendin the min to the last.
    // we can start this bubble sort from back, we try to swap on the bases of min and send the minimum in front.



    return 0;
}