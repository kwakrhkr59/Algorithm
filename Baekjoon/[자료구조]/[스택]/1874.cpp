#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n, input, cur = 1;
    stack<int> s;
    string ans;
    cin >> n;
    while (n--) {
        cin >> input;
        while (cur <= input) {
            s.push(cur++);
            ans += "+\n";
        }
        if (s.top() != input) {
            cout <<"NO";
            return 0;
        }
        s.pop();
        ans += "-\n";
    }
    cout << ans;
    return 0;
}