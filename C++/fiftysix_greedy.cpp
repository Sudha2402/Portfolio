#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <stack>
#include <algorithm>

// min number of coins
// shop in candy Store
// Assign Mice to holes
// Min Rotation to unlock a circular Lock
// N meeting in a room

//
// min number of coins

vector<int> minNumCoins(int N)
{
    // N is the sum we need to generate
    int currency[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

    int noteFreq = 0, NoteCount = 0;
    vector<int> ans;

    // here we keep on divinding the N with starting index

    for (int i = 0; i < sizeof(currency) / sizeof(currency[0]); i++)
    {
        noteFreq = N / currency[i];
        while (noteFreq--)
        {
            // N=N-currency[i]; //this we can do with the help of % to get remainder value directly.

            ans.push_back(currency[i]);

            NoteCount++;
        }

        N = N % currency[i];
    }

    return ans;
}

// shop in candy Store

void sortCandies(int candies[], int N)
{
    // note that array don't need pointer

    // let's use bubble sort

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            if (candies[j] > candies[j + 1])
            {
                swap(candies[j], candies[j + 1]);
            }
        }
    }
}

vector<int> candyStore(int candies[], int N, int K)
{
    // n is candies size, k is the free candies after every buy

    // we have sort method in array
    // sortCandies(candies, N);

    sort(candies, candies + N); // this is inbuilt sort method and it works. candies is array and N is array size.

    cout << "Sorted Candies: ";
    for (int i = 0; i < N; i++)
    {
        cout << candies[i] << " ";
    }
    cout << endl;

    vector<int> ans;

    // we need two point one at start ans other at end for both min and max calculation

    int minCost = 0;
    int start = 0, end = N - 1;
    while (start <= end)
    {
        minCost += candies[start];
        start++;

        // this for loop is complicated, we can directly subtract K from end

        end -= K;

        // for (int i = 0; i < K; i++)
        // {
        //     end--;
        // }
    }

    ans.push_back(minCost);

    int maxCost = 0;
    start = 0, end = N - 1;
    while (start <= end)
    {
        maxCost += candies[end];
        end--;

        start += K;
    }

    ans.push_back(maxCost);

    return ans;
}

// Assign Mice to holes

int assignMiceHoles(int N, int M[], int H[])
{
    sort(M, M + N);
    sort(H, H + N);

    int maxTime = INT32_MIN;
    int diff;
    for (int i = 0; i < N; i++)
    {
        // diff = abs(M[i] - H[i]);
        // if (diff > maxTime)
        // {
        //     maxTime = abs(M[i] - H[i]);
        // }

        // or
        maxTime = max(maxTime, abs(M[i] - H[i]));
    }

    return maxTime;
}

// Min Rotation to unlock a circular Lock
int rotationCount(long long R, long long D)
{
    // we have to match individual bits

    int minRotation = 0;

    // modulus by 10 gives last digit, divide by 10 gives remaining

    while (R > 0 || D > 0)
    {
        int Rdigit = R % 10;
        int Ddigit = D % 10;

        R /= 10;
        D /= 10;

        // minRotation += min(abs(Ddigit - Rdigit), 10 - Rdigit + Ddigit);

        // or

        minRotation += min(abs(Ddigit - Rdigit), 10 - abs(Rdigit - Ddigit));

        // or
        //   int diff = abs(Ddigit - Rdigit);
        //  minRotation += min(diff, 10 - diff);
    }

    return minRotation;
}

// N meeting in a room
int maxMeeting(int start[], int end[], int n)
{
    // here we can't use direct sort method on end, we have to swap the start at the same position

    // priority_queue<pair<int, int>,vector<int>,greater<int>> meetings;//we need to recheck the sequence here vector int is wrong we shoud write inside the vector exactly the data we are using 
    // we could have used vector then sorted it.

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>meetings;//we need to check the sequence

    // vector<pair<int, int>> meetings;

    // we will use end,start so that it gets sorted on the bases of end that is at 0 index

    for (int i = 0; i < n; i++)
    {
        meetings.push(make_pair(end[i], start[i]));

        // meetings.push_back(make_pair(end[i], start[i]));
    }

    // sort(meetings.begin(), meetings.end());

    int maxMetting = 0;
    int endTime = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (meetings.top().second > endTime)
        // if (meetings[i].second > endTime)
        {
            maxMetting++;
            endTime = meetings.top().first;
            // endTime = meetings[i].first;
        }
        meetings.pop();
    }

    return maxMetting;
}

int main()
{
    // min number of coins
    vector<int> notesSplit = minNumCoins(143);
    for (int i = 0; i < notesSplit.size(); i++)
    {
        cout << notesSplit[i] << " ";
    }
    cout << endl; // 100 20 20 2 1

    // shop in candy Store
    int candies[] = {3, 2, 1, 4};
    int N = 4;
    int K = 2;
    vector<int> minMaxCostShop = candyStore(candies, N, K);
    cout << "minMaxCostShop[0] :" << minMaxCostShop[0] << " " << minMaxCostShop[1] << endl;

    // Assign Mice to holes
    int MousePos[] = {4, -4, 2};
    int HousePos[] = {4, 0, 5};
    int maxTime = assignMiceHoles(3, MousePos, HousePos);
    cout << "maxTime : " << maxTime << endl;

    // Min Rotation to unlock a circular Lock
    long long RealValues = 2345;
    long long DestValues = 5432;
    int minRotation = rotationCount(RealValues, DestValues);
    cout << "minRotation : " << minRotation << endl;

    // N meeting in a room
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int maxMettingCond = maxMeeting(start, end, 6);
    cout << "maxMettingConducted :" << maxMettingCond << endl;

    return 0;
}