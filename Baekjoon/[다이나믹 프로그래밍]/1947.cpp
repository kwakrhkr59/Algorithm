#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1000000000;
ll comb(ll n) {
    if (n <= 2) {
        return n - 1;
    }
    vector<ll> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
        dp[i] %= MOD;
    }

    return dp[n];
}
int main() {
    ll n;
    cin >> n;
    cout << comb(n);
    return 0;
}
