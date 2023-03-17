#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>    //sort()
using namespace std;
typedef long long ll;
const int MAX = 100000;
int parent[MAX + 1];
bool cmp(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
    return get<2>(a) < get<2>(b);
}
int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}
bool sameParent(int x, int y) {
    if (find(x) == find(y)) {
        return true;
    }
    return false;
}
void uni(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
}
void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}
bool isConnected(int n) {
    for (int i = 2; i <= n; i++) {
        if (!sameParent(i - 1, i)) {
            return false;
        }
    }
    return true;
}
ll kruskal(int n, vector<tuple<int, int, int>> &graph) {
    ll total = 0;
    sort(graph.begin(), graph.end(), cmp);
    init(n);

    for (int i = 0; i < graph.size(); i++) {
        int a = get<0>(graph[i]);
        int b = get<1>(graph[i]);
        int c = get<2>(graph[i]);
        if (sameParent(a, b)) {
            total += c;
            continue;
        }
        uni(a, b);
    }
    return (isConnected(n)) ? total : -1;
}
int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    vector<tuple<int, int, int>> graph(n + 1);
    while (m--) {
        cin >> a >> b >> c;
        graph.push_back({a, b, c});
    }
    cout << kruskal(n, graph);

    return 0;
}