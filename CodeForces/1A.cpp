#include <iostream>
#include <cmath>
using namespace std;
long long solve(int &n, int &m, int &a) {
    int x = ceil((double)n / a);
    int y = ceil((double)m / a);
    return 1ll * x * y;
}
int main() {
    int n, m, a;
    cin >> n >> m >> a;

    cout << solve(n, m, a);

    return 0;
}