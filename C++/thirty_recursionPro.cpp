#include <iostream>

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Tower Of Hanoi

// Predict the winner

// Josephus Problem || Predict the winner//Recursion me pattern nahi banta toh khud se banana aana chahiye

// Rat in a Maze//recursion on 2D array//Find all direction path

// N bit binary Number //find all n bits binary number where number of 1 is more tha 0 in any prefix.

void towerOfHanoi(int source, int helper, int destination, int disk)
{

    // this logic work.
    // Move n-1 disks to auxiliary.
    // Move the largest disk to destination.
    // Move n-1 disks to destination.

    //
    // This logic not work
    // return case when destination has all count
    // if(destination.size()==size){
    //     return;
    // }

    // if(source.back()>helper.back()){//souce has ligher top then helper hence , push and pop

    //     helper.push_back(source.back());
    //     source.pop_back();

    //     // three cases of backtracking
    //     towerOfHanoi(helper,source,destination,size);
    //     towerOfHanoi(helper,destination,source,size);
    //     towerOfHanoi(destination,source,helper,size);
    // }

    if (disk == 1)
    {
        cout << "Move from " << source << " to " << destination << " Disk " << disk << endl;
        return;
    }

    towerOfHanoi(source, destination, helper, disk - 1); // move n-1 from source to helper using destination as auxiliary
    // When come back then move it to destination
    cout << "Move from " << source << " to " << destination << " Disk " << disk << endl;

    towerOfHanoi(helper, source, destination, disk - 1); // move from helper to destination

    return;
}

// Simple approch
int towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return 0;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);                              // Step 1 // Move n-1 disks to auxiliary.
    cout << "Move disk " << n << " from " << source << " to " << destination << endl; // Step 2//Move the largest disk to destination.
    towerOfHanoi(n - 1, auxiliary, source, destination);                              // Step 3 //Move n-1 disks to destination.

    // we can return answer using the formula. 2^n -1
    int ans = pow(2, n) - 1;
    return ans;
}

// The pattern follows:

// Move n-1 disks to auxiliary.
// Move the largest disk to destination.
// Move n-1 disks to destination.

// Predict the winner
// int predictWinner(vector<bool> &record, int index, int size, int left,int k)
int predictWinner(vector<bool> record, int size, int k)
{
    int index = 0; // Start from the first person
    int left = size;

    while (left > 1)
    {
        // we have to remove every 3rd element.
        int count = 0;
        // k = k % size; // for avoiding repeated check.but writing here makes it fail if 1 is present and it has included it also.

        while (count < k)
        {
            // index = index % size; //it will works at its

            if (record[index] == 0)
            { // after updating, we get the index of last updated, hence this will not work in that case,
                count++;
            }

            if (count < k)
            { // this will increment the index
                // combined:
                index = (index + 1) % size;
                // we have seperated this index so that when updating we can update at this place.
            }
        }

        // when count=3 and index has move once more.
        record[index] = 1; // index is not updated, instead it just fails in if condition that it is 0, then increment.
        left--;
    }

    // now check which one left.
    for (int i = 0; i < size; i++)
    {
        if (record[i] == 0)
        {
            return i + 1; // he is winner.
        }
    }
}

// Solving Optimized
int predictWinnerOptimized(vector<bool> record, int size, int k)
{
    int index = 0; // Start from the first person
    int left = size;

    while (left > 1)
    {
        // we have to remove every 3rd element.
        // int count = 0;//needed when using k times checking.
        // k = k % size; // for avoiding repeated check.but writing here makes it fail if 1 is present and it has included it also.

        // Compute steps to move: (k-1) % remaining friends
        int count = (k - 1) % left; // here if k=10, left=6, instead of moving 10 steps check forward then clockwise circular, then again count may comes.//instead we can circulize the count we need for 0 as per left part iterate only so that , we save the count step

        // 0 0 1 0 0 0//if k=10//left=5,then we need to count 10 steps among 5 0's , instead... k-1%left easily updates, 10-1 % 5=4 hence even we search for count 4, it manage to rach to the same index.

        // while (count < k) //for optimising k, we set the count accordingle
        while (count > 0)
        {
            // index = index % size; //it will works at its

            if (record[index] == 0)
            { // after updating, we get the index of last updated, hence this will not work in that case,
                // count++;
                count--;
            }

            // if (count < k)//as we have set 0 limit hence not needed{ //this will increment the index
            // combined:
            index = (index + 1) % size;
            // we have seperated this index so that when updating we can update at this place.
            // }
        }

        // when count=3 and index has move once more.
        record[index] = 1; // index is not updated, instead it just fails in if condition that it is 0, then increment.
        left--;

        // Move to the next alive friend
        do
        {
            index = (index + 1) % size;
        } while (record[index] == 1);
    }

    // now check which one left.
    for (int i = 0; i < size; i++)
    {
        if (record[i] == 0)
        {
            return i + 1; // he is winner.
        }
    }

    return -1; //
}

int predictWinnerOpt(vector<bool> record, int size, int k)
{
    int index = 0; // Start from the first person
    int left = size;

    while (left > 1)
    {
        // Compute steps to move: (k-1) % remaining friends
        int steps = (k - 1) % left;

        // Move 'steps' alive friends forward
        while (steps > 0)
        {
            index = (index + 1) % size;
            if (record[index] == 0)
            {
                steps--;
            }
        }

        record[index] = 1; // Eliminate the selected friend
        left--;

        // Move to the next alive friend
        do
        {
            index = (index + 1) % size; // after updatig , it will always move one step forward even when record[index] != 1//hence it proves that one confirst where value 0 , next time index++ for next index then check it's 0, when step get 0 that time index is present always at the index where 0 is present after first on round. //it is not in case of very first time when index taken is 0 and it is considered as when taking 0 then it must be non eliminated. hence it starts checking from index==1, then checks index2... at 2 if verified and count==0, then it update the value at that index.

        } while (record[index] == 1);
    }

    // Find the last remaining friend (1-based index)
    for (int i = 0; i < size; i++)
    {
        if (record[i] == 0)
        {
            return i + 1;
        }
    }
    return -1; // Fallback (unreachable if input is valid)
}

// using recursion
int predictWinnerRec(vector<bool> &record, int index, int size, int left, int k)
{
    // /index it gives is considered ad first 0, that can be considered hence in loop directly move to next index
    if (left == 1)
    {

        for (int i = 0; i < size; i++)
        {
            if (record[i] == 0)
            {
                return i + 1;
            }
        }
    }

    int count = (k - 1) % left; // k-1 because index is from 0 and it will reach to that required index when count == 0
    // while (count--)
    while (count > 0)
    {
        index = (index + 1) % size; // first increment then check at next position
        if (record[index] == 0)
        {
            count--;
        }

        // even if we want we could have found next alive here also.which decrease in finding the next 0.//adding this increase more efficiency.
        while (record[index] == 1)
        {
            index = (index + 1) % size;
        }
    }

    //  // even if we want we could have found next alive here also.
    //  while (count--)
    // {
    //     index = (index + 1 )% size;
    //     while (record[index]==1)
    //     {
    //          index = (index + 1 )% size;
    //     }
    // }

    // after this we needed to just update the index value to 1.

    record[index] = 1;
    left--;

    // make the index pointing to next alive
    do
    {
        index = (index + 1) % size;
    } while (record[index] == 1);

    return predictWinnerRec(record, index, size, left, k); // don't forget to write return in int return type function with recursion

    // when

    // when count is 0, check
}

// imagine karo ki remove karne ke liye forward move kiye a rahe the, fir jab hum forward me gaye toh usse 0 maa liya , toh pahle wala index usse k step add karne par hi milega, aur modulus lena padega.//esse hame pahle jis number ne suru kiya hoaga vo  value milega.

// pichhe jane par us wakt jaha se start hua hoga, vo index milega.

// find the winner in O(n) and without any array.
int winnerJosephOpti(int n, int k)
{
    // stop when n==1, only one left
    if (n == 1)
    {
        return 0;
    }

    // int steps=(k-1)%n;
    return (winnerJosephOpti(n - 1, k) + k) % n; // index will be return , to return + value then handle in output part
}

// Base Case (n = 1):

// When only 1 person remains, they are the winner (index 0 in 0-based numbering).

// Recursive Case (n > 1):

// The winner for n people is derived from the winner of n-1 people.

// After eliminating the k-th person in a circle of n people, the problem reduces to n-1 people.

// The + k adjusts for the k steps taken to eliminate a person.

// The % n ensures the result wraps around the circle.

// J(n,k)=(J(n−1,k)+k)%n
// ime Complexity: O(n) (optimal for recursive solution).
// Space Complexity: O(n) (recursion stack).

//
//
//
//
//
// Rat in a maze
//
// find total possible ways.

// my logic is correct,
int ratWays(int arr[][4], bool visited[][4], int i, int j, int n)
{ // don't pass ans in parameter as it makes it's own copy and changes are not reflected in main.. as we thought of a recursive call takes it's own start ans 0 then append in other branch, that works in all such cases.//could have used  pass-by-reference (int&) for cumulative values like ways/ans.

    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }

    visited[i][j] = 1;
    int ans = 0;

    // to maintain the visited matrix

    // we will make the rat to check all the direction
    if (i >= 0 && i < n - 1 && arr[i + 1][j] && visited[i + 1][j] == 0)
    {
        // visited[i + 1][j]  = 1;
        ans += ratWays(arr, visited, i + 1, j, n); // down
        // visited[i + 1][j] =0;
    }
    if (i <= n - 1 && i > 0 && arr[i - 1][j] && visited[i - 1][j] == 0)
    {
        //    visited[i - 1][j] = 1;
        ans += ratWays(arr, visited, i - 1, j, n); // top
        // visited[i - 1][j]=0;
    }
    if (j >= 0 && j < n - 1 && arr[i][j + 1] && visited[i][j + 1] == 0)
    {
        //  visited[i][j + 1] = 1;
        ans += ratWays(arr, visited, i, j + 1, n); // right
        //  visited[i][j + 1]=0;
    }
    if (j <= n - 1 && j > 0 && arr[i][j - 1] && visited[i][j - 1] == 0)
    {
        // visited[i][j - 1] = 1;
        ans += ratWays(arr, visited, i, j - 1, n); // left
                                                   //    visited[i][j - 1] = 0;
    }

    visited[i][j] = 0; // // Backtrack// in case of taken wrong path, then this return will help to come back to old call.the return ans; statement plays a crucial role in backtracking.
    //  Here’s how it ensures the rat explores all possible paths and correctly backtracks when a dead end is reached: //if datatype wold be

    return ans; // this ans is for updating the ans in reference call in answ++, otherwise it is not needed if ans not needed to return.
}

// If we want to print the paths along with count, then we need to take vector of string and push into it.

bool validate(int i, int j, int n)
{
    if (i < 0 || j < 0 || i > n - 1 || j > n - 1)
    {
        return 0;
    }
    return 1;
}

void ratWaysOpti(int ratMaze[][4], vector<vector<bool> > &visitedRat, vector<string> &pathsDirection, string &currentPath, int i, int j, int n, int &ways)
{

    if (i == n - 1 && j == n - 1)
    {
        // reached the goal
        ways++;
        pathsDirection.push_back(currentPath);
        return;
    }

    // array of combination;
    int iCom[] = {1, -1, 0, 0};
    int jCom[] = {0, 0, 1, -1};
    string directions = "DTRL";

    visitedRat[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
        if (validate(i + iCom[k], j + jCom[k], n) && !visitedRat[i + iCom[k]][j + jCom[k]] && ratMaze[i + iCom[k]][j + jCom[k]])
        {
            currentPath.push_back(directions[k]); // works
            // currentPath += directions[k];  // Append//works

            ratWaysOpti(ratMaze, visitedRat, pathsDirection, currentPath, i + iCom[k], j + jCom[k], n, ways);
            // currentPath.pop_back();  // Requires C++11 or later // not works in older C++ compiler
            currentPath.erase(currentPath.end() - 1); // this will help in backtrack
        }
    }

    visitedRat[i][j] = 0; // this will help to backtrack when stuck

    // return;
}

// N bit binary Number //find all n bits binary number where number of 1 is more tha 0 in any prefix.
void nBitBinary(vector<string> &ans, int bits, string temp, int count_1, int count_0)
{
    // if (index == bits)
    if (temp.size() == bits)
    {
        ans.push_back(temp);
        return;
    }


    // we have pused this 1 seperately as 1 comes in both if and else hence take it out of condition

    temp.push_back('1');
    nBitBinary(ans, bits, temp, count_1 + 1, count_0);
    temp.erase(temp.end() - 1); //here it will fill 1 first than 0, in desreasing order as per the requirement

    if (count_1 > count_0)
    {
          // temp.push_back('1');
        // nBitBinary(ans, bits, temp, count_1 + 1, count_0);
        // temp.erase(temp.end() - 1); //we want in decreasing order hence push 1 then 0

        // we can fill with 1 and 0 both
        temp.push_back('0');
        nBitBinary(ans, bits, temp, count_1, count_0 + 1);
        temp.erase(temp.end() - 1);

      
    }
    // else
    // {
    //     // fill only 1
    //     temp.push_back('1');
    //     nBitBinary(ans, bits, index + 1, temp, count_1 + 1, count_0);
    //     temp.erase(temp.end() - 1); //remove the last index value
    // }
}

int main()
{

    // towerOfHanoi(1, 2, 3, 4); // we are shifting the four disk.
    towerOfHanoi(1, 2, 3, 3); // we are shifting the three disk.

    cout << endl;

    cout << towerOfHanoi(3, 'A', 'B', 'C') << endl; // A=Source, B=Auxiliary, C=Destination //7

    cout << endl;

    int friends, intK;

    cout << "Enter the number of friends:" << endl;
    cin >> friends;
    cout << "Enter the integer term k:" << endl;
    cin >> intK;

    vector<bool> record(friends, 0);
    cout << "Winner: " << predictWinner(record, friends, intK) << endl;
    cout << "Winner: " << predictWinnerOpt(record, friends, intK) << endl;
    cout << "Winner: " << predictWinnerRec(record, 0, record.size(), record.size(), intK) << endl;

    cout << winnerJosephOpti(friends, intK) + 1 << endl;

    int maze[4][4] = {1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    bool visited[4][4] = {0};
    cout << ratWays(maze, visited, 0, 0, 4) << endl;

    // let's try less line of code and also print the direction taken.

    // arr[0] = {1, 0, 0, 0};
    // arr[1] = {1, 1, 0, 1};
    // arr[2] = {0, 1, 0, 0};
    // arr[3] = {1, 1, 1, 1};

    // arr.push_back({1, 0, 0, 0});
    // arr.push_back({1, 1, 0, 1});
    // arr.push_back({0, 1, 0, 0});
    // arr.push_back({1, 1, 1, 1});

    // vector<vector<int> > arrRat = {
    //     {1, 0, 0, 0},
    //     {1, 1, 0, 1},
    //     {0, 1, 0, 0},
    //     {1, 1, 1, 1}};

    // All these works only in newer after C++11, for earlier, for loop is needed
    int ratMaze[4][4] = {1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<vector<bool> > visitedRat(4, vector<bool>(4, 0)); // empty 2D vector.
    vector<string> pathsDirection;
    string currentPath; // string validates pushback

    int waysPath = 0;

    if (ratMaze[0][0] == 0 || ratMaze[3][3] == 0)
    {
        // return 0; // here if start and end itself is found 0 then , we can get a single right path.

        cout << waysPath << endl;
    }
    else
    {

        ratWaysOpti(ratMaze, visitedRat, pathsDirection, currentPath, 0, 0, 4, waysPath);
        cout << waysPath << endl;
    }

    for (int i = 0; i < pathsDirection.size(); i++)
    {
        cout << i + 1 << ".\t" << pathsDirection[i] << endl;
    }

    vector<string> NbitBinary;
    string tempbits;
    nBitBinary(NbitBinary, 4, tempbits, 0, 0);

    for (int i = 0; i < NbitBinary.size(); i++)
    {
        cout << NbitBinary[i] << endl;
    }

    return 0;
}