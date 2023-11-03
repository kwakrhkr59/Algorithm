#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
struct point {
    int x, y;
    bool operator>(point &p) {
        if (y == p.y) {
            return x > p.x;
        }
        return y > p.y;
    }
};
point start_point;
ll getCcw(point &p1, point &p2, point &p3) {
    ll ccw = (ll)(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (ll)(p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
    return ccw;
}
bool cmp(point &pa, point &pb) {
    ll ccw = getCcw(start_point, pa, pb);
    if (ccw) {
        return ccw > 0;
    }
    if (pa.y == pb.y) {
        return pa.x < pb.x;
    }
    return pa.y < pb.y;
}
vector<point> getConvex(int c, vector<point> &p) {
    vector<point> convex;
    convex.push_back(p[0]);
    convex.push_back(p[1]);

    for (int i = 2; i < c; i++) {
        while (convex.size() >= 2) {
            point p2 = *(convex.end() - 1);
            point p1 = *(convex.end() - 2);
            if (getCcw(p1, p2, p[i]) <= 0) {
                convex.pop_back();
                continue;
            }
            break;
        }
        convex.push_back(p[i]);
    }
    return convex;
}
void init(int c, vector<point> &p) {
    for (int i = 1; i < c; i++) {
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
double bruteForce(vector<point> &convex) {
    double max_len = 0;
    for (int i = 0; i < convex.size() - 1; i++) {
        for (int j = i + 1; j < convex.size(); j++) {
            max_len = max(max_len, getLen(convex[i], convex[j]));
        }
    }
    return max_len;
}
int main() {
    int c;
    cin >> c;
    vector<point> p(c);
    for (int i = 0; i < c; i++) {
        cin >> p[i].x >> p[i].y;
    }

    init(c, p);
    vector<point> convex = getConvex(c, p);

    cout << fixed;
    cout.precision(6);
    cout << bruteForce(convex);

    return 0;
}