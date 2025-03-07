#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 초기 체중, 기초 대사량, 기초 대사량 변화 역치
    int w0, bmr1, t;
    cin >> w0 >> bmr1 >> t;
    
    // 다이어트 기간, 일일 에너지 섭취량, 일일 활동 대사량
    int d, intake, activity;
    cin >> d >> intake >> activity;
    
    // 기초 대사량 변화를 고려하지 않는 경우의 체중 변화
    int w1 = w0;
    int bmr_const = bmr1;
    for (int i = 0; i < d; i++) {
        w1 += (intake - bmr_const);
        if (w1 <= 0) {
            cout << "Danger Diet" << endl;
            break;
        }
    }
    if (w1 > 0) {
        cout << w1 << " " << bmr_const << endl;
    }
    
    // 기초 대사량 변화를 고려하는 경우의 체중 및 BMR 변화
    int w2 = w0;
    int bmr2 = bmr1;
    for (int i = 0; i < d; i++) {
        int balance = intake - (bmr2 + activity);
        w2 += balance;
        if (w2 <= 0) {
            cout << "Danger Diet" << endl;
            return 0;
        }
        if (abs(balance) > t) {
            bmr2 += balance / 2;
            if (bmr2 <= 0) {
                cout << "Danger Diet" << endl;
                return 0;
            }
        }
    }
    cout << w2 << " " << bmr2 << " ";
    
    // 요요 현상 판단
    if (bmr1 > bmr2) {
        cout << "YOYO" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
