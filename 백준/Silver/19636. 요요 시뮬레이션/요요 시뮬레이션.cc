#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int w1, w2;       // 체중 변수
    int e, l1, l2, t; // 에너지 섭취량, 기초 대사량, 기초 대사량 변화
    int d, a;         // 다이어트 기간, 활동 대사량

    // 입력
    cin >> w1 >> l1 >> t;
    cin >> d >> e >> a;
    w2 = w1;
    l2 = l1;
    for (int i = 0; i < d; i++)
    {
        w1 += e - (l1 + a); // 활동 대사량 변화 고려 x 체중
        w2 += e - (l2 + a);
        if (abs(e - (l2 + a)) > t)
            l2 += floor((e - (l2 + a)) / 2.0); // 절댓값이 T를 초과하면 활동대사량은 증가한다
    }
    // 출력
    if (w1 <= 0 || l1 <= 0)
        cout << "Danger Diet"
             << "\n";
    else
        cout << w1 << " " << l1 << "\n";
    if (w2 <= 0 || l2 <= 0)
        cout << "Danger Diet"
             << "\n";
    else
    {
        cout << w2 << " " << l2 << " ";
        if (0 < l1 - (l2 - 0))
            cout << "YOYO";
        else
            cout << "NO";
    }
    return 0;
}