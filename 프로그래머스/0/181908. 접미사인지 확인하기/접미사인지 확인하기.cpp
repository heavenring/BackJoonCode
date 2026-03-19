#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    
    int my_string_len = my_string.length();
    int suffix_len = is_suffix.length();
    
    if (my_string_len < suffix_len){
        return 0;
    }
    
    string temp = my_string.substr(my_string.length() - is_suffix.length());
    if (temp == is_suffix){
        return 1;
    }
    
    return answer;
}