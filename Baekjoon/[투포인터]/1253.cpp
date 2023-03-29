#include <iostream>
#include <vector>
#include <algorithm> //sort()
using namespace std;
bool isGood(int n, vector<int> &arr, int index) {
    int left = 0, right = n - 1;
    int key = arr[index];
    while (left < right) {
        int tmp = arr[left] + arr[right];
        // 자기 자신을 제외한 다른 수 2개로 표현해야 하므로
        // 자기 자신의 인덱스와 두 포인터와 겹치면 -> 포인터 이동
        if (left == index) {
            left++;
            continue;
        } else if (right == index) {
            right--;
            continue;
        } 

        if (tmp == key) {
            return true;
        }

        if (tmp < key) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}
int getCount(int n, vector<int> &arr) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (isGood(n, arr, i)) {
            cnt++;
        }
    }
    return cnt;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    cout << getCount(n, arr);
    return 0;
}