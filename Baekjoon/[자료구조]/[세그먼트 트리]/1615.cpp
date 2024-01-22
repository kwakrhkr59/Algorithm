#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int> arr;
vector<ll> tree;
vector<vector<int>> graph;
ll init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
ll query(int start, int end, int left, int right, int node) {
    if (right < start || end < left) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(start, mid, left, right, node * 2) + query(mid + 1, end, left, right, node * 2 + 1);
}
void update(int start, int end, int idx, int node) {
    if (idx < start || end < idx) {
        return;
    }
    tree[node]--;
    if (start == end) {
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, idx, node * 2);
    update(mid + 1, end, idx, node * 2 + 1);
}
ll solution(int n, int m) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
        for (auto j : graph[i]) {
            ans += query(0, n - 1, 0, j - 1, 1);
            update(0, n - 1, j, 1);
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i, j;
    cin >> n >> m;

    int height = ceil(log2(n));
    arr.assign(n, 0);
    graph.assign(n, vector<int>());
    tree.assign(1 << (height + 1), 0);

    while (m--) {
        cin >> i >> j;
        graph[i - 1].push_back(j - 1);
        arr[j - 1]++;
    }

    init(0, n - 1, 1);
    cout << solution(n, m);

    return 0;
}