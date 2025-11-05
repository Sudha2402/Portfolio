#include <iostream>

// #include <utility> // For std::pair

// std::tuple (for 3+ values)

using namespace std;

#include <vector>

#include <cmath>

// from the array we need to find the kth missing natural number on the array. here circled like 1, 5, 6,8,9 are missing and user asked for 5 th missing hence 5th missing is 9.
// arr={2,3,4,7,11,12}

// For a sorted array, the number of missing elements before arr[i] is arr[i] - (i + 1).

// Example: At i=3 (arr[3]=7), missing elements before it are 7 - (3 + 1) = 3 ([1,5,6]). //it is for natural number //it simply like jo number h usse apne value se ek kam index par hona chahiye tha agar numbering 1 to n tak h array, par agar uska index kuchh aur h toh

int N_missing(int arr[], int size, int k)
{
    int min = 0, max = size - 1, mid, missed = 0, missing,ans=size - 1;//if no missing then at the end, it will add in the last.

    while (max >= min) // as when min>max means that min index will point to the position where the k-th missing number should be inserted
    {

        mid = min + (max - min) / 2;

        // cout<<arr[mid]<<endl;
        // cout<<(mid + 1)<<endl;
        missing = (arr[mid]) - (mid + 1); // 7 - 4 = 3//value -position count not index as we are taking natural number

        // cout<<min <<" "<<mid<<" "<<max<<" "<<missing<<endl;

        if (missing < k)
        {
            min = mid + 1;
        }
        else
        {//(missing >= k
            ans=mid;//incase we don't get any greater than this index.//well not needed if we are handling on the bases of min not mid.
            max = mid - 1;
        }
    }

    // return min + k; // good approch
    return ans + k; // good approch

    // explaination
    //  min will point to the position where the k-th missing number should be inserted

    // The k-th missing number is exactly min + k because:

    // At index min, there are min numbers before it (indices 0 to min-1)

    // The value at min (if it existed) would be min + 1 (since arrays are 0-indexed)

    // The k-th missing number is min + k because:

    // The sequence up to index min-1 has arr[min-1] - min missing numbers before it

    // We need k missing numbers total, so we add the remaining (k - missing) to arr[min-1]

    // This simplifies mathematically to min + k

    // it has thought in broader way thinking, that min is the value and next k needed from this min position when min>max.//the corrent position can be the palce of that number in form of missed number.but this min has left some other missed hence it will add those missed as increment, to the the kth value.//min index lete hi , k extra add karna padega uskme , kth missing ki value m=nikalne ke liye.

    if (k >= missing)
    {
        return arr[mid] + (k - missing);
    }
    else
    {
        return arr[mid - 1] + (missing - k);
    }

    
}

// check the occurance of a number using binary.
// {2,4,4,4,4,4,5,6}//here occurance of num=4 is 5 times hence return 5
// we can solve it by checking the first occurance then last occurance, and count = last-first +1. as index were returned

// search or find square root of a number using binary search
int sqroot(int num)
{

    if (num < 2)
        return num; // it helps to prevent /0 error //when max=1 or num=1 then also it will give mid as zero hence it will cause error in division by mid or divide by 0.//hence after num =3, all mid will be 1 + . hence before 2, we should return the same num.
    // root of 0 and 1 is same as the number

    int min = 1;
    // max = pow(num,0.5); // we can have set num poer two but that would also have taken a for loop to increment power of 2//power also takes for loop order of n , instead , we let num/2 as max
    int max = num / 2;
    int mid;
    int result = 0;

    while (min <= max)
    {
        // if (min == max)
        // {
        //     if ((mid) * (mid) > num)
        //     {
        //         mid = mid - 1;
        //         break;
        //     }
        // }
        // mid * mid can overflow for large num (e.g., num = 2147395599, where mid = 46340 and mid * mid = 2147395600 overflows a 32-bit int).

        // This leads to undefined behavior (e.g., returning wrong results or crashing).

        // or

        mid = min + (max - min) / 2;
        // cout<<mid<<endl;

        //  long long square = static_cast<long long>(mid) * mid; // Prevent overflow//we have stored mid*mid in the square to prevent overflow

        //  or we can just shift the variable part such that it do not overflow
        // like mid*mid==num can be written as mid== num/mid now it will be easy to store.

        if (mid == num / mid)
        { // here it will cause one more error as if mid==0 then it can't divide
            return mid;
        }
        else if (mid == num / mid)
        {
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
            result = mid; // Keep track of the largest mid where mid^2 <= num //only smaller can be the result not larger.
        }
    }

    // return mid;//overflow in case of min = mid + 1; and as it will cross that max>min, but it has alredy incread it's power hence fails.
    // use result in the min possible and equal for result storation//just like we stored max for inserting an element in sorted array.

    return result;
}

// We have to find the position of a target it is present in sorted and if not present then what will be the index of it to fit in sorted array.//it is easy with linear search but binary search wiil be good in sorted array.

int findPosition(int arr[], int size, int val)
{
    int min = 0, max = size - 1, mid, index = size; // index at the last will be max value
    while (max >= min)
    { // equal just to get the position where inseertion could have been possible but we can hanle it outside the loop as we need no more mid calculation

        //    if min and max are adjacent then not found will be at max index is non matches.//when finally min and max becomes the same index then that index will be position where val should have present

        // or we can have done this also that if any elemnt at mid grater than val the store it's index thinking that it could be it's position //if any other value grater than target is found again then store in in index as updating the neaerest possible.

        mid = min + (max - min) / 2;

        if (arr[mid] == val)
        {
            index = mid;
            // return index;//it will be automatically in other of while loop as return we have mention =ed hence not needed.
            break;
        }
        else if (arr[mid] > val)
        {
            max = mid - 1;
            index = mid; // we store index of max only
        }
        else
        {
            min = mid + 1;
        }
    }

    return index;
}

vector<int> Search(int arr[], int size, int target, int &first, int &last)
{
    vector<int> results;
    first = -1, last = -1;

    // Example logic: Find all occurrences of `target`
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            results.push_back(i); // Store indices where target appears
            if (first == -1)
                first = i; // First occurrence
            last = i;      // Last occurrence
        }
    }
    return results;
}

int search(int arr[], int size, int target, int &first, int &last)
{ // linear search once from forward the from backward. hence maximum front can move to n and backward can move to n , hence O(n)

    int min = 0, max = size - 1, mid;
    first = -1, last = -1;
    // as binary is more efficient search hence we will use binary search.

    while (min <= max)
    {
        mid = min + (max - min) / 2;
        if (target == arr[mid])
        {

            first = mid;
            last = mid;
            // now we will check the very left and right elements

            cout << first << " " << last << endl;

            int prev = mid - 1, next = mid + 1;
            // while (arr[mid] == arr[prev])
            while (arr[mid] == arr[prev] && prev >= min)
            {
                first = prev;
                prev = prev - 1;

                cout << first << " " << last << endl;
            }
            while (arr[mid] == arr[next] && next <= max)
            {
                last = next;
                next = next + 1;

                cout << first << " " << last << endl;
            }

            // int arr[] = {first, last};
            // return arr;//address of local variable 'arr' returned
            // return first, last;//showing only one result

            // one best way to pass more than two values , we can do using vector, it works just like an array

            // vector<int> a(2); // 2 elements (0-initialized)
            // vector<int> a = {first, last};

            // Vectors use zero-based indexing:

            // a[0] = first;
            // a[1] = last;

            // return a; // for this change the function return type as vector<int>

            return 1; // return necessary otherwise it willl never leave if in while loop .
        }
        else if (target > arr[mid])
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }

    return -1;
}

int printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    // int arr[] = {5, 7, 7, 8, 8, 10}; // increasing but not strictly increasing order.
    int arr[] = {5, 7, 8, 8, 8, 10}; // increasing but not strictly increasing order.

    printArray(arr, 6);

    int target, first = -1, last = -1;
    cout << "Enter the target element to search first and last position : ";
    cin >> target;

    cout << search(arr, 6, target, first, last) << endl; // first and last occurance of target element
    cout << first << " " << last << endl;

    vector<int> indices = Search(arr, 5, target, first, last);

    // Print the returned vector
    cout << "Indices where target appears: ";
    for (int index : indices)
    {
        cout << index << " ";
    }
    cout << endl;

    // Print first and last occurrences
    cout << "First occurrence: " << first << endl;
    cout << "Last occurrence: " << last << endl
         << endl;

    int arrStrict[] = {5, 7, 8, 9, 19, 30}; // increasing but not strictly increasing order.

    printArray(arrStrict, 6);
    cout << "Enter the target element to search it's possible index : ";
    cin >> target;
    cout << findPosition(arrStrict, 6, target) << endl;

    int num;
    cout << "Enter the num for sqrt: ";
    cin >> num;

    cout << sqroot(num) << endl;

    int missingNA[] = {2, 3, 4, 7, 11, 12};
    printArray(missingNA, 6);
    cout << "Enter which number missing element value you want to know : ";
    cin >> target;
    cout << N_missing(missingNA, 6, target) << endl;

    return 0;
}