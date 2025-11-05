
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// next greater element right
// next smallest element right
// next greater element left
// next smallest element left
// Next greater element 2

// for below problems, we need count apprach/range/as group of numbers asked
// Stock Span Problem
// largest rectangle in histogram
// minimal rectangle in 2D
// the celebrity Problem
// push, pop, getmin in O(1)
// maximum of minimum from every window size
// minimum of maximum from every window size //do later
// implement two stack in an array
// implement N stack in an array

// in all we have to return a vector as an answer
// here in all question we need to store the history so that we can get the ast time data used needed for comparison, hence we need not to traverse again for each index value.
// we could have solve this using brute force method by moving from left to right in one traverse and then from current index move to extreme for comparison hence it would take O(n^2), time complexity, hence we need to use stack method, even if not stack then it will not be easy to implement, for this we will be needed pointer//hence for storing the last time data we need some space extra, hence we prefer to use stack as it takes the same space as a vector of same size with pointer taken, it would have also took every thing same.

// In such question we use union approch where if one element requirement is not fullfilled by the next the that element and next element together go for searching the answer. If they get to third and third managed to remove the second element doubt then 2 will leave. now if third one not able to answer first element doubt then their doubts add up and not they further traverse to get their answer. here we have to think that last one has more doubt then the next one hence, if next one element doubt is satified then it does not means the first element is also satisfird. hence we need to keep traversing the first untill it is satified. similary it is applied for all.

// Note: always use stack concept when adjacent, nearest type question is aksed.

// Note write pop in while loop , then push at the end in all

vector<int> nextGreaterRight(int arr[], int n)
{
    // we have to traverse till top element do not get the nearest max.if it gets, then that max will ask others if it is max for any other then remove it also from the collection/team then the element will involve in the team and find it's max //here stack in decreasing order from bottom to top will be formed. all smaller elements are combining to gether to get theit max.//we will put index in the stack for easily value access because if elements are pushed and popped, inbetween then index will be lost hence we use index instead of element itself to push into the stack

    vector<int> ans(n, -1); // greatest min right will be not be present // hence for those position , initialized with -1

    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        // if (s.empty())
        // {
        //     s.push(i);
        // }
        // else
        // {

        while (!s.empty() && arr[i] > arr[s.top()])
        { // equal even not allowed as max //here we also need to check if continous pop has made it empty then break the loop //this empty is enough to handle the top if condition also, hence we can remove if else condition
            ans[s.top()] = arr[i];
            s.pop();
        }

        // after satisfying all, it has pushed itselt into the stack.
        s.push(i);

        // }
    }

    // either initialize with -1 or use this to set value there
    // while (s.empty())
    // {
    //     ans[s.top()] = -1;
    //     s.pop();
    // }

    return ans;
}

// here traversing from backside
vector<int> nextGreaterRight2(int arr[], int n)
{

    vector<int> ans(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        // this is exactly same as bottom one hence remove it
        // if (!s.empty() && arr[i] < arr[s.top()])
        // { // right side will be max

        //     ans[i] = arr[s.top()];

        //     // s.push(i); // pushing so that we can check if it could be the naearest max of elements in left side //it is common to push in all hence written in bottom
        // }

        while (!s.empty() && arr[i] > arr[s.top()])
        { // if it becomes greater than nearest for other in the left, hence the smallesr in the stack presnt has no use hence pop it

            s.pop(); // while loop is used in pop operation mainly for continuosly
        }

        // if (!s.empty() &&  arr[i] < arr[s.top()])
        if (!s.empty()) // empty statement is enough to update as we have come to this line after removeing all the smallest.
        {
            ans[i] = arr[s.top()];
        }

        s.push(i);
    }

    return ans;
}

vector<int> nextSmallerRight(int arr[], int n)
{
    vector<int> ans(n, -1);

    stack<int> s;

    for (int i = 0; i < n; i++)
    {

        while (!s.empty() && arr[i] < arr[s.top()])
        { // previous has got it's smallest now pop it

            ans[s.top()] = arr[i];
            s.pop();
        }

        s.push(i);
    }

    return ans;
}

vector<int> smallestleft(int arr[], int n)
{ // stack of all smaller elements in the stack//decreasing order from bottom to top

    vector<int> ans(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) // here we could have started from backside also then whilw with if would not have been needed
    {
        while (!s.empty() && arr[i] <= arr[s.top()])
        {
            s.pop();
        }

        if (!s.empty() && arr[i] > arr[s.top()])
        { // push if it is bigger than top, here stack of increasing from bottom to top will be formed
            ans[i] = arr[s.top()];
            // s.pop();
        }

        s.push(i);
    }

    return ans;
}

vector<int> smallestleft2(int arr[], int n)
{

    vector<int> ans(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!s.empty() && arr[i] < arr[s.top()])
        {
            ans[s.top()] = arr[i];
            s.pop();
        }

        s.push(i);
    }

    return ans;
}

//  next greater element left
vector<int> nextGreaterleft(int arr[], int n)
{ // stack of all greater elements in the stack//or reverse the array, finding all gretest in left from back

    vector<int> ans(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {

        while (!s.empty() && arr[i] >= arr[s.top()])
        {
            s.pop();
        }
        if (!s.empty() && arr[i] < arr[s.top()])
        { // push if it is bigger than top, here stack of increasing from bottom to top will be formed
            ans[i] = arr[s.top()];
            // s.pop();
        }

        s.push(i);
    }

    return ans;
}

vector<int> nextGreaterleft2(int arr[], int n)
{

    vector<int> ans(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!s.empty() && arr[i] > arr[s.top()])
        {
            ans[s.top()] = arr[i];
            s.pop();
        }

        s.push(i);
    }

    return ans;
}

// Next greater element 2
vector<int> nextGreaterRightRevole2(int arr[], int n)
{

    vector<int> ans(n, -1);

    stack<int> s;

    for (int i = 0; i < 2 * n; i++)
    {

        while (!s.empty() && arr[i % n] > arr[s.top()])
        {
            ans[s.top()] = arr[i % n];
            s.pop();
        }

        if (i >= n && s.empty())
        {
            return ans;
        } // not required as we are using the push only if i<n//here even we remove it not impact the answer

        //  // Only push indices during the first traversal
        if (i < n)
        {
            s.push(i);
        }
    }

    // if stack is not empty means they have not got there greater max, hence restart i from 0 upto end

    return ans;
}

// Stock Span Problem

// as we need to count the low but for that we used the logic to find the greastest nearest left but wat if no such present then this smaller will remain uncounted but they should be in answer, hence we will cover that case also

// As it is range calculation, we have to consider the index -1 before 0 and 9 after size so that we can calculate the count / range accurately

// Span of stock prince is the number of days for which it had been in lost from current data.
// hence we find last greater tha this.

vector<int> stockSpan(int arr[], int n)
{

    vector<int> ans(n, 1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!s.empty() && arr[i] > arr[s.top()])
        {

            ans[s.top()] = s.top() - i;
            s.pop();
        }

        s.push(i);
    }

    if (!s.empty())
    {
        // it means next greater we can suume to be at -1
        while (!s.empty())
        {
            ans[s.top()] = s.top() - (-1);
            s.pop();
        }
    }

    return ans;
}

// largest rectangle in histogram
int largestRectArea(int arr[], int n)
{
    // for this we need to find the range upto which this height element can be made in both the direction, hence we need to find nearest smallest right and nearest smallest left. then calculate the range
    // for solving any such problem , pick the middle one element and then analyse, from all direction and calculate answer for it, then move to edge cases

    // when after popping all between two equal 2, this 0 index will be counted, equal we have not considered in left min //we can have some test cases for this when after pop, it is not min left but equal

    int ans = 0;
    stack<int> s;

    int index = -1;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[i] < arr[s.top()])
        {
            // ans=max(ans,i-s.top())//calulate only right side possible, for claculating the left side possible we need to do further calcualtion , but we can use sense that we are pushing only indexthan previous, hence the element present just below the top of stack will be smalller than the current hence that will be the index of leftmost smallest

            index = s.top();

            // s.top ke liye max dhuda ja raha h
            s.pop();
            // s.top might be equal of before also, hence we can st it more -1

            if (!s.empty())
            {
                if (arr[index] == arr[s.top()])
                {
                    // then it will not be left min as it can also be included in area, but we will not pop as for the same before , we need to find range, hence must remain in stack, just change the ans value
                    ans = max(ans, (i - (s.top() - 1) - 1) * arr[index]);
                }
                else
                {
                    ans = max(ans, (i - s.top() - 1) * arr[index]); // this exactly update the ans//shows the height// calculated total area also.
                }
            }
            else
            {
                // ans = max(ans, (index+ i - (-1)- 1) * arr[i]);
                // ans = max(ans, (index+ i) * arr[i]);
                ans = max(ans, i * arr[index]); //-1 index is min last fro it
            }

            // cout << ans << " ";
        }

        s.push(i);
    }

    while (!s.empty())
    { // not able to find the next greater

        index = s.top();

        s.pop();
        if (!s.empty())
        {
            ans = max(ans, (n - s.top() - 1) * arr[index]); // this exactly update the ans//shows the height// calculated total area also.
        }
        else
        {

            ans = max(ans, (n - 1) * arr[index]);
        }

        // cout << ans << " ";
    }

    // cout << endl;

    return ans;
}

// // largest rectangle in histogram //we would have used seperate function to find right smalles then left smallest and then returned the answer.
int largestRectArea2(int arr[], int n)
{

    int ans = 0;
    stack<int> s;

    vector<int> right(n, n);
    vector<int> left(n, -1);

    // we need to create right smallest, left smallest vector seperately
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[i] < arr[s.top()])
        {
            right[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }
    // if all not got's it right min index then it will be 9 /n, hence initialise with n
    // we need to pop all from stack because we have alredy set n as it's smallest index right

    while (!s.empty())
    {
        s.pop();
    }

    // left smallest vector seperately
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] < arr[s.top()])
        {
            left[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }
    // if all not got's it left min index then it will be -1 , hence initialise with -1
    while (!s.empty())
    {
        s.pop();
    }

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (right[i] - left[i] - 1) * arr[i]);
    }

    return ans; // solve in O(2n)
}

// maximal rectangle in 2D with only 1 value inside and no 0 in the rectangle
// We can solve using row by row histogram asumption and keep finding the max.
// we can solve it using dyanmic programming, also so we will do it later.

// let's solve it using histogram
// here vector of string is passed as 2D, but actually 1D

int maxRect(vector<string> arr)
{
    int ans = 0;
    // vector<int> last(arr[0].size(), 0); // column wise

    int last[arr[0].size()] = {0}; // useful to pass in last time used function, hence we need not to rewrite

    for (int i = 0; i < arr.size(); i++)
    {
        cout << "row this time is: ";
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == '0')
            {
                last[j] = arr[i][j] - '0'; // necessary to convert the char to int arr[i][j] gives 49, hence this is ascii char

                // last[j] = arr[i][j];

                // this can be done directly alse
                // last[j]=0;
            }
            else
            {
                last[j] = last[j] + arr[i][j] - '0';
                // last[j] = last[j] + arr[i][j];

                // last[j] +=1;
            }

            cout << last[j] << " ";
        }

        cout << endl;

        // we have the vector holding the height
        // call histogram agrea for this

        ans = max(ans, largestRectArea(last, arr[0].size())); // the cout is also writtem in between to track
    }

    // we are taking O(n^2), time complexity.

    return ans;
}

// the celebrity Problem
// here we need to find the celebrity among persons such that celebraity is known by all and celebrity knows none.

// we are given table but here it is mentioned that a person don't know himselt, as it shows in diagonal.
// we have to return the celebrity number

// find the celebrity in a group of people, where a celebrity is defined as someone who knows no one (all zeros in their row) but is known by everyone else (all ones in their column, except for themselves).

// here we are taking O(n^2), for comparing all one by one

int celebrity(vector<string> &arr)
{ // stop from making copy of itself

    // we will handle row wise such that if all zero means this person can be celebrity as he don't know any one from column, then check if this row in colum is known by all  itself
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        bool flag = 1; // let's start thinking it knows noone

        for (int j = 0; j < arr[i].size(); j++)
        {
            // this way is complext to handle, hence reverse the if else condition
            // if (arr[i][j] == '0')
            // { // can be celebraity
            //     continue;
            // }
            // else
            // {
            //     // break inner for loop;
            //     j = arr[i].size();
            //     flag = 0;
            // }

            if (arr[i][j] == '1')
            {

                // In C++, the break statement only breaks the innermost loop (or switch statement) that it is directly inside. It does not break out of all nested loops.

                // be clear to use break from now onwards
                flag = 0;
                break; //// This breaks only the inner j-loop
            }
        }

        if (flag)
        {
            bool knownByAll = 1; // this i element can be celebrity

            // check for all column with j value

            for (int k = 0; k < arr.size(); k++)
            {
                // if (arr[k][j] == '0' && k == j)
                // {
                //     // set i inner to last to leave it
                //     continue;
                // }
                // else if (arr[k][j] == '0' && i k= j)
                // {
                //     flag = 0;
                //     k = arr.size();
                // }

                if (k == i)
                    continue; // skip self
                if (arr[k][i] == '0')
                {
                    knownByAll = false;
                    break;
                }
            }

            if (knownByAll == 1)
            {
                return i + 1; // ans
            }
        }
    }

    return ans;
}

// to optimize the celebrity problem, we can use stack to remove those cases where that people can't be clebraity at all.
// consider first and second, if both knows each other than both will not be celebrity
// consider first and second, if none knows each other than both will not be celebrity
// consider first and second, if first knows second and second not know the first then first will not be celebrity and second could be hence we can push it into stack, pop when don't know case come ot know case comes

// this is not easily understoodable as we are elemeinate before entering as candidate, hence it is OK but not easy to undersatand. In practical life , we set all the cnadidates then eliminate one by one.

int celebrityOpti(vector<string> &arr)
{
    int ans = 0;
    stack<int> s;

    // int first = -1, second = -1;
    bool flag = 1; // insert

    for (int i = 0; i < arr.size(); i++)
    {
        // second = i;
        flag = 1;

        // cout << i << endl;

        while (!s.empty() && (arr[i][s.top()] == arr[s.top()][i])) // we are asking 2 if it knows the s.top() by arr[i][s.top()] and s.top() is also asked if it knows i by arr[s.top()][i] //if both comes 1 == 1 or 0 ==0 , both are not celebrity.
        {
            s.pop();

            // first = s.top();//here for updating the first , we again need to check if stack not empty

            flag = 0;
            // i also not should be pushed
        }
        while (!s.empty() && arr[i][s.top()] == '0' && arr[s.top()][i] == '1')
        {

            s.pop();
            // first = s.top();
        }

        if (flag && s.empty())
        {
            s.push(i);
            // first = s.top();
        }
    }

    if (!s.empty())
    {
        flag = 1;
        // we need to cross check if this is the person who knows none and known by all
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[s.top()][i] != '0')
            {
                flag = 0;
                break;
            }
            if (arr[i][s.top()] == '0' && i != s.top())
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            return s.top() + 1;
        }
    }

    return -1;
}

// pushing all in one go as all possible candidates, then eliminating one by one works and more easier to understand.
int celebrityOpti2(vector<string> &arr)
{
    int ans = 0;
    stack<int> s;
    int first = -1, second = -1;
    // here we don't need to use flag

    for (int i = 0; i < arr.size(); i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        first = s.top();
        s.pop();

        // if only one left and second trying to access the top, then this will create problem, hence as last remained should be the ans, we will set linit greater than 1 size of stack

        second = s.top();
        s.pop();

        // now compare the case for celebrity
        // if(arr[first][second] == arr[second][first]){
        //     // both knows oth both don't know
        //     continue;
        // }

        if (arr[first][second] == '0' && arr[second][first] == '1')
        {
            // push first
            s.push(first);
        }
        else if (arr[first][second] == '1' && arr[second][first] == '0')
        {
            s.push(second);
        }
    }

    // now cross check the num
    int num = s.top();
    cout << num << endl;

    s.pop();
    // int row=arr.size();
    // int col=arr.size();

    // we can use the logic for row sum should be 0 and for col, sum should be size-1
    int row = 0, col = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        // row += arr[num][i];
        // col += arr[i][num];

        row += (arr[num][i] - '0');
        col += (arr[i][num] - '0');
    }

    cout << num << endl;
    cout << row << endl;
    cout << col << endl;

    return row == 0 && col == arr.size() - 1 ? num + 1 : -1;
}

// Get minimum element from stack.
// we have to do it in O(1) as we do for push and pop
// create function push,pop,getmin all in O(1)

class stackO1
{

    stack<int> s1; // for storing the stack data
    stack<int> s2; // for storing min data

    // if we don't want different stack, we can store at one place using range for modulous. It works only in case of range defined. for range -int to +int then it will not work.

public:
    void _push(int x)
    {
        if (s1.empty())
        {
            s1.push(x);
            s2.push(x);

            // combined
        }
        else
        {
            s1.push(x);
            s2.push(min(x, s2.top()));
        }
    }

    int _pop()
    {
        if (s1.empty())
        {
            return -1;
        }
        int poppedMin = getmin();
        s1.pop();
        s2.pop();
        return poppedMin;
    }

    int getmin()
    {
        if (s2.empty())
        {
            return -1;
        }
        return s2.top();
    }
};

class stackO2
{

    stack<int> s1;

    // if we don't want different stack, we can store at one place using range for modulous. It works only in case of range defined. for range -int to +int then it will not work.
    int range = 100; // if range is 1 to 99

public:
    void _push(int x)
    {
        if (s1.empty())
        {
            s1.push(x * range + x); // data we want to get with division and min with modulus remainder

            // combined
        }
        else
        {
            s1.push((x * range) + min(x, s1.top() % range));
        }
    }

    int _pop()
    {
        if (s1.empty())
        {
            return -1;
        }
        int poppedMin = getmin();
        // if we have to return element
        poppedMin = s1.top() / range;

        s1.pop();

        return poppedMin;
    }

    int getmin()
    {
        if (s1.empty())
        {
            return -1;
        }
        return s1.top() % range;
    }
};

//  maximum of minimum fro every window size
// we could have solves it in O(n^3) sing brute force method.
// maximum size of sliding window is size of arr
// here we need three loops , out loop for window size, innerforloop for getting elements in the window and innermost for getting the min in the window

vector<int> maxOfMiniWindowSize(int arr[], int size)
{ // it is taking O(n^3)
    vector<int> ans(size, INT32_MIN);
    for (int i = 1; i <= size; i++)
    {

        for (int j = 0; j <= size - i; j++)
        {
            int mini = INT32_MAX;
            for (int k = j; k < j + i; k++)
            {
                mini = min(mini, arr[k]);
            }
            ans[i - 1] = max(ans[i - 1], mini);
        }
    }

    return ans;
}

// solve in O(n^2)
vector<int> maxOfMiniWindowSizeOn2(int arr[], int size)
{ // it is taking O(n^2)
    vector<int> ans(size, INT32_MIN);

    for (int i = 0; i < size; i++)
    {
        int mini = INT32_MAX;

        for (int j = i; j < size; j++)
        {
            mini = min(mini, arr[j]); //// Update minimum for current window

            // ans[j] = max(ans[j], mini);//this is stupid logic as if j=3, then it can have window size from 1 to size all, we have not include that, we simply consider it from 3 index to more size

            int windowSize = j - i;

            ans[windowSize] = max(ans[windowSize], mini); // make sure to use it correctly
        }
    }

    return ans;
}

// for index storation
vector<int> smallestleftIndex(int arr[], int n)
{

    vector<int> ans(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!s.empty() && arr[i] < arr[s.top()])
        {
            ans[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    return ans;
}

vector<int> nextSmallerRightIndex(int arr[], int n)
{
    vector<int> ans(n, n);

    stack<int> s;

    for (int i = 0; i < n; i++)
    {

        while (!s.empty() && arr[i] < arr[s.top()])
        { // previous has got it's smallest now pop it

            ans[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    return ans;
}

// to solve in O(n), solve by asking the elements for whick k size it can be min there. //element needs to be min hence we will use max at the k size valued and put it everywhere possible

// here simply we are using the concept that if we get the window size upto which the given element can be min then for all those window size, we have this value comes in presence , hence we can update this value upto those window size if it is max among the min

// window size slid hoge kabhi na kabhi us tak jarur pahuchegi

// hence we will find smallest left and smallest right to calculate the window size in which it will be manimum
vector<int> maxOfMiniWindowSizeStack(int arr[], int size)
{ // it is taking O(n^2)

    vector<int> ans(size, INT32_MIN);

    vector<int> NSR = nextSmallerRightIndex(arr, size);
    vector<int> NSL = smallestleftIndex(arr, size);

    for (int i = 0; i < size; i++)
    { // this is also taking O(n^2), time complexty

        int windowSize = NSR[i] - NSL[i] - 1;

        for (int j = 0; j < windowSize; j++)
        { // at 0 index 1 window size max will be filled

            ans[j] = max(ans[j], arr[i]); // make sure to use it correctly
        }
    }

    return ans;
}

//
// Here we can tink of putting the max window size at it's place, if it remains max then we will update towards the left and window size of 5 with min, will come back for max comparision towards left.
//

// we will solve in O(n)
vector<int> maxOfMiniWindowSizeStackOptiOn(int arr[], int size)
{ // it is taking O(n)

    vector<int> ans(size, INT32_MIN);

    vector<int> NSR = nextSmallerRightIndex(arr, size);
    vector<int> NSL = smallestleftIndex(arr, size);

    for (int i = 0; i < size; i++)
    { // this is also taking O(n), time complexty

        int windowSize = NSR[i] - NSL[i] - 1;
        ans[windowSize - 1] = max(ans[windowSize - 1], arr[i]); // make sure to use it correctly
    }

    // for the places or window size which remains emty, we will get max from right side. hence traverse again storing max and updating towards the left

    int maxi = INT32_MIN;

    for (int i = size - 1; i >= 0; i--)
    {
        ans[i] = max(maxi, ans[i]);
        maxi = ans[i];
    }

    return ans;
}

// not using stack for left min and right min

vector<int> maxOfMiniWindowSizeSimple(int arr[], int size)
{

    vector<int> ans(size, INT32_MIN);

    stack<int> s;

    int windowsize = 0;

    for (int i = 0; i < size; i++)
    {

        while (!s.empty() && arr[i] < arr[s.top()])
        {
            // then we need to pop
            int index = s.top();
            s.pop();
            if (!s.empty())
            {
                // for index element
                windowsize = i - s.top() - 1;
                ans[windowsize - 1] = max(ans[windowsize - 1], arr[index]);
            }
            else
            {
                // range will be just i
                windowsize = i;
                ans[windowsize - 1] = max(ans[windowsize - 1], arr[index]);
            }
        }

        s.push(i);
    }

    while (!s.empty())
    {
        int index = s.top();
        s.pop();
        if (!s.empty())
        {
            // for index element
            windowsize = size - s.top() - 1;
            ans[windowsize - 1] = max(ans[windowsize - 1], arr[index]);
        }
        else
        {
            // range will be just i
            windowsize = size;
            ans[windowsize - 1] = max(ans[windowsize - 1], arr[index]);
        }
    }

    for (int i = size - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i + 1], ans[i]); // we can simply compare with adjacent
    }

    return ans;
}

// Implement two stack in an array
// stack with half half partition creates problem of overflow even when stack not full.

// using two pointer for stack one from front for stack 1 and another from back for stack 2.

// code to implement two stack in an array

class twostack
{
    int top1;
    int top2;
    int size;
    int *arr;

public:
    twostack(int n)
    {
        arr = new int[n];
        top1 = -1;
        top2 = n;
        size = n;
    }

    void push1(int val)
    {
        // push in stack 1

        if (top1 + 1 == top2)
        {
            cout << "Stack is full " << endl;
            return; // overflow, stack full
        }
        top1++;
        arr[top1] = val;
        cout << "pushed int stack 1; " << arr[top1] << endl;
    }

    void push2(int val)
    {
        // push in stack 2

        if (top2 - 1 == top1)
        {
            cout << "Stack is full " << endl;
            return; // overflow, stack full
        }
        top2--;
        arr[top2] = val;
        cout << "pushed int stack 2; " << arr[top2] << endl;
    }

    int pop1()
    {
        // pop in stack 1

        if (top1 == -1)
        {
            return -1; // underflow
        }
        top1--;
        return arr[top1 + 1];
    }

    int pop2()
    {
        // pop in stack 2
        //  cout<<"size: "<<sizeof(arr) / sizeof(arr[0])<<endl;
        // if (top2 + 1 == sizeof(arr) / sizeof(arr[0]))
        if (top2 + 1 == size)
        {
            return -1;
        }

        top2++;
        return arr[top2 - 1];
    }
};

// N stack implementation

class Node
{
public:
    int index;
    Node *next;

    Node(int ind)
    {
        index = ind;
        next = NULL;
    }
};

class NStack
{

    int size;
    int *arr;
    // Node **top=new Node*[n];//n is number of stack
    Node **top; // top is present in stack and pointing to a heap location with single * and the address it points is pointing to another address of node type hence double pointer is used.

    stack<int> st;

public:
    NStack(int arrSize, int n)
    {
        arr = new int[arrSize];
        top = new Node *[n]; // it is like node type pointer//stores the address of node
        for (int i = 0; i < n; i++)
        {
            // initialize all to NULL
            top[i] = NULL;
        }

        // push all the possible index in the stack
        for (int i = 0; i < arrSize; i++)
        {

            st.push(i);
        }
    }

    void push(int stackNo, int val)
    {
        // push in stackNo. //stored in top , stackNo-1 as per the indexing

        if (st.empty())
        {
            cout << "Stack is full " << endl;
            return; // overflow, stack full//as no index available for this node
        }

        int index = st.top();
        st.pop();
        //    the index extracted to be stored in Node then in it's top
        Node *temp = new Node(index);
        temp->next = top[stackNo - 1];
        top[stackNo - 1] = temp;

        arr[top[stackNo - 1]->index] = val;
        cout << "pushed int0 stack : " << stackNo << " , value :" << arr[top[stackNo - 1]->index] << endl;
    }

    int pop(int stackNo)
    {
        // pop in stack 1

        if (top[stackNo - 1] == NULL)
        {
            return -1; // underflow
        }

        int element = arr[top[stackNo - 1]->index];
        st.push(top[stackNo - 1]->index);
        Node *temp = top[stackNo - 1];
        top[stackNo - 1] = top[stackNo - 1]->next;
        delete temp;

        return element;
    }
};

//

int main()
{

    int arr[] = {8, 6, 4, 7, 4, 9, 10, 8, 12};
    vector<int> ans;

    ans = nextGreaterRight(arr, sizeof(arr) / sizeof(arr[0])); // 9 7 7 9 9 10 12 12 -1

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // we could have also solved it from backside// we will check if element in stack is max of itself, if not then move left then keep pushing if smaller found from top, if max then smaller is found then check if top can be it's biiger, if not then pop the element from stack as it will be no more nearest greater as this current element is greater than this top valuse and this current is neares thean other. Now current will compare with the left in stack.

    ans = nextGreaterRight2(arr, sizeof(arr) / sizeof(arr[0])); // 9 7 7 9 9 10 12 12 -1

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    int arr4[] = {4, 13, 11, 5, 9, 7, 8, 6};                  //
    ans = smallestleft(arr4, sizeof(arr4) / sizeof(arr4[0])); // -1 4 4 4 5 5 7 5

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " "; // -1 4 4 4 5 5 7 5
    }
    cout << endl;

    ans = smallestleft2(arr4, sizeof(arr4) / sizeof(arr4[0])); // -1 4 4 4 5 5 7 5

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " "; // -1 4 4 4 5 5 7 5
    }
    cout << endl;

    int arr3[] = {7, 9, 12, 10, 14, 8, 3, 6};                    //
    ans = nextGreaterleft(arr3, sizeof(arr3) / sizeof(arr3[0])); // -1 -1 -1 12 -1 14 8 8

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " "; // -1 -1 -1 12 -1 14 8 8
    }
    cout << endl;

    ans = nextGreaterleft2(arr3, sizeof(arr3) / sizeof(arr3[0])); // -1 -1 -1 12 -1 14 8 8

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " "; // -1 -1 -1 12 -1 14 8 8
    }
    cout << endl;

    // next greater with 2 time rotation, thinking that array has dobled it's side and copied itself

    int arr5[] = {6, 10, 7, 4, 8, 9, 4}; // here we have to double it and check.
    ans = nextGreaterRightRevole2(arr5, sizeof(arr5) / sizeof(arr5[0]));

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    int stock[] = {100, 80, 55, 70, 60, 75, 85};              // here we have to double it and check.
    ans = stockSpan(stock, sizeof(stock) / sizeof(stock[0])); // 1 1 1 2 1 4 6

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // largest rectangle in histogram
    // we are given array of height
    // int histoHeight[] = {2, 3, 4, 2, 6, 5, 4, 5, 3};
    int histoHeight[] = {2, 1, 5, 6, 2, 3}; // when after popping all between two equal 2, this 0 index will be counted, equal we have not considered in left min //we can have some test cases for this when after pop, it is not min left but equal

    int area = largestRectArea(histoHeight, sizeof(histoHeight) / sizeof(histoHeight[0])); // 1 1 1 2 1 4 6

    cout << "largest area :" << area << endl;

    area = largestRectArea2(histoHeight, sizeof(histoHeight) / sizeof(histoHeight[0])); // 1 1 1 2 1 4 6
    cout << "largest area :" << area << endl;

    // Maximal rectangle
    vector<string> box = {"10100", "10111", "11111", "10010"}; // a kind of 2D vector
    int rectmax = 0;
    rectmax = maxRect(box);
    cout << "Max rectangle area possible : " << rectmax << endl;

    // celebrity(vector<string> arr)
    vector<string> meet = {"0110", "1010", "0000", "1110"}; // a kind of 2D vector
    // vector<string> meet = {"001", "001", "110"}; // a kind of 2D vector
    // vector<string> meet = {"0"}; // a kind of 2D vector
    int celebrityNumber = 0;
    celebrityNumber = celebrity(meet);
    cout << "Celebraity is : " << celebrityNumber << endl;

    celebrityNumber = celebrityOpti(meet);
    cout << "Celebraity is : " << celebrityNumber << endl;

    celebrityNumber = celebrityOpti2(meet);
    cout << "Celebraity is : " << celebrityNumber << endl;

    stackO1 s1;
    s1._push(12);
    s1._push(11);
    s1._push(14);
    cout << s1._pop() << endl; // 11//we returned the min element at this top

    stackO2 s2;
    s2._push(12);
    s2._push(11);
    s2._push(14);
    cout << s2._pop() << endl;   // here we returned the element being popped
    cout << s2.getmin() << endl; // return min now at the top

    //  maximum of minimum fro every window size

    int arrForMaxMin[] = {10, 20, 15, 50, 10, 70, 30};
    ans = maxOfMiniWindowSize(arrForMaxMin, sizeof(arrForMaxMin) / sizeof(arrForMaxMin[0])); // 1 1 1 2 1 4 6

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // O(n^2) time complexity
    ans = maxOfMiniWindowSizeOn2(arrForMaxMin, sizeof(arrForMaxMin) / sizeof(arrForMaxMin[0])); // 1 1 1 2 1 4 6

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // O(n^2) time complexity

    cout << endl;

    vector<int> NSR = nextSmallerRightIndex(arrForMaxMin, sizeof(arrForMaxMin) / sizeof(arrForMaxMin[0]));
    for (int i = 0; i < NSR.size(); i++)
    {
        cout << NSR[i] << " ";
    }
    cout << endl;

    vector<int> NSL = smallestleftIndex(arrForMaxMin, sizeof(arrForMaxMin) / sizeof(arrForMaxMin[0]));
    for (int i = 0; i < NSR.size(); i++)
    {
        cout << NSL[i] << " ";
    }
    cout << endl;

    ans = maxOfMiniWindowSizeStack(arrForMaxMin, sizeof(arrForMaxMin) / sizeof(arrForMaxMin[0])); // 1 1 1 2 1 4 6

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    ans = maxOfMiniWindowSizeStackOptiOn(arrForMaxMin, sizeof(arrForMaxMin) / sizeof(arrForMaxMin[0])); // 1 1 1 2 1 4 6

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // let's solve combining without creating extra stack for storing left min and right min index

    ans = maxOfMiniWindowSizeSimple(arrForMaxMin, sizeof(arrForMaxMin) / sizeof(arrForMaxMin[0])); // 1 1 1 2 1 4 6

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // two stack in an array
    twostack twoStack(6);
    twoStack.push1(4);
    twoStack.push1(4);
    twoStack.push1(4);

    twoStack.push2(4);
    twoStack.push2(4);

    twoStack.push1(4);
    twoStack.push1(4);
    twoStack.push2(4);

    cout << twoStack.pop1() << endl;
    cout << twoStack.pop2() << endl;
    cout << twoStack.pop2() << endl;
    cout << twoStack.pop2() << endl;
    cout << twoStack.pop2() << endl;

    // NStack in an array
    // for this we will use three thing, one is the array itself. second is the stack which contains all the index possible from the given array, when push happens then one index is popped and element is pushed in it, then that index is set as top for that stack number.third we need is a top pointer holding the address of top of all stack. hence this store the address of stack which further contain the address of node, hence pointer will will two time node type.

    // n stack

    NStack nStackObj(5, 3);
    nStackObj.push(2, 12);
    nStackObj.push(1, 12);
    nStackObj.push(1, 12);
    nStackObj.push(2, 12);
    nStackObj.push(3, 12);
    nStackObj.push(3, 12);

    cout << nStackObj.pop(2) << endl;
    cout << nStackObj.pop(2) << endl;
    cout << nStackObj.pop(2) << endl;
}
