#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = INF;
    int len = info.size();
    
    vector<vector<int>> dp(len, vector<int>(m, INF));    
    if (info[0][0] < n) dp[0][0] = info[0][0];
    if (info[0][1] < m) dp[0][info[0][1]] = 0;
    
    for (int i = 1; i < len; i++) {
        int a = info[i][0];
        int b = info[i][1];
        for (int j = 0; j < m; j++) {
            if (dp[i - 1][j] == INF) {
                continue;
            }
            // Case1: b 선택
            if (j + b < m) {
                dp[i][j + b] = min(dp[i][j + b], dp[i - 1][j]);
            }
            // Case2: a 선택
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a);
        }
    }
        
    for (int j = 0; j < m; j++) {
        answer = min(answer, dp[len-1][j]);
    }
    if (answer >= n) {
        answer = -1;
    }
    return answer;
}
