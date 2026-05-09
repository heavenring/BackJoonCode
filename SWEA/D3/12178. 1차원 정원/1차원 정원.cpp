#include <iostream>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, d;
		cin >> n >> d;

		long long answer = 0;
		for (int i = 0; i < n; i += (d * 2 + 1)) {
			answer++;
		}

		cout << "#" << t << " " << answer << endl;
	}
}