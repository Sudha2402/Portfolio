#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <stack>
#include <algorithm>

// Job scheduling
// Single threaded CPU
// fractional knapsack
// Non overlapping Intervals
// Insert Interval
// Task Schedular

// Job scheduling
class Job
{
public:
    int id;
    int dead;
    int profit;
};

bool comp(Job a, Job b)
{
    return a.profit > b.profit; // DESCENDING ORDER OF PROFIT
}

vector<int> JobScheduling(Job arr[], int n)
{
    // sort arr on the bases of deadline , or we can simply create two array one for deadline task number and another for profit respectively

    sort(arr, arr + n, comp); // we are using decreasing order of profit.

    // we will fill first profit at the the deadline it is available.//here greedy approch on the bases of profit used.

    // we also need to sort the profit one one deadline.

    // int size = arr[0].dead;

    int size = 0;

    // for size, we can use comparision also

    for (int i = 0; i < n; i++)
    {
        // cout<<"arr[i].profit : "<<arr[i].profit <<" ";//descresing order of profit, hence fill max profit first as per deadline and before it in case of non empty but that has to be filled before other profits

        size = max(size, arr[i].dead);
    }
    cout << endl;

    vector<bool> deadlineTimer(size + 1, 0); // it might be possibel that deadline greater than the size. hence first sort the deadline then check max deadline

    // one deadline profit sort.

    // vector<int> Profit(size + 1, 0);

    // let's traverse the arr[]
    int jobsDone = 0;
    int profitGained = 0;

    // time complexity : O(n*n)
    for (int i = 0; i < n; i++)
    {

        // start from max profit filled then check deadline
        int deadline = arr[i].dead;

        for (int j = deadline; j > 0; j--)
        {

            if (deadlineTimer[j] == 0)
            {
                // fill the job here and increase job count and profit
                deadlineTimer[j] = 1;
                jobsDone++;
                // sum all the profits
                profitGained += arr[i].profit;

                break; // no more checking
            }
        }
    }

    vector<int> ans;

    ans.push_back(jobsDone);
    ans.push_back(profitGained);

    return ans;
}

// job scheduling optimized to decrese time complexity below O(n*n)
//  Optimized version using Union-Find - FIXED

int findEmpty(int deadline, vector<int> &currEmpty)
{
    // base case
    // this empty found needs to be traverse to the top hence recursion call must have return attached, and for also updating the value in called parent value assign the value.

    // here when no empty found then 0 will be the base case as 0 alsways present at inded 0 which is same index hence return 0 from the basse case
    if (deadline == currEmpty[deadline])
    {
        return deadline; // this is the empty present
    }

    // return findEmpty(currEmpty[deadline], currEmpty); // this is to traverse the return result to the top.

    // for also updating the value in parent call
    return currEmpty[deadline] = findEmpty(currEmpty[deadline], currEmpty); // also updating the value in called parent value assign the value.

    // for reflecting this update use pass by reference not value
}

vector<int> JobSchedulingOpti(Job arr[], int n)
{
    sort(arr, arr + n, comp); // we are using decreasing order of profit.

    int size = 0;

    // for size, we can use comparision also

    for (int i = 0; i < n; i++)
    {
        size = max(size, arr[i].dead);
    }

    // vector<bool> deadlineTimer(size + 1, 0);//not needed

    vector<int> currEmpty(size + 1, 0);

    // fill this currEmpty with itself index number
    for (int i = 0; i < size + 1; i++)
    {
        currEmpty[i] = i;
    }

    int jobsDone = 0;
    int profitGained = 0;

    // time complexity < O(n*n)

    for (int i = 0; i < n; i++)
    {
        // start from max profit filled then check deadline
        int deadline = arr[i].dead;

        // we want internal move to the prev empty
        // int index = deadline;

        // while (currEmpty[index] != index)
        // {
        //     //here this will solve but not optimized as when we get new index value and we visit to that index and found not empty then the next empty we find needs to be returned to update in the parent which called it so that next time direct call not affects. hence for storing that return value, we need recursion

        //     index = currEmpty[index];
        // }

        int index = findEmpty(deadline, currEmpty);

        // this index = 0, means no time empty left
        if (index > 0)
        {
            // deadlineTimer[index] = 1;//not needed

            jobsDone++;

            profitGained += arr[i].profit;

            // currEmpty[index] = currEmpty[index] - 1;

            currEmpty[index] = currEmpty[index - 1]; // previous data min updated here // it provides better path compression and faster lookups.
        }
    }

    vector<int> ans;

    ans.push_back(jobsDone);
    ans.push_back(profitGained);

    return ans;

    // return {jobsDone, profitGained};//also a vector
}

// Single threaded CPU
vector<int> getOrder(vector<vector<int>> &tasks)
{
    // tasks are labelled from 0 to n-1.
    // as we are going to sort on the bases of enqueue time, the task number will also change hence we will add this task number in the tasks itself.

    for (int i = 0; i < tasks.size(); i++)
    {
        tasks[i].push_back(i); // this way we have pushed at last index 0, 1, 2
    }

    // sort on the bases of enqueue
    sort(tasks.begin(), tasks.end()); // enqueue is at index 0 hence it will be sorted on the bases of enqueue.

    long long int currtime = tasks[0][0]; // enqueue time is extracted // it is made long long because timer addition can be any long.

    // we can track the last task we have pushed in the heap.
    // int taskNumPushed = 0;

    // create minheap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pt; // we want sort on the bases of processing time, here we are pushing processing time and task number//we want min heap hence we have to mention greater

    // pt.push(make_pair(tasks[0][1], tasks[0][2]));

    vector<int> ans;

    for (int i = 0; i < tasks.size(); i++)
    {
        // we have to process all the task.
        if (tasks[i][0] <= currtime)
        {
            pt.push(make_pair(tasks[i][1], tasks[i][2]));
            // for not processing it next time , we need to remove this from the task list or change the enter time to infinity

            continue;
        }

        // if reached here then process from the heap.

        while (currtime < tasks[i][0])
        {
            currtime += pt.top().first;
            ans.push_back(pt.top().second);

            pt.pop();
        }

        // this current index i is not in the heap but after last i value being pushed into the queue, this for loop is continued

        // push this i event also
        pt.push(make_pair(tasks[i][1], tasks[i][2]));
    }

    while (!pt.empty())
    {
        currtime += pt.top().first;
        ans.push_back(pt.top().second);

        pt.pop();
    }

    return ans;
}

// or method

vector<int> getOrderDefaultMethod(vector<vector<int>> &tasks)
{
    for (int i = 0; i < tasks.size(); i++)
    {
        tasks[i].push_back(i);
    }
    sort(tasks.begin(), tasks.end());

    long long currtime = tasks[0][0];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pt;

    vector<int> ans;

    int i = 0; // track the current task number to be pushed hence push i used.
    while (i < tasks.size() || !pt.empty())
    {
        // i<task.size is satisfied always till the last time when no more tasks to be pushed , pt not empty will be used at last when we have to pop all from pt queue

        // Push all available tasks
        while (i < tasks.size() && tasks[i][0] <= currtime)
        {
            pt.push({tasks[i][1], tasks[i][2]});
            i++;
        }

        if (pt.empty())
        {
            // here if pt is empty and it has come from top while loop then it is because i < tasks.size() hecne we can safely push this i th task

            // Jump to next task's time
            currtime = tasks[i][0];
            continue;
        }

        // Process one task

        int processing = pt.top().first;
        int index = pt.top().second;

        pt.pop();

        currtime += processing;
        ans.push_back(index);
    }

    return ans;
}

// fractional knapsack
struct Item
{ // same work as c, only called directly instead of using struct

    // struct is by default public

    int value;
    int weight;

    // this sequence is automatically followed when we defined this item as statype and then the data present in it on the bases of indexing.
};

bool compareItem(Item a, Item b)
{
    // return a.value / a.weight > b.value / b.weight;//this devide may create floor devision error , hence convert into multiply

    return a.value * b.weight > b.value * a.weight;
}

// function to get maximum total value, w is the weight maximum for the bag to hold, n is the number of items

double fractionalKnapsack(int w, Item arr[], int n)
{
    // we need to calculate value/weight and sort on that bases
    sort(arr, arr + n, compareItem);

    // after sorting, we need to compare
    double valueGenerated = 0;
    for (int i = 0; i < n; i++)
    {
        if (w > 0)
        {
            // if we have used while loop then i<n and w>0 would have been used together

            if (w >= arr[i].weight)
            {

                valueGenerated += arr[i].value;
                w -= arr[i].weight;
            }
            else
            {

                valueGenerated += (w) * (arr[i].value / arr[i].weight);
                // w -= w;
                w = 0;
            }
        }
    }

    return valueGenerated;
}

// Non overlapping Intervals

bool compEnd(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

// we have to remove min number of intervals for not overlapping
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    // sort on thebases of end time, then compare

    // sort(intervals,intervals+n,compEnd);//works in array not in vector

    sort(intervals.begin(), intervals.end(), compEnd); // works in vector

    int minEraseInterval = 0;
    int timer = intervals[0][0];
    for (int i = 0; i < intervals.size(); i++)
    {
        if (timer > intervals[i][0])
        {
            minEraseInterval++;
        }
        else
        {
            timer = intervals[i][1];
        }
    }

    return minEraseInterval;
}

// Insert Interval
vector<vector<int>> insertIntervals(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    // as interval is already non overlapping, we simply need the position where it's start can lie

    vector<vector<int>> CombIntervals;

    int intervalIndex = 0;

    while (intervalIndex < intervals.size() && intervals[intervalIndex][1] < newInterval[0])
    {
        // if start more than end then push it
        CombIntervals.push_back(intervals[intervalIndex]);
        intervalIndex++;
    }

    if (intervalIndex == intervals.size())
    {
        // we have traversed all in the above while as all found smaller
        CombIntervals.push_back(newInterval);
        return CombIntervals;
    }

    // now comes the case of combining
    // here instead of pushing the new interval once and then comparing the rest with CombIntervals last element then updating is complex way. instead we can think of a way when we keep updating the new interval and keep it aside and when finally no more overlap present then insert it

    while (intervalIndex < intervals.size() && intervals[intervalIndex][0] <= newInterval[1])
    {
        // new interval end is more than this current start, newInterval ko abhi bhi nahi push kar sakte
        // it is just like it's end is more than newelement start hence this index can't be inserted directly in the above hence came to this while loop and here it is checked that if end time of newInterval is also more than start of the current index then new interval can also not be pushed

        // hence combine both

        // newinterval start < index end
        // newinterval end >  index start

        // index start,newinterval start <= newinterval end , index end

        // need to combine, but we will store in the newInterval
        newInterval[0] = min(newInterval[0], intervals[intervalIndex][0]);
        newInterval[1] = max(newInterval[1], intervals[intervalIndex][1]);

        intervalIndex++;
    }

    CombIntervals.push_back(newInterval);

    while (intervalIndex < intervals.size())
    {
        CombIntervals.push_back(intervals[intervalIndex]);
        intervalIndex++;
    }

    return CombIntervals;
}

// Task Schedular
// This is asked in LSEG coding round
// here a task will execute after maintaining atleast 2 gap.
int leastInterval(vector<char> &tasks, int n)
{
    // whenever such question comes keep in mind that to count all the given characters that must be min needed. then use the constain to put at the place such that it is occupying least space

    // here we have to return min number of cycle or interval. the positions min needed for all tasks to be executed

    // count each character freq
    vector<int> countCharacters(26, 0);
    for (int i = 0; i < tasks.size(); i++)
    {
        countCharacters[tasks[i] - 'A']++;
    }

    // get max count and it's frequency.

    int maxCount = -1;
    int maxCountFreq = 0;

    for (int i = 0; i < 26; i++)
    {
        if (countCharacters[i] > maxCount)
        {
            maxCount = countCharacters[i];
            maxCountFreq = 1;
        }
        else if (countCharacters[i] == maxCount)
        {
            maxCountFreq++;
        }
    }

    int minInterval = tasks.size();
    minInterval = max(minInterval, (maxCount - 1) * (n + 1) + maxCountFreq);

    return minInterval;
}

int main()
{

    // Job scheduling

    Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};

    vector<int> jobCount_profit = JobScheduling(arr, 4); // 4 jobspresent//each takes 1 unit time to execute.

    cout << "jobCount : " << jobCount_profit[0] << " " << "profit : " << jobCount_profit[1] << endl; // jobCount : 2 profit : 60

    // Job scheduling optimized
    jobCount_profit.clear();
    jobCount_profit = JobSchedulingOpti(arr, 4); // 4 jobspresent//each takes 1 unit time to execute.

    cout << "jobCount : " << jobCount_profit[0] << " " << "profit : " << jobCount_profit[1] << endl; // jobCount : 2 profit : 60

    // Single threaded CPU
    vector<vector<int>> tasks = {{1, 3}, {2, 1}, {2, 2}};
    vector<int> singlethreadorder = getOrder(tasks);
    singlethreadorder.clear();
    singlethreadorder = getOrderDefaultMethod(tasks);

    // fractional knapsack
    Item arrittem[] = {{60, 10}, {100, 20}, {120, 30}};
    int maxValueGenerated = fractionalKnapsack(50, arrittem, 3);
    cout << "maxValueGenerated : " << maxValueGenerated << endl; // maxValueGenerated : 240

    // Non overlapping Intervals
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int minEraseInterval = eraseOverlapIntervals(intervals);
    cout << "minEraseInterval : " << minEraseInterval << endl;

    // Insert Interval
    vector<vector<int>> intervalsTobeInserted = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> afterInsertedInterval = insertIntervals(intervalsTobeInserted, newInterval);

    for (int i = 0; i < afterInsertedInterval.size(); i++)
    {
        cout << afterInsertedInterval[i][0] << " " << afterInsertedInterval[i][1] << "\t";
    }
    cout<<endl;

    // Task Schedular
    vector<char> tasksForMinInterval = {'A', 'A', 'A', 'B', 'B', 'B'};
    int minIntervalReqWithleastNCooling = leastInterval(tasksForMinInterval, 2);
    cout <<"minIntervalReqWithleastNCooling  : "<< minIntervalReqWithleastNCooling << endl;

    



    return 0;
}