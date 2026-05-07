#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		vector<string> cards(n);
		for (int i = 0; i < n; i++) {
			cin >> cards[i];
		}

		/**
		* 6 -> 0 1 2 3 4 5 -> 0 1 2, 3 4 5 -> 0 3 1 4 2 5
		* 0 0
		* 1 3
		* 2 1
		* 3 4
		* 4 2
		* 5 5
		* idx / 2
		* idx / 2 + 3
		* 
		* 7 -> 0 1 2 3 4 5 6 -> 0 1 2 3, 4 5 6 -> 0 4 1 5 2 6 3
		* 0 0
		* 1 4
		* 2 1
		* 3 5
		* 4 2
		* 5 6
		* 6 3
		* idx / 2
		* idx / 2 + n / 2
		*/

		
		// 출력
		cout << "#" << t << " ";
		for (int i = 0; i < n; i++) {
			// 홀수 인덱스일 때
			if (i % 2) {
				if (n % 2) {
					// 홀수라면 카드의 절반보다 1이 더 많은 수를 더해준다.
					cout << cards[i / 2 + n / 2 + 1] << " ";
				} else {
					// 짝수라면 카드의 절반을 더해준다.
					cout << cards[i / 2 + n / 2] << " ";
				}
			} else {
				cout << cards[i / 2] << " ";
			}
		}
		cout << endl;
	}
}