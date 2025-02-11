#include <iostream>

using namespace std;


struct multicolumn
{
    int firstcol;
    int secondcol;
    int thirdcol;
};

void sort(multicolumn arr[], int n) {
    multicolumn temp;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[i].firstcol > arr[j].firstcol) {
                temp.firstcol = arr[i].firstcol;
                temp.secondcol = arr[i].secondcol;
                temp.thirdcol = arr[i].thirdcol;
                arr[i].firstcol = arr[j].firstcol;
                arr[i].secondcol = arr[j].secondcol;
                arr[i].thirdcol = arr[j].thirdcol;
                arr[j].firstcol = temp.firstcol;
                arr[j].secondcol = temp.secondcol;
                arr[j].thirdcol = temp.thirdcol;
            }
            else if (arr[i].firstcol == arr[j].firstcol) {
                if (arr[i].secondcol > arr[j].secondcol) {
                    temp.firstcol = arr[i].firstcol;
                    temp.secondcol = arr[i].secondcol;
                    temp.thirdcol = arr[i].thirdcol;
                    arr[i].firstcol = arr[j].firstcol;
                    arr[i].secondcol = arr[j].secondcol;
                    arr[i].thirdcol = arr[j].thirdcol;
                    arr[j].firstcol = temp.firstcol;
                    arr[j].secondcol = temp.secondcol;
                    arr[j].thirdcol = temp.thirdcol;
                }
                else if (arr[i].secondcol == arr[j].secondcol) {
                    if (arr[i].thirdcol > arr[j].thirdcol) {
                        temp.firstcol = arr[i].firstcol;
                        temp.secondcol = arr[i].secondcol;
                        temp.thirdcol = arr[i].thirdcol;
                        arr[i].firstcol = arr[j].firstcol;
                        arr[i].secondcol = arr[j].secondcol;
                        arr[i].thirdcol = arr[j].thirdcol;
                        arr[j].firstcol = temp.firstcol;
                        arr[j].secondcol = temp.secondcol;
                        arr[j].thirdcol = temp.thirdcol;
                    }
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    multicolumn* arr = new multicolumn[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].firstcol >> arr[i].secondcol >> arr[i].thirdcol;
    }
    sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i].firstcol << " " << arr[i].secondcol << " " << arr[i].thirdcol << endl;
    }
    return 0;
}