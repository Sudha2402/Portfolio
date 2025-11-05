#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <stack>

// Graph
// undirected Graph Adjacency matrix(using class)
// Directed Graph Adjacency matrix(by asking every edge weight from user at run time)
// Adjacency list
// Deleting a node in Adjacency list
// BFS traversal
// DFS traversal
// topological sort (DAG- Directed acyclic graph) using DFS
// topological sort (DAG- Directed acyclic graph) using BFS //Kahn's algorithm
// Cycle detection in undirected graph
// detect cycle in directed graph dfs
// cycle detection using BFS // Kahn's Algorithm for topological sort
// Bipartite Graph (using BFS)
// Bipartite Graph (using DFS)



class Graph
{
private:
    int V;                         // number of vertices
    vector<vector<int>> adjMatrix; // adjacency matrix

public:
    Graph(int vertices)
    {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // because the graph is undirected
    }

    void display()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// Directed Graph Adjacency matrix by asking every edge weight from user at run time
void createGraph(int V, int E)
{ // we will ask this vertex and edges count from main at first passing

    vector<vector<int>> adjacentMatrix(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++)
    {
        int u, v, weight;
        cout << "Enter edge (u v) and weight: ";
        cin >> u >> v >> weight;
        adjacentMatrix[u][v] = weight; // Directed graph
    }

    cout << "Adjacency Matrix Directed:" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << adjacentMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// create directed adjacency list
// Return Pointer to Array
vector<int> *createDirAdjacenyList(int vertex, int edges)
{
    // vector<int> adjlistArr[vertex]; //stack allocation destroyed and not able to return valid result

    // Allocate the array on the heap.
    vector<int> *adjlistArr = new vector<int>[vertex];

    int u, v;
    for (int i = 0; i < edges; i++)
    {
        // enter u and v
        cout << "Enter u and v: ";
        cin >> u >> v;
        adjlistArr[u].push_back(v);
    }

    return adjlistArr; // this is an array containing vector<int> type of data hence pointor will be of this type.

    // after converting to heap allocation // Return the pointer to the heap-allocated memory.

    // The warning [-Wreturn-local-addr] is generated because you are trying to return a pointer or reference to a local variable (adjlistArr) that is allocated on the function's stack. When the function returns, its stack frame is destroyed, and the memory for adjlistArr is deallocated. The pointer you return will then be pointing to invalid, deallocated memory, leading to undefined behavior if you try to use it.
}

vector<vector<pair<int, int>>> createAdjacenyList(int vertex, int edges)
{

    // Note: vector<int> adjList[vertex];    // C-style array of vectors

    // vector<int>adjList[vertex]; //adjacent is an array of size 5 and this array contains vector data type

    // vector<int>adjList[vertex]; // here for weighted, we use pair<int,int> instead of int

    // vector<vector<int>> adjList(vertex);// adjList is an array of size 'vertex' and each element is a vector of integers.
    // vector<vector<int>> adjList(vertex);  // Vector of vectors

    // Note:vector<pair<int, int>> adjList[vertex]; // adjList is an array of size 'vertex' and each element is a vector of pairs//This is a single-dimensional vector where each element is a pair of integers. //[ (a1, b1), (a2, b2), (a3, b3), ... ]

    vector<vector<pair<int, int>>> adjList(vertex); // adjList is an array of size 'vertex' and each element is a vector of pairs'

    // vector<vector<pair<int, int>>>
    //  This is a two-dimensional vector where each element is itself a vector of pairs.
    //[
    //    [ (a1, b1), (a2, b2), ... ],    // Row 0
    //    [ (c1, d1), (c2, d2), ... ],    // Row 1
    //    [ (e1, f1), (e2, f2), ... ],    // Row 2
    //    ...
    //  ]

    cout << "Creating Adjacency list" << endl;

    for (int i = 0; i < edges; i++)
    {
        int u, v, weight;
        cout << "Enter edges (u v weight): ";
        cin >> u >> v >> weight;
        // adjList[u].push_back(v);
        adjList[u].push_back(make_pair(v, weight)); // for weighted graph
        adjList[v].push_back(make_pair(u, weight)); // for undirected graph
    }

    cout << "Adjacency List: " << endl;
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            // cout<<adjList[i][j]<<" ";
            cout << adjList[i][j].first << " " << "(" << adjList[i][j].second << ")" << " "; // for weighted graph
        }
        cout << endl;
    }

    return adjList;
}

#include <utility>   // For std::pair
#include <algorithm> // For std::remove_if

vector<vector<pair<int, int>>> deleteNodeAdjacenyList(int nodeToDelete, vector<vector<pair<int, int>>> &adjList, int &vertex)
{
    // Step 1: Remove all edges pointing TO the node to delete
    for (int i = 0; i < vertex; i++)
    {
        adjList[i].erase(
            remove_if(adjList[i].begin(), adjList[i].end(),
                      [nodeToDelete](const pair<int, int> &p)
                      {
                          return p.first == nodeToDelete;
                      }),
            adjList[i].end());
    }

    // Step 2: Remove the node itself from the adjacency list
    adjList.erase(adjList.begin() + nodeToDelete); // begin se iss index ke node ko hata do

    // Step 3: Update all references to nodes that came after the deleted node
    for (int i = 0; i < adjList.size(); i++)
    {
        for (auto &edge : adjList[i])
        {
            if (edge.first > nodeToDelete)
            {
                edge.first--; // Decrement references to higher-numbered nodes
            }
        }
    }

    // Step 4: Update vertex count
    vertex = adjList.size();

    cout << "Adjacency List after deleting node " << nodeToDelete << ": " << endl;
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j].first << " " << "(" << adjList[i][j].second << ")" << " ";
        }
        cout << endl;
    }

    return adjList;
}

// BFS traversal
vector<int> bfsofGraph(int V, vector<int> adj[])
{
    // TC: O(V+2E)
    // SC: O(2V) //for queue and visited array

    // array has indexing from 0 hence this index value is the node name or number for identification

    vector<int> ans;
    queue<int> q;
    q.push(0);
    // bool visited[V] = {0};
    vector<bool> visited(V, 0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // get connected nodes from adjaceny list then check those not visited then push in the queue

        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!adj[node][i])
            {
                visited[node] = 1; // so that no other node come here as not visited and traverse it again
                q.push(adj[node][i]);
            }
        }
    }

    return ans;
}

// DFS traversal

void dfsMain(vector<int> adj[], vector<int> &ans, int V, vector<bool> &visited)
{

    // V is the vertex we are moving or recursing back

    ans.push_back(V);
    visited[V] = 1;

    for (int i = 0; i < adj[V].size(); i++)
    {
        if (!visited[adj[V][i]])
        {
            dfsMain(adj, ans, adj[V][i], visited);
        }
    }
}

vector<int> dfsofGraph(int V, vector<int> adj[])
{
    // TC: O(V+2E)
    // SC: O(2V) //for queue and visited array

    // array has indexing from 0 hence this index value is the node name or number for identification

    vector<int> ans;
    vector<bool> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsMain(adj, ans, i, visited);
        }
    }

    return ans;
}

// topological sort (DAG- Directed acyclic graph) using DFS

void topodfsMain(vector<int> adj[], stack<int> &s, int V, vector<bool> &visited) // we have to use pass by reference in stack also
{

    // V is the vertex we are moving or recursing back

    visited[V] = 1;

    for (int i = 0; i < adj[V].size(); i++)
    {
        if (!visited[adj[V][i]])
        {
            topodfsMain(adj, s, adj[V][i], visited);
        }
    }

    // stack contain the elements at the time of backtrack. it sees that the top elemement should be my dependent then only I will push myself.//at the end in the depth, no dependent hence it will push itself in stack then recursively it moves back. there it will also visit the branch first due to for loop then it comes back and push itself.

    s.push(V);
}

vector<int> topoSortDfsofGraph(int V, vector<int> adj[])
{

    stack<int> s;
    vector<bool> visited(V, 0);

    // we need to wrap in for loop because it may be possible that we have choosed the start point from a position which is also depenedent on some other. this new start when reach to the last start depenedent then it will push itself and move back

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topodfsMain(adj, s, i, visited);
        }
    }

    // now stack has exactly the topological sort answer
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

// topological sort (DAG- Directed acyclic graph) using BFS

// Kahn's algorithm is a method for topological sorting a directed acyclic graph (DAG) by repeatedly finding nodes with an in-degree of zero. It works by adding nodes with no incoming edges to a queue, then processing them by removing them from the queue, adding them to the sorted list, and decreasing the in-degree of their neighbors.

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

        // get connected nodes from adjaceny list then check those not visited then push in the queue
        // Process all neighbors
        for (int i = 0; i < adj[node].size(); i++)
        {
            indegree[adj[node][i]]--;
            if (indegree[adj[node][i]] == 0) // don't get confused that old indegree 0 will be traced again, no only new indegree 0 created is pushed
            {
                q.push(adj[node][i]); // queue will contain only those having indegree 0  //adj[node][i] is index value in indegree. //index value is not affected with decrement.
            }
        }
    }

    return ans;
}

// Cycle detection in undirected graph

// here actually , we are detecting the neighbour node not the parent node. hence neighbour node detected, we return 0 which make that it is OK to be visited and not cycle, hence we should pass the parent element in parameter for next call.

// The standard working approach uses explicit parent tracking:

int checkparentWrongRightNeighbourCheck(vector<int> adj[], int u, int v)
{
    // check if u is parent of v
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (adj[u][i] == v)
        {
            // break;//if this present then below return not works
            return 1;
        }
    }

    return 0; // default return is neccessary in case it is not parent.
}

int cycleDetectUndirectMainDfs(vector<int> adj[], int V, int parent, vector<bool> &visited)
{

    visited[V] = 1;

    for (int i = 0; i < adj[V].size(); i++)
    {
        // it should not be parent for cycle
        // if (visited[adj[V][i]] && !checkparent(adj, i, V))//indexing ko kaun bhejta h idiot, value bheji jati h
        // if (visited[adj[V][i]] && !checkparent(adj, adj[V][i], V)) //since we are using this visited above also, hence keep other in other loop and this in else part

        if (visited[adj[V][i]])
        {
            // if (!checkparentWrongRightNeighbourCheck(adj, adj[V][i], V))

            // The standard working approach uses explicit parent tracking:, hence increase one more parameter as parent

            if (parent != adj[V][i])
            {
                return 1;
            }
        }

        // if (!visited[adj[V][i]]) //since we are using this visited above also, hence keep other in other loop and this in else part

        else
        {
            int ans = cycleDetectUndirectMainDfs(adj, adj[V][i], V, visited);

            if (ans)
            { // if we received 1 last time then we have to send it to the top.
                return 1;
            }
        }

        // it will check for next branch due to for loop
    }

    return 0;
}

int cycleDetectUndirect(int V, vector<int> adj[])
{
    // we can start from any index, we are starting from 0 index and we will use dfs

    vector<bool> visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            return cycleDetectUndirectMainDfs(adj, i, -1, visited); // at start parent is -1
        }
    }

    return 0; // No cycle found
}

// detect cycle in directed graph using dfs

int cycleDetectdirectMainDfs(vector<int> adj[], int V, vector<bool> &Path, vector<bool> &visited)
{

    visited[V] = 1;
    Path[V] = 1;

    for (int i = 0; i < adj[V].size(); i++)
    {
        if (visited[adj[V][i]])
        {

            if (Path[adj[V][i]])
            {
                return 1;
            }
        }
        else
        {
            int ans = cycleDetectdirectMainDfs(adj, adj[V][i], Path, visited);

            // after last return it will start executing from the down.

            if (ans)
            { // if we received 1 last time then we have to send it to the top.//we could have put ans term here directly.
                return 1;
            }
        }

        // it will check for next branch due to for loop even after reversing back, the current it is present will not be set path 0 as it is out of for loop, first for loop terminates then it stops
    }

    // now it's time to traverse back or reverse from where it came, only mark path as 0 not visited.

    Path[V] = 0;
    return 0;
}

int cycleDetectdirectDfs(int V, vector<int> adj[])
{
    // we can start from any index, we are starting from 0 index and we will use dfs

    vector<bool> visited(V, 0);
    vector<bool> Path(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            return cycleDetectdirectMainDfs(adj, i, Path, visited); // at start path is empty
        }
    }

    return 0; // No cycle found
}

// cycle detection in directed graph using BFS // Kahn's Algorithm

bool isCyclicDirectedBFS(int V, vector<int> adj[])
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

    return ans.size() != V; // cycle present hence ans size is less than vertex
}

// Bipartite Graph (using BFS)
bool isBipartiteBFS(int V, vector<int> adj[])
{

    vector<int> color(V, -1); // no color to all node
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            q.push(i); // for initialization, we need to check for only one at a time, because at start all are -1

            color[i] = 0; // 0 th color is assigned

            while (!q.empty())
            {

                int node = q.front();
                q.pop();

                for (int j = 0; j < adj[node].size(); j++)
                {
                    // if not colored the adjacent
                    if (color[adj[node][j]] == -1)
                    {
                        color[adj[node][j]] = (color[node] + 1) % 2;
                        q.push(adj[node][j]);
                    }

                    // if already colored adjacent
                    else if (color[node] == color[adj[node][j]])
                    {             // -1 at start generally
                        return 0; // not bipartite as adjacent are same color
                    }
                }
            }
        }
    }

    return 1; // it is bipartite
}

// Bipartite Graph (using DFS)
int bipartiteMainDfs(vector<int> adj[], int V, vector<int> &color)
{

    for (int i = 0; i < adj[V].size(); i++)
    {
        // if adjacent is colored
        if (color[adj[V][i]] != -1)
        {
            if (color[adj[V][i]] == color[V])
            {
                return 0; // not bipartite graph
            }
        }
        else
        { // not colored then color it

            color[adj[V][i]] = (color[V] + 1) % 2;
            // color[neighbor] = 1 - color[node]; // Opposite color //this is awesome way

            int ans = bipartiteMainDfs(adj, adj[V][i], color);
            if (!ans)
            { // answer is 0 then traverse it back
                return 0;
            }
        }
    }

    return 1;
}

bool isBipartiteDFS(int V, vector<int> adj[])
{
    // we can start from any index, we are starting from 0 index and we will use dfs

    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;

            if (!bipartiteMainDfs(adj, i, color))
            {             // if it returns 0 then make it flow upward else let for loop continue
                return 0; // at start path is empty
            }
        }
    }

    return 1; // No cycle found
}

int main()
{

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "Adjacency Matrix:" << endl;
    g.display();

    int vertex, edges;
    cout << "Enter number of vertices and edges for graph: ";

    cin >> vertex >> edges;
    createGraph(vertex, edges); // uncomment

    // create directed adjacency list pointer pointing to array containing vector data type
    cout << "creating directed adjacency list " << endl;
    vector<int> *adjlistArr = createDirAdjacenyList(vertex, edges);

    // Important: Don't forget to deallocate the memory.
    // delete[] adjlistArr;

    // let's print out this data
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjlistArr[i].size(); j++)
        {
            cout << adjlistArr[i][j] << " ";
        }
        cout << endl;
    }

    // create weighted undirected adjacency list
    // createAdjacenyList(vertex, edges);

    // vector<pair<int, int>> adjList[vertex] = createAdjacenyList(vertex, edges);//[] is error

    vector<vector<pair<int, int>>> adjList = createAdjacenyList(vertex, edges);

    // Deleting a node in Adjacency list
    int nodeToDelete;
    cout << "Enter node to delete: ";
    cin >> nodeToDelete;
    adjList = deleteNodeAdjacenyList(nodeToDelete, adjList, vertex);

    // BFS traversal
    vector<int> bfs = bfsofGraph(vertex, adjlistArr);

    // DFS traversal
    // ans.clear();
    vector<int> dfs = dfsofGraph(vertex, adjlistArr);

    // topological sort (DAG- Directed acyclic graph) using DFS
    vector<int> topoSortdfs = topoSortDfsofGraph(vertex, adjlistArr);

    // topological sort (DAG- Directed acyclic graph) using BFS
    vector<int> topoSortbfs = topoSortBfsofGraph(vertex, adjlistArr);

    // Note: after topological return, we have to check if all nodes are present or not in the vector return
    if (topoSortdfs.size() == vertex || topoSortbfs.size() == vertex)
    {
        cout << "topological sort possible\n";
    }
    else
    {
        cout << "topological sort not possible\n";
    }

    // Cycle detection in undirected graph
    if (cycleDetectUndirect(vertex, adjlistArr))
    {
        cout << "cycle is detected" << endl;
    }
    else
    {
        cout << "cycle is  not detected" << endl;
    }

    // Cycle detection in directed graph using dfs
    if (cycleDetectdirectDfs(vertex, adjlistArr))
    {
        cout << "cycle is detected" << endl;
    }
    else
    {
        cout << "cycle is  not detected" << endl;
    }

    // Cycle detection in directed graph using bfs
    if (isCyclicDirectedBFS(vertex, adjlistArr))
    {
        cout << "cycle is detected" << endl;
    }
    else
    {
        cout << "cycle is  not detected" << endl;
    }

    // Bipartite Graph (using BFS)
    if (isBipartiteBFS(vertex, adjlistArr))
    {
        cout << "Graph is bipartite" << endl;
    }
    else
    {
        cout << "Graph is not bipartite" << endl;
    }

    // Bipartite Graph (using DFS)
    if (isBipartiteDFS(vertex, adjlistArr))
    {
        cout << "Graph is bipartite" << endl;
    }
    else
    {
        cout << "Graph is not bipartite" << endl;
    }

    //
    //
    // Important: Don't forget to deallocate the memory.
    delete[] adjlistArr;

    return 0;
}