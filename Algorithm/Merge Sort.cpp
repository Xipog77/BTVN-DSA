// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> v1, vector<int> v2) {
    vector<int> ans;
    int i = 0, j = 0;
    while(i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            ans.push_back(v1[i]);
            i++;
        } else {
            ans.push_back(v2[j]);
            j++;
        }
    }
    while(i < v1.size()) {
        ans.push_back(v1[i]);
        i++;
    }
    while (j < v2.size()) {
        ans.push_back(v2[j]);
        j++;
    }
    return ans;
}

vector<int> merge_sort(vector<int> v) {
    if (v.size() <= 1) return v;
    int n = (v.size())/ 2;
    vector<int> v1, v2;
    for (int i = 0; i < n; i++) {
        v1.push_back(v[i]);
    }
    for (int i = n; i < v.size(); i++) {
        v2.push_back(v[i]);
    }
    
    return merge(merge_sort(v1), merge_sort(v2));
}

void print(vector<int> v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v = {3,2,5,1,3,5,23,6,7,9,5,3,8,2};
    print(merge_sort(v));

    return 0;
}