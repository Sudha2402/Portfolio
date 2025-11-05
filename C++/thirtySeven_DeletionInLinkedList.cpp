// Deletion in a Singly Linked List | Deletion in Constant Time

#include <iostream>
#include <vector>
#include <algorithm>

// deleting the first node in linkedlist takes O(1)
// to come back, we need to use linkedlist
// Even tail pointer will not help.


using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
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

Node *insertAtIndex(Node *head, int val, int index)
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

Node *DeleteAtFirst(Node *head)
{
    // if node not exist then delete not  work
    if (head == NULL)
    {
        return head;
    }

    Node *temp = head;
    cout << "Deleted data: " << temp->data << endl;

    if (head->next == NULL)
    {
        delete temp;
        head = NULL;
        return head;
    }

    head = head->next;
    //  delete the pointer temp node
    delete temp;

    return head;
}

// delete at last
Node *DeleteAtLast(Node *head)
{
    // if node not exist then delete not  work
    if (head == NULL)
    {
        return head;
    }
    else if (head->next == NULL)
    {
        // delete head;
        // head = NULL;
        // ❌ Cons if head is deleted directly:

        // If other pointers reference the old head, they become dangling pointers (undefined behavior if accessed).

        // Not thread-safe (another thread might access head between deletion and null assignment).

        // or
        Node *temp = head;
        head = NULL;
        delete temp;

        return head;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    cout << "Deleted data: " << temp->data << endl;

    //  delete the pointer temp node
    delete temp->next;

    temp->next = NULL;

    return head;
}

// delete at last
Node *DeleteAtLastTwoPointer(Node *head)
{ // don't forget to consider edge cases.

    // if node not exist then delete not  work
    if (head == NULL)
    {
        return head;
    }
    else if (head->next == NULL)
    {
        // delete head;
        // head = NULL; //OK but create problem when other pointer pointing to head

        Node *temp = head;
        head = NULL;
        delete temp;

        return head;
    }

    // this will not work for first node only
    Node *temp = head;
    Node *current = NULL; // it contains previous but currently become last after this
    while (temp->next != NULL)
    {
        current = temp;
        temp = temp->next;
    }
    cout << "Deleted data: " << current->data << endl;

    //  delete the pointer temp node
    delete temp;

    current->next = NULL;

    return head;
}

// delete the index
Node *DeleteAtIndex(Node *head, int pos)
{ // don't forget to consider edge cases.

    // if node not exist then delete not  work
    if (head == NULL || pos < 1)
    {

        cout << "Index out of range\n";
        return head;
    }

    Node *temp = head;
    Node *current = NULL;
    while (--pos && temp->next != NULL)
    {
        current = temp;
        temp = temp->next;
    }

    // deleting in between
    if (pos == 0 && current != NULL)
    {
        current->next = temp->next;
        delete temp;
    }

    // deleting the first node when head next present or not present does not matter
    // else if (current == NULL && pos == 0) // position is 1
    else if (pos == 0) // position is 1 , enough as out of range has pos not 0.//current will be always null when pos==0.

    {
        current = head->next;
        delete temp;
        head = current;
    }
    else
    { // pos !=0 //if we know the size then it could be directly in the first if
        cout << "Index out of range\n";
    }

    return head;
}

Node *DeleteAtIndexEdges(Node *head, int pos)
{ // don't forget to consider edge cases.//simpy adding edge cases

    // if node not exist then delete not  work
    if (head == NULL || pos < 1)
    {

        cout << "Index out of range\n";
        return head;
    }
    else if (pos == 1)
    { // to delete first position pointing to current next is not good as current will be null
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *current = NULL;
    while (--pos && temp->next != NULL)
    {
        current = temp;
        temp = temp->next;
    }
    if (pos != 0)
    { // pos !=0 //if we know the size then it could be directly in the first if
        cout << "Index out of range\n";
        return head;
    }

    current->next = temp->next;
    delete temp;

    return head;
}

// More simplified//index is pos-1
Node *DeleteAtIndexSimplify(Node *head, int pos)
{
    if (head == nullptr || pos < 0)
    {
        cout << "Index out of range\n";
        return head;
    }

    // Case: Delete head (pos = 0)
    if (pos == 0)
    {
        Node *newHead = head->next;
        delete head;
        return newHead; // new head will be head
    }

    // Traverse to the node before the target
    Node *prev = head;
    while (--pos > 0 && prev->next != nullptr)
    { // one index behind the pos index
        prev = prev->next;
    }

    // If position is out of bounds
    if (pos > 0 || prev->next == nullptr)
    {
        cout << "Index out of range\n";
        return head;
    }

    // Delete the target node
    Node *temp = prev->next;
    prev->next = temp->next;
    delete temp;

    return head;
}

//
// DeleteAtIndexRecursion(head,head, 2)
// Node *DeleteAtIndexRecursion(Node *head, Node *temp, int pos)
// {//head infext not needs

Node *DeleteAtIndexRecursion( Node *temp, int pos)
{//head infext not needs

    // if node not exist then delete not  work
    if (pos < 1 || temp == NULL)
    {
        cout << "Index out of range\n";
        return NULL;
    }

    else if (pos == 1)
    {
        Node *next = temp->next;
        delete temp;
        return next;
    }

    // OK
    // Node *prev = temp;
    // prev->next = DeleteAtIndexRecursion(head, temp->next, --pos);
    // return prev;

    // OR

    // temp->next = DeleteAtIndexRecursion(head, temp->next, --pos);
    temp->next = DeleteAtIndexRecursion(temp->next, --pos);
    return temp;


}





void deletePointedNode(Node *curr){

    Node *nextNode=curr->next;
    curr->data=nextNode->data;
    curr->next=nextNode->next;
    delete nextNode;

    while(curr !=NULL){ //to print the remaining after deleting all
        cout<<curr->data<<" ";
        curr=curr->next;

    }


}

int main()
{

    Node *linkedList = NULL;
    linkedList = insertAtIndex(linkedList, 20, 4);
    linkedList = insertAtIndex(linkedList, 8, 4);
    linkedList = insertAtIndex(linkedList, 7, 4);
    linkedList = insertAtIndex(linkedList, 30, 4);
    printLinkList(linkedList);
    cout << endl;

    linkedList = DeleteAtFirst(linkedList);
    printLinkList(linkedList);
    cout << endl;

    linkedList = DeleteAtLast(linkedList);
    printLinkList(linkedList);
    cout << endl;

    linkedList = DeleteAtLastTwoPointer(linkedList);
    printLinkList(linkedList);
    cout << endl;

    linkedList = DeleteAtLastTwoPointer(linkedList);
    printLinkList(linkedList);
    cout << endl;

    linkedList = insertAtIndex(linkedList, 20, 4);
    linkedList = insertAtIndex(linkedList, 8, 4);
    linkedList = insertAtIndex(linkedList, 7, 4);
    linkedList = insertAtIndex(linkedList, 30, 4);
    printLinkList(linkedList);
    cout << endl;

    linkedList = DeleteAtIndex(linkedList, 2);
    printLinkList(linkedList);
    cout << endl;

    linkedList = DeleteAtIndexEdges(linkedList, 1);
    printLinkList(linkedList);
    cout << endl;

    linkedList = DeleteAtIndexEdges(linkedList, 2);
    printLinkList(linkedList);
    cout << endl;

    linkedList = DeleteAtIndexEdges(linkedList, 2);
    printLinkList(linkedList);
    cout << endl;

    linkedList = DeleteAtIndexEdges(linkedList, 1);
    printLinkList(linkedList);
    cout << endl;

    linkedList = DeleteAtIndexEdges(linkedList, 1);
    printLinkList(linkedList);
    cout << endl;

    // let's solve deletion with the help of recursion
    linkedList = insertAtIndex(linkedList, 20, 4);
    linkedList = insertAtIndex(linkedList, 8, 4);
    linkedList = insertAtIndex(linkedList, 7, 4);
    linkedList = insertAtIndex(linkedList, 30, 4);
    printLinkList(linkedList);
    cout << endl;

    // linkedList = DeleteAtIndexRecursion(linkedList, linkedList, 2);
    // printLinkList(linkedList);
    // cout << endl;
    // linkedList = DeleteAtIndexRecursion(linkedList, linkedList, 2);
    // printLinkList(linkedList);
    // cout << endl;

    // linkedList = DeleteAtIndexRecursion(linkedList, linkedList, 1);
    // printLinkList(linkedList);
    // cout << endl;

    // linkedList = DeleteAtIndexRecursion(linkedList, linkedList, 2);
    // printLinkList(linkedList);
    // cout << endl;


    linkedList = DeleteAtIndexRecursion(linkedList, 2);
    printLinkList(linkedList);
    cout << endl;
    linkedList = DeleteAtIndexRecursion(linkedList, 2);
    printLinkList(linkedList);
    cout << endl;

    linkedList = DeleteAtIndexRecursion(linkedList, 1);
    printLinkList(linkedList);
    cout << endl;

    linkedList = DeleteAtIndexRecursion(linkedList, 2);
    printLinkList(linkedList);
    cout << endl;



     linkedList = insertAtIndex(linkedList, 20, 4);
    linkedList = insertAtIndex(linkedList, 8, 4);
    linkedList = insertAtIndex(linkedList, 7, 4);
    linkedList = insertAtIndex(linkedList, 30, 4);
    printLinkList(linkedList);
    cout << endl;

    // let's move to the prev from given pointer.
    cout<<linkedList<<endl;//0xfd1d70
    cout<<linkedList->next<<endl;//0xfd1da0

    Node *curr=linkedList->next;
    // Node *prev;
    // prev->next=curr;//just add a new pointer can't help

    // deleting the pointer node but not the last one as we can solve the node

    // We can't get head address from a pinter address//hence instead of moving back, we can move forward and copy the forward node data in current pointed node and delete the next node.

    // let's delete this curr
    deletePointedNode(curr);
printLinkList(linkedList);
    cout << endl;





    return 0;
}
