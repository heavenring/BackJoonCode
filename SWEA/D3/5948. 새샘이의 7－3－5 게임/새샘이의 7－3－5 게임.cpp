#include <iostream>
#include <vector>
#include <set>

#define input_cnt 7

using namespace std;

/* 3개의 수 선택 조합 */
void combination(vector<int>& input, set<int>& sum_set, int idx, int sum, int count) {
	
	if (count == 3) {
		sum_set.insert(sum);
		return;
	}

	for (int i = idx; i < input_cnt; i++) {
		combination(input, sum_set, i + 1, sum + input[i], count + 1);
	}
}


int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		
		vector<int> input(input_cnt);
		for (int i = 0; i < input_cnt; i++) {
			cin >> input[i];
		}

		// -- 풀이 방법 종류 --
		// 1. 숫자 3개의 합을 vector에 저장후 정렬한다
		//    ㄴ 이후 중복 값을 제거해 나가며 5번째로 큰 값을 출력한다
		// 2. 숫자 3개의 합을 set에 저장해서 정렬 후 5번째로 큰 값을 출력한다

		set<int> sum_set;
		combination(input, sum_set, 0, 0, 0);

		// set의 뒤에서 5번째로 큰 값을 찾는다
		auto answer = sum_set.end();
		for (int i = 0; i < 5; i++) {
			--answer;
		}

		cout << "#" << t << " " << *answer << endl;
	}
}