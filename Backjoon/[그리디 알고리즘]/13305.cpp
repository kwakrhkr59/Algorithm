#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll getMinPrice(int n, vector<int> &len, vector<ll> &price) {
    int i = 0;
    ll total = 0;
    while (i < n - 1) {
        total += price[i] * len[i];
        if (price[i] < price[i + 1]) {
            price[i + 1] = price[i];
        }
        i++;
    }
    return total;
}
int main() {
    int n;
    cin >> n;
    vector<int> len(n - 1);
    vector<ll> price(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> len[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    cout << getMinPrice(n, len, price);
    return 0;
}