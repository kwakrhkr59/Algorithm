#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> arr, tree;
int init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = 1;
    }
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
int query(int key, int start, int end, int node) {
    tree[node]--;
    if (start == end) {
        return start;
    }
    int mid = (start + end) / 2;
    if (tree[node * 2] > key) {
        return query(key, start, mid, node * 2);
    }
    return query(key - tree[node * 2], mid + 1, end, node * 2 + 1);
}
vector<int> solution(int n) {
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        int j = query(arr[i], 0, n - 1, 1);
        ans[j] = i + 1;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int height = ceil(log2(n));
    arr.assign(n, 0);
    tree.assign(1 << (height + 1), 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    init(0, n - 1, 1);
    vector<int> ans = solution(n);
    for (auto it : ans) {
        cout << it << "\n";
    }
    return 0;
}