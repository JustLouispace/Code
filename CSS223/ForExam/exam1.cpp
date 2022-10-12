#include <iostream>

using namespace std;

void merge(int array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
         indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

main()
{
    int sizenumberin;
    cout << "Enter a size of number: ";
    cin >> sizenumberin;
    cout << "You entered Size of Number: " << sizenumberin << endl;
    int n[sizenumberin] = {};
    for (int j = 0; j < sizenumberin; j++)
    {
        cout << "Enter a number: ";
        cin >> n[j];
    }
    auto arr_size = sizeof(n) / sizeof(n[0]);

    mergeSort(n, 0, arr_size - 1);

    int sizenumberout;
    cout << "Enter a number output: ";
    cin >> sizenumberout;
    cout << "First " << sizenumberout << " number is ";
    if (sizenumberout <= sizenumberin)
    {
        for (int j = 0; j < sizenumberout; j++)
        {
            cout << n[j] << " ";
        }
    }
    else
    {
        cout << "Error";
    }
    cout << endl;
    cout << "BIG O: O(n)";
}