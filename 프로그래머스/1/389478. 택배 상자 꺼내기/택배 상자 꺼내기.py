# n / w -> 전체 층 수
# num / w 꺼낼 택배의 층 수
# 짝수 번째의 정방향, 홀수 번째의 반대방향
# 마지막으로 올라간 박스의 번호만 계산하면 됨
# 정방향인지 반대방향인지에 따라 박스를 두는 위치가 달라딘다
# 계산식이 있을거 같은데... 
# 1층 1 ~ 6 
# 2층 2*w - (0 ~ 5) 
# 3층 2*w + (1 ~ 6)
# 4층 4*w - (0 ~ 5) 

# 택배 번호 받고~ + a를 해서 올라간다
# a는 윗 택배 번호를 구해야한다
# w를 반으로 나눠 찾는 택배 번호가 왼쪽인지 오른쪽인지 구분한다
# 왼쪽 + 짝수층 이라면 (num - (num / w) * w) + w + 1

# 왼쪽과 오른쪽으로 나눈 후
# 시작 위치를 1 ~ w으로 찾아둔다 (num - (num / w) * w)
# 최상단으로 올라가 끝 위치를 1 ~ w으로 찾아둔다 (n - (n / w) * w)
# 홀수층의 경우 반대로 계산한다 w - 위치
# 최상단의 택배 번호가 시작위치 번호보다 작다면 그대로 크다면 +1을 한다

def solution(n, w, num):
    answer = 0
    
    all_f = (n - 1) // w 
    box_f = (num - 1) // w 
    
    start_f = num - ((num - 1) // w) * w 
    end_f = n - ((n - 1) // w) * w 
    
    if box_f % 2 != all_f % 2:
        if w - start_f + 1 <= end_f:
            answer = all_f - box_f + 1
        else:
            answer = all_f - box_f
    else:
        if start_f <= end_f:
            answer = all_f - box_f + 1
        else:
            answer = all_f - box_f   
    
    print("all_f: ", all_f)
    print("box_f: ", box_f)
    print("start_f: ", start_f)
    print("end_f: ", end_f)
    
    
    return answer