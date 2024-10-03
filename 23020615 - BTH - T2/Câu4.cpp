#include <iostream>

using namespace std;

int main(){
    int m,n;
    cin >> m >> n;
    int map[m][n];
    for (int i = 0; i < m; i++){
        for (int j = 0; j< n; j++){
            cin >> map[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < m - 1; i++){
        for (int j = 0; j < n - 1; j++){
            if (map[i][j] + map[i][j+1] + map[i+1][j] + map[i+1][j+1] == 0) count++;
        }
    }
    cout << count;
}

//testcase: 4 5 1 0 -1 2 1 0 -1 1 0 0 0 0 0 1 -1 1 2 3 -1 0