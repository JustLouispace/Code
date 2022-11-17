#include <iostream>

using namespace std;
class ScoreBoard
{
private:
    string name;
    float score;
    ScoreBoard *next;
    ScoreBoard *prev;

public:
    ScoreBoard(ScoreBoard *next = NULL, ScoreBoard *prev =NULL)
    {
        this->next = next;
        this->prev = prev;
    }
    ScoreBoard(string name, float score, ScoreBoard *next = NULL, ScoreBoard *prev = NULL)
    {
        this->name = name;
        this->score = score;
        this->next = next;
        this->prev = prev;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }
    void setScore(float score)
    {
        this->score = score;
    }
    float getScore()
    {
        return this->score;
    }
    void setNext(ScoreBoard *next)
    {
        this->next = next;
    }
    ScoreBoard *getNext()
    {
        return this->next;
    }
    void setPrev(ScoreBoard *prev)
    {
        this->prev = prev;
    }
    ScoreBoard *getPrev()
    {
        return this->prev;
    }
};
class HeadScoreBoard
{
private:
    int max;
    int num;
    ScoreBoard *head;
    ScoreBoard *tail;
    ScoreBoard *fence;

public:
    HeadScoreBoard()
    {
        setStart();
    }
    ~HeadScoreBoard()
    {
        destroy();
    }
    void setStart()
    {
        head = tail = fence = new ScoreBoard;
        this->max = 10;
        this->num = 0;
    }
    void insert(ScoreBoard *temp)
    {
        if (fence->getNext() != NULL)
        {
            fence->getNext()->setPrev(temp);
        }
        temp->setNext(fence->getNext());
        temp->setPrev(fence);
        fence->setNext(temp);
        this->num++;
    }
    void remove()
    {
        ScoreBoard *temp;
        temp = fence->getNext();
        temp->getNext()->setPrev(fence);
        fence->setNext(temp->getNext());
        delete temp;
    }
    void destroy()
    {
        while (head != NULL)
        {
            fence = head;
            head = head->getNext();
            delete fence;
        }
    }
    void fenceToNext()
    {
        if (fence->getNext() != NULL)
        {
            fence = fence->getNext();
        }
    }
    void fenceToPrev()
    {
        if (fence->getPrev() != NULL)
        {
            fence = fence->getPrev();
        }
    }
    void addNewScore(string name, float score)
    {
        cout << name << " got a new score = " << score << endl;
        ScoreBoard *temp = new ScoreBoard(name, score);
        fence = head;
        while (true)
        {
            if (fence == tail)
            {
                insert(temp);
                tail = temp;
                break;
            }
            else
            {
                if (score > fence->getNext()->getScore())
                {
                    insert(temp);
                    break;
                }
                else
                {
                    fenceToNext();
                }
            }
        }
    }
    void dealExceed()
    {
        while (num > 10)
        {
            fence = tail->getPrev();
            cout << tail->getName();
            cout << " was remove from the score board\n";
            delete tail;
            tail = fence;
            tail->setNext(NULL);
            num--;
        }
    }
    void showBoard()
    {
        fence = head;
        while (fence != tail)
        {
            cout << fence->getNext()->getName();
            cout << "\n" << fence->getNext()->getScore() << endl;
            fenceToNext();
        }
    }
};
int main()
{
    HeadScoreBoard board;
    cout<<"-----------SCOREBORAD Top 10-----------"<<endl;
    board.addNewScore("Pumipat", 40);
    board.addNewScore("Awirut", 80);
    board.addNewScore("Chaninat", 50);
    board.addNewScore("Kollawat", 55);
    board.addNewScore("Pakawat", 53);
    board.addNewScore("Kantapon", 67);
    board.addNewScore("Sirawit", 64);
    board.addNewScore("Siraphat", 69);
    board.addNewScore("Thanyapisit", 92);
    board.addNewScore("Punnapa", 98);
    board.addNewScore("Varintorn", 83);
    board.dealExceed();
    board.showBoard();
    return 0;
}