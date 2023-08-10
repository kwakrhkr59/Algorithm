#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> ci;
const int MAX = 1000000000;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
ci findStart(int n, int m, vector<vector<int>> &cost) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cost[i][j] == 2) {
                return {i, j};
            }
        }
    }
}
vector<vector<int>> bfs(int n, int m, vector<vector<int>> &cost) {
    vector<vector<int>> min_cost(n, vector<int>(m, MAX));
    queue<tuple<int, int, int>> q;

    ci start = findStart(n, m, cost);
    min_cost[start.first][start.second] = 0;
    q.push({start.first, start.second, 0});

    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int c = get<2>(q.front());
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || nx >= n || 0 > ny || ny >= m || cost[nx][ny] == 0) {
                continue;
            }

            int nc = c + 1;
            if (nc < min_cost[nx][ny]) {
                min_cost[nx][ny] = nc;
                q.push({nx, ny, nc});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!cost[i][j]) {
                min_cost[i][j] = 0;
            } else if (min_cost[i][j] == MAX) {
                min_cost[i][j] = -1;
            }
        }
    }
    return min_cost;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cost(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }

    vector<vector<int>> min_cost = bfs(n, m, cost);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << min_cost[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}