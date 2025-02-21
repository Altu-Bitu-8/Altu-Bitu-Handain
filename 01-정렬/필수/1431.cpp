#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int compare(string a, string b) {
    int len1 = a.size();
    int len2 = b.size();
    int sum1 = 0;
    int sum2 = 0;

    // 1. 문자열 길이가 다르면, 짧은 것이 먼저 오도록 정렬
    if (len1 != len2) {
        return len1 < len2;
    }

    // 2. 길이가 같다면, 숫자의 합이 작은 것이 먼저 오도록 정렬
    for (int i = 0; i < a.size(); i++) {
        // 문자열 a 내 숫자의 합 계산
        if (a[i] >= '0' && a[i] <= '9') {
            sum1 += int(a[i]) - '0';
        }
        // 문자열 b 내 숫자의 합 계산
        if (b[i] >= '0' && b[i] <= '9') {
            sum2 += int(b[i]) - '0';
        }
    }

    if (sum1 != sum2) {
        return sum1 < sum2;
    }

    // 3. 앞의 기준으로 비교할 수 없다면, 사전순으로 정렬
    return a < b;
}

int main() {
    int count;
    string serialNumbers[50];

    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> serialNumbers[i];
    }

    // 비교 함수 compare에 따라 정렬
    sort(serialNumbers, serialNumbers + count, compare);
    for (int i = 0; i < count; i++) {
        cout << serialNumbers[i] << "\n";
    }
    
    return 0;
}
