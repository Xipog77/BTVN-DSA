#include <iostream>

using namespace std;

int count(int i, int j, int matrix[10][10], int passed [10][10], int n, int m) {
    int sum = 1;
    
    if (i > 0) {
        if (matrix[i-1][j] == 1 && passed[i-1][j] == 0) {
            passed[i-1][j] = 1;
            sum += count(i-1, j, matrix, passed, n, m);
        }
        if (j + 1 < m && matrix[i-1][j+1] == 1 && passed[i-1][j+1] == 0) {
            passed[i-1][j+1] = 1;
            sum += count(i-1, j+1, matrix, passed, n, m);
        }
        if (j > 0 && matrix[i-1][j-1] == 1 && passed[i-1][j-1] == 0) {
            passed[i-1][j-1] = 1;
            sum += count(i-1, j-1, matrix, passed, n, m);
        }
    }
    
    if (j > 0) {
        if (matrix[i][j-1] == 1 && passed[i][j-1] == 0) {
            passed[i][j-1] = 1;
            sum += count(i, j-1, matrix, passed, n, m);
        }
        if (i + 1 < n && matrix[i+1][j-1] == 1 && passed[i+1][j-1] == 0) {
            passed[i+1][j-1] = 1;
            sum += count(i+1, j-1, matrix, passed, n, m);
        }
    }
    
    if (j + 1 < m) {
        if (matrix[i][j+1] == 1 && passed[i][j+1] == 0) {
            passed[i][j+1] = 1;
            sum += count(i, j+1, matrix, passed, n, m);
        }
    }
    
    if (i + 1 < n) {
        if (matrix[i+1][j] == 1 && passed[i+1][j] == 0) {
            passed[i+1][j] = 1;
            sum += count(i+1, j, matrix, passed, n, m);
        }
        if (j + 1 < m && matrix[i+1][j+1] == 1 && passed[i+1][j+1] == 0) {
            passed[i+1][j+1] = 1;
            sum += count(i+1, j+1, matrix, passed, n, m);
        }
    }
    
    return sum;
}


int main() {
    int n, m;
    cin >> n >> m;
    int max = 0;
    
    int matrix[10][10];
    int passed[10][10];
    
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            passed[i][j] = 0;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1 && passed[i][j] == 0) {
                passed[i][j] = 1;
                int temp = count(i, j, matrix, passed, n, m);
                if (temp > max) max = temp;
            }
        }
    }
    
    cout << max;
}
