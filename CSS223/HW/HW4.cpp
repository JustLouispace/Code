// all possible tic tac toe combinations
// 9*8*7*6*5*4*3*2*1 = 9! = 362,880

#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    for ( int a = 1; a <= 9; a++ )
        for ( int b = 1; b <= 9; b++ )
            if ( b != a )
                for ( int c = 1; c <= 9; c++ )
                    if ( c != a && c != b )
                        for ( int d = 1; d <= 9; d++ )
                            if ( d != a && d != b && d != c )
                                for ( int e = 1; e <= 9; e++ )
                                    if ( e != a && e != b && e != c && e != d )
                                        for ( int f = 1; f <= 9; f++ )
                                            if ( f != a && f != b && f != c && f != d && f != e )
                                                for ( int g = 1; g <= 9; g++ )
                                                    if ( g != a && g != b && g != c && g != d && g != e && g != f )
                                                        for ( int h = 1; h <= 9; h++ )
                                                            if ( h != a && h != b && h != c && h != d && h != e && h != f && h != g )
                                                                for ( int i = 1; i <= 9; i++ )
                                                                    if ( i != a && i != b && i != c && i != d && i != e && i != f && i != g && i != h )
                                                                    {
                                                                        count++;
                                                                        cout << count << " " << a << b << c << d << e << f << g << h << i << endl;
                                                                    }
    return 0;
}

// output:
// 362880 
