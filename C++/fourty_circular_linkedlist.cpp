// Circulat linked list.
// insert at given index

// in circular linkedlist loop related question is asked.
// detect loop in the linkedlist.

//  // we can use map(dictionary) also where insted index, we used the name of the data and then put it's corresponding value

//  Floyd's Cycle-Finding Algorithm to detect and remove a loop

// Intersection in Y shaped linkedlist

// need to be solved
// Add two numbers

// multipy two numbers

// reverse a linkedlist ingroup of size

// flattening a linkedlist
// we thought of one more way where when greater in bottom is found then , it's right position is founded.

// Merge K Sorted LinkedList
// use merge sort for merging K sorted linkedlist.

// make clone of linkedlist with next and random pointer

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

class Node
{
public:
    int data;

    Node *next;
    Node *hori; // for flattening type question
    Node *rand; // for random pointer used in cloning
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// print the linkedlist
void printLinkList(Node *head)
{
    Node *temp = head;
    // while (temp != NULL)
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printLinkListCir(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head;

    // cout << temp->data << " ";
    // temp = temp->next;
    // while (temp != head)
    // {
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }

    // here as we need to do it once , hence we can use do while loop
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

// index not pos
Node *insertAtIndex(Node *head, int index, int val)
{
    Node *temp = new Node(val);

    // Node *find = head;
    // Node *tail = head;

    if (head == NULL)
    {
        // head = temp;
        // tail = head;
        // head->next = head;
        //   return head;

        temp->next = temp;
        return temp;
    }

    Node *tail = head;
    int count = 1;
    while (tail->next != head)
    {
        tail = tail->next;
        count++;
    }
    //  when tail reaches to it's position where tail->next is head

    if (index > count - 1 || index < 0)
    {
        cout << "index out of bound.\n";
        return head;
    }

    if (index == 0)
    {
        temp->next = head;
        head = temp;
        tail->next = head;
        return head;
    }

    // for index insert not position
    // if position then further --index
    Node *find = head;
    while (--index && find->next != head)
    {
        find = find->next;
    }

    // Insert at other positions
    // Node* temp = head;
    // for (int i = 0; i < index - 1; i++) {
    //    temp = temp->next;
    // }

    temp->next = find->next;
    find->next = temp;

    return head;
}

Node *insertAtIndexLinear(Node *head, int val, int index)
{
    Node *temp = new Node(val);
    Node *find = head;

    if (index == 0 || head == NULL)
    {
        temp->next = head;
        head = temp;
        return head;
    }

    temp->next = find->next;
    find->next = temp;
    return head;
}

// check is loop in linkedlist

bool isVisited(vector<Node *> visited, Node *temp)
{

    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == temp)
        {
            return 1;
        }
    }

    return 0;
}

int isLoop(Node *head)
{
    vector<Node *> visited; // adress of node
    Node *temp = head;

    while (temp)
    { // if no loop then it will have end as NULL , hence it can terminate
        if (!isVisited(visited, temp))
        {
            visited.push_back(temp);
            temp = temp->next;
        }
        else
        {
            return 1; // yes loop present
        }
    }

    return 0;
} // time complexity O(n*n)

// to check loop using map method
int isLoopUsingMap(Node *head)
{
    // map
    unordered_map<Node *, bool> visited;
    Node *temp = head;

    while (temp)
    { // if no loop then it will have end as NULL , hence it can terminate
        if (visited[temp] == 1)
        {
            return 1;
        }
        else
        {
            visited[temp] = 1;
            temp = temp->next;
        }
    }

    return 0;
} // time complexity O(n) //as checking into map takes O(1) time

// this map take space complexity O(n)//hence we need to solve it in both O(n) time and O(1) space complexity

int isLoopOptTwoPointer(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    // here as two pointers used where fast moves at 2x and slow just one step. hence when fast get's into loop, it will neccessary somethime collapse with the slow as slow moves one , fast moves double, hence we can think that fast is moving twix=ce than slow to cover the gap hence distance between them keep decresing by one as effective distance is moved by fast one step forward.and fast approcahes to slow somethime neccessarily //as effective step is taken by fast 1 steps, hennce it will catch slow in the single loop iteration of slow, but fast is iteratiing second time

    // when ever effective gap is decreasing by one then faster will catch the slower necessarily. even if slow forward than faster in loop.

    // it is just like two person starting the game from same point on circular track, find the point they met togeter or time.

    while (fast != NULL && fast->next != NULL)
    { // if fast is null , then checking it's next will be terminated

        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        { // we want first set then compare, if compared first then as we initialed at same point then it will always be corrected.
            return 1;
        }
    }

    return 0;
}

// Count the number of nodes in loop.
int countNodeInLoop(Node *head)
{

    // first check if loop present using slowe and fast pointer
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    { // if fast is null , then checking it's next will be terminated

        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        { // we want first set then compare, if compared first then as we initialed at same point then it will always be corrected.
            break;
        }
    }

    // we will break if we found fast == slow// now we need to check again because break could be because of fast != NULL && fast->next != NULL also

    if (fast == slow)
    {
        // start counting by moving fast till it comes to the slow position
        int count = 1;
        fast = fast->next;
        while (fast != slow)
        {
            count++;
            fast = fast->next;
        }

        return count;
    }

    // if fast != NULL && fast->next != NULL
    return 0;
}

// Detyect and remove loop.
// we nee to remove from end point.
// first find if loop exist.

// we need to find the loop head.
// from slow==fast, we can move the fast or slow any one pointer to head of linkedlist. then start moving to next one by one step.  the same pointed node is head node of loop. then again move to the end of loop to point it to NULL

// we can also proof using methematics how starting from first and till to common point makes it same in count

//  Floyd's Cycle-Finding Algorithm to detect and remove a loop

void removeLoop(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return; // No loop possible
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {

        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }

    if (fast != slow)
    {
        return;
    }
    // start moving fast from pointing to head and this slow from current  till it comes to the same node

    //     // Find loop start
    fast = head;
    while (fast != slow)
    {

        fast = fast->next;
        slow = slow->next;
    }

    // now ater loop fast and slow points to same node i.e start of loop

    // now move the the end of loop to point it to next

    while (fast->next != slow)
    {
        fast = fast->next;
    }

    fast->next = NULL; // // Break the loop

    // here we can;t think of taking fast to NULLthen move one by one and stop one step before. It will not work in circular loop, with not linear part.//as start and end cons to the head itself. then taking fast to head then comparing will work at it initail position as head is fast als and slow als. hence setting fast->next will not work, dirctly without comming to common point of loop, then moving again to find the end. then point to next.
}

// here for removing the loop , we can also use the loop gap as number of nodes in the loop and then keeping the fast start from there and then traversing one step for both slow and fast helps in finding the start of loop.

void removeLoopUsingGap(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return; // No loop possible
    }

    Node *slow = head;
    Node *fast = head;

    //  // Detect loop using Floyd's algorithm
    while (fast != NULL && fast->next != NULL)
    {

        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }

    if (fast != slow)
    {
        return;
    }

    // start counting by moving fast till it comes to the slow position
    int count = 1;
    fast = fast->next;
    while (fast != slow)
    {
        count++;
        fast = fast->next;
    }

    // start moving fast from pointing to head and this slow from current  till it comes to the same node

    fast = head;
    slow = head;
    // move the fast to the point where count gap canbe maintained

    while (--count)
    { // count-- will make it exactly maintain the gap of 9, fast points to 9th position //The while (--count) moves fast to exactly count-1 nodes ahead //The subsequent synchronization happens to find the correct break point
        fast = fast->next;
    }

    // here we don't find the start of loop then travese to find the end, gap just before helps here as we can stop the fast one point prier then the metup.

    while (fast->next != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = NULL;
}

// to find the intersetion node
// we can use map also.
//  we can use map where one head is taversed and set the visited map data as 1 then second head travese and check if same name present then that will be intersection node.
// we can use count length approch, then find the diiference between lenghth then move forward
// we have already solve the question to find the loop head, hence that loop head is intersetion point. for that we coudl have made any one node tail point to the last and make it circular.

Node *intersectionNode(Node *linearLinkedPure, Node *linearLinkedPure2)
{

    if (!linearLinkedPure || !linearLinkedPure2)
        return NULL; // Edge case:

    // let's solve with difference length
    Node *head1 = linearLinkedPure;
    Node *head2 = linearLinkedPure2;

    Node *temp = head1;
    int count1 = 0;

    while (temp)
    {
        count1++;
        temp = temp->next;
    }

    temp = head2;
    int count2 = 0;

    while (temp)
    {
        count2++;
        temp = temp->next;
    }

    // find the difference to reposition the heads so that then it satart checking itsel
    int move = 0;
    if (count1 > count2)
    {
        // move count by move
        move = count1 - count2;
        while (move--)
        {
            head1 = head1->next;
        }
    }
    else
    {
        move = count2 - count1;
        while (move--)
        {
            head2 = head2->next;
        }
    }

    // now heads have reached to it's position ,we can use traversing

    // while (head1 && head2 &&  head1 != head2) // loop already guarantees that both pointers will reach NULL simultaneously (if no intersection exists), so the additional checks are redundant.

    while (head1 != head2)
    { // NULL == NULL is true, so the loop exits.
        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1 == NULL)
    {
        return NULL;
    }

    return head1;
}

// Now sloving it by making loop.
Node *intersectionNodeLoop(Node *linearLinkedPure, Node *linearLinkedPure2) // Is optimally efficient (O(n) time, O(1) space). //Handles all Y-shaped cases (including edge cases).
{

    if (!linearLinkedPure || !linearLinkedPure2)
        return NULL; // Edge case:

    // let's solve with difference length
    Node *head1 = linearLinkedPure;
    Node *head2 = linearLinkedPure2;

    Node *temp = head1;

    // This is destructive and unacceptable in real-world use (the original list structure is lost).
    // Only Works if Lists Already Share a Common Tail

    while (temp->next)
    {

        temp = temp->next;
    }

    Node *tail = temp;
    temp->next = head1;

    // now head2 will be the start of tyhis loop linkedlist
    Node *head = head2;
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {

        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }

    if (fast != slow)
    {
        tail->next = NULL;
        return NULL;
    }
    // start moving fast from pointing to head and this slow from current  till it comes to the same node

    //     // Find loop start
    fast = head;
    while (fast != slow)
    {

        fast = fast->next;
        slow = slow->next;
    }

    tail->next = NULL;
    return fast;
}

// Reverse the linkedlist
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *fur;

    while (curr)
    {
        fur = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fur;
    }

    return prev;
}

// Add two numbers present in linkedlist, then return the linked list of the answer.
Node *Add(Node *head1, Node *head2)
{

    // we need to reverse the numbers as addition takes place from back
    Node *ans = new Node(-1);

    Node *temp = ans;
    head1 = reverse(head1);
    printLinkList(head1);
    head2 = reverse(head2);
    printLinkList(head2);

    Node *unitVal;

    int val, unit, carry = 0;

    // Add one by one
    while (head1 && head2)
    {
        val = head1->data + head2->data + carry;
        unit = val % 10;
        carry = val / 10;

        unitVal = new Node(unit);
        temp->next = unitVal;
        temp = temp->next;

        head1 = head1->next;
        head2 = head2->next;
    }

    // if head1 left or head 2 left, then if carry left
    while (head1)
    {
        val = carry + head1->data;
        unit = val % 10;
        carry = val / 10;
        unitVal = new Node(unit);
        temp->next = unitVal;
        temp = temp->next;
        head1 = head1->next;
    }
    while (head2)
    {
        val = carry + head2->data;
        unit = val % 10;
        carry = val / 10;
        unitVal = new Node(unit);
        temp->next = unitVal;
        temp = temp->next;
        head2 = head2->next;
    }

    // if carry left
    if (carry)
    {
        unitVal = new Node(carry);
        temp->next = unitVal;
        temp = temp->next;
    }

    // remove the head of ans
    temp = ans;
    ans = ans->next;
    delete temp;

    ans = reverse(ans); // reverse the answer

    return ans;
}

// Mul two numbers present in linkedlist, then return the linked list of the answer.
Node *MUL(Node *head1, Node *head2)
{

    // we need to reverse the numbers as addition takes place from back
    Node *ans = new Node(-1);

    Node *temp = ans;

    head1 = reverse(head1);
    printLinkList(head1);

    head2 = reverse(head2);
    printLinkList(head2);

    Node *unitVal;

    int val, unit, carry = 0;

    // Add one by one

    Node *Multiplicant = head1;

    Node *fixed = ans;

    while (head2)
    {
        head1 = Multiplicant;
        temp = fixed;

        while (head1)
        {
            if (temp->next)
            {
                val = head1->data * head2->data + carry + temp->next->data;
            }
            else
            {
                val = head1->data * head2->data + carry;
            }

            unit = val % 10;
            carry = val / 10;

            if (temp->next)
            {
                temp->next->data = unit;
            }
            else
            {
                unitVal = new Node(unit);
                temp->next = unitVal;
            }

            temp = temp->next;
            head1 = head1->next;
        }

        while (carry)
        {
            if (temp->next)
            {
                temp->next->data = carry % 10 + temp->next->data;
            }
            else
            {
                unitVal = new Node(carry % 10);
                temp->next = unitVal;
            }

            temp = temp->next;
            carry = carry / 10;
        }

        printLinkList(ans); // one row ans

        head2 = head2->next;

        fixed = fixed->next; // this position value wil be finalized//it points NULL
    }

    printLinkList(ans);

    // remove the head of ans
    temp = ans;
    ans = ans->next;
    delete temp;

    ans = reverse(ans); // reverse the answer

    return ans;
}

// reverse in group
Node *reverseInGroup(Node *head, int k)
{

    // let's reverse inbetween pattern first to observe the pointers use

    // first next creates problem hence let's take dummy node
    Node *ans = new Node(-1);
    Node *first, *second, *third, *fourth;

    first = ans;
    first->next = NULL;
    second = head;
    int count;

    while (second)
    {
        count = k;
        third = second;
        while (--count && third->next)
        {
            third = third->next;
        }
        fourth = third->next;
        third->next = NULL;

        second = reverse(second);

        first->next = second;
        while (second->next != NULL)
        {
            second = second->next;
        }
        second->next = fourth;
        first = second;
        second = fourth;
        first->next = NULL;
    }

    // remove the head of ans
    first = ans;
    ans = ans->next;
    delete first;

    return ans;
}

// merge soreted linkedlist together
Node *merge(Node *head1, Node *head2)
{
    Node *first = head1;
    Node *second = head2;
    Node *ans = new Node(-1);
    Node *tail = ans;
    while (first && second)
    {
        if (first->data <= second->data)
        {
            tail->next = first;
            tail = tail->next;
            first = first->next;
            tail->next = NULL;
        }
        else
        {
            tail->next = second;
            tail = tail->next;
            second = second->next;
            tail->next = NULL;
        }
    }

    while (first)
    {
        tail->next = first;
        tail = tail->next;
        first = first->next;
        tail->next = NULL;
    }

    while (second)
    {
        tail->next = second;
        tail = tail->next;
        second = second->next;
        tail->next = NULL;
    }

    first = ans;
    ans = ans->next;
    delete first;

    return ans;
}





Node *flatten(Node *head)
{
    // we have to flattern this next and hori toghether
    Node *root = head;
    // this root will move horizontally combine two together
    Node *rootNextHori = root->hori;
    root->hori = NULL;

    while (root && rootNextHori)
    {                                     // O(k)//lets n is number of linkedlist
        root = merge(root, rootNextHori); // O(2m) //let's length of each linked list is m node. //let's we have n linkedlist //next time merging takes 2M+M=3M comparisions for 3rd n..

        // m + 2m + 3M+ 4M.... +nm= O(n*2) approx
        rootNextHori = rootNextHori->hori;
        root->hori = NULL;
    }
    // total time complexity= O(n^3)
    // Space complexity=O(1)

    return root;
}



// her as it is linkedlist, so we can suffle the linked list by this when next node elemtn greatewr than the bottom, then move this bottom till the and at it;s correct position horizontally. then comparison taks place with next node bottom and insertion manually.

// we could have implemented this way also.





Node *mergetFlatterningArr(vector<Node *> arr)
{ // O(n^3)
    // we get the arr of head
    Node *root = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        root = merge(root, arr[i]);
    }

    return root;
}

// let's Optimize the flatening by using merge sort.//we keep diving then combine //let's do this in new form of data when number of linkedlist is know, earlier we need one count loop to get n or k value.

// let's take array containing head of all linkedlist totak k in numbers let.

Node *mergeSortFlatterning(vector<Node *> arr, int start, int end)
{
    // we get the arr of head

    // we will recursively call this function then merge
    // mergesort has not linearly merges .It merges in breakdown arr[0] and arr[1] merged together and arr[2] and arr[3] merged together and store in arr[2 ], how fursther new arr[0] and arr[2] merges. here legth of linkedlist after megining not increases linearly, instead partition are combined seperately then join to form upper head. Hence nodes are equally distributed.
    // total nodes present at each level is 8m. where m is number of node in one linkedlist seperatel.

    // Hence time complexity kmlogk., let m ans k same => (n^2 )*logn
    // here k is number of head nodes/ linkedlist/array size

    if (start >= end)
    {
        return NULL;
    }

    int mid = start + (end - start) / 2; // exactly the middle index is pointed by it.

    mergeSortFlatterning(arr, start, mid);
    mergeSortFlatterning(arr, mid + 1, end);      // return NULL from Last
    arr[start] = merge(arr[start], arr[mid + 1]); // merges two linkedlist at a time // here arr[mid + 1] used because we are putting the computed at the start hence for new one mid+1 constains the start of last time
    return arr[start];
}

//
//
// Clone a linkedlist with next and rand pointers
// for now as we have used hori, we can consider using it here also//let's make rand as new node in class Node
//
//
Node *CloneLinkedList(Node *head)
{
    // here we are having next and rand pointer.
    // for rand, we can use linear search which will make it O(n^2) for each

    if (head == NULL)
    {
        return NULL;
    }

    Node *clone = new Node(-1);
    Node *clonetail = clone;

    Node *temp = head;
    while (temp)
    {
        clonetail->next = new Node(temp->data);
        clonetail = clonetail->next;
        temp = temp->next;
    }

    // remove ths extra clone point
    temp = clone;
    clone = clone->next;
    delete temp;

    Node *point = head;
    temp = point; // now fill the random pointer

    Node *clonepoint;
    clonepoint = clone;
    Node *clonetemp = clonepoint;

    while (point)
    { // O(n^2)
        // int count = 0;

        while (point->rand && temp != point->rand)
        {
            temp = temp->next;
            clonetemp = clonetemp->next;
            //  count++;
        }

        if (point->rand && temp == point->rand)
        {
            clonepoint->rand = clonetemp;
        }

        point = point->next;
        temp = point;
        clonepoint = clonepoint->next;
        clonetemp = clonepoint;
    }

    return clone;
}

// Optimized O(n) Time Solution (Hash Map) //address of both stored as clone
// #include <unordered_map>

Node *CloneLinkedListUsingHashMap(Node *head)
{
    if (!head)
        return nullptr;

    unordered_map<Node *, Node *> nodeMap; // Original → Clone mapping
    Node *cloneHead = nullptr;
    Node *cloneTail = nullptr;

    // First pass: Create clone nodes and build the map
    Node *curr = head;
    while (curr)
    {
        Node *newNode = new Node(curr->data);
        nodeMap[curr] = newNode;

        if (!cloneHead)
        {
            cloneHead = newNode;
            cloneTail = newNode;
        }
        else
        {
            cloneTail->next = newNode;
            cloneTail = newNode;
        }
        curr = curr->next;
    }

    // Second pass: Assign random pointers
    curr = head;
    Node *cloneCurr = cloneHead;
    while (curr)
    {
        cloneCurr->rand = nodeMap[curr->rand]; // O(1) lookup
        curr = curr->next;
        cloneCurr = cloneCurr->next;
    }

    return cloneHead;
}

//
//
// cloning in O(n) time where we play a trick when we put the clone node just after the real node then pluck it to original after assigning rand pointer
//
Node *CloneCopy(Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }

    Node *clone = NULL;
    Node *clonetail = clone;

    Node *temp = head;
    while (temp)
    {
        if (!clonetail)
        {
            clone = new Node(temp->data);
            clonetail = clone;
        }
        else
        {
            clonetail->next = new Node(temp->data);
            clonetail = clonetail->next;
        }
        temp = temp->next;
    }

    // let's set the clone inbetween the original

    Node *point = head;
    Node *clonepoint = clone;
    Node *clonetemp;

    while (point)
    {
        temp = point->next; // now fill the random pointer
        clonetemp = clonepoint->next;
        point->next = clonepoint;
        clonepoint->next = temp;

        point = temp;
        clonepoint = clonetemp;
    }

    // combined linkedlist is formed now with copy in between
    // now mark the random pointer in one iteration
    point = head;

    while (point)
    {
        if (point->rand)
        {
            point->next->rand = point->rand->next;
        }

        point = point->next->next;
    }

    // now remove the clone from inbetween
    point = head;
    clone = point->next;
    clonetail = clone; // new need to remove this later

    while (point)
    {
        // using point->next for tails needs needs dummy node creation hence , we will use the collect from next
        clonetail->next = clonetail->next->next;

        point->next = point->next->next;

        clonetail = clonetail->next;
        point = point->next;
    }

    // // just remove first clone node
    // clonetail = clone;
    // clone = clone->next;
    // delete clonetail;

    return clone;
}

int main()
{

    Node *cirLink = NULL;
    cirLink = insertAtIndex(cirLink, 0, 1);
    cirLink = insertAtIndex(cirLink, 0, 2);
    cirLink = insertAtIndex(cirLink, 0, 3);
    cirLink = insertAtIndex(cirLink, 0, 4);
    cirLink = insertAtIndex(cirLink, 0, 5);
    cirLink = insertAtIndex(cirLink, 0, 6);
    printLinkListCir(cirLink);

    Node *linearLinked = NULL;
    linearLinked = insertAtIndexLinear(linearLinked, 1, 1);
    linearLinked = insertAtIndexLinear(linearLinked, 2, 2);
    linearLinked = insertAtIndexLinear(linearLinked, 3, 3);
    linearLinked = insertAtIndexLinear(linearLinked, 4, 4);
    linearLinked = insertAtIndexLinear(linearLinked, 5, 5);
    printLinkList(linearLinked);

    Node *tail = linearLinked;
    while (tail->next)
    {
        tail = tail->next;
    }

    cout << tail->data << endl;

    tail->next = cirLink;

    // printLinkList(linearLinked);//as it will be caught in circular, hence printing creates error

    // 1 5 4 3 2 -> (6 5 4 3 2 1 ).
    // it will firm a loop with head pointer at start linearLinked

    Node *linearLinkedPure = NULL;
    linearLinkedPure = insertAtIndexLinear(linearLinkedPure, 1, 1);
    linearLinkedPure = insertAtIndexLinear(linearLinkedPure, 2, 2);
    linearLinkedPure = insertAtIndexLinear(linearLinkedPure, 3, 3);
    linearLinkedPure = insertAtIndexLinear(linearLinkedPure, 4, 4);
    linearLinkedPure = insertAtIndexLinear(linearLinkedPure, 5, 5);
    printLinkList(linearLinkedPure);

    // As now this linkedlist contains loop, hence we need to find the loop in the list.

    // we canuse vector to store the address of all visited
    cout << "loop present: " << isLoop(linearLinked) << endl;     // 1
    cout << "loop present: " << isLoop(cirLink) << endl;          // 1
    cout << "loop present: " << isLoop(linearLinkedPure) << endl; // 0

    // we can use map(dictionary) also where insted index, we used the name of the data and then put it's corresponding value

    // we can use mapping which store the address as name

    cout << "loop present : " << isLoopUsingMap(linearLinkedPure) << endl;     // 0
    cout << "loop present: " << isLoopOptTwoPointer(linearLinkedPure) << endl; // 0

    //   count the nodes in loop
    cout << "Count loop: " << countNodeInLoop(linearLinked) << endl; // 0
    cout << "Count loop: " << countNodeInLoop(cirLink) << endl;      // 0
    cout << "loop present: " << isLoop(cirLink) << endl;             // 1 '

    removeLoop(cirLink); // it removes the loop in this, hence we can check using

    // removeLoopUsingGap(cirLink);//it passes the cases but we will check from the loopcode

    //    check loop again in this
    cout << "loop present: " << isLoop(cirLink) << endl; // 0//  now loop is removed

    // removeLoopUsingGap(cirLink);

    // Intersection in Y shaped linkedlist
    // for make this we can simply point the end of one linked list to any position other than last and first in another linkedlist.

    Node *linearLinkedPure2 = NULL;
    linearLinkedPure2 = insertAtIndexLinear(linearLinkedPure2, 1, 1);
    linearLinkedPure2 = insertAtIndexLinear(linearLinkedPure2, 2, 2);
    linearLinkedPure2 = insertAtIndexLinear(linearLinkedPure2, 3, 3);
    linearLinkedPure2 = insertAtIndexLinear(linearLinkedPure2, 4, 4);
    linearLinkedPure2 = insertAtIndexLinear(linearLinkedPure2, 5, 5);
    printLinkList(linearLinkedPure2);

    tail = linearLinkedPure2;
    while (tail->next)
    {
        tail = tail->next;
    }

    tail->next = linearLinkedPure->next->next;
    // Now our Y shaped linkedlist is ready

    printLinkList(linearLinkedPure);  // 1 5 4 3 2
    printLinkList(linearLinkedPure2); // 1 5 4 3 2 4 3 2

    //      1
    //      5
    //      4
    //      3
    //      2
    // 1 5->4->3 2

    // this will be the pattern of Y

    // to return the intersetion point.
    // we can use map where one head is taversed and set the visited map data as 1 then second head travese and check if same name present then that will be intersection node.

    Node *intes = NULL;

    cout << intersectionNode(linearLinkedPure, linearLinkedPure2) << endl; // 0x1091810
    intes = intersectionNode(linearLinkedPure, linearLinkedPure2);
    if (intes != NULL)
    {
        cout << intes->data << endl;
    }

    intes = NULL;
    cout << intersectionNodeLoop(linearLinkedPure, linearLinkedPure2) << endl; // 0x1091810
    intes = intersectionNodeLoop(linearLinkedPure, linearLinkedPure2);
    if (intes != NULL)
    {
        cout << intes->data << endl;
    }
    cout << endl;

    // Add two numbers
    printLinkList(linearLinkedPure); // 1 5 4 3 2

    Node *linearLinkedPure3 = NULL;
    linearLinkedPure3 = insertAtIndexLinear(linearLinkedPure3, 9, 1);
    linearLinkedPure3 = insertAtIndexLinear(linearLinkedPure3, 2, 2);
    linearLinkedPure3 = insertAtIndexLinear(linearLinkedPure3, 3, 3);
    linearLinkedPure3 = insertAtIndexLinear(linearLinkedPure3, 9, 4);
    linearLinkedPure3 = insertAtIndexLinear(linearLinkedPure3, 5, 5);

    printLinkList(linearLinkedPure3); // 1 5 4 3 2
    Node *addAns = NULL;
    addAns = Add(linearLinkedPure, linearLinkedPure3);
    printLinkList(addAns); // 111364

    // we can solve multiplication also.

    Node *linearLinkedPure4 = NULL;
    linearLinkedPure4 = insertAtIndexLinear(linearLinkedPure4, 9, 1);
    linearLinkedPure4 = insertAtIndexLinear(linearLinkedPure4, 2, 2);
    linearLinkedPure4 = insertAtIndexLinear(linearLinkedPure4, 3, 3);
    linearLinkedPure4 = insertAtIndexLinear(linearLinkedPure4, 9, 4);
    linearLinkedPure4 = insertAtIndexLinear(linearLinkedPure4, 5, 5);
    Node *linearLinkedPure5 = NULL;
    linearLinkedPure5 = insertAtIndexLinear(linearLinkedPure5, 9, 1);
    linearLinkedPure5 = insertAtIndexLinear(linearLinkedPure5, 2, 2);
    linearLinkedPure5 = insertAtIndexLinear(linearLinkedPure5, 3, 3);
    linearLinkedPure5 = insertAtIndexLinear(linearLinkedPure5, 9, 4);
    linearLinkedPure5 = insertAtIndexLinear(linearLinkedPure5, 5, 5);
    printLinkList(linearLinkedPure4); // 9 5 9 3 2
    printLinkList(linearLinkedPure5); // 9 5 9 3 2
    Node *mulAns = NULL;
    mulAns = MUL(linearLinkedPure4, linearLinkedPure5); // 9 2 0 2 9 4 8 6 2 4
    printLinkList(mulAns);                              // 9 2 0 2 9 4 8 6 2 4

    // reverse a linkedlist ingroup of sizes
    // let sizes i k=4

    Node *linearLinkedPure6 = NULL;
    linearLinkedPure6 = insertAtIndexLinear(linearLinkedPure6, 9, 1);
    linearLinkedPure6 = insertAtIndexLinear(linearLinkedPure6, 2, 2);
    linearLinkedPure6 = insertAtIndexLinear(linearLinkedPure6, 3, 3);
    linearLinkedPure6 = insertAtIndexLinear(linearLinkedPure6, 9, 4);
    linearLinkedPure6 = insertAtIndexLinear(linearLinkedPure6, 5, 5);
    linearLinkedPure6 = insertAtIndexLinear(linearLinkedPure6, 9, 1);
    linearLinkedPure6 = insertAtIndexLinear(linearLinkedPure6, 2, 2);
    linearLinkedPure6 = insertAtIndexLinear(linearLinkedPure6, 3, 3);
    linearLinkedPure6 = insertAtIndexLinear(linearLinkedPure6, 9, 4);
    linearLinkedPure6 = insertAtIndexLinear(linearLinkedPure6, 5, 5);
    printLinkList(linearLinkedPure6); // reverse this in group of k

    linearLinkedPure6 = reverseInGroup(linearLinkedPure6, 4);
    printLinkList(linearLinkedPure6);

    // flattening a sorted linkedlist
    // combine two at a time //merge
    // use mergesort

    Node *linearLinkedPure7 = NULL;
    linearLinkedPure7 = insertAtIndexLinear(linearLinkedPure7, 41, 0);
    linearLinkedPure7 = insertAtIndexLinear(linearLinkedPure7, 22, 0);
    linearLinkedPure7 = insertAtIndexLinear(linearLinkedPure7, 13, 0);
    linearLinkedPure7 = insertAtIndexLinear(linearLinkedPure7, 9, 0);
    linearLinkedPure7 = insertAtIndexLinear(linearLinkedPure7, 5, 0);
    printLinkList(linearLinkedPure7); // 5 9 13 22 41

    Node *linearLinkedPure8 = NULL;
    linearLinkedPure8 = insertAtIndexLinear(linearLinkedPure8, 41, 0);
    linearLinkedPure8 = insertAtIndexLinear(linearLinkedPure8, 22, 0);
    linearLinkedPure8 = insertAtIndexLinear(linearLinkedPure8, 13, 0);
    linearLinkedPure8 = insertAtIndexLinear(linearLinkedPure8, 8, 0);
    linearLinkedPure8 = insertAtIndexLinear(linearLinkedPure8, 7, 0);
    printLinkList(linearLinkedPure8); // 5 9 13 22 41

    Node *linearLinkedPure9 = NULL;
    linearLinkedPure9 = insertAtIndexLinear(linearLinkedPure9, 41, 0);
    linearLinkedPure9 = insertAtIndexLinear(linearLinkedPure9, 22, 0);
    linearLinkedPure9 = insertAtIndexLinear(linearLinkedPure9, 13, 0);
    linearLinkedPure9 = insertAtIndexLinear(linearLinkedPure9, 9, 0);
    linearLinkedPure9 = insertAtIndexLinear(linearLinkedPure9, 8, 0);
    printLinkList(linearLinkedPure9); // 5 9 13 22 41

    // merge all three linkedlist and store here in mergelist
    Node *mergedList = NULL;
    // let's combine all three as new connected linkedlist 2D

    mergedList = linearLinkedPure7;
    mergedList->hori = linearLinkedPure8;
    mergedList->hori->hori = linearLinkedPure9;

    // now we have made it connected in form of bottom(next) , hori(size wise)

    // mergedList = merge(linearLinkedPure7, linearLinkedPure8);
    mergedList = flatten(mergedList);
    printLinkList(mergedList);

    //

    printLinkList(linearLinkedPure7);
    printLinkList(linearLinkedPure8);
    printLinkList(linearLinkedPure9);

    // let we have these three
    // 5 7 8 8 9 9 13 13 13 22 22 22 41 41 41
    // 7 8 8 9 9 13 13 13 22 22 22 41 41 41
    // 8 9 9 13 13 13 22 22 22 41 41 41

    Node *linearLinkedPure10 = NULL;
    linearLinkedPure10 = insertAtIndexLinear(linearLinkedPure10, 41, 0);
    linearLinkedPure10 = insertAtIndexLinear(linearLinkedPure10, 22, 0);
    linearLinkedPure10 = insertAtIndexLinear(linearLinkedPure10, 13, 0);
    linearLinkedPure10 = insertAtIndexLinear(linearLinkedPure10, 9, 0);
    linearLinkedPure10 = insertAtIndexLinear(linearLinkedPure10, 5, 0);
    printLinkList(linearLinkedPure10); // 5 9 13 22 41

    Node *linearLinkedPure11 = NULL;
    linearLinkedPure11 = insertAtIndexLinear(linearLinkedPure11, 41, 0);
    linearLinkedPure11 = insertAtIndexLinear(linearLinkedPure11, 22, 0);
    linearLinkedPure11 = insertAtIndexLinear(linearLinkedPure11, 13, 0);
    linearLinkedPure11 = insertAtIndexLinear(linearLinkedPure11, 8, 0);
    linearLinkedPure11 = insertAtIndexLinear(linearLinkedPure11, 7, 0);
    printLinkList(linearLinkedPure11); // 5 9 13 22 41

    Node *linearLinkedPure12 = NULL;
    linearLinkedPure12 = insertAtIndexLinear(linearLinkedPure12, 41, 0);
    linearLinkedPure12 = insertAtIndexLinear(linearLinkedPure12, 22, 0);
    linearLinkedPure12 = insertAtIndexLinear(linearLinkedPure12, 13, 0);
    linearLinkedPure12 = insertAtIndexLinear(linearLinkedPure12, 9, 0);
    linearLinkedPure12 = insertAtIndexLinear(linearLinkedPure12, 8, 0);
    printLinkList(linearLinkedPure12); // 5 9 13 22 41

    // now lets stoere the head in arr
    vector<Node *> arrmerg;
    arrmerg.push_back(linearLinkedPure10);
    arrmerg.push_back(linearLinkedPure11);
    arrmerg.push_back(linearLinkedPure12);

    // let's use mergesort on this to flattern the linkedlist
    // sorted in the same way virtically and top horizontal.
    mergedList = NULL;

    // mergedList = mergetFlatterningArr(arrmerg);//O(n^3)
    // printLinkList(mergedList);

    mergedList = mergeSortFlatterning(arrmerg, 0, arrmerg.size() - 1); // 5 7 8 8 9 9 13 13 13 22 22 22 41 41 41
    printLinkList(mergedList);
}