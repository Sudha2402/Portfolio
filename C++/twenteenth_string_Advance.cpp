#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// longest palindrome
// Sorting the sentence
// sort vowel in a string
// sum of string // '23'+'549999'='77'

int main()
{

    // string checkLonPali = "aAfbfdfLPAKHdsdssad";//13
    // string checkLonPali = "aAAbbA";//5
    // string checkLonPali = "aabbcbadad";//9
    string checkLonPali = "aaaabbbacccc"; // 11

    int countlower[26] = {0};
    int countUpper[26] = {0};

    int sizeStr = checkLonPali.size();
    int paliLength = 0;
    bool oddPresent = 0;

    // cout<<'Z'-'A'<<endl;//25

    for (int i = 0; i < sizeStr; i++)
    {
        if (checkLonPali[i] - 'A' < 26)
        // we can have also used checkLonPali[i]<'a' //means upper, else lower id checkLonPali[i]>'a'
        {
            countUpper[checkLonPali[i] - 'A'] += 1;
        }
        else if (checkLonPali[i] - 'a' < 26)
        {
            countlower[checkLonPali[i] - 'a'] += 1;
        }
        else
        {
            cout << "not a valid character";
        }
    }

    for (int i = 0; i < 26; i++)
    {

        if (countlower[i] % 2 == 0)
        {
            paliLength += countlower[i];
        }
        else
        {
            oddPresent = 1;
            paliLength += countlower[i] - 1; // even times stored
        }

        if (countUpper[i] % 2 == 0)
        {
            paliLength += countUpper[i];
        }
        else
        {
            oddPresent = 1;
            paliLength += countUpper[i] - 1; // even times stored
        }
    }

    if (oddPresent)
    {
        paliLength++;
        cout << "longest Palindrome Length is : " << paliLength << endl;
    }

    cout << endl;

    //
    //
    //
    //
    //
    //
    //
    //

    // cout<<int('1')<<endl;//49
    // cout<<int('9')<<endl;//57
    // cout<<int('10')<<endl;//error//no such string is defined

    // Sorting the sentence

    string sentence = "Kumari2 Sudha1";
    vector<string> wordsstring(10); // from 0 to 9 index that will hold the position
    int sizeSen = sentence.size(), position;
    string temp;
    int countWords = 0;

    for (int i = 0; i < sizeSen; i++)
    {

        if (sentence[i] == ' ') // this is necessary to consider at last position
        {

            // cout << "\n";
            // it means just before this index, we had last word last letter which stored the position
            position = sentence[i - 1] - '0'; // to get int val of position

            // cout<<position;//2

            temp.pop_back(); // for removing the positional vlue in the string

            // cout << temp << " ";
            wordsstring[position] = temp;
            // cout<<wordsstring[2]<<"";
            temp.clear();
            countWords++;
        }
        else if (i == sizeSen - 1)
        { 
            // we need to perform function on this also
            position = sentence[i] - '0';
            //   because it is already at last hence we haven;t pused digit at the end
            // cout << temp << " ";
            wordsstring[position] = temp;
            temp.clear();
            countWords++;
        }
        else
        {
            temp.push_back(sentence[i]); //simply append
            // cout << sentence[i] << " ";
            // cout << temp << " ";
        }

        // word extraction
        // Kumari2
        // Sudha1
    }

    // cout << endl;

    // for (int i = 1; i < 10; i++)
    for (int i = 1; i <= countWords; i++)
    { // here instead of going upto 10 even when few word present hence use count words

        // cout << wordsstring[i] << " ";//Sudha Kumari//Ok but if we want that sorted string again the we need to call for loop again , hence we will store this sorted string into temp string type variable

        // temp.push_back(wordsstring[i]);//error hence we will use concatenation

        temp += wordsstring[i]; // no error
        temp += " ";            // space also after each word
    }
    // we also need to remove the last space above hence pop it.//for this if we want to store our sorted in temp string then we can do that also

    temp.pop_back();      // to remove the last space from temp
    cout << temp << endl; // gives final answer hecne one one strig print not necessary

    //
    //
    //
    //
    //
    //
    // sort vowel in a string
    //

    string vowelsort = "lEetcOde";
    string sortedVowelAns = "";

    int countlowerLet[26] = {0}; // using previously created array cause error, hecnce always give new variable name in case of array.//if you want to reuse the use vector
    // vector<int>countlower(26,0);//easily updateable

    int countUpperLet[26] = {0};

    sizeStr = vowelsort.size();

    vector<int> anspos;

    for (int i = 0; i < sizeStr; i++)
    {
        if (vowelsort[i] == 'A' || vowelsort[i] == 'E' || vowelsort[i] == 'I' || vowelsort[i] == 'O' || vowelsort[i] == 'U' || vowelsort[i] == 'a' || vowelsort[i] == 'e' || vowelsort[i] == 'i' || vowelsort[i] == 'o' || vowelsort[i] == 'u')
        {
            cout << "yesvowel : " << vowelsort[i] << endl;
            if (vowelsort[i] - 'A' < 26)
            {
                countUpperLet[vowelsort[i] - 'A'] += 1;
                cout << countUpperLet[i] << " ";
                anspos.push_back(i);

                // or

                // we can iterate this string again and at the place of vowel, replace with #, then at time of iteration when # found , replace it with this value
                // countUpperLet[i] ="#"
            }
            else
            {
                countlowerLet[vowelsort[i] - 'a'] += 1;
                anspos.push_back(i);
            }
        }
    }

    cout << anspos.size() << endl;

    for (int i = 0; i < anspos.size(); i++)
    {
        cout << anspos[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 26; i++)
    {
        while (countUpperLet[i])
        {
            sortedVowelAns += (i + 'A');
            countUpperLet[i]--;
        }
    }

    for (int i = 0; i < 26; i++)
    {

        while (countlowerLet[i])
        {

            sortedVowelAns += i + 'a';
            countlowerLet[i]--;
        }
    }

    // Note: here instead of O(26) as time complexity , it is (n) because we are getting the count value in while loop again and again and while loop will run at maximum the size of string because string count is stored hence hence Total time complexity of getting count is O(n)//hence for above two for loop time complexity O(n)

    int anslength = sortedVowelAns.size();
    cout << sortedVowelAns << endl;

    for (int i = 0; i < anslength; i++)
    {
        // anspos[i];//shows position of vowels;
        vowelsort[anspos[i]] = sortedVowelAns[i];
    }
    cout << vowelsort << endl;
    cout << endl;

    //
    //
    //
    //
    //
    //
    //
    // Add string
    //
    // such number 34354546567657543556  can't be stored even with int, long long, double etc. hecne we store in string form.

    // We have one more option big int.//used for very big number

    // factorial have overflow in case of fact of 100, as overflow.

    // sum of string // '23'+'54'='77'

    // // vector<string>strtry;
    // strtry.push_back("hello");
    // strtry.insert(strtry.begin()+0, " Sudha ");//begin index is necessary to pass //this works
    // cout<<strtry[0];
    // cout<<strtry[1];

    // use this concept

    // string str1 = "2345";
    // string str2 = "238";

    // string str1 = "9999";
    // string str2 = "999";
    // 10998

    string str1 = "999";
    string str2 = "99999";

    // Now my all test cases are pased

    // vector<string> strSumAns;//face problem in storing char at any index
    vector<char> strSumAns;

    int index1 = str1.size() - 1;
    int index2 = str2.size() - 1;
    int carry = 0;
    int calval = 0;
    //    string unit;
    char unit;

    // add string.
    while (index1 != -1 && index2 != -1)
    {

        calval = (str1[index1] - '0') + (str2[index2] - '0') + carry; // string -string gives number int when variable which is storing the value is int hence it will automatically convert string'5 to 5 if vriable is int //all operations on char is performed by converting it into ascii always. then at the time of storing as per varable datatype, it gets store as int or char. //if calval of string then this 13 ascii value would have been stored.

        // carry = 0;

        carry = calval / 10;
        unit = (calval % 10) + '0'; // 0 int value added to this value and converted to a new int and as unit is char then unit will store the char at that int// convert back to char//1+ 48 = 49 in char automatically converted to '1'

        cout << calval << " " << carry << " " << unit << " " << endl; // 13 1 3//each step shown

        strSumAns.insert(strSumAns.begin() + 0, unit);
        // cout << strSumAns[0]<<" ";

        // here insted of insertin new value at 0 index , we could have stored it normally like push_back then reverze the answer at last //reverse(ans.begin(),ans.end())

        index1--;
        index2--;
    }

    while (index1 > -1)
    {

        calval = (str1[index1] - '0') + carry;
        // carry = 0;

        carry = calval / 10;
        unit = (calval % 10) + '0';

        cout << calval << " " << carry << " " << unit << " " << endl; // 13 1 3//each step shown

        // string digit= str1[index1];//char erreo
        strSumAns.insert(strSumAns.begin() + 0, unit); // char is incseeted into string hence creates problem// we will chage strSumAns as char
        index1--;
    }
    while (index2 > -1)
    {

        calval = (str2[index2] - '0') + carry;
        // carry = 0;

        carry = calval / 10;
        unit = (calval % 10) + '0';
        strSumAns.insert(strSumAns.begin() + 0, unit);
        index2--;
    }

    if (carry)
    {
        strSumAns.insert(strSumAns.begin() + 0, carry + '0');
    }

    //   print the answer
    for (int i = 0; i < strSumAns.size(); i++)
    {
        cout << strSumAns[i] << " "; // 2583
    }

    return 0;
}