#include <iostream>
using namespace std;
typedef struct {
    int x, y;
} point;
int direction(point &p1, point &p2, point &p3) {
    int ans = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
    if (ans > 0) {
        return 1;
    } else if (ans < 0) {
        return -1;
    }
    return 0;
}
int main() {
    point p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    cout << direction(p1, p2, p3);
    return 0;
}