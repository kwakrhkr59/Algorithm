#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll getCnt(int m, vector<int> &cnt) {
    ll ans = cnt[0];
    for (int i = 0; i < m; i++) {
        ll tmp = cnt[i];
        ans += (tmp * (tmp - 1)) / 2;
    }
    return ans;
}
int main() {
    int n, m, input, sum = 0;
    cin >> n >> m;
    vector<int> cnt(m, 0);
    while (n--) {
        cin >> input;
        sum = (sum + input) % m;
        cnt[sum]++;
    }

    cout << getCnt(m, cnt);

    return 0;
}