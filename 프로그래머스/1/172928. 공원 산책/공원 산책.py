def solution(park, routes):
    answer = []
    
    # 시작 위치 찾기
    for i in range(len(park)):
        for j in range(len(park[0])):
            if park[i][j] == 'S':
                answer = [i, j]
                
    # 이동 방향에 따른 거리 계산
    mv_x = {'E': 1, 'W': -1, 'S': 0, 'N': 0}
    mv_y = {'E': 0, 'W': 0, 'S': 1, 'N': -1}
    for route in routes:
        direction, mv = route.split(' ')
        
        # 현 위치부터 이동할 위치까지 한 칸씩 이동
        for i in range(1, int(mv) + 1):
            # 이동한 위치 계산
            w, h = answer[1] + mv_x[direction] * i, answer[0] + mv_y[direction] * i
            
            # 이동한 위치가 공원 범위에서 벗어나지 않는지 확인
            if not (-1 < w < len(park[0]) and -1 < h < len(park)):
                break
            
            # 이동한 위치에 장애물이 있는지 확인
            if park[h][w] == 'X':
                break
                
        # 이동이 가능한 위치라면 위치 이동
        else:
            answer[0] += mv_y[direction] * i
            answer[1] += mv_x[direction] * i    
            
    
    return answer