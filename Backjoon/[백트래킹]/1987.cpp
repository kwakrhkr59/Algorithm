#include <iostream>
#include <vector>
using namespace std;
const int MAX = 26;
bool visited_alpha[MAX] = {false};
vector<vector<int>> map;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int max_value = 0;
void backtracking(int cnt, int x, int y, int r, int c) {
    bool flag = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < r && 0 <= ny && ny < c) {
            int alpha = map[nx][ny];
            if (visited_alpha[alpha]) {
                continue;
            }
            flag = false;
            visited_alpha[alpha] = true;
            backtracking(cnt + 1, nx, ny, r, c);
            visited_alpha[alpha] = false;
        }
    }
    if (flag) {
        max_value = max(max_value, cnt);
    }
}
int main() {
    int r, c;
    char input;
    cin >> r >> c;
    map.assign(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> input;
            map[i][j] = input - 'A';
        }
    }

    visited_alpha[map[0][0]] = true;
    backtracking(1, 0, 0, r, c);
    cout << max_value;
    return 0;
}