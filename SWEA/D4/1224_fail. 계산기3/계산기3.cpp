#include <iostream>
#include <string>
#include <vector>

#define tc 10

using namespace std;


/* 숫자 여부 확인 */
bool num_check(char s) {

	if (s < '0' || s > '9') {
		return false;
	}

	return true;
}


/* 곱하기 우선 계산 */
string multi_calc(string input) {
	string result = "";
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '*' && num_check(input[i - 1]) && num_check(input[i + 1])) {

			// 곱하기 연산자 앞에 있는 숫자들을 모두 가져오기
			string temp_num1 = "";
			while (num_check(result.back()) && !result.empty()) {
				temp_num1 = result.back() + temp_num1;
				result.pop_back();
			}

			// 곱하기 연산자 뒤에 있는 숫자들을 모두 가져오기
			string temp_num2 = "";
			while (num_check(input[i + 1]) && i < input.size()) {
				temp_num2 += input[i + 1];
				i++;
			}

			int num1 = stoi(temp_num1);
			int num2 = stoi(temp_num2);
			result += to_string(num1 * num2);
		}
		else {
			result += input[i];
		}
	}

	return result;
}


/* 더하기 연산 */
string sum_calc(string input) {
	string result = "";
	for (int i = 0; i < input.size(); i++) {
		// 더하기 연산자의 앞과 뒤가 숫자일 경우
		if (input[i] == '+' && num_check(input[i - 1]) && num_check(input[i + 1])) {
			// 더하기 연산자 앞에 있는 숫자들을 모두 가져오기
			string temp_num1 = "";
			while (num_check(result.back()) && !result.empty()) {
				temp_num1 = result.back() + temp_num1;
				result.pop_back();
			}

			// 더하기 연산자 뒤에 있는 숫자들을 모두 가져오기
			string temp_num2 = "";
			while (num_check(input[i + 1]) && i < input.size()) {
				temp_num2 += input[i + 1];
				i++;
			}

			if (result.back() == '*' || input[i + 1] == '*') {
				result += temp_num1 + "+" + temp_num2;
			}
			else {
				int num1 = stoi(temp_num1);
				int num2 = stoi(temp_num2);
				result += to_string(num1 + num2);
			}
		}
		else {
			result += input[i];
		}
	}

	return result;
}


/* 괄호 연산 */
long long last_calc(string input) {

	vector<long long> nums;
	for (int i = 0; i < input.size(); i++) {
		if (num_check(input[i])) {
			string temp_num = "";
			while (num_check(input[i]) && i < input.size()) {
				temp_num += input[i];
				i++;
			}

			nums.push_back(stoll(temp_num));
		}
		else if (input[i] == '*') {
			string temp_num = "";
			while (num_check(input[i + 1]) && i < input.size()) {
				temp_num += input[i + 1];
				i++;
			}

			long long num1 = nums.back();
			long long num2 = stoll(temp_num);
			nums.pop_back();

			nums.push_back(num1 * num2);
		}
	}

	long long result = 0;
	for (long long num : nums) {
		result += num;
	}

	return result;
}



int main() {

	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		string input;
		cin >> input;

		input = multi_calc(input);
		input = sum_calc(input);
		long long answer = last_calc(input);
		cout << "#" << t << " " << answer << endl;
	}
}