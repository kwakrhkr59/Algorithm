#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int bfs(int &w, int &h, int &sx, int &sy, int &cnt, vector<vector<char>> &map) {
    int ans = INF;
    queue<vector<int>> q;
    vector<vector<vector<int>>> dp(h, vector<vector<int>>(w, vector<int>(1 << 10, INF)));

    q.push({sx, sy, 0});
    dp[sx][sy][0] = 0;

    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int c = q.front()[2];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || nx >= h || 0 > ny || ny >= w) {
                continue;
            }
            if (map[nx][ny] == 'x') {
                continue;
            }

            int nc = c;
            if (map[nx][ny] != '.') {
                nc = c | (1 << map[nx][ny]);
            }

            if (dp[nx][ny][nc] <= dp[x][y][c] + 1) {
                continue;
            }

            if (nc == (1 << cnt) - 1) {
                ans = min(ans, dp[x][y][c] + 1);
                continue;
            }
            
            q.push({nx, ny, nc});
            dp[nx][ny][nc] = dp[x][y][c] + 1;
        }
    }

    return (ans == INF) ? -1 : ans;
}
int main() {
    int w, h, sx, sy, idx;
    vector<vector<char>> map;

    while (true) {
        cin >> w >> h;
        if (!w) {
            break;
        }

        idx = 0;
        map.assign(h, vector<char>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
                if (map[i][j] == 'o') {
                    sx = i;
                    sy = j;
                    map[i][j] = '.';
                } else if (map[i][j] == '*') {
                    map[i][j] = (char)(idx++);
                }
            }
        }

        cout << bfs(w, h, sx, sy, idx, map) << "\n";
    }

    return 0;
}