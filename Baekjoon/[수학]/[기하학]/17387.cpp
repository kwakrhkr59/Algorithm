#include <iostream>
using namespace std;
typedef long long ll;
typedef struct point {
    ll x, y;
    bool operator>(point const &p) {
        if (x == p.x) {
            return y > p.y;
        }
        return x > p.x;
    }
} point;
int ccw(point &pa, point &pb, point &pc) {
    ll tmp = pa.x * pb.y + pb.x * pc.y + pc.x * pa.y;
    tmp -= pb.x * pa.y + pc.x * pb.y + pa.x * pc.y;
    if (tmp > 0) {
        return 1;
    } else if (tmp < 0) {
        return -1;
    }
    return 0;
}
bool isCrossed(point &p1, point &p2, point &p3, point &p4) {
    int c1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int c2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (!c1 && !c2) {
        if (p1 > p2) {
            swap(p1, p2);
        }
        if (p3 > p4) {
            swap(p3, p4);
        }

        if (p1 > p4 || p3 > p2) {
            return 0;
        }
        return 1;
    }

    return (c1 <= 0) && (c2 <= 0);
}
int main() {
    point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

    cout << isCrossed(p1, p2, p3, p4);

    return 0;
}