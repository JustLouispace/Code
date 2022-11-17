#include <iostream>
using namespace std;
struct node
{
    int score;
    string name;
    node *next;
    node *prev;
    node()
    {
        next = NULL;
        prev = NULL;
    }
    node(string name, int score)
    {
        next = NULL;
        prev = NULL;
        this->name = name;
        this->score = score;
    }
};
class doublylinklisted
{
private:
    node *head;
    node *tail;
    node *curr;
    node *bef;

public:
    void main_add(string name, int score)
    {
        node *newnode = new node(name, score);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
            curr = head;
        {
            while (curr != NULL)
            {
                if (curr == head && curr->score < newnode->score)
                {
                    newnode->next = head;
                    curr->prev = newnode;
                    newnode->prev = 0;
                    head = newnode;
                    break;
                }
                else
                {
                    if (curr->score < newnode->score)
                    {
                        newnode->prev = bef;
                        newnode->next = curr;
                        curr->prev = newnode;
                        bef->next = newnode;
                        break;
                    }
                    else if (curr->next == 0)
                    {
                        tail->next = newnode;
                        newnode->prev = curr;
                        tail = newnode;
                        tail->next = 0;
                        break;
                    }
                }
                bef = curr;
                curr = curr->next;
            }
        }
    }
    void display()
    {
        cout << "Name\t\t\tScore" << endl;
        curr = head;
        while (curr != 0)
        {
            cout << curr->name << "\t\t\t" << curr->score << endl;
            curr = curr->next;
        }
    }
    void gettailout(string namen)
    {
        bef = tail->prev;
        bef->next = 0;
        if (tail->name == namen)
        {
            cout << "You score did't reach a score board" << endl;
        }
        else
        {
            cout << tail->name << " is out from the board" << endl;
        }
        delete tail;
        tail = bef;
    }
};
int main()
{
    doublylinklisted *calld = new doublylinklisted();
    string name;
    int score, i;
    for (i = 1; i <= 10; i++)
    {
        cout << "Enter Player " << i << " Name : ";
        cin >> name;
        cout << "Enter Player " << i << " Score : ";
        cin >> score;
        calld->main_add(name, score);
    }
    calld->display();
    cout << "Hello New player! Enter Your Name : ";
    cin >> name;
    cout << "And your Score ! : ";
    cin >> score;
    calld->main_add(name, score);
    calld->gettailout(name);
    calld->display();
}