#include <iostream>
#include <vector>
#include <queue>    //priority_queue
using namespace std;
vector<int> topo_sort(int n, vector<vector<int>> &cond, vector<int> &count) {
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) {
            pq.push(i);
        }
    }
        
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        result.push_back(cur);
        for (int next : cond[cur]) {
            if (--count[next] == 0) {
                pq.push(next);
            }
        }
    }
    return result;
}
int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> cond(n + 1);
    vector<int> count(n + 1);
    while (m--) {
        cin >> a >> b;
        count[b]++;
        cond[a].push_back(b);
    }
    vector<int> order = topo_sort(n, cond, count);
    for (int it : order) {
        cout << it << " ";
    }
    return 0;
}