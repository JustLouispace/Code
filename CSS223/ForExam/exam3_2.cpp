#include <iostream>
#include <string.h>

using namespace std;

main()
{
    // เพราะคำที่ยาวที่สุดในอังกฤษมีความยาวเป็น 52 ตัวอักษร
    char str1[52];
    cout << "Input word : ";
    cin >> str1;

    char str2[52];
    cout << "Input seek word : ";
    cin >> str2;

    int str1Length = strlen(str1);
    int str2Length = strlen(str2);

    int count = 0;

    for (int i = 0; i < str1Length; i++)
    {
        if (str1[i] == str2[count] || str1[i] == str2[count] - 32 || str1[i] == str2[count] + 32)
        {
            count++;
            if (count == str2Length)
            {
                cout << "There is " << str2 << " in " << str1 << "!";
                return 0;
            }
        }
    }
    cout << "There is no " << str2 << " in " << str1 << "!";
    cout << endl;
}