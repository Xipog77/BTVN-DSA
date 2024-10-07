#include <iostream>
#include <stack>

using namespace std;

struct queue {
private:
    stack<int> q;
    stack<int> temp;
public:
    void enqueue(int x) {
        temp.push(x);
        return;
    }
    void Push() {
        if (q.empty()) {
            while (!temp.empty()) {
                q.push(temp.top());
                temp.pop();
            }
        }
    }
    void dequeue() {
        Push();
        q.pop();
    }
    void print() {
        Push();
        cout << q.top() << endl;
    }
};

int main() {
    int n;
    queue Q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int action;
        cin >> action;
        if (action == 1) {
            int temp;
            cin >> temp;
            Q.enqueue(temp);
        }
        else if (action == 2) {
            Q.dequeue();
        }
        else {
            Q.print();
        }
    }
}
