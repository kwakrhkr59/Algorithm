#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
    int x, y;
} point;
bool isSquare(vector<point> &p) {
    vector<int> d;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            d.push_back((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
        }
    }
    sort(d.begin(), d.end());

    return (d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5]);
}
int main() {
    int t;
    vector<point> p(4);
    cin >> t;
    while (t--) {
        for (int i = 0; i < 4; i++) {
            cin >> p[i].x >> p[i].y;
        }

        cout << isSquare(p) << "\n";
    }
    return 0;
}