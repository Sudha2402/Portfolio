#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <stack>
#include <algorithm> // Required for std::max_element

// Covid spread
// simplified Covid spread
// find the number of island
// Replace all O's or a group of 'O with X's that are surrounded by 'X
// prerequsite tasks
// Alien DICTIONARY
// parallel course
// Shortest path distance in undirected non weight graph
// Shortest path node sequence in undirected non weighted graph
// Shortest path dist from src in directed acyclic graph
// Dijkstra's Algorithm (3 ways)
// using queue, using for loop, using priority queue
// Shortest path node sequence in weighted undirected graph

// Covid spread // TC: m*n and SC : m*n
// using BFS
int covidSpreadTime(vector<vector<int>> &hospital)
{
    queue<pair<int, int>> q; // row and col will be pushed

    int count = 0;

    for (int i = 0; i < hospital.size(); i++)
    {
        for (int j = 0; j < hospital[i].size(); j++)
        {
            if (hospital[i][j] == 2)
            {
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty())
    {
        int sizeQ = q.size();
        count++;

        for (int i = 0; i < sizeQ; i++)
        {
            // we are going to push the neighbour
            pair<int, int> p = q.front();
            q.pop();

            // make the adjacent 1 to 2
            if (p.first > 0)
            {
                // top
                if (hospital[p.first - 1][p.second] == 1)
                {
                    hospital[p.first - 1][p.second]++;
                    q.push(make_pair(p.first - 1, p.second));
                }
            }
            if (p.first < hospital.size() - 1)
            {
                // move bottom
                if (hospital[p.first + 1][p.second] == 1)
                {
                    hospital[p.first + 1][p.second]++;
                    q.push(make_pair(p.first + 1, p.second));
                }
            }
            if (p.second > 0)
            {
                // move left
                if (hospital[p.first][p.second - 1] == 1)
                {
                    hospital[p.first][p.second - 1]++;
                    q.push(make_pair(p.first, p.second - 1));
                }
            }
            if (p.second < hospital[p.first].size() - 1) // second is coloumn hence all colums of same length we can use 0 directly
            {
                // move right
                if (hospital[p.first][p.second + 1] == 1)
                {
                    hospital[p.first][p.second + 1]++;
                    q.push(make_pair(p.first, p.second + 1));
                }
            }
        }

        // after finishing loop let's check whether q has element or not. suppose it became empty then we need to check no 1 left
    }

    for (int i = 0; i < hospital.size(); i++)
    {
        for (int j = 0; j < hospital[i].size(); j++)
        {
            if (hospital[i][j] == 1)
            {
                return -1;
            }
        }
    }

    return count - 1; // At last we are decrementing the time by 1 because in the very last traversal before q empty, no new push is done then that initial added time needs to be returned.
}

// simplified Covid spread
// using BFS
int validRowCol(int r, int c, int row, int col)
{
    return r >= 0 && r < row && c >= 0 && c < col;
}

int covidSpreadTimeSimplified(vector<vector<int>> &hospital)
{
    queue<pair<int, int>> q; // row and col will be pushed

    int count = 0;

    for (int i = 0; i < hospital.size(); i++)
    {
        for (int j = 0; j < hospital[i].size(); j++)
        {
            if (hospital[i][j] == 2)
            {
                q.push(make_pair(i, j));
            }
        }
    }

    int r[4] = {-1, +1, 0, 0}; // top , bottom , left , right
    int c[4] = {0, 0, -1, +1}; // top , bottom , left , right

    // this is increment pair for row and col combination

    while (!q.empty())
    {
        int sizeQ = q.size();
        count++;

        for (int i = 0; i < sizeQ; i++)
        {
            // we are going to push the neighbour
            pair<int, int> p = q.front();
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                // also need to check the validity of new row,col
                if (validRowCol(p.first + r[j], p.second + c[j], hospital.size(), hospital[0].size()) && hospital[p.first + r[j]][p.second + c[j]] == 1)
                {
                    hospital[p.first + r[j]][p.second + c[j]] = 2;
                    q.push(make_pair(p.first + r[j], p.second + c[j]));
                }
            }
        }

        // after finishing loop let's check whether q has element or not. suppose it became empty then we need to check no 1 left
    }

    for (int i = 0; i < hospital.size(); i++)
    {
        for (int j = 0; j < hospital[i].size(); j++)
        {
            if (hospital[i][j] == 1)
            {
                return -1;
            }
        }
    }

    return count - 1; // At last we are decrementing the time by 1 because in the very last traversal before q empty, no new push is done then that initial added time needs to be returned.
}

//
//
// find the number of island

void numIslandsmainBfs(vector<vector<char>> &gridisland, queue<pair<int, int>> &q)
{

    int r[8] = {-1, +1, 0, 0, -1, +1, -1, +1}; // top , bottom , left , right , top-left , bottom-left , top-right, bottom-right

    int c[8] = {0, 0, -1, +1, -1, -1, +1, +1}; // top , bottom , left , right , top-left , bottom-left , top-right, bottom-right

    // this is increment pair for row and col combination

    while (!q.empty())
    {

        // we are going to push the neighbour
        pair<int, int> p = q.front();
        q.pop();

        for (int j = 0; j < 8; j++)
        {
            // also need to check the validity of new row,col
            if (validRowCol(p.first + r[j], p.second + c[j], gridisland.size(), gridisland[0].size()) && gridisland[p.first + r[j]][p.second + c[j]] == '1')
            {
                gridisland[p.first + r[j]][p.second + c[j]] = '2'; // we are changing as it is traced
                q.push(make_pair(p.first + r[j], p.second + c[j]));
            }
        }
    }

    return;
}

int numIslands(vector<vector<char>> &gridisland)
{
    queue<pair<int, int>> q; // row and col will be pushed

    int count = 0;

    // start from top left corner 0,0

    for (int i = 0; i < gridisland.size(); i++)
    {
        for (int j = 0; j < gridisland[i].size(); j++)
        {
            if (gridisland[i][j] == '1')
            {
                // start island count from here
                count++;
                q.push(make_pair(i, j));
                // make this pair 2
                gridisland[i][j] = '2';

                numIslandsmainBfs(gridisland, q); // it will make all connect to 2 for not getting track next time. keep on checking the next initial point

                // BFS start here and go throughout the node
            }
        }
    }

    return count;
}

// Replace all O's or a group of 'O with X's that are surrounded by 'X

void fillXOResultmainBfs(vector<vector<char>> &fillXO, queue<pair<int, int>> &q)
{
    int r[4] = {
        -1,
        +1,
        0,
        0,
    }; // top , bottom , left , right  // Only 4 directions needed as it flows horizonally and verticall.

    int c[4] = {
        0,
        0,
        -1,
        +1,
    }; // top , bottom , left , right

    // this is increment pair for row and col combination

    while (!q.empty())
    {

        // we are going to push the neighbour
        pair<int, int> p = q.front();
        q.pop();

        for (int j = 0; j < 4; j++)
        {
            // also need to check the validity of new row,col
            if (validRowCol(p.first + r[j], p.second + c[j], fillXO.size(), fillXO[0].size()) && fillXO[p.first + r[j]][p.second + c[j]] == 'O')
            {
                fillXO[p.first + r[j]][p.second + c[j]] = 'T'; // we are changing as it is traced
                q.push(make_pair(p.first + r[j], p.second + c[j]));
            }
        }
    }

    return;
}

vector<vector<char>> fillXOResult(int m, int n, vector<vector<char>> &fillXO)
{
    queue<pair<int, int>> q; // row and col will be pushed

    // we have to traverse boundaries then bfs from there.

    // start from top row, bottom row, left col, right col

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && fillXO[i][j] == 'O') // boundary O and it's adjacent connected o can't be converted to X
            {

                q.push(make_pair(i, j));
                fillXO[i][j] = 'T';

                fillXOResultmainBfs(fillXO, q); // it will make all connect to 2 for not getting track next time. keep on checking the next initial point

                // BFS start here and go throughout the node
            }
        }
    }

    // now convert the rest O to X and T to O

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fillXO[i][j] == 'O')
            {
                fillXO[i][j] = 'X';
            }
            else if (fillXO[i][j] == 'T')
            {
                fillXO[i][j] = 'O';
            }
        }
    }

    return fillXO;
}

// prerequsite tasks

vector<int> topoSortBfsofGraph(int V, vector<int> adj[])
{

    vector<int> ans;
    queue<int> q;

    // we need to create an array for indegree track
    vector<int> indegree(V, 0);
    for (int j = 0; j < V; j++)
    {
        for (int i = 0; i < adj[j].size(); i++)
        {
            indegree[adj[j][i]]++;
        }
    }

    // push into queue those having indegree=0
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i); // for initialization
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int i = 0; i < adj[node].size(); i++)
        {
            indegree[adj[node][i]]--;
            if (indegree[adj[node][i]] == 0)
            {
                q.push(adj[node][i]);
            }
        }
    }

    return ans;
}

bool isPossiblePreRequisite(int N, int P, vector<pair<int, int>> &prerequisites)
{

    // first create adjacency list then find topological sort
    vector<int> adjlistArr[N];
    for (int i = 0; i < P; i++)
    {
        adjlistArr[prerequisites[i].second].push_back(prerequisites[i].first);

        // we can find indegree here directly instead of traversing the adjlist again but here as we have already created a finction which has this indegree calculation, hence we are not disturbing here.

        // indegree[prerequisites[i].first]++;
    }

    // topological sort (DAG- Directed acyclic graph) using BFS
    vector<int> topoSortbfs = topoSortBfsofGraph(N, adjlistArr);

    // if(topoSortbfs.size()==N){
    //     return 1;
    // }
    // else{
    //     return 0;
    // }

    return topoSortbfs.size() == N; // same as above if else
}

// Alien DICTIONARY

string findorderInAlienDict(string dict[], int N, int K)
{
    // N words//K alphabets hecne 0 to k-1 indexing size needed not 26.
    // dict is an array of string
    // vector<pair<char, char>> p;
    vector<pair<int, int>> p;

    // first create the pairs possible order.
    for (int i = 0; i < N; i++)
    {
        int j = i + 1;

        // for (int j = i + 1; j < N; j++) //your O(N²)
        // { //it might create dublicate pairs hence better to compare adjacent because canse will be still missed after comparing all.

        // after only adjacent comp, it take O(N)

        // Less efficient (O(N²) vs O(N))

        bool foundDiff = false; // no diiferent alpha found

        // I think we need to compare the same in next word and follow the sequence
        for (int k = 0; k < min(dict[i].length(), dict[j].length()); k++)
        {
            // compare the same index pairs
            if (dict[i][k] != dict[j][k])
            {

                // p.push_back(make_pair(dict[i][k], dict[j][k]));

                // let's push on the bases of indexing
                p.push_back(make_pair(dict[i][k] - 'a', dict[j][k] - 'a'));

                // it might be possible that some pairs are alredy present hence we would be needed to traverse the first and second pair present then push it, I think it would be better to make it unique at the time of creating adjacency list. doing this will have less travrsing

                foundDiff = true;

                // do nothing then

                break;
            }

            // continue;//no need as it will automatically continue
            // once equality over
        }

        // Handle case where word2 is prefix of word1 (invalid ordering)
        if (!foundDiff && dict[i].length() > dict[j].length())
        {

            // it may be a case in this ordering but if it is valid dictionary then it will never happen, it is good to leave faster and reduce the time complexity

            return "0"; // Invalid dictionary
        }
        // }
    }

    // create adjaceny list from pairs in vector
    vector<int> adjlistArr[K]; // k alphabets already mentioned

    for (int i = 0; i < p.size(); i++)
    {
        // let's traverse
        bool present = 0;
        for (int j = 0; j < adjlistArr[p[i].first].size(); j++)
        {
            if (adjlistArr[p[i].first][j] == p[i].second)
            {
                present = 1;
                break;
            }
        }

        if (!present)
        {
            adjlistArr[p[i].first].push_back(p[i].second);
        }
    }

    // after creating adjaceny list , we just need topological sort order.
    vector<int> topoSortbfs = topoSortBfsofGraph(K, adjlistArr);

    if (topoSortbfs.size() == K)
    {
        // alphabet sequence is extracted
        // after this order we have to convert back to string
        string ans;

        for (int i = 0; i < topoSortbfs.size(); i++)
        {
            ans += topoSortbfs[i] + 'a';
        }

        return ans;
    }

    else
    {
        return "0";
    }
}

// parallel course
int minimumTimeCourse(int n, vector<vector<int>> &relations, vector<int> time)
{

    // let's make adjaceny list using relation
    // n course mans n vertex

    // when relation is such that it takes node from 1 to n not 0 to n-1 //return wrong result due to index errors

    vector<int> adjlistArr[n];

    for (int i = 0; i < relations.size(); i++)
    {
        // instead of pairs , vectors are present in it
        adjlistArr[relations[i][0] - 1].push_back(relations[i][1] - 1); //// Convert to 0-based indexing as relations given are 1 base
    }

    // let's consider the time calculation using indegree
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        // indegree relation
        for (int j = 0; j < adjlistArr[i].size(); j++)
        {
            indegree[adjlistArr[i][j]]++;
        }
    }

    // let's use indegree for time analysis
    queue<int> q;
    vector<int> timerCompl(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {

            q.push(i);

            // as we have decided to use completion n=time,it is better to push the time here

            timerCompl[i] = time[i]; // They take their own time
        }
    }

    // Note: Your timerPrev array is initialized to all zeros, but courses with no prerequisites should start with their own completion time, not zero.
    // Your timerPrev array tracks prerequisite completion time, but for courses with no prerequisites, it should be 0 (they can start immediately). However, you're not setting the initial completion time for courses that start immediately.

    // we will use the completion time storage.

    // vector<int> timerPrev(n, 0);
    // vector<int> timerCompl(n, 0);

    while (!q.empty())
    {
        // check the current size
        int nodes = q.size();

        // for (int i = 0; i < nodes; i++)
        // { //as we are visiting the queue every time then why it is need to get all indegree 0 at once, we can remove this for loop of i. we just need q.front

        // The only minor improvement would be storing q.front() in a variable for readability, but functionally your code is perfect.

        for (int j = 0; j < adjlistArr[q.front()].size(); j++)
        {
            indegree[adjlistArr[q.front()][j]] -= 1;

            // timerPrev[adjlistArr[q.front()][j]] = max(timerPrev[q.front()] + time[q.front()], timerPrev[adjlistArr[q.front()][j]]);

            timerCompl[adjlistArr[q.front()][j]] = max(timerCompl[q.front()] + time[adjlistArr[q.front()][j]], timerCompl[adjlistArr[q.front()][j]]);

            if (indegree[adjlistArr[q.front()][j]] == 0)
            {
                q.push(adjlistArr[q.front()][j]);
            }
        }

        q.pop();
        // }
    }

    // at last we will get the max value from the timerPrev and add it's own time then return the final result as exact time taken.
    // Your timerPrev array tracks prerequisite completion time, but for courses with no prerequisites, it should be 0 (they can start immediately). However, you're not setting the initial completion time for courses that start immediately.

    // int maxElementIndex = 0; // we start with 0 indexing
    // for (int i = 0; i < n; i++)
    // {
    //     if (timerCompl[i] > timerCompl[maxElementIndex])
    //     {
    //         maxElementIndex = i;
    //     }
    // }

    //

    // return timerprev[maxElementIndex] + time[maxElementIndex];
    // return timerCompl[maxElementIndex]; // this is for time completion

    return *max_element(timerCompl.begin(), timerCompl.end()); // inbuilt way of getting max from vector,* is for value at that max_element pointer. //#include <algorithm> // Required for std::max_element
}

// Shortest path in undirected graph

vector<int> shortestPathUndirectedDist(vector<vector<int>> &edges, int N, int M, int src)
{
    // here path means paths weight not node sequence.
    // here we need the shoetest path from sorce to each node and return the answer.

    // src is source or parent
    // we have to cover all the nodes and mark the shortes path
    // N is nodes , M is edges

    // Note:
    // I am thinking about the case when already visited find the min later than the old then we would be needed to traverse the path again by pushing this newly updated node into q. Give me a such test case to confirm that I am thinking right.

    // You're absolutely right! This is a crucial insight. In weighted graphs, we might need to revisit nodes, but in unweighted graphs with BFS, this should never happen.

    // Revisiting is Never Needed in Unweighted BFS

    // We explore nodes in increasing distance order from source
    // The first time we reach a node, we've found the shortest path
    // Any later path would be longer or equal

    // In unweighted graphs, BFS guarantees that when we first visit a node, we've found the shortest path. This is why Dijkstra's algorithm degenerates to BFS for unweighted graphs.

    vector<int> dist(N, INT32_MAX); // tracks the sortest path to each node from source

    // vector<int> visited(N, 0);
    // as we observe that visited has no need because dist other than max shows that it has been already visited by some other node but if good path is found then we can update.

    // bfs from this 0
    queue<int> q;
    q.push(src);
    // visited[src] = 1;
    dist[src] = 0;

    // let's create adjaceny list
    vector<int> adjlistArr[N];

    for (int i = 0; i < edges.size(); i++)
    {
        // we have 0 based indexing and node labels
        adjlistArr[edges[i][0]].push_back(edges[i][1]); // as it is undirected graph, then one edge is filled in two nodes

        // MISSING: adjlistArr[edges[i][1]].push_back(edges[i][0]);
        adjlistArr[edges[i][1]].push_back(edges[i][0]);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // mark the adjacent visited and push into the queue and also update the dist
        for (int i = 0; i < adjlistArr[node].size(); i++)
        {
            // if not visited then only push in the queue
            // if (!visited[adjlistArr[node][i]])
            if (dist[adjlistArr[node][i]] == INT32_MAX)
            {
                q.push(adjlistArr[node][i]);

                // visited[adjlistArr[node][i]] = 1;
                // dist[adjlistArr[node][i]] = min(dist[node] + 1, dist[adjlistArr[node][i]]);//no need of min

                dist[adjlistArr[node][i]] = dist[node] + 1; // no need of min
            }

            // dist[adjlistArr[node][i]] = min(dist[node] + 1, dist[adjlistArr[node][i]]); //Revisiting is Never Needed in Unweighted BFS // hence put in the condition
        }
    }

    return dist;
}

// Shortest path node sequence in undirected non weighted graph
vector<int> shortestPathNodeSeq(vector<pair<int, int>> edges, int N, int M, int src, int target)
{
    // s is source and t is target

    vector<int> dist(N, INT32_MAX);
    vector<int> Parent(N, -1);

    // bfs from this 0
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    // let's create adjaceny list
    vector<int> adjlistArr[N];

    for (int i = 0; i < edges.size(); i++)
    {
        adjlistArr[edges[i].first].push_back(edges[i].second);
        adjlistArr[edges[i].second].push_back(edges[i].first);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < adjlistArr[node].size(); i++)
        {
            if (dist[adjlistArr[node][i]] == INT32_MAX)
            {
                q.push(adjlistArr[node][i]);
                dist[adjlistArr[node][i]] = min(dist[node] + 1, dist[adjlistArr[node][i]]);
                Parent[adjlistArr[node][i]] = node;
            }
        }
    }

    // now start traverssing the parent from target node to the value
    vector<int> pathSrcTarg;
    int parNode = target;

    while (parNode != -1)
    {
        pathSrcTarg.push_back(parNode);
        parNode = Parent[parNode];
    }

    // reverse the vector ans
    reverse(pathSrcTarg.begin(), pathSrcTarg.end());

    return pathSrcTarg;
}

// Shortest path in directed acyclic graph

void dfsTopoSort(int node, vector<pair<int, int>> adjlistArr[], stack<int> &s, vector<int> &visited)
{ // array adjlistArr[], array must be called with these breackets
    // node ko visit mark karna h.

    visited[node] = 1;

    for (int i = 0; i < adjlistArr[node].size(); i++)
    {
        if (!visited[adjlistArr[node][i].first])
        {
            dfsTopoSort(adjlistArr[node][i].first, adjlistArr, s, visited);
        }
    }
    s.push(node);
}

vector<int> shortestPathDirectedDistFromSrc(int N, int M, vector<vector<int>> &edges, int src)
{

    // edges have 3 element , from , to , weight

    // create adjaceny matrix from edges

    // let's create adjaceny list
    vector<pair<int, int>> adjlistArr[N];

    for (int i = 0; i < edges.size(); i++)
    {
        adjlistArr[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
    }

    // dfs and topological sort needed
    stack<int> s;

    vector<int> visited(N, 0);

    // we don't need for loop to get each node included in topo, unconected are never visitable from src

    // dfsTopoSort(src, adjlistArr, s, visited); // this also work but for uniformatity and reuasability, let's consider the unconnect also in topological sort

    // DFS from ALL nodes to get complete topological sort
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            dfsTopoSort(i, adjlistArr, s, visited);
        }
    }

    // unconnected ke pass source se move karna ka koi way hi nahi h .. hence write -1

    vector<int> dist(N, INT32_MAX);
    dist[src] = 0; // for initialization

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();

        // visit the neighbour node of this to make the edges light weight
        for (int i = 0; i < adjlistArr[curr].size(); i++)
        {

            dist[adjlistArr[curr][i].first] = min(dist[curr] + adjlistArr[curr][i].second, dist[adjlistArr[curr][i].first]); // adjlistArr[curr][i].second is weight of edge
        }
    }

    // convert all INT_Max to -1
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == INT32_MAX)
        {
            dist[i] = -1;
        }
    }

    return dist;
}

// Dijkstra's Algorithm

// it is single source shortest path where all nodes are visited from anywhere but overall cost should be min, it is not like single path from source to all but it is shortest path from source to itself, many branching possible at single source

// used for weighted undirected graph // use BFS

vector<int> dijkstraMyWay(int V, vector<vector<int>> adjlistArr[], int src)
{
    // V is vertex count / nodes

    // we have adjlistArr[] given =
    // {
    // {{1,9},{}}, //indexing 0
    // {{0,9}, {} } //indexing 1
    // }

    vector<int> explored(V, 0);
    vector<int> dist(V, INT32_MAX);

    dist[src] = 0;

    // explred nodes are confirmed shortest distance present
    // Use priority queue (min-heap) for efficient min distance selection
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    queue<int> q;
    q.push(src);

    int node = src;
    q.pop();

    while (node != -1)
    {

        explored[node] = 1;

        for (int i = 0; i < adjlistArr[node].size(); i++)
        {
            if (!explored[adjlistArr[node][i][0]])
            {
                q.push(adjlistArr[node][i][0]);

                // 0 indexing is for next neighbour
                //  let's compare the weight
                if (dist[adjlistArr[node][i][0]] > dist[node] + adjlistArr[node][i][1])
                {
                    dist[adjlistArr[node][i][0]] = dist[node] + adjlistArr[node][i][1];
                }
            }
        }

        // after filling the dist value , we need to get the unexplored min from distance

        // queue has those elements from which we have to select the min// don't get his min, as it is of no need, but we csn use it

        if (q.empty())
        {
            node = -1;
        }
        else
        {
            node = q.front();
            q.pop();

            while (!q.empty())
            {
                if (dist[q.front()] < dist[node])
                {
                    node = q.front();
                }
            }
        }
    }

    return dist;
}

vector<int> dijkstra(int V, vector<vector<int>> adjlistArr[], int src)
{

    vector<int> explored(V, 0);
    vector<int> dist(V, INT32_MAX);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {

        // Find min distance unvisited node
        int node = -1;
        for (int i = 0; i < V; i++)
        {

            if (!explored[i] && (node == -1 || dist[i] < dist[node]))
            { // node -1 ha toh dist[node] check hi nahi hoga
                node = i;
            }
        }

        if (node == -1)
            break;

        explored[node] = 1;

        // Update neighbors
        for (int i = 0; i < adjlistArr[node].size(); i++)
        {
            if (!explored[adjlistArr[node][i][0]])
            {

                if (dist[adjlistArr[node][i][0]] > dist[node] + adjlistArr[node][i][1])
                {
                    // adjlistArr[node][i][1] is weight
                    dist[adjlistArr[node][i][0]] = dist[node] + adjlistArr[node][i][1];
                }
            }
        }
    }

    return dist;
}

// method 3 using minheap priority queue
vector<int> dijkstraPriorityQ(int V, vector<vector<int>> adjlistArr[], int src)
{

    vector<int> explored(V, 0);
    vector<int> dist(V, INT32_MAX);

    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // min on the bases of dist value pushed

    // You're pushing (node, distance)
    // But priority queue compares first element (node index)
    // So it's sorting by node number, not by distance!

    // make (distance , node)

    // q.push(make_pair(src, 0));

    q.push(make_pair(0, src));

    int node = -1;

    while (!q.empty())
    {

        node = (q.top()).second;
        int currentDist = q.top().first; // same as we can directly find dist[adjlistArr[node][i][0]]

        q.pop(); // this pop is min elelement

        // Skip if we already found a better path to this node //it increases efficiency of code

        if (currentDist > dist[node])
        {
            continue;
        }

        explored[node] = 1;

        for (int i = 0; i < adjlistArr[node].size(); i++)
        {
            if (!explored[adjlistArr[node][i][0]])
            {

                // 0 indexing is for next neighbour
                //  let's compare the weight
                if (dist[adjlistArr[node][i][0]] > dist[node] + adjlistArr[node][i][1])
                {
                    dist[adjlistArr[node][i][0]] = dist[node] + adjlistArr[node][i][1];

                    q.push(make_pair(dist[adjlistArr[node][i][0]], adjlistArr[node][i][0])); // update distance then push with this distance
                }
            }
        }
    }

    return dist;
}

// Shortest path node sequence in undirected weighted graph // We have taken help of dijsktra algorithm

vector<int> shortestPathNodeSeqUndirWeight(vector<vector<int>> edges, int N, int M, int src, int target)
{
    // s is source and t is target

    vector<int> dist(N, INT32_MAX);
    vector<int> Parent(N, -1);
    vector<bool> explored(N, 0);

    // bfs from this 0
    // queue<int> q;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push(make_pair(0, src));
    dist[src] = 0;

    // let's create adjaceny list
    vector<pair<int, int>> adjlistArr[N];

    for (int i = 0; i < edges.size(); i++)
    {
        adjlistArr[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        adjlistArr[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }

    while (!q.empty())
    {
        int node = (q.top()).second;

        int currentDist = q.top().first;

        q.pop();

        // Skip if this is an outdated entry
        if (currentDist > dist[node])
        {
            continue;
        }

        // Early termination if target found , not needed but we can put it here

        if (node == target)
            break;

        explored[node] = 1;

        for (int i = 0; i < adjlistArr[node].size(); i++)
        {
            if (!explored[adjlistArr[node][i].first] && dist[adjlistArr[node][i].first] > dist[node] + adjlistArr[node][i].second)
            {

                // dist[adjlistArr[node][i].first] = min(dist[node] + adjlistArr[node][i].second, dist[adjlistArr[node][i].first]);

                dist[adjlistArr[node][i].first] = dist[node] + adjlistArr[node][i].second;

                q.push(make_pair(dist[adjlistArr[node][i].first], adjlistArr[node][i].first));

                Parent[adjlistArr[node][i].first] = node;
            }
        }
    }

    // now start traverssing the parent from target node to the value
    vector<int> pathSrcTarg;
    int parNode = target;

    while (parNode != -1)
    {
        pathSrcTarg.push_back(parNode);
        parNode = Parent[parNode];
    }

    // reverse the vector ans
    reverse(pathSrcTarg.begin(), pathSrcTarg.end());

    return pathSrcTarg;
}

int main()
{

    // Covid spread
    vector<vector<int>> hospital = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}};

    if (covidSpreadTime(hospital) != -1 || covidSpreadTimeSimplified(hospital) != -1)
    {
        // return a numbet then it means it is able to spread else return -1

        cout << "corona is spread in all\n";
    }
    else
    {
        cout << "corona is not spread in all\n";
    }

    // find the number of island
    vector<vector<char>> gridisland = {
        {'2', '1', '0', '2', '1'},
        {'1', '0', '1', '2', '1'},
        {'1', '0', '1', '2', '1'},
        {'1', '0', '0', '2', '1'}};

    cout << "number of island : " << numIslands(gridisland) << endl;

    // Replace all O's or a group of 'O with X's that are surrounded by 'X
    vector<vector<char>> fillXO = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'O'}};

    int m = fillXO.size();
    int n = fillXO[0].size();
    fillXO = fillXOResult(m, n, fillXO);

    // prerequsite tasks
    int N = 4; // number of tasks or vertex from 0 to N-1
    int P = 3; // size of total pairs or relation or list of prerequisite pair. first should be done after second
    vector<pair<int, int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    if (isPossiblePreRequisite(N, P, prerequisites))
    {
        cout << "yes prerequisite possible\n";
    }
    else
    {
        cout << "No prerequisite possible\n";
    }

    // Alien DICTIONARY
    string dict[] = {"acb", "abc", "abd"};
    N = 3;
    int K = 4;
    string AlphaOrder = findorderInAlienDict(dict, N, K);

    // parallel course
    int n = 5;
    vector<vector<int>> relations = {
        {1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};
    vector<int> time = {1, 2, 3, 4, 5};
    int timeofcompletionCourse = minimumTimeCourse(n, relations, time);

    // Shortest path in undirected graph
    N = 9;
    int M = 10;
    vector<vector<int>> edgesPathUndirected = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};
    int src = 0;

    vector<int> pathDisUndirected = shortestPathUndirectedDist(edgesPathUndirected, N, M, src);

    // Shortest path node sequence in undirected graph
    vector<pair<int, int>> edgesPathUndirectedPair = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};

    src = 0;
    vector<int> pathSeqUndirected = shortestPathNodeSeq(edgesPathUndirectedPair, N, M, src, N - 1); // let's take last nde as target

    // Shortest path dist from src in directed acyclic graph
    N = 4, M = 2;
    vector<vector<int>> edgesPathdirectedWg = {
        {0, 1, 2}, {0, 2, 1}};

    src = 0;
    vector<int> pathDistDirected = shortestPathDirectedDistFromSrc(N, M, edgesPathdirectedWg, src);

    // Dijkstra's Algorithm

    // we can pas adjaceny list directly

    int V = 5; // 5 nodes: 0,1,2,3,4
    src = 0;

    // Create and initialize adjacency list directly in main
    vector<vector<int>> adj[5] = {
        {{1, 4}, {2, 1}}, // Node 0: connected to node1(weight=4), node2(weight=1)
        {{3, 2}},         // Node 1: connected to node3(weight=2)
        {{1, 2}, {3, 5}}, // Node 2: connected to node1(weight=2), node3(weight=5)
        {{4, 3}},         // Node 3: connected to node4(weight=3)
        {}                // Node 4: no outgoing edges
    };

    vector<int> pathDistUnDirectedDij1 = dijkstraMyWay(V, adj, src);
    vector<int> pathDistUnDirectedDij2 = dijkstra(V, adj, src);
    vector<int> pathDistUnDirectedDij3 = dijkstraPriorityQ(V, adj, src);

    vector<int> distances = dijkstraPriorityQ(V, adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    // Shortest path node sequence in weighted undirected graph
    int N = 5, M = 6;
    vector<vector<int>> edgesPathUndirected = {
        {1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};

    int src = 0;
    vector<int> pathSeqUndirected = shortestPathNodeSeqUndirWeight(edgesPathUndirected, N, M, src, N - 1); // let's take last nde as target

    return 0;
}