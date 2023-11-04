#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
typedef tuple<int, int, int> tp;
const int MAX_SIZE = 1000;
const int MAX_K = 10;
char map[MAX_SIZE][MAX_SIZE];
int visited[MAX_K + 1][MAX_SIZE][MAX_SIZE];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int bfs(int &n, int &m, int &k) {
    queue<tp> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while (!q.empty()) {
        tp cur = q.front();
        q.pop();

        int x = get<0>(cur);
        int y = get<1>(cur);
        int c = get<2>(cur);
        int dir = visited[c][x][y];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 > nx || nx >= n || 0 > ny || ny >= m || visited[c][nx][ny]) {
                continue;
            }
            
            if (map[nx][ny] == '0') {
                q.push({nx, ny, c});
                visited[c][nx][ny] = dir + 1;
            } else if (c < k && !visited[c + 1][nx][ny]) {
                q.push({nx, ny, c + 1});
                visited[c + 1][nx][ny] = dir + 1;
            }
        }
    }

    int ans = MAX_SIZE * MAX_SIZE;
    for (int c = 0; c <= k; c++) {
        if (visited[c][n - 1][m - 1]) {
            ans = min(ans, visited[c][n - 1][m - 1]);
        }
    }
    return (ans != MAX_SIZE * MAX_SIZE) ? ans : -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    memset(map, 0, sizeof(map));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    cout << bfs(n, m, k);
    return 0;
}