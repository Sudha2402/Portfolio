#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// stack
// insertion and deletion only at one end.

// stack is an abstract data based on user requirent.
// It uses LIFO principle
// Operation. push, pop, top(pointer point the last index or top of stack, size, peek(data at top ) function

// Stack implementation using STL : standard template library
#include <stack>
// it has some operations build in using queue

//
// problems that can be solved using stack

// reverse the array
// Insert at bottom
// make the array beautiful,  we have to remove the adjacent +ve and -ve value together.
// here as we need to store the history of last neightbour after pop, hence we can use stack for storing the history , which will be needed again.
// same same adjacent string is removed
// parenthesis is valid or not //O(n) time complexity and O(n) space complexity.//for O(1) space complexity , we use count of left and right
// minimum add to make valid
// valid parenthesis with  diffrent types of brackets
// background string Compare //if # comes then remove the last charater, it means # means backspace and bacspace removes the last character.
// print bracket number
// Get Minimum at pop//use index of min to store in the stack then when popping, store the ans from back to front in vector//otherwise checking for min every interval takes O(n^2) time complexity.//we can do it directly using brute force method to store in in a vetor with one traversal //print min among all present then pop.//we could have also if pushed the value then we need to maintain another min stack storing min upto this then pop then together in both stack.this way wll increase the time complexity to O(n^2) when comparing with all stack data, hence we put the index to directly the the data using index.

//
//
//
// for stack using arr in heap.

class stackArr
{

    int size;
    int top; // here top need not to be kept pointer as we are using just index value and we can handle it from stack / staic mememory instead of from heap
    int *arr;

public:
    bool flag; // 0 when not empty

    // I want to implement with array
    // constructor
    stackArr(int size)
    {
        arr = new int[size];
        top = -1;
        this->size = size;
        flag = 1; // empty
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow\n";
            return;
        }
        top++;
        arr[top] = data;
        cout << "pushed in the stack : " << data << endl;
        flag = 0;
    }

    void pop()
    { // pop the element at top index
        if (top == -1)
        {
            cout << "Stack underflow\n";
            return;
        }

        //   here we don't have delete option, as it is array, hence even if we change the value to 0 then still it does not make sense.
        cout << "popped from the stack : " << arr[top] << endl;
        top--;

        if (top == -1)
        {
            flag = 1;
        }
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
            return -1;
        }

        return arr[top];
    }

    bool isEmpty()
    {
        // if empty return 1 else returns 0

        return top == -1; // very uniques way of thinking  //compare and return
    }

    int issize()
    {
        // returns the size of stack filled
        return top + 1;
    }
};

// Stack with linkedlit insertion at start

// here Node is created as a type of value.

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class stackLinkedlist
{

    // heap overflow condition exists here

    Node *top; // top is a pointer pointing to Node type value.

    int size;

public:
    stackLinkedlist()
    {
        top = NULL;
        size = 0;
    }

    void push(int data)
    {

        Node *temp = new Node(data);

        // what if this temp is not created due to heap full

        if (temp)
        {

            temp->next = top;
            top = temp;
            size++;
        }

        cout << "Pushed " << top->data << " from the stack\n";
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow\n";
            return;
        }

        Node *temp = top;
        cout << "Popped " << top->data << " from the stack\n";
        top = top->next;
        delete temp;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "Underflow stack";
            return -1;
        }

        return top->data;
    }

    int issize()
    {
        if (top == NULL)
        {
            cout << "Underflow stack";
            return -1;
        }

        return size;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};

void reverse(char arr[], int size)
{
    // for reversing , we need stack to push all then pop one by one

    stack<char> arrStack;
    for (int i = 0; i < size; i++)
    {
        arrStack.push(arr[i]);
    }

    // for (int i=0;i<arrStack.size();i++){
    int i = 0;
    while (!arrStack.empty())
    { // more optimized than .size()
        arr[i] = arrStack.top();
        i++;
        arrStack.pop();
    }

    // solved in O(n) TC

    // O(n) space complexity due to space of stack
}

void reverseVect(vector<char> &arr)
{
    int size = arr.size();
    stack<char> arrStack;
    for (int i = 0; i < size; i++)
    {
        arrStack.push(arr[i]);
    }

    // for (int i=0;i<arrStack.size();i++){
    int i = 0;
    while (!arrStack.empty())
    { // more optimized than .size()
        arr[i] = arrStack.top();
        i++;
        arrStack.pop();
    }
}

stack<int> insertAtBottom(stack<int> st, int x) // takes the copy of the stack not change the original stack
{
    // x is the element to be inserted

    stack<int> temp; // for storing the popped element
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }

    st.push(x);
    cout << "inserted at bottom\n";

    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }

    return st;
}

vector<int> beautifyarray(vector<int> beautiarray)
{
    stack<int> temp;

    for (int i = 0; i < beautiarray.size(); i++)
    {
        if (temp.empty())
        {
            temp.push(beautiarray[i]);
        }
        else
        {
            if ((beautiarray[i] > 0 && temp.top() < 0) || (beautiarray[i] < 0 && temp.top() > 0))
            {
                temp.pop();
            }
            else
            {
                temp.push(beautiarray[i]);
            }
        }
    }

    vector<int> ans(temp.size()); // must create this size for inserting from back at proper index

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans[i] = temp.top();
        temp.pop();
    }
    cout << "beautified\n";

    return ans;
}

// same same adjacent string is removed
vector<string> stringManu(vector<string> arr)
{
    stack<string> temp;

    for (int i = 0; i < arr.size(); i++)
    {
        if (temp.empty())
        {
            temp.push(arr[i]);
        }
        else if (arr[i] == temp.top())
        {
            temp.pop();
        }
        else
        {
            temp.push(arr[i]);
        }
    }

    vector<string> ans(temp.size()); // must create this size for inserting from back at proper index

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans[i] = temp.top();
        temp.pop();
    }
    cout << "string manipulated\n";

    return ans;
}

// parenthesis is valid or not
bool parenthesisValid(string str)
{
    // we can use stack here where we will check if opening bracket comes before it, then valid else return not valid.

    // we will use stack to check if opening is present at the last time, top of the stack for every closing bracket, if present then pop it and move to next index

    stack<char> strStack;
    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] == '(')
        {
            strStack.push(str[i]);
        }
        else
        {
            if (strStack.empty())
            {
                return 0; // not valid as ) comes before any (
            }

            // compare with str top
            strStack.pop(); // it must be ( present in stack. // ) is not pushed into the stack
        }
    }

    // if stack empty then balance else not balance
    // if (strStack.empty())
    // {
    //     return 1;
    // }

    // return 0;

    // combined with bool
    return strStack.empty(); // use one line code approch wherever possible
}

bool parenthesisValidWithoutStack(string str)
{
    int left = 0, right = 0; // right not neede as left increment and decrement shows everything

    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] == '(')
        {
            left++;
        }
        else
        {
            if (left == 0)
            {
                return 0; // not valid as ) comes before any (
            }

            left--;
        }
    }

    // combined with bool
    return left == 0;
}

// minimum add to make valid
int minAddParen(string str)
{
    // int count=0;

    stack<char> strStack;
    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] == '(')
        {
            strStack.push(str[i]);
        }
        else
        {
            if (strStack.empty())
            {
                strStack.push(str[i]);
            }
            else if (strStack.top() != ')')
            {
                strStack.pop();
            }
            else
            {
                strStack.push(str[i]); // here we could have used count also where count holds for all ) and ( is only pused. return count+str.size()
                // count++;
            }
        }
    }

    // combined with bool
    return strStack.size();
    // return strStack.size()+count;
}

// You could make the matching logic slightly clearer by using a map for bracket pairs://we will use later after learning map
//  unordered_map<char, char> pairs = {
//         {')', '('},
//         {'}', '{'},
//         {']', '['}
//     };
bool parenthesisAllValid(string str)
{ // for this stack is the best option to implement it

    stack<char> strStack;
    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            strStack.push(str[i]);
        }
        else
        {
            if (strStack.empty())
            {
                return 0; // not valid as ) comes before any (
            }

            else if (strStack.top() == '(' && str[i] == ')' || strStack.top() == '{' && str[i] == '}' || strStack.top() == '[' && str[i] == ']')
            {
                // compare with str top
                strStack.pop(); // it must be ( present in stack. // ) is not pushed into the stack
            }
            else
            {
                return 0;
            }
        }
    }

    return strStack.empty();
}

// background string Compare

string backspacewithhash(string str)
{

    // for this stack is the best option to implement it as we keep track of all history of visited date, else we were needed to keep a pointer pointing the last index

    stack<char> strStack;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != '#')
        {
            strStack.push(str[i]);
        }
        else
        {
            if (strStack.empty())
            {
                continue;
            }

            else
            {

                strStack.pop();
            }
        }
    }

    string ans = "";
    // set this stack value into ans
    for (int i = strStack.size() - 1; i >= 0; i--)
    {
        ans = strStack.top() + ans; // appending
        strStack.pop();
    }

    return ans;
}

// for string and brackets both validity
bool parenthesisValidInString(string str)
{
    stack<char> strStack;
    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] == '(')
        {
            strStack.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (strStack.empty())
            {
                return 0; // not valid as ) comes before any (
            }

            // compare with str top
            strStack.pop(); // it must be ( present in stack. // ) is not pushed into the stack
        }

        continue;
    }

    return strStack.empty(); // use one line code approch wherever possible
}

// print the bracket number

// here instead of putting bracket into the stack ,we should put the number of bracket, position into the stack so that we can keep the track of this currrent close breacket is result of which last open bracket number.

// this method of storing count will work only for one type of parenthesis.

// ​for diiferent parenthesis , we need to use diiferent stack for storing count of each type of parenthesis.

vector<int> bracketNumber(string str)
{
    int count = 0;
    stack<char> strStack;
    // before count print we should check wheather it is valid or not
    vector<int> countArr;

    if (!parenthesisValidInString(str))
    {
        cout << "not valid parenthesis string\n";
        return countArr;
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            count++;
            // cout<<count<<" ";//we can store this in a vector
            strStack.push(count);
            countArr.push_back(count);
        }
        else if (str[i] == ')')
        {
            countArr.push_back(strStack.top());
            strStack.pop();
        }
    }

    return countArr;
}

// get min at pop
stack<int> _push(int arr[], int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            st.push(arr[i]);
        }
        else
        {
            // push the min at this comparing the current index value and top of stack value

            st.push(min(arr[i], st.top())); // as stack contains the min hence last time min is stored in stack taop
        }
    }

    return st;
}

void getminAtPop(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}




int main()
{

    stackArr S1(3);
    S1.push(4);
    S1.push(5);
    S1.push(-1);
    S1.push(6);
    S1.push(7); // Stack overflow

    if (S1.flag == 0)
    {
        cout << "Peek element is : " << S1.peek() << endl; // here peek return -1 when empty and -1 if value -1 is present, for creating the difference bweteen them, we need to use flag
    }

    S1.pop();

    //
    //
    stackLinkedlist S2;
    S2.push(12);
    S2.push(13);
    S2.push(14);
    S2.pop();
    cout << S2.peek() << endl;
    cout << S2.issize() << endl;
    cout << S2.isEmpty() << endl;

    cout << endl;

    // Stack implementation using STL : standard template library
    stack<int> St; // it is implemented just like vector

    St.push(12);
    St.push(13);
    St.push(14);
    St.top();
    // St.empty();
    cout << St.empty() << endl; // 0
    cout << St.size() << endl;
    cout << St.top() << endl; // 14 //return top element not the top index

    St.pop();
    St.pop();
    St.pop();
    //    cout<<St.pop()<<endl;//error as inbuilt has no such defined withy any return
    cout << St.empty() << endl; // 1

    // reverse the array
    char arr[] = {'c', 'd', 'w', 'e'};
    reverse(arr, sizeof(arr));

    for (int i = 0; i < sizeof(arr); i++)
    {
        cout << arr[i] << " ";
    }
    // e w d c

    cout << endl;

    // if we prefered passing vector then remember to pass the reference in vector for updating at the same place, otherwise vector creates a copy of it.

    vector<char> arrVect = {'c', 'd', 'w', 'e'};
    reverseVect(arrVect);
    for (int i = 0; i < arrVect.size(); i++)
    {
        cout << arrVect[i] << " ";
    }
    cout << endl;

    // Insert at bottom
    //
    // for this we need to remove all and store in vector then put the element at bottom

    // let's use insert at bottom with stack return type
    stack<int> insertedBottom;
    insertedBottom.push(12);
    insertedBottom.push(13);
    insertedBottom.push(14);
    cout << insertedBottom.size() << endl;

    // for (int i = 0; i < insertedBottom.size(); i++)    //not works good, hence use while loop
    // while(!insertedBottom.empty())
    // {
    //     cout << insertedBottom.top() << " ";
    //     insertedBottom.pop();
    // }
    // cout << endl;

    insertedBottom = insertAtBottom(insertedBottom, 17); // this way put the copied stack return here

    // for (int i = 0; i < insertedBottom.size(); i++) //not works good, hence use while loop
    while (!insertedBottom.empty())
    {
        cout << insertedBottom.top() << " ";
        insertedBottom.pop();
    }
    cout << endl;

    // make the array beautiful//  here as we need to store the history of last neightbour after pop, hence we can use stack for storing the history , which will be needed again.

    vector<int> beautiarray = {2, 3, 5, -9, 6, -2, -8, 9};

    vector<int> beauti;
    beauti = beautifyarray(beautiarray);

    // beauti contains the beautified array
    for (int i = 0; i < beauti.size(); i++)
    {
        cout << beauti[i] << " ";
    }
    cout << endl;

    vector<string> stringMenu = {"ab", "ac", "da", "da", "ac", "db", "ea"};

    for (int i = 0; i < stringMenu.size(); i++)
    {
        cout << stringMenu[i] << " ";
    }
    cout << endl;

    vector<string> menipul;
    menipul = stringManu(stringMenu); // only copy contains the changes, original remains the same

    // beauti contains the beautified array
    for (int i = 0; i < menipul.size(); i++)
    {
        cout << menipul[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < stringMenu.size(); i++)
    {
        cout << stringMenu[i] << " ";
    }
    cout << endl;

    // string strParen = "((())())";
    string strParen = "((())()))";

    cout << parenthesisValid(strParen) << endl;
    cout << parenthesisValidWithoutStack(strParen) << endl;

    cout << minAddParen(strParen) << endl; // 9

    //   string strAllParen = "(()){}[()]";//1
    string strAllParen = "[]{()}{[}]"; // 0
    cout << parenthesisAllValid(strAllParen) << endl;

    // string backspace = "ab#c";
    string backspace = "ad#c";
    string backspaceAns;
    backspaceAns = backspacewithhash(backspace);
    cout << backspaceAns << endl;

    // print the bracket number
    string stringParenthesis = "(aa(bdc))p(de)";
    vector<int> bracketNumberAns;
    bracketNumberAns = bracketNumber(stringParenthesis);
    for (int i = 0; i < bracketNumberAns.size(); i++)
    {
        cout << bracketNumberAns[i] << " ";
    }
    cout << endl;

    // Get min at pop
    int arrMinPop[] = {2, 1, 3, 5, 0, 6};
    // we have to return the min in the output but as the given hint shows we have to push data aslo in stack, hence we will push min data, directly into the stack. then we will pop and print

    stack<int> minPop; // stores all min data that is pushed
    minPop = _push(arrMinPop, sizeof(arrMinPop) / sizeof(arrMinPop[0]));
    getminAtPop(minPop);

    return 0;
}