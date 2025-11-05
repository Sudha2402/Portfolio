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

// bookAllocation//such that number of pages difference should be minimum, hence we will take pages as condition and find out the result how much maximum page a student should get.//in between calculation , we need not to be strict that all can;t be filled, it is our choice, it is possible to adjust in any way.//answer bhi nikalna hi mana jaiyega agar try me hum ek me hi bahut sare dal rahe h aur kissi me kuchh nahi dal rahe h.. but real me check karenge to hum daal sakte h uss limit ke according

// allocate minimum number of pages as target to distribute to each and each may have different. In sence of pages per student this min page will become their max limit..for distributing, if any excedd t

int distributionMin(int arr[], int size, int k)
{
    // if(k<=size){
    //     //ok
    // }

    if (k >= size)
    {
        cout << "We have less number of books" << endl;
        return -1;
    }

    // int min = 90, sum, mid, ans;//min should be the max among array
    // int min = 30, sum=0, mid, ans;//min should be the max among array

    int min = maxVal(arr, size), sum = 0, mid, ans = 0; // min should be the max among array

    for (int i = 0; i <= size - 1; i++)
    {
        sum += arr[i]; // it will run atleast once.
    }
    int max = sum; // we have not included last as someone must have it atleast one book.
    ans = 0;

    // cout<<sum<<endl;//232

    while (min <= max)
    {
        mid = min + (max - min) / 2;
        sum = 0;

        // cout << mid << endl;

        // int count = 1, pointer = 0;
        // while (pointer <= size - 1 && count <= k)
        // {
        //     sum = 0;
        //     while ((sum + arr[pointer]) <= mid && pointer < size)
        //     {
        //         sum += arr[pointer];
        //         pointer++;
        //     }
        //     count++;//pointer either must be decremented or sum to be initialized with this pointer value

        // pointer=pointer-1;

        // }

        int count = 1, pointer = 0, page = 0;
        while (pointer <= (size - 1))
        { // we could have used for loop also upto last index.
            // a lop

            page += arr[pointer];
            if (page > mid)
            {
                count++; // it means the page just we added from this pointer should be in next count//jitna humne decide kiya tha usse jaide hi page de diya h, esliye us book ko wapas lo aur count dusre me dal do.
                // jiada pages toh main ek me bhi baat doo. par mujhe paes ko kam karna h takin m pages difference kam karu, hence mid moves back. if count>k, means k bacho me batna tha likin usse extra bacho me baat rahe h toh pages badhane padenge.

                page = arr[pointer];
            }

            pointer++;
        }

        // we have to consider page from 0 and Page>mid

        // if (pointer == size && count == k + 1) {//pointer will also reach to size position hence need not to incled
        if (count <= k)
        { // distribution is possible//maine bhale hi sabme na dale ho par maine maximum etna karne par sabko ek ek bhi de sakti hun//possible
          // we managed to went upto end
          // successful in division

            // count <= k // we used the logic that if we can distribute pages in less than k students then we can also distribute it among k students //sabko kam se kam ek dedo, pages maintained rahenge. //vice versa no possible as pages exceed

            ans = mid;
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }



        // jo pages maine decide kiye h utna unhi me batna chahiye.
    }

    return ans; // each one get one book.

    // time complexity = N*log(n).
    // N is for inner while loop to check pointer position runned n time and overall binary has log n then n executed log n times hence total N*log(n) .
    // Space complexity : O(1)
}



// wall length is given in the array. We need to paint it by k painters, We need minimum time for all walls to be painted. 1 unit legth paint takes 1unit time.//all painters paints the contigous walls

int painterPartition(int arr[], int size, int k)
{

    int min = maxVal(arr, size), sum = 0, max, time, count, mid;

    for (int i = 0; i <= size - 1; i++)
    {
        sum += arr[i]; // it will run atleast once.
    }
    max = sum;
    int ans = sum;

    if (k > size - 1)
    {
        return -1;
    }

    while (max >= min)
    {
        mid = min + (max - min) / 2;
        time = 0, count = 1; //this mid value is somthing we can thing of deciding factor.

        for (int i = 0; i < size; i++)
        {
            if (mid >= time + arr[i])
            { // first check then update//note this condition otherwise gives error
                time += arr[i];
            }
            else
            {
                count++;
                time = arr[i]; // current index i is taken
            }
        }

        if (count <= k)
        { // jo kam me batega to jaida me bhi easily distribute hoga.
            ans = mid;
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }

    return ans;
}



int shipPackage(int arr[], int size, int k)
{ //min weight to be shiped for sending all the weight in k days

    int min = maxVal(arr, size), sum = 0, max, time, count, mid;

    for (int i = 0; i <= size - 1; i++)
    { 
        sum += arr[i]; // it will run atleast once.
    }
    max = sum;
    int ans = sum;

    if (k > size - 1)
    {
        return -1;
    }

    while (max >= min)
    {
        mid = min + (max - min) / 2;
        time = 0, count = 1;
        for (int i = 0; i < size; i++)
        {
            if (mid >= time + arr[i])
            { // first check then update//note this condition otherwise gives error
                time += arr[i];
            }
            else
            {
                count++;
                time = arr[i]; // current index i is taken
            }
        }

        if (count <= k)
        { // jo kam me batega to jaida me bhi easily distribute hoga.
            ans = mid;
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }

    return ans;
}

int main()
{

    // int arr[] = {12, 34, 67, 90}; // not necessary to be sorted.//113
    // int arr[] = {19,9,30,22,7}; // not necessary to be sorted.//30 pages planed to distribute among 4.
    // int arr[] = {5, 10, 30, 20, 15};//use in wall
    int arr[] = {3,2,2,4,1,4};//use in wall

    // answer hamesa max value in array se bada ya barabar hoga.

    int size = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << "Enter the number of children/painter/Days:";
    cin >> k;
    cout << distributionMin(arr, size, k) << endl;
    cout << painterPartition(arr, size, k) << endl;
    cout << shipPackage(arr, size, k) << endl;

    return 0;
}