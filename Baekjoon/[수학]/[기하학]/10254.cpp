#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
vector<point> getConvex(int n, vector<point> &p) {
    vector<point> convex;
    convex.push_back(p[0]);
    convex.push_back(p[1]);

    for (int i = 2; i < n; i++) {
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
pair<point, point> rotatingCalipers(vector<point> &convex) {
    pair<point, point> ans = {{-1, -1}, {-1, -1}};
    double max_len = 0;

    int c = convex.size();
    int j = 1;
    
    for (int i = 0; i < c; i++) {
        int next_i = (i + 1) % c;
        while (true) {
            int next_j = (j + 1) % c;
            point p0 = {0, 0};
            point p1 = {convex[next_i].x - convex[i].x, convex[next_i].y - convex[i].y};
            point p2 = {convex[next_j].x - convex[j].x, convex[next_j].y - convex[j].y};

            if (getCcw(p0, p1, p2) > 0) {
                j = next_j;
            } else {
                break;
            }
        }

        double len = getLen(convex[i], convex[j]);
        if (max_len < len) {
            ans = {convex[i], convex[j]};
            max_len = len;
        }
    }

    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout << fixed;
    cout.precision(6);

    int t, n;
    vector<point> p;

    cin >> t;
    while (t--) {
        cin >> n;
        p.assign(n, {0, 0});
        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
        }

        init(n, p);
        vector<point> convex = getConvex(n, p);
        pair<point, point> ans = rotatingCalipers(convex);

        cout << ans.first.x << " " << ans.first.y << " " << ans.second.x << " " << ans.second.y << "\n";
    }
    return 0;
}