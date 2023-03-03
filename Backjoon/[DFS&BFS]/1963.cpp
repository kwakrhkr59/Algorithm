#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
const int MAX = 9999;
vector<bool> is_prime(MAX + 1, true);
void findPrime() {
    for (int i = 2; i * i <= MAX; i++) {
        for (int j = i * i; j <= MAX; j += i) {
            is_prime[j] = false;
        }
    }
}
int getCount(int n1, int n2) {
    vector<int> visited(MAX + 1, 0);
    queue<string> q;

    visited[n1] = 1;
    q.push(to_string(n1));

    while (!q.empty()) {
        string cur_str = q.front();
        int cur_int = stoi(cur_str);
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            string next_str = cur_str;
            for (int j = 0; j < 10; j++) {
                next_str[i] = j + '0';
                int next_int = stoi(next_str);
                if (next_int < 1000 || visited[next_int] || !is_prime[next_int]) {
                    continue;
                }
                if (next_int == n2) {
                    return visited[cur_int];
                }
                q.push(next_str);
                visited[next_int] = visited[cur_int] + 1;
            }
        }
    }
    return visited[n2] - 1;
}
int main() {
    int t;
    cin >> t;

    findPrime();

    while (t--) {
        int n1, n2;
        cin >> n1 >> n2;
        
        int cnt = getCount(n1, n2);
        if (cnt == -1) {
            cout << "Impossible\n";
        } else {
            cout << cnt << "\n";
        }
    }
    return 0;
}