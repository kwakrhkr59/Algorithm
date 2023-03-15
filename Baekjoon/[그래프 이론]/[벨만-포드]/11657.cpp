#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> ci;
typedef long long ll;
const int INF = 1000000000;
vector<ll> bellmanford(int n, vector<ci> &edge) {
    vector<ll> dist(n + 1, INF);
    dist[1] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < edge.size(); j++) {
            int from = get<0>(edge[j]);
            int to = get<1>(edge[j]);
            int weight = get<2>(edge[j]);
            if (dist[from] == INF) {
                continue;
            }
            if (dist[to] > dist[from] + weight) {
                dist[to] = dist[from] + weight;
            }
        }
    }        
    return dist;
}
int main() {
    int n, m, a, b, c;
    vector<ci> edge;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        edge.push_back({a, b, c});
    }

    vector<ll> dist = bellmanford(n, edge);

    for (int i = 0; i < edge.size(); i++) {
        int from = get<0>(edge[i]);
        int to = get<1>(edge[i]);
        int weight = get<2>(edge[i]);
        if (dist[from] == INF) {
            continue;
        }
        if (dist[to] > dist[from] + weight) {
            cout << "-1";
            return 0;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "-1\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
    return 0;
}