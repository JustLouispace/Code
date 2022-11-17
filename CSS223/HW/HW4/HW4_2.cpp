#include <iostream>
#include <cstring>

using namespace std;

class AQueue {
	public : 
		int maxSize;
		int front;
		int rear;
		int *listArray;
		
		AQueue (int size) {
			maxSize = size + 1;
			rear = 0;
			front = 1;
			listArray = new int[maxSize];
		}
		
		~AQueue () {
			delete listArray;
		}
		
		void clear () {
			rear = 0;
			front = 1;
		}
		
		void enqueue (int it) {
			if(((rear+2)%maxSize)==front) {
				cout<<"Queue is full"<<endl;
			}
			else {
				rear = (rear+1)%maxSize;
				listArray[rear] = it;
			}
		}
		
		int dequeue () {
			if(length()==0) {
				cout<<"Queue is empty"<<endl;
				return 0;	
			}
			int it = listArray[front];
			front = (front+1)%maxSize;
			return it;
		}
		
		int frontValue () {
			if(length()==0) {
				cout<<"Queue is empty"<<endl;
				return 0;
			}
			return listArray[front];
		}
		
		int length () {
			return ((rear+maxSize)-front+1)%maxSize;
		}
};

class Tictactoe {
	public :
		char board[3][3];
		int turn;
		
		Tictactoe () {
			for(int j=2;j>=0;j--) {
				for(int i=0;i<3;i++) {
					board[i][j]='_';
				}
			}
			turn=0;
		}
		
		void update (int x, int y, char player) {
			board[x][y]=player;
			turn++;
		}
		
		int endGameCheck () {
			char p;
			if(turn%2==1) {
				p='x';
			}
			else {
				p='o';
			}
			
			if((board[0][0]==p&&board[1][1]==p&&board[2][2]==p)||
			   (board[0][2]==p&&board[1][1]==p&&board[2][0]==p)||
			   (board[0][0]==p&&board[0][1]==p&&board[0][2]==p)||
			   (board[1][0]==p&&board[1][1]==p&&board[1][2]==p)||
			   (board[2][0]==p&&board[2][1]==p&&board[2][2]==p)||
			   (board[0][0]==p&&board[1][0]==p&&board[2][0]==p)||
			   (board[0][1]==p&&board[1][1]==p&&board[2][1]==p)||
			   (board[0][2]==p&&board[1][2]==p&&board[2][2]==p)) {
			   		return 1;
			   }
			else {
				return 0;
			}
			
		}
		
		int availableMove (int x, int y) {
			if(board[x][y]=='_') {
				return 1;
			}
			else {
				return 0;
			}
		}
		
		void printBoard () {
			cout<<"====Board===="<<endl;
			for(int j=2;j>=0;j--) {
				for(int i=0;i<3;i++) {
					cout<<board[i][j];
				}
				cout<<endl;
			}
			if(endGameCheck()==1) {
				cout<<"----End Game----"<<endl;
			}
		}
};

class Node {
	public :
		int parent;
		Tictactoe *board;
};

class UpTree {
	public :
		int maxSize;
		int root;
		int nextLeaf;
		Node *listArray;
		
		UpTree (int size) {
			maxSize = size + 1;
			root = 0;
			nextLeaf = 1;
			listArray = new Node[maxSize];
			listArray[0].board = new Tictactoe();
			listArray[0].parent = -1;
		}
		
		void traceBack (int pos, string t1, string t2, string t3) {
			if(listArray[pos].parent!=-1) {
				for(int i=2;i>=0;i--) {
					t1=listArray[pos].board->board[i][2]+t1;
				}
				for(int i=2;i>=0;i--) {
					t2=listArray[pos].board->board[i][1]+t2;
				}
				for(int i=2;i>=0;i--) {
					t3=listArray[pos].board->board[i][0]+t3;
				}
				traceBack(listArray[pos].parent,"|"+t1,"|"+t2,"|"+t3);
			}
			else {
				cout<<t1<<endl;
				cout<<t2<<endl;
				cout<<t3<<endl;
			}
		}
		
		void span (int current, AQueue *Que) {
			int spanTime = 0;
			if(listArray[current].board->endGameCheck()==0) {
				for(int j=2;j>=0;j--) {
					for(int i=0;i<=2;i++) {
						if(listArray[current].board->availableMove(i,j)==1) {
							listArray[nextLeaf].board = new Tictactoe();
							*listArray[nextLeaf].board = *listArray[current].board;
							listArray[nextLeaf].parent = current;
							if(listArray[nextLeaf].board->turn%2==0) {
								listArray[nextLeaf].board->update(i,j,'x');
							}
							else {
								listArray[nextLeaf].board->update(i,j,'o');
							}
							Que->enqueue(nextLeaf);
							nextLeaf++;
							spanTime++;
						}
					}
				}
			}
			else {
				cout<<"node number "<<current<<":";
				if(listArray[current].board->turn%2==0) {
					cout<<" o wins"<<endl;
				}
				else {
					cout<<" x wins"<<endl;
				}
				traceBack(current,"","","");
			}
		}
};

int main () {
	UpTree tree(600000);
	AQueue que(220000);
	tree.listArray[0].board->printBoard();
	que.enqueue(0);
	while(que.length()>0) {
		tree.span(que.dequeue(),&que);
	}
	cout<<"Done"<<endl;
	return 0;
}