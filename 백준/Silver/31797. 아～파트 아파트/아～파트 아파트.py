from collections import deque

if __name__ == "__main__":
    n, m = map(int, input().split())

    # list 형식으로 사람들의 손 위치 저장
    floor = list()
    for i in range(1, m + 1):
        left_hand, right_hand = map(int, input().split())
        floor.append((left_hand, i))
        floor.append((right_hand, i))

    # 사람들의 손 위치를 순서대로 정렬
    floor.sort()
    
    # 마지막으로 올라가는 손 위치 계산
    index = n % len(floor) - 1
    print(floor[index][1])
