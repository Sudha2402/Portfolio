#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Note: whenever we have to calculate the sum in iterative manner from left to right then better to consider the prefix sum array table for less time complexity. On subtracting prefix sum from total sum then we will get the sum of right half.

vector<int> Prefix(vector<int> arr)
{
    int size = arr.size();
    vector<int> PrefixSum(size);
    PrefixSum[0] = arr[0];
    for (int i = 1; i < size; i++)
    {
        PrefixSum[i] = PrefixSum[i - 1] + arr[i];
    }

    return PrefixSum;
}

int SubArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size - i; j++)
        {
            for (int k = j; k <= j + i; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl; // one size array in this for loop
        }

        cout << endl; // one size array moves to 2 size array now
    }

    return 0;
}

// Divide array in Subarray with equal sum
bool EqualSumSubArray(int arr[], int size)
{
    int totalsum = 0, leftSum = 0, rightSum = 0;
    for (int i = 0; i < size; i++)
    {
        totalsum += arr[i];
    }

    for (int i = 0; i < size - 1; i++)
    {                      // we choosed this range because , we will get no partition right once we moved to the last index, hence we will be one index prior.
        leftSum += arr[i]; // initializing
        rightSum = totalsum - leftSum;
        if (leftSum == rightSum)
        {
            cout << "Partition Index:" << i << endl;
            return 1;
        }
    }

    return 0; // if not possible
}

// less efficient as timecomplexity=O(n^3)//hence we will try to use prefix sum and forms all the cases, by increasing one index.
int largestSumSubArr(int arr[], int size)
{
    int maxSum = INT16_MIN, sum;
    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size - i; j++)
        {
            sum = 0;
            for (int k = j; k <= j + i; k++)
            {
                // cout << arr[k] << " ";
                sum += arr[k];
            }
            // cout << endl; // one size array in this for loop

            if (sum >= maxSum)
            {
                maxSum = sum;
            }
        }

        // cout << endl; // one size array moves to 2 size array now
    }

    return maxSum;
}

// WhenEver Subarray sum related question is asked then try to use prefix sum or suffix sum
int largestSumSubArrOpti(int arr[], int size)
{
    int maxSum = INT16_MIN, prefix;
    for (int i = 0; i < size; i++)
    {
        prefix = 0;
        for (int j = i; j < size - i; j++)
        {
            prefix += arr[j];
            maxSum = max(prefix, maxSum);
        }
    }

    return maxSum;
}

// O(n)//more optimized//kadane's law//
//  Kade's law says that if prefix sum is coming -ve then meke it 0 then calculate further to calculate the subarray sum.

// Max will follow max among last max and new prefix.

// sub array next connects only when they combined give max, hence if it decrease then it thinks of better forming new sub array.

// here as if it give +ve prefix then we can combined to get benefit of forward terms.

// further has chance to in=gnore the prev but prev has no chance to ingore the next.

int largestSumSubArrMoreOpti(int arr[], int size)
{
    int maxSum = INT16_MIN, prefix = 0;
    for (int i = 0; i < size; i++)
    {

        // if (prefix >= 0)
        // {
        //     prefix += arr[i];
        // }
        // else
        // {
        //     prefix = 0;//it check the prev and now updating in next hence creates logical error, hence first update prefix then change to 0 as done below
        // }
        // maxSum = max(prefix, maxSum);

        // Correct

        prefix += arr[i]; // pahle wale ke pass selection ka chance nahi h usse update hona padega
        maxSum = max(prefix, maxSum);
        if (prefix < 0)
        {
            prefix = 0;
        }
    }

    return maxSum;
}

int maxDiffBiggerRight(int arr[], int size)
{
    int maxDiff = INT16_MIN;    // stores the answer
    int maxNum = arr[size - 1]; // stores max num in the right

    // int currentDiff = INT16_MIN;

    //  int arrSubSum[] = {3, 4, -2, 5, 8, 20, -10, 8};
    for (int i = size - 2; i >= 0; i--)
    {

        //  cout << maxDiff << " "<<arr[i]<<" " << maxNum << endl;//works to check.
        // currentDiff =maxNum - arr[i];

        // maxDiff = max(maxDiff, currentDiff);
        maxDiff = max(maxDiff, maxNum - arr[i]);

        maxNum = max(maxNum, arr[i]);
    }

    return maxDiff;
}

int main()
{

    vector<int> arr = {6, 4, 5, -3, 2, 8};
    vector<int> ans = Prefix(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    cout << "Sub Array :" << endl;
    int arrSub[] = {4, -3, 7, 2};
    int size = sizeof(arrSub) / sizeof(arrSub[0]);
    SubArray(arrSub, size);

      cout << "Sub Array Equal Sum :";
    int arrSubSum[] = {3, 4, -2, 5, 8, 20, -10, 8};
    size = sizeof(arrSubSum) / sizeof(arrSubSum[0]);
    cout << EqualSumSubArray(arrSubSum, size) << endl;

    cout << "Sub Array largest Sum :" << endl;
    cout << largestSumSubArr(arrSub, size) << endl; // O(n3)
    cout << "Sub Array largest Sum Optimized:" << endl;
    cout << largestSumSubArrOpti(arrSub, size) << endl; // O(n2)
    cout << "Sub Array largest Sum More Optimized:" << endl;
    cout << largestSumSubArrMoreOpti(arrSub, size) << endl; // O(n)

  

    cout << "Max Difference when bigger element at right side and smaller in left :";
    int arrMaxDiff[] = {3, 4, -2, 5, 8, 20, -10, 8};
    size = sizeof(arrMaxDiff) / sizeof(arrMaxDiff[0]);
    cout << maxDiffBiggerRight(arrMaxDiff, size) << endl;

    return 0;
}
