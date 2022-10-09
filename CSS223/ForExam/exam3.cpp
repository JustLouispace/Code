#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
main()
{
    char w[20], s[10];
    cout << "Input word : ";
    gets(w);
    cout << "Input seek word : ";
    gets(s);
    int wl = strlen(w);
    int sl = strlen(s);
    int c = 0;
    for (int i = 0; i < wl; i++)
    {
        if (w[i] == s[c] || w[i] == s[c] - 32 || w[i] == s[c] + 32)
        {
            c++;
            if (c == sl)
            {
                cout << "There is " << s << " in " << w << "!";
                return 0;
            }
        }
    }
    cout << "There is no " << s << " in " << w << "!";
    return 0;
}