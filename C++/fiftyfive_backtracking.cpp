#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <stack>
#include <algorithm>

// N queen placement
// M coloring problem
// Sudoku Solver

// N queen placement
// placing N queens on N*N chessboard

void queensPositionWrong(vector<string> &chessBoard, int m, int n, vector<vector<string>> &ans)
{

    // But this still has the "systematic exploration" problem - you're not guaranteed to try all columns!

    // Your current logic creates exponential recursion and invalid solutions because conflicts don't actually prevent queen placement!

    // Check column conflict at position (m, n)

    // If conflict found, move to next column (n+1) at the same row

    // But you don't return after finding conflict!

    // Continue checking other conflicts and potentially place queen in invalid position

    if (m == chessBoard.size())
    {
        ans.push_back(chessBoard);
        return;
    }

    // m and n is the index we have to check

    // place it here
    // check above row and above prev col if no intereaction with other

    int conflict = 0;
    // check for same col, changing row value
    for (int i = 0; i <= m; i++)
    {
        if (chessBoard[i][n] == '1')
        {
            // conflict with this position
            if (n + 1 < chessBoard.size())
            {
                queensPositionWrong(chessBoard, m, n + 1, ans); // next col // this way of next col call is wrong, instead go for for loop in the col value.

                // this branch call is not a good approch as it leads to fursther recursive call from here thill the last cell but we need only the current row and all columns hence we will define the current row by ourself

                conflict = 1;
            }

            // return; // Added return //// EXIT THIS CALL - Never checks diagonals!

            // NO RETURN - continues to diagonal check!

            // You only check one conflict type at a time

            // You might miss other conflict types (diagonals)

            // The recursion becomes too complex to manage
        }
    }

    // Diagonal conflict found → ANOTHER recursive call
    // check for same diagonal left and right

    if (!conflict)
    { // if no conflict found in the col check then only go for diagonal.

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j < chessBoard.size(); j++)
            {
                if (chessBoard[i][j] == '1' && (i + j == m + n || i - j == m - n))
                {
                    // conflict with this position
                    if (n + 1 < chessBoard.size())
                    {
                        queensPositionWrong(chessBoard, m, n + 1, ans); // next col
                        conflict = 1;
                    }
                }

                // return;
            }
        }
    }

    // do this when no conflict
    if (!conflict)
    {
        chessBoard[m][n] = '1'; // string data is updated

        // // check for next row
        // if (m + 1 == chessBoard.size())
        // {
        //     // last row setted
        //     ans.push_back(chessBoard);
        //     // now back track
        //     chessBoard[m][n] = '.';
        // }
        // else
        // {
        queensPositionWrong(chessBoard, m + 1, 0, ans); // check in next row

        // backtrack if return from here
        chessBoard[m][n] = '.';
    }

    // }
}

void queensPosition(vector<string> &chessBoard, int m, vector<vector<string>> &ans)
{

    if (m == chessBoard.size())
    {
        ans.push_back(chessBoard);
        return;
    }
    // we need to check upto all columns then traverse back

    // int conflict = 0;
    for (int k = 0; k < chessBoard.size(); k++)
    {
        int conflict = 0;
        // same col check
        for (int i = 0; i <= m; i++)
        {
            if (chessBoard[i][k] == '1')
            {
                conflict = 1;
                break; // move to next k value
            }
        }

        if (!conflict)
        {

            // Note: Your diagonal check is inefficient - it checks all positions on the board instead of just the relevant diagonals. But it's functionally correct.

            // for (int i = 0; i <= m; i++)
            // {
            //     for (int j = 0; j < chessBoard.size(); j++)
            //     {
            //         if (chessBoard[i][j] == '1' && (i + j == m + k || i - j == m - k))
            //         {
            //             conflict = 1;
            //             break; // move to next k value // // Only breaks inner j loop, not outer i loop!
            //         }

            //         // return;
            //     }

            //     if (conflict)
            //     {
            //         break;
            //     }
            // }

            // instead of starting from 0, we should move -ve from current
            int i = m - 1, j = k - 1;
            // left upper diagonal check
            while (i >= 0 && j >= 0)
            {

                // diff check
                if (chessBoard[i][j] == '1')
                { // j - i == k - m  always 1 as we deducted in that manners
                    conflict = 1;
                    break;
                }

                i--;
                j--;
            }

            if (!conflict)
            {
                i = m - 1, j = k + 1; // Start from position above-right
                                      // right upper diagonal check
                while (i >= 0 && j < chessBoard.size())
                {

                    // sum check
                    if (chessBoard[i][j] == '1')
                    {
                        // j + i == k + m
                        conflict = 1;
                        break;
                    }

                    i--;
                    j++;
                }
            }
        }

        if (!conflict)
        {
            chessBoard[m][k] = '1';
            queensPosition(chessBoard, m + 1, ans);
            chessBoard[m][k] = '.';
        }

        // for next k , reset conflict
        //  conflict = 0;
    }
}

vector<vector<string>> solveNQueens(int n)
{
    // n queens

    // we need backtracking, emans we have to use recursion, hence call another function
    vector<string> chessBoard(n);
    // {"....","....","....","...."};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            chessBoard[j].push_back('.');
        }
    }
    // n * '.' // not work directly

    vector<vector<string>> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << chessBoard[i][j];
        }
        cout << endl;
    }

    // ....
    // ....
    // ....
    // ....

    queensPosition(chessBoard, 0, ans);

    return ans;
}

// M coloring problem

int graphColordfs(int node, bool graph[101][101], int m, int n, vector<int> &color)
{
    // graph contains each edge record.
    // node is colored with prevColor which is one among the m.

    // color the node with color other than prevnode

    // color one level at a time

    // int colorDecided = 0;//this comparision is not ok, hence we will use colorFoundAdj vector

    vector<bool> colorFoundAdj(m, 0);

    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && color[i] != -1)
        { // edge present but color.
          // there is an egde between them

            // may be this adjacent is colored, hence we need to check the color also

            // m colors

            // here for coloring , we have to check prev color and also adjacent of this node color, simply check adjacent of node colors, don't include prev like complexity

            // if (color[i] == colorDecided)
            // {
            //     colorDecided = (colorDecided + 1) % m;
            //     // check for another color
            // }

            colorFoundAdj[color[i]] = 1;
        }
    }

    // color[node] = colorDecided;

    int uncoloredNodeMore = 0;
    for (int i = 0; i < m; i++)
    {
        if (colorFoundAdj[i] == 0)
        {
            // we can use this color
            color[node] = i;

            // let's get new unvisited node
            for (int i = 0; i < n; i++)
            {
                uncoloredNodeMore = 0; // each return, we are checking the new

                // get new uncolored node
                // if no new uncolored node then return 1
                if (graph[node][i] == 1 && color[i] == -1)
                {
                    uncoloredNodeMore = 1;
                    if (graphColordfs(i, graph, m, n, color))
                    {
                        // if it returns 1
                        continue; // continue for searching new uncolored
                    }
                    else
                    {
                        break; // change this color//automatically checks the new 0 in colorFoundAdj array
                    }
                }
            }

            // when no more uncoloredNodeMore then return 1, don't uncolor this
            if (uncoloredNodeMore)
            {
                color[node] = -1; // remove the last color
            }
            else
            {
                return 1; // all adjacent colored
            }
        }
    }

    return 0; // colorFoundAdj[i] == 0 for none, hence can't put any color.
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    //     Maximum number of nodes: 100
    // So array size 101 covers indices 0 to 100 // // Maximum constraint
    // Actual: n nodes, m colors
    // This would be better but less common:
    // bool graph[n][n];  // Variable length array (not standard C++)'

    // 101×101 = Maximum possible size based on problem constraints
    //  Actual usage = Only first n×n portion where n ≤ 100
    //  Purpose = Simplicity, avoid dynamic allocation, handle worst case

    // here m are colors and graph is adj matrix, n is number of nodes
    //  we have to color each nodes and sinnce , we have to keep checking for adjacent, we can use bfs also but it is not easy to trace back to change the color hence we will use dfs. color each nodes either disconnected or connected.

    vector<int> color(n, -1); // no node is colored yet.

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            // this is the start of each disconnected node in the graph, now proceed to dfs
            if (graphColordfs(i, graph, m, n, color))
            {
                // prevNode is not colored
                continue;
            }
            else
            {
                return 0;
            }
        }
    }

    return 1;
}

// Correct Default Graph Coloring approch:

bool isSafe(int node, int col, bool graph[101][101], int n, vector<int> &color)
{ // col is the color which we have to test fro this node wheather safe or not

    // checking all the adjacent nodes.
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] && color[i] == col)
        {
            return 0;
        }
    }
    return 1;
}

bool graphColordfsDefault(int node, bool graph[101][101], int m, int n, vector<int> &color)
{
    // If all nodes are colored
    if (node == n)
    {
        return 1; // one time return at the last hence it is directly taken in the main call function
        // it checks all node available must be colored then return 1.
    }

    // Try all colors for current node
    for (int col = 0; col < m; col++)
    {
        if (isSafe(node, col, graph, n, color))
        { // each color is tested for all adjacent in the safe function check

            // when safe returns 1 //if no color would be assinged out of these m colors then it will get out of for loop and reach to return 0 and that is propogated to the top as return answer.

            color[node] = col;

            // Recursively color next node
            if (graphColordfsDefault(node + 1, graph, m, n, color))
            {

                // this if propogate the result

                // here we are moving to the next node number ourself instead of checking the next connected.

                // 0 connected to: 1,4,5,10
                // 1 connected to: 0,2,3,4
                // 2 connected to: 1,3
                // 3 connected to: 1,2,4,5,8,9
                // 4 connected to: 0,1,3
                // 5 connected to: 0,3,6,7
                // 6 connected to: 5,7
                // 7 connected to: 5,6
                // 8 connected to: 3,9
                // 9 connected to: 3,8.

                // after 4 node, all connected are colored, but we are not checking the connected to be selected next, we are using next number hence node+1 starts from 0 to n, this way we cover all the disconnected also.

                return 1; // here as we are calling in if condition then it will come inside only at the last when node == n then it is transferred upward
            }

            // Backtrack
            color[node] = -1;
        }
    }

    return 0;
}

bool graphColoringDefault(bool graph[101][101], int m, int n)
{
    vector<int> color(n, -1);
    // start node 0 is given
    return graphColordfsDefault(0, graph, m, n, color);
}

// combined method using dfsForGraphColor only
bool dfsForGraphColor(int node, bool graph[101][101], int m, int n, vector<int> &color)
{

    // try each color
    for (int i = 0; i, m; i++)
    {

        // no adjacent node should have this color
        bool ispossible = 1; // shows possible to color with this

        for (int j = 0; j < n; j++)
        {
            if (graph[node][j] && color[j] == i)
            {
                ispossible = 0;
                break;
            }
        }

        if (ispossible == 0)
        {
            continue;
        }

        // if no ispossible error comes then use i color, isspossible is 1 now
        color[node] = i;

        // go to the adjacent node, whom the color is not assigned
        // isspossible = 1 as it is colored

        for (int j = 0; j < n; j++)
        {
            if (graph[node][j] && color[j] == -1)
            {

                if (!dfsForGraphColor(j, graph, m, n, color))
                {
                    ispossible = 0;
                    break;
                }
            }
        }

        // ispossible remains 1 till dfsForGraphColor returning 1., because for 0 it will make ispossible 0 and break from there and needed to change the color. next check for another color
        if (ispossible)
        {

            // if ispossible return 0 last time from adjacent node check //this ispossible will start coming from the last most node where not more uncolored adjacent for this.

            return 1;
        }

        // if not possible then change the color. for loop of color will continue.
        color[node] = -1;
    }

    // reach to it at the deapthest node then it is popogate above then color is changes and recalled.

    return 0;
}

bool graphColoringdfs(bool graph[101][101], int m, int n)
{
    vector<int> color(n, -1);
    // start node 0 is given
    return dfsForGraphColor(0, graph, m, n, color);
}

// Sudoku Solver

int check(int num, int i, int j, vector<vector<char>> &board)
{
    // check same row
    char c = num + '0';
    for (int k = 0; k < 9; k++)
    {
        // if (board[i][k] == char(num))
        if (board[i][k] == c)
        {             // board[i][k] != '.' already checked in find hence it is selected
            return 0; // not fit number
            // this return is whole function return , it does not come back to complete the for loop as no internal calling is done.
        }
    }

    // check same col
    for (int k = 0; k < 9; k++)
    {
        if (board[k][j] == c)
        {
            return 0; // not fit number
        }
    }

    // check box
    for (int m = i / 3 * 3; m < (i / 3 * 3) + 3; m++)
    {
        for (int n = i / 3 * 3; n < (i / 3 * 3) + 3; n++)
        {
            if (board[m][n] == c)
            {
                return 0; // not fit number
            }
        }
    }

    // or we could have store this i / 3 * 3
    int row = i / 3 * 3, col = i / 3 * 3;
    for (int m = 0; m < 3; m++)
    {
        for (int n = 0; n < 3; n++)
        {
            if (board[m + row][n + col] == c)
            {
                return 0; // not fit number
            }
        }
    }

    return 1;
}

int findValueSudokui(int i, int j, vector<vector<char>> &board)
{
    // base condition
    if (i == 9)
    {
        // all row filled
        return 1;
    }

    if (j == 9)
    {
        // current row, all columns filled, move to next row
        return findValueSudokui(i + 1, 0, board); // it is called once hence propogate it's answer in the return. here we use it once not the branches.
    }

    // check i, j if not empty then move to next
    if (board[i][j] != '.')
    {
        // not . then move to next col
        return findValueSudokui(i, j + 1, board);
    }

    // if . is found at this index then fill it
    for (int k = 1; k <= 9; k++)
    {
        // check the color possible
        if (check(k, i, j, board))
        {
            // if return 1 , fill this, then check for new unfilled
            // board[i][j] = char(k);

            board[i][j] = '0' + k;

            if (findValueSudokui(i, j + 1, board))
            {
                return 1; // if find returns 1, then this number is assigned. // findValueSudokui(i, j + 1, board)

                // it will get 1 in the find only at last + 1 row and thereafter just propogate the result, here directly  return findValueSudokui(i, j + 1, board) can't be moved because we need to change the didit at this position when return is 0.
            }

            // we are returning only for changing the color.
            // 0 is returned
            //  remove this number
            board[i][j] = '.';
        }
    }

    return 0; // when no number can be assigned
}

void solveSudokui(vector<vector<char>> &board)
{

    // here we are going to use the approch of filling all the elements in a row, traverse through all column then move to next row. if row reached more than 8 index then return 1.

    findValueSudokui(0, 0, board);
}

int main()
{
    int queens = 4;
    vector<vector<string>> possibleWays = solveNQueens(queens);

    cout << possibleWays.size() << endl;

    for (int i = 0; i < possibleWays.size(); i++)
    {
        for (int j = 0; j < queens; j++)
        {
            for (int k = 0; k < queens; k++)
            {
                cout << possibleWays[i][j][k];
                // cout << possibleWays[i][j];
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }

    // M coloring problem
    bool graph[101][101] = {0}; // default filled all with 0
    int n, m, e;                // nodes, colors, edges
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of colors: ";
    cin >> m;
    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    bool result = graphColoring(graph, m, n);
    cout << "Graph can be colored with " << m << " colors: "
         << (result ? "YES" : "NO") << endl;

    int n = 7, m = 3;

    // Adjacency matrix for 7 nodes
    bool graph[101][101] = {
        // 0  1  2  3  4  5  6
        {0, 1, 1, 1, 0, 0, 0}, // Node 0
        {1, 0, 0, 0, 1, 1, 0}, // Node 1
        {1, 0, 0, 0, 1, 0, 1}, // Node 2
        {1, 0, 0, 0, 0, 1, 1}, // Node 3
        {0, 1, 1, 0, 0, 1, 0}, // Node 4
        {0, 1, 0, 1, 1, 0, 1}, // Node 5
        {0, 0, 1, 1, 0, 1, 0}  // Node 6
    };

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    bool result = graphColoring(graph, m, n);
    cout << "Can color 7-node graph with " << m << " colors: "
         << (result ? "YES" : "NO") << endl;

    // Test with different numbers of colors
    for (int colors = 1; colors <= 4; colors++)
    {
        bool res = graphColoring(graph, colors, n);
        cout << "With " << colors << " colors: " << (res ? "Possible" : "Impossible") << endl;
    }

    // Another test
    int n = 13, m = 3;
    bool graph[101][101] = {false};

    // Define all edges
    int edges[][2] = {
        {0, 1}, {0, 4}, {0, 10}, {0, 5}, {1, 2}, {1, 4}, {1, 3}, {2, 3}, {3, 4}, {3, 5}, {3, 8}, {3, 9}, {8, 9}, {5, 6}, {6, 7}, {5, 7}, {10, 11}, {11, 12}, {10, 12}};

    int numEdges = sizeof(edges) / sizeof(edges[0]);

    // Build the graph
    for (int i = 0; i < numEdges; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u][v] = graph[v][u] = true;
    }

    // Print adjacency matrix (first 13x13)
    cout << "Adjacency Matrix (13 nodes):" << endl;
    cout << "   ";
    for (int j = 0; j < n; j++)
        cout << j % 10 << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i % 10 << ": ";
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    bool result = graphColoring(graph, m, n);
    cout << "13-node graph coloring with " << m << " colors: "
         << (result ? "SUCCESS" : "FAILED") << endl;

    //
    // Sudoku Solver

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},

    };

    solveSudokui(board);

    // we can traverse this board again to get the filled result
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}
