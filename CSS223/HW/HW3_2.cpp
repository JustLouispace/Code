// Multi-column-sorting

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
    cout << "Multi-column-sorting" << endl;
    multicolumn arr[9];
    arr[0].firstcol = 1;
    arr[0].secondcol = 2;
    arr[0].thirdcol = 3;
    arr[1].firstcol = 1;
    arr[1].secondcol = 2;
    arr[1].thirdcol = 2;
    arr[2].firstcol = 1;
    arr[2].secondcol = 1;
    arr[2].thirdcol = 1;
    arr[3].firstcol = 2;
    arr[3].secondcol = 2;
    arr[3].thirdcol = 2;
    arr[4].firstcol = 2;
    arr[4].secondcol = 1;
    arr[4].thirdcol = 1;
    arr[5].firstcol = 2;
    arr[5].secondcol = 1;
    arr[5].thirdcol = 2;
    arr[6].firstcol = 3;
    arr[6].secondcol = 3;
    arr[6].thirdcol = 3;
    arr[7].firstcol = 3;
    arr[7].secondcol = 2;
    arr[7].thirdcol = 2;
    arr[8].firstcol = 3;
    arr[8].secondcol = 1;
    arr[8].thirdcol = 1;

    sort(arr, 9);
    for (int i = 0; i < 9; i++) {
        cout << arr[i].firstcol << " " << arr[i].secondcol << " " << arr[i].thirdcol << endl;
    }
    return 0;
}