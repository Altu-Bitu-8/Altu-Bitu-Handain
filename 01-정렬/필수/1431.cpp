#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// 숫자 합을 구하는 함수
int sum_of_digits(const string& s) {
    int sum = 0;
    for (char c : s) {
        if (isdigit(c)) {
            sum += c - '0';
        }
    }
    return sum;
}

// 정렬 기준 정의
bool compare(const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length(); // 1. 길이가 짧은 것이 먼저
    }
    int sumA = sum_of_digits(a);
    int sumB = sum_of_digits(b);
    if (sumA != sumB) {
        return sumA < sumB; // 2. 숫자의 합이 작은 것이 먼저
    }
    return a < b; // 3. 사전순 비교 (알파벳이 숫자보다 크므로 정상 동작)
}

int main() {
    int N;
    cin >> N;
    vector<string> serials(N);
    
    for (int i = 0; i < N; i++) {
        cin >> serials[i];
    }
    
    sort(serials.begin(), serials.end(), compare);
    
    for (const string& s : serials) {
        cout << s << "\n";
    }
    
    return 0;
}
