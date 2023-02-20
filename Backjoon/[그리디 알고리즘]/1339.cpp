#include <iostream>
#include <vector>
#include <queue> //priority_queue
using namespace std;
typedef pair<int, int> ci;
const int MAX = 26;
vector<int> counts(MAX, 0);
int getMax() {
    priority_queue<ci> tq;
    for (int i = 0; i < MAX; i++) {
        if (counts[i] != 0) {
            tq.push({counts[i], i});
        }
    }
    int num = 9, total = 0;
    while(!tq.empty()) {
        total += tq.top().first * num;
        tq.pop();
        num--;
    }
    return total;
}
int main() {
    int n;
    string word;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word;
        int weight = 1;
        for (int j = word.length() - 1; j >= 0; j--) {
            counts[word[j] - 'A'] += weight;
            weight *= 10;
        }
    }
    cout << getMax();
    return 0;
}