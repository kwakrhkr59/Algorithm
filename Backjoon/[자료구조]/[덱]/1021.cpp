#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int getIndex(int element, deque<int> &dq) {
    deque<int>::iterator it = dq.begin();
    int index = 0;
    while (it != dq.end() && (*it) != element) {
        it++;
        index++;
    }
    return index;
}
int getCnt(int n, vector<int> &num) {
    deque<int> dq;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    for (auto element : num) {
        int index = getIndex(element, dq);
        if (index <= dq.size() / 2) {
            while (dq.front() != element) {
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            dq.pop_front();
        } else {
            while (dq.front() != element) {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            dq.pop_front();
        }
    }
    return cnt;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> num(m);
    for (int i = 0; i < m; i++) {
        cin >> num[i];
    }
    cout << getCnt(n, num);
    return 0;
}