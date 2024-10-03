#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, sum = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
        sum += temp;
    }
    int tb = sum / n;
    int ps = 0;
    for (int i : v){
        ps += (i - tb)*(i-tb);
    }
    cout << tb << " " << ps/n;
}

//testcase: 5 1 2 3 4 5