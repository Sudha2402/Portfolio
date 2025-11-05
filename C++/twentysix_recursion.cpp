// Recursion
// alwat=ys try to make base case that you know, from bigger to larger.
// In recusrion just solve for one case , it will automatically solve for others

// number print
// even number
// factorial
// sum of n natural num
// poer of number
// sum of square of number
// find 8th index value in fabonacii series
// Nth Stair problem//we have to give the total number of ways in answer. to ho on nth satair with either 1step or two step at a time.
// print array elemnt
// find array sum
// fin min and max element using recurssion

// Recursion on string
// find palidrome
// count vowels
// reverse the string
// Capitalize

#include <iostream>
using namespace std;

int repeatWish(int days)
{
    if (days == 0) // base case is where we haave to stop.
    {
        cout << " happy birthday." << endl;
        return 0;
    }
    // while (days - 1 >= 0)
    // {
    cout << days << " left for your birthday\n";
    // return repeatWish(days - 1);//works
    repeatWish(days - 1); // error as never stops in case of return below it.

    // }
}

// to print number from 1 to N using recursion
void PrintNum(int num)
{
    // base case must be before recursion
    if (num == 1)
    {
        cout << num << endl;
        return;
    }

    PrintNum(num - 1);   // to handle my smaller numbers first.
    cout << num << endl; // print me later but handle my lower cases hence it will come back then this will remain in stacka nd get executed.
}

// if not want to rearrange the order of function and output then use toal number also.

// to print number from 1 to N using recursion
void PrintNum2(int num, int N)
{
    // base case must be before recursion
    if (num == N)
    {
        cout << num << endl;
        return;
    }

    cout << num << endl; // print me later but handle my lower cases hence it will come back then this will remain in stacka nd get executed.

    PrintNum2(num + 1, N); // to handle my smaller numbers first.
}

// print even number
void PrintEven(int num)
{
    if (num == 1)
    {
        return;
    }
    if (num % 2 == 0)
    {
        cout << num << " ";
    }

    PrintEven(num - 1); // 10 8 6 4 2 //print in reverse
}

void PrintEven2(int num)
{
    // to let it print in order
    if (num == 1)
    {
        return;
    }

    PrintEven2(num - 1);
    if (num % 2 == 0)
    {
        cout << num << " ";
    }
}

void PrintEven3(int num)
{
    // to let it print in order
    if (num == 2)
    {
        cout << num << " ";
        return;
    }

    PrintEven3(num - 2); // 2 4 6 8 10 12 //we mkae sure that it receives only even number
    cout << num << " ";
}

// factorial
int factorial(int num)
{
    if (num == 1)
    {
        return 1; // return is used to send it back to intial stack instruction and output it is sending is stored in reteun and it will be multiplied then.
    }
    return num * factorial(num - 1); // return is used to move back it's int result in back data //3628800 //it's output is needed in above statements hence return setted.
}

// 5 +  SumOfN(4)
// 4 +  SumOfN(3)
// 3 +  SumOfN(2) //recives SumOfN(2) value from below using return...
// 2 +  SumOfN(1) /receives 1 from SumOfN(1) then return 3 to above
// SumOfN(1)=1//it returns the value calualted

int SumOfN(int N)
{
    if (N == 1)
    {
        return 1;
    }
    return N + SumOfN(N - 1);
}

// Power of 2
int powerOf2(int P)
{
    if (P == 1)
    {
        return 2;
    }

    return 2 * powerOf2(P - 1);
}

// Sum of square of number
int sumOfSquare(int N)
{
    if (N == 1)
    {
        return 1;
    }

    return N * N + sumOfSquare(N - 1);
}

int powerOf2N(int N, int P)
{
    // if (P == 1)
    // {
    //     return 2; // 2^1=2 and we know that is base case
    // }
    // not needed as we have one more lower chack range

    if (P == 0)
    {
        return 1;
    }

    return N * powerOf2N(N, P - 1); //
}

// find 8th index value in fabonacii series
int fabonacci(int N)
{
    // we need to satr from 0 to this N
    if (N = 0)
    {
        return 0;
    }
    if (N = 1)
    {
        return 1;
    }

    return fabonacci(N - 1) + fabonacci(N - 2);
}

// let's debug for 4
// fabonacci(3)+fabonacci(2)
//( fabonacci(2) +fabonacci(1) ) + ( fabonacci(1) + fabonacci(0) )
//(  fabonacci(1) + fabonacci(0) +1 ) + ( 1 + 0 )
//(   1 + 0  +1 ) + ( 1 + 0 )
// 3 //this is exactly at index 4
// fabonacci(3)+fabonacci(2)

// Nth Stair//we have to give the total number of ways in answer.

// No logic for this
// int NthStair(int N){
//     if(N==1){
//         return 1;
//     }
//     if(N==2){
//         return 2;//two ways ..1 1 or 2
//     }

//     if(N%2==1){
//         //last stars has only one way
//         return  NthStair(N-1);
//     }
//     else{
//         // even way
//          return  2+ NthStair(N-1);
//     }
// }

int NthStair(int N)
{
    //     if (N == 1)
    //     {
    //         return 1;
    //     }
    //     if (N == 2)
    //     {
    //         return 2; // two ways ..1 1 or 2
    //     }

    // combined can be written as
    if (N <= 1)
    {
        return 1;
    }

    return NthStair(N - 1) + NthStair(N - 2); // by oberving the pattern
}

// try to solve using for loop i n main()

int GCD(int a, int b)
{

    // int temp;
    // while (b != 0)
    // {
    //     temp=a;
    //     a = b;
    //     b = temp % b;
    // }
    // return a;

    //
    //
    // using recursion
    //
    if (b <= 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

// Print Array
void PrintArray(int arr[], int size)
{

    if (size == 0)
    {
        return;
    }

    PrintArray(arr, size - 1);
    cout << arr[size - 1] << " ";
}

// Summ of all elements in array
int arrSum(int arr[], int size)
// we could have used arrSum(int arr[],int index, int size) //here index is passed 0 then keep increasing index+1 then base case comes to N size
{

    if (size == 0)
    {
        return 0;
    }
    return arr[size - 1] + arrSum(arr, size - 1);
}

// find minimum element in array
int minElement(int arr[], int minVal, int index)
{ // index here we are starting from size.
    if (index == 0)
    {
        // return minVal;
        return arr[index];
    }

    // instead of using this condition we can use invbult function min
    // if (minVal > arr[index - 1])
    // {
    //     minVal = arr[index - 1];
    // }
    return min(arr[index - 1], minElement(arr, minVal, index - 1)); // this also works
}

int maxElement(int arr[], int max, int index)
{ // index here we are starting from size.
    if (index == 0)
    {
        return max;
    }

    if (max < arr[index - 1])
    {
        max = arr[index - 1];
    }
    return maxElement(arr, max, index - 1);
}

bool palidrome(string str, int index, int size)
{
    // malayalam //8

    // keep compressing
    if (size <= index)
    {
        return 1;
    }

    if (str[index] == str[size - 1])
    {
        return palidrome(str, index + 1, size - 1);
    }
    else
    {
        return 0;
    }
}

int countVowels(string str, int index, int size)
{
    if (index == size)
    {
        return 0;
    }

    if (str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u')
    {
        return 1 + countVowels(str, index + 1, size);
    }
    else
    {
        return 0 + countVowels(str, index + 1, size);
    }
}

// reverse a string
void reverse(string &str, int index, int size)
{
    // swap the string
    if (index >= size)
    {
        return;
    }

    char temp = str[index];
    str[index] = str[size - 1];
    str[size - 1] = temp;

    reverse(str, index + 1, size - 1);
}

// lowercase to uppercase

// Upper character has ascii from 65 onwards
// lower character has ascii from 98 onwards

void capitalize(string &str, int size)
{
    if (size == -1)
    {
        return;
    }

    if (str[size] >= 97)
    {
        // lower case
        str[size] = str[size] - 32;
    }

    // we can have directly used with this
    // str[index]='A'+ str[index-'a' //capitalize R. if alredy capital then may create problem

    // str[size]= str[size] + 26
    capitalize(str, size - 1);

    
}

int main()
{

    repeatWish(5);
    cout << endl;
    PrintNum(7);
    cout << endl;
    PrintNum2(1, 5);
    cout << endl;

    PrintEven(10);
    cout << endl;
    PrintEven2(10);
    cout << endl;

    // we could have easily done using recursive decrement
    int num3 = 13;
    if (num3 % 2 == 1)
    {
        num3 = num3 - 1;
    }
    PrintEven3(num3);
    cout << endl;

    // factorial using recursion.
    // cout<<factorial(10)<<endl;

    // if negetive number is passed then handle it using if no negative number fact,

    cout << factorial(4) << endl; // 24

    // Sum of natiral number
    cout << SumOfN(6) << endl; // 21

    // power of 2
    cout << powerOf2(5) << endl; // 32

    // if(power is 0 then return 1)
    cout << powerOf2N(2, 5) << endl; // 32
                                     // it can also be used for 4, 7 ... as we have used num

    // Sum of square of N numbers
    cout << sumOfSquare(5) << endl;

    cout << NthStair(8) << endl;

    // // try to solve using for loop
    int nstart1 = 1;
    int nstart2 = 2;
    int ways;
    int steps;
    cout << "Enter the steps: ";
    cin >> steps;

    if (steps == 1)
    {
        ways = 1;
    }
    else if (steps == 2)
    {
        ways = 2;
    }
    else
    {

        int a = 1, b = 2;
        for (int i = 3; i <= steps; i++)
        {
            ways = a + b;
            a = b;
            b = ways;
        }
    }

    cout << "Ways : " << ways << endl; // 34 for 8 steps  //be clear with all approaches.

    // Greatest Common dividor
    // GCD
    cout << "GCD : " << GCD(48, 18) << endl;

    // PrintArray(int arr[], int size)
    int arr[] = {1, 4, 5, 2};
    // cout << "PrintArray : " << PrintArray(arr, 4) << endl;

    PrintArray(arr, 4);
    cout << endl;

    cout << arrSum(arr, 4) << endl;
    cout << minElement(arr, INT32_MAX, 4) << endl;
    cout << maxElement(arr, INT32_MIN, 4) << endl;
    // cout << palidrome("naman", 0, 5) << endl;//1
    cout << palidrome("malayalam", 0, 9) << endl; // 1
    cout << palidrome("sudha", 0, 5) << endl;     // 0

    cout << countVowels("sudha", 0, 5) << endl; // 2

    string rev = "Sudha";
    cout << rev << endl;
    reverse(rev, 0, 5);

    cout << rev << endl;

    cout << 'a' + 1 << endl;         // 98
    cout << 'a' - 'A' << endl;       // 32
    cout << 'r' - 'a' + 'A' << endl; // R

    capitalize(rev, 5);

    cout << rev << endl; // AHDUS

    return 0;
}