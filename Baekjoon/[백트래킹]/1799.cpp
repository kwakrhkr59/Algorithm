#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ci;
bool check(int &x, int &y, int &diag_flag1, int &diag_flag2, int &n) {
    // 왼쪽 아래 대각선(/)
    int flag1 = 1 << (x + y);
    if (diag_flag1 & flag1) {
        return false;
    }

    // 오른쪽 아래 대각선(\)
    int flag2 = 1 << (x - y + n - 1);
    if (diag_flag2 & flag2) {
        return false;
    }

    diag_flag1 |= flag1;
    diag_flag2 |= flag2;
    return true;
}
void backtracking(int index, int cnt, int diag_flag1, int diag_flag2, int &max_cnt, int &n, vector<ci> &candidate) {
    if (index == candidate.size()) {
        max_cnt = max(max_cnt, cnt);
        return;
    }
    int x = candidate[index].first;
    int y = candidate[index].second;

    backtracking(index + 1, cnt, diag_flag1, diag_flag2, max_cnt, n, candidate);
    if (!check(x, y, diag_flag1, diag_flag2, n)) {
        return;
    }
    backtracking(index + 1, cnt + 1, diag_flag1, diag_flag2, max_cnt, n, candidate);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, input;
    vector<ci> black, white;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input;
            if (!input) {
                continue;
            }

            if ((i + j) % 2) {
                black.push_back({i, j});
            } else {
                white.push_back({i, j});
            }
        }
    }

    int black_cnt = 0, white_cnt = 0;
    backtracking(0, 0, 0, 0, black_cnt, n, black);
    backtracking(0, 0, 0, 0, white_cnt, n, white);

    cout << black_cnt + white_cnt;
    return 0;
}