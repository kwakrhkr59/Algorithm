#include <iostream>
#include <vector>
using namespace std;
int binary_search(int left, int right, int key, vector<int> &lis) {
    if (left >= right) {
        return right;
    }
    int mid = (left + right) / 2;
    if (lis[mid] >= key) {
        return binary_search(left, mid, key, lis);
    }
    return binary_search(mid + 1, right, key, lis);
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
vector<int> getLis(int n, vector<int> &arr) {
    vector<int> lis, index(n);
    for (int i = 0; i < n; i++) {
        int idx = insert(arr[i], lis);
        index[i] = idx;
    }

    vector<int> ans(lis.size());
    int idx = lis.size() - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (index[i] == idx) {
            ans[idx--] = arr[i];
        }
    }

    return ans;
}
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = getLis(n, arr);
    cout << ans.size() << "\n";
    for (auto it : ans) {
        cout << it << " ";
    }

    return 0;
}