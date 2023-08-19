#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;
vector<bool> in(MAX + 1, false);
vector<int> score(MAX + 1, 0);
void calScore(int x) {
    for (int i = x * 2; i <= MAX; i += x) {
        score[i]--;
        if (in[i]) {
            score[x]++;
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        in[arr[i]] = true;
    }
    
    for (int i = 0; i < n; i++) {
        calScore(arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        cout << score[arr[i]] << " ";
    }
    
    return 0;
}
