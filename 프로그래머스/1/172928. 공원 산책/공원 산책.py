# park의 w와 h를 저장해둔다
# park를 순회하여 S의 위치 좌표를 answer에 저장한다
# routes를 순회하며 w와 h를 계산한다
# 계산 도중 -1 < answer[0] < w and -1 < answer[1] < h인지 확인한다
# 이동하는 좌표 사이에 장애물이 있는지 확인한다
# 못가는 좌표라면 이동한 좌표를 돌려놓는다


# E 좌표로 이동할 경우
def location_check_E(park, answer, mv):
    
    # 이동 가능한 위치인가
    if -1 < answer[1] + mv < len(park[0]):
        check = True
        # 이동하는데 장애물이 있는가
        for j in range(answer[1], answer[1] + mv + 1):
            if park[answer[0]][j] == 'X':
                return False    
        
        return True
    else:
        return False 


# W 좌표로 이동할 경우
def location_check_W(park, answer, mv):
    
    # 이동 가능한 위치인가
    if -1 < answer[1] - mv < len(park[0]):
        check = True 
        # 이동하는데 장애물이 있는가
        for j in range(answer[1] - mv, answer[1] + 1):
            if park[answer[0]][j] == 'X':
                return False    
        
        return True
    else:
        return False     

    
# S 좌표로 이동할 경우
def location_check_S(park, answer, mv):
    
    # 이동 가능한 위치인가
    if -1 < answer[0] + mv < len(park):
        check = True
        # 이동하는데 장애물이 있는가
        for i in range(answer[0], answer[0] + mv + 1):
            if park[i][answer[1]] == 'X':
                return False
        
        return True    
    else:
        return False 
    

# N 좌표로 이동할 경우
def location_check_N(park, answer, mv):
    
    # 이동 가능한 위치인가
    if -1 < answer[0] - mv < len(park):
        check = True
        # 이동하는데 장애물이 있는가
        for i in range(answer[0] - mv, answer[0] + 1):
            if park[i][answer[1]] == 'X':
                return False
        
        return True    
    else:
        return False 
    
    
def solution(park, routes):
    answer = []
    
    # 로봇의 시작 위치를 찾는다
    i = 0
    while not answer: # answer이 비어있지 않다면 반복
        j = 0
        while j < len(park[0]):
            if park[i][j] == 'S':
                answer = [i, j]
                break
            j += 1
        i += 1   
    
    
    # routes를 순회
    for data in routes:
        # 방향에 따라 이동 가능한지 확인
        if data[0] == 'E':
            # 이동 가능 여부 메소드에 park, 현재 좌표, 이동 거리를 인자로 전달 
            if location_check_E(park, answer, int(data[2])):
                answer[1] += int(data[2])
                
        elif data[0] == 'W':
            if location_check_W(park, answer, int(data[2])):
                answer[1] -= int(data[2])
                
        elif data[0] == 'S':
            if location_check_S(park, answer, int(data[2])):
                answer[0] += int(data[2])
                
        elif data[0] == 'N':
            if location_check_N(park, answer, int(data[2])):
                answer[0] -= int(data[2])
        
        
    return answer