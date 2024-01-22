#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> topo_sort(int &n, vector<vector<int>> &next, vector<int> &count) {
    vector<int> ans;
    vector<int> order(n + 1, 0);
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) {
            q.push(i);
            order[i] = 1;
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for (int y : next[x]) {
            order[y] = max(order[y], order[x] + 1);
            if ((--count[y]) == 0) {
                q.push(y);
            }
        }
    }

    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (visited[order[i]]) {
            ans.push_back(1);
            return ans;
        }
        visited[order[i]] = true;
    }
    ans.push_back(0);
    return ans;
}
int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> next(n + 1);
    vector<int> count(n + 1, 0);
    while(m--) {
        cin >> a >> b;
        next[a].push_back(b);
        count[b]++;
    }
    vector<int> ans = topo_sort(n, next, count);
    for (int it : ans) {
        cout << it << "\n";
    }
    return 0;
}