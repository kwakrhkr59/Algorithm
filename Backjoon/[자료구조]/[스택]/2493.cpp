#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, input;
    stack<int> heights, order;
    order.push(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        while (!heights.empty() && heights.top() < input) {
            heights.pop();
            order.pop();
        }
        cout << order.top() << " ";
        heights.push(input);
        order.push(i);
    }
    return 0;
}