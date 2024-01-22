#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
vector<ll> getMultiplier(int n) {
    vector<ll> multiplier(n, 0);
    ll m = 1;

    for (int i = 0; i < n; i++) {
        multiplier[i] = m - 1;
        m *= 2;
        m %= MOD;
    }

    return multiplier;
}
ll solution(int n, vector<int> &arr) {
    ll ans = 0;
    vector<ll> multiplier = getMultiplier(n);

    for (int i = 0; i < n; i++) {
        int left = i;
        int right = n - i - 1;
        ans += multiplier[i] * (arr[left] - arr[right]);
        ans %= MOD;
    }
    return ans;
}
int main() {
    int n;
    vector<int> arr;

    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << solution(n, arr);

    return 0;
}