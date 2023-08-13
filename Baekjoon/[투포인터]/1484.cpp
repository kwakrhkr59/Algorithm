#include <iostream>
#include <vector>
using namespace std;
vector<int> getWeight(int g) {
    int past = 1, cur = 2;
    vector<int> weight;
    while (past < cur) {
        int tmp = cur * cur - past * past;
        if (tmp == g) {
            weight.push_back({cur});
            cur++;
            past++;
        } else if (tmp < g) {
            cur++;
        } else {
            past++;
        }
    }
    return weight;
}
int main() {
    int g;
    cin >> g;

    vector<int> weight = getWeight(g);

    if (weight.empty()) {
        cout << -1;
    } else {
        for (auto w : weight) {
            cout << w << "\n";
        }
    }

    return 0;
}