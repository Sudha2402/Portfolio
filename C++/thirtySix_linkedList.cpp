#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// linkedlist
// static without new node
// dynamic with new node

class Node
{
public:
    int data;
    Node *next; // next is a pointer pointing to node type value

    // empty constructor
    Node()
    {
    }

    Node(int val)
    {
        this->data = val;
        this->next = NULL; // Next will have this value, it it had to point some address then address would have been passed
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

// Add node at the end using recursion
Node *recursiveLinkedList(Node *head, Node *tail, int arr[], int i)
{
    if (i == 5)
    {
        // arr finizes
        return head;
    }

    if (head == NULL)
    {
        // we will create linkedlist
        head = new Node(arr[i]);
        tail = head;

        //  // You need to return recursiveLinkedList(...) to propagate head back up.
        // recursiveLinkedList(head, tail, arr, ++i);

        return recursiveLinkedList(head, tail, arr, ++i);
    }
    else
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
        // recursiveLinkedList(head, tail, arr, i++);//it will pass old value first then increment it//hence i revolve around only one index i=0 and keep repeating

        // when we don't need tail then
        // Node *curr = head;
        // while (head->next != nullptr)
        // { // Find tail
        //     curr = curr->next;
        // }
        //  curr->next = recursiveLinkedList(nullptr, arr, i + 1);

        // recursiveLinkedList(head, tail, arr, ++i);

        return recursiveLinkedList(head, tail, arr, ++i);
    }

    return head;

    // return is not necessary but as recursion creates stack hence , we should backup. from the top to down
}

// another way of creating linkedlist using recursion
Node *CreateLinkedList(int arr[], int index, int size)
{
    if (index == size)
    {
        return NULL;
    }

    Node *temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index + 1, size);
    return temp; // this is very important to return back to the head storing the next address in previous.

    // let index==5
    // returns Null, it will come in temp->next=CreateLinkedList(arr, index+1,size); and therafter, it has stored Null in itself->next, now it has to return it's own address to the last call and store it in tempnext hence tha address of this temp need to be stored so that it returns back

    // at the end , it will return head
}

// Recursion to add node in beginning
Node *CreateLinkedListAtFont(Node *head, int arr[], int index)
{
    if (index < 0)
    {
        return head;
    }

    Node *temp = new Node(arr[index]);
    temp->next = head; // at start head=null

    // head=temp;
    // head = CreateLinkedListAtFont(head,arr, index - 1);
    //   return head;
    // we can set it in one line

    return CreateLinkedListAtFont(temp, arr, index - 1);

    // same can be used to print in reverse, if index starts from 0
}

// Recursion reverse order array to linkedlist
Node *CreateLinkedListReverse(Node *head, int arr[], int index, int size)
{
    if (index == size)
    {
        return head;
    }

    Node *temp = new Node(arr[index]);
    temp->next = head; // at start head=null

    return CreateLinkedListReverse(temp, arr, index + 1, size); // 5 4 3 2 1
}

// insert at given index
Node *insertAtIndex(Node *head, int index, int val)
{
    Node *temp = new Node(val);
    Node *find = head;
    

    if (index == 0)
    {
        temp->next = head;
        head = temp;
        return head;
    }

    // int i = 0;
    // while (i != index - 1 && find->next)
    // {
    //     find = find->next;
    //     i++;
    // }


    // here instead of increasing temp this way, we could have done it in backward also
    --index;
    while (--index && find->next)
    {
        find = find->next;
    }

    temp->next = find->next;
    find->next = temp;
    return head;
}

int main()
{
    // statically created node
    Node obj;
    Node obj2;

    obj.data = 12;
    obj.next = &obj2;

    obj2.data = 13;
    obj2.next = NULL;

    cout << obj.data << endl;
    cout << obj.next << endl;       // 0x61ff00
    cout << obj.next->data << endl; // the address it point,get data value from there. //here obj.next.data can't work as obj.next itself is the address , means a kind of pointer pointing to the address like obj is a kind of object pointer containing the class object as pointer.//from the address itself, we use -> directly. as pointer stores the address then we reach using -> here as we get address hence it is used with -> //obj is not pointer, it is creates a copy of class.

    // obj is the object itself (not a pointer), but it behaves like a value.

    // When passed to a function, a copy is made (unless passed by reference).

    // We prefer to use constructor for creating a node
    Node obj3(14);
    cout << obj3.data << endl;
    cout << obj3.next << endl; // 0 shows null

    // Let's try dynamically created node
    Node *Head = new Node(15);
    cout << Head << endl;
    cout << Head->data << endl;
    cout << Head->next << endl;
    // cout<<Head->next->data<<endl; //as all pointers Head->next gives address

    // let's add a node in start

    // Node *Head;
    // Head=NULL;

    if (Head == NULL)
    {
        // it means linkedlist not exist
        Node *temp;
        temp = new Node(16);
        Head = temp;

        // here we can write the directly
        // Head=new Node(16);
    }
    else
    {
        Node *temp;
        temp = new Node(16);
        temp->next = Head; // temp is static hence removed automatically from stack but heap node not deleted.
        Head = temp;
    }

    cout << Head << endl;
    cout << Head->data << endl;
    cout << Head->next << endl;
    cout << Head->next->data << endl;

    // creating a linkedlist from an array
    int arr[5] = {1, 2, 3, 4, 5};

    // creating linkedList//we will follow insert at start
    Node *HeadLink;
    HeadLink = NULL;
    for (int i = 4; i >= 0; i--)
    {
        if (HeadLink == NULL)
        {
            HeadLink = new Node(arr[i]);
        }
        else
        {
            Node *temp = new Node(arr[i]);
            temp->next = HeadLink;
            HeadLink = temp;
        }
    }

    // let's print the linkedlist value
    printLinkList(HeadLink); // OK
    cout << endl;
    //
    //

    // inserting at the end
    // to insert a node at the end, we need to traverse to end, then start puting the answer.hence we will use a pointer temp to store the end address

    Node *HeadLinkBack;
    Node *tail;
    HeadLinkBack = NULL;
    for (int i = 0; i < 5; i++)
    {
        if (HeadLinkBack == NULL)
        {
            HeadLinkBack = new Node(arr[i]);
            tail = HeadLinkBack;
        }
        else
        {
            Node *temp = new Node(arr[i]);
            tail->next = temp;
            tail = tail->next;
        }
    }

    // let's print the linkedlist value
    printLinkList(HeadLinkBack); // OK
    cout << endl;
    //
    //
    //

    // Add node at end using recursion
    Node *recursiveHead = recursiveLinkedList(NULL, NULL, arr, 0);
    printLinkList(recursiveHead);
    cout << endl;

    //
    //
    //
    Node *recursiveHeadTrue = CreateLinkedList(arr, 0, 5);
    printLinkList(recursiveHeadTrue);
    cout << endl;
    //
    //
    //

    // Recursion to add node in beginning
    Node *recursiveAtStart = CreateLinkedListAtFont(NULL, arr, 4);
    printLinkList(recursiveAtStart);
    cout << endl;

    //
    //
    //
    // Recursion to add node in beginning
    Node *recursiveReverse = CreateLinkedListReverse(NULL, arr, 0, 5);
    printLinkList(recursiveReverse);
    cout << endl;
    //
    //
    //
    // insert at index
    // insertAtIndex(Node *head, int index, int val,int i)
    Node *InsertIndex = insertAtIndex(recursiveReverse, 0, 12); // insert 12 at index 0 //it will not update original recursiveReverse
    printLinkList(InsertIndex);
    cout << endl;

    printLinkList(recursiveReverse);
    cout << endl;

    recursiveReverse = insertAtIndex(recursiveReverse, 0, 12); // updates the main
    printLinkList(InsertIndex);
    cout << endl;
    printLinkList(recursiveReverse);
    cout << endl;

    recursiveReverse = insertAtIndex(recursiveReverse, 11, 12); // if it get's out of index then it will insert it at last not the 11 index
    printLinkList(recursiveReverse);
    cout << endl;
}