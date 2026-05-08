#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, m;
		cin >> n >> m;

		vector<bool> students(n + 1, true);
		for (int i = 0; i < m; i++) {
			int student_num;
			cin >> student_num;

			students[student_num] = false;
		}
		
		cout << "#" << t << " ";
		for (int i = 1; i <= n; i++) {
			if (students[i]) {
				cout << i << " ";
			}
		}
		cout << "\n";
	}
}