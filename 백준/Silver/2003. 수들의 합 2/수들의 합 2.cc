#include <iostream>
#include <vector>
using namespace std;
int getCnt(int n, int m, vector<int> &arr) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] - arr[j] == m) {
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    cout << getCnt(n, m, arr);

    return 0;
}