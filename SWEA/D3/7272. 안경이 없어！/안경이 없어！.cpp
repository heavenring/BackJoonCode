#include <iostream>
#include <map>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	// ADOPQR -> 1
	// B -> 2
	map<char, int> c;
	c['A'] = c['D'] = c['O'] =c['P'] = c['Q'] = c['R'] = 1;
	c['B'] = 2;


	for (int t = 1; t <= tc; t++) {
		string text1, text2;
		cin >> text1 >> text2;

		bool same_check = true;
		if (text1.size() != text2.size()) {
			same_check = false;
		} else {
			for (int i = 0; i < text1.size(); i++) {
				if (c[text1[i]] != c[text2[i]]) {
					same_check = false;
					break;
				}
			}
		}

		if (same_check) {
			cout << "#" << t << " SAME" << endl;
		} else {
			cout << "#" << t << " DIFF" << endl;
		}
	}
}