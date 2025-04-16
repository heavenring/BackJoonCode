# 2개의 풀이 있음
def solution(s):
    answer = True
    
# 1.
    if s[0] == ')':
        return False
    else:
        check_list = [s[0]]
        for char in s[1:]:
            # check_list가 비어있을 때
            if not len(check_list):
                if char == ')': # 닫는 괄호가 나온다면 false
                    return False
                else: # 아니라면 리스트에 추가
                    check_list.append(char)
            # check_list에 문자가 있을 때
            else:
                if char == ')':
                    del check_list[-1]
                else:
                    check_list.append(char)
                    
    if len(check_list):
        return False
    else:
        return True
                
    
    
# 2. 
#     # dict를 사용해 계산
#     # 열고 제대로 닫힌다면 check는 0이 된다.
#     dic = {'(': 1, ')': -1}
    
#     check = 0
#     for char in s:
#         check += dic[char]
        
#         # 만일 먼저 닫혀서 -1이 될 경우 뒷 문자는 확인하지 않는다.
#         if check == -1:
#             break;
    
#     # 문자를 확인한 결과 check가 0이 아니라면 잘못된 괄호 배열이다.
#     if check:
#         answer = False
        
#     return answer