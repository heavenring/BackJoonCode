#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer = num_list;
    
    int last_index = num_list.size() - 1;
    int before_index = num_list.size() - 2;
    
    if (num_list[last_index] > num_list[before_index]) {
        answer.push_back(num_list[last_index] - num_list[before_index]);
    } else {
        answer.push_back(num_list[last_index] * 2);
    }
    
    
    return answer;
}