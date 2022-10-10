#include <iostream>

using namespace std;

main(){
    int score[] = {10,4,5,6,7,2,3,45,89,0};
    int count = sizeof(score)/sizeof(score[0]);
    int n = 3;

    int maxi = score[0];
    int top_max[n];
    for(int i = 0; i < count;i++){
        top_max[0] = maxi;
        if (score[i] > maxi){
            maxi = score[i];
            top_max[0] = maxi;
        }
    }
}