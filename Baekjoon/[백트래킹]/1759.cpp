#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
bool isValid(string str) {
    int v = 0, c = str.length();
    for (char ch : str) {
        for (int i = 0; i < 5; i++) {
            if (ch == vowel[i]) {
                v++;
                c--;
                break;
            }
        }
    }

    if (v >= 1 && c >= 2) {
        return true;
    }
    return false;
}
void backtracking(string str, int index, int cnt, int c, vector<char> &arr) {
    if (cnt == 0) {
        if (isValid(str)) {
            cout << str << "\n";
        }
        return;
    }
    for (int i = index; i < c; i++) {
        backtracking(str + arr[i], i + 1, cnt - 1, c, arr);
    }
}
int main() {
    int l, c;
    cin >> l >> c;
    vector<char> arr(c);
    for (int i = 0; i < c; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    backtracking("", 0, l, c, arr);

    return 0;
}