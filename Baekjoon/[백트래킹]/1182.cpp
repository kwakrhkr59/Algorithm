#include <iostream>
#include <vector>
using namespace std;
void backtracking(int idx, int sum, int &cnt, const int n, const int s, vector<int> &arr) {
    if (idx == n) {
        if (sum == s) {
            cnt++;
        }
        return;
    }
    backtracking(idx + 1, sum, cnt, n, s, arr);
    backtracking(idx + 1, sum + arr[idx], cnt, n, s, arr);
}
int main() {
    int n, s, cnt = 0;
    vector<int> arr;

    cin >> n >> s; arr.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];

    backtracking(0, 0, cnt, n, s, arr);
    if (s == 0) {
        cnt--;
    }

    cout << cnt;

    return 0;
}