// search element in a 2D array
#include <iostream>
using namespace std;

void print2D(int arr[][4], int row, int col)
{ // col is necessary to pass. so that compiler can understand which index value is asked and for index calculation, row_index , col_index are passed with array as find the value at this index. So it will get ro_index value from there and col is necessay to find the valuse of index.

    // index=row_index*col + colIndex;

    // address=baseAddress+index*sizeof(dayatype)

    for (int i = 0; i < row; i++) // we can also print it col wise just by change the range value
    {
        for (int j = 0; j < col; j++)
        {

            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void addMatrix(int arr[3][4], int arr2[3][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] + arr2[i][j] << "\t";
        }
        cout << endl;
    }
}

int rowIndexMaxSum(int arr[5][4], int row, int col)
{
    int sum = INT32_MIN, rowIndex, maxSum = INT32_MIN;
    for (int i = 0; i < row; i++)
    {
        sum = 0;
        cout << maxSum << endl;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }

        if (sum > maxSum)
        {
            maxSum = sum;
            rowIndex = i;
        }
    }

    return rowIndex;
}

int diagonalSum(int arr[4][4], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        sum += arr[i][i] + arr[i][col - i];
    }

    if (row % 2 != 0)
    {
        // there is one comon added twice
        sum = sum - arr[col / 2][col / 2];
    }

    return sum;
}

void reverseRow(int arr[3][4], int row, int col)
{
    int arrNew[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arrNew[i][col - 1 - j] = arr[i][j];
            // we can also use swapping
        }
    }


    // this is done using two pointer.
    
     for (int i = 0; i < row; i++)
    {

        int start=0,end=col-1;
        while (start<end){
            swap(arr[i][start],arr[i][end]);
            start++; end--;
        }
        
    }


    // to print it's element
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arrNew[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
}

int main()
{
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int element = 7;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == 7)
            {
                cout << i << " " << j << endl; // 2 0
                break;
            }
        }
    }

    print2D(arr, 3, 4); // we don't need to pass brackets, just base address is passed//row and col is passed for running the for loop.

    int arr1[3][4] = {2, 3, 4, 5, 0, 1, 2, 3, 1, 2, 6, 4};
    int arr2[3][4] = {3, 4, 1, 2, 2, 2, 0, 1, 3, 5, 4};
    int arr3[5][4] = {3, 4, 7, 18, 2, 8, 3, 9, 5, 4, 2, 2, 7, 3, 0, 8, 2, 8, 90, 1};
    int arr4[4][4] = {5, 8, 3, 9, 6, 2, 8, 4, 5, 3, 2, 2, 2, 8, 1, 9};
    int arr5[3][4] = {2, 3, 4, 5, 1, 2, 6, 8, 4, 9, 3, 2};
    addMatrix(arr1, arr2, 3, 4);
    cout << endl;
    cout << rowIndexMaxSum(arr3, 5, 4) << endl;

    cout << endl;
    cout << diagonalSum(arr4, 4, 4) << endl;
    cout << endl;
    reverseRow(arr5, 3, 4);
    cout << endl;
    return 0;
}