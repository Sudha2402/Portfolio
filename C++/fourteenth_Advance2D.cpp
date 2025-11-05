#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// column major order.
// row major order

// 2D vector

// Wave form

// spiral form

// Transpose Matrix

int main()
{

    // index=col_index*row+row_index;
    // but here row,col will be the positional val

    // address= base_address+ index*sizeof(datatype)

    // row major is followed by default in all programming language.

    // Order	Index Calculation (0-based)	Address Calculation
    // Row-Major	index = row * cols + col	address = base + index * sizeof(type)
    // Column-Major	index = col * rows + row	address = base + index * sizeof(type)

    int rows = 3, cols = 4;
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    // Row-major traversal (default in C++)
    cout << "Row-major order:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "arr[" << i << "][" << j << "] = " << arr[i][j]
                 << " | Index = " << i * cols + j << endl;
        }
    }

    // Column-major traversal (inefficient in C++)
    cout << "\nColumn-major order:\n";
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            cout << "arr[" << i << "][" << j << "] = " << arr[i][j]
                 << " | Index = " << j * rows + i << endl;
        }
    }

    cout << endl
         << endl;

    // 2D vector
    // vector<vector<int>>matrix;//declaration

    vector<vector<int>> matrix(rows, vector<int>(cols, 2)); // size+initialization //rows 3, cols=4

    matrix[1][2] = 5; // update the value

    // to print it's element
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
            // cin>>matrix[i][j];//to take input from user
        }
        cout << endl;
    }

    // to find the total number of rows
    cout << matrix.size() << endl;    // 3
    cout << matrix[0].size() << endl; // gives number of cols in first row//4
    cout << endl;

    // Wave form
    // int arr[3][4] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};

    int upward = 0;
    for (int i = 0; i < cols; i++) // 4
    {

        for (int j = 0; j < rows; j++)
        { // 3
            // if (!upward)
            if (i % 2 == 0) // even then downward //this analysis is more powerful
            {
                cout << arr[j][i] << "\t";
            }
            else
            {
                cout << arr[rows - 1 - j][i] << "\t";
            }
        }

        // it will be needed only for toggling
        //  if (!upward)
        //  {

        //     upward = 1;
        // }
        // else
        // {

        //     upward = 0;
        // }
        // cout << endl;
    }
    cout << endl
         << endl;

    // Spiral form print elements

    int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
    int totalElement = rows * cols;
    int row = 0, col = 0; // Current position (can be removed)

    while (totalElement > 0)
    {
        if (row == top && col == left && totalElement > 0)
        { // Move right
            for (int i = left; i <= right; i++)
            {
                cout << arr[row][i] << " ";
                totalElement--;
                col = i;
            }
            top++;
            row++;
        }

        if (row == top && col == right && totalElement > 0)
        { // Move down
            for (int i = top; i <= bottom; i++)
            {
                cout << arr[i][col] << " ";
                totalElement--;
                row = i;
            }
            right--;
            col--;
        }

        if (row == bottom && col == right && totalElement > 0)
        { // Move left
            for (int i = right; i >= left; i--)
            { // Fixed: i >= left
                cout << arr[row][i] << " ";
                totalElement--;
                col = i;
            }
            bottom--;
            row--;
        }

        if (row == bottom && col == left && totalElement > 0)
        { // Move up
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][col] << " ";
                totalElement--;
                row = i;
            }
            left++;
            col++;
        }
    }

    cout << endl
         << endl
         << endl;

    // OR //more optimized by removing row and col unnecessary

    left = 0, right = cols - 1, top = 0, bottom = rows - 1;
    totalElement = rows * cols;
    row = 0, col = 0; // Current position (can be removed)

    while (totalElement > 0)
    {

        // sequenctial movement hence we don't need if condition because its direction are fixed. //hence we can remove if and add totalElement > 0 in for loop update

        // if (row == top && col == left && totalElement > 0)
        { // I am present at top most row and leftmost column
            // move right
            for (int i = left; i <= right && totalElement > 0; i++)
            {
                cout << arr[top][i] << "\t";
                totalElement--;

                // col = i;//not needed as we are not checking if condition
            }
            top++;
            // row++;
        }
        cout << endl;

        // if (row == top && col == right && totalElement > 0)
        { // it has just finished top row and increment top row value //move downward in this case
            for (int i = top; i <= bottom && totalElement > 0; i++)
            {
                // cout << arr[i][col];
                cout << arr[i][right] << "\t";
                totalElement--;

                // row = i;
            }
            right--;
            // col--;
        }

        cout << endl;

        // if (row == bottom && col == right && totalElement > 0)
        { // it has just finished right col //move left in this case
            for (int i = right && totalElement > 0; i >= left; i--)
            {
                // cout << arr[row][i];
                cout << arr[bottom][i] << "\t";
                totalElement--;

                // col = i;
            }
            bottom--;
            // row--;
        }

        cout << endl;

        // if (row == bottom && col == left && totalElement > 0)
        { // it has just finished bottom row //move upward in this case
            for (int i = bottom; i >= top && totalElement > 0; i--)
            {
                cout << arr[i][left] << "\t";
                totalElement--;

                // row = i;
            }
            left++;
            // col++;
        }

        cout << endl;
    }

    cout << endl
         << endl
         << endl;
    // One more condition that can be applied

    left = 0, right = cols - 1, top = 0, bottom = rows - 1;

    // rows=arr.size();//works in case of vector

    while (left <= right && top <= bottom)
    {

        for (int i = left; i <= right; i++)
        {
            cout << arr[top][i] << "\t";
        }
        top++;
        cout << endl;

        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][right] << "\t";
        }
        right--;

        cout << endl;

        for (int i = right; i >= left && top <= bottom; i--)
        { // imagine when solving horizontally, test cases may cause problem when top becomes greater than bottom in between and further left right works then reprint the printed. Right and left ko bhi solve karne se pagle dekhna padega sare test cases. Agar top aage bad gaya h aur lefte right hi sirf comparision kar rahe h uppar wale me toh vo bhi ek problem h. Esliye top ko bhi check karna h.

            cout << arr[bottom][i] << "\t";
        }
        bottom--;

        cout << endl;

        for (int i = bottom; i >= top && top <= bottom; i--)
        { // fir hum vertically ke liye check karenge.
            cout << arr[i][left] << "\t";
            totalElement--;
        }
        left++;

        cout << endl;
    }

    // Transpose matrix
    int transPoseMatrix[cols][rows];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transPoseMatrix[j][i] = arr[i][j];
        }
        // cout << endl;
    }

    // to print it's element
    cout << "Transpose Matrix : \n";
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << transPoseMatrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    // If we want O(1) space complexity then use same matrix and work only in square matrix
    rows = 4, cols = 4;
    int arr2[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {1, 2, 3, 4}};

    cout << "Actual Array : \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    // To convert the orignal matrix into tanspose matrix//05 changes to 50//without using extra space
    //  cout << "Transpose Matrix : \n";

    int Newrows = cols;
    int Newcols = rows;

    int startX = 0;
    int startY = 0;

    // it will have worked only with //only for square matrix

    for (int i = startX; i < rows; i++)
    {
        for (int j = startY; j < cols; j++)
        {
            swap(arr2[i][j], arr2[j][i]); // one time swap will be swapped again
        }
        startX++;
        startY++;

        // cout << endl;
    }

    cout << "Transpose Matrix Result with start index tracing : \n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Transpose Matrix with half part: \n";
    // it will have worked  only with //we can fo it for half part only//only when j>i
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = i + 1; j < cols; j++)
        {
            swap(arr2[i][j], arr2[j][i]); // one time swap will be swapped again
        }
    }

    cout << "Transpose Matrix Result: \n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // note all the ways of transpose calculation

    return 0;
}
