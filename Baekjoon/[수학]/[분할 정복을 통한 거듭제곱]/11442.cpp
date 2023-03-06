#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
vector<vector<ll>> ORIGIN = {{1, 1}, {1, 0}};
vector<vector<ll>> matrixMul(vector<vector<ll>> &mat1, vector<vector<ll>> &mat2) {
    vector<vector<ll>> result(2, vector<ll>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = ((mat1[i][0] * mat2[0][j]) % MOD + (mat1[i][1] * mat2[1][j]) % MOD) % MOD;
        }
    }
    return result;
}
vector<vector<ll>> matrixPower(ll n, vector<vector<ll>> &mat) {
    if (n == 1) {
        return {{mat[0][0] % MOD, mat[0][1] % MOD},
                {mat[1][0] % MOD, mat[1][1] % MOD}};
    }
    vector<vector<ll>> result = matrixPower(n / 2, mat);
    result = matrixMul(result, result);
    if (n % 2) {
        result = matrixMul(result, ORIGIN);
    }
    return result;
}
int fibonacci(ll n) {
    if (n <= 2) {
        return 1;
    }
    vector<vector<ll>> result = matrixPower(n - 2, ORIGIN);
    return (result[0][0] + result[0][1]) % MOD;
}
int main() {
    ll n;
    cin >> n;
    n = ((n - 1) / 2) * 2 + 2;
    cout << fibonacci(n);
    return 0;
}