#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int won(int c[9], int n)
{
    // Check rows
    for (int i = 0; i < 9; i += 3)
    {
        if (c[i] == n && c[i + 1] == n && c[i + 2] == n)
        {
            return 1;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (c[i] == n && c[i + 3] == n && c[i + 6] == n)
        {
            return 1;
        }
    }
    // Check diagonals
    if (c[0] == n && c[4] == n && c[8] == n)
    {
        return 1;
    }
    if (c[2] == n && c[4] == n && c[6] == n)
    {
        return 1;
    }
    return 0;
}

main()
{
    int count = 0;
    int result = 0;
    std::vector<char> pc = {' ', 'x', 'o'};
    int c[9] = {0,0,0, 0,0,0, 0,0,0};
    for (c[0] = 0; c[0] < 3; c[0]++)
        for (c[1] = 0; c[1] < 3; c[1]++)
            for (c[2] = 0; c[2] < 3; c[2]++)
                for (c[3] = 0; c[3] < 3; c[3]++)
                    for (c[4] = 0; c[4] < 3; c[4]++)
                        for (c[5] = 0; c[5] < 3; c[5]++)
                            for (c[6] = 0; c[6] < 3; c[6]++)
                                for (c[7] = 0; c[7] < 3; c[7]++)
                                    for (c[8] = 0; c[8] < 3; c[8]++)
                                    {
                                        count++;
                                        int countx = 0;
                                        int counto = 0;
                                        for (int x : c)
                                        {
                                            if (x == 1)
                                            {
                                                countx++;
                                            }
                                        }
                                        for (int x : c)
                                        {
                                            if (x == 2)
                                            {
                                                counto++;
                                            }
                                        }
                                        if (abs(countx - counto) < 2)
                                        {
                                            if (won(c, 1) + won(c, 2) == 1 || (won(c, 1) + won(c, 2) == 0 && countx + counto == 9))
                                            {
                                                cout << " " << pc[c[0]] << " | " << pc[c[1]] << " | " << pc[c[2]] << endl;
                                                cout << "---+---+---" << endl;
                                                cout << " " << pc[c[3]] << " | " << pc[c[4]] << " | " << pc[c[5]] << endl;
                                                cout << "---+---+---" << endl;
                                                cout << " " << pc[c[6]] << " | " << pc[c[7]] << " | " << pc[c[8]] << endl;
                                                if (won(c, 1))
                                                {
                                                    result = 1;
                                                    cout << result << endl;
                                                }
                                                else if (won(c, 2))
                                                {
                                                    result = -1;
                                                    cout << result << endl;
                                                }
                                                else
                                                {
                                                    result = 0;
                                                    cout << result << endl;
                                                }
                                                cout << endl;
                                            }
                                        }
                                    }
    cout << count << endl;
}