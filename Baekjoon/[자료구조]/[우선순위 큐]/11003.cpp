#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l, d;
    priority_queue<ci, vector<ci>, greater<>> pq;

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> d;
        pq.push({d, i});

        while (pq.top().second <= i - l) {
            pq.pop();
        }
        cout << pq.top().first << " ";
    }
    return 0;
}