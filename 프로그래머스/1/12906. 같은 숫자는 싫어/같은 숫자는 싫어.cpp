#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int now = -1;
    for(int i = 0; i < arr.size(); i++){
        if (now != arr[i]){
            answer.push_back(arr[i]);
            now = arr[i];
        }
    }

    return answer;
}