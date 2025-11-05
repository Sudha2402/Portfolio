// Trapping Rain Water
#include <iostream>
#include <vector>
#include <algorithm>

// Brute force method says to form nested for loop and check all one by one.

//  sort(arr, arr + size);  // Sort the array first//works to sort//nice

using namespace std;

int TrapRain(int arr[], int size)
{

    // vector<int> leftmax(size,0);//vector<int> leftmax(size, 0);  // Creates a vector with `size` elements (all 0)// // Adds new elements AFTER the initialized ones

    vector<int> leftmax(size);  // // No default initialization
    vector<int> rightmax(size); // // No default initialization

    // leftmax.push_back(0); // for first element max will be 0 all all wall will flow out
    int CurrentleftMax = 0;
    int CurrentRightMax = 0;
    int totalQuantityStored = 0;
    cout << "Start: " << endl;
    for (int i = 0; i < size; i++)
    {

        leftmax[i] = CurrentleftMax;

        // cout << CurrentleftMax << " " << arr[i] << " " << leftmax.at(i) << " " << endl; // CurrentleftMax and leftmax[i-1] should be same//leftmax[i] is always zero because we are not extracting inright way.

        // leftmax.push_back(CurrentleftMax);//as size is defined then , those positions need to updat either or remvoe size from declaration

        CurrentleftMax = max(arr[i], CurrentleftMax);
    }

    for (int i = 0; i < leftmax.size(); i++)
    {
        cout << leftmax[i] << " ";
    }
    cout << endl;

    for (int i = size - 1; i >= 0; i--)
    {

        rightmax[i] = CurrentRightMax;

        // cout << CurrentRightMax << " " << arr[i] << " " << rightmax.at(i) << " " << endl;

        CurrentRightMax = max(arr[i], CurrentRightMax);
    }

    for (int i = 0; i < leftmax.size(); i++)
    {
        cout << rightmax[i] << " ";
    }
    cout << endl;

    // now we can check the quantity that can be stored on the top of building.

    for (int i = 0; i < size; i++)
    {

        if (min(rightmax[i], leftmax[i]) - arr[i] > 0)
        {
            totalQuantityStored += min(rightmax[i], leftmax[i]) - arr[i];
        }
    }

    return totalQuantityStored;
}

int TrapRainSpaceOpti(int arr[], int size)
{

    int CurrentleftMax = 0;
    int CurrentRightMax = 0;
    int totalQuantityStored = 0;
    int maxElement = 0;
    int maxIndex = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
            maxIndex = i;
        }
    }

    for (int i = 0; i < maxIndex; i++)
    {

        // if (CurrentleftMax - arr[i] > 0)
        // {
        //     totalQuantityStored += CurrentleftMax - arr[i];
        // }

        // CurrentleftMax = max(CurrentleftMax, arr[i]);//we can prevent this max check when we find CurrentleftMax - arr[i]

        // Above works but one another way to prevent more arithmatic operation
        if (CurrentleftMax > arr[i])
        {
            totalQuantityStored += CurrentleftMax - arr[i];
        }
        else
        {
            // now we are sure that CurrentleftMax is not greater hence needs update
            CurrentleftMax = arr[i];
        }
    }

    for (int i = size - 1; i > maxIndex; i--)
    {
        if (CurrentRightMax - arr[i] > 0)
        {
            totalQuantityStored += CurrentRightMax - arr[i];
        }

        CurrentRightMax = max(CurrentRightMax, arr[i]);
    }

    return totalQuantityStored;
}

int TrapRainMoreOpti(int arr[], int size)
{ // using one loop, to optimize it more we will use condition
    int CurrentleftMax = 0;
    int CurrentRightMax = 0;
    int totalQuantityStored = 0;
    int maxElement = 0;
    int maxIndex = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
            maxIndex = i;
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (i <= maxIndex) // if = is notnadded then it will move to else, but we need to remvove this index hence even when we add it here then i will not cause issue.
        {
            if (CurrentleftMax > arr[i])
            {
                totalQuantityStored += CurrentleftMax - arr[i];
            }
            else
            {
                // now we are sure that CurrentleftMax is not greater hence needs update
                CurrentleftMax = arr[i];
            }
        }
        else
        {
            //  int rightIndex = size - 1 - (i - maxIndex - 1);  // Proper backward mapping//as suggested to remove  confusing "mirroring" of indices// but actually it is same.

            if (CurrentRightMax > arr[size - (i - maxIndex)]) // This creates confusing "mirroring" of indices that's hard to maintain
            {
                totalQuantityStored += CurrentRightMax - arr[size - (i - maxIndex)];
            }
            else
            {
                CurrentRightMax = arr[size - (i - maxIndex)];
            }
        }
    }

    return totalQuantityStored;
}

//  two pointer //we can try to solve it using two pointer.//start at 0 and end at size-1//then change the indexing accordingly such that it not come to max position

int trapRainWater(int arr[], int size)
{
    if (size == 0)
        return 0;

    int left = 0, right = size - 1;
    int leftMax = 0, rightMax = 0;
    int totalWater = 0;

    while (left <= right)
    {

        if (arr[left] <= arr[right])
        { // we are assuming that rightmost tower is taller or equal to first tower. //left is current position in left //right is cuurent pointer position from right side

            if (arr[left] >= leftMax)
            {                        // pura pani dagar ke nichhe aa jaiga toh kuch store nahi hoga iss building ke top par.
                leftMax = arr[left]; // Update leftMax
            }
            else
            {
                totalWater += leftMax - arr[left]; // Trap water
            }
            left++;
        }
        else
        {

            // we are assuming that rightmost tower is smaller then first tower.//jiss tarf ka chhota h vo dagrega, aur kuchh store nahi karega. //esliye uss tarf se max ki taraf jana h. //rightMax = arr[right];  // Update rightMax taki anw tok jaye.

            if (arr[right] >= rightMax)
            {
                rightMax = arr[right]; // Update rightMax
            }
            else
            {
                totalWater += rightMax - arr[right]; // Trap water
            }
            right--;
        }
    }
    return totalWater;
}

int Sum_3(int arr[], int size, int target)
{

    // first sort then run three for loop ranges i=0 to < n-2, j=i+1 to < n-1; k from j+1 to < n //it will take time complexity O(n3)

    // we will try to convert it into two pointer in two sum problems

    // we will sort before using it

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // 1 4 6 8 10 45 //sorted

    int ans, start, end;

    for (int i = 0; i < size - 2; i++)
    {
        ans = target - arr[i]; // this will be used as target for two sum problem

        start = i + 1;
        end = size - 1;

        while (start < end)
        {
            if (arr[start] + arr[end] == ans)
            {
                return 1;
            }
            else if (arr[start] + arr[end] > ans)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
    }

    return 0;
}

int Sum_4(int arr[], int size, int target)
{

    // brute force method using O(n4) complexity. //four for loop needed

    // we need to sort, then we will use two pinter approch.//for thress as ans.

    // we will sort before using it
    // 0 0 1 1 5 6

    //     we can optimize only upto 1 loop in sum problem using this approch.

    // Don't think of using four pointer that will not work. only two pinter works even in N sum

    if (size < 4)
        return false; // Need at least 4 elements

    sort(arr, arr + size); // Sort the array first//works to sort//nice

    // bubble sort is length , hence use direct command
    // for (int i = 0; i < size - 1; i++)
    // {
    //     for (int j = 1; j < size - i; j++)
    //     {
    //         if (arr[j - 1] > arr[j])
    //         {
    //             swap(arr[j - 1], arr[j]);
    //         }
    //     }
    // }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // 0 0 1 1 5 6//sorted

    int ans, start, end;

    for (int i = 0; i < size - 3; i++)
    {
        //  if (i > 0 && arr[i] == arr[i - 1]) continue;
        // Without skipping, you’d get multiple identical quadruplets like (1, 1, 1, 2).//removes dublicate, if not needed then we can remove

        ans = target - arr[i];

        for (int j = i + 1; j < size - 2; j++)
        {

            //   if (j > i + 1 && arr[j] == arr[j - 1]) continue;

            ans = ans - arr[j]; // this will be used as target for two sum problem

            start = j + 1;
            end = size - 1;

            while (start < end)
            {
                if (arr[start] + arr[end] == ans)
                {
                    return 1;
                }
                else if (arr[start] + arr[end] > ans)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
    }

    return 0;
}

int main()
{
    // int arr[] = {4, 2, 0, 5, 2, 6, 2, 3};
    // int arr[] = {1, 4, 45, 6, 10, 8};

    int arr[] = {1, 5, 1, 0, 6, 0};

    int size;

    size = sizeof(arr) / sizeof(arr[0]);
    // TrapRain(arr, size);
    cout << TrapRain(arr, size) << endl;

    // 0 4 4 4 5 5 6 6
    // 6 6 6 6 6 3 3 0
    // 10

    cout << TrapRainSpaceOpti(arr, size) << endl;
    cout << TrapRainMoreOpti(arr, size) << endl;
    cout << trapRainWater(arr, size) << endl;

    // int target = 13;
    int target = 7;
    cout << Sum_3(arr, size, target) << endl;
    cout << Sum_4(arr, size, target) << endl;
}