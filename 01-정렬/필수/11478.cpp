#include <iostream>
#include <set>
#include <string>

using namespace std;

int count_unique_substrings(const string& s) {
    set<string> substrings;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        string temp = "";
        for (int j = i; j < n; j++) {
            temp += s[j];
            substrings.insert(temp);
        }
    }
    
    return substrings.size();
}

int main() {
    string s;
    cin >> s;
    
    cout << count_unique_substrings(s) << "\n";
    
    return 0;
}
