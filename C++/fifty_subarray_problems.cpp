#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

// Zero Sum subarray(brute force method, then use prefix sum)
// Subarray Sum equals K
// Subarray Sums divisible by K
// Subarray product less than K
// Subarray product of sum and it's length less than K
// Minimum size Subarray Sum greater or equal to the target.
// Minimum window Substring
// Length of longest subarray with atmost K frequency
// Count Subarray where max element appear at least K times
// Subarray with K different Integer

// Zero Sum subarray
// brute force method O(n^3)
int sumZeroBrute(vector<int> &arr)
{
    int total = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {

            // we count sum from i to this j as one subarray

            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            if (sum == 0)
            {
                total++; // for returning

                // we can print here also
                for (int p = i; p <= j; p++)
                {
                    cout << arr[p] << " ";
                }
                cout << endl;
            }
        }
    }

    return total;
}

// brute force method O(n^2) for  Zero Sum subarray
int sumZeroBruteOpti(vector<int> &arr)
{
    int total = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {

            sum += arr[j];

            if (sum == 0)
            {
                total++; // for returning

                // we can print here also
                for (int p = i; p <= j; p++)
                {
                    cout << arr[p] << " ";
                }
                cout << endl;
            }
        }
    }

    return total;
}

//  Zero Sum subarray in O(n)
long long int sumZeroOpti(vector<int> &arr)
{
    long long int total = 0;
    long long int prefixSum = 0;
    unordered_map<long long int, long long int> prefixCount;
    prefixCount[0] = 1; // 0 prefixSum value already present once.

    for (int i = 0; i < arr.size(); i++)
    {
        prefixSum += arr[i];
        // if (prefixCount[prefixSum] > 0)
        if (prefixCount.count(prefixSum) > 0)
        {
            // we increment later but first check it sum 0 possible, aleady occured earlier

            // more than 0 count means count in total as it's current count

            total += prefixCount[prefixSum];

            // now increase the count
            prefixCount[prefixSum]++;
        }
        else
        {
            prefixCount[prefixSum] = 1;
        }
    }

    return total;
}

// Subarray Sum equals K
int sumKOpti(vector<int> &arr, int K)
{
    int total = 0;
    int prefixSum = 0;
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1; // 0 prefixSum value already present once.

    for (int i = 0; i < arr.size(); i++)
    {
        prefixSum += arr[i];
        // if (prefixCount[prefixSum - K]  > 0)
        if (prefixCount.count(prefixSum - K) > 0)
        {
            // we increment later but first check it sum 0 possible, aleady occured earlier

            // more than 0 count means count in total as it's current count

            total += prefixCount[prefixSum - K];

            // now increase the count
            prefixCount[prefixSum]++;
        }
        else
        {
            prefixCount[prefixSum]++; // don't use = 1 as we are not checking this number count in if.
        }
    }

    return total;
}

// Subarray Sums divisible by K
int sumDivKOpti(vector<int> &arr, int K)
{
    int total = 0;
    int prefixSum = 0;
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1; // 0 prefixSum value already present once.
    int rem;

    for (int i = 0; i < arr.size(); i++)
    {
        prefixSum += arr[i];
        rem = prefixSum % K;

        // make all -ve rem to positive
        // if(rem<0){
        //     // rem=(rem+K);//only for negative
        //     rem=(rem+K)%K;
        // }

        rem = (rem + K) % K; // this line enough for above //can be taken for all positive and -ve

        // if (prefixCount.count(rem) > 0)
        // {

        //     total += prefixCount[rem];

        //     // now increase the count
        //     prefixCount[rem]++;
        // }
        // else
        // {
        //     prefixCount[rem] = 1;
        // }

        // we can replace whole if-else condition with these two lines
        total += prefixCount[rem]; // 0 count h toh 0 hi add ho lo
        prefixCount[rem]++;
    }

    return total;
}

// Subarray product less than K
int productLessKOpti(vector<int> &arr, int K)
{
    int total = 0;
    int product = 1;
    int start = 0, end = 0;

    while (end < arr.size())
    {
        product *= arr[end];

        while (product >= K && start <= end)
        {
            product = product / arr[start];
            start++;
        }

        if (product < K)
        {
            total += (end - start + 1); // here we are adding size as new subarray.
            end++;
        }
    }

    return total;
}

// Subarray product of sum and it's length less than K
int ScoreLessK(vector<int> &arr, int K)
{
    int total = 0;
    int score = 0;
    int start = 0, end = 0;

    while (end < arr.size())
    {
        score += arr[end];
        int length = end - start + 1;
        score *= length;

        while (score >= K && start <= end)
        {
            int old_length = end - start + 1;
            score /= old_length; // Get sum
            score -= arr[start]; // Update sum
            start++;
            int new_length = end - start + 1;
            score *= new_length; // Get new score
        }

        if (score < K)
        {
            total += (end - start + 1);
            int current_length = end - start + 1;
            score /= current_length; // Get sum for next iteration
            end++;
        }
    }
    return total;
}

// Minimum size Subarray Sum
int minSizeSubSum(vector<int> &arr, int K)
{
    int size = INT32_MAX;
    int prefixSum = 0;
    int start = 0, end = 0;

    for (int end = 0; end < arr.size(); end++)
    {
        prefixSum += arr[end];

        while (prefixSum >= K)
        {
            size = min(size, end - start + 1);
            // prefixSum -= arr[start];
            // start++;

            // above combined can be written as above.
            prefixSum -= arr[start++];

            //  here start ++ error, check the below one. Here as start will take initial value first hence sum decrement the old start value. Then it will increment start for new value.
        }
    }

    return size;
}

// Minimum window Substring
string minWinSub(string str, string subs)
{
    int characters = subs.size();
    // it's better to store mapping character count
    map<char, int> characterCount; // don't write char, it would not work.

    int count = 0;
    int size = INT32_MAX;
    int start = 0;
    int index = -1; // this will track the final substring start point.
    string ans;

    while (start < subs.size())
    {
        characterCount[subs[start]]++;
        start++;
    }

    start = 0;

    for (int end = 0; end < str.size(); end++)
    {
        characterCount[str[end]]--; // agar 0 han toh vo -ve ho jayenge.
        // if after decrement this end value still greater than 0 or equal to 0, means an elelemnt of sub string is deducted, means we need to include this as it was earlier in the substring count, hence the totla character is decreased after this deduction.

        if (characterCount[str[end]] >= 0)
        {
            characters--; // one character successfully found that need to be include in substring
        }

        while (characters == 0 && start <= end)
        {
            // the current substring has all the characters
            // now start will change to get more smaller

            // size = min(size, end - start + 1);

            if (size > end - start + 1)
            {
                size = min(size, end - start + 1);
                index = start; // we have to keep track for the final print // hence we need to keep in if condition.
            }

            // now we have to exclude the characters hence we will increment
            characterCount[str[start]]++;

            if (characterCount[str[start]] > 0)
            { // if it would have been important then atleast it would have endup to 0 count , hence any increment will make that important greater than 0 but if it is not important then it would have become -ve and any increment will at max make it 0 but not positive.

                // this is important substring character
                characters++; // this character shows that we need to find some more characters which are missing in the substring, hence now end will increment in search
            }

            start++; // it is must to increment as characters of this start is increment, hence start has to shift.
        }
    }

    for (int i = index; i < (index + size); i++)
    {
        ans += str[i];
    }

    return ans;
}

// Length of longest subarray with atmost K frequency
int lengthLongKFreq(vector<int> &arr, int K)
{

    int size = INT_MIN;
    int start = 0;
    map<int, int> numCount;

    for (int end = 0; end < arr.size(); end++)
    {
        numCount[arr[end]]++;

        while (numCount[arr[end]] > K)
        {

            // this current number has appeared more than frequency required hence we need to shift start and decrease the count of start

            numCount[arr[start]]--;
            start++;
        }

        size = max(end - start + 1, size);
    }

    return size;
}

// Count Subarray where max element appear at least K times (frequency of max element as whole is checked not the subarray max)
long long CountSubMaxK(vector<int> &arr, int K)
{

    //  there is no functional difference between long long and long long int

    int start = 0, end = 0;
    int total = 0;
    int maxElement = 0; // all are positive number
    int count = 0;

    for (int end = 0; end < arr.size(); end++)
    {
        maxElement = max(maxElement, arr[end]);
    }

    for (int end = 0; end < arr.size(); end++)
    {

        // // Use reverse iterators to get the maximum key
        // auto maxElement = countNum.rbegin();

        // // Output the maximum key
        // cout << "Maximum key in the map: " << maxElement->first<< endl;

        // this lower if is confusing and repeated if check even know that it will not work, hence we will use directly while as it will check and answer both.

        // if (arr[end] == maxElement)
        // {
        //     count++;

        //     if (count >= K) // in actual hum == tak hi kaam karte h.
        //     {
        //         // total += arr.size() - end + 1;

        //         total += arr.size() - end; // indexing from 0 hence end less than actual count hence count left of size will inclue the end hence no need to add   + 1 here.

        //         // now shift start to  check further

        //         while (count >= K)
        //         {
        //             if (arr[start] == maxElement)
        //             {
        //                 count--;
        //                 start++;
        //             }
        //             else
        //             {
        //                 start++;
        //                 total += arr.size() - end; // new start se pura last tak.
        //             }
        //         }
        //     }
        // }

        //
        if (arr[end] == maxElement)
        {
            count++;
        }

        while (count == K)
        {
            total += arr.size() - end;

            if (arr[start] == maxElement)
            {
                count--;
            }

            start++;
        }
    }

    return total;
}

// Subarray with K different Integer
int KIntegers(vector<int> &arr, int K)
{
    int countK = 0;
    int countK2 = 0;
    int total = 0;
    int start = 0;
    map<int, int> numCount;

    int countDistinct = 0;

    // let's perform for atleast K
    for (int end = 0; end < arr.size(); end++)
    {
        numCount[arr[end]]++;

        if (numCount[arr[end]] == 1)
        {
            countDistinct++; // one new dstinct element has come
        }

        // here when exact count comes then we can't solve it directly as at a time we can move either start or end but here combined not possible in one direction right or left
        // hence we use atleast difference or atmost difference

        // exact K = abs( atleast (K+1) - atleast (K+1) )

        // cout << "numCount.size() K : " << numCount.size() << endl;
        cout << "countDistinct K : " << countDistinct << endl;

        // while (numCount.size() == K)
        while (countDistinct == K)
        {
            // note once element inserted and other than 0 then even if value is 0 it will show it as count size. hence size count not decreases even with update 0, hence we need to manually track the count or size of map or distinct element.

            countK += arr.size() - end;

            // changing size
            numCount[arr[start]]--;
            if (numCount[arr[start]] == 0)
            {
                countDistinct--; // one new dstinct element has come
            }
            start++;
        }
    }

    // let's perform for atleast K+1
    start = 0;
    numCount.clear();
    countDistinct = 0;

    for (int end = 0; end < arr.size(); end++)
    {
        numCount[arr[end]]++;

        if (numCount[arr[end]] == 1)
        {
            countDistinct++; // one new dstinct element has come
        }

        cout << "countDistinct K+1 : " << countDistinct << endl;
        while (countDistinct == (K + 1))
        {
            countK2 += arr.size() - end;

            numCount[arr[start]]--;

            if (numCount[arr[start]] == 0)
            {
                countDistinct--; // one new dstinct element has come
            }
            start++;
        }
    }

    total = abs(countK2 - countK);

    // return countK; 
    // return countK2;
    return total;
}

int main()
{
    // Zero Sum subarray
    vector<int> arr = {6, -1, -3, 4, -2, 2, 4, 6, -12, -2};
    cout << "Zero Sum values :" << sumZeroBrute(arr) << endl;
    cout << "Zero Sum values :" << sumZeroBruteOpti(arr) << endl;
    cout << "Zero Sum values :" << sumZeroOpti(arr) << endl;

    // Subarray Sum equals K
    vector<int> arr2 = {2, 1, 7, -4, 2, 1, 3, 4, -15, 2, -3, 6};
    int K = 6;
    cout << "K Sum values :" << sumKOpti(arr2, K) << endl;

    // Subarray Sums divisible by K
    vector<int> arr3 = {3, 5, 6, 3, 9, 4, 6, 9};
    K = 7;
    cout << "K Sum Divisible by K :" << sumDivKOpti(arr3, K) << endl;

    // Subarray product less than K
    vector<int> arr4 = {2, 5, 10, 8, 100, 1000, 5, 15};
    K = 999;
    cout << "Subarray Product less than K :" << productLessKOpti(arr4, K) << endl;

    // Subarray product of Sum  and size of subarray less than K is the score.
    vector<int> arr5 = {2, 1, 4, 3, 5};
    K = 10;
    cout << "Count Subarrays with score (sum * size) less than K :" << ScoreLessK(arr5, K) << endl;

    // Minimum size Subarray Sum
    vector<int> arr6 = {2, 3, 1, 2, 4, 3};
    K = 7;
    cout << "Min size subarray Sum :" << minSizeSubSum(arr6, K) << endl;

    // Minimum window Substring holding all characters
    string str = "ADOBECODEBANC";
    string subs = "ABC";
    cout << "Min window Substring :" << minWinSub(str, subs) << endl;

    // Length of longest subarray with atmost K frequency
    vector<int> arr7 = {1, 2, 3, 1, 2, 3, 1, 2};
    K = 2;
    cout << "Length of longest subarray with atmost K frequency :" << lengthLongKFreq(arr7, K) << endl;

    // Count Subarray where max element appear at least K times
    vector<int> arr8 = {1, 3, 2, 3, 3};
    K = 2;
    cout << "Count Subarray where max element appears at least K times :" << CountSubMaxK(arr8, K) << endl;

    // Subarray with K different Integer
    vector<int> arr9 = {1, 2, 1, 2, 3};
    K = 2;
    cout << "Subarray with exactly K different Integer :" << KIntegers(arr9, K) << endl;

    return 0;
}