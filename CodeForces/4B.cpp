#include <iostream>
#include <vector>
using namespace std;
pair<int, int> getBound(int &d, vector<pair<int, int>> &range) {
    int low_bound = 0;
    int high_bound = 0;
    for (int i = 0; i < d; i++) {
        low_bound += range[i].first;
        high_bound += range[i].second;
    }
    return {low_bound, high_bound};
}
vector<int> solve(int &d, int &sum_time, vector<pair<int, int>> &range) {
    vector<int> record(d, 0);
    pair<int, int> bound = getBound(d, range);
    int low_bound = bound.first;
    int high_bound = bound.second;

    if (high_bound < sum_time || low_bound > sum_time) {
        return {};
    }

    int idx = 0;
    for (idx = 0; idx < d; idx++) {
        int interval = range[idx].second - range[idx].first;
        if ((low_bound + interval) >= sum_time) {
            record[idx] = range[idx].first + (sum_time - low_bound);
            break;
        }
        record[idx] = range[idx].second;
        low_bound += interval;
    }
    while (++idx < d) {
        record[idx] = range[idx].first;
    }

    return record;
}
int main() {
    int d, sum_time;
    vector<pair<int, int>> range;

    cin >> d >> sum_time;
    range.assign(d, {0, 0});

    for (int i = 0; i < d; i++) {
        cin >> range[i].first >> range[i].second;
    }

    vector<int> record = solve(d, sum_time, range);
    if (record.empty()) {
        cout << "NO";
    } else {
        cout << "YES\n";
        for (int t : record) {
            cout << t << " ";
        }
    }

    return 0;
}