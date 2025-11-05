#include <iostream>
using namespace std;

// Binary Search in 2D
// Search in sorted row and sorted column but whole not sorted.
// binary search in decreasing order array

// timecomplexity O(n+logM)//n for each row and then binary serach in that row //in binary search on matrix or 2D
// don't say N*logM beacuse it is not using binary reach for all row. All row search may takes N time then 1 row selected takes logn time hence time complexity will be added not multiplied.

// Searching with the help of 1D assumption , finding the index using row_index and col_Index then applying binary concept on whole

// index/cols = row_index

// index%cols = column Index

// time complexity in this case is log(n*m);

// Search in sorted row and col, we move either left or down as per condition of A and target
// time Complexity O(n+m)   //as if it has traversed one comple time row and one comple time col
// best case O(1)

// we can start from any corner top right or bottom left.
// we must choose the corner whre it is decresing in one direction and increaing in other direction



// binary search in decreasing order array //only start and mid changes it's condition as comparision to in increasing order


int main()
{

    // binary search in 2D//sorted array
    int rows = 4, cols = 4;
    int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    int start = 0, end = rows * cols - 1;
    int value = 12;

    while (start <= end)
    {
        // int  mid = (start + end) / 2;
        int mid = start + (end - start) / 2;
        int i = mid / cols, j = mid % cols;

        if (arr[i][j] == value)
        {
            cout << "Binary Search iNC :yes present";
            break;
        }
        else if (arr[i][j] < value)
        {
            start = mid + 1;
           
        }
        else
        {
             end = mid - 1;
        }
    }
    cout<<endl;

    // Search in sorted row and col, we move either left or down as per condition of A and target

    int i = 0, j = cols - 1;
    int target = 50;
    int arr2[5][5] = {{4, 8, 15, 25, 60}, {18, 22, 26, 42, 80}, {36, 40, 45, 68, 104}, {48, 50, 72, 83, 130}, {70, 99, 114, 128, 170}};

    // while (i > 0 && i < rows && j > 0 && j < cols)
    while (i < rows && j > 0) //as i always increasing and j always decreasing
    {

        if (arr2[i][j]== target){
            cout<<"sorted row and col , yes Present";
            break;
        }
        else if(arr2[i][j] < target){
            //move down
            i++;
        }
        else{
            // move left
            j--;
        }
    }
   cout<<endl;

    //  // binary search in 2D decreasing sorted array

 
    int arr3[4][4] = {{20,19,18,17}, {16,15,13,12}, {11,10,9,8}, {7,6,5,4}};

    start = 0, end = rows * cols - 1;
   value = 12;

    while (start <= end)
    {
       
        int mid = start + (end - start) / 2;
        int i = mid / cols, j = mid % cols;
        
        if (arr3[i][j] == value)
        {
            cout << "binary search in 2D decreasing  yes present";
            break;
        }
        else if (arr3[i][j] > value)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

       cout<<endl;

    return 0;
}