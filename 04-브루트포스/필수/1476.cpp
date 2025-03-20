# include <iostream>

using namespace std;

int main(){
    int ei, si,mi;
    int e=1, s=1, m=1;

    cin>>ei>>si>>mi;

    int year=1;

    while(!(s==si && m==mi && e==ei)){ // 원하는 값과 일치할 때까지 반복
        year++;
        e=(e%15)+1; //1~15
        s = (s % 28) + 1; // 1~28 
        m = (m % 19) + 1; // 1~19 

    } 

    cout << year << '\n'; // 결과 출력
}
