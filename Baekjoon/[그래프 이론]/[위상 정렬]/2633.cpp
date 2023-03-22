#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> topo_sort(int n, vector<int> &count, vector<vector<int>> &cond) {
    queue<int> q;
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) {
            q.push(i);
            result.push_back(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : cond[cur]) {
            if (--count[next] == 0) {
                q.push(next);
                result.push_back(next);
            }
        }
    }
    return result;
}
int main() {
    int n, m, i, prev, cur;
    cin >> n >> m;
    vector<int> count(n + 1, 0);
    vector<vector<int>> cond(n + 1);
    while (m--) {
        cin >> i >> prev;
        while (--i) {
            cin >> cur;
            count[cur]++;
            cond[prev].push_back(cur);
            prev = cur;
        }
    }
    vector<int> result = topo_sort(n, count, cond);
    if (result.size() != n) {
        cout << "0";
    } else {
        for (auto it : result) {
            cout << it << "\n";
        }
    }
    return 0;
}