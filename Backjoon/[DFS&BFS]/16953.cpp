#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> ci;
int bfs(ll a, ll b) {
    queue<ci> q;
    q.push({a, 0});
    while (!q.empty()) {
        ci prev = q.front();
        q.pop();
        if (prev.first == b) {
            return prev.second + 1;
        }

        ll cur_num = prev.first * 2;
        int cur_cnt = prev.second + 1;
        if (cur_num <= b) {
            q.push({cur_num, cur_cnt});
        }

        cur_num = prev.first * 10 + 1;
        if (cur_num <= b) {
            q.push({cur_num, cur_cnt});
        }
    }
    return -1;
}
int main() {
    ll a, b;
    cin >> a >> b;
    cout << bfs(a, b);
    return 0;
}