#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
using namespace std;

int main(){
    srand(time(NULL));
    int map[10][10];
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10 ;j++){
            map[i][j] = 0;
        }
    }
    int birthDay = 7;
    int monsterX = 3;
    int lastID = 3;
    int secondLastID = 4;

    //Tree
    int tree_X;
    int tree_Y;
    while(true){
        tree_X = rand() % 10;
        tree_Y = rand() % 10;
        if ((tree_X != birthDay && tree_Y != lastID) || (tree_X != monsterX && tree_Y != secondLastID)){
            break;
        }
    }
    map[tree_X][tree_Y] = 1;
    
    //Hero
   	map[birthDay][lastID] = 2;
   	
   	//Monster
   	map[monsterX][secondLastID] = 3;
    
    for(int i = 9;i >= 0;i--){
        for(int j = 0;j < 10 ;j++){
            cout << map[j][i];
        }
        cout << "\n";
    }

	float Taxicab = abs(birthDay-monsterX)+abs(lastID-secondLastID);

	float Euclidean = sqrt(pow(birthDay-monsterX,2)+pow(lastID-secondLastID,2));

	float Chebyshev;
		if(abs(birthDay - monsterX)>abs(lastID-secondLastID)){
			Chebyshev=abs(birthDay-monsterX);
		}
		else{
			Chebyshev=abs(lastID-secondLastID);
		}

cout << "Taxicab = " << Taxicab << endl;
cout << "Euclidean = " << Euclidean << endl;
cout << "Chebyshev = " << Chebyshev << endl;
}