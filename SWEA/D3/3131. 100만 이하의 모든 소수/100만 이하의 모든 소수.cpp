#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	
	string answer = "";
	vector<bool> prime(1000001, true);
	prime[0] = prime[1] = false;
	for (long long i = 2; i <= 1000000; i++) {
		if (prime[i]) {
			answer += to_string(i) + " ";

			for (long long j = i * i; j <= 1000000; j += i) {
				prime[j] = false;
			}
		}
	}

	cout << answer;
}