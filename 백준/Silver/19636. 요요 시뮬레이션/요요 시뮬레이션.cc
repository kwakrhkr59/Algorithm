#include <iostream>
#include <tuple>
#include <cmath>
using namespace std;
tuple<int, int, int> diet(int w0, int i0, int i, int a, int d, int t) {
    int w1 = w0;          // 기초대사량 변화 고려 X
    int w2 = w0, m2 = i0; // 기초대사량 변화 고려 O

    while (d--) {
        w1 += i - i0 - a;
        w2 += i - m2 - a;

        if (abs(i - m2 - a) > t) {
            m2 += float(i - m2 - a) / 2.0;
        }
    }
    return {w1, w2, m2};
}
int main() {
    int w0, i0, i, a;
    int d, t;
    int final_weight, final_meta;
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    tuple<int, int, int> tmp = diet(w0, i0, i, a, d, t);
    int w1 = get<0>(tmp), m1 = i0;
    int w2 = get<1>(tmp), m2 = get<2>(tmp); // rl

    if (w1 <= 0) {
        cout << "Danger Diet\n";
    } else {
        cout << w1 << " " << m1 << "\n";
    }

    if (w2 <= 0 || m2 <= 0) {
        cout << "Danger Diet";
    } else {
        cout << w2 << " " << m2 << " ";
        if (m2 < i0) {
            cout << "YOYO";
        } else {
            cout << "NO";
        }
    }
    return 0;
}