// Polynomial addition and multiplication with linked lists

#include <iostream>

using namespace std;

struct Node
{
    float coefficient;
    int degree;
    Node *next;
};

class Polynomial
{
private:
    Node *head;
    Node *tail;

public:
    Polynomial()
    {
        // cout << "Polynomial created." << endl;
        head = tail = NULL;
    }
    ~Polynomial()
    {
        Node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        // cout << "Polynomial deleted." << endl;
    }

    void Insert(float coeff, int exp)
    {

        Node *new_node = new Node();
        new_node->coefficient = coeff;
        new_node->degree = exp;
        if (head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            if (exp > head->degree)
            {
                new_node->next = head;
                head = new_node;
            }
            else
            {
                Node *temp = head;
                while (temp->next != NULL)
                {
                    if (temp->next->degree < exp)
                    {
                        new_node->next = temp->next;
                        temp->next = new_node;
                        return;
                    }
                    temp = temp->next;
                }
                tail->next = new_node;
                tail = new_node;
            }
        }
    }

    void add(Node *head1, Node *head2)
    {
        Node *temp1, *temp2;
        temp1 = head1;
        temp2 = head2;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->degree == temp2->degree)
            {
                Insert(temp1->coefficient + temp2->coefficient, temp1->degree);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if (temp1->degree > temp2->degree)
            {
                Insert(temp1->coefficient, temp1->degree);
                temp1 = temp1->next;
            }
            else
            {
                Insert(temp2->coefficient, temp2->degree);
                temp2 = temp2->next;
            }
        }
        while (temp1 != NULL)
        {
            Insert(temp1->coefficient, temp1->degree);
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            Insert(temp2->coefficient, temp2->degree);
            temp2 = temp2->next;
        }
    }

    void multi(Node *head1, Node *head2)
    {
        Node *temp1, *temp2;
        temp1 = head1;
        temp2 = head2;
        float arrcoeff[20] = {}, coeffic, t = 0;
        int arrexp[20] = {}, exp, count = 0;
        while (temp1 != NULL)
        {
            temp2 = head2;
            while (temp2 != NULL)
            {
                t = 0;
                coeffic = temp1->coefficient * temp2->coefficient;
                exp = temp1->degree + temp2->degree;
                for (int i = 0; i < count; i++)
                {
                    if (exp == arrexp[i])
                    {
                        arrcoeff[i] += coeffic;
                        t = 1;
                        break;
                    }
                }
                if (t == 0)
                {
                    arrcoeff[count] = coeffic;
                    arrexp[count] = exp;
                    count++;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        for (int i = 0; i < count; i++)
        {
            Insert(arrcoeff[i], arrexp[i]);
        }
    }

    Node *Get_Head()
    {
        return head;
    }

    void Show()
    {
        Node *temp = head;
        if (temp != NULL)
        {
            while (temp != NULL)
            {
                cout << temp->coefficient << "x^" << temp->degree << "+";
                temp = temp->next;
            }
            cout << "\b \b" << endl;
        }
        else
        {
            cout << "The list is empty.\n";
        }
    }
};

main()
{
    Polynomial a;
    Polynomial b;
    Polynomial c;
    Polynomial d;
    a.Insert(5, 5);
    a.Insert(3, 3);
    a.Insert(4, 1);
    b.Insert(1, 4);
    b.Insert(2, 6);
    b.Insert(3, 5);

    c.add(a.Get_Head(), b.Get_Head());
    d.multi(a.Get_Head(), b.Get_Head());

    cout << "\n---------------------------------------------\n"<< endl;
    cout << "a = ";
    a.Show();
    cout << "b = ";
    b.Show();
    cout << "\nResult with Add Polynomial";
    cout << "\nc = a + b\nc = ";
    c.Show();
    cout << "\nResult with Mutiple Polynomial" << endl;
    cout << "d = a x b\nd = ";
    d.Show();
    cout << "\n---------------------------------------------" << endl;
}