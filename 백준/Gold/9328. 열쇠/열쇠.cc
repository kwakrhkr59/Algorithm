#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<char>> map;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> doors;
queue<pair<int, int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool isValid(int x, int y, int h, int w, int &key) {
    if (0 > x || x >= h || 0 > y || y >= w || visited[x][y] || map[x][y] == '*') {
        return false;
    }
    if (map[x][y] == '.' || map[x][y] == '$') {
        return true;
    }
    if ('a' <= map[x][y] && map[x][y] <= 'z') {
        if (key & (1 << (map[x][y] - 'A'))) {
            return true;
        }
        key = key | (1 << (map[x][y] - 'a'));
        for (auto point : doors[map[x][y] - 'a']) {
            q.push(point);
        }
        return true;
    }
    if (key & (1 << (map[x][y] - 'A'))) {
        return true;
    }
    for (auto point : doors[map[x][y] - 'A']) {
        if (point.first == x && point.second == y) {
            return false;
        }
    }
    doors[map[x][y] - 'A'].push_back({x, y});
    return false;
}
void update(int x, int y, int &cnt) {
    visited[x][y] = true;
    q.push({x, y});
    if (map[x][y] == '$') {
        map[x][y] = '.';
        cnt++;
    }
}
void init(int h, int w, int &key, int &cnt) {
    for (int i = 0; i < h; i++) {
        if (isValid(i, 0, h, w, key)) update(i, 0, cnt);
        if (isValid(i, w - 1, h, w, key)) update(i, w - 1, cnt);
    }
    for (int j = 1; j < w - 1; j++) {
        if (isValid(0, j, h, w, key)) update(0, j, cnt);
        if (isValid(h - 1, j, h, w, key)) update(h - 1, j, cnt);
    }
}
int bfs(int h, int w, string init_key) {
    int key = 0, cnt = 0;
    for (char ch : init_key) {
        key += 1 << (ch - 'a');
    }
    init(h, w, key, cnt);

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny, h, w, key)) update(nx, ny, cnt);
        }
    }
    return cnt;
}
int main() {
    int t, h, w;
    string init_key;

    cin >> t;
    while (t--) {
        cin >> h >>w;
        map.assign(h, vector<char>(w));
        visited.assign(h, vector<bool>(w, false));
        doors.assign(26, vector<pair<int, int>>());
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
        cin >> init_key;
        if (init_key == "0") {
            init_key = "";
        }

        cout << bfs(h, w, init_key) << "\n";
    }

    return 0;
}