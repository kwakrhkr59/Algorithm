#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> getPellindrome(int n, vector<int> &arr) {
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));   //dp[i][j]=i에서 j까지 pallindrome인지 여부
    for (int i = 1; i <= n; i++) {
        dp[i][i] = true;

        // 홀수 길이
        int j = i + 1, k = i - 1;
        while (j <= n && k > 0 && arr[j] == arr[k]) {
            dp[k][j] = true;    // s < e
            j++;
            k--;
        }

        // 짝수 길이
        j = i, k = i - 1;
        while (j <= n && k > 0 && arr[j] == arr[k]) {
            dp[k][j] = true;    // s < e
            j++;
            k--;
        }
    }
    return dp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, s, e;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<vector<bool>> isPellindrome = getPellindrome(n, arr);

    cin >> m;
    while (m--) {
        cin >> s >> e;
        cout << isPellindrome[s][e] << "\n";
    }
    return 0;
}