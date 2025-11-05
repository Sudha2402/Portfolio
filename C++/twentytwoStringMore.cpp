// KMP Algorithm || Longest Prefix Suffix

// string Matching Algorithm

//  Knuth-Morris-Pratt Algorithm

// Naive string matching algorithm

// KMP string matching algorithm

// Make a string Palindrome.//by adding characters only at start.

// Circular pattern matching

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int longestPreSufLength(string str)
{
    int len = str.size();

    vector<int> lps(len, 0);
    int prefix = 0, suffix = 1;

    while (suffix < len)
    {

        cout << "prefix : " << prefix << " " << "suffix : " << suffix << endl;

        cout << "str[prefix] : " << str[prefix] << " " << "str[suffix] : " << str[suffix] << endl;

        if (str[prefix] == str[suffix])
        {
            lps[suffix] = prefix + 1;
            // cout << "need to update" << endl;
            cout << "lps[suffix] : " << lps[suffix] << endl;
            prefix++;
            suffix++;
        }
        else if (prefix - 1 >= 0)
        {
            prefix = lps[prefix - 1];
        }
        else
        { // if pre == 0
            cout << "lps suffix is chaging to 0 here" << endl;
            lps[suffix] = 0;
            suffix++;
        }

        cout << "lps[suffix-1] : " << lps[suffix] << endl; // as it has just passed suffix beyond the range hence to print previous, we need decrement by 1
    }

    return lps[suffix - 1]; // as it has just passed suffix beyond the range, we need decrement by 1
}

// this is totally wrong logic as it nevers move back in case of mismatch, it will always fail in case of repeating characters.
// int stringMatchingNaive(string str, string pattern)
// {
//     int start = 0;

//     cout << str.size() - pattern.size() << endl; // 5
//     for (int i = 0; i < str.size(); i++)
//     {//this is wrong logic of shifting i also beacuse in case of repeatation string and start from inbetween , it will not move back to that place.

//         cout << i << " " << start << endl;
//         if (str[i] == pattern[start])
//         {
//             start++;
//         }
//         else
//         {
//             start = 0;

//         }

//         if (start == (pattern.size()))
//         {
//             // return 1;
//             // return i;//to return the index
//             return (i - (pattern.size() - 1)); // to return the index
//         }

//         if (i >= (str.size() - pattern.size()) && (str.size() - i - pattern.size() + start == 0))
//         {
//             return 0;
//         }
//     }
//     return 0;
// }



int stringMatchingNaive(string str, string pattern)
{
    for (int i = 0; i <= str.size() - pattern.size(); i++)
    {
        int start = 0;
        while (start < pattern.size() && str[i + start] == pattern[start]) // instead of introducting new pointer to main string for sliding, we used i + start//
        {
            start++;
        }

        if (start == pattern.size())
        {
            return i; // Return the starting index of the match
        }
    }
    return 0; // Return 0 if no match found
}

int KMPstringMatchingProblem(string str, string pattern)
{
    int strsize = str.size(), patternSize = pattern.size();

    int first = 0, second = 0; // for main string

    vector<int> arr(patternSize, 0);
    // let's fill this arr array first as per longest prefix and suffix.
    int prefix = 0;
    int suffix = 1;

    while (suffix < patternSize)
    {
        // we can even fill it as we iterate.//but it may create iteration problem as first first matches then it will have wrong pattern fill

        // aabcaabd
        if (pattern[prefix] == pattern[suffix])
        {
            arr[suffix] = prefix + 1;
            prefix++;
            suffix++;
        }
        else
        {
            if (prefix - 1 >= 0)
            {
                prefix = arr[prefix - 1];
            }
            else
            { // when prefix==0
                arr[suffix] = 0;
                suffix++;
            }
        }
    }

    for (int i = 0; i < patternSize; i++)
    {
        cout << arr[i] << " "; // 0 0 0 1 2 0
    }
    cout << endl;

    while (second < patternSize)
    {
        cout << "first " << first << " Second " << second << endl;
        if (str[first] == pattern[second])
        {
            first++;
            second++;
        }
        else
        {
            if (second - 1 >= 0)
            {
                second = arr[second - 1];
                cout << "Second is updated: " << second << endl;
            }
            else
            {
                first++;
            }
        }

        if (second == patternSize)
        {
            cout << "first " << first << " Second " << second << endl;
            return first - second;
        }
    }

    return -1;
}

// or more simplified. We can have matched the whole pattern for for one index until it breaks the pattern

// find the character needed to make a string palindrome by adding it in first.
// one approch is in O(n^2). Here we need to put a pointer from end of the given string then chack from first to last if given string is palindrome , if not then add the end chracter in the front. then move end to onr point left then again check if string is palindrome or not. // keep checking unitil we find the palindrome and keep adding char at the start.

// Another way is to use KMP to solve in O(n).Here we need to reverse the string then add $ in orignial string, then add reverse string to look like ssds$sdss , then find LPS.//last LPS value is subtracted from given string length , and we get the answer of how many string to be includes to make it palindrome.

// this method is even useful in finding the longest palindrome characters possible as substring

int palidromeCharToadd(string str)
{

    string strMain = str; // aaaotcaakr
    cout << str << endl;
    // reverse the string.
    reverse(str.begin(), str.end()); // rkaactoaaa
    cout << str << endl;
    string KMPString = strMain + '$' + str; // aaaotcaakr$rkaactoaaa
    cout << KMPString << endl;
    vector<int> LPS(KMPString.size(), 0);

    // now find LPS on KMPString
    int first = 0, second = 1;
    while (second < KMPString.size())
    {
        if (KMPString[first] == KMPString[second])
        {
            LPS[second] = first + 1;
            second++;
            first++;
        }
        else
        {
            if (first - 1 >= 0)
            {
                first = LPS[first - 1];
            }
            else
            {
                LPS[second] = 0;
                second++;
            }
        }
    }

    int lengthOfcharToadd = strMain.size() - LPS[KMPString.size() - 1];
    // character to be added //we can aslo started from index 3 to 0 and reverse it.
    string finalStr = "";
    for (int i = strMain.size() - 1; i >= LPS[KMPString.size() - 1]; i--)
    {
        cout << strMain[i] << " "; // r k a a c t o
        finalStr += strMain[i];
    }
    cout << endl;

    // final palindrome
    for (int i = 0; i < strMain.size(); i++)
    {
        finalStr += strMain[i];
    }

    cout << finalStr << endl; // rkaactoaaaotcaakr

    return strMain.size() - LPS[KMPString.size() - 1]; // 7//characters need to add at the start.//to print the chare , we can simply print last 7 characters
}

// Circular pattern matching
int CircularRotaedstringMatchingProblem(string str, string pattern)
{

    // we have to find if pattern can be in string with rotation

    // we just need to change the give string to it's duble for solving rottion question.
    str = str + str;

    int strsize = str.size(), patternSize = pattern.size();

    int first = 0, second = 0; // for main string

    vector<int> arr(patternSize, 0);
    // let's fill this arr array first as per longest prefix and suffix.
    int prefix = 0;
    int suffix = 1;

    while (suffix < patternSize)
    {
        // we can even fill it as we iterate.//but it may create iteration problem as first first matches then it will have wrong pattern fill

        // aabcaabd
        if (pattern[prefix] == pattern[suffix])
        {
            arr[suffix] = prefix + 1;
            prefix++;
            suffix++;
        }
        else
        {
            if (prefix - 1 >= 0)
            {
                prefix = arr[prefix - 1];
            }
            else
            { // when prefix==0
                arr[suffix] = 0;
                suffix++;
            }
        }
    }

    for (int i = 0; i < patternSize; i++)
    {
        cout << arr[i] << " "; // 0 0 0 1 2 0
    }
    cout << endl;

    while (second < patternSize)
    {
        cout << "first " << first << " Second " << second << endl;
        if (str[first] == pattern[second])
        {
            first++;
            second++;
        }
        else
        {
            if (second - 1 >= 0)
            {
                second = arr[second - 1];
                cout << "Second is updated: " << second << endl;
            }
            else
            {
                first++;
            }
        }

        if (second == patternSize)
        {
            cout << "first " << first << " Second " << second << endl;
            return first - second;
        }
    }

    return -1;
}




// repeated string match.

// we have to repeat the str upto the match length or greater, then one more time match then finally, one more time reat and conclude your answer of string matching.

int repeatedStrMatch(string str, string pattern)
{

    // base case of string matching:
    if (str == pattern)
    {
        // return 0;//means matched and index is 0.
        return 1; //
    }

    int a = str.size(), b = pattern.size();
    string strCheck = str;
    int repeat = 1;

    vector<int> LPS(b, 0);

    for (int i = a; i < b; i = i + a)
    {
        strCheck += str;
        repeat += 1;
    }

    cout << strCheck << endl; // abcdabcd
    cout << repeat << endl;   // abcdabcd

    // now we can form LPS on pattern
    int prefix = 0, suffix = 1;

    while (suffix < b)
    {

        if (pattern[prefix] == pattern[suffix])
        {
            LPS[suffix] = prefix + 1;
            prefix++;
            suffix++;
        }
        else
        {
            if (prefix - 1 >= 0)
            {
                prefix = LPS[prefix - 1];
            }
            else
            {
                LPS[suffix] = 0;
                suffix++;
            }
        }
    }

    for (int i = 0; i < b; i++)
    {
        cout << LPS[i] << " ";
    }
    cout << endl;
    // 0 0 0 0 1 2 3 4

    int first = 0, second = 0;
    int inc = 1;
    for (int i = 0; i < strCheck.size(); i++)
    {

        cout << first << " " << second << endl;

        if (strCheck[first] == pattern[second])
        {
            first++; // at it's own position
            second++;
        }
        else
        {
            if (second == 0)
            {
                first++;
            }
            else
            {
                second = LPS[second - 1];
            }
        }

        if (second + 1 == b)
        {
            // return second-first;
            cout << "in this cond" << endl;
            cout << second << " " << b << endl;
            return repeat;
        }

        if (second > 0 && second < b && inc && i == strCheck.size() - 1)
        {
            cout << "Inside final increment" << endl;
            strCheck += str;
            repeat += 1;
            inc = 0;
        }
        else if (i == strCheck.size() - 1)
        {
            return -1;
        }
    }

    return -1;
}





int main()
{

    string s1 = "Sudha";
    string s2 = "Sudha";
    if (s1 == s2)
    {
        cout << "equal" << endl;
    }
    else
    {
        cout << "not equal" << endl;
    }

    // KMP Algorithm || Longest Prefix Suffix
    // For solving this I can think of using two pinters one at start then other at end, keep traversing. Front traverse is stored in string with pushback and end traverse strignstoresd at first index, if any such lenghtn is found that 0 index of  these string matches then strat comparing

    // we can store this string such that length of given string size of vector string, then size of 1 string stored at 0 index, then compare, if equal.

    //
    // suffix strart from second position because equal length to the given string match not allowed , in that case it will alway be the whole length string as it matches to itself always.

    // now we are using KMP
    cout << longestPreSufLength("ABCABDABCABDABDAB") << endl;


    
    cout << stringMatchingNaive("abacdabad", "abad") << endl;

    cout << KMPstringMatchingProblem("onionionson", "onions") << endl;

    cout << KMPstringMatchingProblem("aaaaab", "aaab") << endl;
    cout << palidromeCharToadd("aaaotcaakr") << endl;

    cout << "Index from which it start matching: " << CircularRotaedstringMatchingProblem("cdeabroab", "abcde") << endl;
    cout << "Pepeat : " << repeatedStrMatch("abcd", "cdabcdab") << endl;

    return 0;
}