#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp;
vector<bool> visited;
void dfs(int parent, vector<vector<int>> &tree) {
    visited[parent] = true;
    dp[parent][0] = 1;
    for (int child : tree[parent]) {
        if (visited[child]) {
            continue;
        }
        dfs(child, tree);
        dp[parent][0] += min(dp[child][0], dp[child][1]);
        dp[parent][1] += dp[child][0];
    }
}
int main() {
    int n, u, v;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    dp.assign(n + 1, vector<int>(2, 0));
    visited.assign(n + 1, false);
    while (--n) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, tree);

    cout << min(dp[1][0], dp[1][1]);

    return 0;
}