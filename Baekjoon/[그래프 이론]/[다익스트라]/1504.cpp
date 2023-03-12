#include <iostream>
#include <vector>
#include <queue> //priority_queue
using namespace std;
typedef pair<int, int> ci;
const int INF = 1000000000;
vector<int> dijkstra(int n, int start, vector<vector<ci>> &graph) {
    priority_queue<ci, vector<ci>, greater<ci>> pq;
    vector<int> dist(n + 1, INF);
    dist[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        int cur = pq.top().first;
        pq.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int next_weight = dist[cur] + graph[cur][i].second;
            if (dist[next] > next_weight) {
                dist[next] = next_weight;
                pq.push({next, next_weight});
            }
        }
    }
    return dist;
}
int minLen(int n, int u, int v, vector<vector<ci>> &graph) {
    int min_value;
    vector<int> dist_s = dijkstra(n, 1, graph);
    vector<int> dist_u = dijkstra(n, u, graph);
    vector<int> dist_v = dijkstra(n, v, graph);
    int s_to_u = dist_s[u];
    int s_to_v = dist_s[v];
    int u_to_v = dist_u[v];
    int u_to_n = dist_u[n];
    int v_to_n = dist_v[n];
    min_value = min(s_to_u + u_to_v + v_to_n, s_to_v + u_to_v + u_to_n);
    if (u_to_v >= INF || min_value >= INF) {
        return -1;
    }
    return min_value;
}
int main() {
    int n, e, v1, v2, t, u, v;
    cin >> n >> e;
    vector<vector<ci>> graph(n + 1);
    while (e--) {
        cin >> v1 >> v2 >> t;
        graph[v1].push_back({v2, t});
        graph[v2].push_back({v1, t});
    }
    cin >> u >> v;

    cout << minLen(n, u, v, graph);
    return 0;
}