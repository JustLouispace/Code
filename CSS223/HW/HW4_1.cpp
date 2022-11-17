#include <iostream>

using namespace std;

// 0 = empty
int board[3][3] = { {0, 0, 0},
                    {0, 0, 0},
                    {0, 0, 0} };

int checkXWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1) {
            return 1;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == 1 && board[1][i] == 1 && board[2][i] == 1) {
            return 1;
        }
    }
    if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
        return 1;
    }
    if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) {
        return 1;
    }
    return 0;
}

int checkOWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == 2 && board[i][1] == 2 && board[i][2] == 2) {
            return 1;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == 2 && board[1][i] == 2 && board[2][i] == 2) {
            return 1;
        }
    }
    if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) {
        return 1;
    }
    if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2) {
        return 1;
    }
    return 0;
}

int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}


// Check if the board is full
bool boardFull() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

// Print the board
void printBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// All combinations of tic-tac-toe board
main(){
    // Loop all combinations of tic-tac-toe board
    
}