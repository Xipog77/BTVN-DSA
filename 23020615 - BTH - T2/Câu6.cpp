#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v, le;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if (temp%2 != 0) le.push_back(temp);
        v.push_back(temp);
    }
    sort(le.begin(),le.end());
    int l = 0;
    for (int i = 0; i < n; i++){
        if (v[i] %2 != 0) v[i] = le[l++];
    }
    for (int i : v) cout << i << " ";
}

//testcase: 6 6 55 26 35 21 66