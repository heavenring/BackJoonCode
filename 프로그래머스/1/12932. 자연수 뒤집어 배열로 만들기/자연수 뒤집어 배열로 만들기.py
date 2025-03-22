def solution(n):
    answer = []
    
    num = n
    while num > 0:
        answer.append(num % 10)
        num //= 10
    
    return answer