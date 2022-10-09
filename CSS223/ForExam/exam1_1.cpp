#include <iostream>

using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];
    // O(n)
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    // O(n)
    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // O(n)
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // O(n)
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    // O(n)
    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixsort(int arr[], int n)
{

    int m = getMax(arr, n);
    // O(n)
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

main()
{
    int sizenumberin;
    cout << "Enter a number: ";
    cin >> sizenumberin;
    cout << "You entered Size of Number: " << sizenumberin << endl;
    int n[sizenumberin] = {};
    for (int j = 0; j < sizenumberin; j++)
    {
        cout << "Enter a number: ";
        cin >> n[j];
    }

    int arr_size = sizeof(n) / sizeof(n[0]);
    radixsort(n, arr_size);

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