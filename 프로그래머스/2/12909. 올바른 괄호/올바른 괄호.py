def solution(s):
    answer = True
    
    # dict를 사용해 계산
    # 열고 제대로 닫힌다면 check는 0이 된다.
    dic = {'(': 1, ')': -1}
    
    check = 0
    for char in s:
        check += dic[char]
        
        # 만일 먼저 닫혀서 -1이 될 경우 뒷 문자는 확인하지 않는다.
        if check == -1:
            break;
    
    # 문자를 확인한 결과 check가 0이 아니라면 잘못된 괄호 배열이다.
    if check:
        answer = False
        
    return answer