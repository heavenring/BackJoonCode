#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

/* 기본 map 세팅 */
map<string, string> set_map() {

	map<string, string> map;
	map["0"] = "ZRO";
	map["1"] = "ONE";
	map["2"] = "TWO";
	map["3"] = "THR";
	map["4"] = "FOR";
	map["5"] = "FIV";
	map["6"] = "SIX";
	map["7"] = "SVN";
	map["8"] = "EGT";
	map["9"] = "NIN";

	map["ZRO"] = "0";
	map["ONE"] = "1";
	map["TWO"] = "2";
	map["THR"] = "3";
	map["FOR"] = "4";
	map["FIV"] = "5";
	map["SIX"] = "6";
	map["SVN"] = "7";
	map["EGT"] = "8";
	map["NIN"] = "9";
	
	return map;
}


int main() {
	int tc;
	cin >> tc;

	map<string, string> map = set_map();

	for (int t = 1; t <= tc; t++) {
		string order;
		long long n;
		cin >> order >> n;

		vector<int> num(n);
		for (int i = 0; i < n; i++) {
			string num_str;
			cin >> num_str;

			num[i] = stoi(map[num_str]);
		}

		sort(num.begin(), num.end());

		cout << order << "\n";
		for (int i = 0; i < n; i++) {
			cout << map[to_string(num[i])] << " ";
		}
		cout << "\n";
	}
}