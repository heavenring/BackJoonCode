#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		string n;
		cin >> n;

		vector<int> num_cnt(10, 0);
		for (char c : n) {
			num_cnt[c - '0']++;
		}

		// n의 배수 중에서 n과 자리수가 달라질 경우 탐색 중단
		bool is_possible = false;
		long long num = stoll(n);
		for (int i = 2; to_string(num * i).size() == n.size(); i++) {
			string temp = to_string(num * i);

			// n의 배수인 temp의 각 자리 숫자 개수 세기
			vector<int> temp_num_cnt(10, 0);
			for (char c : temp) {
				temp_num_cnt[c - '0']++;
			}

			// n과 temp의 각 자리 숫자 개수가 같다면
			// 더 큰 배수 만들기 가능
			if (temp_num_cnt == num_cnt) {
				is_possible = true;
				break;
			}
		}

		cout << "#" << t << " " << (is_possible ? "possible" : "impossible") << "\n";
	}
}