#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int STAGE = 100000;
int dp[STAGE][5][5];
int board[STAGE];
int move(int cur_pos, int next_pos) {
    if (cur_pos == next_pos) {
        return 1;
    }
    if (cur_pos == 0) {
        return 2;
    }
    if (abs(next_pos - cur_pos) != 2) {
        return 3;
    }
    return 4;
}
int calculate(int stage, int x, int y, int n) {
    if (stage >= n) {
        return 0;
    }
    if (dp[stage][x][y]) {
        return dp[stage][x][y];
    }

    int next_pos = board[stage];
    int left_move = calculate(stage + 1, next_pos, y, n) + move(x, next_pos);
    int right_move = calculate(stage + 1, x, next_pos, n) + move(y, next_pos);

    return dp[stage][x][y] = min(left_move, right_move);
}
int main() {
    int input, n;

    for (n = 0;; n++) {
        cin >> board[n];
        if (board[n] == 0) {
            break;
        }
    }

    memset(dp, 0, sizeof(dp));
    cout << calculate(0, 0, 0, n);

    return 0;
}