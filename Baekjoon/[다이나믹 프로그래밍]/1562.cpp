#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000000;
int getCount(int n) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(10, vector<int>(1024, 0)));
    for (int i = 1; i < 10; i++) {
        dp[0][i][1 << i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 1024; k++) {
                if (j - 1 >= 0) {
                    dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k];
                    dp[i][j][k | (1 << j)] %= MOD;
                }
                if (j + 1 < 10) {
                    dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k];
                    dp[i][j][k | (1 << j)] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < 10; j++) {
        ans += dp[n - 1][j][1023];
        ans %= MOD;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;

    cout << getCount(n);

    return 0;
}