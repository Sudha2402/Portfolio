#include <iostream>
using namespace std;
#include <cmath> //swap

int winner(int num)
{
    if (num % 4)
    {
        return 0; // loose when i am initator and winning number has 4 as factor.//we have to move 3 stpes , we try to catch the remaining number factor of 4.but opponent has power.
    }
    else
    {
        return 1; // win
    }
}

int Min(int a, int b)
{ // min is build in function in c++
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}




// using directly by diagonal movements.

int bishopMove(int row, int col)
{
    int count = 0, leftdiagonal = 0, rightdiagonal = 0;
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (i + j == row + col)
            {
                rightdiagonal++;
            }
            else if (j - i == col - row)
            {
                leftdiagonal++;
            }
            else
            {
                continue; // not needed
            }
        }
    }

    count = leftdiagonal + rightdiagonal;
    return count - 1; // need to remove current position
}

// or using four seperate digonal line
// left to//left bottom//right top//right bottom
int bishopMoveCount(int row, int col)
{
    int count = 0, lefttopdiagonal = 0, leftbottomdiagonal = 0, righttopdiagonal = 0, rightbottomdiagonal = 0, j = col, i = row, lastPositionRow, lastPositionCol;

    while (j != 8 && i != 8)
    {
        i++;
        lastPositionRow = i;
        j++;
        lastPositionCol = j;
    }

    // rightbottomdiagonal = lastPositionRow - row;//or
    rightbottomdiagonal = lastPositionCol - col;

    count += rightbottomdiagonal;

    // similarly check for righttop
    j = col;
    i = row;
    while (j != 8 && i != 1)
    {
        i--;
        lastPositionRow = i;
        j++;
        lastPositionCol = j;
    }

    righttopdiagonal = row - lastPositionRow;

    count += righttopdiagonal;

    // similarly check for leftbottom
    j = col;
    i = row;
    while (j != 1 && i != 8)
    {
        i++;
        lastPositionRow = i;
        j--;
        lastPositionCol = j;
    }

    leftbottomdiagonal = lastPositionRow - row;

    count += leftbottomdiagonal;

    // lefttop
    j = col;
    i = row;

    while (j != 1 && i != 1)
    {
        i--;
        lastPositionRow = i;
        j--;
        lastPositionCol = j;
    }

    lefttopdiagonal = row - lastPositionRow;

    count += lefttopdiagonal;

    return count;
}

// or method 3 just by finding the min difference between the limit value
// bishops moves only diagonally
int bishopMoveCountMin(int row, int col)
{
    int count = 0;

    // right bottom limit last possible j != 8 && i != 8
    count += min(8 - row, 8 - col); // min is build in function in c++// hence we need not to write it.

    // righttop// j != 8 && i != 1
    count += min(row - 1, 8 - col);

    // leftbottom//j != 1 && i != 8
    count += min(8 - row, col - 1);

    // lefttop //j != 1 && i != 1
    count += min(row - 1, col - 1);

    return count;
}

int isRectangle(int a, int b, int c, int d)
{
    if (a == b && c == d || a == c && b == d || a == d && b == c)
    {

        return 1;
    }
    else
    {
        return 0;
    }
}

void Swap(float &a, float &b)
{ // same name function can exist but parameter must be different //pass by reference , value and location both remains same//only a points to that location and a also holds it's value, print a will give value

    int temp = a;
    a = b;
    b = temp;
}

double fact(int num)
{
    double val = 1;
    while (num)
    {
        // if(val>INT16_MAX){
        //     return 0;//if factorial overflow//Factorial is : 9.33262e+157//shows answer when overflows
        // }
        val *= num;
        num--;
    }
    return val;
}

// for finding trailing zero without finding factorial.
// we can find the total number of 5 in all number factor

int trailingZeroes(int n)
{
    // Write Your Code here
    int count = 0;
    while (n / 5 > 0)
    {
        count += n / 5;
        n = n / 5;
    }

    return count;
}

int trailZero(int num)
{
    int rem, count = 0;
    while (num)
    {
        rem = num % 10;
        if (rem == 0)
        {
            count++;
        }
        else
        {
            return count;
        }
        num = num / 10;
    }

    return count;
}

int TrailZero(int fact)
{
    int count = 0;

    while (fact >= 5)
    {
        fact = fact / 5;
        count += fact;
    }

    return count;
}

// An Armstrong number, also known as a narcissistic number or pluperfect digital invariant, is a number that is equal to the sum of its own digits each raised to the power of the number of digits. For example, 153 is an Armstrong number because 153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153.

int isArmstrong(int num)
{ // we could have seperated count digit function and  count would have been passed inside this function as parameter.

    float ininum = num, rem, sum = 0, count = 0, val; // handles float defined pow function accurately

    while (num)
    { // count number of digits for power.
        rem = num % 10;
        count++;
        num = num / 10;
    }

    num = ininum;

    // cout << count << endl; // ok

    while (num)
    {
        rem = num % 10;

        // val = 1;
        // int countPower = count;
        // while (countPower)
        // {
        //     countPower--;
        //     val *= rem; // for power we canhave used inbuild function
        // }

        // val using inbult function
        val = pow(rem, count); // correct//pow function//pow(5,3)//124 due to float impricision , hence pass float in the function for accuracy
        // Floating-Point Imprecision:

        // pow() operates on floating-point numbers (double), not integers.

        // Internally, it might calculate 5^3 as something like 124.999999... due to rounding errors.

        // When stored in an int, this gets truncated to 124.

        sum = sum + val;

        // cout << num << " " << rem << " " << val << " " << sum << endl;

        num = num / 10;
    }

    if (sum == ininum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char capitalize(char &val)
{

    // val = val - 32;//we don't check this 32 then we can use that char directly//both works
    val = val - ('a' - 'A');

    return val;
}

int main()
{

    int a = 3, b = 6;
    swap(a, b); // inbuild function

    float c = 3.9, d = 6.9;
    Swap(c, d); // 

    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
    // swap(2,4);//error//value must be passed stored at some location//it will reswap
    swap(c, d); // value must be passed stored at some location//it will reswap

    // convert 'a' to 'A'
    cout << 'a' - 'A' << " " << endl; // 32
    char val = 'd';
    cout << capitalize(val) << endl;
    cout << val << endl; // 32

    // Armstrong number
    int num;
    cout << "Enter the number to check armstrong : ";
    cin >> num;
    cout << isArmstrong(num) << endl;
    cout << pow(5, 3) << endl; // 125

    // find trailing zero in factorial:
    cout << "Factorial is : " << fact(5) << endl;   // 120
    cout << "Factorial is : " << fact(100) << endl; // 120
    int trailfact = fact(5);
    cout << trailZero(trailfact) << endl;


    // cout<<trailZero(fact(100))<<endl;
    cout << trailZero(fact(10)) << endl;
    cout << trailZero(fact(25)) << endl; // overflow


    cout << TrailZero(100) << endl; // 24//no overflow as we are not checking by dividing.

    // to check wheather we can make rectangle or not out of four sides given
    int side1, side2, side3, side4;
    cout << "Enter the sides of rectanlge:";
    cin >> side1 >> side2 >> side3 >> side4;

    cout << isRectangle(side1, side2, side3, side4) << endl;

    //  Bishop problem
    // horse can move anywhere diagonally from it's position only.
    // A standard chessboard has 8 rows and 8 columns, resulting in a total of 64 squares.

    int row, col;
    cout << "Enter the row and column position of bishop:";
    cin >> row >> col;

    cout << bishopMove(row, col) << endl;

    cout << bishopMoveCount(row, col) << endl;
    cout << bishopMoveCountMin(row, col) << endl;

    cout << "Enter the winning number";
    cin >> num;
    winner(num);

    return 0;
}
