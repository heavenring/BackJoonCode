# 주식 가격의 등락을 입력 받는다
# 0번째 주식을 n번째 까지 반복시켜서
# 가격이 낮은걸 만나면 break 및 answer.append()
# 이걸 배열이 빌 때 까지 반복
# -> o(n!)

# 

from collections import deque

def solution(prices):
    answer = []
    
    prices = deque(prices)
    
    i = 0
    while len(prices):
        count = 0
        price = prices.popleft()
        for p in prices:
            count += 1
            if price > p:
                break
            
        answer.append(count)
        
    return answer