#include <iostream>
using namespace std;
/**[백준 11723] 집합
 * - vector나 map으로 각 원소의 유무를 판단할 경우 시간초과 발생!
 *   => 총 원소의 개수는 20. 32비트 크기 int의 각 bit에 원소의 유무를 저장
 * - value의 i번째 bit가 1이면: 현재 집합에 i 존재 O
 * - value의 i번째 bit가 1이면: 현재 집합에 i 존재 X
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, x, value = 0;
    string op;
    cin >> m;
    while (m--) {
        cin >> op;

		// x 피연산자가 입력되지 않는 연산자: all, empty
        if (op == "all") {
            // 공집합에 모든 원소 추가
            value = 0;
            for (int i = 1; i <= 20; i++) {
                value += (1 << i);
            }
        }
		else if (op == "empty") {
            // 현재 집합을 공집합으로 바꾸기
            value = 0;
        }

		// x 피연산자가 입력되는 연산자: add, remove, check, toggle
        else {
            cin >> x;
            if (op == "add") {
                if (!(value & (1 << x))) { // 현재 집합에 x가 없으면
                    value += (1 << x); // S에 x 추가
                }
            }
            else if (op == "remove") {
                if (value & (1 << x)) { // 현재 집합에 x가 있으면
                    value -= (1 << x); // S에서 x 제거
                }
            }
            else if (op == "check") {
                if (value & (1 << x)) { // 현재 집합에 x가 있는지 출력
                    cout << "1\n"; // 1 출력
                } else { // 현재 집합에 x가 있는지 출력
                    cout << "0\n"; // 0 출력
                }
            }
            else if (op == "toggle") {
                if (value & (1 << x)) { // 현재 집합에 x가 없으면
                    value -= (1 << x); // S에 x 추가
                } else { // 현재 집합에 x가 있으면
                    value += (1 << x); // S에서 x 제거
                }
            }
        }
    }
    return 0;
}
