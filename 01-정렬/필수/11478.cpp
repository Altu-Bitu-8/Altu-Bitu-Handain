#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s; 
    set<string> substrings; // 중복을 방지하기 위한 집합
    int n = s.length();
    
    // 모든 부분 문자열을 생성하여 집합에 삽입
    for (int i = 0; i < n; i++) {
        string temp = "";
        for (int j = i; j < n; j++) {
            temp += s[j];
            substrings.insert(temp); 
        }
    }
    
    cout << substrings.size() << "\n"; // 서로 다른 부분 문자열 개수 출력
    
    return 0;
}
