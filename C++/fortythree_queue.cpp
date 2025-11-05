// FIFO //Queue

// circular implementation of queue using array
// implementation of queue using linkedlist
// inbult STL queue

// Print all the element in queue
// queue reversal using stack is good option

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class queueArray
{
    int *arr;
    int front, rear;
    int size;

public:
    queueArray(int n)
    {
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return front == (rear + 1) % size;
    }

    void push(int x)
    {
        if (isEmpty())
        {

            front = rear = 0;
            arr[rear] = x;
        }
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
        }

        cout << "pushed into queue: " << arr[rear] << endl;
        return;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }

        // if front and rear is last element then we need to bring front and back at the start

        cout << "popped from queue: " << arr[front] << endl;
        if (front == rear)
        {

            front = rear = -1;
        }

        else
        {

            front = (front + 1) % size;
        }
    }
};

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queueLinkedList
{

    Node *front;
    Node *rear;

public:
    queueLinkedList()
    {
        front = NULL;
        rear = NULL;
    }

    void push(int val)
    {

        Node *temp = new Node(val);
        if (front == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = rear->next;
        }

        cout << "pushed into queue: " << rear->data << endl;

        return;
    }

    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        else
        {
            cout << "popped from queue: " << front->data << endl;
            Node *temp = front;
            front = front->next; // we need to handle that case also when front is NULL, then rear should also be null
            delete temp;

            if (front == NULL)
            {
                rear = NULL;
            }

            return;
        }
    }
};

// print all the element in queue
// when completely distroying anf not needed then  we can pop and print till it becomes empty

void printQueue(queue<int> Q)
{ // affect the original if & used, for remaining the original use copy

    while (!Q.empty())
    {
        cout << Q.front() << " ";
        Q.pop();
    }

    cout << endl;
}

void printQueueRemain(queue<int> &Q)
{ // affect the original

    // we can store the poped element in a vector then again make queue from it//here we can use stack also for stoting the popped element, push at front front required then

    vector<int> v;

    while (!Q.empty())
    {
        cout << Q.front() << " ";
        v.push_back(Q.front());
        Q.pop();
    }

    while (v.size())
    {
        Q.push(v.at(0));
        // vector delete from front
        v.erase(v.begin() + 0); //// This is O(n) operation for each element!
    }

    cout << endl;

    // Restore queue efficiently instead of using front pop in vector //simply we can iterate then clear all at once using vector.clear()
    // for (int val : v)
    // {
    //     Q.push(val);
    // }
}

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

void queueReverse(queue<int> Q)
{
    stack<int> st;
    while(!Q.empty()){
    st.push(Q.front());
    Q.pop();
    }

    while(!st.empty()){
        Q.push(st.top());
        st.pop();
    }

    printQueueWithoutExtra(Q);
}



// reverse first K element of queue
// we can store the first k in stack which has to be reversed and put other in vector, then combine, or we can push k in stack and then push as k from stack to the end, then remaining queue store time pushed at back and popped form front
void queueReverseK(queue<int> Q , int k)
{
    stack<int> st;

    while(k--){
    st.push(Q.front());
    Q.pop();
    }

    int remaining=Q.size();
    while(!st.empty()){
        Q.push(st.top());
        st.pop();
    }

    while(remaining--){
        Q.push(Q.front());
        Q.pop();
    }

    printQueueWithoutExtra(Q);
}



int main()
{
    queueArray Q(5);
    Q.push(4);
    Q.push(4);
    Q.push(4);
    Q.push(4);
    Q.push(4);
    Q.push(4);
    Q.pop();
    Q.pop();
    Q.pop();
    Q.pop();

    cout << Q.isEmpty() << endl; // 0 means no
    cout << Q.isFull() << endl;  //

    queueLinkedList Ql; // when no parameter then don't put empty here
    Ql.push(12);
    Ql.push(12);
    Ql.push(12);
    Ql.push(12);
    Ql.pop();

    Ql.pop();
    Ql.pop();
    Ql.pop();
    Ql.pop();

    Ql.push(12);
    Ql.push(12);
    Ql.push(12);

    // queue inbuilt implementation
    queue<int> Qin;
    Qin.push(12);
    Qin.push(13);
    Qin.push(14);
    Qin.push(15);
    Qin.push(16);
    cout << Qin.front() << endl;
    cout << Qin.back() << endl;
    cout << Qin.empty() << endl;
    cout << Qin.size() << endl;

    printQueue(Qin);

    printQueueRemain(Qin);

    printQueueWithoutExtra(Qin);


    queueReverse(Qin);
    queueReverseK(Qin,3);
}
