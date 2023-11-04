#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int getDir(int &i, int &j, int &n, int &m, vector<vector<char>> &map) {
    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int max_dir = 0;

    q.push({i, j, 0});
    visited[i][j] = true;

    while (!q.empty()) {
        tuple<int, int, int> p = q.front();
        q.pop();

        int x = get<0>(p);
        int y = get<1>(p);
        int dir = get<2>(p);
        max_dir = max(max_dir, dir);

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || nx >= n || 0 > ny || ny >= m) {
                continue;
            }
            if (map[nx][ny] == 'W' || visited[nx][ny]) {
                continue;
            }

            q.push({nx, ny, dir + 1});
            visited[nx][ny] = true;
        }
    }
    return max_dir;
}
int bruteForce(int &n, int &m, vector<vector<char>> &map) {
    int max_dir = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'W') {
                continue;
            }
            max_dir = max(max_dir, getDir(i, j, n, m, map));
        }
    }
    return max_dir;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    cout << bruteForce(n, m, map);

    return 0;
}