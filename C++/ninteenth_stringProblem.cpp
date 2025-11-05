#include <iostream>
using namespace std;

// Defanging an IP address
// clockwise//right rotation
// anticlock wise// left rotation
// Pangram
// sort a string using count sort

void rightRotate(string &str1)
{

    int end = str1.size(), start = end - 2;
    int last = str1[end - 1];
    while (start >= 0)
    {
        str1[start + 1] = str1[start];
        start--;
    }
    str1[0] = last;
}

void leftRotate(string &str1)
{

    int end = str1.size(), start = 1;
    int first = str1[0];
    while (start < end)
    {
        str1[start - 1] = str1[start];
        start++;
    }
    str1[end - 1] = first;
}

int main()
{

    // whenever . comes in the string of IP adress then replace it with [.]
    // substitute will not work as its length is more than 1 byte to store at place, hence new string defined and concatenated them as per condition

    string IPaddress = "1.23.1.2";
    int start, end;
    string ans;//not needed to do it like =""
    start = 0, end = IPaddress.size();
    while (start < end)
    {
        if (IPaddress[start] != '.')
        { //"." //creates error as one index value is considered as char

            ans += IPaddress[start];
        }
        else
        {
            ans += "[.]";
        }
        start++;
    }

    cout << ans << endl; // 1[.]23[.]1[.]2

    // time complexity O(n)

    // Space complexity O(n) as answer a new variable size string is made.

    string rotateCheck = "amazon";
    string rotated = "azonam";
    start = 0, end = rotateCheck.size();
    while (start < end)
    {
        if (rotateCheck[start] != rotated[(start - 2 + end) % end]) // left rotate //|| rotateCheck[start] != rotated[(start + 2) % end] //for right rotate
        {
            cout << "not rotated 2 places left";
            break;
        }
        start++;

        if (start == end - 1)
        {
            cout << " Rotated" << endl;
        }
    }

    // as question says
    // two string are given and check if string2 can be getted by rotating string1 in any direction by 2 places

    // as here it mentioned two then we need modulus, but if we rotate one at a time then modulus not needed just store first or last then update//

    string str1 = "amazon";
    string str2 = "azonam";

    if (str1.size() == str2.size())
    {
        start = 0, end = str1.size();

        // string strCheck = str1; // must stoe before updating , but better to pass a copy

        string clockwise = str1;
        // rightRotate(str1);
        // rightRotate(str1);
        rightRotate(clockwise);
        rightRotate(clockwise);

        if (clockwise == str2)
        {
            cout << "rotated 2 places right" << endl;
        }
        else
        {
            cout << "not rotated 2 places right" << endl;
        }

        string anticlockwise = str1;
        leftRotate(anticlockwise);
        leftRotate(anticlockwise);

        if (anticlockwise == str2)
        {
            cout << "rotated 2 places left" << endl;
        }
        else
        {
            cout << "not rotated 2 places left" << endl;
        }
    }
    else
    {
        cout << "not relation between string" << endl;
    }

    // extracting index from char
    // cout<<'a'/1 - 97<<endl;//0//97//return the ascii value of char
    // cout<<'t'/1 -97 <<endl;//19

    // or we can use index= char - 'a';//index of a is 0

    // Check Pangram;
    string sentence = "the quick brown fox jumps over the lazy dog";
    end = sentence.size();
    // int arrAlpha[26] = {0};
    bool arrAlpha[26] = {0};

    int index;
    for (int i = 0; i < end; i++)
    {
        index = sentence[i] - 'a';
        arrAlpha[index] += 1;//instead we can have just used bool, because we don't need other than 1 and 0
    }

    for (int i = 0; i < 26; i++)
    {

        cout << arrAlpha[i] << " ";
        if (arrAlpha[i] == 0)
        {
            cout << "it is not Pangram" << endl;
            break;
        }

        if (i == 25)
        {
            cout << "\n it is Pangram" << endl;
        }
    }

    // time complexity : O(n+26)

    // sort a string
    // insertion sort we found good but it has O(n2), hence we will use count sort

    string unsortedString = "sudha";
    end = unsortedString.size();
    int countsort[26] = {0};

    for (int i = 0; i < end; i++)
    {
        index = unsortedString[i] - 'a';
        countsort[index] += 1;
    }

    // char c;
    cout << "Sorted String: ";
    for (int i = 0; i < 26; i++)
    {

        while (countsort[i] != 0)
        {

            // cout <<  char(i+97);
            // or use

            char c = i + 'a';//works
            // c = i + 'a';//also work
            // cout << c;

            countsort[i]--;
        }
    }


    // we can also change ito O(n) by using two value storage at one place then using the power of modulus and divide.

    // counting search is good for string not int


    return 0;
}