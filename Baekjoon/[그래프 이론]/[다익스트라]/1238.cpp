#include <iostream>
#include <vector>
#include <queue>    //priority_queue
using namespace std;
typedef pair<int, int> ci;
const int INF = 1000000000;
vector<int> dijkstra(int n, int start, vector<vector<ci>> &graph) {
    vector<int> dist(n + 1, INF);
    priority_queue<ci> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int cur = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if (dist[cur] < weight) {
            continue;
        }
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].second;
            int next_weight = weight + graph[cur][i].first;
            if (dist[next] > next_weight) {
                dist[next] = next_weight;
                pq.push({next_weight, next});
            }
        }
    }
    return dist;
}
int solution(int n, int x, vector<vector<ci>> &incoming, vector<vector<ci>> &outgoing) {
    vector<int> dist1 = dijkstra(n, x, incoming);
    vector<int> dist2 = dijkstra(n, x, outgoing);
    int max_value = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = dist1[i] + dist2[i];
        max_value = max(max_value, tmp);
    }
    return max_value;
}
int main() {
    int n, m, x, u, v, w;
    cin >> n >> m >> x;
    vector<vector<ci>> incoming(n + 1), outgoing(n + 1);
    while (m--) {
        cin >> u >> v >> w;
        incoming[u].push_back({w, v});
        outgoing[v].push_back({w, u});
    }

    cout << solution(n, x, incoming, outgoing);
    return 0;
}