#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100;
const int INF = 1000000000;
int operand[MAX];
int operator_cnt[4];
int max_value = -INF, min_value = INF;
int calculate(int n, vector<int> &operator_order) {
    int ans = operand[0];
    for (int i = 1; i < n; i++) {
        switch (operator_order[i - 1]) {
            case 0:
                ans += operand[i];
                break;
            case 1:
                ans -= operand[i];
                break;
            case 2:
                ans *= operand[i];
                break;
            case 3:
                ans /= operand[i];
                break;
        }
    }
    return ans;
}
void backtracking(int cnt, int n, vector<int> &operator_order) {
    if (cnt == n - 1) {
        int ans = calculate(n, operator_order);
        max_value = max(max_value, ans);
        min_value = min(min_value, ans);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (operator_cnt[i] <= 0) {
            continue;
        }
        operator_cnt[i]--;
        operator_order.push_back(i);
        backtracking(cnt + 1, n, operator_order);
        operator_order.pop_back();
        operator_cnt[i]++;
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> operand[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> operator_cnt[i];
    }
    vector<int> operator_order;
    backtracking(0, n, operator_order);
    cout << max_value << "\n"
         << min_value;
    return 0;
}