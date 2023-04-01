#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
vector<string> words;
void count(int &max_value, int visited) {
    int cnt = 0;
    for (string w : words) {
        bool flag = true;
        for (int i = 0; i < w.size(); i++) {
            if (!(visited & (1 << (w[i] - 'a')))) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cnt++;
        }
    }
    max_value = max(max_value, cnt);
}
void backtracking(int idx, int cnt, int k, int &max_value, int visited) {
    if (cnt == k) {
        count(max_value, visited);
    }
    for (int i = idx + 1; i < 26; i++) {
        if (visited & (1 << i)) {
            continue;
        }
        backtracking(i, cnt + 1, k, max_value, visited | (1 << i));
    }
}
int init() {
    int visited = 0;
    char initial[5] = {'a', 'n', 't', 'i', 'c'};
    for (char c : initial) {
        visited = visited | (1 << (c - 'a'));
    }
    return visited;
}
int main() {
    int n, k, max_value = 0, visited = init();
    string w;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> w;
        words.push_back(w);
    }

    if (k < 0) {
        cout << '0';
        return 0;
    }


    backtracking(-1, 0, k - 5, max_value, visited);
    cout << max_value;

    return 0;
}