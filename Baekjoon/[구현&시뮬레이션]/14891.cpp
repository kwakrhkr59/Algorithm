#include <iostream>
using namespace std;
const short TOTAL = 4;
const short SIZE = 8;
const bool N = 0;
const bool S = 1;
struct gear {
    bool pole[SIZE];
    short idx = 0;
    bool top() {
        return pole[idx];
    }
    bool left() {
        return pole[(idx + 6) % SIZE];
    }
    bool right() {
        return pole[(idx + 2) % SIZE];
    }
    void rotate(int d) {
        idx = (idx + d + SIZE) % SIZE;
    }
};
gear gears[TOTAL];
void rotateGear(short n, short d, short checked) {
    if (checked & (1 << n)) {
        return;
    }
    checked |= (1 << n);

    if (n + 1 < TOTAL && gears[n].right() != gears[n + 1].left() ) {
        rotateGear(n + 1, -d, checked);
    }

    if (n - 1 >= 0 && gears[n - 1].right() != gears[n].left()) {
        rotateGear(n - 1, -d, checked);
    }
    gears[n].rotate(d);
}
short sum() {
    short ans = 0;
    for (short i = 0; i < TOTAL; i++) {
        ans += gears[i].top() * (1 << i);
    }
    return ans;
}
int main() {
    short k, n, d;
    char input;
    for (short i = 0; i < TOTAL; i++) {
        for (short j = 0; j < SIZE; j++) {
            cin >> input;
            gears[i].pole[j] = (input == '1') ? S : N;
        }
    }

    cin >> k;
    while (k--) {
        cin >> n >> d;
        rotateGear(n - 1, -d, 0);
    }

    cout << sum();

    return 0;
}