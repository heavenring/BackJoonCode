#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		vector<string> answer(n + 1);
		for (int i = 0; i < n / 2; i++) {
			
			// A팀 선수 지명
			for (int j = 0; j < n; j++) {
				if (answer[a[j]].empty()) {	
					answer[a[j]] = "A";
					break;
				}
			}

			// B팀 선수 지명
			for (int j = 0; j < n; j++) {
				if (answer[b[j]].empty()) {
					answer[b[j]] = "B";
					break;
				}
			}
		}

		// 결과 출력
		for (int i = 1; i <= n; i++) {
			// 결과 출력 시 남은 사람은 A팀으로 간주
			if (answer[i].empty()) {
				answer[i] = "A";
			}

			cout << answer[i];
		}
		cout << endl;
	}
}