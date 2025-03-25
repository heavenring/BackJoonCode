def solution(X, Y):
    answer = ''
    
    x_list = [0 for i in range(10)]
    y_list = [0 for i in range(10)]
    
    # 어떤 숫자가 몇개 있는지 확인
    # 내림차 순으로 숫자 개수 저장
    for num in X:
        x_list[9 - int(num)] += 1
        
    for num in Y:
        y_list[9 - int(num)] += 1
        
    
    for i in range(10):
        # 더 적은 개수 == 겹치는 숫자 개수
        for num in range(min(x_list[i], y_list[i])):
            answer += str(9 - i)
            
            # answer == "0"일 경우 이후는 "0"만 붙기 때문에 break
            if answer == "0":
                break
    
    if answer == "":
        answer = "-1"
        
    return answer