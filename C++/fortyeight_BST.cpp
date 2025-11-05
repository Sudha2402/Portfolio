#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>

// remember the way to propogate the result in the recursion in between or use parameter with answer and simply return for all rest.

// BST

// create BST from user input.// for now we are creating using array
//  method 2 using recursion
// deleting a node
// or method using swap to delete the node
// Check BST
// we can use inorder traversal.
// we can remove the space complexity of storing inorder traverse value as we need only left node to compare
// Minimum distance between any two nodes in BST
// sum of k smallest elements in BST
// Kth largest Element in BST

// Array to balance BST
// Construct BST from preorder traversal
// Construct BST from postorder traversal
// Preorder and BST
// check if a BST can be created with preorder
// lowest common ancestor in a BST
// Print BST element in given range
// Check whether BST contains Dead End
// Common Node in two BST
// Merge two BST

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// create BST from user input.// for now we are creating using array
Node *createBST(Node *root, int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        Node *n = new Node(arr[i]);
        // we need to treaverse till we find a posititon for it to fit.
        Node *parent = root;

        // if no parent already then we need to create root
        if (!root)
        {
            root = n;
        }

        while (parent)
        {
            if (arr[i] <= parent->data)
            { // we want dublicate in left
                if (parent->left)
                {
                    parent = parent->left;
                }
                else
                {
                    parent->left = n;
                    break; // if this line not added then it will fall in infinite loop condition
                }
            }
            else
            {
                if (parent->right)
                {
                    parent = parent->right;
                }
                else
                {
                    parent->right = n;
                    break;
                }
            }
        }
    }

    return root;
}

// method 2 using recursion
Node *insertNode(Node *root, Node *&n)
{ // address is passsed so that it don't creates it's copy You don't need to pass n by reference (Node * &n) since you're not modifying the pointer itself, just using its value. You can pass by value: //here n is a pointer which is pointing to a location, hence not take dublicate problem.

    if (!root)
    {
        // Node *n = new Node(arr[i]);//when data passed inted of pointer in n
        return n; // this n will be the root
    }

    if (n->data <= root->data)
    {
        root->left = insertNode(root->left, n);
    }
    else
    {
        root->right = insertNode(root->right, n);
    }

    return root;
}

// deleting a node
// for now we are replacing with left largest node
// let's use recursive
Node *deleteNode(Node *root, int target)
{
    if (!root)
    {
        return root;
    }
    if (root->data == target)
    {
        // we got it
        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            Node *parent = root;
            Node *parentLarger = root->left;
            // get max from left side

            while (parentLarger->right)
            {
                parent = parentLarger;
                parentLarger = parentLarger->right;
            }

            // disconnect the parent from last place
            // parent->right = NULL;//what if  parentLarger has it's left child also
            parent->right = parentLarger->left;

            parentLarger->left = root->left;
            parentLarger->right = root->right;
            delete root;
            return parentLarger; // we also need to unlink it's connection from parent.
        }
    }

    if (root->data > target)
        root->left = deleteNode(root->left, target);
    if (root->data < target)
        root->right = deleteNode(root->right, target);

    return root;
}

// or method using swap to delete the node
Node *deleteNode2(Node *root, int target)
{
    if (!root)
        return root;

    if (root->data == target)
    {
        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        { // this is appreciatable
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            // Find maximum in left subtree
            Node *parentLarger = root->left;
            while (parentLarger->right)
            {
                parentLarger = parentLarger->right;
            }

            // Copy the data
            root->data = parentLarger->data;

            // Delete the duplicate from left subtree
            root->left = deleteNode2(root->left, parentLarger->data);
            return root;
        }
    }

    if (target < root->data)
        root->left = deleteNode2(root->left, target);
    else
        root->right = deleteNode2(root->right, target);

    return root;
}

// Check BST
// we can use inorder traversal.
// comparing with only left and right not give right decision with parent node comparinsion, it should be less or more.
// inorder traversal is best approach
void inorderBST(Node *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    inorderBST(root->left, ans);
    ans.push_back(root->data);
    inorderBST(root->right, ans);
}


bool checkBST(Node *root)
{
    vector<int> ans;
    inorderBST(root, ans);

    // check if it is asscending or not
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] < ans[i - 1])
        {
            return 0;
        }
    }

    return 1;
}

// we can remove the space complexity of storing inorder traverse value as we need only left node to compare

bool checkBSTImproved(Node *root, int &prev)
{
    // prev at start will be INT_MIN //here we are using the
    if (!root)
    {
        return 1;
    }

    // checkBSTImproved(root->left, prev);//not works to propogate the result

    // Check left subtree
    // if (!checkBSTImproved(root->left, prev))
    //     return false;

    // we can also use l to store result of left
    bool l = checkBSTImproved(root->left, prev);
    if (l == 0)
    {
        // we need to propogate it // store the left answer then return from there if such case arises. means inbetween , we received 0 value. then return from there.
        return 0;
    }

    // Check current node only when we got 1 return from the leaf node.

    if (prev > root->data)
    {
        return 0; // not automatically passed to last nodes called hence it will be reflected at the last. We need to propogate it // it will travell to  whole stack, hence right part will never be check anymore

        // You're not propagating the return value from recursive calls
    }

    prev = root->data;
    // checkBSTImproved(root->right, prev);

    // for propogating return must be there
    return checkBSTImproved(root->right, prev); // Check return values: Use the return values from recursive calls to propagate errors //ye return prev ke l me jaiyega.//yaha se return hone ke baad vo last prev value use karne lagegi jo root se pahle root tha. hence prev add needs to be passsed to let it preopogate even if it returned form right side.

    // don't forget return from here.
}

// Minimum distance between any two nodes in BST
int minDistance(Node *root, int &ans, int &prev)
{ // here we don't need to return anything as &ans used, hence as we need to move to the end hence no case of answer propogation in between arrises hence be simple here.
    if (!root)
    {
        return ans;
    }

    int left = minDistance(root->left, ans, prev); // left not used anywhere hence it is senseless to put in variable

    if (prev == INT32_MIN)
    {
        prev = root->data;
    }
    else
    {
        ans = min(ans, root->data - prev);
        prev = root->data;
    }

    return minDistance(root->right, ans, prev);
}

// Minimum distance between any two nodes in BST
void minDistanceImp(Node *root, int &ans, int &prev)
{
    if (!root)
    {
        return;
    }

    minDistance(root->left, ans, prev);
    if (prev != INT32_MIN)
    {
        ans = min(ans, root->data - prev);
    }
    prev = root->data;
    minDistanceImp(root->right, ans, prev);
}

// sum of k smallest elements in BST
void SumKSmallest(Node *root, int &K, int &ans)
{
    if (!root)
    {
        return;
    }

    if (K)
    {
        SumKSmallest(root->left, K, ans);
        ans = ans + root->data;
        K--;
        SumKSmallest(root->right, K, ans);
    }
    else
    {
        return;
    }
}

// or we can implement K in parts also
// sum of k smallest elements in BST
void SumKSmallest(Node *root, int &K, int &ans)
{
    if (!root)
    {
        return;
    }

    SumKSmallest(root->left, K, ans);

    if (K > 0)
    {
        ans = ans + root->data;
        K--;
    }
    else
    {
        return; // we can remove it.
    }

    if (K > 0)
    {
        SumKSmallest(root->right, K, ans);
    }
}

//
// Kth largest Element in BST
//
int kthLargestElement(Node *root, int &K)
{
    if (!root)
    {
        return -1;
    }

    // if (K != 0)
    // {
    //     int ans = kthLargestElement(root->right, K);
    //     if (ans == -1)
    //     {
    //         K--; // it has become 0 just now, hence return this K root node answer but is is calling kthLargestElement(root->left, K) hence answer movedBack
    //     }
    //     else
    //     {
    //         return ans;
    //     }

    //     return kthLargestElement(root->left, K);
    // }
    // else
    // {
    //     // last time return the ans
    //     return root->data; // kth largest element, the result won't propagate back to the original caller.
    // }

    int ans = kthLargestElement(root->right, K);
    if (ans != -1)
        return ans; // for propogating the result to last calls

    K--;
    if (K == 0)
    {
        return root->data;
    }
    else
    {
        return kthLargestElement(root->left, K);
    }
}

//
// Array to Balance BST, preorder traversal
//
void preOrderOfBalanceBSTArr(Node *root, int arr[], int low, int high, vector<int> &preorder)
{
    if (low > high)
    {
        return;
    }
    int mid = low + (high - low) / 2;

    // this mid index value will be the root

    preorder.push_back(arr[mid]);

    preOrderOfBalanceBSTArr(root->left, arr, low, mid - 1, preorder);
    preOrderOfBalanceBSTArr(root->right, arr, mid + 1, high, preorder);
}

// Array to Balance BST implementation with tree, preorder traversal
//
Node *preOrderOfBalanceBSTArrImp(Node *root, int arr[], int low, int high, vector<int> &preorder)
{
    if (low > high)
    {
        return root;
    }
    int mid = low + (high - low) / 2;

    // this mid index value will be the root
    // if (!root)
    // {
    root = new Node(arr[mid]);
    // }

    preorder.push_back(arr[mid]);

    root->left = preOrderOfBalanceBSTArrImp(root->left, arr, low, mid - 1, preorder);
    root->right = preOrderOfBalanceBSTArrImp(root->right, arr, mid + 1, high, preorder);

    return root;
}

// Construct BST from preorder traversal
Node *BSTFrompreOrder(int low, int high, vector<int> &preorder, int &i)
{ // i starts from 0
    if (i == preorder.size() || preorder[i] > high || preorder[i] < low)
    {                // don't forget any condition
        return NULL; // earlier we were returning the root as root we included in parameter also but as wer are linking at the time of return , we need not that, hence removed from here.
    }

    Node *root = new Node(preorder[i++]); // so that below face the updated i value which is next.

    // root->left = BSTFrompreOrder(low, preorder[i], preorder,i); //as we have increment i hence it preorder[i] will not work
    root->left = BSTFrompreOrder(low, root->data - 1, preorder, i); // as we have increment i hence it will not work

    root->right = BSTFrompreOrder(root->data + 1, high, preorder, i); // it will take the same i where left has returned

    return root;
}

// Construct BST from postorder traversal
Node *BSTFrompostOrder(int low, int high, vector<int> &postOrder, int &i)
{
    if (i < 0 || postOrder[i] < low || postOrder[i] > high)
    {
        return NULL;
    }

    Node *root = new Node(postOrder[i--]);

    // if dublicate then remove +1 , -1 from low high decided.
    // root->right = BSTFrompostOrder(root->data + 1, high, postOrder, i);  // >
    root->right = BSTFrompostOrder(root->data, high, postOrder, i); // >=

    root->left = BSTFrompostOrder(low, root->data - 1, postOrder, i); // <

    return root;
}

//
// Preorder and BST
// check if a BST can be created with preorder

Node *preOrderBSTCheck(int low, int high, vector<int> &preorder, int &i, bool &ans)
{
    if (i == preorder.size() || preorder[i] > high || preorder[i] < low)
    {
        return NULL;
    }

    Node *root = new Node(preorder[i++]);

    root->left = preOrderBSTCheck(low, root->data, preorder, i, ans);
    root->right = preOrderBSTCheck(root->data + 1, high, preorder, i, ans);

    if (root->left == NULL && root->right == NULL && i != preorder.size() - 1)
    {
        // this i index was not able to be alloted to any hence it shows wrong preorder hence return 0;
        ans = 0;
    }
    return root;
}

// let's solve it using stack not recursion to remove the segmentation problem of stack overflow in recursion
bool preOrderBSTStack(vector<int> &preorder)
{
    stack<int> low;
    low.push(INT32_MIN);
    stack<int> high;
    high.push(INT32_MAX);

    int index = 0;
    bool side = 0; // means left
    // side=1//means right side inserted

    vector<int> ans;
    int leftHigh;

    while (index < preorder.size() && !low.empty() && !high.empty())
    {

        if (low.top() < preorder[index] && preorder[index] < high.top())
        {
            // comes in this range

            ans.push_back(preorder[index]);

            // if left side inserted
            if (side == 0)
            {
                low.push(low.top());
                high.push(preorder[index]);
            }

            // if right side inserted
            if (side == 1)
            {
                low.push(leftHigh);
                leftHigh = INT32_MIN;
                high.push(high.top());
            }

            // combining both, I can think of this condition side

            index++;
            side = 0;
        }
        else
        {

            // we should pop only if size>2
            if (low.size() > 2)
            {

                low.pop();

                leftHigh = high.top();
                high.pop();

                side = 1;
            }
            else
            {
                break;
            }
        }
    }

    if (index < preorder.size())
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Using standardized apprach that is correct in almost all cases //for prorder, we push the right element into the stack then left element then we pop left element on camparing or push more.

bool preOrderBSTStackStd(vector<int> &preorder)
{
    stack<int> low;
    low.push(INT32_MIN);
    stack<int> high;
    high.push(INT32_MAX);

    int lowerBound, UpperBound;

    for (int index = 0; index < preorder.size(); index++)
    {

        if (!low.empty() && preorder[index] < low.top())
        {
            return 0;
        }
        // very first csae that moght occur.

        // here we might have a case when greater than the range, max at the bottom in stack and min at the top in stack

        while (!high.empty() && preorder[index] > high.top())
        {
            low.pop();
            high.pop();
        }

        if (!high.empty() && !low.empty())
        {
            // for deciding the left and right node limit
            lowerBound = low.top();
            UpperBound = high.top();

            // it is popped because we have stored the top value and thereafter we will push the right and left limit hence parent limit is of not use fursther.
            low.pop();
            high.pop();
        }
        else
        {
            return 0;
        }

        // right side perspective low and high are pushed and then left side and comparision takes place with left side lastest pushed.
        low.push(preorder[index]);
        high.push(UpperBound);

        // left side push.
        low.push(lowerBound);
        high.push(preorder[index]);

        // this is for comparing the new element at top, hence first new element will be checked with respect to left limit then if not , it is popped to check for right side limit, so on op takes place till new element is found to be in range as per high.
    }

    return 1;
}

// using one stack only
bool preOrderBST1StackStd(vector<int> &preorder)
{

    // here inshort, it is trying to store the upper limit in stack and when element comes less tha top then it is easily pushed. But if element comes larger than the top means that element max can't be top element hence top element is popped and that popped element is considered as min for fursther noeds to be inserted. This popp continues till the current element to be pushed found it's max limit.

    stack<int> s;
    int rootMin = INT_MIN;

    for (int i = 0; i < preorder.size(); i++)
    {
        int current = preorder[i]; // the current node which has to be inserted in the BST

        // If we find a value smaller than the current root, it's invalid

        if (current < rootMin) // rootmin the the min we heve taken from parent, ans if min then this comes it reorder then , it can't be adjusted anywhere hence fails and return false

        { // root is it's parent element min / low
            return false;
        }

        // Pop until we find the parent for right subtree

        // when smaller elements comes than the top element, means this element can be fitted in left of the top element as this is smaller then the top, hence smaller element is pushed easily , in that case the top would be action as max for new node to be pushed.

        // in simple min is stored using rootMin variable for the element to be pushed and max is stored in the form of top element, if empty the top then it will it's owm value as max.

        while (!s.empty() && s.top() < current)
        {
            rootMin = s.top(); // The last popped becomes the root or min of the new node to be inserted or pushed. Hence only greater elements are pushed and lower are popped, till
            s.pop();
        }

        s.push(current);
    }

    return true;
}

// lowest common ancestor in a BST
//  we have three way to solve it
// first, make two vectors tracing the path of each element then find the element just before the first mismatched, or we can say last matched element in both the vector.

// second method is when found one element , then trace back and find to the other side of that element keeping in record the last node, here simply we move back to the path and from each path we find for another node in it's rightmost left untraced path.

// third method is superb as it donot take any extra space , it says to trace the common path till it points to same side, if their side are divided then from that point, it will be the common node

// we will use recursive method.//we will return the node of common ancestor not it's value
Node *lowestCommonAncestor(Node *root, int target1, int target2)
{
    if (!root)
    {
        return NULL;
    }

    if (root->data > target1 && root->data > target2)
    {
        return lowestCommonAncestor(root->left, target1, target2); // in BST, here other side is not neede to check hence we can propogate back from here also, instead of ch3ecking for output storing in variable then checking if ans was returned or something else returned.
    }
    else if (root->data < target1 && root->data < target2)
    {
        return lowestCommonAncestor(root->right, target1, target2);
    }
    else
    {
        return root; // this root is the answer // we need to propogate it back
    }
}

// Print BST element in given range

int rangeLower, rangeHigher; // set values globally so that it would not be neede to pass in the parameter. // these values are always same hence we can make it global

void InorderRangePrint(Node *root, vector<int> &ans)
{

    // if (!root || !(rangeLower <= root->data && root->data <= rangeHigher)) // skip entire subtrees where the root node is outside the range, even if those subtrees might contain valid nodes deeper down! //hence don't return this way
    if (!root)
    {
        return;
    }

    InorderRangePrint(root->left, ans);
    if (rangeLower <= root->data && root->data <= rangeHigher)
    {
        ans.push_back(root->data);
    }

    InorderRangePrint(root->right, ans);
}

vector<int> elementIngivenRange(Node *root, int low, int high)
{
    // we will first find the exact parent where we can get element in the range as mentioned
    int minElement = INT_MIN;
    int maxElement = INT_MAX;

    rangeLower = low;
    rangeHigher = high;

    // while (minElement < rangeLower && maxElement > rangeHigher && !(rangeLower < root->data && root->data < rangeHigher))
    while (root && !(rangeLower <= root->data && root->data <= rangeHigher))
    {
        if (root->data > rangeHigher && minElement < rangeLower)
        {
            // move to the left

            maxElement = root->data;

            // min element remains the same
            root = root->left;
        }

        if (root->data < rangeLower && rangeHigher < maxElement)
        {
            // move to the right
            minElement = root->data;

            // maxElement remains the same as earlier

            root = root->right;
        }
    }

    // the root you will reach is the root from where you would get valuable result.
    vector<int> ans;
    InorderRangePrint(root, ans);
    return ans;
}

// another approch when we don'try to find the root exactly. Just carry on InorderTraversal

void InorderRangePrintTogether(Node *root, vector<int> &ans)
{

    if (!root)
    {
        return;
    }

    // Only go left if current node could have values > lower bound
    if (rangeLower < root->data)
    {
        InorderRangePrintTogether(root->left, ans);
    }

    // Check if current node is in range
    if (rangeLower <= root->data && root->data <= rangeHigher)
    {
        ans.push_back(root->data);
    }

    // Only go right if current node could have values < upper bound
    if (rangeHigher > root->data) // don't think move to right if root->data is less than lower range.
    {
        InorderRangePrintTogether(root->right, ans);
    }

    return; // not actually needed , it will move back automatically
}

// Approch 3 just like first but here exact root is found within the same function
void InorderRangePrintTogether2(Node *root, vector<int> &ans)
{

    if (!root)
    {
        return;
    }

    // Only go left if current node out of range
    if (rangeLower < root->data && rangeHigher < root->data)
    {
        InorderRangePrintTogether2(root->left, ans);
    }
    // Only go right if current node out of range
    else if (rangeHigher > root->data && rangeLower > root->data)
    {
        InorderRangePrintTogether2(root->right, ans);
    }

    // when in the range  //now this node traversal matters as we did in first//now again checking will be done at this point.
    // if (rangeLower <= root->data && root->data <= rangeHigher)
    else
    {
        InorderRangePrintTogether2(root->left, ans);
        ans.push_back(root->data);
        InorderRangePrintTogether2(root->right, ans);
    }

    // return;//not neceesary
}

vector<int> elementIngivenRangeTogether(Node *root, int low, int high)
{

    rangeLower = low;
    rangeHigher = high;

    vector<int> ans;
    InorderRangePrintTogether(root, ans); // method 2

    ans.clear();
    InorderRangePrintTogether2(root, ans); // method 3
    return ans;
}

// Check whether BST contains Dead End
// I will use recursive method

Node *deadEndCheck(Node *root, int low, int high)
{
    // if (high != INT32_MAX && low !=INT32_MIN && high - low == 1) // creates overflow condition as max - min will be added {
    if (!root->left && !root->right && (high - root->data == 1 || root->data - low == 1)) // creates overflow condition as max - min will be added //A node is only a dead end if:It's a leaf node (no children)
    {
        return root; // dead end node //here this root is NULL, hence we are not able to track efficiently with this. //hence use root->left and right when root present
    }

    if (!root->left && !root->right)
    {
        return NULL;
    }

    if (root->left && deadEndCheck(root->left, low, root->data))
    {
        return root;
    }

    if (root->right)
    {
        return deadEndCheck(root->right, root->data, high);
    }

    // above two combined can be shared like this

    // return deadEndCheck(root->left, low, root->data) || deadEndCheck(root->right,root->data, high); //for this we were needed bool.
}

Node *deadEndCheckImp(Node *root, int low, int high)
{
    // Check if leaf node and has dead end condition
    if (!root->left && !root->right && (high - root->data == 1 || root->data - low == 1))
    {
        return root;
    }

    if (root->left)
    {
        Node *leftResult = deadEndCheckImp(root->left, low, root->data);
        if (leftResult)
            return leftResult;
    }

    if (root->right)
    {
        return deadEndCheckImp(root->right, root->data, high);
    }

    return NULL;
}

bool deadEndNodeCusto(Node *root, int low, int high)
{
    if (!root)
    {
        return 0;
    }

    // Check if current node is a dead end (leaf node with no available children)
    if (!root->left && !root->right)
    { // child , leaf node

        if (high - root->data == 1 || root->data - low == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }

        // or combine , we can check difference of 2
        // return (high - low <= 2); //// No integer values between bounds
    }

    return deadEndNodeCusto(root->left, low, high) || deadEndNodeCusto(root->right, low, high);
}

// Method 2 to solve it directly using bool return
bool deadEndNode(Node *root)
{
    if (!root)
    {
        return 0;
    }

    int low = INT32_MIN;
    int high = INT32_MAX;

    return deadEndCheck(root, low, high) != NULL; // not manage to reach to end without any dead node in between, any dead end has been encountered on the way.

    return deadEndNodeCusto(root, INT_MIN, INT_MAX);
}

// Common Node in two BST
vector<int> commonNodes(Node *root1, Node *root2)
{

    stack<Node *> s1;
    stack<Node *> s2;

    vector<int> ans;

    // push all left diagonally elements connected for tree 1 in stack 1
    while (root1)
    {
        s1.push(root1);
        root1 = root1->left;
    }
    // root1 at last will be null

    // push all left diagonally elements connected for tree 2 in stack 2
    while (root2)
    {
        s2.push(root2);
        root2 = root2->left;
    }

    // now we need to compare till any one of the stack not gets empty
    while (!s1.empty() && !s2.empty())
    {
        // compare top element of s1 and s2

        // s1==s2
        if (s1.top()->data == s2.top()->data)
        {
            ans.push_back(s1.top()->data);

            // pop both top but also shift the root1 from last time null to current top right so that we can traverse new root all left elements coneected.

            root1 = s1.top()->right;
            root2 = s2.top()->right;

            // pop both top elements
            s1.pop();
            s2.pop();
        }

        // s1>s2
        else if (s1.top()->data > s2.top()->data)
        {
            // smaller will be not in common hence we can pop it, here s2 top is smaller hence it is popped but remember to push it's right as that will be greater than the current top.

            root2 = s2.top()->right;
            s2.pop();
        }
        // s1<s2
        else
        {
            root1 = s1.top()->right;
            s1.pop();
        }

        // now as we have moved our root1 or root2 to right side then thereafter all left elements are needed to be pushed as they are max now from last top

        // push all left diagonally elements connected for tree 2 as per new root1
        while (root1)
        {
            s1.push(root1);
            root1 = root1->left;
        }

        // push all left diagonally elements connected for tree 2 as per new root2
        while (root2)
        {
            s2.push(root2);
            root2 = root2->left;
        }
    }

    return ans;
}

// sorted linkedlist to BST.
// we will solve it using vector for storing the array data and then easily access

Node *createBSTArr(vector<int> &arrLL, int start, int end)
{

    if (end < start)
    {
        return NULL;
    }

    int mid = start + (end - start + 1) / 2; // we are trying to get upper limit of mid

    Node *root = new Node(arrLL[mid]);
    root->left = createBSTArr(arrLL, start, mid - 1);
    root->right = createBSTArr(arrLL, mid + 1, end);

    return root;
}

Node *BSTfromLL(Node *root)
{

    // for here we are considering Node is the type which connecting in the linkedlist. //instead of next we will use right as next in node of linkedlist.

    // Preserve the original head pointer
    Node *temp = root;

    vector<int> arrLL;

    while (temp)
    {
        arrLL.push_back(temp->data);
        temp = temp->right;
    }

    // form this arry vector we will form BST

    root = NULL;

    int start = 0;
    int end = arrLL.size() - 1; // index end is to be given

    root = createBSTArr(arrLL, start, end);

    return root;
}

// Another method

Node *sortedListToBST(Node *head)
{
    // 1. Base Case: Empty list
    if (!head)
        return nullptr;

    // 2. Base Case: Single node in the list
    if (!head->right)
        return new Node(head->data);

    // 3. Find the middle of the linked list using two pointers
    Node *slow = head, *fast = head, *prev = nullptr;

    while (fast && fast->right)
    {
        prev = slow;               // Keeps track of the node BEFORE slow
        slow = slow->right;        // Moves one step at a time
        fast = fast->right->right; // Moves two steps at a time
    }
    // When the loop ends, 'slow' is at the middle node.

    // 4. 'prev' now points to the node before the middle.
    //    We break the list into two parts by setting prev->right to NULL.
    //    This creates the left sub-list: from 'head' to 'prev'.
    if (prev)
        prev->right = nullptr;

    // 5. Create the root node using the data from the middle node.
    Node *root = new Node(slow->data);

    // 6. Recursively build the left subtree from the left half of the list.
    //    The left half is the original list from 'head' up to 'prev' (which we just set to NULL).
    root->left = sortedListToBST(head);

    // 7. Recursively build the right subtree from the right half of the list.
    //    The right half starts from the node after the middle ('slow->right').
    root->right = sortedListToBST(slow->right);

    return root;
}

//  Merge two BST
Node *mergeTwoBST(Node *root1, Node *root2)
{

    vector<int> ans1;
    vector<int> ans2;

    inorderBST(root1, ans1);
    inorderBST(root2, ans2);

    vector<int> ans;
    int i = 0, j = 0;

    while (i < ans1.size() && j < ans2.size())
    {
        // merging these two vectors
        if (ans1[i] < ans2[j])
        {

            // ans.push_back(ans1[i]);
            // i++;

            // or we can write it combining

            ans.push_back(ans1[i++]);
        }
        else
        {
            ans.push_back(ans2[j++]);
        }
    }

    while (i < ans1.size())
    {
        // it may be possible that all ans1 not filled, hence they should be filled first.
        ans.push_back(ans1[i++]);
    }

    while (j < ans2.size())
    {

        ans.push_back(ans2[i++]);
    }

    // now we need to cree the BST again from this vector.
    // form this arry vector we will form BST

    Node *root = NULL;

    int start = 0;
    int end = ans.size() - 1; // index end is to be given

    root = createBSTArr(ans, start, end);

    return root;
}

int main()
{
    Node *root = NULL;

    int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
    root = createBST(root, arr, sizeof(arr) / sizeof(arr[0]));

    // let's traverse inorder
    inorder(root);
    cout << endl;

    //  method 2 using recursion
    root = NULL;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        Node *n = new Node(arr[i]); // we could have created it even in the function call, hence just needed to pass value
        root = insertNode(root, n);

        // root = insertNode(root, arr[i]);
    }

    inorder(root);
    cout << endl;

    // delete the values
    root = deleteNode(root, 5);

    // isBST
    cout << "ISBST" << checkBST(root) << endl;
    int prevMIN = INT32_MIN;
    cout << "ISBST" << checkBSTImproved(root, prevMIN) << endl;

    // Minimum distance between any two nodes
    int ans = INT32_MAX;
    int prev = INT32_MIN;
    ans = minDistance(root, ans, prev);

    //   improved method
    minDistanceImp(root, ans, prev);

    // sum of k smallest
    int K = 3;
    int ans = 0;
    cout << "Sum of first " << 3 << " smallest elements: " << ans << endl;

    cout << kthLargestElement(root, K) << endl;

    vector<int> preorderBST;
    preOrderOfBalanceBSTArr(root, arr, 0, sizeof(arr) / sizeof(arr[0]), preorderBST);

    root = NULL;
    root = NULL;
    preOrderOfBalanceBSTArrImp(root, arr, 0, sizeof(arr) / sizeof(arr[0]), preorderBST);

    root = NULL;
    int indexI = 0;
    root = BSTFrompreOrder(INT32_MIN, INT32_MAX, preorderBST, indexI);

    root = NULL;
    vector<int> postOrderBST = {1, 7, 5, 50, 40, 10};
    indexI = postOrderBST.size() - 1;
    root = BSTFrompostOrder(INT32_MIN, INT32_MAX, postOrderBST, indexI);

    bool ansPreBST = 1;
    indexI = 0;
    preOrderBSTCheck(INT32_MIN, INT32_MAX, preorderBST, indexI, ansPreBST);
    cout << " preOrderBST :  " << ansPreBST << endl;

    if (indexI == preorderBST.size() - 1)
    {
        cout << " preOrderBST :  " << ansPreBST << endl;

        // return indexI == preorderBST.size() - 1;
    }

    // using two stack
    preOrderBSTStack(preorderBST);

    // using standered method of pushing for preorder traverrsal
    preOrderBSTStackStd(preorderBST);

    // using one stack,
    preOrderBST1StackStd(preorderBST);

    // lowest common ancestor in a BST
    Node *commonNode = lowestCommonAncestor(root, 34, 56);

    // print BST element in given range
    elementIngivenRange(root, 12, 46);
    elementIngivenRangeTogether(root, 12, 46);

    // Check whether BST contains Dead End
    deadEndNode(root);
    deadEndCheck(root, INT32_MIN, INT32_MAX);
    deadEndCheckImp(root, INT32_MIN, INT32_MAX);
    deadEndNodeCusto(root, INT32_MIN, INT32_MAX);

    // Common Node in two BST
    vector<int> commonNodesList = commonNodes(root, root);

    //  sorted linkedlist to BST.
    Node *tree;
    tree = BSTfromLL(root);

    //  Merge two BST
    root = mergeTwoBST(tree, root);

    return 0;
}