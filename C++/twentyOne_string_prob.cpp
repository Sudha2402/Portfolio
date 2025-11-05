#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Roman to integer
// integer to roman
// factorial of a number
// longest subset without repeating character.
// sliding window protocol //solves in O(N) or O(2N)
// Smallest Distinct Window.

//
//
//
//
//  Smallest Distinct Window.
// We have to find the the smallest window of substring possible that holds all the distinct present in the string//for such we will use sliding window with expansion and reduction

int smalllestDistWin(string str)
{

    int n = str.size();
    if (n == 0)
        return 0; // to handle when nothing in string

    int first = 0, second = 0;

    int difference = 0; // store how many characters are still need to sreach when differece greater than 0. if equal to 0 than it means all distinct coved then it will check for reduction of window.then expansion again.

    int smallest = str.size();

    vector<int> count(256, 0); // it can be more than just 0 and 1

    for (int i = 0; i < str.size(); i++)
    {
        if (count[str[i]] == 0)
        {
            count[str[i]] = 1; // now we need to update later again to 0
            difference += 1;
        }
    }

    cout << "different Characters : " << difference << endl; // Ok

    for (int i = 0; i < str.size(); i++)
    {
        count[str[i]] = 0;
    }

    while (second < str.size())
    {

        // if (difference > 0) //no need as untill differ > 0 , we keep it track in fitst diff loop
        // {
        // expand

        // what ever is coming in str, increase it's count

        if (count[str[second]] == 0)
        {

            difference -= 1;
        }
        count[str[second]] += 1;

        // }//even if not needed, but it not created any problem.

        // else //only this if, else was creating error or problem.//and it is sensleass, Why I have added, this else part will never run when it enters.
        // {

        while (difference == 0)
        {

            smallest = min(second - first + 1, smallest);

            count[str[first]] -= 1; // it will become 0 hence diifence increase

            if (count[str[first]] == 0)
            {
                difference += 1;
            }

            first++;
        }
        // }

        second++; // check for next. ..if we have positioned second++ before while deff==0 then we need only second-first in min calulation , +1 would have not been neded.
    }

    return smallest;
}

//
//
//
//
//
// optimal approach to find the longest subset without repeating character.//but it reachecs to last substring possible by removing the last dublicate

// sliding window protocol to find the length of longest substring with no repetation

// Note: Why is it O(n) and not O(n²)?
// The while loop does not run for every second; it only runs when a duplicate is encountered.
// Total operations:
// second moves right → n steps.
// first moves right → at most n steps (total across all iterations).
// Thus, total steps = 2n → O(n).

int longSubstrLength(string str)
{

    int longest = 0;

    vector<bool> arr(256, 0); // for all ascii//0 to 255 indexing

    // time complexity for finding the longest substring length O(n^2)//for printing the substring, we needed one for loop.

    int first = 0, second = 0;

    for (second = 0; second < str.size(); second++)
    {
        cout << second << " " << first << endl;
        while (arr[str[second]])
        {
            arr[str[first]] = 0;
            first++; // increment first till the repeated not removed
        }

        arr[str[second]] = 1;

        // starts when second has moved to index 1.

        longest = max(longest, second - first + 1);
        // if (longest < (second + 1 - first))
        // {
        //     longest = second + 1 - first;
        // }
    }

    return longest;
}

vector<char> longSubstr(string str)
{
    vector<char> substr;
    int longest = 0;
    bool setstr = 0;

    // bool arr[26] = {0};
    vector<bool> arr(26, 0);

    // time complexity for finding the longest substring length O(n^2)//for printing the substring, we needed one for loop.

    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        // cout << "i =" << i << "\n";

        for (int j = i; j < str.size() && arr[str[j] - 'a'] == 0; j++)
        {

            // cout << "j =" << j << " ";

            count++; // count total number of substring with no contrants

            if (longest < (j - i + 1))
            {
                longest = (j - i + 1);
                cout << "longest substring length: " << longest << endl;
                substr.clear();
                setstr = 1;
            }

            for (int k = i; k <= j; k++)
            {
                // to print the substring
                arr[str[k] - 'a'] = 1;
                cout << str[k] << " "; // it is capable of print all the substring

                // substr[k] = str[k]; // update string//wrong way to update as that index is not created neccessarily

                if (setstr)
                {
                    substr.push_back(str[k]); // update string
                }
            }

            // arr[26] = {0}; // again initialize to 1;//it affects only 26 th index

            // arr.clear();//clear removes index also, hence just update

            cout << endl;
            setstr = 0; // set is 0 so that next time storing substring stores it
        }

        for (int i = 0; i < arr.size(); i++)
        {
            // cout<<arr[i]<<" ";
            arr[i] = 0;
        }
    }

    cout << "Total substring : " << count << endl;
    cout << "longest substring length : " << longest << endl;

    return substr;
}

vector<int> factorial(int factNum)
{

    vector<int> fact(1, 1); // 1 is base case//and this reuslt will be string but for now just focus on int
    int temp;
    int carry = 0;

    while (factNum > 1)
    {

        // 05
        //  49
        for (int i = 0; i < fact.size(); i++)
        {
            temp = (fact[i]) * factNum + carry; // each i stores only sing bit and rest goes into carry // when next digit multiplied then, again it substitue at one place and rest goes to carry
                                                //  fact.push_back(factNum[i]);
                                                //  now as number can be 1000 also , hence //it has to be stored like 0001 in arr of numb.

            fact[i] = temp % 10; // ones digits //05

            carry = temp / 10; // 24
        }

        while (carry)
        {

            fact.push_back(carry % 10);
            carry = carry / 10;
        }

        factNum--;
    }

    reverse(fact.begin(), fact.end());

    return fact;
}

int romonNumber(char chr)
{
    if (chr == 'I')
    {
        return 1;
    }
    else if (chr == 'V')
    {
        return 5;
    }
    else if (chr == 'X')
    {
        return 10;
    }
    else if (chr == 'L')
    {
        return 50;
    }
    else if (chr == 'C')
    {
        return 100;
    }
    else if (chr == 'D')
    {
        return 500;
    }
    else if (chr == 'M')
    {
        return 1000;
    }
    else
    {
        return 0; // not valid
    }
}

int romantoInt(string str)
{
    int size = str.size();
    int sum = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (romonNumber(str[i]) < romonNumber(str[i + 1]))
        {
            // treat this as negative number
            sum -= romonNumber(str[i]);
        }
        else
        {
            // just add as positive number
            sum += romonNumber(str[i]);
        }
    }
    // we also need to add the last character
    sum += romonNumber(str[size - 1]);

    return sum;
}

// integer to roman//hard to take vector param hence passes in main. we can use after learning public class

string IntToroman(int num)
{
    string roman;

    return roman;
}

int main()
{

    // Roman to integer
    // string roman = "XXXIVDXLIII"; //no works as , this will works only for less than 4000 numbers//for this we need to check the greater number after the current position as whole//we can traverse from back also.

    //  string roman = "XXXI";//31 //this logic holds good here.
    string roman = "MMMDXLIII"; // 3543//this logic holds good here.

    cout << romantoInt(roman) << endl;

    //
    //
    //
    //
    //
    //
    // integer to roman
    //
    //
    vector<string> thousands = {"", "M", "MM", "MMM"};
    vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> tens = {"", "X", "XX", "XXX", "XL", "LX", "LXX", "LXXX", "XC"};
    vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    int number = 3543;
    // convert it into 3000+50+40+10;
    int place = 1;
    string romanValue;

    // while (number)
    // {

    //     int rem = number % 10;
    //     int val = rem * place;
    //     romanValue += ones[val]; // then we will reverse it.//we need to define for all this way and becomes length. hence we will use direct approch

    //     place *= 10;
    //     number = number / 10;
    // }

    romanValue = thousands[number / 1000] + hundreds[(number % 1000) / 100] + tens[(number % 100) / 10] + ones[(number % 10)]; // very beautiful approch

    cout << romanValue << endl;

    //
    //
    //
    //
    //
    //
    //
    // factorial of a num
    //
    //
    int factNum;
    cout << "Enter a number to find it's factorial:"; // 50
    cin >> factNum;

    // we are preffereing to call the function
    vector<int> fact = factorial(factNum);

    for (int i = 0; i < fact.size(); i++)
    {
        cout << fact[i];
    }

    cout << endl;
    //
    //
    //
    //
    //
    // longest substring without repeating character
    //
    // vector<char> longSubstr(string str)
    // vector<char> longestSubStr = longSubstr("abbc");
    vector<char> longestSubStr = longSubstr("ababc");

    cout << "longest Substring : ";
    for (int i = 0; i < longestSubStr.size(); i++)
    {
        cout << longestSubStr[i] << " ";
    }
    cout << endl;

    int longestSubstringLength = longSubstrLength("abcabcbb");
    cout << "longest Substring length : " << longestSubstringLength << endl;

    cout << "Smallest Window size :" << smalllestDistWin("AABBBCBBAC") << endl;
    cout << "Smallest Window size :" << smalllestDistWin("aabcbcdbca") << endl;

    return 0;
}