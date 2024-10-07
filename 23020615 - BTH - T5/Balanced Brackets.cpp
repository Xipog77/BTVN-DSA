#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

struct Stack {
private:
    char arr[1000];
    int top = 0;

public:
    void add(char d) {
        if (top >= 1000) {
            cout << "Stack is full!" << endl;
            return;
        }
        arr[top++] = d;
    }

    char get() {
        if (top == 0) {
            return '\0';
        }
        return arr[--top];
    }

    bool isEmpty() {
        return top == 0;
    }
};

string isBalanced(string s) {
    Stack ans;
    for (char c : s) {
        if (c == '{' || c == '[' || c == '(') {
            ans.add(c);
        }
        else if (c == '}') {
            if (ans.get() == '{') continue;
            else return "NO";
        }
        else if (c == ']') {
            if (ans.get() == '[') continue;
            else return "NO";
        }
        else if (c == ')') {
            if (ans.get() == '(') continue;
            else return "NO";
        }
    }

    return ans.isEmpty() ? "YES" : "NO";
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
