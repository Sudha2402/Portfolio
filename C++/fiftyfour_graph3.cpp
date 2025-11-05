#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <stack>
#include <algorithm>

// bellman Ford Algorithm
// Floyd Watshall Algorithm
// Shortest source to destination path
// knight walk
// find whether path exist
// Eular path and Eular circuit on the bases on connected and indegree count
// Circle of string
//





// bellman Ford Algorithm

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{

    // Here we will analyse all the edges V-1 times.
    // Atlast analye all edges once more to see if any changes occurred.

    // We have choose V-1 because we have V vertex then V-1 edges max possible to reach at other node.

    // vector<int> dist(V, INT32_MAX);//as per leetcode , they want 10^8 hence write 1e8

    vector<int> dist(V, 1e8);

    dist[src] = 0;

    int maxpathlengthToAnyNodeFromSource = V - 1; // hence this is used below loop
    // it is just like one edge ko use karke souce tak pahuchne ka shortest path possible. then 2 edges ko use karke and so on till V-1 edges ke collection ko use karke kiss kiss node par shortest path possible ho raha h. //that's why we relax all the edges each time. means we update the distance value as per the consideration of new edge might chage the path cost for others

    for (int count = 0; count < V - 1; count++)
    {

        // Here we will analyse all the edges V-1 times.
        // Atlast analye all edges once more to see if any changes occurred.

        // We have choose V-1 because we have V vertex then V-1 edges max possible to reach at other node.

        for (int i = 0; i < edges.size(); i++)
        {
            if (dist[edges[i][0]] == 1e8)
            { // this edge will not make any changes to other as it is itselt now low , continue for considering next edge then see the changes this new edge can make
                continue;
            }

            if (dist[edges[i][1]] > dist[edges[i][0]] + edges[i][2])
            {
                dist[edges[i][1]] = dist[edges[i][0]] + edges[i][2];
            }
        }
    }

    // last time all edges are checked if still possibility of update then we declare -ve cycle
    bool flag = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        if (dist[edges[i][0]] == 1e8)
        { // this edge will not make any changes to other as it is itselt now low , continue for considering next edge then see the changes this new edge can make
            continue;
        }

        if (dist[edges[i][1]] > dist[edges[i][0]] + edges[i][2])
        {

            flag = 1;
            dist[edges[i][1]] = dist[edges[i][0]] + edges[i][2];
            break;
        }
    }

    if (!flag)
    {
        cout << "No Negative cycle detected!" << endl;
        return dist;
    }

    cout << "Negative cycle detected!" << endl;
    return vector<int>(1, -1); // Single element with value -1 //size one and initial value is -1 setted.
}

// Floyd Watshall Algorithm
vector<vector<int>> floydWatshallAllPairShortestDist(vector<vector<int>> &matrix)
{
    int vertex = matrix.size();

    // Create a copy to avoid modifying original matrix
    vector<vector<int>> dist = matrix;

    // in the matrix , impossible path is -1, hence for using MIN convert those to INTMAX

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = INT32_MAX;
            }

            // Set diagonal to 0 if not already set
            if (i == j && dist[i][j] != 0)
            {
                dist[i][j] = 0;
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int intermediate = 0; intermediate < vertex; intermediate++)
    {
        for (int i = 0; i < vertex; i++)
        { // row
            for (int j = 0; j < vertex; j++)
            { // col
                // i,j represent a cell in matrix

                // Check for overflow and valid paths
                if (matrix[i][intermediate] == INT32_MAX || matrix[intermediate][j] == INT32_MAX)
                {
                    // is intermediate ke karan path shortest nahi hoga
                    continue;
                }

                matrix[i][j] = min(matrix[i][j], matrix[i][intermediate] + matrix[intermediate][j]);
            }
        }
    }

    // Convert INT32_MAX back to -1 for output
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            if (matrix[i][j] == INT32_MAX)
            {
                matrix[i][j] = -1;
            }
        }
    }

    return matrix;
}

// valid index check in matrix
int validMatrixIndex(int x, int y, int m, int n)
{
    return x >= 0 && y >= 0 && x < m && y < n;
}

// Shortest source to destination path
int shortestSourcePathDist(vector<vector<int>> &A, int M, int N, int X, int Y)
{ // we are considering Source as 0,0 and here X, Yis target index.

    // A is adjacency matrix
    // M and N are rews and columns

    if (X == 0 && Y == 0)
    {
        // source and target same point
        return 0;
    }

    // possibility that source index is 0 value hence never reach the destination

    if (A[0][0] == 0)
    {
        return -1; // never movee from source.
    }

    queue<pair<pair<int, int>, int>> q; //{i,j,dist} //i and j are row and column. dist is the dis travelled so far

    q.push({{0, 0}, 0}); // at the time of return , we will use step + 1 as return.

    A[0][0] = 2; // not to revisit here

    int row[4] = {-1, 0, 1, 0}; // top, right , bottom, left
    int col[4] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int steps = q.front().second;

        // we would have explicitly used this steps bu=y poping all the count at a time in the queue and incrementing only one step for each count queue as at one count all are at same level hence only one step is counted.

        // don't confused with step and box when at box 0, then step is 0 and standing at another position, means we are moving, only 1 step to reach this index. hence for reaching 1,1 from 0,0 we are moving one step to reach this index hence we will push 1 step in queue not 2 even though it is the second box on which we are standing. two box pair is one step. hence for n boxes , we made n-1 steps.

        q.pop();

        for (int K = 0; K < 4; K++)
        {

            int new_x = i + row[K];
            int new_y = j + col[K];

            if (validMatrixIndex(new_x, new_y, M, N) && A[new_x][new_y] == 1)
            {
                // it can be position anywhere in if condition.
                A[new_x][new_y] = 2;

                if (new_x == X && new_y == Y)
                {
                    return steps + 1; // is new found index ke liye ek bar jaane padega kyuki abhi hum new position cal kar rahe h usspar gaye nahi h.
                }

                q.push({{new_x, new_y}, steps + 1}); // this steps +1 shows that it has been covered this much like it has covered step boxes and it is currently on step + 1 box. hence in final answer we are returning step +1
            }
        }
    }

    // as we have changes 1 to 2, we can back covert to 1 if needed to return the original matrix.

    return -1;
}

// knight walk
// square matrix is given. N is row, col
// here position is given on one bases indexing

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &targetPos, int N)
{
    // return the steps or total move taken.
    // KnightPos is current position, targetPos is the position to reach
    // when we have to explore in all posible direction then use BFS

    // as KnightPos and targetPos are 1 base indexing , then convert it to 0 base first
    KnightPos[0]--;
    KnightPos[1]--;
    targetPos[0]--;
    targetPos[1]--;

    if (KnightPos[0] == targetPos[0] && KnightPos[1] == targetPos[1])
    {
        return 0;
    }

    // pop time we would have moved one more step.

    int rowMove[8] = {2, 2, -2, -2, 1, -1, 1, -1};
    int colMove[8] = {1, -1, 1, -1, 2, 2, -2, -2};

    vector<vector<bool>> visited(N, vector<bool>(N, 0)); // Correct Ways to Create N×N Matrix and initialize with 0

    queue<vector<int>> q;

    q.push(KnightPos);
    visited[KnightPos[0]][KnightPos[1]] = 1;

    int steps = 0;

    while (!q.empty())
    {

        int count = q.size();

        steps++; // currect index ko paar karliya h. next possible index pushed h.

        for (int i = 0; i < count; i++)
        {
            int row = q.front()[0];
            int col = q.front()[1];

            q.pop();

            // push all the possibles in the queue
            for (int i = 0; i < 8; i++)
            {
                int new_row = row + rowMove[i];
                int new_col = col + colMove[i];

                // check valid
                if (new_row < N && new_col < N && new_row >= 0 && new_col >= 0 && !visited[new_row][new_col])
                {
                    // push karte wakt hi mil jaye toh aur badiya.
                    if (new_row == targetPos[0] && new_col == targetPos[1])
                    {
                        return steps;
                    }

                    q.push({new_row, new_col}); // this is a vector and pushed together.

                    // to track already traversed position, we need a bool matrix visited

                    visited[new_row][new_col] = 1;
                }
            }
        }
    }

    return -1;
}

// find whether path exist

bool pathExistPathSearch(vector<vector<int>> &Amatrix, pair<int, int> src, vector<pair<int, int>> &ans)
{
    // for visited, make this 3 in Amatrix to  5
    // move all possible directions from src
    int row[4] = {-1, 0, 1, 0}; // top, right , bottom, left
    int col[4] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        if (src.first + row[i] >= 0 && src.second + col[i] >= 0 && src.first + row[i] < Amatrix.size() && src.second + col[i] < Amatrix[0].size())
        {
            if (Amatrix[src.first + row[i]][src.second + col[i]] == 2)
            {
                // destination reached
                ans.push_back({src.first + row[i], src.second + col[i]});

                return 1;
            }
            else if (Amatrix[src.first + row[i]][src.second + col[i]] == 3)
            {
                // continue moving
                ans.push_back({src.first + row[i], src.second + col[i]});

                Amatrix[src.first + row[i]][src.second + col[i]] = 5; // as visisted marked

                // call again
                src = {src.first + row[i], src.second + col[i]};

                if (pathExistPathSearch(Amatrix, src, ans))
                {
                    return 1;
                }

                ans.pop_back();
            }
        }

        // Restore original value
        // Amatrix[src.first + row[i]][src.second + col[i]] = 3;//not needed as once traverse and not found path in that then furst exploration will also not find path there.
    }

    return 0;
}

vector<pair<int, int>> pathExistInWallBlankSorDest(vector<vector<int>> Amatrix)
{
    // get source then move to des and stop, if des is fount first then move to source and stop

    pair<int, int> src;

    for (int i = 0; i < Amatrix.size(); i++)
    {
        for (int j = 0; j < Amatrix[i].size(); j++)
        {

            if (Amatrix[i][j] == 1)
            {
                // source is found,
                src = {i, j};
            }
            // else if (Amatrix[i][j] == 2)
            // {
            //     // dest is found, no need to find dest first
            //     dest = {i, j};
            // }
        }
    }

    vector<pair<int, int>> ans;
    // last element of ans

    ans.push_back(src); // Start with source

    pathExistPathSearch(Amatrix, src, ans);

    if (!ans.empty() && Amatrix[ans[ans.size() - 1].first][ans[ans.size() - 1].second] == 2)
    {
        return ans;
    }
    else
    {
        ans.clear();
        return ans;
    }
}

// Eular path and Eular circuit
// return 0 for none, 1 for eular path, 2 for eular circuit.

void isAllConnected(int node, int V, vector<int> adj[], vector<int> &visited)
{
    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
        {
            isAllConnected(adj[node][i], V, adj, visited);
            // return;// WRONG! Returns after first unvisited neighbor
        }
    }

    return;
}

int isEularCircuit(int V, vector<int> adj[])
{
    // V is vertex count and adj is adjacency list

    vector<int> degree(V);
    int oddCount = 0;
    for (int i = 0; i < V; i++)
    {
        degree[i] = adj[i].size();
        if (degree[i] % 2 != 0)
        { // this we could have done at the very first time filling the degree
            // odd degree found
            oddCount++;
        }
    }

    // check that all non zero degree should be connected for Eular path and circuit.

    // for this connected, use dfs

    vector<int> visited(V, 0);

    // Find first node with non-zero degree for DFS
    int startNode = -1;
    for (int i = 0; i < V; i++)
    {
        if (degree[i] > 0)
        {
            startNode = i;
            break;
        }
    }

    // If all vertices have degree 0, it's technically an Euler circuit
    if (startNode == -1)
    {
        return 2;
    }

    // we need to check startNode having degree != 0
    isAllConnected(startNode, V, adj, visited);

    // check the visited vector
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0 && degree[i] != 0)
        {
            return 0; // not connected with non zero degree hence not eular path or curcuit
        }
    }

    // all are connected.

    // check for eular circuit
    // degree of all is even or 0

    // int oddCount = 0;
    // for (int i = 0; i < V; i++)
    // {
    //     if (degree[i] % 2 != 0)
    //     { //this we could have done at the very first time filling the degree
    //         // odd degree found
    //         oddCount++;
    //     }
    // }

    // check eular path , atleast odd degree 0 or 2
    if (!oddCount)
    {
        return 2;
    }
    else
    {
        // Euler path requires exactly 2 odd-degree vertices, Euler circuit requires 0 odd-degree vertices.
        if (oddCount == 2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

// Circle of string
int isCircle(int N, vector<string> A)
{

    // A contanins all strings from where first and last character we need to extract

    // we will use character a - 0, b- 1 like this for adj list
    vector<int> adj[26];
    vector<int> Indegree(26, 0);
    vector<int> Outdegree(26, 0);

    for (int i = 0; i < N; i++)
    {
        string temp = A[i]; // string stored but we can use directly also

        adj[A[i][0] - 'a'].push_back(A[i][A[i].size() - 1] - 'a');

        Outdegree[A[i][0] - 'a']++;
        Indegree[A[i][A[i].size() - 1] - 'a']++; // last character in the string
    }

    // return 0 is better to be checked first instead of doing any connected check and consuming more time.
    for (int i = 0; i < 26; i++)
    {
        if (Indegree[i] != Outdegree[i])
        {
            return 0;
        }
    }

    // check all non 0 degree should be connected

    vector<int> visited(26, 0);

    // Find first node with non-zero degree for DFS
    int startNode = -1;
    for (int i = 0; i < 26; i++)
    {
        if (Indegree[i] > 0) // or Outdegree[i] > 0, both are equal
        {
            startNode = i;
            break;
        }
    }

    // If all vertices have degree 0, it's technically an Euler circuit
    // If all vertices have degree 0, it's a valid circle (empty circle)
    if (startNode == -1)
    {
        return 1;
    }

    // we need to check startNode having degree != 0
    isAllConnected(startNode, 26, adj, visited);

    // check the visited vector
    // Verify all non-zero degree vertices are connected
    for (int i = 0; i < 26; i++)
    {
        if (visited[i] == 0 && Indegree[i] != 0)
        {
            return 0; // not connected with non zero degree hence not eular curcuit
        }
    }

    return 1;
}

int main()
{

    int V = 5;
    int src = 0;

    vector<vector<int>> edges = {
        {0, 1, 4},  // from node 0 to node 1 with weight 4
        {0, 2, 5},  // from node 0 to node 2 with weight 5
        {1, 2, -2}, // from node 1 to node 2 with weight -2
        {2, 0, 3}   // from node 2 to node 0 with weight 3
    };

    vector<int> distances = bellmanFord(V, edges, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    // Floyd Watshall Algorithm
    // Input matrix where -1 means no direct path
    vector<vector<int>> matrix = {
        {0, 3, -1, 7},
        {8, 0, 2, -1},
        {5, -1, 0, 1},
        {2, -1, -1, 0}};

    vector<vector<int>> floydWatshallAllPairShortestDistResult = floydWatshallAllPairShortestDist(matrix);

    cout << "\nShortest Path Matrix:" << endl;
    for (int i = 0; i < floydWatshallAllPairShortestDistResult.size(); i++)
    {
        for (int j = 0; j < floydWatshallAllPairShortestDistResult[i].size(); j++)
        {
            cout << floydWatshallAllPairShortestDistResult[i][j] << " ";
        }
        cout << endl;
    }

    // Shortest source to destination path
    vector<vector<int>> A = {
        {1, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 0, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1}};

    int X = 4;
    int Y = 2;
    int shortestDistanceFromSourceToDestAdjMatrix = shortestSourcePathDist(A, A.size(), A.size(), X, Y);

    // knight walk
    vector<int> KnightPos = {4, 5};
    vector<int> targetPos = {1, 1};
    int N = 6;
    int minStepToReachTargetByHorse = minStepToReachTarget(KnightPos, targetPos, N);

    // find whether path exist

    // solving using dfs
    vector<vector<int>> Amatrix = {
        {3, 0, 3, 0, 0},
        {3, 0, 2, 0, 3},
        {3, 3, 3, 3, 3},
        {0, 3, 0, 0, 3},
        {3, 3, 1, 0, 3}};
    vector<pair<int, int>> pathExist = pathExistInWallBlankSorDest(Amatrix);

    // Eular path and Eular circuit
    int V = 5;
    vector<int> adj[V];
    adj[0] = {1, 2, 3, 4};
    adj[1] = {0, 2, 3, 4};
    adj[2] = {0, 1, 3, 4};
    adj[3] = {0, 1, 2, 4};
    adj[4] = {0, 1, 2, 3};

    int result = isEularCircuit(V, adj);
    cout << "Result: ";
    if (result == 2)
        cout << "Euler Circuit";
    else if (result == 1)
        cout << "Euler Path";
    else
        cout << "Neither";
    cout << " (Code: " << result << ")" << endl;

    // Circle of string
    vector<string> AString = {"abc", "cde", "efa"};
    int isCircleAns=isCircle(AString.size(),AString);

    
}