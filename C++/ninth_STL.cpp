#include <iostream>
using namespace std;

#include <vector>
#include <algorithm> //for sort inbuild method also

int main()
{
    // declaring vector
    vector<int> v1;
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(0);
    v1.push_back(3);
    v1.push_back(8);

    cout << v1.size() << endl;     // 5
    cout << v1.capacity() << endl; // 8

    // ato update  vect stsrt val array
    //  vector[index];
    v1[2] = 7;

    vector<int> v2 = {2, 4, 3, 5, 6};
    cout << v2.size() << endl;     // 5
    cout << v2.capacity() << endl; // 5

    vector<int> v3(5, 3);
    //

    int size, ini;
    cout << "Enter the size of vector: ";
    cin >> size;
    cout << "Enter the initalized value of vector: ";
    cin >> ini;
    vector<int> v4(size, ini);

    // we can take vaLUE from user too
    for (int i = 0; i < v4.size(); i++)
    {
        cout << "Enter the values of vector: ";
        cin >> v4[i];
    }

    // to print vector
    for (auto i = v2.begin(); i < v2.end(); i++)
    {
        cout << *i << " "; // 2 4 3 5 6
    }
    cout << endl;

    // to pop value from vector
    // cout<< v2.rbegin() << endl;
    v2.pop_back();             // pop from end
    cout << v2.size() << endl; // 4

    v2.erase(v2.begin() + 2);
    cout << v2.size() << endl; // 3

    v4.clear();
    cout << v4.size() << endl; // 0

    // iterating just like array.
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " "; // 2 4 5
    }
    cout << endl;

    // to insert an element in between vector not the last.
    cout << v2.front() << endl; // 2//first element value
    cout << v2.back() << endl;  // 5 //last element value
    cout << v2.empty() << endl; // 0 //last element value
    cout << v2.at(2) << endl;   // 5 /eleemnt at index 2

    // to insert a value at some index
    //  v2.insert(v2.begin()+index,val);
    v2.insert(v2.begin() + 1, 9); // 2 9 4 5

    v3 = v2; // all v2 values will be coppied to v3 vector

    for (auto i : v3)
    {
        cout << i << " "; // 2 9 4 5//as all values are copied.//it is capable of printing elements of vector.//just like i stores one elemet at a time like disctionary.then print it's value
    }
    cout << endl;

    // sort in increasing order
    sort(v2.begin(), v2.end()); // 2 4 5 9 //must #include <algorithm> for sorting

    sort(v2.begin(), v2.end(), greater<int>()); // in decreasing order sorting.//9 5 4 2

    sort(v2.rbegin(), v2.rend()); // 9 5 4 2//sort in descending order.

    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;

    // error//Reverse iterators (rbegin(), rend()) are special iterator objects that can't be directly printed like values. They're designed for traversal, not direct output.
    // cout << v2.rbegin() << endl; // only used in loop to print reverse
    // cout << v2.rend() << endl;

    cout << *v2.rbegin() << endl; // Prints last element
    // cout << *v2.rend() << endl;  // ERROR: rend() points before first element

    // for (auto i = v2.rbegin(); i != v2.rend(); i--)//// ❌ Wrong direction// // not acceptable
    for (auto i = v2.rbegin(); i != v2.rend(); i++) // acceptable
    {

        cout << *i << " "; // 2 4 3 5 6
    }
    cout << endl;

    // using size parameter we can use reverse direction
    for (size_t i = v2.size(); i-- > 0;) // ✅ Safe alternative
    {
        cout << v2[i] << " ";
    }
    cout << endl;

    sort(v2.begin(), v2.end()); // need to sort before binary search

    // cout<<binary_search(v2.begin(),v2.end(),val);
    cout << binary_search(v2.begin(), v2.end(), 12) << endl; // 0 // not present
    cout << binary_search(v2.begin(), v2.end(), 9) << endl;  // 1 // present

    // to find the index of an element
    // cout<<find(v2.begin(),v2.end(),9)<<endl;//find() returns an iterator//find() returns an iterator, not an index or a directly printable value.//find() returns an iterator (vector<int>::iterator), not an integer.//cout doesn't have a built-in overload to print iterators directly.

    cout << find(v2.begin(), v2.end(), 9) - v2.begin() << endl; // 3 //this index concept also used in array to get index of elemets //iterator of an elemet - iterator of index 0.

    // cout << *find(v2.begin(), v2.end(), 9) << endl; // 9//as this pointer points this index hence * shows it's value// to get index, we need to subtract first index iterator

    // Iterator arithmetic is valid for random-access iterators (like those from vector).

    // Subtracting two iterators gives the distance between them (as an integer).

    // v2.begin() is the starting point, so this calculates the index.

    // count the number of elements with given value
    cout << count(v2.begin(), v2.end(), 9) << endl; // 1

    // to find the max element in the vector

    // cout << max_element(v2.begin(), v2.end()) << endl; //error

    // trying to directly print the iterator returned by max_element() without dereferencing it//as it returns pointer//hence erro

    //     max_element() returns an iterator, not the actual value

    // cout cannot directly print iterators (same issue as with find())

    // You need to dereference the iterator to get the value

    cout << *max_element(v2.begin(), v2.end()) << endl; // ✅ Correct

    //  work on sorted ranges (like vectors) to find insertion points for elements

    // lower bound
    // cout<<lower_bound(v2.begin(), v2.end(), value);

    // What it does: Returns an iterator pointing to the first element ≥ value
    // Behavior:
    // If value exists: Points to its first occurrence
    // If value doesn't exist: Points to first element greater than value
    // If all elements are smaller: Returns v.end()

    cout << lower_bound(v2.begin(), v2.end(), 3) - v2.begin(); // 1

    // upper bound
    cout << upper_bound(v2.begin(), v2.end(), 3) - v2.begin();//11

    // What it does: Returns an iterator pointing to the first element > value
    // Behavior:
    // If value exists: Points to first element after its last occurrence
    // If value doesn't exist: Same as lower_bound
    // If all elements are smaller: Returns v.end()


    // in sorting bound means between which number in sorted array, lower bound means number  first element ≥ value.
    // Upper bound (first element > value)

    





    return 0;
}