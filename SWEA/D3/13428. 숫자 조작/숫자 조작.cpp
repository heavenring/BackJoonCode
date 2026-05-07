#include <iostream>
#include <algorithm>

using namespace std;


/* 가장 작은 수 생성 */
string find_min_num(string origin_num, int idx) {
	
	// 가장 작은 숫자 중 맨 뒤에 있는 숫자의 인덱스 탐색
	int min_idx = idx;
	int min_num = origin_num[idx] - '0';
	for (int i = idx; i < origin_num.size(); i++) {
		// 가장 작은 수가 0일 경우 제외
		if (min_num >= origin_num[i] - '0' && (idx || origin_num[i] != '0')) {
			min_num = origin_num[i] - '0';
			min_idx = i;
		}
	}

	// 가장 작은 숫자의 인덱스와 현재 인덱스 위치 변경
	swap(origin_num[idx], origin_num[min_idx]);

	return origin_num;
}


/* 가장 큰 수 생성 */
string find_max_num(string origin_num, int idx) {

	// 가장 뒤에 있는 가장 큰 수의 인덱스 탐색
	int max_idx = idx;
	int max_num = origin_num[idx] - '0';
	for (int i = idx; i < origin_num.size(); i++) {
		if (max_num <= origin_num[i] - '0') {
			max_num = origin_num[i] - '0';
			max_idx = i;
		}
	}

	// 가장 큰 수의 인덱스와 현재 인덱스 위치 변경
	swap(origin_num[idx], origin_num[max_idx]);

	return origin_num;
}


int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		string origin_num;
		cin >> origin_num;
		
		/**
		* origin_num의 크기 만큼 반복문을 돌린다
		* 현재 인덱스를 기준으로 다음 인덱스 부터 끝까지 탐색하여 가장 작은 수를 반환 받는다
		* 반환 받은 숫자가 origin_num보다 작으면 출력, 크거나 같다면 다음 인덱스 기준으로 다시 반복문을 돌린다
		* 이를 크게 만드는 경우에도 반복한다
		*/

		string min_num = origin_num;
		for (int i = 0; i < origin_num.size(); i++) {
			string temp = find_min_num(origin_num, i);
			if (temp < min_num) {
				min_num = temp;
				break;
			}
		}

		string max_num = origin_num;
		for (int i = 0; i < origin_num.size(); i++) {
			string temp = find_max_num(origin_num, i);
			if (temp > max_num) {
				max_num = temp;
				break;
			}
		}

		cout << "#" << t << " " << min_num << " " << max_num << "\n";
	}
}