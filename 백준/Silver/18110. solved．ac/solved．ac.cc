#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
void trimmedMean(int n, int &sum, vector<int> &arr) {
    if (n == 0) {
        return;
    }

    int cut = round(n * 0.15);
    sort(arr.begin(), arr.end());

    for (int i = 0; i < cut; i++) {
        sum -= arr[i];
        sum -= arr[n - i - 1];
    }

    sum = round(float(sum) / (n - 2 * cut));
}
int main() {
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    trimmedMean(n, sum, arr);

    cout << sum;

    return 0;
}