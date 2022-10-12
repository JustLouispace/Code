#include <iostream>

using namespace std;

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1) {
        int index = partition(arr, l, r);
        if (index - l == k - 1)
            return arr[index];
        if (index - l > k - 1) 
            return kthSmallest(arr, l, index - 1, k);
        return kthSmallest(arr, index + 1, r, 
                            k - index + l - 1);
    }
    return INT_MAX;
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

    kthSmallest(n, 0, sizenumberin - 1, 2);

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