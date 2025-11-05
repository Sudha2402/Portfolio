// Doubly linked list
#include <iostream>
using namespace std;

// Double linked list is used in UNDO and REDO operation, where each node contains the current time data, then it moves to next node to fill the all chages+old.

// thare is a current pointer which traverse over the double linked list. If UNDO , then it displays the cuntent of prev, In case of REDO, next pointer works.

// INSERT
// DELETE
// Remove Dublicate

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = NULL;
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
}

Node *InsertAtStart(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {

        head = newNode;
        return head;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    return head;
}

Node *InsertAtEnd(Node *head, int val)
{

    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }

    newNode->prev = temp;
    temp->next = newNode;

    return head;
}

Node *InsertAtPos(Node *head, int val, int pos)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {

        head = newNode;
        return head;
    }

    else if (pos == 1)
    {

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }

    Node *temp = head;
    int count = 1;
    while (temp->next && count < pos - 1)
    { // we stop at one position back before the inserting index //we don't want the tempt to go and point out of index value
        temp = temp->next;
        count++; // checked how many nodes visited and covered before this current.
    }

    // Case 3: Position exceeds length+1 //it has not executed above loop upto end.
    if (count < pos - 1)
    {
        delete newNode; // Clean up//if you want still it to be insertd at last then that is eary.

        return head;
    }

    // Case 4: Valid middle/end insertion
    newNode->prev = temp;
    newNode->next = temp->next;
    if (temp->next)
    {                               // this position is not end position
        temp->next->prev = newNode; // note this as many times we forget to handle thsi case.
    }

    temp->next = newNode;

    return head;
}

// insert at position in simple way and one thought
Node *InsertAtPosSimple(Node *head, int val, int pos)
{
    if (pos < 1)
    {
        return head; // Invalid position
    }

    Node *newNode = new Node(val);

    if (head == NULL)
    {

        head = newNode;
        return head;
    }

    if (pos == 1)
    { // insert at start

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    else
    {

        // Traverse to position
        Node *temp = head;
        int count = 1;
        while (temp->next && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        // Case 3: Position exceeds length+1 //it has not executed above loop upto end.//it
        if (count < pos - 1)
        {
            delete newNode; // Clean up
            return head;
        }

        // inset at end
        // insert at mid

        newNode->prev = temp;
        newNode->next = temp->next;

        //   insert at mid
        if (temp->next)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    return head;
}

// delete the node
Node *DeleteAtStart(Node *head)
{

    if (head == NULL)
    {
        return head;
    }

    Node *temp = head->next;
    delete head;
    if (temp)
    {
        temp->prev = NULL;
    }
    head = temp;
    return head;
}

// delete the end
Node *DeleteAtEnd(Node *head)
{

    if (head == NULL)
    {
        return head;
    }

    // Single node case
    if (!head->next)
    {
        delete head;
        return nullptr;
    }

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }

    if (temp->prev)
    {
        temp->prev->next = NULL;
    }

    // if(temp->prev==NULL){ //for handling single node, we could have done it at top also
    //     head=NULL;
    // }

    delete temp;

    return head;
}

// Delete at position
Node *DeleteAtPos(Node *head, int pos)
{

    if (!head || pos < 1)
        return head;

    Node *temp = head;

    if (pos == 1)
    {
        // delete first position
        temp = head;
        head = head->next;
        if (head)
        { // Head not null
            head->prev = NULL;
        }
        delete temp;
        return head;
    }
    int count = 1;
    while (temp->next && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    // temp is element to be deleted
    if (count < pos - 1)
    {
        // if it is still less means pos greaer than length
        return head;
    }

    // delete the last position
    // delete middle position

    temp->prev->next = temp->next;

    if (temp->next)
    {
        temp->next->prev = temp->prev; // middle element deleted
    }
    delete temp;

    return head;
}

// doublelinkedlist using recursion
Node *doublyRecrFun(Node *doublyRecr, int arr[], int size, int i, Node *prevNode)
{
    if (i == size)
    {
        return NULL;
    }

    Node *newNode = new Node(arr[i]);
    newNode->prev = prevNode;
    newNode->next = doublyRecrFun(doublyRecr, arr, size, i + 1, newNode);
    return newNode;
}

// Using for loop to create doubly linkedlist from arr
Node *doublArr(int arr[], int size)
{
    if (size == 0)
        return NULL;
    Node *nextNode = NULL;

    for (int i = size - 1; i >= 0; i--)
    {
        Node *newNode = new Node(arr[i]);
        newNode->next = nextNode;
        if (nextNode)
        {
            nextNode->prev = newNode;
        }
        nextNode = newNode;
    }

    return nextNode;

    // OR use from forward
    
    // Node* head = new Node(arr[0]);
    //     Node* current = head;

    //     for (int i = 1; i < size; i++) {
    //         Node* newNode = new Node(arr[i]);
    //         newNode->prev = current;
    //         current->next = newNode;
    //         current = newNode;
    //     }

    //     return head;



}

int main()
{

    // Insert into a doublt linkedList
    Node *doubly = NULL;

    // Insert at start
    doubly = InsertAtStart(doubly, 30);
    printLinkList(doubly);
    cout << endl;
    doubly = InsertAtStart(doubly, 20);
    printLinkList(doubly);
    cout << endl;

    // Insert at end
    doubly = InsertAtEnd(doubly, 30);
    printLinkList(doubly);
    cout << endl;
    doubly = InsertAtEnd(doubly, 20);
    printLinkList(doubly);
    cout << endl;

    // insert at positition
    doubly = InsertAtPos(doubly, 30, 1); // now doubly points the head
    printLinkList(doubly);
    cout << endl;
    doubly = InsertAtPos(doubly, 20, 1);
    printLinkList(doubly);
    cout << endl;
    doubly = InsertAtPos(doubly, 10, 1);
    printLinkList(doubly);
    cout << endl;
    doubly = InsertAtPos(doubly, 40, 4);
    printLinkList(doubly);
    cout << endl;
    doubly = InsertAtPosSimple(doubly, 40, 4);
    printLinkList(doubly);
    cout << endl;
    doubly = DeleteAtStart(doubly);
    printLinkList(doubly);
    cout << endl;
    doubly = DeleteAtEnd(doubly);
    printLinkList(doubly);
    cout << endl;
    doubly = DeleteAtPos(doubly, 5);
    printLinkList(doubly);
    cout << endl;

    Node *doublyRecr = NULL;
    int arr[] = {9, 6, 3, 9, 5};
    // to create linked list from array
    // we coul have used for loop and recursion also
    doublyRecr = doublyRecrFun(doublyRecr, arr, sizeof(arr) / sizeof(arr[0]), 0, NULL);
    printLinkList(doublyRecr);
    cout << endl;

    Node *doublyArr = doublArr(arr, sizeof(arr) / sizeof(arr[0]));
    printLinkList(doublyArr);
    cout << endl;
}