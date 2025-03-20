#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

// 주어진 단어의 문자 빈도를 저장하는 함수
map<char, int> getFrequency(const string& word) {
    map<char, int> freq;
    for (char c : word) {
        freq[c]++;
    }
    return freq;
}

// 두 단어가 비슷한지 판별하는 함수
bool isSimilar(const string& base, const string& target) {
    map<char, int> baseFreq = getFrequency(base);
    map<char, int> targetFreq = getFrequency(target);

    int baseSize = base.size();
    int targetSize = target.size();

    // 크기 차이가 2 이상이면 절대 불가능
    if (abs(baseSize - targetSize) > 1) {
        return false;
    }

    // 문자 개수 차이를 비교
    int diffCount = 0; // 다른 문자 개수
    int charChange = 0; // 단어 변경 횟수

    for (char c = 'A'; c <= 'Z'; c++) {
        int countDiff = baseFreq[c] - targetFreq[c];

        if (countDiff != 0) {
            diffCount += abs(countDiff);
            if (abs(countDiff) > 1) {
                return false; // 하나 이상의 추가/삭제가 존재하면 불가능
            }
            charChange++;
        }
    }

    // 조건 1: 완전히 같으면 true
    if (diffCount == 0) return true;

    // 조건 2: 하나의 문자를 추가/삭제한 경우
    if (diffCount == 1) return true;

    // 조건 3: 하나의 문자를 변경한 경우 (두 문자가 교체됨)
    if (diffCount == 2 && charChange == 2) return true;

    return false;
}

int main() {
    int N;
    cin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    string baseWord = words[0]; // 첫 번째 단어 기준
    int similarCount = 0;

    for (int i = 1; i < N; i++) {
        if (isSimilar(baseWord, words[i])) {
            similarCount++;
        }
    }

    cout << similarCount << endl;
    return 0;
}
