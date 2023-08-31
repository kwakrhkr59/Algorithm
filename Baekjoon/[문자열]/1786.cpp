#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> getPi(string p) {
    int m = p.size();
    vector<int> pi(m, 0);

    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            pi[i] = ++j;
        }
    }

    return pi;
}
vector<int> kmp(string t, string p) {
    vector<int> ans;
    vector<int> pi = getPi(p);
    int n = t.size();
    int m = p.size();

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && t[i] != p[j]) {
            j = pi[j - 1];
        }
        if (t[i] == p[j]) {
            if (j == m - 1) {
                ans.push_back(i - j + 1);
                j = pi[j];
            } else {
                j++;
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string t, p;
    getline(cin, t);
    getline(cin, p);

    vector<int> ans = kmp(t, p);
    cout << ans.size() << "\n";
    for (auto it : ans) {
        cout << it << "\n";
    }

    return 0;
}