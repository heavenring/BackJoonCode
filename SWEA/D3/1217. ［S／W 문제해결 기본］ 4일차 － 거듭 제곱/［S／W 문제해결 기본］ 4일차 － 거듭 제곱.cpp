#include <iostream>

#define tc 10

using namespace std;


/* 거듭제곱 계산 */
int calc(int n, int m) {

	if (m == 0) {
		return 1;
	} else {
		return calc(n, m - 1) * n;
	}
}


int main() {
	
	for (int t = 1; t <= tc; t++) {
		int tc_num;
		cin >> tc_num;

		int n, m;
		cin >> n >> m;

		cout << "#" << tc_num << " " << calc(n, m) << endl;
	}
}