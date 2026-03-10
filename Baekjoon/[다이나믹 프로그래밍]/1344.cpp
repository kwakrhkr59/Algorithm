#include <iostream>
#include <vector>
using namespace std;
const int CNT_PART = 18;
double pow(double a, int p) {
    double result = 1;
    double mult = a;
    while (p > 0) {
        if (p % 2 == 1) {
            result *= mult;
        }
        p /= 2;
        mult *= mult;
    }
    return result;
}
vector<int> get_comb() {
    vector<vector<int>> total_comb(CNT_PART + 1, vector<int>(CNT_PART + 1, 0));
    total_comb[1][0] = total_comb[1][1] = 1;
    for (int i = 2; i <= CNT_PART; i++) {
        total_comb[i][0] = total_comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            total_comb[i][j] = total_comb[i - 1][j - 1] + total_comb[i - 1][j];
        }
    }
    return total_comb[CNT_PART];
}
double solution(double prob_a, double prob_b) {
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17};
    vector<int> comb18 = get_comb();

    double prob_a_prime = 0;
    double prob_b_prime = 0;
    for (int p : primes) {
        prob_a_prime += comb18[p] * pow(prob_a, p) * pow(1 - prob_a, CNT_PART - p);
        prob_b_prime += comb18[p] * pow(prob_b, p) * pow(1 - prob_b, CNT_PART - p);
    }

    double prob_a_not_prime = 1 - prob_a_prime;
    double prob_b_not_prime = 1 - prob_b_prime;

    return 1 - prob_a_not_prime * prob_b_not_prime;
}
int main() {
    int prec_a, prec_b;
    cin >> prec_a >> prec_b;
    cout.precision(7);
    cout << fixed;
    cout << solution(prec_a / 100.0, prec_b / 100.0);
    return 0;
}
