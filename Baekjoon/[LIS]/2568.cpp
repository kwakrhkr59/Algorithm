#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct line {
    int a, b;
};
bool cmp(const line &l1, const line &l2) {
    return (l1.b < l2.b) || (l1.b == l2.b && l1.a < l2.a);
}
int binary_search(int left, int right, int key, vector<int> &lis) {
    if (left >= right) {
        return right;
    }
    int mid = (left + right) / 2;
    if (lis[mid] < key) {
        return binary_search(mid + 1, right, key, lis);
    }
    return binary_search(left, mid, key, lis);
}
int insert(int value, vector<int> &lis) {
    int len = lis.size();
    if (lis.empty() || lis[len - 1] < value) {
        lis.push_back(value);
        return len;
    }
    int idx = binary_search(0, len - 1, value, lis);
    lis[idx] = value;
    return idx;
}
vector<int> getNotLis(int &n, vector<line> &lines) {
    vector<int> lis, not_lis, index(n);
    sort(lines.begin(), lines.end(), cmp);
    
    for (int i = 0; i < n; i++) {
        int idx = insert(lines[i].a, lis);
        index[i] = idx;
    }

    vector<int> ans(n - lis.size());
    int lis_index = lis.size() - 1;
    int ans_index = ans.size() - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (index[i] != lis_index) {
            ans[ans_index--] = lines[i].a;
        } else {
            lis_index--;
        }
    }
    

    sort(ans.begin(), ans.end());
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    vector<line> lines;

    cin >> n;
    lines.assign(n, {0, 0});
    for (int i = 0; i < n; i++) {
        cin >> lines[i].a >> lines[i].b;
    }

    vector<int> ans = getNotLis(n, lines);
    cout << ans.size() << "\n";
    for (int idx : ans) {
        cout << idx << "\n";
    }

    return 0;
}