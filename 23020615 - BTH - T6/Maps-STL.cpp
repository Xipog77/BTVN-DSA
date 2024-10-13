#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string,int> m;
    int q;
    cin >> q;
    string temp;
    getline(cin,temp);
    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        if (n == 1) {
            string str;
            int num;
            cin >> str;
            cin >> num;
            m[str] += num;
        }
        else if (n == 2) {
            string str;
            cin >> str;
            m.erase(str);
        }
        else {
            string str;
            cin >> str;
            if (m[str] != 0) cout << m[str] << endl;
            else cout << 0 << endl;
        }
    }   
    return 0;
}