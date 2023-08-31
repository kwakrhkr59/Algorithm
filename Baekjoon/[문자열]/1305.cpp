#include <iostream>
#include <vector>
using namespace std;
int minLength(int l, vector<char> &p) {
    vector<int> pi(l, 0);
    int j = 0;
    for (int i = 1; i < l; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            pi[i] = ++j;
        }
    }

    return l - pi[l - 1];
}
int main() {
    int l;
    cin >> l;
    vector<char> p(l);
    for (int i = 0; i < l; i++) {
        cin >> p[i];
    }

    cout << minLength(l, p);

    return 0;
}