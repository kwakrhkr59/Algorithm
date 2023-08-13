#include <iostream>
#include <vector>
using namespace std;
typedef struct {
    double x, y;
} point;
double ccw(point &p1, point &p2, point &p3) {
    return ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y)) / 2.0;
}
double getArea(int n, vector<point> &points) {
    double area = 0;
    for (int i = 1; i < n -1; i++) {
        area += ccw(points[0], points[i], points[i + 1]);
    }
    if (area < 0) {
        return -area;
    }
    return area;
}
int main() {
    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    cout << fixed;
    cout.precision(1);
    cout << getArea(n, points);

    return 0;
}