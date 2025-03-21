#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<char> w(n, '?');  // 바퀴 초기 상태 ('?'로 초기화)
    int pos = 0;  // 화살표 위치
    unordered_set<char> used;  // 사용된 알파벳 저장

    for (int i = 0; i < k; i++) {
        int s;
        char ch;
        cin >> s >> ch;

        // s만큼 시계방향으로 이동
        pos = (pos - s % n + n) % n;

        // 기존 문자와 충돌하는 경우 불가능
        if (w[pos] != '?' && w[pos] != ch) {
            cout << "!" << endl;
            return 0;
        }

        // 동일 문자가 다른 위치에 있는 경우 불가능
        if (used.count(ch) && w[pos] != ch) {
            cout << "!" << endl;
            return 0;
        }

        // 문자 저장 및 기록
        w[pos] = ch;
        used.insert(ch);
    }

    // 결과 출력 (pos부터 시계방향)
    for (int i = 0; i < n; i++) {
        cout << w[(pos + i) % n];
    }
    cout << endl;

    return 0;
}
