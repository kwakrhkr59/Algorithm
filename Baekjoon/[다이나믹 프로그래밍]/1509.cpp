#include <iostream>
#include <vector>
using namespace std;
const int MAX = 2501;
vector<vector<bool>> getPallindrome(string &w) {
    int len = w.size();
    vector<vector<bool>> isPellindrome(len + 1, vector<bool>(len + 1, false));
    for (int mid = 0; mid < len; mid++) {
        isPellindrome[mid + 1][mid + 1] = true;
        //홀수
        int left = mid - 1, right = mid + 1;
        while (left >= 0 && right < len && w[left] == w[right]) {
            isPellindrome[left + 1][right + 1] = true;
            left--;
            right++;
        }

        //짝수
        left = mid, right = mid + 1;
        while (left >= 0 && right < len && w[left] == w[right]) {
            isPellindrome[left + 1][right + 1] = true;
            left--;
            right++;
        }
    }
    return isPellindrome;
}
int partition(string &w) {
    vector<vector<bool>> isPellindrome = getPallindrome(w);
    vector<int> cnt(w.size() + 1, MAX);

    cnt[0] = 0;
    cnt[1] = 1;
    for (int i = 2; i <= w.size(); i++) {
        for (int j = 1; j <= i; j++) {
            if (!isPellindrome[j][i]) {
                continue;
            }
            cnt[i] = min(cnt[i], cnt[j - 1] + 1);
        }
    }
    return cnt[w.size()];
}
int main() {
    string w;
    cin >> w;

    cout << partition(w);
    return 0;
}