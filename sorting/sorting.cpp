// sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void printArr(int* arr, int len)
{
    for (int i{ 0 }; i < len; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

// insertion sort
// avg = worst case = O(n^2)
bool insertSort(int* arr, int len)
{
    if ((arr == nullptr) || (len < 0) || (len == 0)) return false;

    int valToInsert{};
    int holePos{};

    for (int i{ 0 }; i < len; ++i)
    {
        valToInsert = arr[i]; // store current value
        holePos = i; // track insertion position

        while (holePos > 0 && arr[holePos - 1] > valToInsert)
        // if not index 0 (first element) and the previous element is greater than current value
        {
            arr[holePos] = arr[holePos - 1]; // shift up previous value
            --holePos; // move hole backwards by one
        }

        arr[holePos] = valToInsert; // finally insert current value into where hole is
    }

    return true;
}

// merge array for merge sort
void mergeArr(int* arr, int p, int q, int r)
{
    int lSize = q - p + 1; // size of left sub-array
    int rSize = r - q; // size of right sub-array

    int* lArr{ new int[lSize] }; // temp array to hold left sub-array
    int* rArr{ new int[rSize] }; // temp array to hold righ sub-array

    for (int i{ 0 }; i < lSize; ++i) // fill left sub-array
    {
        lArr[i] = arr[p + i];
    }

    for (int j{ 0 }; j < rSize; ++j) // fill right sub-array
    {
        rArr[j] = arr[q + 1 + j];
    }

    // init indices
    int lIndex{ 0 };
    int rIndex{ 0 };
    int arrIndex{ p };

    while ((lIndex < lSize) && (rIndex < rSize)) // keep going until one of sub-array's end is reached
    {
        if (lArr[lIndex] < rArr[rIndex]) // if left element is smaller, put it in main array
        {
            arr[arrIndex] = lArr[lIndex];
            ++lIndex; // shift to next position in left sub-array
        }
        else // if right element is smaller, put it in main array
        {
            arr[arrIndex] = rArr[rIndex];
            ++rIndex; // shift to next position in right sub-array
        }
        ++arrIndex; // shift to next position in main array each time it is populated
    }

    while (lIndex < lSize) // fill rest of left sub-array into main array (assuming right sub-array reached end first from above)
    {
        arr[arrIndex] = lArr[lIndex];
        ++lIndex;
        ++arrIndex;
    }

    while (rIndex < rSize) // fill rest of right sub-array into main array (assuming left sub-array reached end first from above)
    {
        arr[arrIndex] = rArr[rIndex];
        ++rIndex;
        ++arrIndex;
    }

    // delete temp arrays
    delete[] lArr;
    delete[] rArr;
}

// merge sort
// worse case = O(n * log n)
void mergeSort(int* arr, int p, int r)
{
    if (r > p) // keep going as long as size of arr is not 1
    {
        int q = p + (r - p) / 2; // becareful to add p as base, since p not always == 0
        mergeSort(arr, p, q); // recursively sort left side
        mergeSort(arr, q + 1, r); // recursively sort right side
        mergeArr(arr, p, q, r); // merge and actually sort two sub-arrays
    }
}

int main()
{
    int arr[]{ 14, 33, 27, 10, 35, 19, 42, 44 };

    //insertSort(arr, std::size(arr));

    mergeSort(arr, 0, std::size(arr) - 1);

    printArr(arr, std::size(arr));
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
