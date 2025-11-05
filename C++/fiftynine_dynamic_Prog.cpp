#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <stack>
#include <algorithm>

// fabonaci series n th value
// Climbing Stairs
// Number of Hops
// min cost Climbing Stair
// House Robbery
// House Robber 2

// fabonaci series n th value

// find fabonaci at n place using recursion
int fabonaciRecur(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return fabonaciRecur(n - 1) + fabonaciRecur(n - 2);

    // first we write the base equation that f(n)=f(n-1)+f(n-2)//but this assignment is used in case of dynamic programming storation
}

// top down approach
int fabonaciTopDown(int n, vector<int> &dptopdown)
{
    if (n == 0 || n == 1)
    {
        dptopdown[n] = n;
        return n;
    }

    if (dptopdown[n] == -1)
    {
        return dptopdown[n] = fabonaciRecur(n - 1) + fabonaciRecur(n - 2);
    }
    else
    {
        return dptopdown[n];
    }
}

// bottom up approch
int fabonaciBottomUp(int n)
{
    // here we will start with the base data
    vector<int> dpfact(n + 1, -1);
    dpfact[0] = 0;
    dpfact[1] = 1;

    if (n <= 1)
    {
        return n;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            dpfact[i] = dpfact[i - 1] + dpfact[i - 2];
        }

        return dpfact[n];
    }
}

// space optimization for this approach
int fabonaciSpaceOpti(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int first = 0, second = 1, third;
    for (int i = 2; i <= n; i++)
    {
        third = first + second;
        first = second;
        second = third;
    }

    return third;
}

// Climbing Stairs
// recursive
int StairWaysRecur(int curr, int n)
{

    // currently at stair 0 and we need to reach n
    if (curr == n)
    {
        return 1;
    }
    else if (curr > n)
    {
        return 0;
    }

    return StairWaysRecur(curr + 1, n) + StairWaysRecur(curr + 2, n);
}

// top down approach
int StairWaysTopDown(int curr, int n, vector<int> &dpWays)
{
    // currently at stair 0 and we need to reach n

    if (curr == n)
    {
        return 1;
    }
    else if (curr > n)
    {
        return 0;
    }

    if (dpWays[curr] == -1)
    {

        return dpWays[curr] = StairWaysTopDown(curr + 1, n, dpWays) + StairWaysTopDown(curr + 2, n, dpWays);
    }
    else
    {
        return dpWays[curr];
    }
}

// bottom up approach
int StairWaysBottomUp(int n)
{
    // currently at stair 0 and we need to reach n

    vector<int> dpWays(n + 2, -1);

    // in the tree we make 0 as root then left and right as one step and 2 steps respectively.

    // at bottom we have n and n+1 node label, like for step 5, n=5 and n+1=6

    // base case is simpy filled
    dpWays[n] = 1;
    dpWays[n + 1] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        dpWays[i] = dpWays[i + 1] + dpWays[i + 2];
    }

    return dpWays[0];
}

// space optimized approach
int StairWaysSpaceOpti(int n)
{
    // currently at stair 0 and we need to reach n
    // as base case starts from n, n+1 start that with tree visualization

    int topstairUpper = 0;
    int topstairSecond = 1;
    int currStair;

    for (int i = n - 1; i >= 0; i--)
    {
        currStair = topstairUpper + topstairSecond;
        topstairUpper = topstairSecond;
        topstairSecond = currStair;
    }

    return currStair;
}

// approch two for stair problem by using from top to come below starts //it is just like coming down stairs

// recursive approch
int StairWaysRecur2(int curr)
{

    // currently at stair n and we need to calculating how we came here either from step 4 or fromstep 3
    if (curr == 0)
    {
        return 1; // 0th step think like as destination.
    }
    else if (curr < 1)
    {
        return 0;
    }

    return StairWaysRecur2(curr - 1) + StairWaysRecur2(curr - 2);
}

// top down approach
int StairWaysTopDown2(int curr, vector<int> &dpWays)
{
    // currently at stair n and we need to reach 0

    if (curr <= 1)
    {
        return 1;
    }

    if (dpWays[curr] == -1)
    {

        return dpWays[curr] = StairWaysTopDown2(curr - 1, dpWays) + StairWaysTopDown2(curr - 2, dpWays);
    }
    else
    {
        return dpWays[curr];
    }
}

// bottom up approach
int StairWaysBottomUp2(int n)
{
    // currently at stair 0 and we need to reach n

    vector<int> dpWays(n + 1, -1);

    // in the tree we make 0 as root then left and right as one step and 2 steps respectively.

    // at bottom we have n and n+1 node label, like for step 5, n=5 and n+1=6

    // base case is simpy filled
    dpWays[0] = 1;
    dpWays[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dpWays[i] = dpWays[i - 1] + dpWays[i - 2];
    }

    return dpWays[n];
}

// space optimized approach
int StairWaysSpaceOpti2(int n)
{
    // currently at stair 5 and we need to reach 0
    // as base case starts from 0, -1 or simply 1 start that with tree visualization

    int currStair;
    int bottomstairUpper = 1;  // for step 1
    int bottomstairSecond = 1; // for step 0

    for (int i = 2; i <= n; i++)
    {

        currStair = bottomstairUpper + bottomstairSecond;
        bottomstairSecond = bottomstairUpper;
        bottomstairUpper = currStair;
    }

    return currStair;
}

// Number of Hops

// recursive approch
int HopsNumRecursive(int curr)
{

    // currently at stair n and we need to calculating how we came here either from step 4 or fromstep 3 or step 2
    if (curr == 0)
    {
        return 1; // 0th step think like as destination.
    }
    else if (curr < 1)
    {
        return 0;
    }

    return HopsNumRecursive(curr - 1) + HopsNumRecursive(curr - 2) + HopsNumRecursive(curr - 3);
}

// top down approach
int HopsNumTopDown(int curr, vector<int> &dpWays)
{
    // currently at stair n and we need to reach 0

    if (curr <= 1)
    {
        return 1;
    }
    if (curr == 2)
    {
        return 2;
    }

    if (dpWays[curr] == -1)
    {
        return dpWays[curr] = HopsNumTopDown(curr - 1, dpWays) + HopsNumTopDown(curr - 2, dpWays) + HopsNumTopDown(curr - 3, dpWays);
    }
    else
    {
        return dpWays[curr];
    }
}

// bottom up approach
int HopsNumBottomUp(int n)
{
    // currently at stair n and we need to reach 0

    vector<int> dpWays(n + 1, -1);

    // in the tree we make 0 as root then left and right as one step and 2 steps and third , 3 steps

    // base case is simply filled
    dpWays[0] = 1;
    dpWays[1] = 1;
    dpWays[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dpWays[i] = dpWays[i - 1] + dpWays[i - 2] + dpWays[i - 3];
    }

    return dpWays[n];
}

// space optimized approach
int HopsNumSpaceOpti(int n)
{
    // currently at stair 5 and we need to reach 0
    // as base case starts from 0, -1 or simply 1 start that with tree visualization

    int currStair;
    int bottomstairUpper = 2;  // for step 2
    int bottomstairSecond = 1; // for step 1
    int bottomstairThird = 1;  // for step 0

    for (int i = 3; i <= n; i++)
    {

        currStair = bottomstairUpper + bottomstairSecond + bottomstairThird;
        bottomstairThird = bottomstairSecond;
        bottomstairSecond = bottomstairUpper;
        bottomstairUpper = currStair;
    }

    return currStair;
}

// min cost Climbing Stair

// here indexing is an issue
// Array Bounds: For costOfStairs[] = {10, 15, 20} (size 3), valid indices are 0,1,2

// here step 1 cost is at 0 and step 2 qt index 1 and so on. actually step 3rd cost at 2nd index, hence when index n-1 used, it accesses the index it is given. if we have to reach step 4 then we need to cross upt step 3 and each stpe cost is one index back.

// Step Numbering:
// Step 1 cost = costOfStairs[0] = 10
// Step 2 cost = costOfStairs[1] = 15
// Step 3 cost = costOfStairs[2] = 20

// We want to reach step 4: This means we need to calculate cost to go beyond step 3
// The logic: We pay the cost of the step we're LEAVING, not the step we're landing on

// recursive approch
int MinCostClimbingRecur(int curr, int costOfStairs[])
{

    // when 3 steps given as size then these indexing will not create proble as step 3rd which we have to croos to reach 4 step is at index 2, hence,we will not mention 4 here, simply consider 3 size array.

    // when curr 3 passed then cost of this stpe is at index 2 given and then we will check the way to reach at step 3. forget adding one mre index at start for matching

    // in simple we are tracking, jaha par ho means current, waha ek step pichhe ka cost pay kiya hoga and 2 step pichhe ka cost pay kiya hoga. we have paid that cost and simply in way call , we have to return by how much paying we came to that step. this is the way of recursive call.

    // here at the destination stair , we don't cross it hence we don't add its cost.

    // currently at stair n and we need to calculating how we came here either from step 4 or from step 3

    // if we have not added 0 index explicitly.
    //  step 1 cost is at index 0 in cost array. but actually cost is already added in call time, we have to return the way to simply reach there.

    // here 1 shows that curr 1 par kaha se pahuchec, abhi 1 ko cross nahi kiya h.. simply answer will be 0 as only oth step is croosed hence , we have not paid yet.

    if (curr <= 1)
    {

        // here this will not create any problem because 0th step has no cost. neither we have to pay for destination stair as we have not crossed it but only reached there.

        return 0; // 0th step think like as destination.//here cost will be 0 as at step 0, we have no step 0 cost. //here return 0 shows cost 0.

        // here =1 used because we are currently at step 1 but not crossed yet, hence it's cost is also not added.
    }

    // here no -2 index in cost hence that would create proble, hence we used insertion of 0 at 0th index.

    // here cost will create problem as step 1 cost is in 0th index
    // return min(costOfStairs[curr - 1 - 1] + MinCostClimbingRecur(curr - 1, costOfStairs), costOfStairs[curr - 2 - 1] + MinCostClimbingRecur(curr - 2, costOfStairs));

    // when 0 is inseted at start for 0th index in cost array
    return min(costOfStairs[curr - 1] + MinCostClimbingRecur(curr - 1, costOfStairs), costOfStairs[curr - 2] + MinCostClimbingRecur(curr - 2, costOfStairs));
}

//
// top down approach
int MinCostClimbingTopDown(int curr, vector<int> &dpWays, int costOfStairs[])
{
    // currently at stair n and we need to reach 0

    if (curr <= 1)
    {
        return 0;

        // here 1 shows that curr 1 par kaha se pahuchec, abhi 1 ko cross nahi kiya h.. simply answer will be 0 as only oth step is croosed hence , we have not paid yet.
    }

    // if(curr ==1){
    //     return costOfStairs[1];
    // }

    if (dpWays[curr] == -1)
    {
        // some time deciding the base case creates problem.
        // here when step is 2 means now we have either came from 1 or 0 hence when at step 1 , we have crossed it to reach to step 2, hence write cost of 1 then get ways to reach this 1 which is returned as 0 becuase only 0th step crossed. after backtracking 1 other option is cost of 0 and way to reach 0

        return dpWays[curr] = min(costOfStairs[curr - 1] + MinCostClimbingTopDown(curr - 1, dpWays, costOfStairs), costOfStairs[curr - 2] + MinCostClimbingTopDown(curr - 2, dpWays, costOfStairs));
    }
    else
    {
        return dpWays[curr];
    }
}

// bottom up approach
int MinCostClimbingBottomUp(int n, int costOfStairs[])
{
    // currently at stair n and we need to reach 0

    vector<int> dpWays(n + 1, -1);

    // in the tree we make 0 as root then left and right as one step and 2 steps and third , 3 steps

    // base case is simply filled
    dpWays[0] = 0;

    dpWays[1] = 0; // 1 step tak aane ka cost, abhi 1 stpe ko cross nahi kiya h.

    for (int i = 2; i <= n; i++)
    {
        dpWays[i] = min(costOfStairs[i - 1] + dpWays[i - 1], costOfStairs[i - 2] + dpWays[i - 2]);
    }

    return dpWays[n];
}

// space optimized approach
int MinCostClimbingSpaceOpti(int n, int costOfStairs[])
{
    // currently at stair 5 and we need to reach 0
    // as base case starts from 0, -1 or simply 1 start that with tree visualization

    int currStair;
    int bottomstairUpper = 0;  // for step 1
    int bottomstairSecond = 0; // for step 0

    for (int i = 2; i <= n; i++)
    {

        currStair = min(bottomstairUpper + costOfStairs[i - 1], bottomstairSecond + costOfStairs[i - 2]);
        bottomstairSecond = bottomstairUpper;
        bottomstairUpper = currStair;
    }

    return currStair;
}

// House Robbery

// we are using from final like as if 4 houses then we have made table like 5 as root, and it's left when reached after robbing 4 or reached after robbing 3 hence respective cost max is added.

// it is just like min cost star, we backtracked like we crossed this stair , now tell how we came here.

// recursive approch
int MaxCostRobbedRecur(int curr, int costOfHouses[])
{
    // suppose we have 4 houses, and we need to increse by 2 to analyse properly that is one way but, we are neglecting tht way and instead we are using size indexing

    // Your recursive logic is actually correct for the house robber problem! It properly handles all cases where houses cannot be adjacent. The examples I thought were failures were actually me misunderstanding the problem constraints.

    // curr represents the number of houses we're considering

    if (curr <= 0)
    { // 2nd house par directly 0 se aaye honge.
        // 1 house par directly aaye honge kyunki usse pahle koi h hi nahi
        return 0;
    }
    if (curr == 1)
    {
        return costOfHouses[0];
    }

    return max(costOfHouses[curr - 1] + MaxCostRobbedRecur(curr - 2, costOfHouses), costOfHouses[curr - 2] + MaxCostRobbedRecur(curr - 3, costOfHouses));

    // but above we used the logic that rob this house and check for two step back house or rob previous step house means this current house is not robbed and then we checked 2 house back from the previous house of the current
}

// recursive approch standard
int MaxCostRobbedRecurStandard(int index, int costOfHouses[])
{ // let's take index vaue for simplicity

    // if (index < 0)
    // {
    //     return 0;
    // }

    if (index == 0)
    {
        return costOfHouses[0];
    }

    // to fix -1 indexing proble, better to return max from index 1 als becuase further recursion will call -1 becuase it skipped the previous of 1 which is 0 and n=move to -1. we can thereafter remove < 0 base case

    if (index == 1)
    {
        return max(costOfHouses[0], costOfHouses[1]);
    }

    // Two choices at current position:
    // 1. Rob current house (cindex) and skip previous house (index -1)
    // 2. Skip current house and take maximum from previous house (index-1)
    return max(costOfHouses[index] + MaxCostRobbedRecurStandard(index - 2, costOfHouses), MaxCostRobbedRecurStandard(index - 1, costOfHouses));
}

// Top down Approach
int MaxCostRobbedTopDown(int index, int costOfHouses[], vector<int> &dpWays)
{ // let's take index vaue for simplicity
    // indexing start from 6 and total 7 houses hence dp size is 7, indexing from 0 to 6

    if (index == 0)
    {
        return costOfHouses[0];
    }

    if (index == 1)
    {
        return max(costOfHouses[0], costOfHouses[1]);
    }

    if (dpWays[index] != -1)
    {
        return dpWays[index];
    }

    return dpWays[index] = max(costOfHouses[index] + MaxCostRobbedTopDown(index - 2, costOfHouses, dpWays), MaxCostRobbedTopDown(index - 1, costOfHouses, dpWays));
}

// bottom up Approach
int MaxCostRobbedBottomUp(int index, int costOfHouses[])
{
    vector<int> dpWays(index + 1, -1);

    // indexing start from 6 and total 7 houses hence dp size is 7, indexing from 0 to 6

    dpWays[0] = costOfHouses[0];
    dpWays[1] = max(costOfHouses[0], costOfHouses[1]);

    // here index is becoming the house count and house are 7 if index is 6

    // i is possible index value to be filled
    for (int i = 2; i <= index; i++)
    {
        dpWays[i] = max(costOfHouses[i] + dpWays[i - 2], dpWays[i - 1]); // costOfHouses[i], current index house cost added to last possible max before 2 steps.
    }

    return dpWays[index];
}

// Space optimized Approach
int MaxCostRobbedSpaceOpti(int houses, int costOfHouses[])
{

    int prevToprev = costOfHouses[0];
    int prev = max(costOfHouses[0], costOfHouses[1]);

    // here houses is becoming the house count and house are 7 if houses is 6

    int curr;

    // i is possible houses value to be filled, here i is the indexing from 0
    for (int i = 2; i < houses; i++)
    {
        // for each houses, i  indexing houses not counting

        curr = max(costOfHouses[i] + prevToprev, prev);
        prevToprev = prev;
        prev = curr;
    }

    return curr;
}

// House Robber 2
// in case of circular house

// Remember the way of seperating the indexes from 0 to n-2 index and from 1 to n-1 index in seperate array

// recursive approch standard
int CircularHouseRobberyRecursive(int index, vector<int> &costOfHouses)
{

    if (index == 0)
    {
        return costOfHouses[0];
    }

    if (index == 1)
    {
        return max(costOfHouses[0], costOfHouses[1]);
    }

    return max(costOfHouses[index] + CircularHouseRobberyRecursive(index - 2, costOfHouses), CircularHouseRobberyRecursive(index - 1, costOfHouses));
}

int robbery(vector<int> &costOfHouses)
{

    int n = costOfHouses.size();

    // base cases
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return costOfHouses[0];
    }
    if (n == 2)
    {
        return max(costOfHouses[0], costOfHouses[1]);
    }

    // make seperate array
    vector<int> arr1(n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        arr1[i] = costOfHouses[i];
    }

    // or

    // Case 1: Include first house, exclude last house
    // vector<int> arr1(costOfHouses.begin(), costOfHouses.end() - 1);

    vector<int> arr2(n - 1);

    for (int i = 1; i < n; i++)
    { // upto last index
        arr2[i-1] = costOfHouses[i];
    }

    // or
    //  Case 2: Exclude first house, include last house
    // vector<int> arr2(costOfHouses.begin() + 1, costOfHouses.end());

    // we are passing index value , as size -1
    int curr1 = CircularHouseRobberyRecursive(n - 1 - 1, arr1);
    int curr2 = CircularHouseRobberyRecursive(n - 1 - 1, arr2);

    return max(curr1, curr2);
}

//space optimization
int robberySpaceOpti(vector<int> &costOfHouses)
{

    int n = costOfHouses.size();

    // base cases
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return costOfHouses[0];
    }
    if (n == 2)
    {
        return max(costOfHouses[0], costOfHouses[1]);
    }

    // make seperate array
    vector<int> arr1(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        arr1[i] = costOfHouses[i];
    }

    vector<int> arr2(n - 1);
    for (int i = 1; i < n; i++)
    {
        arr2[i-1] = costOfHouses[i];
    }

    // solving arr1
    int prevToprev = arr1[0];
    int prev = max(arr1[0], arr1[1]);

    int curr1;

    // i is possible houses value to be filled, here i is the indexing from 0
    for (int i = 2; i < arr1.size(); i++)
    {
        // for each houses, i  indexing houses not counting

        curr1 = max(arr1[i] + prevToprev, prev);
        prevToprev = prev;
        prev = curr1;
    }

    // solving arr2
    prevToprev = arr2[0];
    prev = max(arr2[0], arr2[1]);

    int curr2;

    for (int i = 2; i < arr2.size(); i++)
    {
        // for each houses, i  indexing houses not counting

        curr2 = max(arr2[i] + prevToprev, prev);
        prevToprev = prev;
        prev = curr2;
    }

    return max(curr1, curr2);
}

int main()
{

    // fabonaci series n th value

    // recursion
    cout << "fabonaciRecur(6) : " << fabonaciRecur(6) << endl; // fabonaciRecur(6) : 8

    // top down approach
    vector<int> dptopdown(6 + 1, -1); // size is n+1 because 0, 1 and so on goes hence n is present at n index means n+1 total size as 0 index is also the
    cout << "fabonaciTopDown(6) : " << fabonaciTopDown(6, dptopdown) << endl;

    // bottom up approach
    cout << "fabonaciBottomUp(6) : " << fabonaciBottomUp(6) << endl;

    // space optimization for this approach
    cout << "fabonaciSpaceOpti(6) : " << fabonaciSpaceOpti(6) << endl;

    // Climbing Stairs

    // recursion
    cout << "StairWaysRecur(0,5) : " << StairWaysRecur(0, 5) << endl; // current start is 0

    // top down approach
    vector<int> dpWays(5 + 2, -1); // one extra is taken because it may take one extra becuase of i+2, like if 5 needed, but it can go to 6
    cout << "StairWaysTopDown : " << StairWaysTopDown(0, 5, dpWays) << endl;

    // bottom up approach
    cout << "StairWaysBottomUp : " << StairWaysBottomUp(5) << endl; // StairWaysBottomUp : 8

    // space optimized approach
    cout << "StairWaysSpaceOpti : " << StairWaysSpaceOpti(5) << endl; // StairWaysSpaceOpti : 8

    // Solving climbing stair using method 2
    cout << "StairWaysRecur2 : " << StairWaysRecur2(5) << endl; // currently we are at 5.

    // top down approach
    vector<int> dpWays2(5 + 1, -1); // no one extra is taken because we stoped at 1 returning 1.
    cout << "StairWaysTopDown2 : " << StairWaysTopDown2(5, dpWays2) << endl;

    // bottom up approach
    cout << "StairWaysBottomUp2 : " << StairWaysBottomUp2(5) << endl;

    // space optimized approach
    cout << "StairWaysSpaceOpti2 : " << StairWaysSpaceOpti2(5) << endl;

    // Number of Hops
    cout << "HopsNum : " << HopsNumRecursive(4) << endl; // currently we are at 4. // HopsNum : 7

    // top down approach
    vector<int> dpWaysForHop(4 + 1, -1);
    cout << "HopsNumTopDown : " << HopsNumTopDown(4, dpWaysForHop) << endl;

    // bottom up approach
    cout << "HopsNumBottomUp : " << HopsNumBottomUp(4) << endl;

    // space optimized approach
    cout << "HopsNumSpaceOpti : " << HopsNumSpaceOpti(4) << endl;

    //
    // min cost Climbing Stair
    //

    int costOfStairs[] = {10, 15, 20};
    // we can take one or two steps at a time.

    // here index 0 will create problem, hence we will insert one more value at start.

    // int costOfStairs[] = {0, 10, 15, 20};

    // cout << "MinCostClimbingRecur : " << MinCostClimbingRecur(4, costOfStairs) << endl;

    cout << "MinCostClimbingRecur : " << MinCostClimbingRecur(3, costOfStairs) << endl;

    // top down approach
    // vector<int> dpWaysForMinCostStairClimbing(4 + 1, -1);
    vector<int> dpWaysForMinCostStairClimbing(3 + 1, -1);

    // cout << "MinCostClimbingTopDown : " << MinCostClimbingTopDown(4, dpWaysForMinCostStairClimbing, costOfStairs) << endl;
    cout << "MinCostClimbingTopDown : " << MinCostClimbingTopDown(3, dpWaysForMinCostStairClimbing, costOfStairs) << endl;

    // bottom up approach
    // cout << "MinCostClimbingBottomUp : " << MinCostClimbingBottomUp(4, costOfStairs) << endl;
    cout << "MinCostClimbingBottomUp : " << MinCostClimbingBottomUp(3, costOfStairs) << endl;

    // space optimized approach
    // cout << "MinCostClimbingSpaceOpti : " << MinCostClimbingSpaceOpti(4, costOfStairs) << endl;
    cout << "MinCostClimbingSpaceOpti : " << MinCostClimbingSpaceOpti(3, costOfStairs) << endl;

    // House Robbery

    // for 4 houses , we will use to pass 4+2 = 6, so that numbering not creates problem.

    // int costOfHouses[] = {0, 1, 2, 3, 1};
    // int costOfHouses[] = {1, 2, 3, 1};
    // cout << "MaxCostRobbedRecur : " << MaxCostRobbedRecur(4, costOfHouses) << endl;

    int costOfHouses[] = {7, 3, 2, 8, 2, 1, 10};

    cout << "MaxCostRobbedRecur : " << MaxCostRobbedRecur(7, costOfHouses) << endl;

    // index value is passed for simplycity
    cout << "MaxCostRobbedRecurStandard : " << MaxCostRobbedRecurStandard(6, costOfHouses) << endl;

    // top down approch
    vector<int> dpWaysForMaxHouseRobbed(7, -1); // we are using 0 indexing hence size not need to increase by 1//7 houses present
    cout << " MaxCostRobbedTopDown : " << MaxCostRobbedTopDown(6, costOfHouses, dpWaysForMaxHouseRobbed) << endl;

    // bottom up approach
    cout << " MaxCostRobbedBottomUp : " << MaxCostRobbedBottomUp(6, costOfHouses) << endl;

    // Space optimized
    cout << " MaxCostRobbedSpaceOpti : " << MaxCostRobbedSpaceOpti(7, costOfHouses) << endl; // 7 is total number of house not the last index

    // House Robber 2
    // in case of circular house
    vector<int> costOfHousesCircular = {7, 3, 2, 8, 2, 1, 10};
    cout << "robbery : " << robbery(costOfHousesCircular) << endl;

    // Space optimized
    cout << "robberySpaceOpti : " << robberySpaceOpti(costOfHousesCircular) << endl;

    
}