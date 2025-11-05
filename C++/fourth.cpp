#include <iostream>
#include <string>


using namespace std;

char hexval(int value)
{
    switch (value)
    {
    case 10:
        return 'A';
        break;
    case 11:
        return 'B';
        break;
    case 12:
        return 'C';
        break;
    case 13:
        return 'D';
        break;
    case 14:
        return 'E';
        break;
    case 15:
        return 'F';
        break;
    default:
        return '0'+value; //it must be converted to char using // Prepend the character. //'value'//it do not perform concatetaion , char just replace the old and takes one one character.
    }
}

int main()
{

    // bitwise operator
    int ans;
    ans = 2 & 3;
    cout << ans << endl;
    ans = 2 | 3;
    cout << ans << endl;
    ans = 2 ^ 3;
    cout << ans << endl;
    ans = 17 << 4; // 17*2^4
    cout << ans << endl;
    ans = 18 >> 3; // right shift by 3 places//18/2^3
    cout << ans << endl;
    ans = ~18; // complement//-19
    cout << ans << endl;
    ans = ~-18; // complement//17
    cout << ans << endl;

    ans = 5 ^ 10 * 5 - 3 >> 7 * 4 > 8 != 5 == 7;
    cout << ans << endl; // 5//first solve * > - > >> > > == > != > ^

    cout << ++ans << endl; // 6
    cout << ans << endl;   // 6
    cout << ans++ << endl; // 6//it will change in next line
    cout << ans << endl;   // 7

    // Note pre and post increment effect is not seen in seperate line, only when cout is present then we can differentiate
    // a++
    // ++a;
    // any code below this will get the updated value.

    // sum of n natural number using do while loop

    int sum = 0;
    int i = 0;
    do
    {
        sum += i;
        i++;
    } while (i < 11);
    cout << sum << endl;

    // decimal to binary conversion
    int num;
    cout << "Enter the number to be converted in binary : ";
    cin >> num;

    int rem, bin = 0, unit = 1;

    while (num)
    {

        rem = num % 2;
        bin += rem * unit;
        unit *= 10;

        num /= 2;
    }

    cout << bin << endl;

    // binary to decimal
    cout << "Enter the number in binary to convert to decimal : ";
    cin >> num;
    int dec = 0, power = 1;

    while (num > 0)
    {

        rem = num % 10;
        dec += rem * power;
        power *= 2;

        num /= 10;
        //    cout << dec << endl;
    }

    cout << dec << endl;

    // binary to octal
    // binary -> dec -> oct with div 8
    cout << "Enter the number in binary to convert into octal : ";
    cin >> num;
    dec = 0, power = 1;

    while (num > 0)
    {

        rem = num % 10;
        dec += rem * power;
        power *= 2;

        num /= 10;
        //    cout << dec << endl;
    }

    // cout << dec << endl;//decimal

    int oct = 0;
    unit = 1;

    while (dec)
    {

        rem = dec % 8;
        oct += rem * unit;
        unit *= 10;

        dec /= 8;
    }

    cout << oct << endl;






    // dec to hexadecimal
    int dec;
    cout << "Enter the number to be converted in hexadecimal : ";
    cin >> dec;

    string hex="";
    int unit = 1;

    while (dec)
    {
        int rem = dec % 16;
        // hex += rem * unit;
        // rem = hexval(rem);
        // hex = to_string(rem)+hex;
        hex = hexval(rem) + hex;  // Prepend the character
        dec /= 16;
    }

    cout << hex << endl;

    return 0;
}