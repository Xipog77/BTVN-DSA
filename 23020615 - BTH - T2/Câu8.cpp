#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int n)
{
    if (n <= 1) return false; 
    else{
        for (int i = 3; i < n; i++){
            if (n % i == 0) return false;
        }
        return true;
    } 
}   

int main(){
    int n;
    cin >> n;
    vector<int> v, snt;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if (check(temp)) snt.push_back(temp);
        v.push_back(temp);
    }
    sort(snt.begin(),snt.end());
    int j = 0;
    for (int i = 0; i < n; i++){
        if (check(v[i])) v[i] = snt[j++];
    }
    for (int i : v) cout << i << " ";
}