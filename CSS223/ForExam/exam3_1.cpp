#include <iostream>

using namespace std;

main(){
    string str1;
    cout << "Input word : ";
    cin >> str1;
    string str2;
    cout << "Input seek word : ";
    cin >> str2;
    int i = 0 , j = 0;
    while(i, str1.length() && j<str2.length()){
        if(str1[i] == str2[j]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    if(j == str2.length()){
        cout << "There is " << str2 << " in " << str1 << "!";
    }
    else{
        cout << "There is no " << str2 << " in " << str1 << "!";
    }
    cout << endl;
    cout << "BIG O: O(n)";
}