#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000000;
ll comb(ll n) {
    if (n <= 2) {
        return n - 1;
    }
    ll prev1 = 1;
    ll prev2 = 0;
    ll ans;
    int idx = 2;
    while (idx++ < n) {
        ans = (idx - 1) * (prev1 + prev2);
        ans %= MOD;
        prev2 = prev1;
        prev1 = ans;
    }

    return ans;
}
int main() {
    ll n;
    cin >> n;
    cout << comb(n);
    return 0;
}
