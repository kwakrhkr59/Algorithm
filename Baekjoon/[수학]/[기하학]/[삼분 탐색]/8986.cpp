#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll getSum(vector<int> &x, int &n, int &interval) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs((ll)(interval)*i - x[i]);
    }
    return sum;
}
void ternarySearch(vector<int> &x, int &n, int &lo, int &hi) {
    if (hi - lo <= 3) {
        return;
    }

    int p = (lo * 2ll + hi) / 3;
    int q = (lo + hi * 2ll) / 3;
    if (getSum(x, n, p) < getSum(x, n, q)) {
        hi = q;
    } else {
        lo = p;
    }
    ternarySearch(x, n, lo, hi);
}
ll solution(vector<int> &x, int &n) {
    int lo = 0, hi = 1 << 30;
    ll ans = 1ll << 62;

    ternarySearch(x, n, lo, hi);

    for (int i = lo; i <= hi; i++) {
        ans = min(ans, getSum(x, n, i));
    }

    return ans;
}
int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << solution(x, n);

    return 0;
}