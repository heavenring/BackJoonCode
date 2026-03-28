#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    // 홀수
    long long a = 0;
    
    // 짝수
    long long b = 0;
    
    for (int num : num_list){
        if (num % 2) {
            a = a * 10 + num;
        } else {
            b = b * 10 + num;
        }
    }
    
    
    return a + b;
}