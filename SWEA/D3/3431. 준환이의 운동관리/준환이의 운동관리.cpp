#include <iostream>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		long long l, u, x;
		cin >> l >> u >> x;

		long long answer = 0;
		if (x > u) {
			answer = -1;
		}
		else if (x < l) {
			answer = l - x;
		}

		cout << "#" << t << " " << answer << "\n";
	}
}