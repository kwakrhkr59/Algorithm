#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> topo_sort(int n, vector<vector<int>> &cond, vector<int> &count, vector<int> &time) {
    vector<int> dp(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (count[i]) {
            continue;
        }
        dp[i] = time[i];
        q.push(i);
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
    return dp;
}
int main() {
    int n, pre;
    cin >> n;
    vector<vector<int>> cond(n + 1);
    vector<int> count(n + 1, 0);
    vector<int> time(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> time[i];
        while (1) {
            cin >> pre;
            if (pre == -1) {
                break;
            }
            cond[pre].push_back(i);
            count[i]++;
        }
    }

    vector<int> dp = topo_sort(n, cond, count, time);
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << "\n";
    }
    return 0;
}