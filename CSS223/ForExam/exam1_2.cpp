#include <iostream>

using namespace std;

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	if (start >= end){
		return;
    }
	int p = partition(arr, start, end);

	quickSort(arr, start, p - 1);

	quickSort(arr, p + 1, end);
}

int main()
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

	quickSort(n, 0, sizenumberin - 1);

    int sizenumberout;
    cout << "Enter a number output: ";
    cin >> sizenumberout;
    cout << "First " << sizenumberout << " number is ";
    if (sizenumberout <= sizenumberin)
    {
        for (int i = 0; i < sizenumberout; i++)
        {
            cout << n[i] << " ";
        }
    }
    else
    {
        cout << "Error";
    }
	return 0;
}