#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const char EXIT = 'O';
vector<vector<char>> map;
vector<vector<vector<vector<bool>>>> visited;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
pair<int, int> find(int n, int m, char color) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == color) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
bool isValid(int x, int y, int n, int m) {
    if (0 > x || x >= n || 0 > y || y >= m) {
        return false;
    }
    if (map[x][y] == '#') {
        return false;
    }
    return true;
}
vector<int> move(int rx, int ry, int bx, int by, int n, int m, int idx) {
    int rnx = rx + dx[idx];
    int rny = ry + dy[idx];
    int bnx = bx + dx[idx];
    int bny = by + dy[idx];

    int rc = 0, bc = 0;
    
    while (isValid(bnx, bny, n, m) && map[bnx][bny] != EXIT) {
        bnx += dx[idx];
        bny += dy[idx];
        bc++;
    }
    if (map[bnx][bny] == EXIT) {
        return {-1, -1, -1, -1};
    }
    bnx -= dx[idx];
    bny -= dy[idx];

    while (isValid(rnx, rny, n, m) && map[rnx][rny] != EXIT) {
        rnx += dx[idx];
        rny += dy[idx];
        rc++;
    }
    if (map[rnx][rny] == EXIT) {
        return {n, m, n, m};
    }
    rnx -= dx[idx];
    rny -= dy[idx];

    if (visited[rnx][rny][bnx][bny]) {
        return {-1, -1, -1, -1};
    }

    if (rnx == bnx && rny == bny) {
        if (rc > bc) {
            rnx -= dx[idx];
            rny -= dy[idx];
        } else {
            bnx -= dx[idx];
            bny -= dy[idx];
        }
    }

    if (!isValid(rnx, rny, n, m) || !isValid(bnx, bny, n, m) || visited[rnx][rny][bnx][bny]) {
        return {-1, -1, -1, -1};
    }
    visited[rnx][rny][bnx][bny] = true;
    return {rnx, rny, bnx, bny};
}
int bfs(int n, int m) {
    queue<vector<int>> q;

    pair<int, int> red_point = find(n, m, 'R');
    pair<int, int> blue_point = find(n, m, 'B');
    q.push({red_point.first, red_point.second, blue_point.first, blue_point.second, 0});
    visited[red_point.first][red_point.second][blue_point.first][blue_point.second] = true;

    while (!q.empty()) {
        int rx = q.front()[0];
        int ry = q.front()[1];
        int bx = q.front()[2];
        int by = q.front()[3];
        int cnt = q.front()[4] + 1;
        q.pop();

        if (cnt > 10) {
            return -1;
        }


        for (int i = 0; i < 4; i++) {
            vector<int> next = move(rx, ry, bx, by, n, m, i);
            if (next[0] == -1) {
                continue;
            }
            if (next[0] == n && next[1] == m) {
                return cnt;
            }
            q.push({next[0], next[1], next[2], next[3], cnt});
        }
    }
    return -1;
}
int main() {
    int n, m;
    cin >> n >> m;
    map.assign(n, vector<char>(m));
    visited.assign(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(n, vector<bool>(m, false))));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    cout << bfs(n, m);

    return 0;
}