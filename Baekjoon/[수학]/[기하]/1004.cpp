#include <iostream>
using namespace std;
bool in(int x, int y, int cx, int cy, int r) {
    int dir = (x - cx) * (x - cx) + (y - cy) * (y - cy);
    if (dir < r * r) {
        return true;
    }
    return false;
}
int main() {
    int t, n;
    int x1, y1, x2, y2, cx, cy, r;
    int cnt;
    bool f1, f2;

    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2 >> n;

        cnt = 0;
        while (n--) {
            cin >> cx >> cy >> r;

            f1 = in(x1, y1, cx, cy, r);
            f2 = in(x2, y2, cx, cy, r);
            if (f1 ^ f2) {
                cnt++;
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}