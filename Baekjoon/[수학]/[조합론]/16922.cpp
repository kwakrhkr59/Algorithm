#include <iostream>
#include <vector>
using namespace std;

vector<int> roman_values = {1, 5, 10, 50};
vector<bool> checked(2501, false);

void check(const vector<int>& count) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += count[i] * roman_values[i];
    }
    checked[sum] = true;
}
void backtracking(int index, int remaining, vector<int>& count) {
    if (remaining == 0) {
        check(count);
        return;
    }

    for (int i = index; i < 4; i++) {
        count[i]++;
        backtracking(i, remaining - 1, count);
        count[i]--;
    }
}
int count_vector() {
    int result = 0;
    for (int i = 0; i <= 2500; i++) {
        if (checked[i])
            result++;
    }
    return result;
}
int main() {
    int n;
    cin >> n;

    vector<int> count(4, 0);
    backtracking(0, n, count);

    cout << count_vector();

    return 0;
}
