#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 60;
vector<ll> getCandidates() {
    vector<ll> candidates;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j <= i; j++) {
            ll value = ((ll)1 << i) + ((ll)1 << j);
            candidates.push_back(value);
        }
    }
    return candidates;
}
ll binarySearch(ll num, vector<ll> candidates) {
    int left = 0, right = candidates.size() - 1;
    if (num == candidates[left]) {
        return candidates[left];
    }
    if (num == candidates[right]) {
        return candidates[right];
    }
    while (left < right) {
        int mid = (left + right) / 2;
        if (candidates[mid] == num) {
            return candidates[mid];
        }
        if (candidates[mid] < num) {
            if (num > candidates[mid + 1]) {
                left = mid + 1;
                continue;
            }
            if (num - candidates[mid] <= candidates[mid + 1] - num) {
                return candidates[mid];
            }
            return candidates[mid + 1];
        } else {
            right = mid;
        }
    }
    return candidates[left];
}
pair<int, int> getPair(ll num) {
    int x, y;
    for (int i = 1; i < MAX; i++) {
        if (num == (ll)1 << i) {
            return {i - 1, i - 1};
        }
        if (num < (ll)1 << i) {
            break;
        }
    }
    for (x = 0; x < MAX; x++) {
        if (num & ((ll)1 << x)) {
            num -= (ll)1 << x;
            break;
        }
    }
    for (y = x; y < MAX; y++) {
        if (num & ((ll)1 << y)) {
            break;
        }
    }
    return {x, y};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    ll m;
    vector<ll> candidates = getCandidates();

    cin >> n;
    while (n--) {
        cin >> m;
        pair<int, int> ans = getPair(binarySearch(m, candidates));
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}