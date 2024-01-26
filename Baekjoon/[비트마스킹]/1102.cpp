#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e9;
void dfs(int cnt, int state, vector<int> &dp, int &min_value, int &n, int &p, vector<vector<int>> &cost) {
    if (cnt++ == p) {
        min_value = min(min_value, dp[state]);
        return;
    }
    for (int i = 0; i < n; i++) {\
        if (!(state & (1 << i))) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (state & (1 << j)) {
                continue;
            }
            int next_state = state | (1 << j);
            int next_cost = dp[state] + cost[i][j];
            if (next_cost < dp[next_state]) {
                dp[next_state] = next_cost;
                dfs(cnt, next_state, dp, min_value, n, p, cost);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, p, cnt = 0, state = 0;
    vector<vector<int>> cost;
    char on;

    cin >> n;
    cost.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> on;
        if (on == 'Y') {
            state |= 1 << i;
            cnt++;
        }
    }
    cin >> p;

    int min_value = MAX;
    vector<int> dp(1 << (n + 1), MAX);
    dp[state] = 0;
    dfs(cnt, state, dp, min_value, n, p, cost);

    if (cnt >= p) {
        cout << 0;
    } else if (min_value == MAX) {
        cout << -1;
    } else {
        cout << min_value;
    }

    return 0;
}