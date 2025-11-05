#include <iostream>
using namespace std;

// all string function and theory
// reverse string
// find size of string
// to check wheather a string is palindrome or not

int main()
{

    // to get space or tab as as cin then we need getline function.//cin terminates only in case of enter

    string s3;
    getline(cin, s3);   // cin is in the bracket//Sudha Kumari
    cout << s3 << endl; // Sudha Kumari//don't break at space

    cout << s3.size() << endl; // it don't show size of null//only char ans space size is consuderd.

    char arr[] = {'a', 'p', 'p', 'l', 'e'};
    for (int i = 0; i < sizeof(arr); i++)
    {
        cout << arr[i];
    }
    cout << endl;
    cout << arr << endl; // apple//it print some extra also sometimes

    // for variable size
    char arr2[10]; // only 9 character to be entered because 1 space reserved for \0

    // cin>>arr2;//sudha
    // arr2[3]='\0';//sud
    // cout<<arr2;//print whatever entered
    // cout<<endl;

    // for (int i = 0; i < sizeof(arr2); i++)
    // {
    //     cout << arr2[i];//print some extra.
    // }
    // cout<<endl;

    string s = "Sudha Kumari";
    cout << s << endl; // consider space as character, hence S give only Sudha Kumari

    // string s2;
    // cin >> s2; // when space prensent then it do not read further. //Sudha Kumari
    // cout << s2 << endl; // Sudha

    // Note if a space is entered in above cin the input will take just after that space string as input and tkae it next string and not ask for cin later.

    // append in string
    string appendstring = s + s3;
    appendstring = s + "hello"; // allowed
    // appendstring = s + 'hello';//not allowed due to char with multiple characters allowed
    appendstring = s + 'h';       // allowed
    cout << appendstring << endl; // Sudha Kumarihello sudha

    // append function
    appendstring = s.append(s3); // Sudha Kumarihello sudha
    cout << appendstring << endl;

    // pushback in string to add one character only

    // s.push_back("I am good");//worng as gaps
    // s.push_back(s2);//error
    //  s.push_back("good");//error as more than one char
    //  s.push_back("g");//error string not char

    s.push_back('g'); // works

    // popback in string
    s.pop_back(); // no parameter is passed//only last index is popped

    // Escape character
    string mess = "Sudha is a \"good\" coder"; // backslack ignore the usual meaning of character just after it and it do not print itself
    cout << mess << endl;                      // Sudha is a "good" coder
    // string errpo="\"; \\error as \ consider" after it as usual hence show error

    string nullch = "\0"; // just do nothing//print blank

    //
    //
    // Reverse the string
    //

    string revcheck = "Sudha";
    int start = 0, end = revcheck.size() - 1; // for indexing
    while (start < end)
    {
        swap(revcheck[start], revcheck[end]);
        start++;
        end--;
    }
    cout << revcheck << endl; // ahduS

    // to find the length/size of string in revcheck;
    int startsize = 0;
    while (revcheck[startsize] != '\0')
    {
        startsize++;
    }
    cout << startsize << endl; // 5

    // to check wheather a string is palindrome or not
    string palidro;
    // getline(cin,palidro);//even helpful to get paragraph

    cin >> palidro;
    start = 0;
    end = palidro.size() - 1;
    while (start < end)
    {
        if (palidro[start] == palidro[end])
        {
            start++;
            end--;
        }
        else
        {
            cout << "not palidrome" << endl;
            return 0; // considering it as last so that it not return that it is palidreom
            break;
        }
    }

    cout << "palidrome" << endl;
}