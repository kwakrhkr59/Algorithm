#include <iostream>
#include <vector>
using namespace std;
void dfs(int &node, vector<vector<int>> &graph, vector<int> &visited) {
    for (int next_node : graph[node]) {
        if (visited[next_node]) {
            continue;
        }
        visited[next_node] = -visited[node];
        dfs(next_node, graph, visited);
    }
}
bool isBipartite(int &v, vector<vector<int>> &graph) {
    vector<int> visited(v + 1, 0);
    for (int u = 1; u <= v; u++) {
        if (visited[u]) {
            continue;
        }
        visited[u] = 1;
        dfs(u, graph, visited);
    }

    for (int u = 1; u <= v; u++) {
        if (!visited[u]) {
            return false;
        }
        for (int w : graph[u]) {
            if (visited[u] == visited[w]) {
                return false;
            }
        }
    }

    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, v, e, u, w;
    vector<vector<int>> graph;

    cin >> k;
    while (k--) {
        cin >> v >> e;
        graph.assign(v + 1, vector<int>());

        while (e--) {
            cin >> u >> w;
            graph[u].push_back(w);
            graph[w].push_back(u);
        }

        cout << (isBipartite(v, graph) ? "YES\n" : "NO\n");
    }

    return 0;
}