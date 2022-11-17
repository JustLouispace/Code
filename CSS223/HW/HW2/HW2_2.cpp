#include <iostream>
using namespace std;
class Polynomial
{
private:
    Polynomial *next;
    int coefficient;
    int exponent;

public:
    Polynomial(Polynomial *next = NULL)
    { // O(1)
        this->next = next;
    }
    Polynomial(int coefficient, int exponent, Polynomial *next = NULL)
    { // O(1)
        this->coefficient = coefficient;
        this->exponent = exponent;
        this->next = next;
    }
    Polynomial *getNext()
    { // O(1)
        return this->next;
    }
    int setNext(Polynomial *next)
    { // O(1)
        this->next = next;
        return 0;
    }
    int getCoefficient()
    {
        return this->coefficient; // O(1)
    }
    int setCoefficient(int coefficient)
    { // O(1)
        this->coefficient = coefficient;
        return 0;
    }
    int getExponent()
    { // O(1)
        return this->exponent;
    }
    int setExponent(int exponent)
    { // O(1)
        this->exponent = exponent;
        return 0;
    }
};
class HeadPolynomial
{
private:
    Polynomial *head;
    Polynomial *tail;
    Polynomial *fence;

public:
    int initiate()
    { // O(1)
        head = tail = fence = new Polynomial;
        return 0;
    }
    int destroy()
    { // O(n)
        while (head != NULL)
        {
            fence = head;
            head = head->getNext();
            delete fence;
        }
        return 0;
    }
    int insert(Polynomial *temp)
    { // O(1)
        temp->setNext(fence->getNext());
        fence->setNext(temp);
        return 0;
    }
    int fenceToHead()
    { // O(1)
        fence = head;
        return 0;
    }
    void fenceToNext()
    { // O(1)
        if (fence->getNext() != NULL)
        {
            fence = fence->getNext();
        }
    }
    bool checkNextLink()
    { // O(1)
        if (fence != tail)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Polynomial *getPoly()
    { // O(1)
        return fence->getNext();
    }
    int accessExpo()
    { // O(1)
        return fence->getNext()->getExponent();
    }
    int accessCoeff()
    { // O(1)
        return fence->getNext()->getCoefficient();
    }
    HeadPolynomial()
    { // O(1)
        initiate();
    }
    ~HeadPolynomial()
    { // O(n)
        destroy();
    }
    int addTerm(int coefficient, int exponent)
    { // O(n)
        Polynomial *temp = new Polynomial(coefficient, exponent);
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
                if (exponent > fence->getNext() -> getExponent())
                {
                    insert(temp);
                    break;
                }
                else if (exponent == fence->getNext() -> getExponent())
                {
                    int sum = coefficient + fence -> getNext()->getCoefficient();
                    fence->getNext()->setCoefficient(sum);
                    delete temp;
                    break;
                }
                else
                {
                    fenceToNext();
                }
            }
        }
        return 0;
    }
    int showPoly()
    { // O(n)
        fence = head;
        while (fence->getNext() != NULL)
        {
            if (fence != head && fence->getNext() -> getCoefficient() >= 0)
            {
                cout << "+";
            }
            cout << fence->getNext()->getCoefficient();
            if (fence->getNext()->getExponent() != 0)
            {
                cout << "x";
                if (fence->getNext()->getExponent() != 1)
                {
                    cout << "^" << fence->getNext() -> getExponent();
                }
            }
            fenceToNext();
        }
        cout << "\n";
        return 0;
    }
    int add(HeadPolynomial p1, HeadPolynomial p2)
    { // O(n)!!!
        HeadPolynomial *temp1 = &p1;
        HeadPolynomial *temp2 = &p2;
        temp1->fenceToHead();
        temp2->fenceToHead();
        fence = head;
        while (temp1->checkNextLink() && temp2->checkNextLink())
        {
            if (temp1->accessExpo() > temp2->accessExpo())
            {
                Polynomial *temp = new Polynomial(temp1 -> accessCoeff(),temp1->accessExpo());
                insert(temp);
                tail = temp;
                temp1->fenceToNext();
            }
            else if (temp1->accessExpo() < temp2 -> accessExpo())
            {
                Polynomial *temp = new Polynomial(temp2 -> accessCoeff(),temp2->accessExpo());
                insert(temp);
                tail = temp;
                temp2->fenceToNext();
            }
            else if (temp1->accessExpo() == temp2 -> accessExpo())
            {
                int sumCoefficient;
                sumCoefficient = temp1->accessCoeff() + temp2->accessCoeff();
                Polynomial *temp = new Polynomial(sumCoefficient, temp1->accessExpo());
                insert(temp);
                tail = temp;
                temp1->fenceToNext();
                temp2->fenceToNext();
            }
            fenceToNext();
        }
        return 0;
    }
    int multiply(HeadPolynomial p1, HeadPolynomial p2)
    { //O(n ^ 2)
        HeadPolynomial *temp1 = &p1;
        HeadPolynomial *temp2 = &p2;
        fence = head;
        HeadPolynomial *temp = new HeadPolynomial;
        for (temp1->fenceToHead(); temp1->checkNextLink(); temp1 -> fenceToNext())
        {
            for (temp2->fenceToHead(); temp2 -> checkNextLink();
                 temp2->fenceToNext())
            {
                int sum_exponent = temp1->accessExpo() + temp2->accessExpo();
                int sum_coefficient = temp1->accessCoeff() * temp2->accessCoeff();
                Polynomial *mul_result = new Polynomial(sum_coefficient, sum_exponent);
                temp->insert(mul_result);
                temp->fenceToNext();
                temp->tail = mul_result;
            }
        }
        for (temp->fenceToHead(); temp->checkNextLink(); temp -> fenceToNext())
        {
            int coefficient = temp->accessCoeff();
            int exponent = temp->accessExpo();
            addTerm(coefficient, exponent);
        }
        return 0;
    }
};
int main()
{
    HeadPolynomial a, b, sum, mul;
    a.addTerm(4, 3);
    a.addTerm(3, 2);
    a.addTerm(5, 0);
    b.addTerm(6, 1);
    b.addTerm(5, 0);
    cout << "Polynomial 1 is ";
    a.showPoly();
    cout << "Polynomial 2 is ";
    b.showPoly();
    sum.add(a, b);
    cout << "Sum of polynomial is ";
    sum.showPoly();
    mul.multiply(a, b);
    cout << "Multiple result of polynomial is ";
    mul.showPoly();
    return 0;
}