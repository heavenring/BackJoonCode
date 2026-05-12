#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		vector<long long> price(n * 2);
		for (int i = 0; i < price.size(); i++) {
			cin >> price[i];
		}

		cout << "#" << t;
		for (int i = 0; i < price.size(); i++) {
			// 할인가로 추정되는 가격일 경우
			// ㄴ 정가가 4배수 일때, 할인가는 정가의 75%이기 때문에 3배수 이다
			if (price[i] != -1 && price[i] % 3 == 0) {
				// 나머지 가격표 중에서 정가 탐색
				for (int j = i + 1; j < price.size(); j++) {
					// 할인가를 정가로 역산했을 때의 정가가 존재 시
					if (price[j] == price[i] / 3.0 * 4.0) {
						cout << " " << price[i];
						price[j] = -1;
						break;
					}
				}
			}
		}
		cout << "\n";
	}
}