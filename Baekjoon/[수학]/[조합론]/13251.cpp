#include <iostream>
#include <vector>
using namespace std;
double get_prob(int total_cnt, vector<int> rocks, int m, int k) {
    double total_prob = 0;
    for (int i = 0; i < m; i++) {
        double cur_prob = 1;
        for (int j = 0; j < k; j++) {
            cur_prob *= (rocks[i] - j) / (double)(total_cnt - j);
        }
        total_prob += cur_prob;
    }
    return total_prob;
}
int main() {
    int total_cnt = 0;
    vector<int> rocks(50, 0);
    int m, k;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> rocks[i];
        total_cnt += rocks[i];
    }
    cin >> k;

    cout << fixed;
    cout.precision(10);
    cout << get_prob(total_cnt, rocks, m, k);
}
