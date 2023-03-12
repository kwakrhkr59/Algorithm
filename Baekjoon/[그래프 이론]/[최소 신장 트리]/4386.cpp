#include <iostream>
#include <vector>
#include <tuple>
#include <math.h>
#include <algorithm> //sort()
using namespace std;
typedef pair<float, float> point;
typedef tuple<int, int, float> edge;
const int MAX = 100;
int parent[MAX];
int cmp(const edge &a, const edge &b) {
    return get<2>(a) < get<2>(b);
}
int find(int a) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = find(parent[a]);
}
void uni(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}
bool sameParent(int a, int b) {
    if (find(a) == find(b)) {
        return true;
    }
    return false;
}
float kruskal(int n, vector<edge> &graph) {
    float result = 0;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < graph.size(); i++) {
        int u = get<0>(graph[i]);
        int v = get<1>(graph[i]);
        float w = get<2>(graph[i]);
        if (sameParent(u, v)) {
            continue;
        }
        uni(u, v);
        result += w;
    }
    return result;
}
float connect(point &a, point &b) {
    int x_squared = (a.first - b.first) * (a.first - b.first);
    int y_squared = (a.second - b.second) * (a.second - b.second);
    return sqrt(x_squared + y_squared);
}
vector<edge> connectAll(vector<point> &stars) {
    vector<tuple<int, int, float>> graph;
    for (int i = 0; i < stars.size(); i++) {
        for (int j = i + 1; j < stars.size(); j++) {
            graph.push_back({i, j, connect(stars[i], stars[j])});
        }
    }
    return graph;
}
int main() {
    int n;
    float x, y;
    cin >> n;
    vector<point> stars(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        stars[i] = {x, y};
    }
    vector<edge> graph = connectAll(stars);
    sort(graph.begin(), graph.end(), cmp);

    cout << fixed;
    cout.precision(2);
    cout << kruskal(n, graph);

    return 0;
}