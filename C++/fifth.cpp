#include <iostream>
using namespace std;
#include <cmath> //for using squareroot

// all basic logic is made in this

int main()
{

    // sum of digits
    int num;
    cout << "Enter the digits : ";
    cin >> num;
    int sum = 0, digit;
    while (num > 0)
    {
        digit = num % 10;
        sum = sum + digit;
        num = num / 10;
    }

    cout << "Sum is : " << sum << endl;

    // we need single digit answer hence keep adding the number until single digit is found//single digit number is 1 to 9 , it means num >9 will repeat loop

    cout << "Enter the digits : ";
    cin >> num;

    while (num > 9)
    {
        sum = 0;
        while (num > 0)
        {
            digit = num % 10;

            sum = sum + digit;
            num = num / 10;
        }

        num = sum;
    }

    cout << "Single digit Sum is : " << sum << endl; // same
    // cout << "Single digit Sum is : " << num<<endl;//same

    // leap year
    int year;
    cout << "Enter the year : ";
    cin >> year;
    if (year % 400 == 0)
    {                                            // four century years
        cout << year << " is leap year" << endl; // it is certain to be leap year
    }
    else if (year % 4 == 0 && year % 100 != 0)
    { // for non century years
        cout << year << " is leap year" << endl;
    }
    else
    {
        cout << year << " is not a leap year" << endl;
    }

    // Reverse Integer //439->934 //this logic will also work for negitive number
    int inte, rev = 0, digitRem;
    cout << "Enter the integer : ";
    cin >> inte;

    // while (inte)
    while (inte != 0)
    {
        digitRem = inte % 10;

        inte = inte / 10;
        // if (rev > INT32_MAX || rev <INT32_MIN)


        if (rev > INT32_MAX || rev < INT32_MIN)
        { // this is general test of intmin and max // // Check for overflow before performing the operation //as *10 has to be performed so overflow should be from /10 range.
            rev = 0;
            break;
        }
        
        rev = rev * 10 + digitRem; 
    }

    cout << rev << endl;

    // if a number is power of 2 then yes else no
    int intePower;
    bool isPower = 0;
    cout << "Enter the number to test power of 2 : ";
    cin >> intePower;

    for (int i = 2; i <= intePower; i = i * 2)
    {
        if (intePower == i)
        {

            isPower = 1;
            break;
        }
    }

    if (isPower)
    {
        cout << "it is power of 2 number" << endl;
    }
    else
    {
        cout << "it is not power of 2 number" << endl;
    }

    // we could hAVE ALsO HUST REVERSED AND COMPare with original

    // or method using binary

    cout << "Enter the number to test power of 2 : ";
    cin >> intePower;
    isPower = 1;

    while (intePower != 1)
    {
        // if (intePower % 2 != 0)
        if (intePower % 2 == 1) // as it has only 1 or 0 as remainder
        {
            isPower = 0;
            break;
        }
        intePower = intePower / 2;
    }

    if (isPower)
    {
        cout << "it is power of 2 number" << endl;
    }
    else
    {
        cout << "it is not power of 2 number" << endl;
    }



    // bool isPowerOfTwo(int n) {
    //     int ans = 1;
    //     if (n == 2 || n == 1) {
    //         return 1;
    //     }
    //     while (ans < n) {
    //         if(ans>INT_MAX/2 || ans<INT_MIN/2){
    //             return 0;
    //         }
    //         ans *= 2;
    //     }

    //     if (ans == n) {
    //         return 1;
    //     } else {
    //         return 0;
    //     }
    // }

    // to print square root of a number
    int number;
    cout << "Enter the number to find squareroot : ";
    cin >> number;

    int squareroot = 1;
    while (squareroot * squareroot != number && (squareroot + 1) * (squareroot + 1) <= number)
    {
        squareroot++;
    }
    cout << "squareroot : " << squareroot << endl;

    // squareroot function fro mathc
    cout << "squareroot : " << sqrt(number) << endl; // squareroot : 6.7082


// int mySqrt(int x) {
//         int ans;
//         if(x==0){
//             return 0;
//         }
//         for (int i = 1; i<= x/i; i++) {
//             ans = i;
//             if(i>INT_MAX/i+1){
//                 return i;
//             }
//         }

//         return ans;
//     }



    // palindrome in case of number //121
    // we do it num==rev then palidrome
    int inte, palidrome, rev = 0, digitRem;
    cout << "Enter the integer : ";
    cin >> inte;
    palidrome = inte;
    // while (inte)
    while (inte != 0 && inte > 0)
    {
        digitRem = inte % 10;

        inte = inte / 10;
        // if (rev > INT32_MAX || rev <INT32_MIN)

        // Runtime Integer OverFlow Error must need to be handle
        if (rev > INT16_MAX || rev < INT16_MIN)
        { // this is general test of intmin and max
            rev = 0;
            break;
        }
        rev = rev * 10 + digitRem;
    }

    // cout << rev << endl;
    if (palidrome == rev && rev != 0 && palidrome > 0)
    {
        cout << rev << " is palidrome." << endl;
    }
    else
    {
        if (rev == 0 && palidrome > 0)
        {
            cout << palidrome << "overflow integer." << endl;
        }
        else
        {
            cout << palidrome << " is not palidrome." << endl;
        }
    }
    // here more loops to handle the output otherwise we would have simple used return 0 means not palidrome

    // complement of a number
    // 121 -> binary -> bits chage -> bin to num
    // decimal to binary conversion
    int num;
    cout << "Enter the number to be find it's complement : ";
    cin >> num;

    int rem, bin = 0, unit = 1;

    while (num)
    {

        rem = num % 2;
        bin += rem * unit;
        unit *= 10;

        num /= 2;
    }

    cout << bin << endl; // 1100

    int dec = 0;
    int power = 1;

    // the very first case when bin=0 then return should be 1 as complement
    if (bin == 0)
    {
        dec = 1;
    }

    while (bin > 0)
    {

        rem = bin % 10;

        // bit change // if we try to print the bit change from binary to binary is not possible hence we change the bit and along with creating the decimal value, now if we want to check complement in binary then we can convert this decimal to binary.//complement of bits start from leftmost first significant bit 1 not from 32 bit first

        // we can replace this if else with xor

        // if (rem == 1)
        // {
        //     rem = 0;
        // }
        // else
        // {
        //     rem = 1;
        // }

        rem = rem ^ 1;

        dec += rem * power;
        power *= 2;

        bin /= 10;
        //    cout << dec << endl;
    }

    cout << dec << endl; // 12

    return 0;
}