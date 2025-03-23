def solution(n, m):
    answer = []
    
    # 최대 공약수
    max_num = max([n, m]) # n, m중 큰 수 찾기
    while n % max_num or m % max_num: # 가장 큰 수부터 나누며 나머지 확인
        max_num -= 1
        
    answer.append(max_num)
    
    # 최소 공배수
    origin_n = n
    origin_m = m
    while n != m:
        if n < m:
            n += origin_n
        else:
            m += origin_m
    
    answer.append(n)
    
    return answer