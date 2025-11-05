#include <iostream>
using namespace std;

// Rotate by 90 degree//also called rotate image by 90 degree as image is points in matrix form hence it can be taken in that way

// One time 90 deg + 90 deg is 180 degrades
// 270= 3*(90 deg)

// for 180 degree rotation , we can simply use colum reverse  then -> row reverse

// rotate 90 deg anti-clockwise

// rotate matrix k times//each time 90 deg is rotated

// Note: Any rotation can be solved using 3 concepts
// transpose
// row reverse
// column reverse

// combination of these

// time complexiy O(row*col)

int main()
{

    // i=j, j=col-i.
    // Update karne se purana gayab ho jayega toh new Array banake kar lete h

    int rows = 4, cols = 4;
    int arr2[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

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

    int arrRotated90[4][4];

    cout << "Rotate Array by 90 deg : \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arrRotated90[j][cols - 1 - i] = arr2[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arrRotated90[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

    // We can try to solve without using extra space

    // we noticed that
    // 0,0 -> 0,3
    // 0,3 -> 3,3
    // 3,3 -> 3,0
    // 3,0 -> 0,0

    // 0,1 -> 1,3 // i,j = j,cols-1-i
    // 1,1 -> 1,2 //pattern works

    // we noticed that

    // i=j //j=i //i+j=3

    // 0,0 <- 0,3

    // 0,3 <- 0,0
    // 3,3 <- 0,3
    // 3,0 <- 3,3

    // 0,1 <- 2,0 // i,j <- j,cols-1-i
    // 1,1 <- 2,1 //pattern works

    // 0,2 <- 1,0 // i,j = j,cols-1-i

    // i=j and j=cols-1-i

    // store 0,0 somewhere
    // update from downward

    // i=3, j=0// range row to o and col from 0 to cols
    //     arr[j][cols-1-i]= arr2[i][j] //0 ,1 -> 1, 3

    // no such logic is working without extra space or creating new array.

    cout << "Rotate Array by 90 deg in place , Transpose -> reverse: \n";

    //  transpose
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = i + 1; j < cols; j++)
        {
            swap(arr2[j][i], arr2[i][j]);
        }
    }

    // reverse
    for (int i = 0; i < rows; i++)
    {
        // for (int j = 0; j < cols / 2; j++)
        // {
        //     swap(arr2[i][j], arr2[i][cols - 1 - j]);
        // }

        // or using two pointer
        int start = 0, end = cols - 1;
        while (start < end)
        {
            swap(arr2[i][start], arr2[i][end]);
            start++, end--;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // 180 degree rotation.

    cout << "Rotate by 180 deg: \n";
    // colum reverse //column wise swapping then column increment

    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows / 2; i++)
        {
            swap(arr2[i][j], arr2[rows - 1 - i][j]);
        }
    }

    // row reverse
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols / 2; j++)
        {
            swap(arr2[i][j], arr2[i][cols - 1 - j]);
        }
    }

    // print
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // for 180 deg rotation , we can have one more logic, just by shifting the position of index

    // int temp = arr[i][j]
    //  arr[i][j]= arr[rows-1-i][col-1-j]
    // arr[rows-1-i][col-1-i]=temp

    // this works in 180 deg

    for (int i = 0; i < rows / 2; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // int temp = arr2[i][j];
            // arr2[i][j] = arr2[rows - 1 - i][cols - 1 - j];
            // arr2[rows - 1 - i][cols - 1 - j] = temp;

            swap(arr2[rows - 1 - i][cols - 1 - j], arr2[i][j]);

            // works only when swapping has to be done, not works in 90 deg rotation
        }
    }
    cout << endl;

    // print
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // rotate anti-clockwise
    // first transpose then reverse column
    cout << "Rotate Array by -90 deg in place , Transpose -> reverse col: \n";

    //   we can also follow row reverse then transpose

    //   we can also do 3*90 deg to get 270 deg as 270 deg= -90 deg

    //  transpose
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = i + 1; j < cols; j++)
        {
            swap(arr2[j][i], arr2[i][j]);
        }
    }

    // reverse column
    for (int j = 0; j < cols; j++)
    {

        // or using two pointer
        int start = 0, end = rows - 1;
        while (start < end)
        {
            swap(arr2[start][j], arr2[end][j]);
            start++, end--;
        }
    }

    // print
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Rotate the matrix k times
    cout << "Rotate Array k times by 90 deg in place , Transpose -> reverse: \n";

    int ktimes;
    cout << "Enter the number of times to be rotated: ";
    cin >> ktimes;

    while (ktimes % 4) // incase 5 writes then works only once//as 1 complete 360 deg after 4
    {
        //  transpose
        for (int i = 0; i < rows - 1; i++)
        {
            for (int j = i + 1; j < cols; j++)
            {
                swap(arr2[j][i], arr2[i][j]);
            }
        }

        // reverse
        for (int i = 0; i < rows; i++)
        {
            // for (int j = 0; j < cols / 2; j++)
            // {
            //     swap(arr2[i][j], arr2[i][cols - 1 - j]);
            // }

            // or using two pointer
            int start = 0, end = cols - 1;
            while (start < end)
            {
                swap(arr2[i][start], arr2[i][end]);
                start++, end--;
            }
        }

        ktimes--;
    }

    //  print k rotation output
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}