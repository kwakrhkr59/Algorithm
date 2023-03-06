#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<bool> getNumbers(ll min_range, ll max_range) {
    ll range = max_range - min_range + 1;
    vector<bool> isPrime(range, false);
    for (ll i = 2; i * i <= max_range; i++) {
        ll start = (min_range / (i * i)) * i * i;
        if (start != min_range) {
            start += i * i;
        }

        for (ll j = start; j <= max_range; j += i * i) {
            isPrime[j - min_range] = true;
        }
    }
    return isPrime;
}
int getCount(ll min_range, ll max_range) {
    vector<bool> isPrime = getNumbers(min_range, max_range);
    int cnt = 0;
    for (ll i = 0; i <= max_range - min_range; i++) {
        if (!isPrime[i]) {
            cnt++;
        }
    }
    return cnt;
}
int main() {
    ll min_range, max_range;
    cin >> min_range >> max_range;
    cout << getCount(min_range, max_range);
    return 0;
}