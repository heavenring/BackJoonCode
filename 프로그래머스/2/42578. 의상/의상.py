import itertools

# 해시를 조금이라도 넣어보고자 시도한 풀이
def solution(clothes):    
    cloth_count = dict()
    
    # 옷 종류에 따라 몇 개의 옷이 있는지 구한다
    for cloth in clothes:
        if cloth[1] in cloth_count:
            cloth_count[cloth[1]] += 1
        else:
            cloth_count[cloth[1]] = 1
    
    # 옷을 1개 입을 때 ~ 모든 종류의 옷을 입을때
    answer = 1
    for count in cloth_count.values():
        answer *= (count + 1)
        
    return answer - 1