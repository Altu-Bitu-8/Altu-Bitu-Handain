#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); //입출력 속도 빠르게 해주는 거
    int N;
    cin >> N; //N 입력 받기

    //Min-Heap 선언
    priority_queue<int, vector<int>,greater<int>> pq;


     // N x N 개의 수를 입력받으며 처리
     for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num; // 숫자 입력 받기

            pq.push(num); // 힙에 삽입

            // 힙의 크기가 N보다 크면 가장 작은 값 제거
            if (pq.size() > N) {
                pq.pop();
            }
        }

     }

    // N번째 큰 수가 힙의 top()에 존재
    cout << pq.top() << endl;

    return 0;




}