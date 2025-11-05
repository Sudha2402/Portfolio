#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// linear search
// binary search

// time complexity in recursion
// For time complexity, calculate the total node formed . for space complexity find the height of tree.
// when array is passed in parameter then it is taken as pointer and only 4 bytes is take by it in every call.
// when vector is passed then it's copy is made, hence it take n size in every call.
// when &vector passed then it is used as reference and take constant time

// // merge sort//O(nlogn) //divide and merge.
// max space when this large merge is called can be imagined.
// Space complexity: O(n)

// merge sort

int linearSearch(int arr[], int size, int element)
{
    if (size == 0)
    {
        return -1;
    }

    if (arr[size - 1] == element)
    {
        return size - 1;
    }
    else
    {
        return linearSearch(arr, size - 1, element);
    }
}

int binarySearch(int arr[], int low, int high, int element)
{

    int mid = low + (high - low) / 2;

    if (low > high)
    {
        return -1;
    }

    if (arr[mid] == element)
    {
        return mid;
    }
    else if (arr[mid] > element)
    {
        return binarySearch(arr, low, mid - 1, element);
    }
    else
    {
        return binarySearch(arr, mid + 1, high, element);
    }
}

// merge sort
// we divide the problem into subpart then merge it

void merge(int arrMerge[], int low, int mid, int high) // solves linearlt hence O(n)
{
    // int arr[100]={0};//overflow error

    // we will use dynamic allocation
    int *arr = new int[high - low + 1]; // dynamically allocate memory

    // we could have used dynamic memory location also using vector also
    // vector<int>arr(high-low+1);

    int i = low;
    int j = mid + 1;
    int k = 0;

    // cout << "low: " << low << " mid: " << mid << " high : " << high << endl;

    while (i <= mid && j <= high)
    {

        if (arrMerge[i] <= arrMerge[j])
        {
            arr[k] = arrMerge[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = arrMerge[j];
            j++;
            k++;
        }
    }

    // copy the remaining
    // while (i < mid + 1)
    while (i <= mid)
    {
        arr[k] = arrMerge[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        arr[k] = arrMerge[j];
        k++;
        j++;
    }

    // index for k
    int limit = k;
    // now start updating from low to high from arr[k];
    for (int k = 0; k < limit; k++)
    {
        // cout << arr[k] << " ";
        arrMerge[low + k] = arr[k];
    }
    // cout << endl;

    // for update we could have used while loop also with index=0 then low<=high
    // int index=0;
    // while(low<=high){
    //     arrMerge[low] = arr[index];
    //     low++; index++;
    // }

    for (int i = low; i <= high; i++)
    {
        cout << arrMerge[i] << " ";
    }
    cout << endl;

    return;
}

void mergeSort(int arrMerge[], int low, int high) // diving take O(log n)
{
    // we need to divide the array
    int mid = low + (high - low) / 2;

    //   if(low == high){ //this is doning same what low < high doiung to stop//this shoes that only single elements left after dividing
    //     return;
    //   }

    if (low < high)
    { // instead of this we could hace simply wrote return startement

        // cout << "low: " << low << " mid: " << mid << " high : " << high << endl;
        mergeSort(arrMerge, low, mid);

        mergeSort(arrMerge, mid + 1, high);
        // merge from right most division last one

        merge(arrMerge, low, mid, high); // from very first time , we left low at last before single array and high at last. //now we need to merge it
    }

    return;
}

int quickPivotFix(int arrQuick[], int low, int high)
{

    /*
    int pivot = arrQuick[low];
    int i = low + 1;
    int j = high;
    while (i <= j)
    {

        while (arrQuick[i] <= pivot)
        {
            i++;
        }
        while (arrQuick[j] > pivot)
        {
            j--;
        }

        if (arrQuick[i] > pivot && arrQuick[j] <= pivot && i < j)
        { // chhote wale ya barabar left me and bade wale right me.

            // swap
            swap(arrQuick[i], arrQuick[j]);
            i++;
            j--;
        }
    }

    swap(arrQuick[low], arrQuick[j]);

    // this j is final position hence we need to partition here
    return j;

    // method 1 all above uncomment togethor
*/

    //
    //
    //
    // method 2
    //

    // instead of writing above whole , we could have used a new way.

    // we keep swapping the smaller than this pivot at end, //at last i loop moves to end and it put the pivot at it's correct position

    int pivot = arrQuick[high];
    int pos = low;
    for (int i = low; i <= high; i++)
    { //O(n) time to put it at correct position.  n is the size of array it is dealing with currentl

        // swap with the right position all smaller and equal than pivot to the left
        if (arrQuick[i] <= pivot)
        {
            swap(arrQuick[i], arrQuick[pos]);
            pos++;
        }
    }

    return pos - 1; // pos is final position of pivot.
}

void quickSort(int arrQuick[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int partition = quickPivotFix(arrQuick, low, high); // partition is pivot index.
    quickSort(arrQuick, low, partition - 1);
    quickSort(arrQuick, partition + 1, high);

    // }

    return;
}

int main()
{

    // linear search using recursion
    int arr[] = {2, 4, 7, 11, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << linearSearch(arr, size, 12) << endl;

    cout << binarySearch(arr, 0, size, 12) << endl;
    cout << binarySearch(arr, 0, size, 13) << endl;

    // time complexity
    // For time complexity, calculate the total node formed . for space complexity find the height of tree.

    // that is only end part and merge left and this left takes n space for temp array.
    // hence as n>logn
    // Space complexity: O(n) or O(n+logn)

    // int arrMerge[] = {6, 4, 7, 2, 9, 8, 3, 5};
    int arrMerge[] = {6, 3, 5, 2, 2, 8, 1, 3, 2, 9};
    size = sizeof(arrMerge) / sizeof(arrMerge[0]);
    mergeSort(arrMerge, 0, size - 1); // high is last index

    for (int i = 0; i < size; i++)
    {
        cout << arrMerge[i] << " ";
    }
    cout << endl;

    // we can also try to merge in descending order.


    // Quick sort
    int arrQuick[] = {6, 3, 5, 2, 2, 8, 1, 3, 2, 9};
    size = sizeof(arrQuick) / sizeof(arrQuick[0]);
    quickSort(arrQuick, 0, size - 1); // high is last index

    for (int i = 0; i < size; i++)
    {
        cout << arrQuick[i] << " ";
    }
    cout << endl;


    // Average time complexity is O(nlogn).
// Average case Space complexity = height of tree,= logn

// In worst case , its time complexity is O(n^2) and space complexity is O(n) as height in worst case is N , hence  O(n)


    

    return 0;
}