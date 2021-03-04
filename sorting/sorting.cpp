// sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>

void printArr(int* arr, int len)
{
    for (int i{ 0 }; i < len; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

// bubble sort
// worst case O(n^2)
void bubbleSort(int* arr, int len)
{
    assert(arr != nullptr || len > 0);

    for (int end{ len }; end > 1; --end) // reduce max index by 1 each time
    {
        for (int i{ 0 }; i < end - 1; ++i) // bubbles one largest element to the end
        {
            if (arr[i + 1] < arr[i])
            {
                std::swap(arr[i + 1], arr[i]); // swap each pair if needed
            }
        }
    }
}

// selection sort
// worst case O(n^2)
void selectionSort(int* arr, int len)
{
    for (int start{ 0 }; start < len - 1; ++start) // start with each element starting at index 0
    {
        int min = start; // store starting element's index as 'min'

        for (int i{ start }; i < len; ++i) // compare against of subsequent elements
        {
            if (arr[i] < arr[min]) // if another is smaller, then set min as its index
            {
                min = i;
            }
        }
        std::swap(arr[start], arr[min]); // swap starting element with min element
    }
}

// insertion sort
// worst case = O(n^2)
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

// partition array for quick sort
int partition(int* arr, int p, int r, int len)
{
    //std::cout << "partitioning...\n";
    //std::cout << "p = " << p << ", r = " << r << '\n';
    int pivot = arr[r]; // store right most element as pivot
    //std::cout << "pivot = " << pivot << '\n';
    int i = p - 1; // set i to first element just outside of range

    for (int j{ p }; j < r; ++j) // traverse all elements up to element just before pivot
    {
        if (arr[j] < pivot) // if the element at j is smaller than pivot
        {
            //std::cout << arr[j] << " is smaller than " << pivot << '\n';
            ++i; // increment i
            //std::cout << "swapping " << arr[i] << " with " << arr[j] << '\n';
            std::swap(arr[i], arr[j]); // swap elements at i and j
            //printArr(arr, len);
        }
        //else // otherwise do nothing
        //{
        //    std::cout << arr[j] << " is greater than or equal to " << pivot << '\n';
        //    std::cout << "do nothing\n";
        //}
    }

    //std::cout << "swapping " << arr[i + 1] << " with " << arr[r] << '\n';
    std::swap(arr[i + 1], arr[r]); // finally, swap pivot element with the first element that is larger
    //std::cout << "returning pi = " << i + 1 << ", pivot = " << arr[i + 1] << '\n';
    //printArr(arr, len);
    return (i + 1); // return the new pivot index
}

// quick sort
// worse case = O(n * log n)
void quickSort(int* arr, int p, int r, int len)
{
    if (p >= r) // stop when array size is 1
    {
        //std::cout << "p = r = " << p << '\n';
        return;
    }

    int pi = partition(arr, p, r, len); // do partition and return the new partition index

    quickSort(arr, p, pi - 1, len); // sort the left side of partition index
    quickSort(arr, pi + 1, r, len); // sort the right side of partition index
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
