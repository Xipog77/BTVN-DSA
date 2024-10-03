#include <iostream>

using namespace std;

int main(){
    int n, chan = 0, le = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if (temp%2 == 0) chan++;
        else le++;
    }
    cout << chan << " " << le; 
}

//testcase: 3 1 2 3
