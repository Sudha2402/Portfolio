// all tree, binary tree related terms.
// height of bootom is 0 and level of root is 0
// level wise tree creation with -1 as no child of its
// let's create tree using queue

#include <iostream>
using namespace std;
#include <queue>
#include <deque>
#include <cmath>

// Create tree level wise and side wise and using recursion
// In order, preorder, postorder traversal
// level wise traversal
// binary size
// binary sum
// Count leafs in binary tree
// Count non leafs in binary tree
// height of binary tree
// largest value in each level
// two tree are identical
// Mirror tree
// Check for balance tree
// level order traversal in spiral form

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

Node *createTreeLevel()
{
    cout << "Enter the root element :";
    int data;
    queue<Node *> Q;
    cin >> data;
    Node *root = new Node(data);
    Q.push(root);

    while (!Q.empty())
    {
        Node *parent = Q.front();
        Q.pop();

        cout << "Enter the left element of " << parent->data << ":";
        cin >> data;
        if (data != -1)
        {
            parent->left = new Node(data);
            Q.push(parent->left);
        }

        cout << "Enter the right element of " << parent->data << ":";
        cin >> data;
        if (data != -1)
        {
            parent->right = new Node(data);
            Q.push(parent->right);
        }
        // else{
        //     parent->right=NULL;
        // }
    }

    return root;
}

Node *createTreeSide()
{
    cout << "Enter the root element :";
    int data;
    deque<Node *> Q;
    cin >> data;
    Node *root = new Node(data);
    Q.push_back(root);
    Node *parent;

    while (!Q.empty())
    {
        parent = Q.back();

        if (parent->left == NULL)
        {
            cout << "Enter the left element of " << parent->data << ":";
            cin >> data;
        }
        else
        {
            data = -1;
        }

        while (data != -1)
        {
            parent->left = new Node(data);
            Q.push_back(parent->left);

            parent = Q.back();
            cout << "Enter the left element of " << parent->data << ":";
            cin >> data;
        }

        // now move to the right part of the last node

        // if (parent->right == NULL)
        // { //we Infer to op as soon as element get's it right element, so that if we left it's left null then in backtrack it will ask for the left as we have left it null.
        parent = Q.back();
        cout << "Enter the right element of " << parent->data << ":";
        cin >> data;
        // }
        // else
        // {
        //     data = -1;
        // }

        if (data != -1)
        {
            parent = Q.back();
            parent->right = new Node(data);
            Q.pop_back(); // right bharte hi popback
            Q.push_back(parent->right);
        }
        else
        {
            Q.pop_back();
        }
    }

    return root;
}

// Base Case: When val == -1, return NULL
// Recursive Case:
// Create a new Node *parent with the value
// Recursively create left subtree and assign to parent->left
// Recursively create right subtree and assign to parent->right
// Return the parent pointer so the caller can link it

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

    return parent; // even without returning this statement , it is because garbage it returning the proper address as it is in heap. Hence it is not recommended to skip this line

    // if statements are not used then only linking will not happen but executuion of output ok.

    //     No, it won't get stuck - it will complete execution, but:

    // The tree structure in memory is actually built correctly (all nodes exist with proper left/right pointers)

    // But the return addresses are garbage, so the caller might not get the right root address

    // If by chance the garbage returned equals the actual root address, then printTree() will work

    // If the garbage is wrong, printTree() might crash or print nonsense
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

// In order Traversal
void InOrderAns(Node *parent, vector<int> &ans) // ans for storing the result
{
    if (parent == NULL)
    {
        return;
    }

    InOrderAns(parent->left, ans);
    cout << parent->data << " ";
    ans.push_back(parent->data);
    InOrderAns(parent->right, ans);
}

// Pre order Traversal
void PreOrder(Node *parent)
{

    cout << parent->data << " ";

    if (parent->left != NULL)
    {
        PreOrder(parent->left);
    }

    if (parent->right != NULL)
    {
        PreOrder(parent->right);
    }
}

// Post order Traversal
void PostOrder(Node *parent)
{

    if (parent->left != NULL)
    {
        PostOrder(parent->left);
    }

    if (parent->right != NULL)
    {
        PostOrder(parent->right);
    }

    cout << parent->data << " ";
}

// Note , recursion do not need return statement for moving bakc to hte last class when popping down in heap stack, it will automatically comback without returning anything

// level wise traversal
vector<int> printTree(Node *root)
{

    // we are using queue
    queue<Node *> Q;
    Q.push(root);
    Node *parent;

    vector<int> ans;

    while (!Q.empty())
    {

        cout << Q.front()->data << " ";
        ans.push_back(Q.front()->data);
        parent = Q.front();

        if (parent->left != NULL)
        {
            Q.push(parent->left);
        }
        if (parent->right != NULL)
        {
            Q.push(parent->right);
        }

        Q.pop();
    }

    cout << endl;

    // space complexity is according to the number of leaf node.
    // if it is complete ninary three then maximum number of leaf nodes possible= (number of nodes/2) +1

    return ans;
}

// size of binary tree
int binarySize(Node *parent, int &count)
{
    if (parent == NULL)
    {
        return 0;
    }
    count++; // as root not null then it will itself be in size hence count increment

    // let's check if root->left and  root->right exist
    binarySize(parent->left, count);
    binarySize(parent->right, count);

    // return count;//just for returning but as we have passed address, direct count print from outside will have it's answer
}

int binarySizeSingle(Node *parent)
{
    if (parent == NULL)
    {
        return 0;
    }
    // count++; // as root not null then it will itself be in size hence count increment

    // // let's check if root->left and  root->right exist
    // binarySize(parent->left, count);
    // binarySize(parent->right, count);

    return (1 + binarySizeSingle(parent->left) + binarySizeSingle(parent->right));

    // here don't confuse that we are getting 0 it return instead of count, actuall all counts are because of the very first time 1

    // for root: 1 + left call+ right call
    // from left call, again 1 + left call+ right call happens, if left call and right call return 0 then overall this time we have 1, it will return back and add up in last time left call, then right call from there happens, if right call is -1 the 0 retruns, hence 1+1+0 at last will be ans// hence 2 is ans

    // after observing whole, we can get this way.
}

// Sum of Binary Tree
int binarySum(Node *parent)
{
    if (parent == NULL)
    {
        return 0;
    }

    return (parent->data + binarySum(parent->left) + binarySum(parent->right));
}

// Sum of Binary Tree with seperate sum count
int binarySumSep(Node *parent, int &sum)
{
    if (parent == NULL)
    {
        return 0;
    }

    sum += parent->data;
    binarySumSep(parent->left, sum);
    binarySumSep(parent->right, sum);

    // return (parent->data + binarySum(parent->left) + binarySum(parent->right));

    // return sum;//it is just for returning, we can ignore it.//
}

// Base case 1: If parent == NULL, returns 0 (empty tree or null child)
// Base case 2: If both children are NULL, returns 1 (found a leaf node)
// Recursive case: Recursively counts leaves in left and right subtrees and sums them

int leafsCount(Node *parent)
{
    if (parent == NULL)
    {
        return 0;
    }
    int count = 0; //// ERROR: 'count' is undeclared! , here this initialization works only when new side is being visited.

    if (parent->left == NULL && parent->right == NULL)
    {
        return 1;
    }
    count += leafsCount(parent->left);
    count += leafsCount(parent->right);

    return count; // only for returning at last when count passed as parameter, we could have used count & paremeter also.
                  //  // ERROR: Missing return statement for non-void function!

    //     return count; statement is essential because:
    //
    // It propagates the result upwards through the recursion stack
    //
    // Each recursive call needs to return its count to the parent call
    //
    // Without it, the computed value gets lost
}

int leafsCountSingle(Node *parent)
{
    if (parent == NULL)
    {
        return 0;
    }
    if (parent->left == NULL && parent->right == NULL)
    {
        return 1;
    }
    return leafsCountSingle(parent->left) + leafsCountSingle(parent->right);
}

// we can do count ++ in anothyer loop als

void leafsCountAdd(Node *parent, int &count)
{
    if (parent == NULL)
    {
        return;
    }

    if (parent->left == NULL && parent->right == NULL)
    {
        count++; // single time increment takes place
        return;
    }
    leafsCount(parent->left);
    leafsCount(parent->right);
}

// non leaf count

int nonleafsCountSingle(Node *parent)
{
    if (parent == NULL)
    {
        return 0;
    }

    if (parent->left == NULL && parent->right == NULL)
    {
        return 0;
    }

    //    if (parent->left != NULL || parent->right != NULL) {
    return 1 + nonleafsCountSingle(parent->left) + nonleafsCountSingle(parent->right); // this way of increment ing +1 is helpful, when we hqave to form the case
                                                                                       //    }
                                                                                       // else{
                                                                                       //	retrun 0;
                                                                                       //}
}

int nonleafsCountAno(Node *parent)
{
    if (parent == NULL)
    {
        return 0;
    }

    if (parent->left != NULL || parent->right != NULL)
    {
        return 1 + nonleafsCountAno(parent->left) + nonleafsCountAno(parent->right); // this way of increment ing +1 is helpful, when we hqave to form the case

        // return 1 + recursiveCall() is exactly the right pattern for counting nodes that satisfy a condition! This is a standard recursion technique where:

        //+1 counts the current node
        //
        // recursiveCall() accumulates counts from subtrees
    }
    else
    {
        return 0;
    }

    
}

// height of binary tree
int heightOfTree(Node *parent)
{
    if (parent == NULL)
        return 0;
    int height = 0;
    //    height = max(max(height, 1+heightOfTree(parent->left)), max(height, 1+heightOfTree(parent->right)));

    //                 "	max(0, 1+heightOfTree(X)) is always equal to 1+heightOfTree(X) since 0 is the minimum
    //"	You're doing max(0, X) unnecessarily for both subtrees
    //"	This adds unnecessary comparisons and function calls
    // For a large tree, your code makes twice as many max() comparisons as needed:
    // Your code: 2 max() operations per node + redundant comparisons with height=0
    // Standard code: 1 max() operation per node

    height = max(1 + heightOfTree(parent->left), 1 + heightOfTree(parent->right));
    // This is mathematically equivalent to the standard approach and will give the correct height.
    // here as we are adding 1 in both hence we can make it common

    // height =1 + max( heightOfTree(parent->left), heightOfTree(parent->right));     //this is simple and efficient, we could have write return here also
    //
    //
    //     return height;

    return height = 1 + max(heightOfTree(parent->left), heightOfTree(parent->right)); // we could have calculated left part and right part seperately also, then max

    int left = heightOfTree(parent->left);
    int right = heightOfTree(parent->right);

    return height = 1 + max(left, right);
}

// largest value in one level
// we can pop in order of 2
vector<int> largestAtLevelWrong(Node *parent, int sizeOfBinary)
{
    if (!parent)
        return {};

    queue<Node *> Q;
    vector<int> ans;

    Node *root = parent;
    Q.push(root);

    Node *frontNode = Q.front();

    int largest = frontNode->data;
    ans.push_back(largest); // 0 power pushed first
    Q.pop();
    if (frontNode->left)
        Q.push(frontNode->left);
    if (frontNode->right)
        Q.push(frontNode->right);

    // while (!Q.empty())
    // {
    // as here we need level wise pop hence pop on bases of level.

    // we need to get the total number of nodes for calculating the max level possible.

    // pop and push it's left and right

    // here actually we missed the observation where the size of Q shows the number of elements at that level.

    for (int i = 1; pow(2, i) <= sizeOfBinary && !Q.empty(); i++)
    {

        // pow(2, i) <= sizeOfBinary not work good in tracking the level, hence we should use another approch where level can be checked //it would have worked if we calculated the levels insetead of elements or size of tree.

        //             Test case where it fails:
        //             Tree:
        //         1
        //        / \
//       2   3
        //      /     \
//     4       5
        //    /
        //   6

        // sizeOfBinary = 6
        // This tree has 4 levels, but:

        // pow(2,1)=2 <= 6 ✓ (level 1)

        // pow(2,2)=4 <= 6 ✓ (level 2)

        // pow(2,3)=8 <= 6 ✗ (stops at level 2)

        largest = INT32_MIN;
        int limit = 2 * i;
        while (!Q.empty() && limit--)
        {

            frontNode = Q.front();
            largest = max(largest, frontNode->data);
            Q.pop();
            if (frontNode->left)
                Q.push(frontNode->left);
            if (frontNode->right)
                Q.push(frontNode->right);
        }

        ans.push_back(largest);
    }
    // }
}

// this is good way //BFS Approach is Still Superior:
vector<int> largestAtLevel(Node *parent)
{
    if (!parent)
        return {}; // empty vector

    queue<Node *> Q;
    vector<int> ans;

    Node *root = parent;
    Q.push(root);

    Node *frontNode;
    int largest;

    while (!Q.empty())
    {

        int limit = Q.size(); // level size
        largest = INT32_MIN;
        // for (int i = 0; i < Q.size(); i++)
        for (int i = 0; i < limit; i++)
        { // Q.size() changes everytime, hence we need to store the last time Q size

            frontNode = Q.front();

            largest = max(largest, frontNode->data);
            Q.pop();
            if (frontNode->left)
                Q.push(frontNode->left);
            if (frontNode->right)
                Q.push(frontNode->right);
        }
        ans.push_back(largest);
    }

    return ans;
}

int isIdenticalWrong(Node *tree, Node *root)
{

    int checkfurther = 0;

    if (!tree && !root)
    {
        checkfurther = 1;
        // return 1;//backtrack
    }
    else if (!tree || root && tree || !root)
    {
        checkfurther = 0;
        return 0; // nodes not identical identical
    }

    if (tree && root && tree->data == root->data)
    {
        checkfurther = 1;
        // here you have used the return 1 part which is not ideal, return only if reached to end and NULL, then it confirms that no more changes can be made in that row.
    }
    else
    {
        checkfurther = 0;
        return 0;
    }

    while (checkfurther && tree->left && root->left)
    {

        isIdentical(tree->left, root->left); // here using while loop for backtrack is not good
    }

    while (checkfurther && tree->right && root->right)
    {
        isIdentical(tree->right, root->right);
    }

    if (checkfurther)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isIdentical(Node *tree, Node *root)
{

    if (!tree && !root)
    {

        return 1; // backtrack
    }

    //	if(!tree || root && tree || !root){
    if (!tree || !root)
    {

        return 0; // nodes not identical identical
    }

    if (tree->data != root->data)
    {

        return 0;
    }

    //		if(tree->left&& root->left){//it is already hanfdles at start, if null passed, it will check there itself

    int identicalLeft = isIdentical(tree->left, root->left);
    //		}

    int identicalRight = isIdentical(tree->right, root->right);

    return identicalLeft && identicalRight;

    // or

    //	return isIdentical(tree->left, root->left) &&  isIdentical(tree->right, root->right);
}

Node *mirrorTreeWrong(Node *parent)
{
    // here are change the main address hence overall reflect chenges in output //here we have used much complex if , else which is not actually needed.
    // we could have moved to left part untill null, then then return to last node, then move to rightside until null present in right branch null, here ae are getting to the bottom most node int tree. then swap, finally it returns the node it has swapped.
    // here what we are doing wrong is , we swapped once left part if null, then it might be possible that the right part we have swapped in in left now and the left which we have swappt has moved to right hence same left part will as now right will be checked , and then when it returns NULL

    //     1
    //    / \
//   3    2
    //   \   / \
//    6 5   4
    //     \
//      7

    //    here 3 has swapped with and then 3 right part is checked and it will return and moved to 1 but here 7 is never checked, hence it is worng
    //     1
    //    / \
//   3    2
    //  /   / \
// 6   5   4
    // /
    // 7

    // hence we have to move to the deepest node possible whose left and right node both tracked to the end then swap and moved above,

    if (!parent)
    {
        return NULL;
    }

    mirrorTreeWrong(parent->left); // here it will swap only from level one but level two also has to swap

    Node *temp;
    if (parent->right) // right part is set to null , hence it will create no problem. No need to use if condition
    {
        temp = parent->right;
    }
    else
    {
        temp = NULL;
    }
    if (parent->left)
    {
        parent->right = parent->left;
    }
    else
    {
        parent->right = NULL;
    }
    parent->left = temp;

    mirrorTreeWrong(parent->right);

    return parent; // not necessary
}

Node *mirrorTree(Node *parent)
{
    if (!parent)
    {
        return NULL;
    }

    // First recursively mirror both subtrees
    mirrorTree(parent->left);
    mirrorTree(parent->right);

    // Then swap the left and right pointers
    Node *temp = parent->left;
    parent->left = parent->right;
    parent->right = temp;

    return parent; // Return the mirrored node
}

// using top to bottom approch, as we have swap from top, we will not be back at this node, hence return not possible
void mirrorTreeTopToBottom(Node *parent)
{
    if (!parent)
    {
        return;
    }

    // Then swap the left and right pointers
    Node *temp = parent->left;
    parent->left = parent->right;
    parent->right = temp;

    // First recursively mirror both subtrees
    mirrorTreeTopToBottom(parent->left);
    mirrorTreeTopToBottom(parent->right);
}

// using bottom to top approch,
void mirrorTreeBottomToTop(Node *parent)
{
    if (!parent)
    {
        return;
    }

    // First recursively mirror both subtrees
    mirrorTreeBottomToTop(parent->left);
    mirrorTreeBottomToTop(parent->right);

    // Then swap the left and right pointers
    Node *temp = parent->left;
    parent->left = parent->right;
    parent->right = temp;
}

int isImbalance(Node *parent)
{
    if (!parent)
    {
        return 0; // as it is returning for height also , hence we beterr check parent null when passing, then return there only.
    }

    int heightLeft = 1 + isImbalance(parent->left);
    int heightRight = 1 + isImbalance(parent->right);

    if (abs(heightLeft - heightRight) > 1)
    {
        // not valid
        return 0;
    }
    else
    {
        int height = max(heightLeft, heightRight);
        return height;
    }
}

int heightOfTreePart(Node *parent)
{
    if (!parent)
    {
        return 0;
    }

    int heightLeft = 1 + heightOfTreePart(parent->left);
    int heightRight = 1 + heightOfTreePart(parent->right);
    int height = max(heightLeft, heightRight);
    return height;
}

int isBalanced(Node *parent)
{
    if (!parent)
    {
        return 1; // as it is returning for height also , hence we beterr check parent null when passing, then return there only.
    }

    int heightLeft = heightOfTreePart(parent->left);
    int heightRight = heightOfTreePart(parent->right);
    // it will give the answer of left hight of root completel in one go and similarly, we can get it for right part in one go. then one comparision is needed.  Actually I got the point, we shold check the height at each level instead only at top.

    // there are many cases in which left and right part of lower nodes not balance hence calculating in one go is not right approch

    // complete calculation at a time, no recursion , here, it will be in height

    if (abs(heightLeft - heightRight) > 1)
    {
        // not valid
        return 0;
    }
    else
    {
        return isBalanced(parent->left) && isBalanced(parent->right); // here it will move to next left bottom, as after comparing with top one //Efficiency: Your isImbalance has O(n²) time complexity due to repeated height calculations
    }
}

// let's combine height calculation and isBalance together
int isBalancedOptimizedWrongReturn(Node *parent)
{

    if (!parent)
    {
        return 0; // as it is returning for height also , hence we beterr check parent null when passing, then return there only.
    }

    int heightLeft = 1 + isBalancedOptimizedWrongReturn(parent->left);
    // if it has receive -1 then immidiately exit with continous retrun -1
    if (heightLeft == 0)
    {
        return -1;
    }

    //     Error 0 gets "lost" when you do 1 + error(0) = 1

    // No way to distinguish between valid height 1 and error-converted-to-1

    // Error propagation fails completely

    int heightRight = 1 + isBalancedOptimizedWrongReturn(parent->right);
    if (heightRight == 0)
    {
        return -1;
    }

    // complete calculation at a time, no recursion , here, it will be in height

    if (abs(heightLeft - heightRight) > 1)
    {

        // not valid
        return -1; // exit//it will return 0 as its keep decrementing hence reach to 0 in last call.
    }
    else
    {
        int height = max(heightLeft, heightRight);
        return height;
    }

    // 1. Mixed Return Types:
    // Sometimes returns height (positive integer)

    // Sometimes returns error code (-1)

    // This creates ambiguity in the return value
}

// let's combine height calculation and isBalance together
int isBalancedOptimized(Node *parent)
{
    if (!parent)
    {
        return 0; // as it is returning for height also , hence we beterr check parent null when passing, then return there only.//
    }

    // height we will retrun after getting that -1 has been returned from last call
    int leftPartHeight = isBalancedOptimized(parent->left); // returned value height is stored here directly, means for this node parent , we have the height. hence when 0 and 0 moved the height comes is 1, this 1 is the height of it's parent which called it will get and returned answer will be height of parent and then after it;s execution it retruns the height for it's parent and that retruned value will be used by parent for leftPartHeight - rightPartHeight

    if (leftPartHeight == -1)
    {
        return -1;
    }

    int rightPartHeight = isBalancedOptimized(parent->right);
    if (rightPartHeight == -1)
    {
        return -1;
    }

    // reached to bottom most then retrun back, at bottom both are 0 hence leftPartHeight - rightPartHeight=0

    if (abs(leftPartHeight - rightPartHeight) > 1)
    {
        // not valid
        return -1; // exit//keep passing it to the last time call next and return form there
    }
    else
    {
        int height = 1 + max(leftPartHeight, rightPartHeight);
        return height; // atleast eight will be returned with +1 means all level node counted. if level 4 then it returns 4.level 1 to 4 like that.
    }
}

int isbalanceHeight(Node *parent, int &valid)
{

    if (!parent)
    {
        return 0;
    }

    int leftHeight = isbalanceHeight(parent->left, valid);

    // we can avoid calculating right part if not valid

    if (valid) // this way minimise the cycle doing wastage on checking right even if we get the not valid.
    {
        int rightHeight = isbalanceHeight(parent->right, valid);

        if (abs(leftHeight - rightHeight) > 1)
        {
            valid = 0;
            // return -1;//no such sense when we are not passing in further call, insted it will disturb the height calculation.
        }

        return 1 + max(leftHeight, rightHeight);
    }
    return -1;
}

// If we are finding this hard to propogate the return value for invalid then we can use valid parameter
int isbalance(Node *parent)
{
    if (!parent)
    {
        return 1;
    }

    int valid = 1;
    isbalanceHeight(parent, valid);
    return valid;
}

// level order traversal in Spiral Form
vector<int> levelTraversalSpiral(Node *parent)
{

    vector<int> ans;
    deque<Node *> Q;

    // let's take root as traversed from  right to left
    Q.push_front(parent);
    // ans.push_back(parent->data);//
    int levelsize;
    Node *temp;

    while (!Q.empty())
    {

        // traverse right to left
        levelsize = Q.size();

        for (int i = 0; i < levelsize; i++)
        {
            temp = Q.back();
            ans.push_back(temp->data);
            Q.pop_back();

            if (temp->right)
            {
                Q.push_front(temp->right);
            }
            if (temp->left)
            {
                Q.push_front(temp->left);
            }
        }

        // traverse left to right
        levelsize = Q.size();
        for (int i = 0; i < levelsize; i++)
        {
            temp = Q.front();
            ans.push_back(temp->data);
            Q.pop_front();
            if (temp->left)
            {
                Q.push_back(temp->left);
            }
            if (temp->right)
            {
                Q.push_back(temp->right);
            }
        }
    }

    return ans;
}

// more clear with toggle
vector<int> levelSpiralTraversal(Node *parent)
{

    // here We are starting from right to left. hence it is rverse of general pattern left to right at first

    vector<int> ans;
    deque<Node *> Q;

    // let's take root as traversed from  right to left
    Q.push_front(parent);
    // ans.push_back(parent->data);//
    int levelsize;
    Node *temp;

    int rightToLeft = 1;

    while (!Q.empty())
    {

        // traverse right to left
        levelsize = Q.size();

        if (rightToLeft)
        {
            for (int i = 0; i < levelsize; i++)
            {
                temp = Q.back();
                ans.push_back(temp->data);
                Q.pop_back();

                if (temp->right)
                {
                    Q.push_front(temp->right);
                }
                if (temp->left)
                {
                    Q.push_front(temp->left);
                }
            }
        }

        // traverse left to right
        // levelsize = Q.size();
        else
        {

            for (int i = 0; i < levelsize; i++)
            {
                temp = Q.front();
                ans.push_back(temp->data);
                Q.pop_front();
                if (temp->left)
                {
                    Q.push_back(temp->left);
                }
                if (temp->right)
                {
                    Q.push_back(temp->right);
                }
            }
        }

        // toggle rightToLeft
        rightToLeft = !rightToLeft; // if 1 then 0 if 0 then 1
    }

    return ans;
}

int main()
{
    Node *tree = createTreeLevel();
    printTree(tree); // 3 4 2 4 2 3 2
    // Node *tree2 = createTreeSide();

    // for recursion, we need to pass the root for initialization
    cout << "Enter the root element :";
    // int data;
    // cin >> data;
    // Node *root = createTreeSideRec(data);
    Node *root = createTreeSideRec();
    cout << "Ilevel print: ";
    printTree(root); // 1 2 7 3 6 8 4 5 9 10

    // print the tree
    cout << "InOrder: ";
    InOrder(root); //
    cout << endl;

    vector<int> ans;
    cout << "InOrderAns: ";
    InOrderAns(root, ans);
    cout << endl;

    // ans has all data
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    cout << "PreOrder: ";
    PreOrder(root);
    cout << endl;
    cout << "PostOrder: ";
    PostOrder(root);
    cout << endl;

    int sizeOfBinary = 0;
    // cout << "size of binary tree is: " << binarySize(root, sizeOfBinary); // size of binary tree is: 10//we we don't use retrun , as we passed & , we can directly call

    binarySize(root, sizeOfBinary);
    cout << "size of binary tree is: " << sizeOfBinary << endl;

    sizeOfBinary = binarySizeSingle(root);
    cout << "size of binary tree is: " << sizeOfBinary << endl;

    // binary Sum
    int binarySumData = binarySum(root);
    cout << "Sum of binary tree is: " << binarySumData << endl;

    binarySumData = 0;
    // binarySumData = binarySumSep(root, binarySumData);//as we have stopped return, we can simply return it.
    binarySumSep(root, binarySumData);
    cout << "Sum of binary tree is: " << binarySumData << endl;

    cout << "leaf count: " << leafsCount(root) << endl;
    cout << "leaf count: " << leafsCountSingle(root) << endl;

    int leafcount = 0;
    leafsCountAdd(root, leafcount);
    cout << "leaf count: " << leafcount << endl;

    cout << "Non leaf count: " << nonleafsCountSingle(root) << endl;
    cout << "Non leaf count: " << nonleafsCountAno(root) << endl;

    // height of tree
    int heightOfTreeCount = heightOfTree(root);
    cout << "height of tree is: " << heightOfTreeCount << endl;

    // ans = largestAtLevelWrong(root, sizeOfBinary);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    ans = largestAtLevel(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    //    identical Nodes
    // Check if two tree are identical or not

    cout << "Is both tree Identical: " << isIdentical(tree, root);

    root = mirrorTree(root);
    mirrorTreeTopToBottom(root); // make it back original.
    mirrorTreeBottomToTop(root); // again mirroring it

    root = mirrorTree(root);

    // Check for balance tree

    // we simply need to calculate the left height and right height and move from bottom to top, here we are interested in the diffrence if height gets greater than -1 and 1 means ans > 1 then it is imbalance , return

    cout << "Is  tree Imbalance: " << isImbalance(root) << endl;
    cout << "Is  tree Imbalance: " << isBalancedOptimized(root) << endl;
    cout << "Is  tree Imbalance: " << isbalance(root) << endl;

    // level order traversal in Spiral Form
    ans = levelSpiralTraversal(root);
    cout<<"Spiral traversal right to left then L->right";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    ans = levelTraversalSpiral(root);
     cout<<"Spiral traversal right to left then L->right";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
