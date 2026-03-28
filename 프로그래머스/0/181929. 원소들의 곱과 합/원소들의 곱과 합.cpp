#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    int multi = 1;
    int sum = 0;
    
    for (int num : num_list){
        multi *= num;
        sum += num;
    }
    
    return pow(sum, 2) > multi;
}