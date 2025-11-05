#include <iostream>
using namespace std;



int maxVal(int arr[], int size)
{
    int maxVal = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
int minVal(int arr[], int size)
{
    int minVal = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }
    return minVal;
}

int printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}



int bananaValUnsorted(int arr[], int size, int k)
{
    // k is the hours we have to distribute this bananas such that if we finish we move to next index bananas

    // min is sum/k and max is sum or max of among this.but as we need min banana hence max+ max(arr)

    int mid, min, max, time = 0,ans;
    long long sum=0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];//integer overflow, hence chage to long long
    }

    min = sum / k; // in k hours if total bananas are given in this way then we can handle this.

    ans=min;

    max = sum;
    while (max >= min)
    {
        mid = min + (max - min) / 2; // suppose this much banana is eaten in 1 hour. then we need to calculate total hours needed for all bananas in array.

        if(!mid){
            mid=1;//to remove divide by zero error.
        }

          cout << ans << " " << min << " " << mid << " " << max << endl;

          time=0;
        for (int i = 0; i < size; i++)
        {
            time += arr[i] / mid; // as it gives int hence may cause problem.hence if remainder after moductus then increment time by 1 hour more.

            if (arr[i] % mid)
            {
                time++;
            }
        }

        if(time<=k){
            ans=mid;
            max=mid-1;//agar etne samaye me etna kha skate h toh if we need min banana to be eaten hence we move to left portion

        }
        else{
            min=mid+1;
        }
    }

    return ans;
}

// Aggressive cow problem.//proper analysis for sorted only
int cowminValFinal(int arr[], int size, int k)
{
    int minVal = arr[0], mid, max = arr[size - 1] - arr[0], ans = arr[0], dis = 0, count, minGap = 0;

    while (minVal <= max)
    {
        mid = minVal + (max - minVal) / 2;

        cout << ans << " " << minVal << " " << mid << " " << max << endl;

        dis = arr[0], count = 1; // positioned at arr[0]
        for (int i = 1; i < size; i++)
        { // as first cow is sitted at position 0 index

            cout << dis << " " << count << endl;
            if (dis + mid > arr[i])
            { // mid ko add karke relation banana jaida easy , gap nikalne se... mid add karne se hum har ek ka inde and distace from common bhi haeck ar painge.

                // arr[0]+mid<=arr[i]//for the next position of cow at arr[i]
                continue; // we can have skipped it by writting just else part in if condition.
            }
            else
            {
                count++;      // now 2nd ko baitha diya
                dis = arr[i]; // ye 2nd ki positional diatance h.i index par second wala baitha h aur voh main point se dis distance par h//ab es dis me aur mid value plus karenege toh eska matlab agar vo array ke kissi position par fit baithata h toh count 3 hojaiga aur third wale ko vha baitha denge.
            }
        }

        if (count >= k)
        { // agar jaida ko baitha sakte h toh kam arram se baith jainge.//toh hum usse ans consider kar sakte h... lakin hame max didtance chahiye to hum next dekhenge kya ess mid distance se bhi jaida possible h...
            ans = mid;
            minVal = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    return ans;
}

// Aggressive cow problem.
int cowminVal(int arr[], int size, int k)
{
    int minVal = arr[0], mid, max = arr[size - 1] - arr[0], ans = 1, dis = 0, count, minGap = 0; // for max , we calculate the max gap possible between atleast two.

    // we expect minVal 1 distance
    // possible distances 1 to 9 possible.
    // start as binary taking

    //  cout << ans << " " << minVal << " " << mid << " " << max << endl;

    while (minVal <= max)
    {
        mid = minVal + (max - minVal) / 2;

        cout << ans << " " << minVal << " " << mid << " " << max << endl;

        dis = 0, count = 1; // we need count =k-1 as we assign gap to one at one end and other at another end
        for (int i = 0; i < size - 1; i++)
        {

            cout << dis << " " << count << endl;
            if (dis < mid)
            { // here we are considering if dis exceed mid then move to next count
                dis = dis + arr[i + 1] - arr[i];
                if (dis >= mid)
                { // we clear with relation and don't hasitate to form nested condition or loop.
                    count++;
                    dis = 0;
                }
            }
        }

        if (count >= k)
        {
            // ans = mid;
            ans = mid;
            minVal = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    return ans;
}

// Aggressive cow problem.
int cowminVal2(int arr[], int size, int k)
{
    int minVal = arr[0], mid, max = arr[size - 1] - arr[0], ans = 1, dis = 0, count, minGap = 0; // for max , we calculate the max gap possible between atleast two.

    // we expect minVal 1 distance
    // possible distances 1 to 9 possible.
    // start as binary taking

    while (minVal <= max)
    {
        mid = minVal + (max - minVal) / 2;

        cout << ans << " " << minVal << " " << mid << " " << max << endl;

        dis = 0, count = 1; // we need count =k-1 as we assign gap to one at one end and other at another end
        for (int i = 0; i < size - 1; i++)
        {

            cout << dis << " " << count << endl;

            if (dis < mid)
            { // if mid exceed , then no problem , we will increase dis until it fulfils the gap condition.//here no need to get min gap earlier.
                if (arr[i + 1] - arr[i] >= 0)
                    dis = dis + arr[i + 1] - arr[i];
                else
                    dis = dis + arr[i] - arr[i + 1];

                if (dis >= mid)
                {
                    count++; // necessary for last index.
                    dis = 0;
                }
            }
        }

        if (count >= k)
        {
            ans = mid;
            minVal = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    return ans;
}


// Aggressive cow problem if unsorted
int cowminValUnsorted(int arr[], int size, int k)
{

    // it will still create problem , hence we need to sort it first in increasing order.
    // we can use insertion sort//we will use this
    int key, j;

    // printArray(arr,size);

    for (int i = 1; i < size; i++)
    {

        key = arr[i];
        j = i - 1;
        // for(j=i-1;j>=0;j--)//not good
        // for (j = i - 1; j >= 0 && arr[j] > key; j--) //both this and while is same.
        while (arr[j] > key && j >= 0)
        {

            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        // printArray(arr,size);
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int min = arr[0], mid, max = arr[size - 1] - arr[0], ans = 1, dis = 0, count; // for max , we calculate the max gap possible between atleast two.

    // we expect min 1 distance
    // possible distances 1 to 9 possible.
    // start as binary taking

    while (min <= max)
    {
        mid = min + (max - min) / 2;

        cout << ans << " " << min << " " << mid << " " << max << endl;

        dis = 0, count = 1; // we need count =k-1 as we assign gap to one at one end and other at another end
        for (int i = 0; i < size - 1; i++)
        {

            cout << dis << " " << mid << " " << count << endl;

            if (dis < mid)
            { // if mid exceed , then no problem , we will increase dis until it fulfils the gap condition.//here no need to get min gap earlier.

                dis = dis + arr[i + 1] - arr[i];

                if (dis >= mid)
                {
                    count++; // necessary for last index.
                    dis = 0;
                }
            }
            // else
            // {
            //     count++;
            //     dis = arr[i + 1] - arr[i];
            // }
        }

        if (count >= k)
        {
            ans = mid;
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    return ans;
}

int main()
{

    // int arr[] = {1, 2, 4, 8, 9}; // distances from a common start point.
    // int arr[] = {10, 1, 2, 7, 5}; // distances from a common start point.//make it sorted first

    // answer hamesa max value in array se bada ya barabar hoga.

    // int arr[] = {1, 2, 5, 7, 10};

    int arr[] = {3, 6, 11, 7};

    int size = sizeof(arr) / sizeof(arr[0]);
    int k;

    cout << "Enter the number of Cows / hours:";
    cin >> k;

    // cout << cowminValFinal(arr, size, k) << endl; // for sorted only
    // cout << cowminVal(arr, size, k) << endl; // for sorted only
    // cout << cowminVal2(arr, size, k) << endl;//for sorted
    // cout << cowminValUnsorted(arr, size, k) << endl; // for sorted

    cout << bananaValUnsorted(arr, size, k) << endl;
}