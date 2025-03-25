def solution(X, Y):
    answer = ''
    
    x_list = [0 for i in range(10)]
    y_list = [0 for i in range(10)]
    
    for num in X:
        x_list[int(num)] += 1
        
    for num in Y:
        y_list[int(num)] += 1
    
    x_list.reverse()
    y_list.reverse()
    
    for i in range(10):
        for num in range(min(x_list[i], y_list[i])):
            answer += str(9 - i)
            if answer == "0":
                break
    
    if answer == "":
        answer = "-1"
        
    return answer