#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> topo_sort(int n, vector<vector<int>> &cond, vector<int> &count) {
    vector<int> semester(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) {
            semester[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < cond[cur].size(); i++) {
            int next = cond[cur][i];
            if (--count[next] == 0) {
                semester[next] = semester[cur] + 1;
                q.push(next);
            }
        }
    }
    return semester;
}
int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> cond(n + 1);
    vector<int> count(n + 1, 0);
    while (m--) {
        cin >> a >> b;
        cond[a].push_back(b);
        count[b]++;
    }

    vector<int> semester = topo_sort(n, cond, count);
    for (int i = 1; i <= n; i++) {
        cout << semester[i] << " ";
    }
    return 0;
}