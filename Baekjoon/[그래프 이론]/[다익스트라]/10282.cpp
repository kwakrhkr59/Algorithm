#include <iostream>
#include <vector>
#include <queue> //priority_queue
using namespace std;
typedef pair<int, int> ci;
const int INF = 1000000000;
ci count(int n, vector<int> &dist) {
    int infect_cnt = 0, infect_time = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            continue;
        }
        infect_cnt++;
        infect_time = max(infect_time, dist[i]);
    }
    return {infect_cnt, infect_time};
}
ci dijkstra(int n, int c, vector<vector<ci>> &graph) {
    vector<int> dist(n + 1, INF);
    priority_queue<ci> pq;

    pq.push({c, 0});
    dist[c] = 0;

    while (!pq.empty()) {
        int cur = pq.top().first;
        int weight = pq.top().second;
        pq.pop();
        if (weight > dist[cur]) {
            continue;
        }
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int next_weight = graph[cur][i].second + weight;
            if (dist[next] > next_weight) {
                dist[next] = next_weight;
                pq.push({next, next_weight});
            }
        }
    }
    return count(n, dist);
}
int main() {
    int t, n, d, c, a, b, s;
    cin >> t;
    while (t--) {
        cin >> n >> d >> c;
        vector<vector<ci>> graph(n + 1);
        while (d--) {
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }
        ci ans = dijkstra(n, c, graph);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}