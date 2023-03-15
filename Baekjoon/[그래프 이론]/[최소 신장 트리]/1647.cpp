#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm> //sort()
using namespace std;
const int MAX = 100000;
int parent[MAX + 1];
int cmp(const tuple<int, int ,int> &x, const tuple<int, int ,int> &y) {
    return get<2>(x) < get<2>(y);
}
int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
}
bool sameParent(int x, int y) {
    if (find(x) == find(y)) {
        return true;
    }
    return false;
}
int kruskal(int n, vector<tuple<int, int, int>> &graph) {
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < graph.size(); i++) {
        int u = get<0>(graph[i]);
        int v = get<1>(graph[i]);
        int w = get<2>(graph[i]);
        if (sameParent(u, v)) {
            continue;
        }
        uni(u, v);
        result.push_back(w);
    }
    sort(result.begin(), result.end());
    int ans = 0;
    for (int i = 0; i < result.size() - 1; i++) {
        ans += result[i];
    }
    return ans;
}
int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    vector<tuple<int, int ,int>> graph;
    while (m--) {
        cin >> a >> b >> c;
        graph.push_back({a, b, c});
    }
    sort(graph.begin(), graph.end(), cmp);
    cout << kruskal(n, graph);

    return 0;
}