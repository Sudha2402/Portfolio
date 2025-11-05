#include <iostream>
using namespace std;
// store 2 values at one place.
// using modulus and division effectively

// find missing and repeating element
// find the occurance of number
// Majority Element.

int main()
{

    // store 2 values at one place. //Take as number 2222222, sore num 2 and its occurance count 7. at one place //if we limit the range 1 to 99. then common number 99+1=100
    // value =(number*100+occurance) should be stored at one plcaer. Then at time of retrival. num=value/100.
    // occurance=value % 100

    // we have many methods to find missing and repeated number
    // but we are interested to solve in O(n + n) and space complexity O(1)//hence we will use the concept of storing two b=values at one place

    int arr[7] = {4, 3, 2, 1, 2, 7, 6};
    // 7 elements // including 7 // hence we will be needed 8 as common number and one more index would have been needed to store the ocuurance of 7 at 7th index.  but as 0 is not any element then 0 th index will store only value but no occurance as 0 is not in range. Hence to utilize this index also, we decrement all values in array by one . Then at time of extraction we will increment it also.

    // printing
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;



    

    // for optimizing index storage
    for (int i = 0; i < 7; i++)
    {
        arr[i] = arr[i] - 1; // decrementing all values
    }

    // printing
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;

    // storing the count and value at that index together with number
    for (int i = 0; i < 7; i++)
    {

        int val = arr[i]; // Index Out of Bounds: arr[6] exists, but arr[7] does not (array size is 7, indices 0 to 6).
        // hence we need to extract the exact value by removing those 7 to get index.

        int index = val % 7;
        arr[index] = arr[index] + 7;

        // we could have written
        // arr[arr[i]%7] +=7;

        // printing to check at each step
        for (int i = 0; i < 7; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // printing
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int missing = 0;
    int repeating = 0;
    for (int i = 0; i < 7; i++)
    {

        cout << i + 1 << " " << "Occurance : " << arr[i] / 7 << endl;
        // 1 Occurance : 1
        // 2 Occurance : 2
        // 3 Occurance : 1
        // 4 Occurance : 1
        // 5 Occurance : 0
        // 6 Occurance : 1
        // 7 Occurance : 1

        if (arr[i] / 7 > 1)
        {
            cout << "repeated number is :" << i + 1 << endl;
            // if we needed to seperate this missing and repeated print then we could have seperated this for loop for both and only one if condition , if it satisfies the break // that case time complexity is O(n+n) and here O(n) //almost same approch
        }
        if (arr[i] / 7 == 0)
        {
            cout << "Missing number is :" << i + 1 << endl;
        }

        cout << i << " " << "Number at this index  in original array : " << (arr[i] % 7) + 1 << endl;
    }

    /*
    4 3 2 1 2 7 6
    3 2 1 0 1 6 5

    3 2 1 7 1 6 5
    3 2 8 7 1 6 5
    3 9 8 7 1 6 5
    10 9 8 7 1 6 5
    10 16 8 7 1 6 5
    10 16 8 7 1 6 12
    10 16 8 7 1 13 12

    10 16 8 7 1 13 12
    0 Number at this index  in original array : 4
    repeated number is :2
    1 Number at this index  in original array : 3
    2 Number at this index  in original array : 2
    3 Number at this index  in original array : 1
    Missing number is :5
    4 Number at this index  in original array : 2
    5 Number at this index  in original array : 7
    6 Number at this index  in original array : 6
    PS C:\Sudhadocuments\C++>
    */

    cout << endl;
    cout << endl;

    // Find the occurance of Number.
    int arr2[8] = {3, 2, 5, 3, 1, 2, 3, 7};

    // for optimizing index storage
    for (int i = 0; i < 8; i++)
    {
        arr2[i] = arr2[i] - 1; // decrementing all values
    }

    // storing the count and value at that index together with number
    for (int i = 0; i < 8; i++)
    {
        arr2[arr2[i] % 8] += 8;
    }
    cout << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << i + 1 << " " << "Occurance : " << arr2[i] / 8 << endl;
    }

    cout << endl;
    cout << endl;

    // Majority Element.

    int arr3[11] = {3, 3, 2, 3, 1, 3, 2, 2, 1, 3, 3};

    // for optimizing index storage
    for (int i = 0; i < 11; i++)
    {
        arr3[i] = arr3[i] - 1; // decrementing all values
    }

    // storing the count and value at that index together with number
    for (int i = 0; i < 11; i++)
    {
        arr3[arr3[i] % 11] += 11;
    }
    cout << endl;

    for (int i = 0; i < 11; i++)
    {
        // cout << i + 1 << " " << "Occurance : " << arr3[i] / 11 << endl;
        if (arr3[i] / 11 > 11 / 2)
        {
            cout << "Majority Elements with count > N/2 :" << i + 1 << " ";
            // jiski occurance rest ke occurance ko add karne ke baad bhi jaida ho.//it's occurance must be greater than n/2

            // hence we can start cancelling two different at a time,
        }
    }

    cout << endl;
    cout << endl;

    // Moore voting algorithm

    // or method to find majority element only if one number is occureed greater than N/2 times
    // jiski occurance rest ke occurance ko add karne ke baad bhi jaida ho.//it's occurance must be greater than n/2

    // hence we can start cancelling two different at a time,
    int arr4[11] = {3, 3, 2, 3, 1, 3, 2, 2, 1, 3, 3};
    int majority;
    int majorityCount = 0;

    for (int i = 0; i < 11; i++)
    {
        if (majorityCount == 0)
        {
            majority = arr4[i];
            majorityCount++;
        }

        cout << majority << " " << majorityCount << endl;

        if (arr4[i] != majority)
        {
            majorityCount--;
        }
        else
        {
            majorityCount++;
        }
    }

    // at the end it may be possible that the last left which has occurred less time is in majority, in that case we must verify that it has occurred more than N/2 //we need to run for loop again for storing it total count

    int totalMajorityCount = 0;
    for (int i = 0; i < 11; i++)
    {
        if (arr4[i] == majority)
        {
            totalMajorityCount++;
        }
    }

    if (totalMajorityCount > 11 / 2)
    {
        cout << "Majority Elements with count > N/2 :" << majority << " with major count: " << totalMajorityCount << endl; // this way of calculating is callled moore voting algorithm//time complexity O(n)
    }

    return 0;
}
