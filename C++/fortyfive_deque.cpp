#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

// Double ended queue
// inbuilt stack and queue is implememnted with Dequeue

// Dequeue with linkedlist
// Dequeue with array
// stack using deque inbuilt

// Sliding window maximum.
// Minimum Number of K consecutive Flip bits //two methods

// Deque with linkedlist
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class deQue
{
public:
    Node *front, *rear;

    deQue()
    {
        front = NULL;
        rear = NULL;
    }

    void push_front(int val)
    {
        Node *temp = new Node(val); // what if node not created due to overflow
        if (temp == NULL)
        {
            cout << "overflow Heap\n";
            return;
        }
        if (front == NULL)
        {
            front = temp;
            rear = temp;
            return;
        }
        else
        {
            temp->next = front;
            front->prev = temp;
            front = temp;
            return;
        }
    }
    void push_back(int val)
    {
        Node *temp = new Node(val);
        if (front == NULL)
        {
            front = temp;
            rear = temp;
            return;
        }
        else
        {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            return;
        }
    }

    void pop_front()
    {

        if (front == NULL)
        {
            cout << "Underflow deque\n";

            return;
        }
        // else if (front == rear)
        // {
        //     // if only one node is popped
        //     Node *temp = front;
        //     front = NULL;
        //     rear = NULL;
        //     delete temp;
        // }
        // else
        // {
        //     Node *temp = front;
        //     front = front->next;
        //     temp->next = NULL;
        //     front->prev = NULL;
        //     delete temp;
        //     return;
        // }

        Node *temp = front;
        front = front->next;
        delete temp;

        if (front)
        {
            // if front present, then prev to null
            front->prev = NULL;
        }
        else
        {
            rear = NULL;
        }

        return;
    }
    void pop_back()
    {
        if (front == NULL)
        {
            cout << "Underflow deque\n";

            return;
        }
        // else if (front == rear)
        // {
        //     // if only one node is popped
        //    Node *temp = rear;
        //     front = NULL;
        //     rear = NULL;
        //     delete temp;
        // }
        // else
        // {
        //     Node *temp = rear;
        //     rear = rear->prev;
        //     rear->next = NULL;
        //     temp->prev = NULL;
        //     delete temp;
        //     return;
        // }

        Node *temp = rear;
        rear = rear->prev;
        delete temp;

        if (rear)
        {
            // not null
            rear->next = NULL;
        }
        else
        {
            front = NULL;
        }
        return;
    }

    int frontEle()
    {
        if (front)
        {
            return front->data;
        }
        else
        {
            return -1;
        }
    }

    int backEle()
    {
        if (front)
        {
            return rear->data;
        }
        else
        {
            return -1;
        }
    }
};

// Dequeue with array
class deQueArray
{

    // the modulo operator (%) has a higher precedence than the addition operator (+) in most programming languages

    int size;
    int *arr;
    int front = -1, rear = -1;

public:
    deQueArray(int n)
    {
        arr = new int[n];
        size = n;
    }

    bool isFull()
    {
        return front == (rear + 1) % size;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void push_front(int val)
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[front] = val;
            cout << "DEQUE pushed at front :" << arr[front] << endl;
        }
        else
        {
            if (front == (rear - 1) % size)
            {
                cout << "DEQUE full\n";
                return;
            }
            else
            {
                front = (front - 1 + size) % size;
                arr[front] = val;
                cout << "DEQUE pushed at front :" << arr[front] << endl;
                return;
            }
        }
    }

    void push_back(int val)
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[front] = val;
        }
        else
        {
            if (front == (rear - 1) % size)
            {
                cout << "DEQUE full\n";
                return;
            }
            else
            {
                rear = (rear + 1) % size;
                arr[rear] = val;
                cout << "DEQUE pushed at back :" << arr[rear] << endl;
                return;
            }
        }
    }

    void pop_front()
    {
        if (isEmpty())
        {
            cout << "DeQue underflow\n";
            return;
        }
        else
        {
            if (front == rear)
            {
                cout << "front popped from deque: " << arr[front] << endl;
                front = rear = -1;
                return;
            }
            else
            {
                cout << "front popped from deque: " << arr[front] << endl;
                front = (front + 1) % size;
                return;
            }
        }
    }

    void pop_back()
    {
        if (isEmpty())
        {
            cout << "DeQue underflow\n";
            return;
        }
        else
        {
            if (front == rear)
            {
                cout << "back popped from deque: " << arr[rear] << endl;
                front = rear = -1;
                return;
            }
            else
            {
                cout << "back popped from deque: " << arr[rear] << endl;
                rear = (rear - 1 + size) % size;
                return;
            }
        }
    }
};

//  stack using deque inbuilt
class stack
{

    deque<int> dq;

public:
    void push(int val)
    {
        dq.push_back(val);
    }

    void pop()
    {
        dq.pop_back();
    }
};

// Sliding window maximum.
vector<int> slideMax(int arr[], int n, int k)
{
    vector<int> ans;
    for (int i = 0; i <= n - k; i++)
    {
        int greater = INT32_MIN;
        for (int j = i; j < i + k; j++)
        {
            greater = max(arr[j], greater);
        }
        ans.push_back(greater);
    }

    return ans;
}

vector<int> slideWindowMax(int arr[], int n, int k)
{
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < k - 1; i++)
    {
        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    // if max later is foun then remove the min, from the end
    //  if max found then push this max and pop at end, when min is found then simply push at back .pop from pront when out of window slide
    for (int i = k - 1; i < n; i++)
    {

        // remove out of window left element
        if (!dq.empty() && dq.front() < i + 1 - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(arr[dq.front()]);
    }

    return ans;
}

// Minimum Number of K consecutive Flip bits
// where k is the size of window it it has to flip all at a time.
// we have to make all 1, if all can't me made then return -1
// we need to return in how many flip all bits can be made to 1.
// we can solve in order of NK using sliding method, k used at time of flipping and checking

int flipbitsMin(int arr[], int n, int k)
{
    int flips = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            // flip from here upto the end
            for (int j = i; j < i + k && j < n; j++)
            {
                // if (arr[j] == 0)
                // {
                //     arr[j] = 1;
                // }
                // else
                // {
                //     arr[j] = 0;
                // }

                // above combined condition can be
                arr[j] = !arr[j]; // not works here
            }

            flips++;
        }
    }

    if (arr[n - 1] == 1)
        return flips;
    else
        return -1;
}

// using queue and poppint the index where 1 is present.push at end and pop from front.//even this will also take O(nk), k is utilized at the time of popping
// to solve in O(n), we can store the count of flips one index has done then if count is even the current result will be its final value else complement it.

int flipbitsMinOpti(int arr[], int n, int k)
{
    int flips = 0;
    vector<int> count(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (count[i] % 2 == 0)
        {

            if (arr[i] == 0) // if if can be combined as count[i] % 2 == arr[i] as both 0
            {
                flips++;

                for (int j = i; j < i + k && j < n; j++)
                {
                    count[j]++;
                }
            }
            else
            {
                continue;
            }
        }
        else if (count[i] % 2 == 1)
        {
            if (arr[i] == 1) // if if can be combined as count[i] % 2 == arr[i] as both 1 , hence instead of if else we can write as together
            {
                // it has flipped once and moved to 0
                flips++;

                for (int j = i; j < i + k && j < n; j++)
                {
                    count[j]++;
                }
            }
        }

        cout << "flips happened so far are : " << flips << endl;
    }

    // cout<<"flips happened so far are : "<<flips<<endl;

    if ((count[n - 1] % 2 == 0 && arr[n - 1] == 1) || (count[n - 1] % 2 == 1 && arr[n - 1] == 0))
        return flips;
    else
        return -1;
}

// now instrad of storing the count we can simply use queue size as count of flips happened so far.Whenever flip happens it flipps to a new index and that index is pushed. Old index from where it has alredy flipped and become 1 then that will be popped once it comes out of lower limit. out of lower limit calculated on the bases of current index , if current index greater than the queue element first then pop it.

int flipbitsMinOptiCount(int arr[], int n, int k)
{
    int flips = 0; // to check the flips
    // size of queue to check the count

    // queue<int>Q;
    deque<int> Q;

    // for (int i = 0; i < n; i++) //for returning -1 , we should use i only upto n-k
    for (int i = 0; i < n - k + 1; i++) // for returning -1 , we should use i only upto n-k
    {
        if (!Q.empty() && Q.front() < i)
        {
            Q.pop_front();
        }
        if (Q.size() % 2 == arr[i]) //! Q.empty() &&
        {
            flips++;
            Q.push_back(i + k - 1); // index it has flipped upto this, and size give the count upto which it has been flipped
        }

        cout << "flips happened so far are : " << flips << endl;
    }

    for (int i = n - k; i < n; i++)
    {
        if (Q.size() % 2 != arr[i])
        {
            continue;
        }
        else
        {
            return -1;
        }
    }

    return flips; // as here flip size we have extended can go with less size till it is smaller than , fixed size not considered
}

int main()
{

    deQue dqLinkedList;
    dqLinkedList.push_front(12);
    dqLinkedList.push_back(23);
    // dqLinkedList.pop_back();
    // dqLinkedList.pop_front();
    cout << dqLinkedList.frontEle() << endl;
    cout << dqLinkedList.backEle() << endl;

    // Dequeue with array
    deQueArray deQueueArray(5);
    deQueueArray.push_front(12);
    deQueueArray.push_back(23);
    deQueueArray.pop_back();
    deQueueArray.pop_front();

    deque<int> DQ;
    DQ.push_front(12);
    DQ.push_back(23);
    DQ.pop_back();
    DQ.pop_front();
    cout << DQ.front() << endl;
    cout << DQ.back() << endl;

    stack st;
    st.push(13);
    st.push(15);
    st.pop();

    // Sliding window maximum.
    // we can solve in O(n^2) also, but for optimization solve using deque
    int arr[] = {4, 3, 7, 5, 2, 3, 1, 2, 8, 7};
    vector<int> ans;
    ans = slideMax(arr, sizeof(arr) / sizeof(arr[0]), 3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // solving in O(n)
    ans = slideWindowMax(arr, sizeof(arr) / sizeof(arr[0]), 3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // Minimum Number of K consecutive Flip bits
    // where k is the size of window it it has to flip all at a time.
    // we have to make all 1, if all can't me made then return -1
    // we need to return in how many flip all bits can be made to 1.
    int arr3[] = {0, 1, 0, 1};

    cout << "flips: " << flipbitsMin(arr3, sizeof(arr3) / sizeof(arr3[0]), 2) << endl; // this will directly make it all 1 hence we need to give new input to next flip check

    int arr4[] = {0, 0, 1, 0, 0, 1, 1, 0, 1, 0};
    cout << "flips: " << flipbitsMinOpti(arr4, sizeof(arr4) / sizeof(arr4[0]), 4) << endl; // O(n*k)

    // int arr5[] = {0, 0, 1, 0, 0, 1, 1, 0, 1, 0};
    int arr5[] = {1, 0, 1, 1, 1};
    cout << "flips: " << flipbitsMinOptiCount(arr5, sizeof(arr5) / sizeof(arr5[0]), 4) << endl; // O(n)
}