#include <iostream>
using namespace std;
typedef long long ll;
const int MAX = 54;
ll dp[MAX + 1]; // dp[n]: 1부터 2^n까지의 1의 개수
void init() {
    dp[0] = 1;
    for (int i = 0; i < MAX; i++) {
        dp[i + 1] = dp[i] * 2 + ((ll)1 << i) - 1;
    }
}
ll getSum(ll n) {
    ll sum = 0;
    for (int i = MAX; i >= 0 && n > 0; i--) {
        if (n & ((ll)1 << i)) {
            sum += dp[i] + (n - ((ll)1 << i));
            n -= (ll)1 << i;
        }
    }
    return sum;
}
int main() {
    ll a, b;
    cin >> a >> b;
    init();

    cout << getSum(b) - getSum(a - 1);

    return 0;
}