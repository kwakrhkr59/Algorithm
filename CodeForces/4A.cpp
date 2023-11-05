#include <iostream>
using namespace std;
bool bruteForce(int &w) {
    return (w % 2 == 0) && (w > 2);
}
int main() {
    int w;
    cin >> w;
    cout << (bruteForce(w) ? "YES" : "NO");
    return 0;
}