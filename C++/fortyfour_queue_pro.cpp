
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// calculate the time needed to get all tickets
// implement queue using stack.
// implement stack using queue.
// print all number in every window of size k
// first negative integer in every window of size k.//two methods
// first no repaeating char in a stram of characters//two method



void printQueueWithoutExtra(queue<int> &Q)
{ // affect the original

    // we can push the poped element in a vector then again make queue from it//

    int size = Q.size();
    while (size--)
    {
        cout << Q.front() << " ";
        Q.push(Q.front());
        Q.pop();
    }

    cout << endl;
}

int timeneeded(queue<int> Q, int k)
{
    int time = 0;
    int kIndex = k;
    while (k != 0)
    {

        if (kIndex == 0)
        {
            k--;
        }
        if (Q.front() > 0)
        {
            time++;
        }
        Q.push(Q.front() - 1);
        Q.pop();
        kIndex = (kIndex - 1 + Q.size()) % Q.size();
    }

    // we can pop 0 from here now.

    return time;
}

int timeneededUsingQueue(vector<int> arr, int k)
{
    int time = 0;

    queue<int> Q;

    for (int i = 0; i < arr.size(); i++)
    {
        Q.push(i); // we have pushed all the index for tracking not the value.
    }

    // until ticket at k !=0
    while (arr[k] != 0)
    {
        int index = Q.front();
        // if (arr[Q.front()] != 0)
        // { //not needed as queue has only those having non zero.

        time++;
        arr[Q.front()]--;
        if (arr[Q.front()])
        {
            Q.push(Q.front());
        }

        Q.pop(); // pop shuld be in every case
        // }
    }

    return time;
}

// time complexity can go upto O(n^2)
// let's decrese the time complexity
// we are storing the min while traversing.

int timeneededUsingQueueOpti(vector<int> arr, int k)
{
    int time = 0;
    // we have to compare at each index, this arr[k];

    for (int i = 0; i < k; i++)
    {
        time += min(arr[k], arr[i]);
    }

    // for the k th index
    time += arr[k]; // we have take this time , after this has executed one time lesser than kth value

    for (int i = 0; i < k; i++)
    {
        time += min(arr[k] - 1, arr[i]);
    }

    return time;
}

// implement queue using stack.
// pop from first and push to last.
// here we need to use two stack one for push and other for pop

class Queuestack
{

    stack<int> s1;
    stack<int> s2;

public:
    Queuestack()
    {
        // we will push in s1 and pop by getting the bottom in new stack
    }

    void push(int val)
    {
        s1.push(val);
        cout << "pushed : " << s1.top() << endl;
        return;
    }

    bool empty()
    {
        // if (s2.empty() && s1.empty())
        // {
        //     // underflow
        //     cout << "queue is empty \n";
        //     return 1;
        // }

        return s2.empty() && s1.empty();
    }

    void pop()
    {
        // copy all elements from s1 if s2 is empty
        if (empty())
        {
            // underflow
            cout << "queue is empty \n";
            return;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "popped from queue: " << s2.top() << endl;
        s2.pop();
        return;
    }

    int front()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }
};

// push(): O(1)
// pop(): O(1) amortized (occasional O(n) when transferring)
// front(): O(1) amortized

// implement stack using queue
class StackQueue
{

    queue<int> q1;
    queue<int> q2;

public:
    bool empty()
    {
        return q1.empty() && q2.empty();
    }
    void push(int val)
    {

        // here as at the time of popping we need to push all the front elements to another queue , hence we don't need to bring all back, instead we can involve logic

        if (empty())
        {
            // we can use direct push into q1
            q1.push(val);
            cout << "pushed : " << q1.back() << endl;
            return;
        }

        if (q1.empty() && !q2.empty())
        {
            q2.push(val);
            cout << "pushed : " << q2.back() << endl;
        }
        else if (!q1.empty() && q2.empty())
        {
            q1.push(val);
            cout << "pushed : " << q1.back() << endl;
        }

        return;

        // all cases not needed above , just this much will be OK shown below
        // Always push to the non-empty queue, or q1 if both are empty
        if (!q1.empty())
        {
            q1.push(val);
        }
        else
        {
            q2.push(val);
        }
        cout << "pushed: " << val << endl;
    }

    // // Swap the queues
    // swap(q1, q2);//possible when we don't want to check condition from both queue

    void pop()
    {
        // copy all elements from q1 to q2 except the last one, and vice versa

        if (empty())
        {
            // underflow
            cout << "queue is empty \n";
            return;
        }
        if (q2.empty())
        {
            while (q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }

            cout << "popped from queue: " << q1.front() << endl;
            q1.pop();
        }
        else if (q1.empty())
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            cout << "popped from queue: " << q2.front() << endl;
            q2.pop();
        }

        return;
    }

    int top()
    {
        if (empty())
        {
            cout << "queue is empty \n";
            return -1;
        }
        if (!q1.empty())
        {
            return q1.back();
        }

        else if (!q2.empty())
        {
            return q2.back();
        }

        return -1; // just for pattern read
    }
};

// print all number in every window of size k
//  all type of window related question can be solve using queue, specially the print type

void displayQueue(queue<int> &Q, int arr[])
{
    int n = Q.size();
    while (n--)
    {
        cout << arr[Q.front()] << " ";
        Q.push(Q.front());
        Q.pop();
    }
    cout << endl;
}

void printWindowEle(int arr[], int n, int k)
{
    // k is size of window//n is size of array
    queue<int> Q; // we will put index of element
    int windSiz = k;
    for (int i = 0; i < n; i++)
    {

        Q.push(i);

        if (Q.size() == windSiz)
        {
            displayQueue(Q, arr);
            // now pop one at start
            Q.pop();
        }
    }
}

// first negative integer in every window of size k.
// here whenever first in window comes , we can use queue concet
// here we will push the index of only negative in the queue and if this index gets out then we will pop it, push new index as iterate

void printFirstNegWindK(int arr[], int n, int k)
{
    queue<int> Q;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] < 0)
        {
            Q.push(i);
        }
        // pop which has got out of range
        if (!Q.empty() && Q.front() < i + 1 - k)
        {
            Q.pop();
        }

        // cout<<"Checking all: ";
        // displayQueue(Q,arr);

        if (i + 1 >= k)
        {
            //  cout<<"hello"<<endl;
            // print the front element as min firt negative in this window size
            if (Q.empty())
            {

                cout << "0" << " ";
            }
            else
            {
                // cout <<"Min here: "<< arr[Q.front()] << " ";
                cout << arr[Q.front()] << " ";
            }
        }
    }

    cout << endl;
}

// clear approach of seperate push
vector<int> printFirstNegWindKCl(int arr[], int n, int k)
{
    queue<int> Q;
    vector<int> ans;
    for (int i = 0; i < k - 1; i++)
    {
        if (arr[i] < 0)
        {
            Q.push(i);
        }
    }

    for (int i = k - 1; i < n; i++)
    {

        if (arr[i] < 0)
        {
            Q.push(i);
        }
        // pop which has got out of range
        if (!Q.empty() && Q.front() < i + 1 - k)
        {
            Q.pop();
        }

        if (Q.empty())
        {
            ans.push_back(0);
            cout << "0" << " ";
        }
        else
        {
            ans.push_back(arr[Q.front()]);
            cout << arr[Q.front()] << " ";
        }
    }

    cout << endl;

    return ans;
}

// first no repaeating char in a stram of characters
// as first is highlighted, we will use queue
string firstNoRepeated(string A)
{

    queue<char> Q;
    vector<int> repeated(26, 0);
    string ans;

    for (int i = 0; i < A.size(); i++)
    {
        // as we think of pushing those which has not come ever in string, for this we need comparision in the ans string


        // OK but unncecessary headache

        // if (repeated[A[i] - 'a'] > 0)
        // {
        //     // already have come//hence don't push this and pop if first is this
        //     if (!Q.empty() && Q.front() == A[i])
        //     { // This will crash when the queue is empty because you're calling Q.front() on an empty queue.
        //         Q.pop();
        //     }
        // }
        // else
        // {
        //     Q.push(A[i]);
        // }

        // simpler to add without using above unneccessary condition

        repeated[A[i] - 'a']++; //// Increment count of current character

        // If this is the first occurrence, add to queue
        if (repeated[A[i] - 'a'] == 1)
        {
            Q.push(A[i]);
        }

        while (!Q.empty() && repeated[Q.front() - 'a'] > 1)
        {
            Q.pop();
        }

        if (!Q.empty())
        {
            ans += Q.front();
        }
        else
        {
            ans += "#";
        }
    }

    return ans;
}

int main()
{
    queue<int> Qin;
    Qin.push(1);
    Qin.push(5);
    Qin.push(2);
    Qin.push(3);
    Qin.push(7);

    printQueueWithoutExtra(Qin);

    // time needed to buy the ticket for kth person. Only one ticket can be given at a time and move back to the queue.

    // number of tickets neede is given
    //  1 5 2 3 7

    // for getting one ticket at a time, it needs 1 sec, hence give answer of the time needed to buy tickets.

    // we can use linear approch where we can send the element to back when ticket it needs still is >0
    // popping inbetween cause k index finding problom, either we put then in stack and increment time only when it's value>0

    cout << "time needed: " << timeneeded(Qin, 2) << endl; // here 2 is index value

    // Approch where intermediate makes sense.
    // when array of tickets is given
    vector<int> tickets = {1, 5, 2, 3, 7};

    cout << "time needed: " << timeneededUsingQueue(tickets, 2) << endl;     // here 2 is index value
    cout << "time needed: " << timeneededUsingQueueOpti(tickets, 2) << endl; // here 2 is index value

    // implement Queue using stack
    Queuestack QS;
    QS.push(12);
    QS.push(13);
    QS.push(14);
    cout << QS.front() << endl;
    QS.push(15);
    QS.push(16);

    QS.pop();
    QS.push(17);

    QS.pop();
    QS.pop();
    QS.pop();
    QS.pop();
    QS.pop();
    QS.pop();
    cout << endl;
    // implement stack using queue
    StackQueue SQ;
    SQ.push(12);
    SQ.push(13);
    SQ.push(14);
    SQ.push(15);
    SQ.push(16);
    SQ.pop();
    SQ.pop();
    SQ.pop();
    cout << SQ.top() << endl;

    // print all number in every window of size k
    int arr[] = {3, 6, 2, 7, 8, 11};
    printWindowEle(arr, 6, 3);

    int arr2[] = {2, -3, -4, -2, 7, 8, 9, -10};
    printFirstNegWindK(arr2, 8, 3);
    printFirstNegWindKCl(arr2, 8, 3);

    // instead of printing value each time we can return a vector of answer also
    vector<int> ansMin = printFirstNegWindKCl(arr2, 8, 3);

    // first no repaeating char in a stram of characters
    // as first is highlighted, we will use queue

    // cout << firstNoRepeated("abcacdbd") << endl;
    cout << firstNoRepeated("ababdc") << endl; // aab#dd
}