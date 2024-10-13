#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int action, num;
        cin >> action >> num;
        if (action == 1) {
            s.insert(num);
        } 
        else if (action == 2) {
            s.erase(num);
        } 
        else {
            if (s.find(num) != s.end()) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    } 
}



