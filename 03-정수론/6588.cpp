#include <stdio.h>
#include <iostream>

using namespace std;

const int MAX_N = 1000000;
bool arr[MAX_N + 1]; // 전역 배열 사용 (메모리 누수 방지)

void che() {
    arr[0] = arr[1] = true; // 0과 1은 소수가 아님
    for (int i = 2; i * i <= MAX_N; i++) {
        if (!arr[i]) { // 소수라면
            for (int j = i * i; j <= MAX_N; j += i) {
                arr[j] = true; // 소수가 아닌 것으로 마킹
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    che(); // 소수 전처리

    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        
        bool hasAns = false; // 🔹 입력마다 초기화해야 함

        for (int i = 3; i < n; i += 2) {
            if (!arr[i] && !arr[n - i]) {
                hasAns = true;
                printf("%d = %d + %d\n", n, i, n - i);
                break;
            }
        }

        if (!hasAns)
            printf("Goldbach's conjecture is wrong.\n");
    }

    return 0;
}
