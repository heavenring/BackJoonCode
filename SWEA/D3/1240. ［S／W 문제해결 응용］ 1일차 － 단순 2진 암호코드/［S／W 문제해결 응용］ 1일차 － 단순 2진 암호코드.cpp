#include <iostream>
#include <string>

#define total_code_size 56
#define code_size 7
#define zero "0001101"
#define one "0011001"
#define two "0010011"
#define three "0111101"
#define four "0100011"
#define five "0110001"
#define six "0101111"
#define seven "0111011"
#define eight "0110111"
#define nine "0001011"

using namespace std;


/* 코드가 존재하는 문자열 여부 반환 */
bool code_exist(string str) {

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '1') {
			return true;
		}
	}
	
	return false;
}


/* 이진코드와 매칭되는 숫자 반환 */
string match_code(string code) {
	
	string result = "";
	if (code == zero) {
		result = "0";
	}
	else if (code == one) {
		result = "1";
	}
	else if (code == two) {
		result = "2";
	}
	else if (code == three) {
		result = "3";
	}
	else if (code == four) {
		result = "4";
	}
	else if (code == five) {
		result = "5";
	}
	else if (code == six) {
		result = "6";
	}
	else if (code == seven) {
		result = "7";
	}
	else if (code == eight) {
		result = "8";
	}
	else if (code == nine) {
		result = "9";
	}

	return result;
}


/* 문자열 내 코드 탐색 및 반환 */
string find_code(string str) {
	
	// 7자리 문자열을 읽어 이진 코드 탐색
	// 코드가 8자리가 될 경우 탐색 중지
	string result = "";
	for (int i = 0; i < str.size() - total_code_size; i++) {
		string temp_code = "";
		for (int j = i; j < i + total_code_size; j += code_size) {
			string code = str.substr(j, code_size);
			temp_code += match_code(code);
		}

		if (temp_code.size() == 8) {
			result = temp_code;
			break;
		}
	}

	return result;
}


/* 올바른 이진 코드 여부 반환 */
bool code_check(string code) {

	long long result = 0;
	for (int i = 0; i < code.size(); i++) {
		if (i % 2) {
			result += code[i] - '0';
		} else {
			result += (code[i] - '0') * 3;
		}
	}

	if (result % 10) {
		return 0;
	} else {
		return result;
	}
}


/* 반환 값 계산 */
long long calc_answer(string code) {

	long long result = 0;
	for (int i = 0; i < code.size(); i++) {
		result += code[i] - '0';
	}

	return result;
}


int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, m;
		cin >> n >> m;

		long long answer = 0;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;

			if (code_exist(str) && !answer) {
				string code = find_code(str);
				if (code_check(code)) {
					answer = calc_answer(code);
				}
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}
}