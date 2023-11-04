#include <iostream>
#include <vector>
using namespace std;
int solve(int n, vector<int> &a) {
    int total = a[0];
    for (int i = 1; i < n; i++) {
        total ^= a[i];
    }

    for (int i = 0; i < n; i++) {
        if (total ^ a[i] == a[i]) {
            return a[i];
        }
    }

    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    vector<int> a;

    cin >> t;
    while (t--) {
        cin >> n;
        a.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(n, a) << "\n";
    }

    return 0;
}{\rtf1}