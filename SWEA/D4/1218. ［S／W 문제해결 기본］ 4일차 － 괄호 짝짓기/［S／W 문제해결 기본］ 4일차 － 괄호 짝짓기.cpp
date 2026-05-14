#include <iostream>
#include <vector>

#define tc 10

using namespace std;

int main() {
	
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		string input;
		cin >> input;

		bool check = true;
		vector<char> stack;
		for (int i = 0; i < n && check; i++) {
			if (input[i] == '(' || input[i] == '[' || input[i] == '{' || input[i] == '<') {
				stack.push_back(input[i]);
			} else {
				if (!stack.empty()) {
					char top = stack.back();
					if ((top == '(' && input[i] == ')') ||
						(top == '[' && input[i] == ']') ||
						(top == '{' && input[i] == '}') ||
						(top == '<' && input[i] == '>')) {
						stack.pop_back();
					} else {
						check = false;
					}
				} else {
					check = false;
				}
			}
		}

		if (check && stack.empty()) {
			cout << "#" << t << " 1" << endl;
		} else {
			cout << "#" << t << " 0" << endl;
		}
	}
}