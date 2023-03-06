#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ci;
const int SIZE = 9;
vector<vector<int>> map(SIZE, vector<int>(SIZE, 0));
bool isValid(ci &point, int &value) {
    int x = point.first;
    int y = point.second;
    //가로
    for (int ny = 0; ny < SIZE; ny++) {
        if (ny == y) {
            continue;
        }
        if (map[x][ny] == value) {
            return false;
        }
    }
    //세로
    for (int nx = 0; nx < SIZE; nx++) {
        if (nx == x) {
            continue;
        }
        if (map[nx][y] == value) {
            return false;
        }
    }
    //구역
    int x_start = (x / 3) * 3;
    int y_start = (y / 3) * 3;
    for (int dx = 0; dx < 3; dx++) {
        for (int dy = 0; dy < 3; dy++) {
            int nx = dx + x_start;
            int ny = dy + y_start;
            if (nx == x && ny == y) {
                continue;
            }
            if (map[nx][ny] == value) {
                return false;
            }
        }
    }
    return true;
}
void backtracking(int cnt, vector<ci> &zeros) {
    if (cnt == zeros.size()) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << map[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }
    for (int i = 1; i <= SIZE; i++) {
        if (!isValid(zeros[cnt], i)) {
            continue;
        }
        int x = zeros[cnt].first;
        int y = zeros[cnt].second;
        map[x][y] = i;
        backtracking(cnt + 1, zeros);
        map[x][y] = 0;
    }
}
int main() {
    vector<ci> zeros;
    char input;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> input;
            map[i][j] = input - '0';
            if (input == '0') {
                zeros.push_back({i, j});
            }
        }
    }
    backtracking(0, zeros);
    return 0;
}