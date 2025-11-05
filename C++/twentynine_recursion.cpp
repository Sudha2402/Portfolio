#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Find all the permutation

// find distinct permutation when dublicate values present.

// ways to Sum N. //I think I have done such question already

// //new brach is evaluated as it itself is parent in forward, then combine with ans+= new branch ans at the time of backtrack //

void permutation(int arr[], int size, vector<vector<int>> &permutationsPattern, vector<int> &tempHolder, int visited[], int &count)
// when we c=have case where all branch of each node is equal to the size of input, then use for loop with pushback and backtracking by popping and marking unvisited.

{
    if (tempHolder.size() == size)
    {
        permutationsPattern.push_back(tempHolder);

        count++;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (visited[i] == 0)
        {
            tempHolder.push_back(arr[i]);
            visited[i] = 1;
            permutation(arr, size, permutationsPattern, tempHolder, visited, count);

            // backtracking when same size and search when last time any incomple i value left in for loop.
            visited[i] = 0;
            tempHolder.pop_back();
        }
    }

    // last i value left will be continued after bactrack which was left inbetween recursion call.
}

// Permutation with concept of swapping where left position elements are fixed.//no visited and temp needed

void permutationSwap(vector<int> arr, int size, vector<vector<int>> &permutationsPattern, int &count, int index)

{
    if (index == size)
    {
        permutationsPattern.push_back(arr);
        count++;
        return;
    }

    for (int i = index; i < size; i++)
    {
        swap(arr[i], arr[index]);
        permutationSwap(arr, size, permutationsPattern, count, index + 1);

        // backtracking
        swap(arr[i], arr[index]);
    }
}

//

void permutationSwapRepeat(vector<int> arr, int size, vector<vector<int>> &permutationsPattern, int &count, int index)

{
    if (index == size)
    {
        permutationsPattern.push_back(arr);
        count++;
        return;
    }

    // for every permutation , we need new bool table
    //  for(int i=0;i<21;i++){
    //  arrFixed[i]=0;
    //  }

    //     Reset bool Array After Each Swap:
    // Since the same element can reappear later, we must reset the bool array after each swap and index and moved to new position

    vector<bool> arrFixed(21, 0);

    // Each call has its own arrFixed, so backtracking doesn’t interfere with previous checks.

    // arrFixed is Local to Each Recursive Call

    // It is recreated fresh every time permutationSwapRepeat is called.

    // Since it’s declared inside the function (not passed as a parameter), each call gets its own independent copy.

    // When backtracking happens (after recursion returns), the previous call’s arrFixed is still intact.

    for (int i = index; i < size; i++)
    {

        // if (arr[i] != arr[index] && i != index || arr[i] == arr[index] && i == index)
        // { // we need to check if the very left side fixed is same as this then not
        //     swap(arr[i], arr[index]);
        //     permutationSwapRepeat(arr, size, permutationsPattern, count, index + 1,arrFixed);

        //     // backtracking
        //     swap(arr[i], arr[index]);
        // }

        // No such com works, hence we need to track at the index value, other number has fixed or not

        if (!arrFixed[arr[i] + 10])
        { // we need to check if the very left side fixed is same as this then not
            swap(arr[i], arr[index]);

            arrFixed[arr[index] + 10] = 1; // making here 1 because in permutation, we will set it latter.

            permutationSwapRepeat(arr, size, permutationsPattern, count, index + 1);

            // backtracking
            swap(arr[i], arr[index]);
        }
    }
}

// same as above but want to call it in the Way to sum n permutation .

void permutationSwapRepeatInside(vector<int> arr, int size, vector<vector<int>> &SumNPattern, int &count, int index)
{

    // return cases
    if (index == size)
    {
        SumNPattern.push_back(arr);
        count++;
        return;
    }

    vector<bool> visited(21, 0);

    for (int i = index; i < size; i++)
    { // before index , we are fixing it's position

        if (visited[arr[i] + 10] == 0)
        {
            // swap, index with all i
            swap(arr[index], arr[i]);
            visited[arr[i] + 10] = 1;
            permutationSwapRepeatInside(arr, size, SumNPattern, count, index + 1);

            swap(arr[index], arr[i]);
        }
    }
}

// Way to sum n;//as no dublicate present hence no bool needed and vector array.//as orders matter hence , we need to check permutation also for each.
void SumN(int arr[], vector<vector<int>> &SumNPattern, vector<int> &temp, int size, int index, int sum, int target, int &count)
{

    // use multiple time the same,
    if (sum < 0)
    {
        // stop checking for further
        return;
    }
    // if (sum == 0 && index == size)
    else if (sum == 0)
    {

        // we will use permutation check over this temp vector then all combination will give the answer.

        //   we should call the permutation function here.

        permutationSwapRepeatInside(temp, temp.size(), SumNPattern, count, 0);

        // we got the pattern
        // SumNPattern.push_back(temp);
        // count++;

        return;
    }
    else if (index == size)
    {
        return;
    }

    // When multiple allowed
    // when current element is selected and decided to repeat
    temp.push_back(arr[index]);
    SumN(arr, SumNPattern, temp, size, index, sum - arr[index], target, count);
    temp.pop_back();

    //    when decided not to include
    SumN(arr, SumNPattern, temp, size, index + 1, sum, target, count);
}

int sumNWay(int arr[], int size, int sum)
{

    if (sum == 0)
    {
        return 1;
    }
    else if (sum < 0)
    {
        return 0;
    }


    // int ans = 0;
    long long ans = 0;

    cout << "ans out: " << ans << endl;

//     Local variable: Each recursive call gets its own ans.

// Accumulation: Results from deeper calls "bubble up" and are added to the caller's ans.

    for (int i = 0; i < size; i++)
    {
        ans += sumNWay(arr, size, sum - arr[i]);
         cout << "ans Inside: " << ans << endl;
    }

    // return ans;
    return ans%1000000007;//as per question for preventing overflow.
    
}


// Note pattern
// ans out: 0
// ans out: 0
// ans out: 0
// ans out: 0
// ans out: 0
// ans out: 0
// ans out: 0

// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 2
// ans Inside: 2
// ans Inside: 2

// here no inbetween ans=0 becuse all continued to be in same for loop 

// ans out: 0 //gets out of for loop, then ans it store is 0
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1

// ans Inside: 3  //at the time of return last ans stored is 2, and this return 1 combines to it and forms 3 in ans as update....
// ans Inside: 4

// Note

// ans Inside: 4 //this is store in ans, and from here again out of for loop is going to be evaluated, and it will start from ans=0 then and at time of return , it checks the last time ans... here , we can think ans starting from 0 so that , it's loop answer don't class from backtrack as when backtrack udated, it moves to next brach with that answer then . above that branch has not taken ans, hence we need to start from top branch even when evaluated individually, as when taking any brach from top to bottom, it gives the the ans in that branch then add up to the other braches in ans++

// ans out: 0
// ans out: 0
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1 //in new brach and final answer is updated in last time ans

// ans Inside: 5  //new brach is evaluated with top ans value then combine with ans+= new branch ans


// ans out: 0
// ans Inside: 1
// ans Inside: 1
// ans Inside: 1
// ans Inside: 6
// 6

int main()
{

    // // Find all the permutation
    // for permutation , we need to fix one value at a time, hence it can be used to deal like recursion

    int arr[] = {1, 2, 3};
    int size;
    size = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>> permutationsPattern;
    vector<int> tempHolder;
    int visited[size] = {0};
    int count = 0;
    permutation(arr, size, permutationsPattern, tempHolder, visited, count);

    // must visualize it with backtrack.

    cout << count << endl;

    for (int i = 0; i < permutationsPattern.size(); i++)
    {
        for (int j = 0; j < permutationsPattern[i].size(); j++)
        {
            cout << permutationsPattern[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    vector<int> arrSwap = {1, 2, 3};
    size = arrSwap.size();
    vector<vector<int>> permutationsPatternSwap;
    count = 0;

    permutationSwap(arrSwap, size, permutationsPatternSwap, count, 0);

    cout << count << endl;

    for (int i = 0; i < permutationsPatternSwap.size(); i++)
    {
        for (int j = 0; j < permutationsPatternSwap[i].size(); j++)
        {
            cout << permutationsPatternSwap[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // Permutation with repeatation
    vector<int> arrSwapRepeat = {1, 1, 2};
    size = arrSwapRepeat.size();
    vector<vector<int>> permutationsPatternSwapRepeat;
    count = 0;

    // bool arrFixed[21]={0}; // number can be from -10 to +10 //at index, 9..1 is stored. num+10 for index visit //as 10 if num stored at index 20.//it need to be reset after each swap as fixed moved to new level

    permutationSwapRepeat(arrSwapRepeat, size, permutationsPatternSwapRepeat, count, 0);

    cout << count << endl;

    for (int i = 0; i < permutationsPatternSwapRepeat.size(); i++)
    {
        for (int j = 0; j < permutationsPatternSwapRepeat[i].size(); j++)
        {
            cout << permutationsPatternSwapRepeat[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    int waySumN[] = {1, 5, 6};
    // int waySumN[] = {1, 2, 1};
    vector<vector<int>> SumNPattern;
    vector<int> temp;
    size = sizeof(waySumN) / sizeof(waySumN[0]);
    int targetSumN = 7;
    int targetSumNCount = 0;
    cout << targetSumNCount << endl;
    SumN(waySumN, SumNPattern, temp, size, 0, targetSumN, targetSumN, targetSumNCount);

    cout << targetSumNCount << endl;

    for (int i = 0; i < SumNPattern.size(); i++)
    {
        for (int j = 0; j < SumNPattern[i].size(); j++)
        {
            cout << SumNPattern[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << sumNWay(waySumN, size, targetSumN) << endl;
}