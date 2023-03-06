#include <iostream>
#include <vector>
using namespace std;
void recursion(int col_center, int row_start, int len, vector<vector<char>> &pattern) {
    if (len == 6) {
        pattern[row_start][col_center] = '*';
        pattern[row_start + 1][col_center - 1] = '*';
        pattern[row_start + 1][col_center + 1] = '*';
        for (int col = 0; col < 5; col++) {
            pattern[row_start + 2][col_center + col - 2] = '*';
        }
        return;
    }
    int next_len = len / 2;
    recursion(col_center, row_start, next_len, pattern);
    recursion(col_center - next_len / 2, row_start + next_len / 2, next_len, pattern);
    recursion(col_center + next_len / 2, row_start + next_len / 2, next_len, pattern);
}
int main() {
    int n;
    cin >> n;
    vector<vector<char>> pattern(n, vector<char>(2 * n, ' '));
    recursion(n, 0, 2 * n, pattern);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 2 * n; j++) {
            cout << pattern[i][j];
        }
        cout << "\n";
    }
    return 0;
}