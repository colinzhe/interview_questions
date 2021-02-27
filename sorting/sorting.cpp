// sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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

void mergeArr(int* arr, int p, int q, int r)
{
    int lSize = q - p + 1;
    int rSize = r - q + r;
}

// merge sort
// worse case = O(n * log n)
void mergeSort(int* arr, int p, int r)
{
    if (r > p)
    {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        mergeArr(arr, p, q, r);
    }
}

void printArr(int* arr, int len)
{
    for (int i{ 0 }; i < len; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
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
