#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct text {
private:
    string t;
    stack<string> action;
    stack<bool> state;

public:
    void append(string W) {
        t.append(W);
        action.push(W);
        state.push(true);
        return;
    }
    void del(int k) {
        string temp = t.substr(t.size() - k);;
        t.erase(t.size() - k);
        action.push(temp);
        state.push(false);
        return;
    }
    void undo() {
        if (state.top()) {
            for (int i = 0; i < action.top().size(); i++) {
                t.pop_back();
            }
        }
        else {
            for (char c : action.top()) {
                t.push_back(c);
            }
        }
        action.pop();
        state.pop();
        return;
    }
    void print(int k) {
        cout << t[k - 1] << endl;
        return;
    }
};

int main() {
    int Q;
    cin >> Q;
    text t;
    for (int i = 0; i < Q; i++) {
        int action = 0;
        cin >> action;
        if (action == 1) {
            string temp;
            cin >> temp;
            t.append(temp);
        }
        else if (action == 2) {
            int n;
            cin >> n;
            t.del(n);
        }
        else if (action == 3) {
            int n;
            cin >> n;
            t.print(n);
        }
        else {
            t.undo();
        }
    }
    return 0;
}
