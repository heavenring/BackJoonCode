num = int(input())
rocks = list(map(int, input().split(' ')))

answer = 0
# 왼쪽 돌상, 오른쪽 돌상 구분
for rock_num in range(1, 3):
    count = 0
    for forward in rocks: 
        # 해당 돌상이 구하고자 하는 돌상과 같은 방향을 본다면
        if forward == rock_num:
            count += 1
        else:
            count -= 1
            # 다른 방향을 보는 돌상이 더 많아 진다면 개수 초기화
            count = max(count, 0)
        
        # 같은 방향을 보는 돌상이 가장 많을 때 저장
        answer = max(answer, count)

print(answer)
