#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
struct advertise {
    int cost;
    int customer;
};
int knapsack(int c, int n, vector<advertise> &list) {
    vector<int> dp(c + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int pivot = min(c, list[i].customer);
        for (int j = 1; j < pivot; j++) {
            dp[j] = min(dp[j], list[i].cost);
        }
        for (int j = pivot; j <= c; j++) {
            dp[j] = min(dp[j], dp[j - list[i].customer] + list[i].cost);
        }
    }
    return dp[c];
}
int main() {
    int c, n;
    vector<advertise> list;

    cin >> c >> n;
    list.assign(n, {0, 0});

    for (int i = 0; i < n; i++) {
        cin >> list[i].cost >> list[i].customer;
    }

    cout << knapsack(c, n, list);

    return 0;
}
