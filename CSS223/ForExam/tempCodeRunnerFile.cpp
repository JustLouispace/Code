#include <iostream>
#include <stack>

using namespace std;

struct queue {
    stack<int> stacks;
    void enqueue(int x) {
        stacks.push(x);
    }
    int dequeue() {
        if (stacks.empty()) {
            cout << "Queue is empty";
            exit(0);
        }
        int x = stacks.top();
        stacks.pop();
        if (stacks.empty()) {
            return x;
        }
        int item = dequeue();
        stacks.push(x);
        return item;
    }
};

main() {
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}