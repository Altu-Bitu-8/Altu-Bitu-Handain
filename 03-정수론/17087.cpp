#include <iostream>
#include <vector>

using namespace std;

//GCD 계산 함수
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N, S;
    cin >> N >> S; // N: 동생 수, S: 수빈이의 초기 위치

    vector<int> arr(N); // 동생들의 위치를 저장할 벡터
    for (int i = 0; i < N; i++) {
        cin >> arr[i]; // 동생 위치 입력
    }

    // 첫 번째 동생과의 거리 차이를 초기 GCD 값으로 설정
    int result = abs(S - arr[0]);

    // 나머지 동생들과의 거리 차이를 GCD에 반영
    for (int i = 1; i < N; i++) {
        result = gcd(result, abs(S - arr[i]));
    }

    cout << result << endl; // 가능한 D의 최댓값 출력
    return 0;
}
