#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int won(int c[9], int n) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (c[i] == n && c[i+1] == n && c[i+2] == n) {
            return 1;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (c[i] == n && c[i+3] == n && c[i+6] == n) {
            return 1;
        }
    }
    // Check diagonals
    if (c[0] == n && c[4] == n && c[8] == n) {
        return 1;
    }
    if (c[2] == n && c[4] == n && c[6] == n) {
        return 1;
    }
    return 0;
}

main () {
    int res = 0;
    std::vector<char> pc = {' ', 'x', 'o'};
    int c[9] = {0};
    for (c[0]=0;c[0]<3;c[0]++)
        for (c[1]=0;c[1]<3;c[1]++)
            for (c[2]=0;c[2]<3;c[2]++)
                for (c[3]=0;c[3]<3;c[3]++)
                    for (c[4]=0;c[4]<3;c[4]++)
                        for (c[5]=0;c[5]<3;c[5]++)
                            for (c[6]=0;c[6]<3;c[6]++)
                                for (c[7]=0;c[7]<3;c[7]++)
                                    for (c[8]=0;c[8]<3;c[8]++){
                                        int countx = 0;
                                        int county = 0;
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
                                                county++;
                                            }
                                        }
                                        if (abs(countx - county) < 2)
                                        {
                                            if(won(c,1) + won(c,2) == 1 || (won(c,1) + won(c,2)  == 0 && countx+county == 9 ))
                                            {
                                                cout << " " << pc[c[0]] << " | " << pc[c[1]] << " | " << pc[c[2]] << endl;
                                                cout << "---+---+---" << endl;
                                                cout << " " << pc[c[3]] << " | " << pc[c[4]] << " | " << pc[c[5]] << endl;
                                                cout << "---+---+---" << endl;
                                                cout << " " << pc[c[6]] << " | " << pc[c[7]] << " | " << pc[c[8]] << endl;
                                                if (won(c, 1)) { 
                                                    res = 1;
                                                    cout<<res<<endl;
                                                } else if (won(c, 2)) { 
                                                    res = -1;
                                                    cout<<res<<endl;
                                                } else { 
                                                    res = 0;
                                                    cout<<res<<endl;
                                                }
                                                cout<<endl;
                                            }
                                        }
                                    }
}