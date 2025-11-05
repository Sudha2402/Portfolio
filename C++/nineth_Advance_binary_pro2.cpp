#include <iostream>
using namespace std;

// Peak index in mountain

int peakIndex(int arr[], int size)
{
    // we can have done it with linear search also but it would have O(n) time complexity.//binary search can be in any series which on division into two parts form either increasing or decresing

    int min = 0, max = size - 1, peakElement = arr[size - 1], mid, peakIndex = size - 1;

    if (size == 1)
        return 0; // for handling

    while (min <= max)
    {

        // cout << peakIndex << endl;
        // cout << peakElement << endl;

        mid = min + (max - min) / 2;
        // mid = max + (min - max / 2);//removes runtime arror when we try to access a number beyound the range.////it would have worked as //round up to integer as /2 will cause limit not execc ed.//0-1/2=-0.5//max+0,5 will not create error if mid =0.5 hence it will consider 0 index not =1 index//1-0.5 ==0 but if we have used  mid = min + (max - min) / 2; then 0(+0.5) hence 0 and any -1 will make it reack to -1//that is error or runtime out error// 1-(0-1)/2==1-0.5=//still not usnferstood.

        // lower works but more condition hence we combined condition in below conditions //Alternative approach is more robust against boundary issues// may continue searching even after finding a peak //tracks the maximum element seen so far
        // if (arr[mid] >= peakElement)
        // {
        //     // min = mid;
        //     peakElement = arr[mid];
        //     peakIndex = mid;
        // }

        // if (arr[mid + 1] >= peakElement)
        // {
        //     peakElement = arr[mid + 1];
        //     peakIndex = mid + 1;
        //     min = mid + 1;
        // }
        // else if (arr[mid - 1] > peakElement)
        // {
        //     peakElement = arr[mid - 1];
        //     peakIndex = mid - 1;
        //     max = mid - 1;
        // }
        // else
        // {
        //     return peakIndex;
        //     // return peakElement;
        // }

        // we caqn have formed the condition easily after visualizing the diagram
        // , peak,left,right condition

        // Handle boundary cases//not need to change mid calculation find
        if (mid == 0)
        {
            if (arr[mid] > arr[mid + 1])
                return mid;
            else
                min = mid + 1;
        }
        else if (mid == size - 1)
        {
            if (arr[mid] > arr[mid - 1])
                return mid;
            else
                max = mid - 1;
        }

        if (arr[mid] > arr[mid + 1] && arr[mid] >= arr[mid - 1]) // this will raise error when we try to access mid+1 when mid is last index element
        {
            return mid; // peakindex
        }
        else if (arr[mid - 1] < arr[mid])
        {
            min = mid + 1; // agar alredy peak par hota toh uppar hi ruk jata
        }
        else
        {
            max = mid - 1;
        }
    }

    // return peakIndex;
    // return peakElement;
    return -1;
}


// to find the min element in the rortated array
// we can use binary here also just like above//in case of rotated error.

int RotateMin(int arr[], int size)
{

    int min = 0, max = size - 1, mid, Smaller = 0, SmallerElement = arr[0];
    cout << min << endl;

    // arr[0] is helpful in checking which direction it is rotated.//left rotaed or right rotated.

    while (min <= max)
    {
        mid = min + (max - min) / 2;
        if (arr[mid] >= arr[0]) // we are using the base case in rotated sorted array
        {                       // increasing accending still, as left element will be lesser then this, min is not found in left side
            min = mid + 1;      // we will start from right side//left side sorted array, from the left side
        }
        else               // if (arr[mid] <= arr[0])
        {                  // possiblility that it has started decrementing
            Smaller = mid; //
            SmallerElement = arr[mid];
            max = mid - 1;
        }
        // else
        // {
        //     // return Smaller;//no need
        // }
    }

    return Smaller;
}

// search in rotated array
int rotateSearch(int arr[], int size, int val)
{ // portion selection then switch to other portion from within the portion select as per inner condition.
    int min = 0, max = size - 1, mid, ans = -1;

    // cout << min << endl;

    while (min <= max)
    {
        mid = min + (max - min) / 2;
        // if (arr[mid] == val)
        // { // only in strict array.
        //     return mid;
        // }
        // // wrong logic
        // else if (arr[mid] > arr[0] && arr[mid] > val)
        // {
        //     // still increasing
        //     max = mid - 1;
        // }
        // else if (arr[mid] < arr[0] && arr[mid] > val)
        // {
        //     max = mid - 1;
        // }
        // else if (arr[mid] > arr[0] && arr[mid] < val)
        // {
        //     // still increasing
        //     min = mid + 1;
        // }
        // else if (arr[mid] < arr[0] && arr[mid] < val)
        // {
        //     min = mid + 1;
        // }

        // right logic //Clear Identification of Sorted Halves:
        if (arr[mid] == val)
        { // only in strict array.
            return mid;
        }
        else if (arr[mid] >= arr[0])
        { // arr[mid] >= arr[0] cleanly identifies if we're in the left sorted portion

            // to find left sorted
            //  if val lies in between then we can form our range else range differs

            if (val >= arr[min] && arr[mid] > val)
            {
                // val lies inside this
                max = mid - 1;
            }
            else
            {
                min = mid + 1;
            }
        }
        else
        { // arr[mid]<arr[0]//handles the right rotated sorted portion

            // right rotated  sorted//again small to big
            if (val <= arr[max] && arr[mid] < val)
            {
                // val lies inside this
                min = mid + 1;
            }
            else
            {
                max = mid - 1;
            }
        }
    }

    return ans;
}

int main()
{

    // 2,4,6,8,10,8,5
    // it is like first inctreasing then decreasing, We have to find the peak element.

    // we can use binary search.
    // we should look the next index wheater greater or smaller, if smaller then , we should find left index, if greater then , we can think that as new max, then set the range accordingly, keep getting min in between

    // int arr[] = {2, 4, 6, 8, 10, 8, 5};
    // int arr[] = {2, 4, 6, 8, 5};
    // int arr[] = {4, 6, 8, 10, 1, 2};
    int arr[] = {2, 4, 0, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << peakIndex(arr, size) << endl;



    //rotated Array

    cout << RotateMin(arr, size) << endl;//
    cout << RotateMin(arr, size) << endl;



    int val;
    cout << "Enter the value to search : ";
    cin >> val;
    cout << rotateSearch(arr, size, val);

    return 0;
}
