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
int getItems(int n, int m, vector<int> &dist, vector<int> &items) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] <= m) {
            total += items[i];
        }
    }
    return total;
}
int getMaximum(int n, int m, vector<int> &items, vector<vector<ci>> &graph) {
    vector<vector<int>> dist_all(n + 1);
    for (int i = 1; i <= n; i++) {
        dist_all[i] = dijkstra(n, i, graph);
    }

    int max_items = 0;
    for (int i = 1; i <= n; i++) {
        max_items = max(max_items, getItems(n, m, dist_all[i], items));
    }
    return max_items;
}
int main() {
    int n, m, r, a, b, l;
    cin >> n >> m >> r;
    vector<int> items(n + 1);
    vector<vector<ci>> graph(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }
        
    while (r--) {
        cin >> a >> b >> l;
        graph[a].push_back({l, b});
        graph[b].push_back({l, a});
    }

    cout << getMaximum(n, m, items, graph);
    return 0;
}