#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
vector<ll> arr, tree;
ll init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % MOD;
}
ll multiple(int start, int end, int left, int right, int node) {
    if (left > end || right < start) {
        return 1;
    }
    if (left <= start && right >= end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return (multiple(start, mid, left, right, node * 2) * multiple(mid + 1, end, left, right, node * 2 + 1)) % MOD;
}
void update(int start, int end, int node, int index, ll value) {
    if (index < start || index > end) {
        return;
    }
    if (start == end) {
        tree[node] = value;
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, value);
    update(mid + 1, end, node * 2 + 1, index, value);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, k, a, b, c;
    cin >> n >> m >> k;
    int height = ceil(log2(n));
    arr.assign(n, 0);
    tree.assign(1 << (height + 1), 1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    init(0, n - 1, 1);

    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            arr[b - 1] = c;
            update(0, n - 1, 1, b - 1, c);
        } else {
            cout << multiple(0, n - 1, b - 1, c - 1, 1) << "\n";
        }
    }

    return 0;
}