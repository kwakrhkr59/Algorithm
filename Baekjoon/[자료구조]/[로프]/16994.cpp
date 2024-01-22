#include <iostream>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, q, m, x, y;
    string s;
    rope<char> rp;

    cin >> s >> q;
    n = s.size();
    rp.append(s.c_str());

    while (q--) {
        cin >> m >> x;
        switch (m) {
            case 3:
                cout << rp[x] << "\n";
                break;
            case 1:
                cin >> y;
                rp = rp.substr(x, y - x + 1) + rp.substr(0, x) + rp.substr(y + 1, n - y - 1);
                break;
            case 2:
                cin >> y;
                rp = rp.substr(0, x) + rp.substr(y + 1, n - y - 1) + rp.substr(x, y - x + 1);
                break;
        }
    }

    return 0;
}