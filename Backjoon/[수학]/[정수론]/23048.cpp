#include <iostream>
#include <vector>
using namespace std;
typedef long long ll; //500000 ** 2 -> int 범위 초과 => 오버플로우 발생
vector<int> colorring(int n) {
    vector<int> color(n + 1, 0);
    int cnt = 1;
    color[1] = 1;
    for (ll i = 2; i <= n; i++) {
        if (color[i]) {
            continue;
        }
        color[i] = ++cnt;
        for (ll j = i * i; j <= n; j += i) {
            if (color[j] == 0) {
                color[j] = cnt;
            }
        }
    }
    color[0] = cnt; //k를 color[0]에 저장
    return color;
}
int main() {
    int n;
    cin >> n;

    vector<int> color = colorring(n);
    int k = color[0];
    cout << k << "\n";
    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }

    return 0;
}