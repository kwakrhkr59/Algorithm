#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> topo_sort(int n, vector<vector<bool>> &cond, vector<int> &count) {
    vector<int> result;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) {
            q.push(i);
            result.push_back(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next = 1; next <= n; next++) {
            if (cond[cur][next] && --count[next] == 0) {
                q.push(next);
                result.push_back(next);
            }
        }
    }
    return result;
}
int main() {
    int t, n, m, a, b;
    vector<vector<bool>> cond;
    vector<int> count, order;
    cin >> t;
    while (t--) {
        cin >> n;
        cond.assign(n + 1, vector<bool>(n + 1, false));
        count.assign(n + 1, 0);
        order.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> order[i];
            count[order[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cond[order[i]][order[j]] = true;
            }
        }
        cin >> m;
        while (m--) {
            cin >> a >> b;
            if (cond[a][b]) {
                count[a]++;
                count[b]--;
            } else {
                count[a]--;
                count[b]++;
            }
            cond[a][b] = !cond[a][b];
            cond[b][a] = !cond[b][a];
        }

        vector<int> result = topo_sort(n, cond, count);
        if (result.size() != n) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        for (int it : result) {
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}