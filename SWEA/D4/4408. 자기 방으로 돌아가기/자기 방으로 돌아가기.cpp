#include <iostream>
#include <vector>
#include <algorithm>

#define room_size 200

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		vector<int> rooms(room_size);
		for (int i = 0; i < n; i++) {
			int start, end;
			cin >> start >> end;

			if (start > end) {
				swap(start, end);
			}

			for (int j = (start - 1) / 2; j <= (end - 1) / 2; j++) {
				rooms[j]++;
			}
		}

		int answer = 0;
		for (int cnt : rooms) {
			answer = max(answer, cnt);
		}

		cout << "#" << t << " " << answer << "\n";
	}

}