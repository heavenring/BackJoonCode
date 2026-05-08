#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, p;
		cin >> n >> p;

		/**
		* n번의 이동 선택 기회가 주어진다
		* 각 이동은 기회 횟수만큼 층을 올라갈지, 대기할지 선택이 가능하다
		* 최대한 높은곳으로 이동하려고 할 때, 
		* p층에 도달하지 않도록 하는 최대 높이를 구하라
		* 
		* (엘리베이터는 0층에서 출발함에 유의하라)
		* 
		* -- 자연어 풀이 --
		* 1. dp를 사용할건데, 기본값은 0으로 초기화한다
		*    ㄴ dp의 인덱스는 선택 횟수이며,
		*    ㄴ 저장된 값은 이동한 층의 높이이다
		* 2. 폭탄이 있는 p층에는 -1을 저장한다
		* 3. dp를 갱신할 때 현재 ~ 1번째 선택까지의 선택을 모두 고려하여 갱신한다
		*    ㄴ dp[i] = max(dp[i - 1], dp[i - 2 ~ 0]) + i
		* 4. 갱신 시 p층에 도달할 경우는 갱신하지 않는다
		* 
		* -- 추가 수정 사항 --
		* 1. dp의 인덱스가 선택 횟수이기 때문에 dp[p]에 -1을 저장할 필요 없다
		* 2. 폭탄이 1개임을 감안하여 
		*    ㄴ만약 이동한 층의 높이가 p층일 경우
		*    ㄴ 1층을 올라가지 않는 선택을 한 번만 한다.
		*/ 

		long long answer = 0;
		for (int i = 1; i <= n; i++) {
			answer += i;

			if (answer == p) {
				answer -= 1;
			}
		}

		cout << answer << "\n";
	}
}