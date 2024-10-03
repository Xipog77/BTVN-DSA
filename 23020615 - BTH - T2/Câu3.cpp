#include <iostream>

using namespace std;

int main(){
    int m,n,Q;
    cin >> m >> n >> Q;
    int map[m][n];
    for (int i = 0; i < m; i++){
        for (int j = 0; j< n; j++){
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < Q; i++){
        int x, y;
        cin >> x >> y;
        cout << map[x][y] << endl;
    }
}

//testcase: 3 3 2 1 3 5 2 4 7 3 4 2 0 2 1 1 