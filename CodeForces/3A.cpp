#include <iostream>
using namespace std;
pair<int, string> solve(char x1, char y1, char x2, char y2) {
    int cnt = 0;
    string route;
    while (x1 != x2 || y1 != y2) {
        if (x1 < x2) {
            x1++;
            route += "R";
        } else if (x1 > x2) {
            x1--;
            route += "L";
        }

        if (y1 < y2) {
            y1++;
            route += "U";
        } else if (y1 > y2) {
            y1--;
            route += "D";
        }

        route += "\n";
        cnt++;
    }

    return {cnt, route};
}
int main() {
    char x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    pair<int, string> ans = solve(x1, y1, x2, y2);
    cout << ans.first << "\n"
         << ans.second;

    return 0;
}