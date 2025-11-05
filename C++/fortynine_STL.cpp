#include <iostream>
#include <bits/stdc++.h> // for using stl libraries

using namespace std;

// defining person datatype for set
class Person
{
public:
    int age;
    string name;

    // making these set to sort on the bases of age.

    bool operator<(const Person &other) const
    {
        // return age > other.age; // returns true or false //set age in descending order. at start age greater than first will be in front.

        return age < other.age; // ascending order of age // age is first and others are compared with it. age is the new to be putted.
    }
};

int main()
{

    // The s.erase() and s.find() methods are used with various Standard Template Library (STL) containers, including set, multiset, string, vector, and list. They are general-purpose methods for searching (find) and deleting (erase) elements within a container

    list<int> l1; // list is like double ended linkedlist.

    // Insertion/Deletion at a Specific Position: (O(N))
    // Accessing Elements (by index or value): \(O(N)\)

    l1.push_back(12);
    l1.push_back(15);
    l1.push_front(5);

    cout << "l1.front : " << l1.front() << " l1.back() : " << l1.back() << endl;

    for (auto it = l1.begin(); it != l1.end(); it++)
    {
        // cout << *it << " "; // 5 12 15
        cout << *it << " "; // 5 12 15
    }

    cout << endl;

    l1.pop_back();
    l1.pop_front();

    l1.push_back(123);
    l1.push_back(13);
    l1.push_front(3);

    // printing in reverse
    for (auto it = l1.rbegin(); it != l1.rend(); it++)
    {
        cout << *it << " "; // 13 123 12 3  // rend is in left side -1 index and in right side rbegin starts. it ++ is used because it itself decides from r that it has to increment in left side hence -- is not given.
    }

    cout << endl;

    // SET
    // sorted on one attribute like age etc hence operator is used for defining it.

    // set of int
    set<int> s1 = {40, 60, 2, 5, 8};
    // find returns the iterator for that number
    if (s1.find(110) != s1.end())
    {
        cout << "Element 110 found." << endl;
    }
    else
    {
        cout << "Element 110 not found." << endl;
    }

    s1.erase(2);           // erase by value
    s1.erase(s1.find(30)); // Erase by iterator
    for (int val : s1)
    {
        cout << val << " ";
    }

    cout << endl;

    // set of any user defined data type.
    set<Person> s;
    // let's defined some person
    Person P1, P2, P3;
    P1.age = 10, P1.name = "Sudha";
    P2.age = 1, P2.name = "Sana";
    P3.age = 25, P3.name = "Shanaya";

    s.insert(P1);
    s.insert(P2);
    s.insert(P3);

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << (*it).age << " " << it->name << endl;
    }

    // to remove all elements from the set

    // MULTI SET
    // set of int
    multiset<int> ms = {40, 60, 2, 40, 5, 8};

    for (int val : ms)
    {
        cout << val << " ";
    }

    cout << endl;

    // UNORDERED SET
    // unique element, search, insert and delete have average constant
    unordered_set<int> us = {40, 60, 2, 40, 5, 8};

    for (int val : us)
    {                       // for (auto it = s.begin(); it != s.end(); it++) also used in all. both works the same
        cout << val << " "; // any order not even in same order pushed.
    }

    cout << endl;

    // MAP

    // key value pairs

    // it stores data in key value pair
    // it uses Red-black tree or AVL for implementation.
    // Insertion, deletion, and search operation have logarithmic time O(logn) making them fast for most use cases.

    map<int, int> m;
    m.insert(make_pair(20, 30));
    m.insert(make_pair(30, 20));
    m[15] = 12;
    m[20] = 35; // updated
    m.insert(make_pair(40, 10));

    // it should be present in sorted form on output.

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    if (m.count(20))
    {
        cout << m[20] << " "; // 30
    }

    // cout<<m[200]<<endl;//0

    // multimap

    // dublicate key allowed
    multimap<int, int> mm;
    mm.insert(make_pair(20, 30));
    mm.insert(make_pair(20, 40));
    // mm[100] = 12;//insertion this way not allowed.
    // mm[20] = 35; // update cause error

    // unordered map

    // unique, not sorted, hashing, search insert and delete in constant time execution

    unordered_map<int, int> um;
    um.insert(make_pair(20, 30));
    um.insert(make_pair(30, 20));
    um[15] = 12;
    um[20] = 35; // updated
    um.insert(make_pair(40, 10));

    for (auto it = um.begin(); it != um.end(); it++)
    { //in any order not even in the same way mentioned or created
        cout << it->first << " " << it->second << endl;
    }
}
