#include <iostream>
#include <string>
using namespace std;
struct Node{
    string name;
    int score;
    Node *next;
    Node *prev;
    Node(string name, int score, Node *next = NULL, Node *prev = NULL){
        this->name = name;
        this->score = score;
        this->next = next;
        this->prev = prev;
    }
};
class ScoreBoard
{
private:
    Node *head;
    Node *tail;
public:
    ScoreBoard()
    {
        head = NULL;
        tail = NULL;
    }
    void sortScoreBoard(){
        Node *current = head;
        Node *temp = NULL;
        if(head == NULL){
            return;
        }
        else{
            while(current != NULL){
                temp = current->next;
                while(temp != NULL){
                    if(current->score < temp->score){
                        int tempScore = current->score;
                        string tempName = current->name;
                        current->score = temp->score;
                        current->name = temp->name;
                        temp->score = tempScore;
                        temp->name = tempName;
                    }
                    temp = temp->next;
                }
                current = current->next;
            }
        }
    }
    void addScore(string name, int score)
    {
        Node *newNode = new Node(name, score);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        sortScoreBoard();
    }
    void print()
    {
        int i = 0;
        Node *current = head;
        cout<<"Top 10 SCOREBORAD"<<endl;
        while (current != NULL&&i<10)
        {
            cout << current->name << " : " << current->score << " Point " << endl;
            current = current->next;
            i++;
        }
        cout<<"-----------------\n"<<endl;
    }
};
int main()
{
    ScoreBoard s;
    s.addScore("George", 260);
    s.addScore("Job   ", 250);
    s.addScore("Geng  ", 50);
    s.addScore("Mick  ", 200);
    s.addScore("Louis ", 190);
    s.addScore("Tonkla", 180);
    s.addScore("Boss  ", 170);
    s.addScore("Mint  ", 160);
    s.addScore("Pond  ", 150);
    s.addScore("Kong  ", 140);
    s.print();
    s.addScore("Kung  ", 145);
    s.addScore("Jame  ", 300);
    s.print();
    return 0;
}
