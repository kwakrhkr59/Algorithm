#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
struct point {
    ll x, y;
    bool operator>(point &p) {
        if (y == p.y) {
            return x > p.x;
        }
        return y > p.y;
    }
};
point start_point;
ll ccw(point &p1, point &p2, point &p3) {
    ll c = (ll)(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (ll)(p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
    return c;
}
bool cmp(point &pa, point &pb) {
    ll c = ccw(start_point, pa, pb);
    if (c) {
        return c > 0;
    }
    if (pa.y == pb.y) {
        return pa.x < pb.x;
    }
    return pa.y < pb.y;
}
vector<point> convex(int n, vector<point> &p) {
    vector<point> c;
    c.push_back(p[0]);
    c.push_back(p[1]);

    for (int i = 2; i < n; i++) {
        while (c.size() >= 2) {
            point p2 = *(c.end() - 1);
            point p1 = *(c.end() - 2);
            if (ccw(p1, p2, p[i]) <= 0) {
                c.pop_back();
                continue;
            }
            break;
        }
        c.push_back(p[i]);
    }
    return c;
}
void init(int n, vector<point> &p) {
    for (int i = 1; i < n; i++) {
        if (p[0] > p[i]) {
            swap(p[0], p[i]);
        }
    }
    start_point = p[0];
    sort(p.begin() + 1, p.end(), cmp);
}
double getLen(point &pa, point &pb) {
    ll dx = pa.x - pb.x;
    ll dy = pa.y - pb.y;
    return sqrt(dx * dx + dy * dy);
}
double getArc(int l) {
    return 2 * M_PI * l;
}
ll solution(int n, int l, vector<point> &p) {
    vector<point> c = convex(n, p);

    double total = getLen(c[0], *(c.end() - 1));
    for (int i = 1; i < c.size(); i++) {
        total += getLen(c[i], c[i - 1]);
    }
    total += getArc(l);

    return round(total);
}
int main() {
    int n, l;
    cin >> n >> l;
    vector<point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    init(n, p);
    cout << solution(n, l, p);

    return 0;
}