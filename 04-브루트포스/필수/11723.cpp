#include <iostream>
#include <string>
using namespace std;

int S=0; // 비트마스킹으로 집합 표현

//add
void add(int x){
    //새로운 비트만 1로 만들기 위해 OR 연산

    S|=(1<<(x-1)); //x번째 비트 1로 설정

}

//remove
void remove(int x){
    S &= ~(1 << (x - 1)); // x번째 비트를 0으로 설정
}

//check
void check(int x){
    // check일땐 출력해야됨 (있으면 1 아니면 0)
    cout << ((S & (1 << (x - 1))) ? 1 : 0) << '\n';
    
}
//toggle(있으면 없게 없으면 있게)
void toggle(int x){
    S ^= (1 << (x - 1)); // x번째 비트를 반전
}

//all
void all(){
    S = (1 << 20) - 1; // 1~20 모든 비트를 1로 설정
}

//empty
void empty(){
    S = 0; // 모든 비트를 0으로
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M;
    cin >> M;

    //M번 돌기기
    while(M--){

        string cmd;
        int x;
        cin >> cmd;

        if (cmd == "add") {
            cin >> x;
            add(x);
        } 
        else if (cmd == "remove") {
            cin >> x;
            remove(x);
        } 
        else if (cmd == "check") {
            cin >> x;
            check(x);
        } 
        else if (cmd == "toggle") {
            cin >> x;
            toggle(x);
        } 
        else if (cmd == "all") {
            all();
        } 
        else if (cmd == "empty") {
            empty();
        }

    }

    return 0;
}