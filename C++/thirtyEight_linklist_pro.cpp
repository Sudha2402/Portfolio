#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
    }
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
    // cout<<endl;
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

    temp->next = newNode;

    return head;
}

Node *DeleteAtIndexRecursion(Node *temp, int pos)
{
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

    temp->next = DeleteAtIndexRecursion(temp->next, --pos);
    return temp;
}

//
Node *reverseLinkList(Node *head)
{
    // we need to revers
    vector<int> arr;
    Node *temp = head;
    while (temp)
    {
        // insert at beginning in vector
        arr.insert(arr.begin() + 0, temp->data);
        temp = temp->next;
    }

    temp = head;
    for (int i = 0; i < arr.size(); i++)
    {
        temp->data = arr[i];
        temp = temp->next;
    }

    return head;
}

// If we need to reverse the address also
// we can do with inserting elements in new linkedlist at start
Node *reverseLinkListWithTwoPointer(Node *head)
{

    Node *temp = head;
    Node *prev = NULL;
    // Node *curr=NULL;
    Node *future = NULL;

    while (temp)
    {
        // curr = temp;
        // curr->data = temp->data;
        // curr->next = prev;//current next and temp next are same address, hence chaging the next value will update the orginal linkedlist array als.//as it update the direct address stored, hence stor the next address in new pointer.

        Node *future = temp->next; // next address is store so that temp can start back from here as next elemet not the direct prev value.

        temp->next = prev;

        prev = temp;
        // temp = temp->next;
        temp = future;
    }

    // head = curr;

    return prev;
}

// reverse the linkedlist using recursion
// here future line can be stored just below the recursive line.
// we have three pointer prev, curr, fur
// prev val return can be recursive
Node *reverseLinkedListRecursion(Node *prev, Node *curr)
{

    if (curr == NULL)
    {
        return prev;
    }

    Node *fur = curr->next;
    curr->next = prev;
    // theafter we need// prev=curr,  curr=fur
    //    we will do this using parameter in function
    // prev=curr;
    // curr=fur;
    // return reverseLinkedListRecursion(prev,curr); //we could have done this directly,

    return reverseLinkedListRecursion(curr, fur); // recursion here is just like loop just pass the updated value directly in terms of return.
}

// return the address of middle element.
// we need to count the total number of node
Node *middleElement(Node *head)
{
    // here we needed two time traversal, can we solve in O(n)//we will try this time to solve in one traversal with the help of pseudo pointer.

    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    // middle will be half of this
    temp = head;
    int middle = count / 2; // steps to move
    while (middle--)
    {
        temp = temp->next;
    }

    return temp;
}

// pseudo pointer to find Middle of linkedlist
Node *middleElementPseudo(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    // while (fast != NULL && fast->next != NULL ) //make sure to used && in this case as If fast is NULL, fast->next will crash (dereferencing NULL).
    while (fast && fast->next)
    {
        // fast null needed when fast->next has only one element as fast takes 2 jump, it will give null for second jump

        fast = fast->next->next;
        slow = slow->next;
    }

    cout << slow << endl;

    return slow;
}

// rotate list by k
Node *rotateByK(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    // we can use pseudo pointer where jump to the last take place with the help of k
    // Node *first = head;
    // Node *endterm = head;
    // move endterm as as k

    // we can even count the total then divide it by size the move from start.
    // k%size//take this remainder index from back.

    int count = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }

    k = k % count;
    if (k == 0)
        return head; // No rotation needed

    int firstPosition = count - k; // last now//we could have simply used the old value count-=k;

    Node *newend = head;

    while (--firstPosition)
    { // here we used direct method where this newend will be end value and it's next moves to head and tail attach to head, here we have found one step prior tha k so that we can handle with one pointer. //we could have also used two pointer prev and curr //curr will move to the index which is going to be first now and prev will be end of list.
        newend = newend->next;
    }

    temp->next = head; // we had reserved the temp detains from count, hence we need not to traverse again to get the tail address
    head = newend->next;
    newend->next = NULL;

    return head;
}

// rotate list by k
Node *rotateByKTwoPointer(Node *head, int k)
{

    if (head == NULL || k == 0)
        return head; // Edge cases

    Node *fast = head;
    Node *slow = head;

    int slide = k;
    // as we are not using count then we need to use circular traversal, hence it would be better to use count.

    // while (slide-- && fast->next != NULL)
    // {
    while (slide--)
    {
        if (!fast->next)
        {
            fast = head; // Loop back if needed //remove this from main while
            continue;    // otherwise we will move twice instead of once
        }
        fast = fast->next; // it
    } // first time first and endterm at proper gap k.

    // if (slide != -1)
    // {//in case of circular, it is not needed//infext it is not needed at all even here as if k is in the count term as per length then this will never happen
    //     cout << "out of range\n";
    //     return head;
    // }

    // Move both until fast reaches end//slixe it simply , not jump
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    fast->next = head;
    head = slow->next;
    slow->next = NULL;

    return head;
}

// Remove Nth Node from end
Node *removeNEnd(Node *head, int n)
{
    if (head == NULL)
    { // Edge case: empty list
        cout << "List is empty\n";
        return NULL;
    }

    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    // n fro end will be count-n position from where all happens

    temp = head;

    int find = count - n;
    if (n > count)
    {
        cout << "Out of range\n";
        return head;
    }
    else if (find == 0)
    {
        // remove the first
        // temp at head
        head = temp->next;
        delete temp;
        return head;
    }

    while (--find > 0)
    {
        temp = temp->next;
    }
    Node *del = temp->next;
    temp->next = del->next;
    delete del;

    return head;
}

// Solve using two pointer to remove N end //
Node *removeNEndTwoPointer(Node *head, int n)
{
    if (!head)
        return NULL;

    Node *fast = head, *slow = head;
    // Move fast `n` steps ahead
    while (n--)
    {
        if (!fast)
            return head; // n > length
        fast = fast->next;
    }

    // If fast is NULL, delete head
    if (!fast)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    // Move both until fast reaches end
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the target node
    Node *del = slow->next;
    slow->next = del->next;
    delete del;

    return head;
}

// to delete every k node
Node *removeEveryKNode(Node *head, int k)
{

    if (!head || k <= 0)
        return head; // Edge cases

    int count;
    Node *prev = NULL;
    Node *curr = head;

    while (curr)
    {
        count = k - 1;
        if (count == 0)
        {
            // remove every 1 element
            head = curr->next;
            delete curr;
            curr = head;
            continue;
        }
        while (count-- && curr->next)
        {
            prev = curr;
            curr = curr->next;
        }

        if (count == -1)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }

        else
        {
            return head;
        }
    }

    return head;
}

// above approch has many issue, hence we will use modulus method to solve it
Node *removeEveryKNodeCount(Node *head, int k)
{
    if (!head || k <= 0)
        return head; // Edge cases

    Node *prev = NULL;
    Node *curr = head;
    int count = 1; // Tracks position (1-based)

    while (curr)
    {
        if (count % k == 0) // here instead of modulous we could have also re-initialized it.//count=1//if count =k then work

        { // Delete every k-th node
            if (prev)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                // reinitialize, count=1 if another approch is using
            }
            else
            { // Deleting head //as previous would have been null
                head = curr->next;
                delete curr;
                curr = head;
                // count=1//   // reinitialize, count=1 if another approch is using
            }
        }
        else
        { // Move forward
            prev = curr;
            curr = curr->next;
        }

        count++;
    }

    return head;
}

// Check Palindrome
// I will take O(n^2)
int Palidrome(Node *head)
{
    //
    if (head == NULL || head->next == NULL)
        return 1;

    Node *end = head;
    Node *first = head;
    int count = 1;

    while (end->next != NULL)
    {
        end = end->next;
        count++;
    }

    while (count > 0)
    {
        Node *end = first;
        int temp = count;
        while (--temp)
        {
            end = end->next;
        }
        if (first->data == end->data)
        {
            first = first->next;
            count -= 2; // as when count is 1, then fursther decrement will make it negative
        }
        else
        {
            return 0;
        }
    }

    return 1; // palindrome
}

// when you have got stuch with any problems in linkedlist but you think , this could have been done using array or vector then try in that way as it will take less time complexity but takes space complexity more, still we prefer fast

// check palindrome using vector
int isPalidrome(Node *head)
{
    //
    if (head == NULL)
        return 1;

    Node *end = head;
    vector<int> linkedListarr;
    linkedListarr.push_back(end->data);

    while (end->next != NULL)
    {
        end = end->next;
        linkedListarr.push_back(end->data);
    }

    int size = linkedListarr.size();
    int first = 0;
    int last = size - 1;
    while (last > first)
    {

        if (linkedListarr[first] == linkedListarr[last])
        {
            first++;
            last--;
        }
        else
        {
            return 0;
        }
    }
    return 1; // palindrome
}

// check palindrome by reversing after middle
int isPalidromeByReverse(Node *head)
{

    if (head == NULL || head->next == NULL)
        return 1; // empty is palindrome

    // find the middle node

    Node *fast = head;
    Node *slow = head;

    // we also need to break the connection before middle so that we can iterate
    Node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = NULL;
    // the possition of slow is mid
    Node *middle = slow;

    cout << middle->data << endl; //

    //     First half: 1 → 2 → NULL
    // Middle: 3 → NULL
    // Second half: 2 → 1

    // Split the list into two halves
    // if (fast != NULL) //ok
    Node *secondHalf = slow;
    if (fast->next == NULL)
    { //// Odd-length: Skip the middle node
        // odd must have come //fast next comes null in odd hence stops there
        secondHalf = slow->next; // so that middle elemetns remain. it is not neccessaty
    }

    // we need to reverse it
    // we can use three pointer
    prev = NULL;
    Node *curr = secondHalf;
    Node *fur = NULL;
    while (curr != NULL)
    {
        fur = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fur;
    }

    // Note:Your middle-finding logic works correctly for both odd and even lengths, but the reversal and comparison part may fail for odd-length lists because the middle node is included in the reversed half. For odd-length palindromes, the middle node should be ignored during comparison (since it doesn't need to match anything).

    secondHalf = prev;

    cout << secondHalf->data << endl;
    printLinkList(secondHalf);
    cout << endl;

    Node *first = head;
    while (secondHalf != NULL && first != NULL)
    // while (first != NULL)
    {
        // Your comparison loop while (first != NULL) assumes secondHalf is at least as long as first. If the original list has an odd length, secondHalf will be one node longer than first, and secondHalf->data could be accessed when secondHalf is NULL (though your current loop stops when first is NULL, so this might not crash but could miss some cases).

        // incase of odd number of elements, we left comparing the od one with extra length, instead we can reverse from secondHalf next in case of odd., odd can be found with fast ==NULL//we can handle above

        if (secondHalf->data == first->data)
        {
            secondHalf = secondHalf->next;
            first = first->next;
        }
        else
        {
            return 0;
        }
    }

    return 1; // palindrome
}

// in short above method here
int isPalindromeOptimized(Node *head)
{
    if (!head || !head->next)
        return 1; // empty or single-node list is palindrome

    // Find middle using fast-slow pointers
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    Node *prev = NULL, *curr = slow, *next;
    while (curr)
    { // as this slow is the middle element.//reverse starting fom middle
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Compare first half and reversed second half
    Node *left = head, *right = prev;
    while (right)
    {
        if (left->data != right->data)
            return 0;
        left = left->next;
        right = right->next;
    }

    return 1; // palindrome
}

// Remove Dublicate
// using vector
Node *RemoveDublicate(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    Node *prev = head;

    arr.push_back(temp->data);
    temp = temp->next;
    while (temp)
    {
        if (prev->data == temp->data)
        {
            temp = temp->next;
        }
        else
        {
            arr.push_back(temp->data);
            prev = temp;
            temp = temp->next;
        }
    }

    int distinct = arr.size();
    temp = head;
    for (int i = 0; i < distinct && temp; i++)
    {
        cout << arr[i] << endl;
        temp->data = arr[i];

        prev = temp; // Keep track of last valid node which is valid when deleting a node and it's next will be attached in prev

        temp = temp->next;
    }

    // from the temp current delete upto end, we will follow delete at index zero till
    //   here if we track the temp to be deleted then we will not be able to attach null in the end of current list

    prev->next = NULL;

    while (temp && temp->next)
    {
        cout << "Deleted:" << temp->data << endl;
        Node *toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    return head;
}

// or we could have done using this also
Node *RemoveDuplicates(Node *head)
{
    if (!head || !head->next)
        return head;

    vector<int> arr;
    Node *temp = head;
    Node *prev = head;

    // Step 1: Collect unique elements
    arr.push_back(temp->data);
    temp = temp->next;
    while (temp)
    {
        if (prev->data == temp->data)
        {
            temp = temp->next;
        }
        else
        {
            arr.push_back(temp->data);
            prev = temp;
            temp = temp->next;
        }
    }

    // Step 2: Update first part of list with unique elements
    temp = head;
    for (int i = 0; i < arr.size() && temp; i++)
    {
        temp->data = arr[i];
        prev = temp; // Keep track of last valid node
        temp = temp->next;
    }

    // Step 3: Delete remaining nodes after unique elements
    if (prev && prev->next)
    {
        Node *toDelete = prev->next;
        prev->next = nullptr; // Terminate the list

        // Delete all remaining nodes
        while (toDelete)
        {
            Node *next = toDelete->next;
            delete toDelete;
            toDelete = next;
        }
    }

    return head;
}

// Remove dublicate inplace and effectively
Node *RemoveDuplicateInplace(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Node *prev = head;
    // Node *curr = head->next;

    // here instead of using two pointer we could have used simply curr and curr->next

    Node *curr = head;

    while (curr && curr->next)
    {
        // if (prev->data == curr->data)
        if (curr->next->data == curr->data)
        {
            // remove current
            Node *temp = curr->next;

            // curr = curr->next;
            curr->next = temp->next;
            // prev->next = curr;
            delete temp;
        }
        else
        {
            // not remove
            curr = curr->next;
            // prev = prev->next;
        }
    }

    return head;
}

// merge two sorted List
Node *mergeSorted(Node *mergedLinkedList, Node *headpass1, Node *headpass2)
{

    // here as head1 and head2 points the original, hence it created problemas head is shifted.

    // we could have used seperate linkedlist where we could have inserte new node in the traversal, let's try that approach first.

    Node *head1 = headpass1, *head2 = headpass2;

    while (head1 && head2)
        if (head1->data <= head2->data)
        {
            // insert head1 at the end of single linkedlist
            mergedLinkedList = InsertAtEnd(mergedLinkedList, head1->data);
            head1 = head1->next;
        }
        else
        {
            mergedLinkedList = InsertAtEnd(mergedLinkedList, head2->data);
            head2 = head2->next;
        }

    // it might be possible that head1 not completely filled or head2 not filled
    while (head1)
    {
        mergedLinkedList = InsertAtEnd(mergedLinkedList, head1->data);
        head1 = head1->next;
    }

    while (head2)
    {
        mergedLinkedList = InsertAtEnd(mergedLinkedList, head2->data);
        head2 = head2->next;
    }

    return mergedLinkedList;
}

// to solve it inplace without extra linkedlist creation
Node *mergeSortedOpti(Node *head1, Node *head2)
{
    if (!head1)
    {
        return head2;
    }
    else if (!head2)
    {
        return head1;
    }

    Node *prev = NULL;
    Node *start = NULL;

    // printLinkList(head1);
    // cout << endl;
    // printLinkList(head2);
    // cout << endl;

    while (head1 != NULL && head2 != NULL)
    {
        // cout << head1->data << endl;
        // cout << head2->data << endl;
        if (head1->data <= head2->data)
        {
            if (prev)
            {
                prev->next = head1;
            }
            if (!start)
            {
                start = head1;
            }

            prev = head1;
            head1 = head1->next;
        }
        else
        {
            if (prev)
            {
                prev->next = head2;
            }

            if (!start)
            {
                start = head2;
            }
            prev = head2;
            head2 = head2->next;
        }
    }

    if (head1)
    {
        prev->next = head1;
    }

    if (head2)
    {
        prev->next = head2;
    }

    return start;
}

Node *mergeSortedOptimized(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    Node *mergedHead = nullptr;
    Node *tail = nullptr;

    // Initialize merged list
    if (head1->data <= head2->data)
    {
        mergedHead = head1;
        head1 = head1->next;
    }
    else
    {
        mergedHead = head2;
        head2 = head2->next;
    }
    tail = mergedHead;

    // Merge process
    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // Attach remaining elements
    tail->next = head1 ? head1 : head2;

    return mergedHead;
}

Node *mergeSortedOptiTry(Node *head1, Node *head2)
{
    // Create a dummy node to simplify merging
    Node dummy; // instead of empty constructor we have used dumy with 0 data and at time of return , return dummy next
    Node *tail = &dummy;

    dummy.next = nullptr;

    // Node *head=new Node(0);
    // Node *tail=head;
    // now simply tail next will point to the selected min.

    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
        tail->next = nullptr; // Explicitly break old links so that it can't point to any node.
    }

    // Attach remaining elements
    tail->next = head1 ? head1 : head2;

    return dummy.next;
}

// Sorting the linked list with only 0, 1,2 value present
Node *SortLinkThree(Node *head)
{
    // we could have used count operation
    int count0 = 0, count1 = 0, count2 = 0;
    Node *temp = head;
    while (temp)
    {
        if (temp->data == 0)
        {
            count0++;
        }
        else if (temp->data == 1)
        {
            count1++;
        }
        else if (temp->data == 2)
        {
            count2++;
        }
        temp = temp->next;
    }

    temp = head;
    while (count0--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    while (count1--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    while (count2--)
    {
        temp->data = 2;
        temp = temp->next;
    }

    return head;
}

// Sorting the linked list with only 0, 1,2 value present //along with it's address
Node *SortLinkThreeInPlaceAdd(Node *head)
{
    // we could have used count operation

    Node *temp = head, *head0 = new Node(-1), *head1 = new Node(-1), *head2 = new Node(-1);

    Node *tail0 = head0, *tail1 = head1, *tail2 = head2;

    while (temp)
    {
        if (temp->data == 0)
        {
            tail0->next = temp;
            temp = temp->next;
            tail0 = tail0->next;
            tail0->next = NULL; // explicitly breking the old connection //
        }
        else if (temp->data == 1)
        {
            tail1->next = temp;
            temp = temp->next;
            tail1 = tail1->next;
            tail1->next = NULL;
        }
        else if (temp->data == 2)
        {
            tail2->next = temp;
            temp = temp->next;
            tail2 = tail2->next;
            tail2->next = NULL;
        }
    }

    if (head1->next)
    {
        tail0->next = head1->next;
    }
    else
    {
        tail0->next = head2->next;
    }

    tail1->next = head2->next; // move even when null in head2->next

    if (head0->next)
    {
        return head0->next;
    }
    else if (head1->next)
    {
        return head1->next;
    }
    else
    {
        return head2->next;
    }
}

int main()
{

    Node *linkedList = NULL;
    linkedList = insertAtIndex(linkedList, 20, 0);
    linkedList = insertAtIndex(linkedList, 8, 0);
    linkedList = insertAtIndex(linkedList, 7, 0);
    linkedList = insertAtIndex(linkedList, 30, 0);
    printLinkList(linkedList);
    cout << endl;

    // reverse the linkedlist using arry
    linkedList = reverseLinkList(linkedList);
    printLinkList(linkedList);
    cout << endl;

    linkedList = reverseLinkListWithTwoPointer(linkedList);
    printLinkList(linkedList);
    cout << endl;

    linkedList = reverseLinkedListRecursion(NULL, linkedList);
    cout << "linked list reverse with recursion\n";
    printLinkList(linkedList);
    cout << endl;

    // 20 8 7 30
    cout << middleElement(linkedList) << endl;    // 0x861d70
    cout << linkedList->next->next << endl;       // 0x861d70
    cout << linkedList->next->next->data << endl; // 7

    middleElementPseudo(linkedList);
    cout << middleElementPseudo(linkedList) << endl;

    printLinkList(linkedList);
    cout << endl;
    linkedList = rotateByK(linkedList, 2);
    printLinkList(linkedList);
    cout << endl;

    linkedList = rotateByKTwoPointer(linkedList, 2);
    printLinkList(linkedList);
    cout << endl;

    linkedList = rotateByKTwoPointer(linkedList, 4);
    printLinkList(linkedList);
    cout << endl;

    linkedList = removeNEnd(linkedList, 2);
    printLinkList(linkedList);
    cout << endl;

    linkedList = insertAtIndex(linkedList, 20, 0);
    linkedList = insertAtIndex(linkedList, 8, 0);
    linkedList = insertAtIndex(linkedList, 7, 0);
    linkedList = insertAtIndex(linkedList, 30, 0);
    printLinkList(linkedList);

    cout << endl;

    linkedList = removeEveryKNode(linkedList, 2);
    printLinkList(linkedList);
    cout << endl;

    linkedList = removeEveryKNodeCount(linkedList, 2);
    printLinkList(linkedList);
    cout << endl;

    linkedList = insertAtIndex(linkedList, 10, 0);
    linkedList = insertAtIndex(linkedList, 30, 0);
    linkedList = insertAtIndex(linkedList, 20, 0);
    printLinkList(linkedList);
    cout << endl;

    cout << Palidrome(linkedList) << endl;            // using two pointer
    cout << isPalidrome(linkedList) << endl;          // using vector
    cout << isPalidromeByReverse(linkedList) << endl; // using revese the node after middle
    printLinkList(linkedList);
    cout << endl;

    // Remove Dublicate from sorted linked list for insequence
    linkedList = insertAtIndex(linkedList, 10, 0);
    linkedList = insertAtIndex(linkedList, 10, 0);
    linkedList = insertAtIndex(linkedList, 5, 0);
    linkedList = insertAtIndex(linkedList, 5, 0);
    printLinkList(linkedList);
    cout << endl;

    linkedList = RemoveDuplicateInplace(linkedList);
    printLinkList(linkedList);
    cout << endl;

    linkedList = RemoveDublicate(linkedList);
    printLinkList(linkedList);
    cout << endl;

    linkedList = RemoveDuplicates(linkedList);
    printLinkList(linkedList);
    cout << endl;

    // Merge two sorted list
    Node *linkedList2 = NULL;
    linkedList2 = insertAtIndex(linkedList, 10, 0);
    linkedList2 = insertAtIndex(linkedList, 10, 0);
    linkedList2 = insertAtIndex(linkedList, 5, 0);
    linkedList2 = insertAtIndex(linkedList, 5, 0);
    printLinkList(linkedList2);
    cout << endl;

    Node *mergedLinkedList = NULL;
    mergedLinkedList = mergeSorted(mergedLinkedList, linkedList, linkedList2);
    printLinkList(mergedLinkedList);
    cout << endl;

    printLinkList(linkedList);
    cout << endl;
    printLinkList(linkedList2);
    cout << endl;

    // linkedList = mergeSortedOpti(linkedList, linkedList2);
    // printLinkList(linkedList);
    // cout << endl;

    // linkedList = mergeSortedOptimized(linkedList, linkedList2);
    // printLinkList(linkedList);
    // cout << endl;

    // linkedList = mergeSortedOptiTry(linkedList, linkedList2);
    // printLinkList(linkedList);
    // cout << endl;

    Node *linkedList3 = NULL;
    linkedList3 = insertAtIndex(linkedList3, 10, 0);
    linkedList3 = insertAtIndex(linkedList3, 10, 0);
    linkedList3 = insertAtIndex(linkedList3, 5, 0);
    linkedList3 = insertAtIndex(linkedList3, 5, 0);
    printLinkList(linkedList3);
    cout << endl;

    Node *linkedList4 = NULL;
    linkedList4 = insertAtIndex(linkedList4, 10, 0);
    linkedList4 = insertAtIndex(linkedList4, 10, 0);
    linkedList4 = insertAtIndex(linkedList4, 5, 0);
    linkedList4 = insertAtIndex(linkedList4, 5, 0);
    printLinkList(linkedList4);
    cout << endl;

    linkedList3 = mergeSortedOpti(linkedList3, linkedList4);
    printLinkList(linkedList3);
    cout << endl;

    //  linkedList3 = mergeSortedOptimized(linkedList3, linkedList4);
    // printLinkList(linkedList3);
    // cout << endl;

    //  linkedList3 = mergeSortedOptiTry(linkedList3, linkedList4);
    // printLinkList(linkedList3);
    // cout << endl;

    // Earlier we faced problem because we marged with new array insert , then again in mergining, we have chaged the original flow content. Hence using the old linkedlist will create error and caught in infinite loop.

    Node *linkedList5 = NULL;
    linkedList5 = insertAtIndex(linkedList5, 1, 0);
    linkedList5 = insertAtIndex(linkedList5, 0, 0);
    linkedList5 = insertAtIndex(linkedList5, 2, 0);
    linkedList5 = insertAtIndex(linkedList5, 2, 0);
    linkedList5 = insertAtIndex(linkedList5, 0, 0);
    linkedList5 = insertAtIndex(linkedList5, 1, 0);
    linkedList5 = insertAtIndex(linkedList5, 0, 0);

    printLinkList(linkedList5);
    cout << endl;
    // let's sort this linkedlist
    // using count and inplace without address change
    linkedList5 = SortLinkThreeInPlaceAdd(linkedList5);
    printLinkList(linkedList5);
    cout << endl;

    linkedList5 = SortLinkThree(linkedList5);
    printLinkList(linkedList5);
    cout << endl;



    
}