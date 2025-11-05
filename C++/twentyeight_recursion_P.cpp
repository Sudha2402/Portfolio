#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// set//subset//powerset//subsequence set//all same
// subsequence for "abc"
// generate parenthesis

// Subset Sum

// Target Sum

// Perfect Sum Problem

// // Target sum repeatation

//
//
//
//

// Whenever yes and no comes then we always use recursion and make tree where , we take and not take

//  as one time recursion takes constant time, hence for each node represent one recursion, node count will be time complexity. as all level has 2^n nodes. hence total will be 2^n+1-1.

// Note that in half partition, time taken is O(logn) but here it is power of 2, (wrong, it is height and each level sum is n, as individual size combine... here all node works constant time , here no base case is such that array size at last will be 1 hence we can comare to find the height. here , nothing to do with height for time complexity.

// Hence check relation that it is of yes, no type question hence 2^n will be checked.

// Space complexity.

// we calcuate ans size. 2^n total power set hence this much row, and each row can have max n elements. hence this time complexity is n*2^n.
// Time complexity in each recursion call taken by temp.It will be it's height.  temp has max size of n. and temp is created at each level, and max level is n times, hence O(n*n) comes here also.

// Hence combined space complexity is O( n*2^n +  n*n)

/*
How Recursion Handles temp
Pass by Value: Notice that temp is passed by value, not by reference. This means each recursive call gets its own copy of temp.

Stack Behavior: Each recursive call pushes a new stack frame with:

Its own copy of parameters (including temp)

The current execution state (program counter, etc.)

Two Branches at Each Level: At each index, you make two recursive calls:

One without modifying temp (exclusion case)

One after adding the current element to temp (inclusion case)

Example Walkthrough
Let's consider arr = [1, 2] (size = 2):

text
Initial call: powersetSubseq(arr, ans, [], 0, 2)
│
├─ Exclude arr[0] (1): powersetSubseq(arr, ans, [], 1, 2)
│  │
│  ├─ Exclude arr[1] (2): powersetSubseq(arr, ans, [], 2, 2) → ans = [[]]
│  │
│  └─ Include arr[1] (2): powersetSubseq(arr, ans, [2], 2, 2) → ans = [[], [2]]
│
└─ Include arr[0] (1): powersetSubseq(arr, ans, [1], 1, 2)
   │
   ├─ Exclude arr[1] (2): powersetSubseq(arr, ans, [1], 2, 2) → ans = [[], [2], [1]]
   │
   └─ Include arr[1] (2): powersetSubseq(arr, ans, [1,2], 2, 2) → ans = [[], [2], [1], [1,2]]
Key Points About Stack Storage
Each call gets its own temp: When you make the first recursive call (powersetSubseq(arr, ans, temp, index + 1, size)), it uses the current unmodified temp.

Modifications are local: When you do temp.push_back(arr[index]), this only affects the local temp copy for that specific recursive call and its descendants.

Original temp is preserved: The original temp (before the push) remains unchanged for the first recursive call because it was passed by value.

Base case captures current state: When you reach index == size, you capture whatever is in temp at that moment, which represents all the inclusion/exclusion decisions made along that particular path.

Visualization of Stack Frames
For arr = [1, 2]:

text
Call stack depth 0: temp = [], index = 0
  Call stack depth 1: temp = [], index = 1 (exclude 1)
    Call stack depth 2: temp = [], index = 2 → add [] to ans
    Call stack depth 2: temp = [2], index = 2 → add [2] to ans
  Call stack depth 1: temp = [1], index = 1 (include 1)
    Call stack depth 2: temp = [1], index = 2 → add [1] to ans
    Call stack depth 2: temp = [1,2], index = 2 → add [1,2] to ans
Why This Works Correctly
The exclusion path keeps the original temp unchanged

The inclusion path modifies a copy of temp (not the original)

All combinations are explored because at each element we try both including and excluding it

If temp were passed by reference, this wouldn't work because all recursive calls would be modifying the same vector. The pass-by-value approach ensures each call path maintains its own state.

*/

void powersetSubseq(int arr[], vector<vector<int>> &ans, vector<int> temp, int index, int size)
{

    if (index == size)
    {
        ans.push_back(temp);
        return;
    }

    // not include, simply move to next position.
    powersetSubseq(arr, ans, temp, index + 1, size);

    // if include then push back in temp.//then move the index.
    temp.push_back(arr[index]); // for space optimization, we could have used reference temp also, shown below
    powersetSubseq(arr, ans, temp, index + 1, size);
}

// it also works
void powersetSubseqSpO(int arr[], vector<vector<int>> &ans2, vector<int> &temp, int index, int size)
{

    if (index == size)
    {
        ans2.push_back(temp);
        return;
    }

    // not include, simply move to next position.
    powersetSubseq(arr, ans2, temp, index + 1, size);

    // if include then push back in temp.//then move the index.
    temp.push_back(arr[index]); // for space optimization, we could have used reference temp also, shown below
    powersetSubseq(arr, ans2, temp, index + 1, size);
    temp.pop_back();
}

void powersetSubseqStrSpO(string arr, vector<vector<char>> &ansStr, vector<char> &temp, int index, int size)
{

    // Yes, push_back() is a member function of the std::string class in C++. It is used to append a single character to the end of the string.

    if (index == size)
    {
        ansStr.push_back(temp);
        return;
    }

    // not include, simply move to next position.
    powersetSubseqStrSpO(arr, ansStr, temp, index + 1, size);

    // if include then push back in temp.//then move the index.
    temp.push_back(arr[index]); // for space optimization, we could have used reference temp also, shown below

    powersetSubseqStrSpO(arr, ansStr, temp, index + 1, size);
    temp.pop_back();
}

void powersetSubseqStrSpO2(string arr, vector<string> &ansStr, string &temp, int index, int size)
{

    // Yes, push_back() is a member function of the std::string class in C++. It is used to append a single character to the end of the string.

    if (index == size)
    {
        ansStr.push_back(temp);
        return;
    }

    // not include, simply move to next position.
    powersetSubseqStrSpO2(arr, ansStr, temp, index + 1, size);
    //

    // if include then push back in temp.//then move the index.
    temp.push_back(arr[index]); // for space optimization, we could have used reference temp also, shown below

    powersetSubseqStrSpO2(arr, ansStr, temp, index + 1, size);
    temp.pop_back();
}

// generate parenthesi
// void generateParanthesis(vector<string> &ansParenthesis, string &temppara, int brackets, int leftCount, int rightCount, char character)
void generateParanthesis(vector<string> &ansParenthesis, string &temppara, int brackets, int leftCount, int rightCount)
{

    // // int leftCount = 0, rightCount = 0;

    // if (character == '(')
    // {
    //     leftCount += 1;
    // }
    // else if (character == ')')
    // {
    //     rightCount += 1;
    // }

    // if (rightCount > leftCount)
    // {
    //     return;
    // }
    // specify this condition inside

    //  // Base case: we've used all brackets
    if (leftCount == brackets && rightCount == brackets)
    {
        ansParenthesis.push_back(temppara);
        return;
    }

    // The issue is that you're modifying leftCount and rightCount before passing them to recursive calls, but these modifications persist when you backtrack (after pop_back()). This causes incorrect counts when exploring different branches of the recursion tree.

    //  // Add '(' if we haven't used all left brackets
    if (leftCount <= brackets)
    {
        // Include left
        temppara.push_back('('); // left charpassed is pushed
        // leftCount++;
        generateParanthesis(ansParenthesis, temppara, brackets, leftCount + 1, rightCount); // this will help instead of using extra modifier as, it persist for all.//on backtracking, this count will be according to that back level not this incremented.
        temppara.pop_back();
    }

    // Include Right// // Add ')' if we have more '(' than ')'
    if (rightCount < leftCount)
    {
        // Include left
        temppara.push_back(')'); // right charpassed is pushed
        // rightCount++;
        generateParanthesis(ansParenthesis, temppara, brackets, leftCount, rightCount + 1);
        temppara.pop_back(); // // Backtrack
    }
}

// subset sum
void subsetSum(int arr[], int index, vector<int> &subsetSumAns, int sum, vector<vector<int>> &subsetSumAnsExp, vector<int> &tempArray, int size)
{ // here as we need only sum hence  temparray is not necessary to create.//we just need sum value properly passed in eah step.
    if (index == size)
    {
        subsetSumAns.push_back(sum); //  // just for purpose of printing, we could have cout sum here directly
        subsetSumAnsExp.push_back(tempArray);
        return;
    }

    // Any can be done before.

    // not include
    subsetSum(arr, index + 1, subsetSumAns, sum, subsetSumAnsExp, tempArray, size);

    // include that index;
    tempArray.push_back(arr[index]); // only for temp and can be remove

    subsetSum(arr, index + 1, subsetSumAns, sum + arr[index], subsetSumAnsExp, tempArray, size);

    tempArray.pop_back(); ////only for temp and can be remove
}

bool findTarget(int arr[], int index, int sum, int size, int target)
{
    if (sum == target)
    {
        return 1;
    }

    if (index == size || sum > target)
    {
        return 0;
    }

    // not include
    return findTarget(arr, index + 1, sum, size, target) || findTarget(arr, index + 1, sum + arr[index], size, target); // here or has benefit , even one return true then it will not check other part and time will be left.

    // inbetween return is not the final answer, it return back here and radom number would have been generated, hence specify return at last. Then tohose return has to be reflected, hence , return must be at last for recursion call.
}

// Perfect Sum Problem
void PerfectsubsetSum(int arr[], int index, int sum, vector<vector<int>> &subsetSumAnsExp, vector<int> &tempArray, int size, int target, int &count)
{

    // if (index == size && sum != target || sum > target)
    if (index == size && sum != target) // now this will handle negative number also
    {                                   // we could have also done in this way where we keep decreasing sum on the bases of selected index array from target. then if this comes == 0 then it is match and if < target then not a match.

        return;
    }

    else if (index == size && sum == target)
    { // as we are returning only after complete subset from hence less chaces of fail in 0
        subsetSumAnsExp.push_back(tempArray);
        count++;
        return;
    }

    // Any can be done before.

    // not include
    PerfectsubsetSum(arr, index + 1, sum, subsetSumAnsExp, tempArray, size, target, count);

    // include that index;
    tempArray.push_back(arr[index]); // only for temp and can be remove

    PerfectsubsetSum(arr, index + 1, sum + arr[index], subsetSumAnsExp, tempArray, size, target, count);

    tempArray.pop_back(); ////only for temp and can be remove

    // just for retuning the count , return PerfectsubsetSum(arr, index + 1, sum, subsetSumAnsExp, tempArray, size, target)+PerfectsubsetSum(arr, index + 1, sum + arr[index], subsetSumAnsExp, tempArray, size, target);  //return 1 when found, return 0 when not found , as in compiler, it is asking for greater 10^9+7 hence take, modulus. then return (...)%1000000007

    //
}

//

// Target sum repeatation

//
// Worst case: sum / min(repeatArr) (if min(repeatArr) = 1, depth = sum).
// Example: If sum = 10 and repeatArr = [1, 2], the recursion can go up to 10 levels deep.

// The recursion tree grows exponentially with sum.
// Time = O(2^(sum/min_element)) (very slow for large sum).
// With Memoization (DP Optimization):
// If we cache results for (sum, index), we reduce it to polynomial time.
// Time = O(size × sum) (pseudo-polynomial).

void repeatSumTarget(int repeatArr[], vector<vector<int>> &SumRepeatSet, vector<int> &tempArr, int &count, int sum, int size, int index, int target)
{

    if (sum < 0 || index == size)
    {
        // over deducted, hence return//expecting no negative numbers
        return;
    }
    // else if (sum == 0 && index == size)
    if (sum == 0 && index == size) // as we have combined two above
    {
        // exactly matched the target
        SumRepeatSet.push_back(tempArr);
        count++;
        return;
    }
    // else if (index == size)
    // { //make sure to cover all return cases.
    //     return;//same type can be in or
    // }

    // not include index
    repeatSumTarget(repeatArr, SumRepeatSet, tempArr, count, sum, size, index + 1, target);

    // include mutiple time
    if (sum >= 0)
    {
        tempArr.push_back(repeatArr[index]);
        repeatSumTarget(repeatArr, SumRepeatSet, tempArr, count, sum - repeatArr[index], size, index, target);
        tempArr.pop_back();
    }
}

int main()
{

    // subsequence
    // power set but elements must be in same sequence

    int arr[] = {1, 2, 3};
    vector<vector<int>> ans;
    vector<vector<int>> ans2;
    vector<int> temp;
    int size = sizeof(arr) / sizeof(arr[0]);

    powersetSubseq(arr, ans, temp, 0, size);
    powersetSubseqSpO(arr, ans2, temp, 0, size);

    // print this 2D vector
    for (int i = 0; i < ans.size(); ++i)
    { // Iterate through rows
        for (int j = 0; j < ans[i].size(); ++j)
        { // Iterate through columns of the current row
            cout << ans[i][j] << " ";
        }
        cout << endl; // Move to the next line after printing a row
    }

    // print this 2D vector
    for (int i = 0; i < ans2.size(); ++i)
    { // Iterate through rows
        for (int j = 0; j < ans2[i].size(); ++j)
        { // Iterate through columns of the current row
            cout << ans2[i][j] << " ";
        }
        cout << endl; // Move to the next line after printing a row
    }

    // subsequence on string
    string Str = "abc";
    vector<vector<char>> ansStr; // we could have used string vector simply.
    vector<char> tempChar;       // string temp could have been used directly.
    size = Str.size();           // size: 3
    // cout<<"size: "<<size<<endl;

    powersetSubseqStrSpO(Str, ansStr, tempChar, 0, size);

    // print this 2D vector
    for (int i = 0; i < ansStr.size(); ++i)
    { // Iterate through rows
        for (int j = 0; j < ansStr[i].size(); ++j)
        { // Iterate through columns of the current row
            cout << ansStr[i][j] << " ";
        }
        cout << endl; // Move to the next line after printing a row
    }

    // subsequence on string
    // string Str = "abc";
    vector<string> ansStr2;
    string tempChar2;
    size = Str.size();

    powersetSubseqStrSpO2(Str, ansStr2, tempChar2, 0, size);

    // now to print this
    for (int i = 0; i < ansStr2.size(); ++i)
    { // Iterate through rows

        cout << ansStr2[i] << " ";
    }
    cout << endl;

    // generate arenthesis possible brackets
    // number of brackets=3
    int brackets = 3;
    vector<string> ansParenthesis;
    string temppara;
    // generateParanthesis(ansParenthesis, temppara, brackets, 0, 0, '('); //passing the first characters create error as we need to handle in function

    generateParanthesis(ansParenthesis, temppara, brackets, 0, 0);

    for (int i = 0; i < ansParenthesis.size(); i++)
    {
        cout << ansParenthesis[i] << endl;
    }

    // subset sum
    int arrSubSum[] = {3, 4, 5};
    vector<int> subsetSumAns;
    vector<vector<int>> subsetSumAnsExp;
    vector<int> tempArray;
    size = sizeof(arrSubSum) / sizeof(arrSubSum[0]);
    subsetSum(arrSubSum, 0, subsetSumAns, 0, subsetSumAnsExp, tempArray, size);

    // print subset sum
    for (int i = 0; i < subsetSumAns.size(); i++)
    {
        cout << subsetSumAns[i] << " ";
    }
    cout << endl;
    // 12 7 8 3 9 4 5 0 //0 5 4 9 3 8 7 12

    for (int i = 0; i < subsetSumAnsExp.size(); ++i)
    { // Iterate through rows

        cout << "Sum: " << subsetSumAns[i] << "{";

        for (int j = 0; j < subsetSumAnsExp[i].size(); ++j)
        { // Iterate through columns of the current row
            cout << subsetSumAnsExp[i][j] << " ";
        }
        cout << "}" << endl; // Move to the next line after printing a row
    }

    // Target Sum
    // We have to find the it's subset whose sum is equal to the target.
    int arrTargetSum[] = {3, 6, 4, 5};

    size = sizeof(arrTargetSum) / sizeof(arrTargetSum[0]);
    int targetSubSum = 12;
    cout << findTarget(arrTargetSum, 0, 0, size, targetSubSum) << endl;

    // PerfectSum
    // int perfectSumArray[] = {5, 2, 3, 6, 10, 8};
    int perfectSumArray[] = {1, 0};
    int countPerfect = 0;
    vector<vector<int>> subsetPerfectSumAnsExp;
    vector<int> tempPerfectArray;
    size = sizeof(perfectSumArray) / sizeof(perfectSumArray[0]);

    // PerfectsubsetSum(perfectSumArray, 0, 0, subsetPerfectSumAnsExp, tempPerfectArray, size, 10, countPerfect);
    PerfectsubsetSum(perfectSumArray, 0, 0, subsetPerfectSumAnsExp, tempPerfectArray, size, 1, countPerfect);

    cout << countPerfect << endl;

    for (int i = 0; i < subsetPerfectSumAnsExp.size(); ++i)
    {

        for (int j = 0; j < subsetPerfectSumAnsExp[i].size(); ++j)
        {
            cout << subsetPerfectSumAnsExp[i][j] << " ";
        }

        cout << endl;
    }

    // // Target sum repeatation
    // here repeatation is allowed.
    // let's try to write it's code.

    // we will find all possible till index reach last and sum not overflow.
    int repeatArr[] = {2, 3, 4};
    // int repeatArr[] = {2, 3, 4,0}; //if zero will be here then it be be caught in infinite loop as multiple time 0 is keep adding, hence works only when 0 is not present, else , if 0 is find then remove it from checking

    int sumRepeatTarget = 6;
    vector<vector<int>> SumRepeatSet;
    vector<int> SumRepeatSettemp;
    size = sizeof(repeatArr) / sizeof(repeatArr[0]);
    int countRepeatTarget = 0;

    repeatSumTarget(repeatArr, SumRepeatSet, SumRepeatSettemp, countRepeatTarget, sumRepeatTarget, size, 0, sumRepeatTarget);

    cout << countRepeatTarget << endl;

    cout << endl;

    for (int i = 0; i < SumRepeatSet.size(); ++i)
    {

        for (int j = 0; j < SumRepeatSet[i].size(); ++j)
        {
            cout << SumRepeatSet[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}