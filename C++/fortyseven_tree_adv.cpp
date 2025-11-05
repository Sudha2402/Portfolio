#include <iostream>
using namespace std;
#include <queue>
#include <deque>
#include <cmath>

// stack we need for iteration traversal
#include <stack>
#include <vector>
#include <algorithm>

// Check if two nodes are cousin//nodes having same grandparent
// left view of binary tree using queue
// left view of binary tree using recursion
// right view of binary tree
// top view
// bottom view

// traversal of tree using iteration not recursion
// preorder
// postorder
// inorder//complex

// Construct a tree from Inorder and preorder
// form tree from pre + in
// form tree from post + in
// check validity of tree

// Vertical Traversal of Binary Tree
// Diagonal traversal of binary tree
// boundary traversal

// morris traversal
// Inorder using morris in O(1) space
// Preorder
// Postorder

// flatten Binary to linked list

// burning tree
// Max path Sum between two special Nodes with only one connection


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
{ // instead of taking val from start , we can take from insside also
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

// Check if two nodes are cousin//nodes having same grandparent
// we need to get elements on same level with different parent

// we can use queue method

bool cousinNodes(Node *root, Node *a, Node *b)
{

    // learning, becareful when using else if as it neglects case. hence better to use if .

    // Don't forget to reset the value.

    if (root == nullptr || a == nullptr || b == nullptr)
        return false;

    queue<Node *> Q;
    Q.push(root);

    int firstMatch = 0;
    int secondMatch = 0;

    while (!Q.empty())
    {
        int levelSize = Q.size();
        int first = 0;
        int second = 0;

        firstMatch = 0;
        secondMatch = 0;

        for (int i = 0; i < levelSize; i++) // here we could have used while(levelSize--)
        {

            // as now we have pushed the element only after checking if they belongs to same parent or not hence when matching at the time of pop levelwise will not give situation when both belongs to same parent . if both are found at the time of pop then they are cousin

            first = 0;
            second = 0;

            if (Q.front() == a)
            {
                firstMatch = 1;
            }
            else if (Q.front() == b)
            {
                secondMatch = 1;
            }

            // if (firstMatch == secondMatch == 1) //not allowed in C++
            if (firstMatch && secondMatch)
            {
                return 1; // in optimized, it is done outside
            }

            Node *temp = Q.front();
            Q.pop();

            if (temp->left == a)
            {
                first = 1;
            }
            // else if (temp->right == b)
            if (temp->right == b)
            {
                second = 1;
            }

            // we can combine these in one line if(emp->left == a && temp->right == b || temp->left == b && temp->right == a) return false as same node

            if (temp->left == b)
            {
                second = 1;
            }

            if (temp->right == a)
            {
                first = 1;
            }

            if (first && second)
            {
                // we need to check if they are child of same parent or not
                return 0;
            }
            // else
            // {
            if (temp->left)
                Q.push(temp->left);
            if (temp->right)
                Q.push(temp->right);
            // }
        }
    }

    return 0;
}

// more professional

bool cousinNodesBetter(Node *root, Node *a, Node *b)
{
    if (root == nullptr || a == nullptr || b == nullptr)
        return false;
    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        int levelSize = Q.size();
        bool foundA = false, foundB = false;

        for (int i = 0; i < levelSize; i++)
        {
            Node *temp = Q.front();
            Q.pop();

            // Check if the current node is either a or b
            if (temp == a)
                foundA = true;
            if (temp == b)
                foundB = true;

            // Check if a and b are children of the same parent
            if (temp->left && temp->right)
            {
                if ((temp->left == a && temp->right == b) ||
                    (temp->left == b && temp->right == a))
                {
                    return false; // same parent, not cousins
                }
            }

            // Push children if they exist
            if (temp->left)
                Q.push(temp->left);
            if (temp->right)
                Q.push(temp->right);
        }
        // If both found in the same level and they are not siblings (already checked above), return true.
        if (foundA && foundB)
            return true;
        // If only one is found in this level, they are not at the same depth.
        if (foundA || foundB)
            return false;
    }
    return false;
}

// cousin node with help of parent function.
//  bool parentOfNode(Node *root, Node *a, Node *b){
// suppose we have passed the address.
// we could have pass value also

bool parentOfNode(Node *root, int a, int b)
{
    if (!root)
    {
        return 0;
    }

    if (root->left && root->right)
    {
        if (root->left->data == a && root->right->data == b || root->left->data == b && root->right->data == a)
        {
            // same parent
            return 1;
        }
        else
        {
            // keep searching
            // return parentOfNode(root->left, a, b);
            // return parentOfNode(root->right, a, b);

            // this way return is not acceptable, use OR operator

            return parentOfNode(root->left, a, b) || parentOfNode(root->right, a, b);
        }
    }
}

// Here we have solved using seperate function to check if both nodes are having same parent.
// first we assign the level at which current node is found, if it is found then it's level is assign hence till one level check finish, if both found then l1== l2 , then we call the parent function to check if they are child of same parent.  It is done only when it exit the while loop when l1==2 but not equla to -1. then in return parent is called. if parent function returns 0 means not sibling hence return 1.

bool cousinNodesWithPare(Node *root, int a, int b)
{ // it assumes that all data values are unique.

    queue<Node *> Q;
    Q.push(root);

    int level = 0;
    int l1 = -1, l2 = -1;
    while (!Q.empty())
    {
        int levelSize = Q.size();

        while (levelSize--)
        {
            Node *temp = Q.front();
            Q.pop();

            if (temp->data == a)
            {
                l1 = level;
            }
            else if (temp->data == b)
            {
                l2 = level;
            }

            if (temp->left)
                Q.push(temp->left);
            if (temp->right)
                Q.push(temp->right);
        }

        level++;
        if (l1 != l2)
        { // if one node is found at a level and other not found then return 0 as both not on same level.
            return 0;
        }

        else if (l1 != -1 && l2 != -1)
        {
            // l1==ll2 and not equal to -1
            break; // both found//check level++, then l1!l2 , is is not even both remained -1 hene return 0 as one has been found but not both. //if l1== l2 then check if not equal to -1 means both found at a level and exit the while loop with break.
        }
    }

    return !parentOfNode(root, a, b);
}

// left view of binary tree
vector<int> leftView(Node *root)
{
    vector<int> ans;

    if (root == nullptr)
        return ans; // ans is a garbage

    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        int levelSize = Q.size();
        ans.push_back(Q.front()->data); // only at start push it

        while (levelSize--)
        {
            Node *temp = Q.front();
            Q.pop();

            if (temp->left)
                Q.push(temp->left);
            if (temp->right)
                Q.push(temp->right);
        }
    }

    return ans;
}

// let's solve it using recursion not level wise traversal
// here we can think of storing level value when we keep going down, update only when not in the value present old not changes, here we need to calculate the total level in the form of height but it is better to do all in function not seperare height, it will not work

void leftViewRecur(Node *root, int level, vector<int> &ans)
{

    // we should use inbuilt level track not height of tree
    if (!root)
    {
        return;
    }

    if (ans.size() <= level) // level we have started from 0 hence = also used//here < case will never come hence , we can simply use ==
    {
        ans.push_back(root->data);
    }

    // don't push in ans
    leftViewRecur(root->left, level + 1, ans);
    leftViewRecur(root->right, level + 1, ans);
}

// right view of binary tree
vector<int> rightView(Node *root)
{
    vector<int> ans;

    if (root == nullptr)
        return ans; // ans is a garbage

    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        int levelSize = Q.size();
        ans.push_back(Q.front()->data); // only at start push it

        while (levelSize--)
        {
            Node *temp = Q.front();
            Q.pop();

            if (temp->right)
                Q.push(temp->right);

            if (temp->left)
                Q.push(temp->left);
        }
    }

    return ans;
}

// right view of binary tree using recursion
vector<int> rightViewRecur(Node *root, int level, vector<int> &ans)
{

    // we should use inbuilt level track not height of tree
    if (!root)
    {
        return;
    }

    if (ans.size() <= level) // level we have started from 0 hence = also used//here < case will never come hence , we can simply use ==
    {
        ans.push_back(root->data);
    }

    // don't push in ans
    leftViewRecur(root->right, level + 1, ans);
    leftViewRecur(root->left, level + 1, ans);
}

int heightOfTree(Node *root)
{
    if (!root)
    {
        return 0;
    }

    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

// wrong approch as at right side bottom most will be printed first
void topViewRecurWrong(Node *root, int index, vector<int> &ans)
{ // here index will be leftheight, then indexing will be properly
    if (!root)
    {
        return;
    }

    topViewRecurWrong(root->left, index - 1, ans);

    // after this line index will be acco to the parameter
    // first push the bottom most hence indexing helps in that way

    if (ans.size() == index)
    {
        ans.push_back(root->data); // this will not work for right most node as bootommost node print will create error in sequence.
    }
    topViewRecurWrong(root->right, index + 1, ans);
}

// size of array is leftmost +rightmost + root
// top view level wise
// we can find size using l,r find function

int heightOfTree(Node *root)
{
    if (!root)
    {
        return 0;
    }

    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

// Horizontal distances (HD):
int findHD(Node *root, int &l, int &r, int index)
{ // index starts from 0
    if (!root)
    {
        return 0;
    }

    l = min(l, index); // no such situation will come when index goes at the place where no node present.
    r = max(r, index);

    findHD(root->left, l, r, index - 1);
    findHD(root->right, l, r, index + 1);

    // return the size of tree top element
    return r - l + 1;
}

// Using level traversal
vector<int> topView(Node *root)
{

    // int arrSize = 1 + heightOfTree(root->left) + heightOfTree(root->right);

    // or simply use
    int l = 0, r = 0;
    int arrSize = findHD(root, l, r, 0);

    vector<int> ans(arrSize);
    vector<bool> levelFiled(arrSize, 0); // lowelevel preference incase of left and higher level in case of right hence we will solve it seperately //as it is level wise traversal we are simply filling top first and it is valid in all case.

    if (root == nullptr)
        return ans; // ans is a garbage

    queue<Node *> Q;
    Q.push(root);

    // we are using seperate index queue also to track the index element coming first will be filled first, index helps to decide the position where we have to fill this node data.

    queue<int> Index;
    // Index.push(heightOfTree(root->left));
    // or
    Index.push(-l); // top node index as per left tree height

    while (!Q.empty())
    {
        Node *temp = Q.front();
        Q.pop();

        int pos = Index.front();
        Index.pop();

        if (!levelFiled[pos])
        {
            levelFiled[pos] = 1;
            ans[pos] = temp->data;
        }

        // if filled then don't do anything

        if (temp->left)
        {
            Q.push(temp->left);
            Index.push(pos - 1);
        }

        if (temp->right)
        {
            Q.push(temp->right);
            Index.push(pos + 1);
        }
    }

    return ans;
}

// topview using recursion, we just need to push the element at low level if same

vector<int> topviewRecurParent(Node *root)
{

    // as all these are needed but we don't have access to the main hence we can use all this in seperate function, se what I have done in topviewRecurParent

    int l = 0, r = 0;
    int arrSize = findHD(root, l, r, 0);
    // now l will be updated
    vector<int> index(r - l + 1, INT32_MAX);
    vector<int> answerTopView(r - l + 1);

    topviewRecur(root, index, answerTopView, l, 0); // called below it //levelnum starts form 0

    return answerTopView;
}

vector<int> topviewRecur(Node *root, vector<int> &Index, vector<int> &ans, int pos, int levelNum) // we need this levelNum for storing in the level
{                                                                                                 // as here we are not able to make index and ans here, hence we can call this function from another function
    // we will check the index vector where it's greater then replace with smaller.

    if (!root)
    {
        return ans;
    }

    // pos starts with left index then  left and right dec inc

    if (!Index[pos])
    {

        // if empty at this pos then fill it
        // Index[pos] = pos;//stupid, position in one virtical line is same hence it is not sense of comparision
        Index[pos] = levelNum;
        ans[pos] = root->data;
    }
    else
    {
        // if (Index[pos] > pos) //here it is index value hence in one virtical line it is same, hence as we are moving top then update old with top, without any condition //stupid
        if (Index[pos] > levelNum)
        {
            Index[pos] = pos;
            ans[pos] = root->data;
        }
    }

    // recursive call
    topviewRecur(root->left, Index, ans, pos - 1, levelNum + 1);
    topviewRecur(root->right, Index, ans, pos + 1, levelNum + 1);

    return ans;
}

// bottom view of Binary tree
// here also we will be needed horizontal width

// Using level traversal
vector<int> bottomView(Node *root)
{
    int l = 0, r = 0;
    int arrSize = findHD(root, l, r, 0);

    vector<int> ans(arrSize);
    vector<int> levelFiled(arrSize, INT32_MIN);
    if (root == nullptr)
        return ans;

    queue<Node *> Q;
    Q.push(root);

    queue<int> Index;
    Index.push(-l); // top node index as per left tree height
    int levelNum = 0;
    while (!Q.empty())
    {
        int levelSize = Q.size();
        while (levelSize--)
        {
            Node *temp = Q.front();
            Q.pop();

            int pos = Index.front();
            Index.pop();

            // if (!levelFiled[pos])
            if (levelFiled[pos] == INT32_MIN)
            {
                // levelFiled[pos] = pos;//stupid
                levelFiled[pos] = levelNum;
                ans[pos] = temp->data;
            }

            // if filled then don't do anything just compare
            else
            {
                // if (levelFiled[pos] < pos) // as value of pos will be same, hence this not works
                if (levelFiled[pos] < levelNum)
                {
                    levelFiled[pos] = levelNum;
                    ans[pos] = temp->data;
                }
            }

            if (temp->left)
            {
                Q.push(temp->left);
                Index.push(pos - 1);
            }

            if (temp->right)
            {
                Q.push(temp->right);
                Index.push(pos + 1);
            }
        }
        levelNum++;
    }

    return ans;
}

// bottom view using recursion, we just need to push the element at low level if same

vector<int> bottomviewRecurParent(Node *root)
{

    // as all these are needed but we don't have access to the main hence we can use all this in seperate function, se what I have done in topviewRecurParent

    int l = 0, r = 0;
    int arrSize = findHD(root, l, r, 0);
    // now l will be updated
    vector<int> index(r - l + 1, INT32_MAX);
    vector<int> answerTopView(r - l + 1);

    bottomviewRecur(root, index, answerTopView, l, 0); // called below it

    return answerTopView;
}

vector<int> bottomviewRecur(Node *root, vector<int> &Index, vector<int> &ans, int pos, int levelNum)
{ // as here we are not able to make index and ans here, hence we can call this function from another function
    // we will check the index vector where it's greater then replace with smaller.

    if (!root)
    {
        return ans;
    }

    // pos starts with left index then  left and right dec inc

    if (Index[pos] == INT32_MAX)
    {

        // if empty at this pos then fill it
        // Index[pos] = pos;
        Index[pos] = levelNum;

        ans[pos] = root->data;
    }
    else
    {
        // if (Index[pos] < pos)
        if (Index[pos] <= levelNum)
        { // update
            // Index[pos] = pos;
            Index[pos] = levelNum;
            ans[pos] = root->data;
        }
    }

    // recursive call
    bottomviewRecur(root->left, Index, ans, pos - 1, levelNum + 1);
    bottomviewRecur(root->right, Index, ans, pos + 1, levelNum + 1);

    return ans;
}

// traversal of tree using iteration not recursion

// preorder traversal Iterative
vector<int> preorderIter(Node *root)
{
    stack<Node *> S;
    vector<int> ans;
    S.push(root);

    while (!S.empty())
    {
        Node *temp = S.top();
        S.pop();
        ans.push_back(temp->data);

        if (temp->right)
            S.push(temp->right);
        if (temp->left)
            S.push(temp->left);
    }

    return ans;
}

// postorder traversal Iterative
vector<int> postorderIter(Node *root)
{
    stack<Node *> S;
    vector<int> ans;
    S.push(root);

    while (!S.empty())
    {
        Node *temp = S.top();
        S.pop();

        ans.push_back(temp->data);

        // as the sequence in Postorder is NRL, hence Right has to be printed first then it must be before left in the stack hence left is pushed first to putit in bottom and then right to pop it from there.

        if (temp->left)
            S.push(temp->left);

        if (temp->right)
            S.push(temp->right);
    }

    // as above while produce. NRL, but for postorder we need LRN. hence just reverse the answer

    reverse(ans.begin(), ans.end());

    return ans;
}

// inorder traversal Iterative
vector<int> inorderIter(Node *root)
{
    stack<Node *> S;
    vector<int> ans;
    S.push(root);

    stack<Node *> visited; // actually i am thinking to include this as top element after pop which has no fursther child.//it is not possible as inbetween have childer, hence we must track each.
    // I have thought to check if ellements are visited using this popped allin between storage , means they have been visited once. hence second time seen means give into answer.

    // we can use indexing method where root is provided left height.
    // int l = 0, r = 0;
    // findHD(root, l, r, 0);
    // top index=-l

    // we need to calculate total number of nodes to create ans of that size.

    // before emptying, we have to push all the nodes

    while (!S.empty())
    {

        Node *temp = S.top();
        S.pop();

        if (!visited.empty() && visited.top() == temp)
        {
            // it is being visited second time
            ans.push_back(temp->data);
            visited.pop();
            continue; // don't check below steps now.
        }
        else
        {
            visited.push(temp);
        }

        // we can track if it is second time visited by checking if the popped element is left child of the very top node, if yes then it is visited second time

        // if( S.top()->left==temp){
        //     //second time visited
        //     //no it not working as this is always true even for first time. I come to conclusion that it can be solved with visited track only
        // }

        if (temp->right)
            S.push(temp->right);

        S.push(temp);

        if (temp->left)
            S.push(temp->left);

        // if both left and right not present then show into the stack
        // if (!temp->left && !temp->right)
        // {
        //     ans.push_back(temp->data);
        // }
    }

    return ans;
}

vector<int> inorderIterClear(Node *root)
{
    stack<Node *> S;
    vector<int> ans;
    S.push(root);

    stack<Node *> visited;

    while (!S.empty())
    {

        Node *temp = S.top();
        S.pop();

        if (!visited.empty() && visited.top() == temp)
        {
            // it is being visited second time
            ans.push_back(temp->data);
            visited.pop();
            continue; // don't check below steps now.
        }
        else
        {
            visited.push(temp);
        }

        if (temp->right)
            S.push(temp->right);

        S.push(temp);

        if (temp->left)
            S.push(temp->left);
    }

    return ans;
}

// Another way using this method but in form of boolean
vector<int> inorderIter2(Node *root)
{
    stack<Node *> S;
    vector<int> ans;
    S.push(root);

    stack<bool> visited;
    visited.push(0); // it is being pushed for the first time.

    while (!S.empty())
    {
        Node *temp = S.top();
        S.pop();

        // it's flag value is stored at top of visited
        bool flag = visited.top();
        visited.pop();

        if (!flag)
        {
            // when flag is 0 means visited first time
            if (temp->right)
            {
                S.push(temp->right);
                visited.push(0);
            }

            S.push(temp);
            visited.push(1); // mark as visited 1 first time, now next time it will be second.

            if (temp->left)
            {
                S.push(temp->left);
                visited.push(0);
            }
        }

        else
        {
            // when flag alredy 1 then simply pop and not push anything anywhere, just put this into ans.
            ans.push_back(temp->data);
        }
    }

    return ans;
}

Node *treeFormInPreParent(vector<int> &pre, vector<int> &in)
{

    vector<int> pre = {1, 2, 4, 5, 8, 9, 3, 6, 1};
    vector<int> in = {4, 2, 8, 5, 9, 1, 6, 3, 7};

    // treeFormInPre(pre, in, 0, 0, pre.size());
    int index = 0;
    return treeFormInPreClear(pre, in, 0, index, pre.size() - 1);
    return treeFormInPreMeth2(pre, in, 0, index, pre.size() - 1);
}

// Construct a tree from Inorder and preorder
// inorder and preorder vector is given //Correct Way, but I don't know why you got confused, check each edge cases every time.

Node *treeFormInPre(vector<int> &pre, vector<int> &in, int start, int &index, int end)
{
    if (start > end || index >= pre.size())
    {
        return NULL;
    }

    int currIndexIn = -1;
    // int currIndexIn = index; //we can think of passing this cuuIndex
    for (int i = start; i < end; i++)
    {
        if (in[i] == pre[index])
        {
            currIndexIn = i;
            break;
        }
    }
    if (currIndexIn == -1)
    {                // this case not comes generally,
        return NULL; // we wiil move to next index+1
        // no new element is created hence lower will fail, we can simply return the start index.
    }

    // we need to create node from vector data
    Node *element = new Node(in[currIndexIn]);
    // we need to find index of this element in the inorder
    // here I am using linear search

    // if index is in in the assign it to the tree

    // element->left = treeFormInPre(pre, in, start, index + 1, currIndexIn);//the very next element of pre is in left and then very next to next is in right from there.

    // here some situation may arise where it is not found in left part then check to the right part, hence passing index +1 not good idea.

    // here passing the very next in right creates problem, we can store updated currIndexIn other than -1 then pass in right side.

    index = index + 1;
    element->left = treeFormInPre(pre, in, start, index, currIndexIn);

    // element->right = treeFormInPre(pre, in, currIndexIn, index + 2, end);

    element->right = treeFormInPre(pre, in, currIndexIn + 1, index, end);

    return element;
}

Node *treeFormInPreClear(vector<int> &pre, vector<int> &in, int start, int &index, int end)
{
    if (start > end || index >= pre.size())
    { // The algorithm will keep incrementing index until it exceeds bounds
        // Without check: SEGMENTATION FAULT
        // With check: Safe return NULL

        // You're right that start > end should theoretically prevent index from going out of bounds in valid cases. But real-world programming requires defensive checks.

        // index=index-1;//You should never decrement the index in the base case. The calling function already incremented the index to point to the next element.

        return NULL;
    }

    int currIndexIn = -1;

    for (int i = start; i <= end; i++)
    {
        if (in[i] == pre[index])
        {
            currIndexIn = i;
            break;
        }
    }
    if (currIndexIn == -1)
    {
        return NULL;
    }

    Node *element = new Node(pre[index]); // currIndexIn is the position in the inorder array //index is the position in the preorder array

    index = index + 1; // only one time incremet needed

    element->left = treeFormInPre(pre, in, start, index, currIndexIn - 1); // index increment hone se pahle hi return aa jata h. hence if not found in left then it will search for this index in right. //index null ke time kabhi change ho hi nahi raha h. toh usse checge karne ka koi matlab nahi banta.

    // index = index + 1;
    element->right = treeFormInPre(pre, in, currIndexIn + 1, index, end);

    return element;
}

// The logic behind index + (currIndexIn - start) + 1 is to calculate the starting index of the right subtree in the preorder array without using pass-by-reference. Let me break it down:

// What each part means:

// index: Current position in preorder array (the root)
// currIndexIn: Position of root in inorder array
// start: Start index of current subtree in inorder array
// (currIndexIn - start): Number of elements in the left subtree
// + 1: Skip the root itself

// For root = 1:
// - index = 0 (position in preorder)
// - currIndexIn = 3 (position in inorder)
// - start = 0 (start of inorder segment)
// - Left subtree size = currIndexIn - start = 3 - 0 = 3 elements
// - Right subtree starts at: 0 + 3 + 1 = 4 in preorder

Node *treeFormInPreMeth2(vector<int> &pre, vector<int> &in, int start, int index, int end)
{
    if (start > end || index >= pre.size())
    {

        return NULL;
    }

    int currIndexIn = -1;

    for (int i = start; i <= end; i++)
    {
        if (in[i] == pre[index])
        {
            currIndexIn = i;
            break;
        }
    }
    if (currIndexIn == -1)
    {
        return NULL;
    }

    Node *element = new Node(pre[index]);

    element->left = treeFormInPreMeth2(pre, in, start, index + 1, currIndexIn - 1);

    element->right = treeFormInPreMeth2(pre, in, index + (currIndexIn - start) + 1, index, end);

    return element;
}

// Construct a tree from Inorder and postorder
Node *treeFormInPostParent(vector<int> &post, vector<int> &in)
{

    vector<int> post = {4, 6, 7, 5, 2, 10, 9, 8, 3, 1};
    vector<int> in = {4, 2, 6, 5, 7, 1, 10, 8, 9, 3};

    // as node is better to be first hence either we reverse or start the indexing from last

    int index = post.size() - 1;
    return treeFormInPost(post, in, post.size() - 1, index, 0);

    return treeFormInPostForward(post, in, 0, index, post.size() - 1);

    return treeFormInPostForwardFailCase(post, in, 0, index, post.size() - 1);
}

Node *treeFormInPost(vector<int> &post, vector<int> &in, int start, int index, int end)
{
    if (start < end || index < 0)
    {
        return NULL;
    }

    int currIndexIn = -1;

    for (int i = start; i >= end; i--)
    {
        if (in[i] == post[index])
        {
            currIndexIn = i;
            break;
        }
    }

    if (currIndexIn == -1)
    {
        return NULL;
    }

    Node *element = new Node(post[index]);

    element->right = treeFormInPost(post, in, start, index - 1, currIndexIn + 1); // becareful when writing in backward approch , start remains at it's own position.

    element->left = treeFormInPost(post, in, currIndexIn - 1, index - (start - currIndexIn) - 1, end);

    return element;
}

Node *treeFormInPostMath2(vector<int> &post, vector<int> &in, int start, int &index, int end)
{
    if (start < end || index < 0)
    {
        return NULL;
    }

    int currIndexIn = -1;

    for (int i = start; i >= end; i--)
    {
        if (in[i] == post[index])
        {
            currIndexIn = i;
            break;
        }
    }

    if (currIndexIn == -1)
    {
        return NULL;
    }

    Node *element = new Node(post[index]);

    index--;
    element->right = treeFormInPost(post, in, start, index, currIndexIn + 1); // becareful when writing in backward approch , start remains at it's own position.

    element->left = treeFormInPost(post, in, currIndexIn - 1, index, end);

    return element;
}

// easy way with forward passing
Node *treeFormInPostForward(vector<int> &post, vector<int> &in, int start, int index, int end)
{
    if (start > end || index < 0)
        return NULL;
    {
        return NULL;
    }

    int currIndexIn = -1;

    for (int i = start; i <= end; i++)
    {
        if (in[i] == post[index])
        {
            currIndexIn = i;
            break;
        }
    }

    if (currIndexIn == -1)
    {
        return NULL;
        // when this comes means our tree can be constructed common for both hence we should use this to return explicitly.
    }

    Node *element = new Node(post[index]);

    element->right = treeFormInPost(post, in, currIndexIn + 1, index - 1, end); // becareful when writing in backward approch , start remains at it's own position.

    element->left = treeFormInPost(post, in, start, index - (end - currIndexIn) - 1, currIndexIn - 1); // left subtree index index - (end - currIndexIn) - 1 //index - 1 - (end - currIndexIn) == index - (end - currIndexIn) - 1

    return element;
}

// Check Tree Traversal
// we can try to construct tree from pre + in then post + in then compare if same or not like identical, if same then Ok else return 0.

// to control the tree preparation when not unique
Node *treeFormInPostForwardFailCase(vector<int> &post, vector<int> &in, int start, int index, int end)
{
    if (start > end || index < 0)

    {
        return NULL;
    }

    int currIndexIn = -1;

    for (int i = start; i <= end; i++)
    {
        if (in[i] == post[index])
        {
            currIndexIn = i;
            break;
        }
    }

    if (currIndexIn == -1)
    {
        return NULL;
        // when this comes means our tree can be constructed common for both hence we should use this to return explicitly.
    }

    Node *element = new Node(post[index]);

    element->right = treeFormInPostForwardFailCase(post, in, currIndexIn + 1, index - 1, end); // becareful when writing in backward approch , start remains at it's own position.
    if (element->right == NULL && (currIndexIn + 1) <= end)
    {                   // usne null return kar diya par abhi vo out of range nahi h , means leaf node return nahi h, hence we need to delete all nodes as tree construction not possible
        delete element; // Clean up
        return NULL;    // Propagate error
    }

    element->left = treeFormInPostForwardFailCase(post, in, start, index - (end - currIndexIn) - 1, currIndexIn - 1); // left subtree index index - (end - currIndexIn) - 1 //index - 1 - (end - currIndexIn) == index - (end - currIndexIn) - 1
    if (element->left == NULL && start <= (currIndexIn - 1))
    {
        delete element; // Clean up
        return NULL;    // Propagate error
    }

    return element;
}

void verticalTraverseSetLevelFail(Node *root, int index, vector<vector<int>> &traversal)
{
    if (!root)
    {
        return;
    }

    // traversal[index].push_back(root->data); //here direct pushing creates level disturbed as left part is traversed upto end hence it's element in the line of above will be pused into the 2D array vector before this hence this way push not works. //we need to sort it.

    // call left and right
    verticalTraverseSetLevelFail(root->left, index - 1, traversal);
    verticalTraverseSetLevelFail(root->right, index + 1, traversal);

    traversal[index].push_back(root->data); // this way bottom node are pused first hence it removes the sort problem and at last we just need to reverse it.

    return;
}

// Vertical Traversal of Binary Tree
vector<int> verticalTraversalLevelFail(Node *root)
{
    // we will think of using indexing method as we did in top or bottom view.
    //  Here as we need to print all the elements togther hence we will use 2D array to store the data. Here also we need to use same indexing technique.

    int l = 0, r = 0;
    int HD = findHD(root, l, r, 0);
    // now l contains leftmost node value as per indexing.
    //  r contains right side length, those size length can be created

    // traversal only has to contain the value hence int type is OK.
    vector<vector<int>> traversal(-l + r + 1); // create 2D array of this size as we are having this much vertical lines

    // we are using recursive call of the function
    verticalTraverseSetLevelFail(root, -l, traversal);

    // reverse as we have pused bottom first
    for (int i = 0; i < traversal.size(); i++)
    {
        reverse(traversal[i].begin(), traversal[i].end());
    }

    vector<int> ans;

    // as  verticalTraverseSet handle all, we can simply call print for 2D vector
    for (int i = 0; i < traversal.size(); i++)
    {
        for (int j = 0; j < traversal[i].size(); j++)
        {
            ans.push_back(traversal[i][j]);
        }
    }

    return ans;
}

// vertical traversal of binary tree using BFS
vector<int> verticalTraversalBFS(Node *root)
{
    // we will think of using indexing method as we did in top or bottom view.
    //  Here as we need to print all the elements togther hence we will use 2D array to store the data. Here also we need to use same indexing technique.

    int l = 0, r = 0;
    int HD = findHD(root, l, r, 0);
    // now l contains leftmost node value as per indexing.
    //  r contains right side length, those size length can be created

    // traversal only has to contain the value hence int type is OK.
    vector<vector<int>> traversal(-l + r + 1); // create 2D array of this size as we are having this much vertical lines

    // we need level order traversal now
    queue<Node *> LevelNode;
    queue<int> Index;

    LevelNode.push(root);
    Index.push(-l);

    while (!LevelNode.empty())
    {

        Node *temp = LevelNode.front();
        int verticalIndex = Index.front();

        LevelNode.pop();
        Index.pop();

        traversal[verticalIndex].push_back(temp->data);

        if (temp->left)
        {
            LevelNode.push(temp->left);
            Index.push(verticalIndex - 1);
        }
        if (temp->right)
        {
            LevelNode.push(temp->right);
            Index.push(verticalIndex + 1);
        }
    }

    vector<int> ans;
    // as  verticalTraverseSet handle all, we can simply call print for 2D vector
    for (int i = 0; i < traversal.size(); i++)
    {
        for (int j = 0; j < traversal[i].size(); j++)
        {
            ans.push_back(traversal[i][j]);
        }
    }

    return ans;
}

void diagonalTraverseSet(Node *root, int l, int r, vector<vector<int>> &traversal)
{
    if (!root)
    {
        return;
    }

    traversal[l].push_back(root->data);

    diagonalTraverseSet(root->left, l + 1, r, traversal); // here is no use of right hence we can remove it from parameter

    diagonalTraverseSet(root->right, l, r + 1, traversal);

    return;
}

//  Diagonal traversal of binary tree using DFS as BFS fails in dialgonal bottom print first then top but as top comes first hence we can't use BFS
vector<int> diagonalTraversalDFS(Node *root)
{
    int l = 0, r = 0;
    int HD = findHD(root, l, r, 0);

    // we need as much as row of 2D as in left size
    vector<vector<int>> traversal(-l); // create 2D array of this size as we are having this much vertical lines

    // we need DFS order traversal , hence we need to use recursion

    diagonalTraverseSet(root, 0, 0, traversal);

    vector<int> ans;
    // as  verticalTraverseSet handle all, we can simply call print for 2D vector
    for (int i = 0; i < traversal.size(); i++)
    {
        for (int j = 0; j < traversal[i].size(); j++)
        {
            ans.push_back(traversal[i][j]);
        }
    }

    return ans;
}

// Boundary traversal
// we can do it with DFS only, for this we need to get to left dept then print it is no more childer. hence itseted of root to be null , we will check left and right null, then move back from there//this will print only bottommost elements , hence we need to break into parts to print leftmost, bottom and finaaly rightmost.

void leftElements(Node *root, vector<int> &ans)
{
    if (!root->left && !root->right)
    {
        return; // I want to include leaf node in the bottom traversal not here.
    }

    ans.push_back(root->data);

    if (root->left)
    {

        leftElements(root->left, ans);
    }
    else if (root->right)
    {
        leftElements(root->right, ans);
    }

    return; // we need not to move back.
}

void bootomElements(Node *root, vector<int> &ans)
{

    if (!root->left && !root->right)
    {
        ans.push_back(root->data); // it will push the only root present which we have alredy pushed at the first hence it create dublicate in case of only one root node.

        return;
    }

    bootomElements(root->left, ans);
    bootomElements(root->right, ans);
}

// print all rightmost nodes in the tree
void rightElements(Node *root, vector<int> &ans) // here we could have also traversed the right side and reversed it. then inserted.
{
    if (!root->left && !root->right)
    {
        return;
    }

    if (root->right)
        rightElements(root->right, ans);
    ans.push_back(root->data);

    // if we are at least then the very last will be the mai root node and as it is considered in left traversal, we need to pop this one.
}

vector<int> boundaryTraversalDFS(Node *root)
{
    vector<int> ans;

    if (!root)
        return ans;

    // push leftmost boundary elements
    Node *element = root;

    // ans.push_back(element->data); // we will inseat the root first to remove the dublicate traverse in either left or right part. // //it will push the only root present which we have alredy pushed at the first hence it create dublicate in case of only one root node.

    // let's add condition before this push
    // if(!root->left && !root->right){
    //     //do n't push
    // }

    // OR we can also use
    if (!root->left && !root->right)
    {
        return ans; // If root is the only node, return immediately instead of going to dublicate in left and right.
    }

    if (root->left || root->right)
    {
        ans.push_back(element->data);
    }

    if (root->left)
    {
        leftElements(root->left, ans);
    }

    // push the bottommost elements
    bootomElements(root, ans);

    // push the rightmost elements
    // we can traverse to the right side only and reach to the bottom node then return from there with pushing.

    if (root->right)
    {
        rightElements(root->right, ans);
        // ans.pop_back();//not needed if we are using reverse method to push. and strat from root right instead of root itself.
    }

    return ans;
}

//
//
//
// Here instead of checking in the function directly for empty , we are checking in function we called then return.

void leftBoundary(Node *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right)) // only this is the change we are handling the very first situstion when left and right not present here, istead of before calling it. whenever we are using left and right make sure root itself exist.
        return;
    ans.push_back(root->data);
    if (root->left)
        leftBoundary(root->left, ans);
    else
        leftBoundary(root->right, ans);
}

void leaves(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }
    leaves(root->left, ans);
    leaves(root->right, ans);
}

void rightBoundary(Node *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
        return;
    if (root->right)
        rightBoundary(root->right, ans);
    else
        rightBoundary(root->left, ans);
    ans.push_back(root->data);
}

vector<int> boundaryTraversal2(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    ans.push_back(root->data);

    leftBoundary(root->left, ans);
    leaves(root, ans);
    rightBoundary(root->right, ans);

    return ans;
}

// morris traversal

// Inorder using morris in O(1) space
vector<int> inorderMorris(Node *root)
{

    vector<int> ans;

    while (root)
    {
        if (root->left)
        {
            Node *curr = root->left;                   //
                                                       // traverse the curr rifhtmost
            while (curr->right && curr->right != root) // here curr will always be present, hence check if curr right is present or not //now we are just at last node diagonally in curr traversal. //curr->right helps to not to let the curr to null
            {
                curr = curr->right;
            }
            // when no more curr right is present then link it's right to where we have to return back after recursion , as no recursion we are using we will link right here.

            if (curr->right == NULL) // here curr will always be present
            {                        // to avoid the proble when root has no left nodes. //it will come here after failing curr->right !=root

                curr->right = root; // we are atlast

                // now go to it's right side upto it points to right.
                root = root->left;
            }
            else
            {
                // when curr->right == root
                // unlink here
                curr->right = NULL;
                // as left traverse completed, hence push this into ans
                ans.push_back(root->data);
                root = root->right;
            }
        }
        else
        {

            // now reached to leftmost  node with no left node but right node may or may not be present.
            ans.push_back(root->data);

            // now go to it's right side upto it points to right.

            root = root->right; // here we will move to last time root first and then unlink at the time checking if it's right not null. Here it is not possible to unlink the right from root and then move back , hence first move back then unlink it.

            // this line is the main logic which let's you back to the roor as per link created earlier. after reaching to this root, again check it's left with curr and and if right most is with link then make it null and then add
        }
    }

    return ans;
}

// Preorder using morris in O(1) space

// we need to print the ans the move to left and keep linking the rightmost
vector<int> preorderMorris(Node *root)
{
    vector<int> ans;
    while (root)
    {
        // ans.push_back(root->data); // we will follow only root to print not curr //here at the time of comming back it creates dublicate elements which are already traversed

        if (root->left)
        {
            Node *curr = root->left;
            while (curr->right && curr->right != root)
            {
                curr = curr->right;
            }

            if (curr->right == NULL)
            {
                // Create temporary link and PROCESS current node
                ans.push_back(root->data); // we will follow only root to print not curr // // Process BEFORE going left

                curr->right = root;
                root = root->left;
            }
            else
            {
                // Remove temporary link and move right
                // if curr->right ==root
                curr->right = NULL;

                root = root->right; // helps to traverse back
            }
        }
        else
        {
            // !root->left
            // return back to it's right

            // No left child, process current node and move right

            ans.push_back(root->data); //
            root = root->right;
        }
    }

    return ans;
}

// Postorder using morris
// we can traverse for rifht side then reverse it.

vector<int> postorderMorris(Node *root)
{
    vector<int> ans;
    while (root)
    {
        if (root->right)
        {
            Node *curr = root->right;
            while (curr->left && curr->left != root)
            {
                curr = curr->left;
            }

            if (curr->left == NULL)
            {
                curr->left = root;
                ans.push_back(root->data); // Process in reverse order
                root = root->right;
            }
            else
            {

                // if curr->left ==root
                // Remove temporary link
                curr->left = NULL;

                root = root->left; // helps to traverse back
            }
        }
        else
        {
            // !root->right
            // return back to it's left
            ans.push_back(root->data);
            root = root->left;
        }
    }

    // reverse the answer
    reverse(ans.begin(), ans.end());

    return ans;
}

//
//
// flatten Binary to linked list
//
// we can simply prorder traverse and save the result in form of linkedlist reat pointer. Here we would be needed extra space O(n)

// here it increases complexity by involving pointing then moving back. we can simply chage from the top about the connections.

void flattenBinaryToLinkedList(Node *root)
{
    // what ever node changes we will do here will be reflected in the main

    // we will follow preorder traversal

    while (root)
    {

        if (root->left)
        {
            Node *curr = root->left;
            while (curr->right && curr->right != root)
            {
                curr = curr->right;
            }

            if (curr->right == NULL)
            {
                curr->right = root;
                root = root->left;
            }
            else
            {
                // Remove temporary link and move right
                // if curr->right ==root
                curr->right = root->right;

                // as we are prefering one side next as right, hence change the left to right by here to the bottom last left node

                root->right = root->left;
                root->left = NULL;
                root = curr->right;
            }
        }
        else
        {
            root = root->right;
        }
    }
}

// simplest approch
void flattenBinaryToLinkedListSimple(Node *root)
{

    while (root)
    {

        if (root->left)
        {
            Node *curr = root->left;
            while (curr->right && curr->right != root)
            {
                curr = curr->right;
            }

            // we will chage the pointings from top to bottom not from bottom to top as per morris

            curr->right = root->right;
            root->right = root->left;
            root->left = NULL;
            root = root->right; // we directly linked and chaged the direction.
        }
        else
        {
            root = root->right;
        }
    }
}

// burning tree
// let's code with the understanding I have got.

int Burn(Node *root, int &timer, int target)
{
    if (!root)
    {
        return 0;
    }
    if (root->data == target)
    {
        return -1;
    }

    int left = Burn(root->left, timer, target);
    int right = Burn(root->right, timer, target);

    if (left < 0)
    {
        timer = max(timer, right + abs(left));
        return left - 1; // etne niche se aag lag gayi h.
    }
    if (right < 0)
    {
        timer = max(timer, abs(right) + left);
        return right - 1; // etne niche se aag lag gayi h.
    }

    return 1 + max(left, right);
}

int Height(Node *root)
{
    if (!root)
    {
        return 0;
    }

    return 1 + max(Height(root->left), Height(root->right));
}

void findTargetNode(Node *root, Node *&targetNode, int target)
{ // here this pointer is pointing to the address hence reflected, but it would have not reflected in main.
    if (!root)
    {
        return;
    }

    if (root->data == target)
    {
        targetNode = root;
    }

    findTargetNode(root->left, targetNode, target);
    findTargetNode(root->right, targetNode, target);
}

int minTimeBurn(Node *root, int target)
{
    int timer = 0;
    Burn(root, timer, target); // it will set the timer.

    // let's find the target node and it's further branch height
    Node *targetNode = NULL;
    findTargetNode(root, targetNode, target); // once target node is set , we need to change it into

    // now find the height from the target node

    int targetHeight = Height(targetNode);

    return max(timer, targetHeight);
}

//
//
// One simplest approch we can think of when we would not be needed to find the target seperately and setting the time from there, we can do it from the very first time we found the target.
int Burn2(Node *root, int &timer, int target)
{
    if (!root)
        return 0;

    if (root->data == target)
    {
        // Fire spreads to both left and right children simultaneously
        int leftTime = Height2(root->left);   // Time to burn left subtree
        int rightTime = Height2(root->right); // Time to burn right subtree
        timer = max(timer, max(leftTime, rightTime));
        return -1;
    }

    int left = Burn2(root->left, timer, target);
    int right = Burn2(root->right, timer, target);

    if (left < 0)
    {
        // Target found in left subtree
        int timeToBurnThroughRight = right; // Time to burn right subtree
        int timeFromTarget = abs(left);     // Time for fire to reach current node from target
        timer = max(timer, timeToBurnThroughRight + timeFromTarget);
        return left - 1;
    }

    if (right < 0)
    {
        // Target found in right subtree
        int timeToBurnThroughLeft = left; // Time to burn left subtree
        int timeFromTarget = abs(right);  // Time for fire to reach current node from target
        timer = max(timer, timeToBurnThroughLeft + timeFromTarget);
        return right - 1;
    }

    return 1 + max(left, right);
}

int Height2(Node *root)
{
    if (!root)
        return 0;
    return 1 + max(Height2(root->left), Height2(root->right));
}

int minTimeBurn2(Node *root, int target)
{
    int timer = 0;
    Burn2(root, timer, target);
    return timer;
}

//
// Max path Sum between two special Nodes with only one connection
//

int maxPathSum(Node *root, int &Sum, int add)
{

    if (!root)
    {
        return 0;
    }

    // Handle negative values: Use max(0, ...) to avoid including negative path sums
    int left = maxPathSum(root->left, Sum, add);

    int right = maxPathSum(root->right, Sum, add);

    Sum = max(left + right + root->data, Sum);

    add = max(left + root->data, right + root->data);
    return add;

    // above can be combined as below hence removed the dependeny of add parameter
    // return  root->data+ max(left,right);
}

// only unneccesary parameter is removed.
int maxPathSumImpr(Node *root, int &Sum)
{

    if (!root)
    {
        return 0;
    }

    // Use max(0, ...) to handle negative values (we can choose to not take a path) // as it not handle -ve properly. //Handle negative values: Use max(0, ...) to avoid including negative path sums
    int left = max(0, maxPathSumImpr(root->left, Sum));

    int right = max(0, maxPathSumImpr(root->right, Sum));

    Sum = max(left + right + root->data, Sum);

    return root->data + max(left, right);
}

int main()
{
    cout << "Enter the root element :";
    // int data;
    // cin >> data;

    Node *root = createTreeSideRec();
    cout << "Ilevel print: ";

    InOrder(root); // 1 2 7 3 6 8 4 5 9 10

    Node *a = root->left->left;
    Node *b = root->right->left;

    cout << cousinNodes(root, a, b) << endl;
    cout << cousinNodesBetter(root, root->left->left, root->right->left) << endl;

    cout << cousinNodesWithPare(root, root->left->left->data, root->right->left->data) << endl;

    vector<int> ans = leftView(root);
    // we can check with print
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    ans.clear();
    ans = leftView(root);

    ans.clear();
    leftViewRecur(root, 0, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    ans.clear();
    ans = rightView(root);

    ans.clear();
    ans = rightViewRecur(root, 0, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    ans.clear();
    ans = topView(root);

    // topview using recursion

    // // as all these are needed but we don't have access to the main hence we can use all this in seperate function, se what I have done in topviewRecurParent

    // int l = 0, r = 0;
    // int arrSize = findHD(root, l, r, 0);
    // // now l will be updated
    // vector<int> index(r - l + 1, INT32_MAX);
    // vector<int> answerTopView(r - l + 1);
    // ans.clear();
    // ans = topviewRecur(root, index, answerTopView, l);

    ans = topviewRecurParent(root);
    ans = bottomView(root);
    ans = bottomviewRecurParent(root);

    // traversal of tree using iteration not recursion
    vector<int> ansPre = preorderIter(root);
    vector<int> ansPost = postorderIter(root);
    vector<int> ansIn = inorderIter(root);
    ans = inorderIterClear(root);
    ans = inorderIter2(root);

    // form tree from pre + in
    //  form tree from post + in
    //  check validity of tree

    root = treeFormInPreParent(ansPre, ansIn);
    root = treeFormInPreParent(ansPost, ansIn);

    // Vertical Traversal of Binary Tree
    ans = verticalTraversalLevelFail(root);
    ans = verticalTraversalBFS(root);

    //  Diagonal traversal of binary tree using DFS
    ans = diagonalTraversalDFS(root);

    // boundary traversal
    boundaryTraversalDFS(root);

    //  another method
    boundaryTraversalDFS(root);
    boundaryTraversal2(root);

    // morris traversal
    // Inorder using morris in O(1) space
    inorderMorris(root);

    // Preorder
    preorderMorris(root);

    // Postorder
    postorderMorris(root);

    // flattern binary to linked list
    flattenBinaryToLinkedList(root);
    flattenBinaryToLinkedListSimple(root);

    // Burning Tree
    minTimeBurn(root, 5);
    minTimeBurn2(root, 5);

    // max path between two special nodes with one connection

    int maxSum = INT32_MIN;
    maxSum = maxPathSum(root, maxSum, 0);
    maxSum = maxPathSumImpr(root, maxSum);

    return 0;
}