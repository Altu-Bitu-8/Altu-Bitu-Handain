#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 사원 정보를 저장할 구조체
struct Employee {
    int D, H, lineNo; // 근무 일수(D), 화장실 급한 정도(H), 줄 번호(lineNo)

    // 우선순위 큐에서 사용할 비교 연산자 (큰 값이 먼저 나오도록 설정)
    bool operator<(const Employee& other) const {
        if (D != other.D) return D < other.D;      // 근무 일수 내림차순 (큰 값 우선)
        if (H != other.H) return H < other.H;      // 화장실 급한 정도 내림차순 (큰 값 우선)
        return lineNo > other.lineNo;              // 줄 번호 오름차순 (작은 값 우선)
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<queue<Employee>> lines(M); // 각 줄을 표현하는 큐
    priority_queue<Employee> pq; // 우선순위 큐 (최대 힙)

    int decaLine = K % M; // 데카가 속한 줄 번호
    int decaIndex = K / M; // 데카가 줄에서 몇 번째인지

    // 사원 정보 입력 및 줄 나누기
    for (int i = 0; i < N; i++) {
        int Di, Hi;
        cin >> Di >> Hi;
        lines[i % M].push({Di, Hi, i % M}); // M개의 줄로 나눠서 저장
    }

    // 각 줄의 첫 번째 사원을 우선순위 큐에 삽입
    for (int i = 0; i < M; i++) {
        if (!lines[i].empty()) {
            pq.push(lines[i].front());
            lines[i].pop();
        }
    }

    int count = 0; // 화장실을 사용한 사람 수

    while (!pq.empty()) {
        Employee topEmployee = pq.top();
        pq.pop();

        // 데카의 차례인지 확인
        if (topEmployee.lineNo == decaLine && decaIndex == 0) {
            cout << count << endl;
            return 0;
        }

        count++; // 한 사람이 화장실 이용 완료

        // 해당 줄에서 다음 사원이 있는 경우 추가
        if (!lines[topEmployee.lineNo].empty()) {
            pq.push(lines[topEmployee.lineNo].front());
            lines[topEmployee.lineNo].pop();
        }

        // 데카의 위치 조정
        if (topEmployee.lineNo == decaLine) {
            decaIndex--;
        }
    }

    return 0;
}
