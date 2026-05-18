#include <iostream>
#include <string>
#include <vector>

#define col_size 5
#define row_size 15

using namespace std;

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		vector<vector<string>> text(col_size, vector<string>(row_size));
		for (int i = 0; i < col_size; i++) {
			string input;
			cin >> input;

			for (int j = 0; j < input.size(); j++) {
				text[i][j] = input[j];
			}
		}

		cout << "#" << t << " ";
		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				cout << text[j][i];
			}
		}
		cout << "\n";
	}
}