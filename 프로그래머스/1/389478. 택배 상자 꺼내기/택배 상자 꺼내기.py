# 로직 수정
# (w - num) * 2 + 1 위 박스와의 차이
# 2*w - num + 1 -> (12 - 8) * 2 + 1 -> 
# (w - num) * 2 + 1
# (2*w - num) * 2 + 1

def solution(n, w, num):
    answer = 0
    
    # 층 계산
    floor = (num - 1) // w + 1    
    while n >= num: # 위에 박스가 없을 때 까지 반복
        answer += 1
        
        print(f"floor: {floor}")
        print(f"num: {num}")
        
        # 위 박스와의 거리 차이 계산
        num += (floor * w - num) * 2 + 1 
        floor += 1
        
    return answer