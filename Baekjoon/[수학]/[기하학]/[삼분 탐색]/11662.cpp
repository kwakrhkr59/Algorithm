#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef struct {
    double x, y;
} point;
const double MIN_ERR = 0.000001;
double distance(point &p1, point &p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}
double ternarySearch(vector<point> &p) {
    point min_hi, min_lo, kang_hi, kang_lo;
    min_hi = {p[1].x - (p[1].x - p[0].x) / 3, p[1].y - (p[1].y - p[0].y) / 3};
    min_lo = {p[0].x + (p[1].x - p[0].x) / 3, p[0].y + (p[1].y - p[0].y) / 3};
    kang_hi = {p[3].x - (p[3].x - p[2].x) / 3, p[3].y - (p[3].y - p[2].y) / 3};
    kang_lo = {p[2].x + (p[3].x - p[2].x) / 3, p[2].y + (p[3].y - p[2].y) / 3};    

    if (distance(min_hi, min_lo) < MIN_ERR || distance(kang_hi, kang_lo) < MIN_ERR) {
        return distance(min_hi, kang_hi);
    }
    if (distance(min_hi, kang_hi) < distance(min_lo, kang_lo)) {
        p[0] = min_lo;
        p[2] = kang_lo;
    } else {
        p[1] = min_hi;
        p[3] = kang_hi;
    }
    return ternarySearch(p);
}
int main() {
    vector<point> p(4);
    for (int i = 0; i < 4; i++) {
        cin >> p[i].x >> p[i].y;
    }

    cout << fixed;
    cout.precision(6);
    cout << ternarySearch(p);

    return 0;
}