#include <iostream>
#include <map>

using namespace std;

//방향 백터
map <string,pair<int,int>> moves={
    {"R", {0, 1}}, {"L", {0, -1}}, {"B", {-1, 0}}, {"T", {1, 0}},
    {"RT", {1, 1}}, {"LT", {1, -1}}, {"RB", {-1, 1}}, {"LB", {-1, -1}}
};

//좌표->위치
pair<int,int> toInt(string loc){
    return {loc[1]-'1',loc[0]-'A'};
}

//위치->좌표
string toLoc(int x, int y){
    return string(1, 'A' + y) + to_string(x + 1);
}

int main(){
    ios_base::sync_with_stdio(false); //입출력 속도 빠르게 해주는 거

    cin.tie(0);
    cout.tie(0);

    string king,dol;
    int n;
    cin >> king >> dol >> n; //3개 입력 받음

    pair <int,int> k =toInt(king);
    pair <int,int> d =toInt(dol);

    for (int i=0; i<n; i++){
        string move;
        cin >> move;

        int x=moves[move].first; //x 방향 이동
        int y=moves[move].second;//y 방향 이동

        //킹의 새 위치
        int nx=k.first+x, ny=k.second + y;

        if(!(nx>=0 && nx<8 && ny>=0 &&ny<8)) continue; //체스판 벗어나면 무시

        //킹 이동후, 돌과 만나면 돌도 그 방향으로 이동시키기
        if(nx==d.first &&ny == d.second){
            int dx=d.first+x, dy=d.second +y;
            if(!(dx>=0 && dx<8 && dy>=0 &&dy<8)) continue; // 돌이 벗어나면 무시
            d={dx,dy};
        }

        k={nx,ny};

    }

    //꼴에 맞게 변환환
    cout << toLoc(k.first,k.second) << '\n';
    cout << toLoc(d.first,d.second) << '\n';

    return 0;
    


}