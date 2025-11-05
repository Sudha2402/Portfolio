#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <algorithm>

// file stream

// we want same file to have read write and save in secondary memory
// if we want to read, then we need to take a file from secondary to ram then read it.
// I we want to write then create or bring a file to ram and write into the file and then save to Secondary memory

// ifstream//input file stream//read the input file in form of stream
// ofstream//output file stream to write in file as output.
// ofstream and ifstream is a class of fstream.

// ofstream and ifstream have many function defined inside,like open, hence to use this class . we need to make object of this class file then use different function.

int main()
{

    // to read in file
    ifstream fin;
    fin.open("file.txt");

    // let's read
    char c;
    fin >> c;
    cout << c << endl; // prints only one character.//move to next character as it has reado one.

    fin >> c; // get like inputs
    cout << c << endl;

    while (!fin.eof())
    {
        cout << c; // last time it is called
        fin >> c;
    };

    fin.close();
    cout << endl;

    fin.open("file.txt");
    c = fin.get(); // consider space as character
    while (!fin.eof())
    {
        cout << c; // last time it is called
        c = fin.get();
    };

// to get line from file
string line;
while (getline(fin,line))
{
   cout<<line<<endl;//takes one line at a time//here finc starts from start point.
}




fin.close();










    // // we can use combined constructor also
    // ofstream foutName("file.txt");
    // foutName.close();

    // to open file
    ofstream fout;
    fout.open("file.txt"); // if not such file then it will create by itself.

    vector<int> arr(5);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    // we can sort this data also then put it in the file
    sort(arr.begin(), arr.end());

    // we want to output this input into the file
    for (int i = 0; i < arr.size(); i++)
    {
        fout << arr[i] << " "; // we can put it into it's place
    }

    fout<<"\nHello Sudha\n";
    fout<<"Hello India\n";


    fout.close(); // it is opended in write mode

    return 0;
}