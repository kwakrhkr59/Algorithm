#include <iostream>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
int t, q, p, c, v, d = 0;
int ver = 0;
char s[101];
rope<char> rp[50001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> q;
        if (q == 1) {
            cin >> p >> s;
            p -= d;
            rp[ver + 1] = rp[ver];
            rp[++ver].insert(p, s);
        } else if (q == 2) {
            cin >> p >> c;
            p -= d;
            c -= d;
            rp[ver + 1] = rp[ver];
            rp[++ver].erase(p - 1, c);
        } else {
            cin >> v >> p >> c;
            v -= d;
            p -= d;
            c -= d;
            cout << rp[v].substr(p - 1, c) << "\n";
            for (int i = p - 1; i < p + c - 1; i++) {
                if (rp[v][i] == 'c') {
                    d++;
                }
            }
        }
    }

    return 0;
}