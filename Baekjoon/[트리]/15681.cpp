#include <iostream>
#include <vector>
using namespace std;
vector<int> leaves;
int find(int root, int cur, vector<vector<int>> &graph) {
    if (leaves[cur]) {
        return leaves[cur];
    }
    int cnt = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        int child = graph[cur][i];
        if (root == child) {
            continue;
        }
        cnt += find(cur, child, graph);
    }
    leaves[cur] = cnt;
    return cnt;
}
vector<vector<int>> makeTree(int n, int r, vector<vector<int>> &graph) {
    vector<vector<int>> tree(n + 1);
    int root = r, child;
    int cnt = n;
    while (n--) {

    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, q, v1, v2, u;
    cin >> n >> r >> q;
    vector<vector<int>> graph(n + 1);
    leaves.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    find(-1, r, graph);

    while (q--) {
        cin >> u;
        cout << leaves[u] << "\n";
    }
    return 0;
}