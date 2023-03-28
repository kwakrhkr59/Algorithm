#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int topo_sort(int n, vector<vector<int>> &cond, vector<int> &count, vector<int> &time) {
    vector<int> dp(n + 1, 0);
    queue<int> q;
    int max_value = 0;
    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) {
            dp[i] = time[i];
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < cond[cur].size(); i++) {
            int next = cond[cur][i];
            dp[next] = max(dp[next], dp[cur] + time[next]);
            if (--count[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        max_value = max(max_value, dp[i]);
    }
    return max_value;
}
int main() {
    int n, pre;
    cin >> n;
    vector<vector<int>> cond(n + 1);
    vector<int> count(n + 1, 0), time(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> time[i] >> count[i];
        for (int j = 0; j < count[i]; j++) {
            cin >> pre;
            cond[pre].push_back(i);
        }
    }

    cout << topo_sort(n, cond, count, time);
    return 0;
}