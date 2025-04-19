# list에 다리 길이만큼 deque 생성
# 생성한 deque에 트럭을 하나씩 넣는다
# 다리 위 트럭의 무게를 변수에 저장한다
# 트럭의 무게가 다리 무게보다 가볍게 유지한다
# 트럭의 개수가 0개가 될 때 까지 반복한다

from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0
    
    # 다리 위 트럭을 계산할 deque를 만든다.
    bridge_on_truck = deque()
    for i in range(bridge_length):
        bridge_on_truck.append(0)
        
    # 다리 위 트럭의 무게
    bridge_on_truck_weight = 0
    
    # 운송이 필요한 트럭이 0개일 때 까지 반복한다.
    while len(truck_weights):
        answer += 1
        
        # 트럭이 다리를 지났을 때
        bridge_on_truck_weight -= bridge_on_truck.popleft()
        
        # 다리 위에 새로운 트럭이 올라갈 수 있다면
        if bridge_on_truck_weight + truck_weights[0] <= weight:
            # 현재 무게를 업데이트 하고,
            bridge_on_truck_weight += truck_weights[0]
            # 다리에 트럭을 올린다
            bridge_on_truck.append(truck_weights[0])
            # 다리에 올라간 트럭은 리스트에서 제거한다
            del truck_weights[0]
        # 다리 위에 새로운 트럭이 올라갈 수 없다면
        else:
            # 트럭을 앞으로 이동시킨다
            bridge_on_truck.append(0)
    
    # 마지막으로 올라간 트럭이 다리를 지나는 시간을 더한다
    answer += bridge_length
        
    return answer