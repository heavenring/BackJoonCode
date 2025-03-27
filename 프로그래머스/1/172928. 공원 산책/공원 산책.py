# park의 w와 h를 저장해둔다
# park를 순회하여 S의 위치 좌표를 answer에 저장한다
# routes를 순회하며 w와 h를 계산한다
# 계산 도중 -1 < answer[0] < w and -1 < answer[1] < h인지 확인한다
# 못가는 좌표라면 이동한 좌표를 돌려놓는다

def location_check_w(park, now_location, mv, h):
    
    if -1 < mv < len(park[0]):
        check = True
        for i in range(now_location, mv + 1):
            if park[h][i] == 'X':
                return False    
            
        for i in range(mv, now_location + 1):
            if park[h][i] == 'X':
                return False    
        
        return True
    else:
        return False 
    


def location_check_h(park, now_location, mv, w):
    
    if -1 < mv < len(park):
        check = True
        for i in range(now_location, mv + 1):
            if park[i][w] == 'X':
                return False
        
        for i in range(mv, now_location + 1):
            if park[i][w] == 'X':
                return False
        
        return True    
    else:
        return False 
    
    

    
def solution(park, routes):
    answer = []
    
    # park의 크기를 저장한다
    w = len(park[0])
    h = len(park)
    
    # 로봇의 시작 위치를 찾는다
    i = 0
    while not answer:
        j = 0
        while j < w:
            if park[i][j] == 'S':
                answer = [i, j]
                break
            j += 1
        i += 1   
    
    
    # routes를 순회
    for data in routes:
        # 방향과 이동칸 확인
        if data[0] == 'E':
            if location_check_w(park, answer[1], answer[1] + int(data[2]), answer[0]):
                answer[1] += int(data[2])
        elif data[0] == 'W':
            if location_check_w(park, answer[1], answer[1] - int(data[2]), answer[0]):
                answer[1] -= int(data[2])
        elif data[0] == 'S':
            if location_check_h(park, answer[0], answer[0] + int(data[2]), answer[1]):
                answer[0] += int(data[2])
        elif data[0] == 'N':
            if location_check_h(park, answer[0], answer[0] - int(data[2]), answer[1]):
                answer[0] -= int(data[2])
        
        
    return answer