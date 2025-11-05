#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// two pointer will always work when we have only two results, input required.//every operation based on involving two elements in array will work

// start ke badane se sum icrease ho raha tha aur end ke ghatne se sum decrease ho r aha tha.. opposite behavior//start=0, end=size-1//ek baar me ek hi cheez change karenge.

//  we noticed that after increasing start, answer decease, hence on decreasing end we want answer to be increasing. We find the opposite behavior hence it works.

// ​ek bar me hum start ki position fix karenge aur sirf end ko change karke behavior analyse karenge.

// firs agli bar end ko fix karke , hum sirf start ko change karke behavior check kar3enge , if behavior is same then wrong position of start and end but if different behavior then that approch work.

// jab same behavior h toh , isliye humne dono ko change karna chaha aur start ko bhi ek bar me increase karenge aur end ko bhi ek bar me 1 increase karenge. Same hum dono ko end par laga kar bhi kar sakte h. start=size-1 and end=size . fir dono ko increase karenge.

// jab ek bar end ko increase kar diya h ek case ke liye jab k<target ho toh , next time jab issi ke andar case banega jab k>target ho toh , end ka pahla behavior increase ka tha toh vo increase hi rahega... , es approch ke liye dono ko increase karna padega

// two pointer remove the chance of input check by eleminating many inputs.

vector<int> mulCheck(vector<int> arr, int target)
{
    // we need to sort it first:
    sort(arr.begin(), arr.end());
    vector<int> mul;

    int start, end;

    int size = arr.size();
    start = 0;
    end = size - 1;

    while (start < end) // not even equal other wise it will be like square
    {

        if (arr[start] == 0)
        {
            if (target == 0)
            {
                // Handle 0 * x = 0 case (if needed)
                mul.push_back(0);
                mul.push_back(arr[end]); // Or any other logic
                return mul;
            }
            else
            {
                start++;  //  Skip further checks for this iteration
                continue; // this is necessay if you care about handling the division by zero case//do't go for fusther downlard as start is changes , we better recheck.
            }
        }

        // Use multiplication to avoid division issues
        long long product = (long long)arr[start] * arr[end];

        // if (arr[end] == target / arr[start])
        if (product == target)
        {

            mul.push_back(arr[start]);
            mul.push_back(arr[end]);

            start++; // Move both pointers to find all pairs (remove if only one pair is needed)
            end--;
        }
        else if (product < target)
        {

            start++; //// Need a larger product
        }
        else
        {
            end--; //// Need a smaller product
        }
    }

    return mul; // Empty if no pair found
}




int main()
{

    // int arr[] = {1, 1, 0, 1, 0, 1, 0, 1, 1};
    int arr[] = {1, 0, 0, 1, 0, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int start = 0;
    int end = size - 1;

    // it is not better approch// as it causees unwanted check
    
    // while (start < end)
    // {
    //     if (arr[start] == 1 && arr[end] == 0)
    //     {
    //         swap(arr[start], arr[end]);
    //         start++;
    //         end--;
    //     }

    //     // After swapping, the code rechecks the same positions in the while loops

    //     // Example: After swapping start and end, it will redundantly check arr[start] == 0 and arr[end] == 1 again

    //     while (arr[start] == 0)
    //     {
    //         start++;
    //     }
    //     while (arr[end] == 1)
    //     {
    //         end--;
    //     }
    // }

    // or using conditions //it is better as it has less while loop and less swapping, not need of explicitly skipping the correct position.

    while (start < end)
    { // ek baar me ek ko hi aage badhana h , dono ko sath nahi.
        if (arr[start] == 0)
        {
            start++;
        }
        else
        {
            if (arr[end] == 0)
            {
                swap(arr[start], arr[end]);
                start++;
                end--;
            }
            else
            {
                end--;
            }
        }
    } // time complexity O(n)







    // to find sum of any two elements in sorted array is equal to target.
    int sumCheck[] = {2, 7, 11, 15, 27};
    // int target = 22;
    int target = 42;
    int first = 0, second = 0;
    size = sizeof(sumCheck) / sizeof(sumCheck[0]);
    start = 0;
    end = size - 1;
    // cout<<end;

    while (start < end)
    {

        if (sumCheck[start] + sumCheck[end] == target)
        {
            first = sumCheck[start];
            second = sumCheck[end];
            break;
        }
        else if (sumCheck[start] + sumCheck[end] > target)
        {
            // that end can never give the correct result
            end--;
        }
        else
        {
            start++;
        }
    }

    if (first != -1 && second != -1)
    {
        cout << first << "+" << second << "=" << target << endl;
    }



    //diff check
    vector<int> diffCheck = {5, 10, 3, 2, 50, 80};

    target = 45;
    first = -1, second = -1;

    size = diffCheck.size();
    start = 0;
    end = start + 1;//note
    // cout<<end;

    // we need to sort it first:
    sort(diffCheck.begin(), diffCheck.end());

    // we also need to check that if target is < 0 then make it possitive as will not affect//array can be negative also//we just need to sort.
    if (target < 0)
    {
        target = target * -1;
    }

    // while (start <= end && end<size)

    while (end < size)
    {
        if (diffCheck[end] - diffCheck[start] == target)
        {
            first = diffCheck[start];
            second = diffCheck[end];
            break;
        }
        else if (diffCheck[end] - diffCheck[start] < target)
        {
            // that end can never give the correct result
            end++;
        }
        else
        {
            start++;
        }
        // as we are increasing both start and end , hence there is chaces that start==end and we don't have to terminate here hence increment end++
        if (start == end)
        {
            end++; // no error of equal and terminate inbetween
        }
    }

    if (first != -1 && second != -1)
    {
        cout << second << "-" << first << "=" << target << endl;
    }



    vector<int> mulCheckArray = {3, 7, 8, 11, 23};
    target = 56;
    vector<int> ans = mulCheck(mulCheckArray, target);

    if (!ans.empty())
    {
        cout << ans[0] << " * " << ans[1] << " = " << target << endl;
    }
    else
    {
        cout << "No pair found." << endl;
    }

    return 0;
}