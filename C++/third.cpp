#include <iostream>
using namespace std;

int main()
{
    cout << "Pattern Printing\n";
    cout << "Enter rows and col: \n";
    int row, col;
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int i = 0; i < col; i++)
        {
            cout << "*\t";
        }
        cout << "\n";
    }

    // row number pattern
    // 1       1
    // 2       2
    // 3       3
    // 4       4
    // 5       5

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << i + 1 << "\t";
        }
        cout << "\n";
    }

    // column number pattern
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << j + 1 << "\t";
        }
        cout << "\n";
    }

    // reverce column number pattern
    for (int i = 0; i < row; i++)
    {
        for (int j = col; j > 0; j--)
        {
            cout << j << "\t";
        }
        cout << "\n";
    }

    // column square number pattern
    for (int i = 0; i < row; i++)
    {
        for (int j = col; j > 0; j--)
        {
            cout << j * j << "\t";
        }
        cout << "\n";
    }

    // row alphabet pattern
    char rowlast = 'a' + row; // d
    // cout<<collast;
    for (char j = 'a'; j < rowlast; j++)
    {
        for (int i = 0; i < col; i++)
        {
            cout << j << "\t";
        }
        cout << "\n";
    }

    // col alphabet pattern
    char collast = 'a' + col; // d
                              // cout<<collast;

    for (int i = 0; i < row; i++)
    {

        for (char j = 'a'; j < collast; j++)
        {
            cout << j << "\t";
        }
        cout << "\n";
    }

    // number print with increment
    // 1       2       3       4       5
    // 6       7       8       9       10
    // 11      12      13      14      15
    // 16      17      18      19      20
    // 21      22      23      24      25
    for (int i = 0; i <= row; i++)
    {

        for (char j = 0; j < col; j++)
        {
            cout << col * i + j + 1 << "\t"; // we are tracking how much elements are printed as row is tracked//
        }
        cout << "\n";
    }

    cout << "\n"; // we can use count also

    int numcount = 1;
    for (int i = 0; i <= row; i++)
    {

        for (char j = 0; j < col; j++)
        {

            cout << numcount << "\t";
            numcount++;
        }
        cout << "\n";
    }

    // left pyramid
    // *
    // **
    // ***
    // ****
    // *****
    // ******
    for (int i = 1; i <= row; i++)
    {

        for (char j = 0; j < i; j++)
        {

            cout << "*";
        }
        cout << "\n";
    }

    // // left pyramid

    // for (int i = 1; i <= row; i++)
    // {
    //     cout << "*\t" * i << "\n";//not valid in c++// hence we need loop for this
    // }

    // number left pyramid pattern

    for (int i = 1; i <= row; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << "\n";
    }

    // number left pyramid pattern
    // 1
    // 2 2
    // 3 3 3
    // 4 4 4 4
    // 5 5 5 5 5
    // 6 6 6 6 6 6
    for (int i = 1; i <= row; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    // character left pyramid pattern
    char rowchar = 'a' + row - 1;
    for (char i = 'a'; i <= rowchar; i++)
    {
        for (char j = 'a'; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    // or

    // character left pyramid pattern
    // a
    // b b
    // c c c
    // d d d d
    // e e e e e
    // f f f f f f

    for (int i = 1; i <= row; i++)
    {
        char rowchar = 'a' + i - 1;
        for (char j = 'a'; j <= rowchar; j++)
        {
            cout << rowchar << " ";
        }
        cout << "\n";
    }

    // reverse star
    // * * * * * *
    // * * * * *
    // * * * *
    // * * *
    // * *
    // *
    for (int i = row; i > 0; i--)
    {
        // for (int j = i; j > 0; j--)
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }

    cout << "\n";
    // or

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < (row - i); j++)
        {

            cout << "* ";
        }
        cout << "\n";
    }

    // number uper left pyramid

    // 1 2 3 4 5 6
    // 1 2 3 4 5
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= (row + 1 - i); j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    // number left pyramid
    // 6
    // 6 5
    // 6 5 4
    // 6 5 4 3
    // 6 5 4 3 2
    // 6 5 4 3 2 1
    for (int i = row; i >= 1; i--)
    {
        for (int j = row; j >= i; j--)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    // right pyramid
    //         *
    //       * *
    //     * * *
    //   * * * *
    // * * * * *
    for (int i = 1; i <= row; i++)
    {
        for (int j = row; j > 0; j--)
        {
            if (j > i)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }

        cout << "\n";
    }

    // or

    for (int i = 1; i <= row; i++)
    {
        for (int j = row - i; j > 0; j--)
        {
            cout << "  ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << "* ";
        }

        cout << "\n";
    }

    // right number half pyramid
    //          1
    //        2 2
    //      3 3 3
    //    4 4 4 4
    //  5 5 5 5 5
    for (int i = 1; i <= row; i++)
    {
        for (int j = row; j > 0; j--)
        {
            if (j > i)
            {
                cout << "  ";
            }
            else
            {
                cout << i << " ";
            }
        }

        cout << "\n";
    }

    // reverse number count right pyramid
    //         1
    //       2 1
    //     3 2 1
    //   4 3 2 1
    // 5 4 3 2 1

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= row; j++)
        {
            if (j <= row - i)
            {
                cout << "  ";
            }
            else
            {
                cout << row - j + 1 << " ";
            }
        }

        cout << "\n";
    }

    // number count right pyramid

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= row; j++)
        {
            if (j <= row - i)

            {
                cout << "  ";
            }
            else
            {
                cout << j << " ";
            }
        }
        cout << "\n";
    }

    // number count right pyramid//some time three for loops are good for space printing.
    //         1
    //       1 2
    //     1 2 3
    //   1 2 3 4
    // 1 2 3 4 5

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= row - i; j++)
        {

            cout << "  ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << k << " ";
        }

        cout << "\n";
    }

    // alphabets
    //         A
    //       A B
    //     A B C
    //   A B C D
    // A B C D E
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= row - i; j++)
        {

            cout << "  ";
        }
        for (char k = 'A'; k < ('A' + i); k++)
        {
            cout << k << " ";
        }

        cout << "\n";
    }

    // with tree for loops , it can be from 1 to 2*rowno.-1

    //         *
    //       * * *
    //     * * * * *
    //   * * * * * * *
    // * * * * * * * * *
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j < row + i; j++)
        {
            if (j <= (row - i))
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }

        cout << "\n";
    }

    // pattern print//palidrome
    //           1
    //         1 2 3
    //       1 2 3 4 5
    //     1 2 3 4 5 6 7
    //   1 2 3 4 5 6 7 8 9
    // 1 2 3 4 5 6 7 8 9 10 11

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= row - i; j++)
        {

            cout << "  ";
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            cout << k << " ";
        }

        cout << "\n";
    }

    // pattern print//palidrome
    //           1
    //         1 2 3
    //       1 2 3 4 5
    //     1 2 3 4 5 6 7
    //   1 2 3 4 5 6 7 8 9
    // 1 2 3 4 5 6 7 8 9 10 11

    // we alanayse that after printing upto rows it start decreasing from row-1 to 1
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= row - i; j++)
        {

            cout << "  ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << k << " ";
        }
        for (int k = i - 1; k >= 1; k--)
        {
            cout << k << " ";
        }

        cout << "\n";
    }

    //         1
    //       1 2 1
    //     1 2 3 2 1
    //   1 2 3 4 3 2 1
    // 1 2 3 4 5 4 3 2 1

    // reverse pyramid star

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j < i; j++)
        {

            cout << "  ";
        }
        for (int k = i; k <= 2 * row - i; k++)

        {
            cout << "*" << " ";
        }

        cout << "\n";
    }

    // or

    // reverse pyramid star

    for (int i = row; i > 0; i--)
    {
        for (int j = 1; j <= row - i; j++)
        {

            cout << "  ";
        }
        for (int k = 1; k <= 2 * i - 1; k++)

        {
            cout << "*" << " ";
        }

        cout << "\n";
    }

    // special patterns

    // * * * * * * * *
    // * * *     * * *
    // * *         * *
    // *             *
    // *             *
    // * *         * *
    // * * *     * * *
    // * * * * * * * *

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 2 * row; j++)
        {

            if (j >= row - i and j < row + i)
            {
                cout << " " << " ";
            }
            else
            {
                cout << "*" << " ";
            }
        }

        cout << "\n";
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 2 * row; j++)
        {

            if (j > i and j < 2 * row - i - 1)
            {
                cout << " " << " ";
            }
            else
            {
                cout << "*" << " ";
            }
        }

        cout << "\n";
    }

    cout << "\n";

    // or we can have done in with two for loops in row then three inner for loop

    for (int i = row; i > 0; i--)
    { // row selection matters as start prints depends on row //if i start from row then that much start print relation needed
        for (int j = 0; j < i; j++)
        {

            cout << "*" << " ";
        }
        for (int j = 0; j < 2 * row - 2 * i; j++)
        {
            cout << " " << " ";
        }
        for (int j = 0; j < i; j++)
        {

            cout << "*" << " ";
        }

        cout << "\n";
    }

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*" << " ";
        }
        for (int j = 1; j <= 2 * row - 2 * i; j++)
        {
            cout << " " << " ";
        }
        for (int j = 1; j <= i; j++)
        {

            cout << "*" << " ";
        }

        cout << "\n";
    }

    cout << "\n";
    cout << "\n";

    // double triangle butterfly
    // *             *
    // * *         * *
    // * * *     * * *
    // * * * * * * * *
    // * * *     * * *
    // * *         * *
    // *             *

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*" << " ";
        }
        for (int j = 1; j <= 2 * row - 2 * i; j++)
        {
            cout << " " << " ";
        }
        for (int j = 1; j <= i; j++)
        {

            cout << "*" << " ";
        }

        cout << "\n";
    }
    for (int i = row - 1; i > 0; i--)
    { // row selection matters as start prints depends on row //if i start from row then that much start print relation needed
        for (int j = 0; j < i; j++)
        {

            cout << "*" << " ";
        }
        for (int j = 0; j < 2 * row - 2 * i; j++)
        {
            cout << " " << " ";
        }
        for (int j = 0; j < i; j++)
        {

            cout << "*" << " ";
        }

        cout << "\n";
    }

    // rombus
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < (2 * row - i); j++)

        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }

        cout << "\n";
    }

    cout << "\n";
    cout << "\n";

    // try better way
    //    *
    //   * *
    //  * * *
    // * * * *

    // with proper space analysis , we can do this.
    //    *
    //   * *
    //  * * *
    // * * * *
    // * * * *
    //  * * *
    //   * *
    //    *
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= row - i; j++)

        {
            cout << " "; // single time space
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "* "; // here two times one for character and other for term
        }

        cout << "\n";
    }
    for (int i = row; i > 0; i--)
    {
        for (int j = 1; j <= row - i; j++)

        {
            cout << " "; // single time space
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "* "; // here two times
        }

        cout << "\n";
    }

    return 0;
}