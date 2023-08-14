#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, int> cnt;
void left(int idx, int sum, const int n, vector<int> &arr) {
    if (idx == n / 2) {
        cnt[sum]++;
        return;
    }
    left(idx + 1, sum, n, arr);
    left(idx + 1, sum + arr[idx], n, arr);
}
void right(int idx, int sum, long long &ans, const int n, const int s, vector<int> &arr) {
    if (idx == n) {
        ans += cnt[s - sum];
        return;
    }
    right(idx + 1, sum, ans, n, s, arr);
    right(idx + 1, sum + arr[idx], ans, n, s, arr);
}
int main() {
    int n, s;
    long long ans = 0;
    vector<int> arr;

    cin >> n >> s; arr.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];

    left(0, 0, n, arr);
    right(n / 2, 0, ans, n, s, arr);

    if (s == 0) {
        ans--;
    }

    cout << ans;

    return 0;
}