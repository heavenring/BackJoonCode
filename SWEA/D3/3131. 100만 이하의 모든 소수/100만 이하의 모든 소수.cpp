#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	
	vector<bool> prime(1000001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i < prime.size(); i++) {
		if (prime[i]) {
			for (int j = i * i; j < prime.size(); j += i) {
				prime[j] = false;
			}
		}
	}

	for (int i = 2; i < prime.size(); i++) {
		if (prime[i]) {
			cout << i << " ";
		}
	}
}