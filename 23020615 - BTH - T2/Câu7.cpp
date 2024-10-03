#include <iostream>
#include <vector>

using namespace std;

int count(vector<vector<int>> map, int n, int m){
    int sum = 0;
    for(int i = 0; i < n; i++) sum += map[i][m];
    return sum;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0 ; i < n; i++)
        for (int j = 0; j < m; j++) cin >> map[i][j];
        
    for (int i = 0; i < n; i++){
        cout << count(map,n,i) << " ";
    }
}

//testcase: 2 3 1 2 3 3 2 1