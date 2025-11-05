#include <iostream>

#include <vector>

// heap implementation, insert, delete, built from array, sort it, traverse
// Priority Queue
// height of a heap , edges height count
// Minimum cost of Ropes
// Magician and Chocolates
// Last Stone Weight
// Take gift from richest pile
// profit maximization
// Kth Smallest Element
// Kth Largest Element
// Sum of elements between k1 and k2 smallest.
// Kth largest element in a stream
// Merge two binary max heap
// is binary tree heap
// level order traversal in spiral form using stack(2 stacks)  not vector or queue
// merge K sorted linkedlist to get new sorted linked list

using namespace std;

// let create a class of name heap
class MaxHeap
{

    int total_size;
    int size;
    // vector<int> arr;
    int *arr; // we want to allocate heap memory not the stack

public:
    MaxHeap(int tsize)
    {
        // value is going to be the heap size
        total_size = tsize;
        size = 0;
        arr = new int[total_size]; // CORRECTED: Use [] for array allocation
    }

    ~MaxHeap() // ADDED: Destructor to prevent memory leak
    {
        delete[] arr;
    }

    void insert(int value)
    { // method

        if (size == total_size)
        {
            cout << "Heap overflow\n";

            return;
        }

        arr[size] = value; // new elements fitted here then swapping takes place.

        int index = size;
        size++; // for next time insertion

        // compare with it's parent // current node ko insert kiya ja raha h, so rest positions has nothing to do. here heapify not used.

        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            // iterative approch and not take as space as

            // if parent is less than swap the values
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2; // this is the new index with which upper one will be compared, smaller is send to bottom, now bigger has to flow above.
        }

        cout << arr[index] << "is inserted into the heap\n"; // this index position changes is the new element we are floating to the top.
        cout << value << "is inserted into the heap\n";
    }

    void heapify(int nodeIndex)
    {
        bool swapped = false;

        // if (arr[nodeIndex] < arr[2 * nodeIndex + 1] && 2 * nodeIndex + 1 < size) //You're accessing the array element BEFORE checking the bounds! This can cause segmentation faults. //order mathers
        if (2 * nodeIndex + 1 < size && arr[nodeIndex] < arr[2 * nodeIndex + 1])
        {
            swap(arr[nodeIndex], arr[2 * nodeIndex + 1]);
            heapify(2 * nodeIndex + 1);
            // return;//once you enter the left child block, you never come back to check the right child at the same level.

            swapped = true;
        }
        // else if (2 * nodeIndex + 2 < size && arr[nodeIndex] < arr[2 * nodeIndex + 2] ) //else if which means it only checks the right child if the left child comparison fails. But you should check both children and swap with the larger one.

        if (2 * nodeIndex + 2 < size && arr[nodeIndex] < arr[2 * nodeIndex + 2])
        {
            swap(arr[nodeIndex], arr[2 * nodeIndex + 2]);

            heapify(2 * nodeIndex + 2);

            swapped = true;
        }

        // at last we have to verify the final after left swap and right swap from nodeIndex itself for final check.

        //         Initial:
        //       5
        //      / \
        //     7   8
        //    / \
        //   9   6

        //         8
        //      / \
        //     9   7   ← 9 > 8! Heap property violated!
        //    / \
        //   5   6

        if (swapped)
        {
            heapify(nodeIndex);
        }
    }

    // the above heapify method is very  inefficient and could cause infinite recursion! hence we check both left and right at the same time and select the max to swap with.
    void heapifyOpti(int nodeIndex)
    {
        int largest = nodeIndex;
        int left = 2 * nodeIndex + 1;
        int right = 2 * nodeIndex + 2;

        if (left < size && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }

        // we will swap with the largest
        if (largest != nodeIndex)
        {
            // largest is not the top hence we need to swap.
            swap(arr[largest], arr[nodeIndex]);
            heapifyOpti(largest); // this largest index will be new target
        }
    }

    // delete top or root node in max heap.
    void deleteTop()
    {
        if (size == 0)
        {
            // no element present, hence at start
            cout << "Heap is underflow\n";
            return;
        }

        int deletedNode = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = 0;
        size--;

        // after swapping, we need to adjust the correct position. hence we will use heapify method
        heapifyOpti(0);

        cout << deletedNode << "is deleted successfully" << endl;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        { // we are dealing with filled size not the total size of heap created // it is level wise print

            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

void heapifyUni(int arr[], int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // we will swap with the largest
    if (largest != i)
    {
        // largest is not the top hence we need to swap.
        swap(arr[largest], arr[i]);
        heapifyUni(arr, largest, n); // this largest index will be new target
    }
}

void BuildMaxHeap(int arr[], int n)
{
    // we will get the parent of last node. n nodes total and last node index is n-1, hence get it's parent node and that will be the start of swap.

    // current position se pura niche ka change hoga. heapify me koi change nahi hoga chahe koi bhi way choose karo.

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyUni(arr, i, n);
    }
}

// Sorting heap
void heapSort(int arr[], int n)
{
    BuildMaxHeap(arr, n); // ADDED: Must build heap first!

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        heapifyUni(arr, 0, i); // we are using step up , not from the n/2-1 node
    }
}

void printHeap(int arr[], int n)
{
    // let's print this heap also
    for (int i = 0; i < n; i++)
    { // we are dealing with filled size not the total size of heap created // it is level wise print

        cout << arr[i] << " ";
    }

    cout << endl;
}

// Priority Queue

// priority queue is the inbuilt implementation of max- heap
#include <bits/stdc++.h> //it includes all libraties like set, map, string, algoritnm, queue, vector etc.
#include <queue>         //needed for priority queue
#include <vector>

// height of a heap , edges height count
// we need to get the node index then we will get it's height. node(N) / 2^n = height. keep dividing by 2 and number of times we divide till answer is 1 is the height.

// int heapHeight(int arr[], int N)
int heapHeight(priority_queue<int> p, int N)
{

    // as per question
    if (N == 1)
    {
        return 1; // height is 1 for 1 node, here edge not checked
    }

    int height = 0;

    while (N > 1)
    {
        N /= 2;
        height++;
    }

    return height;
}

// Minimum cost of Ropes
long long int minCostRope(long long int arr[], long long int N)
{
    // N is the number of node or size of arr

    // convert array to min heap priority queue
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for (long long i = 0; i < N; i++)
    {
        minHeap.push(arr[i]);
    }

    long long cost = 0;
    // let's addup two min
    // while (N > 1)

    while (minHeap.size() > 1)
    {
        long long a = minHeap.top();
        minHeap.pop();
        long long b = minHeap.top();
        minHeap.pop();
        long long c = a + b;
        minHeap.push(c);

        cost += c;

        // N--;
    }

    // return minHeap.top(); // it will not work as we want to add rope addition price, here this way it is showing the total length prince not the cost, it's simply the addition of numbers but we want to add cost of adding two rope at a time and then combining.

    return cost;
}

// Magician and Chocolates
// we have to select maximum chocolate to eat and count as whole even if half ate and half placed again

int maxChoco(int A, vector<int> &arr)
{
    // A is the unit time we can eat the chocolate
    // creating max heap using priority queue
    priority_queue<int> p;
    for (int i = 0; i < arr.size(); i++)
    {
        p.push(arr[i]);
    }

    // let's evaluate

    long long int chocolates = 0;
    while (A-- && !p.empty())
    { // number of time keep decreasing

        int curr = p.top();
        chocolates += p.top();
        p.pop();
        p.push(curr / 2);
    }

    return chocolates % 1000000007; // modulus 10^9 + 7 given in the question
}

// Last Stone Weight
int lastStoneWeight(vector<int> &stones)
{

    priority_queue<int> p;
    for (int i = 0; i < stones.size(); i++)
    {
        p.push(stones[i]);
    }

    while (p.size() > 1)
    {
        int x = p.top();
        p.pop();
        int y = p.top();
        p.pop();

        if (x != y)
        {
            p.push(x - y);
        }
    }

    // return p.top(); //it is possible that it become 0 lke for arr={2,2}. hence p emty then ans should be 0.
    return !p.empty() ? p.top() : 0;
}

// Take gift from richest pile

// profit maximization
int maxProfit(int A, vector<int> &arr)
{ // array shows empty seat in index row

    priority_queue<int> p;
    for (int i = 0; i < arr.size(); i++)
    {
        p.push(arr[i]);
    }

    // let's evaluate

    long long int profitCost = 0;

    while (A-- && !p.empty())
    { // number of buyers keep decreasing

        int curr = p.top();
        profitCost += p.top();
        p.pop();

        if (curr - 1)
            p.push(curr - 1); // avoid pushing 0
    }

    return profitCost; // modulus 10^9 + 7 given in the question
}

// Kth Smallest Element
int kthSmallest(int arr[], int l, int r, int K)
{
    // l and r is start and end index of arr
    //  k is the position smallest we need to get
    //  we could have sort it then get k-1 index value.

    // we are creating max heap and we will keep size of k and compare the new element with max and if new is smaller then keep it in the heap and pop the largest

    priority_queue<int> p;
    for (int i = l; i < K && K <= r; i++)
    {
        p.push(arr[i]); // k elements pushed
    }

    for (int i = K; i <= r; i++)
    {
        if (arr[i] < p.top())
        {
            p.pop();
            p.push(arr[i]);
            // this way we want heap to contain  K smallest only. hence at last Kth smallest is the top element of this max heap
        }
    }

    return (p.size() == K) ? p.top() : -1;
}

// Kth Largest Element
int kthLargest(int arr[], int l, int r, int K)
{

    // we are creating min heap and we will keep size of k and compare the new element with min and if new is larger then keep it in the heap and pop the smallest or top.

    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = l; i < K && K <= r; i++)
    {
        p.push(arr[i]); // k elements pushed
    }

    for (int i = K; i <= r; i++)
    {
        if (arr[i] > p.top())
        {

            p.pop();
            p.push(arr[i]);

            // this way we want heap to contain  K smallest only. hence at last Kth smallest is the top element of this max heap
        }
    }

    return (p.size() == K) ? p.top() : -1;
}

// Kth largest element in a stream

// Input: arr[] = [10, 20, 5, 15], k = 2
// Output: -1 10 10 15
// Explanation: First insertion gives -1 as fewer than 2 elements. After second, 2nd largest is 10. Then still 10. After inserting 15, elements are [10, 20, 5, 15]; 2nd largest is now 15.

vector<int> kthLargestStream(int arr[], int N, int K)
{
    priority_queue<int, vector<int>, greater<int>> p;

    vector<int> ans;
    for (int i = 0; i < K - 1 && K < N; i++)
    {

        p.push(arr[i]); // k elements pushed
        ans.push_back(-1);
    }

    // we want to push the actual kth largest in the vector for ans
    p.push(arr[K - 1]);     // it is k-1 because of indexing
    ans.push_back(p.top()); // K the max is being pushed

    for (int i = K; i < N; i++)
    {
        if (arr[i] > p.top())
        {

            p.pop();
            p.push(arr[i]);

            // this way we want heap to contain  K smallest only. hence at last Kth smallest is the top element of this max heap
        }

        ans.push_back(p.top());
    }

    return ans;
}

// Sum of elements between k1 and k2 smallest.
long long sumBetweenTwoKth(long long arr[], long long N, long long K1, long long K2)
{
    // n is the size of array
    if (K1 > K2)
    {
        swap(K1, K2); // we want K2 > K1
    }

    priority_queue<int> p1;

    for (int i = 0; i < K1 && K1 < N; i++)
    {
        p1.push(arr[i]); // k elements pushed
    }

    for (int i = K1; i < N; i++)
    {
        if (arr[i] < p1.top())
        {
            p1.pop();
            p1.push(arr[i]);
            // this way we want heap to contain  K1 smallest only. hence at last Kth smallest is the top element of this max heap
        }
    }

    // creating p2
    priority_queue<int> p2;
    for (int i = 0; i < K2 && K2 < N; i++)
    {
        p2.push(arr[i]); // k2 elements pushed
    }

    for (int i = K2; i < N; i++)
    {
        if (arr[i] < p2.top())
        {
            p2.pop();
            p2.push(arr[i]);
            // this way we want heap to contain  K2 smallest only. hence at last Kth smallest is the top element of this max heap
        }
    }

    // perform sum of both heap and take difference
    long long Sum = 0;

    // we have to exclude the largest also hence first pop one time in p2
    p2.pop();

    while (p2.size())
    {
        Sum += p2.top();
        p2.pop();
    }

    while (p1.size())
    {
        Sum -= p1.top();
        p1.pop();
    }

    return Sum;
}

// Merge two binary max heap
vector<int> mergeheaps(vector<int> &a, vector<int> &b)
{
    vector<int> ans;

    for (int i = 0; i < a.size(); i++)
    {
        ans.push_back(a[i]);
    }

    for (int i = 0; i < b.size(); i++)
    {
        ans.push_back(b[i]);
    }

    // now answer is a simple array, we have to create max heap.
    int N = ans.size();
    // convert vector to arr;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = ans[i];
    }

    for (int i = N / 2 - 1; i >= 0; i--)
    {
        heapifyUni(arr, i, N);
    }

    for (int i = 0; i < N; i++)
    {
        ans[i] = arr[i];
    }

    return ans;
}

// for checking tree and heap relationship

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Node *createTreeSideRec(int val)

Node *createTreeSideRec()
{ // instead of taking val from start , we can take from inside also
    int val;
    cin >> val;
    if (val == -1)
    {
        return NULL;
    }

    Node *parent = new Node(val);
    cout << "Enter the left element of " << parent->data << ":";
    // cin >> val;
    parent->left = createTreeSideRec();

    cout << "Enter the right element of " << parent->data << ":";
    // cin >> val;
    parent->right = createTreeSideRec();

    return parent;
}

// In order Traversal
void InOrder(Node *parent)
{
    if (parent == NULL)
    {
        return;
    }

    // Here we are returnig from check statement in everyline, we can use in one line return as if node itself is null then returned
    if (parent->left != NULL)
    {
        InOrder(parent->left);
    }
    cout << parent->data << " ";
    if (parent->right != NULL)
    {
        InOrder(parent->right);
    }
}

int count(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

int isCBT(Node *root, int index, int total_Nodes)
{
    if (!root)
    {
        return true; // NULL node is fine for CBT
    }

    if (index >= total_Nodes)
    {
        return 0; // this is final return and it has to flow through all nodes /// This returns 0 but doesn't stop recursion
    }

    return isCBT(root->left, 2 * index + 1, total_Nodes) && isCBT(root->right, 2 * index + 2, total_Nodes); // I thought of his but didn't implement it initially
}

bool maxHeap(Node *root)
{

    // root null // Leaf node - always satisfies heap property
    if (!root)
    {
        return 1;
    }

    // Case 1: Leaf node (both children NULL) //we can add this check at start also
    if (!root->left && !root->right)
    {
        return true;
    }

    // left child exist only
    // if (root->left && !root->right && root->data > root->left->data) {  don't add check condition in the para instead use in the return && itself

    if (root->left && !root->right)
    {
        return root->data >= root->left->data && maxHeap(root->left);
    }

    // right child exist only
    if (!root->left && root->right)
    {
        return root->data >= root->right->data && maxHeap(root->right);
    }

    // both child exist
    if (root->left && root->right)
    {
        return root->data >= root->left->data && root->data >= root->right->data && maxHeap(root->left) && maxHeap(root->right);
    }

    // return 0 for other cases as child will be less than root
    return 0; //// Should never reach here //we can simply call this in the very start also and as else case not need to write the && in return itself shows 1 or 0.
}

// or simplified way
bool maxHeapSimple(Node *root)
{
    if (!root)
        return true;

    // Check left child
    if (root->left && root->data < root->left->data)
        return false;

    // Check right child
    if (root->right && root->data < root->right->data)
        return false;

    // Recursively check both subtrees
    return maxHeapSimple(root->left) && maxHeapSimple(root->right);
}

// is binary tree heap

bool isBinaryHeap(Node *tree)
{
    if (!tree)
    {
        return true; // Empty tree is technically a heap
    }

    // count nodes in the tree
    int num = count(tree);
    cout << "\ncount of nodes : " << num << endl;

    bool ans = isCBT(tree, 0, num);
    if (!ans)
    {
        return 0;
    }

    // return maxHeap(tree);
    return maxHeapSimple(tree);
}

//  level order traversal in spiral form using stack(2 stacks)  not vector or queue
vector<int> spiralOrderTraversal(Node *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }

    stack<Node *> s1; // for left to right
    stack<Node *> s2; // for right to left

    // for stack we needed two stacks doing alternate push and pop

    // if we have used dequeue then one one que enough as we can use push front and push back. just size check and then pop from front or back accordingly.

    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {

        // left to right
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            ans.push_back(temp->data);

            if (temp->left)
            {
                s2.push(temp->left);
            }
            if (temp->right)
            {
                s2.push(temp->right);
            }
        }

        // right to left
        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            ans.push_back(temp->data);

            if (temp->right)
            {
                s1.push(temp->right);
            }
            if (temp->left)
            {
                s1.push(temp->left);
            }
        }
    }

    return ans;
}

// merge K sorted linkedlist to get new sorted linked list

// here instead of directly using inbuilt greater<Node *> we will create our own comparator class

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data; // min heap
    }
};

Node *mergekLists(Node *arr[], int K)
{
    // K is the number of linked list
    // we will use min heap to get the smallest element at top and keep adding to the new linked list

    priority_queue<Node *, vector<Node *>, Compare> minHeap;

    // push all linked list addresses not the values, hence we will extract later on.

    for (int i = 0; i < K; i++)
    {
        if (arr[i] != NULL)
        {
            minHeap.push(arr[i]);
        }
    }

    Node *head = NULL;
    Node *tail = NULL;

    while (!minHeap.empty())
    {
        Node *temp = minHeap.top(); // temp is the node address of linkedlist complete connected.
        minHeap.pop();

        // add this to the new linked list
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->right = temp; // as it is linked list using right pointer
            tail = tail->right;
        }

        // now push the next element of this linked list to the heap
        if (temp->right != NULL)
        {
            minHeap.push(temp->right); // it will be new node address in the min heap of complete folowed up list. here sorting is done on the bases of this head address value data hence we created compare class.
        }
    }

    return head;
}

int main()
{

    MaxHeap H1(6);
    H1.insert(12);
    H1.insert(11);
    H1.insert(1);
    H1.insert(1);
    H1.insert(31);
    H1.insert(21);
    H1.insert(16);
    H1.insert(28);

    H1.print();

    H1.deleteTop();
    H1.deleteTop();
    H1.deleteTop();
    H1.print();

    // build maxheap in O(n) from given array /. use step down. down ko step karo means, comparision starts from bottom to top.

    int arrElement[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    int length = sizeof(arrElement) / sizeof(arrElement[0]);
    BuildMaxHeap(arrElement, length);
    printHeap(arrElement, length);
    // 70 14 18 11 5 13 8 9 10 3 //solution

    heapSort(arrElement, length);
    printHeap(arrElement, length); // 3 5 8 9 10 11 13 14 18 70

    // Priority Queue
    cout << "Priority queue \n";
    priority_queue<int> p;
    p.push(12);
    p.push(2);
    p.push(121);
    p.push(122);
    p.push(1);

    cout << p.top() << endl;
    cout << p.size() << endl;

    // Delete
    p.pop();
    cout << p.size() << endl;

    // to get all the traversing element not possible in inbuilt data structure.
    while (!p.empty())
    {
        cout << p.top() << " "; // shows the max element first which is the top //121 12 2 1
        p.pop();
    }
    cout << endl;

    // min heap

    // Declare a min-heap priority queue
    // Syntax: priority_queue<Type, Container, Comparator>
    // Type: The type of elements to store (e.g., int, double, custom objects)
    // Container: The underlying container to use (e.g., vector, deque)
    // Comparator: A function object that defines the ordering (e.g., greater for min-heap)
    // priority_queue<int, vector<int>, greater<int>> minHeap;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert elements into the min-heap
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);
    minHeap.push(1);
    minHeap.push(15);

    // Extract elements from the min-heap (will be in ascending order)
    cout << "Elements extracted from the min-heap: ";
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " "; // Access the smallest element
        minHeap.pop();                // Remove the smallest element
    }
    cout << endl;

    // height of a heap
    p.push(12);
    p.push(2);
    p.push(121);
    p.push(122);
    p.push(1);
    cout << "heap height : " << heapHeight(p, p.size()) << endl; // 2

    // Minimum cost of Ropes
    long long int arr[] = {4, 3, 2, 6};
    cout << "Minimum cost of Ropes : " << minCostRope(arr, sizeof(arr) / sizeof(arr[0])) << endl; // 29

    // Magician and Chocolates
    int A = 5;
    vector<int> B = {2, 4, 6, 8, 10};
    cout << "Maximum chocolate ate : " << maxChoco(A, B) << endl; // 33

    // Last Stone Weight
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << "last stone weight : " << lastStoneWeight(stones) << endl; // 1

    // Take gift from richest pile

    // profit maximization
    A = 3; // number of people to sold the ticket
    vector<int> seats = {2, 3};
    cout << "Maximum profit : " << maxProfit(A, seats) << endl; // 7

    // Kth Smallest Element
    int l = 0, r = 5;
    int arrSmall[] = {7, 10, 4, 3, 20, 15};
    int K = 3;
    cout << K << "th Smallest Element : " << kthSmallest(arrSmall, l, r, K) << endl; // 7

    // Kth Largest Element
    l = 0, r = 8;
    int arrLarge[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    K = 4;
    cout << K << "th Largest Element : " << kthLargest(arrLarge, l, r, K) << endl; // 4

    // Sum of elements between k1 and k2 smallest.
    long long int arrKSum[] = {20, 8, 22, 4, 12, 10, 14};
    int K1 = 3, K2 = 6;
    int N = sizeof(arrKSum) / sizeof(arrKSum[0]);
    cout << "Sum between Kth Smallest Element : " << sumBetweenTwoKth(arrKSum, N, K1, K2) << endl; // 26

    // Kth largest element in a stream
    K = 2;
    int arrStream[] = {10, 20, 5, 15};
    N = sizeof(arrStream) / sizeof(arrStream[0]);
    vector<int> ans = kthLargestStream(arrStream, N, K);

    cout << "Kth largest in stream : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // Merge two binary max heap
    vector<int> a = {10, 6, 6, 2};
    vector<int> b = {12, 7, 9};
    ans = mergeheaps(a, b);
    int arrMerge[ans.size()];
    cout << "merged max heap : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // is binary tree heap
    cout << "Enter the root element :";
    Node *root = createTreeSideRec();
    cout << "Ilevel print: ";
    InOrder(root);

    if (isBinaryHeap(root))
    {
        cout << "It is binary heap\n";
    }
    else
    {
        cout << "It is not binary heap\n";
    }

    // level order traversal in spiral form using stack(2 stacks)  not vector or queue
    ans.clear();
    ans = spiralOrderTraversal(root);
    cout << "Spiral order traversal : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // merge K sorted linkedlist to get new sorted linked list

    int Klists;
    cout << "Enter the number of linked list to be merged :";
    cin >> Klists;
    Node *listArr[Klists];
    for (int i = 0; i < Klists; i++)
    {
        cout << "Enter the linked list " << i + 1 << " elements :";
        listArr[i] = createTreeSideRec(); // reusing the same function to create linked list using right pointer
    }
    Node *mergedHead = mergekLists(listArr, Klists);
    cout << "Merged linked list : ";
    InOrder(mergedHead); // reusing inorder function to print linked list using right pointer
    cout << endl;

    return 0;
}