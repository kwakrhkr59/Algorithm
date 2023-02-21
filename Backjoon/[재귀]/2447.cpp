#include <iostream>
#include <vector>
using namespace std;
void recursion(int size, int x, int y, int n, vector<vector<char>> &stars) {
    int next_size = size / 3;
    if (next_size == 1) {
        for (int dx = 0; dx < 3; dx++) {
            for (int dy = 0; dy < 3; dy++) {
                if (dx == 1 && dy == 1) {
                    continue;
                }
                stars[x + dx][y + dy] = '*';
            }
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            int nx = x + next_size * i;
            int ny = y + next_size * j;
            recursion(next_size, nx, ny, n, stars);
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<vector<char>> stars(n, vector<char>(n, ' '));
    recursion(n, 0, 0, n, stars);
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cout << stars[x][y];
        }
        cout << "\n";
    }
}