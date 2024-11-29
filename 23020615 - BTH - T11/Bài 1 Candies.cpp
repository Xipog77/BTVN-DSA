#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> point;
    vector<int> candy;
    
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        point.push_back(temp);
    }
    candy.push_back(1);
    
    for (int i = 1; i < n; i++) {
        if (point[i] > point[i-1]) candy.push_back(candy[i-1] + 1);
        else candy.push_back(1);
    }
    
    for (int i = n - 2; i >= 0; i--) {
        if (point[i] > point[i+1]) {
            candy[i] = max(candy[i], candy[i+1] + 1);
        }
    }
    
    long sum = 0;
    for (int i : candy) {
        sum += i;
    }
    
    cout << sum;
}
