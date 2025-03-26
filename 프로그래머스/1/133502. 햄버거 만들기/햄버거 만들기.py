# 1, 2, 3, 1 순으로 열이 이어져야 함
# 재료를 한바퀴 순회한다
# 순회하는동안 빵이 나오면 이후 3개를 탐색한다
# 탐색이 성공하면 del ingredient[i:i+4]
# pre_bread[-1]의 위치로 돌아가 이후 3개를 재탐색 한다
# 탐색에 실패하면 pre_bread.append(i)

def solution(ingredient):
    answer = 0
    
    pre_bread = []
    
    i = 0
    while i < len(ingredient):
        # 빵을 찾았을 때 햄버거를 만들 재료가 있는지 확인
        if ingredient[i] == 1 and i + 4 <= len(ingredient):
            # 햄버거가 만들어지면 재료 삭제
            if ingredient[i:i + 4] == [1, 2, 3, 1]:
                del ingredient[i:i + 4]
                answer += 1
                
                # 이전에 발견한 빵이 있다면 해당 빵 위치로 이동
                if pre_bread:
                    i = pre_bread[-1] - 1
                    del pre_bread[-1]
                # 이전에 발견한 빵이 없다면 바로 뒤로 이동
                else:
                    i -= 1
                    
            # 햄버거가 만들어지지 않으면 빵 위치 저장
            else:
                pre_bread.append(i)        
        
        i += 1
            
    return answer