from collections import deque

if __name__ == "__main__":
    n, m = map(int, input().split())

    # list 형식으로 사람들의 손 위치 저장
    floor = list()
    for i in range(1, m + 1):
        left_hand, right_hand = map(int, input().split())
        floor.append([left_hand, i])
        floor.append([right_hand, i])

    # 사람들의 손 위치를 순서대로 정렬
    floor.sort()

    # list를 deque로 변환
    floor = deque(floor)

    # n번째 사람 구하기
    for i in range(n):
        floor.append(floor.popleft())

    answer = floor.pop()
    print(answer[1])

