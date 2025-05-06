# 각 인원의 방문 시간을 저장한다 -> list
# 각 인원의 방문 시간 텀을 계산한다 -> list
# time을 오름차 순으로 정렬한다
# 난로의 최대 가동 시간 -= (time[-1][0] - 1)으로 난로 가동 시간을 줄인다
# 이를 성냥의 개수 - 1번 반복한다


if __name__ == '__main__':
    n, k = map(int, input().split())

    # 방문 시간 저장
    visit_time = list()
    for i in range(n):
        visit_time.append(int(input()))

    # 방문 시간 텀 구하기
    time = list()
    for i in range(1, n):
        time.append(visit_time[i] - visit_time[i - 1])

    # print(f"time: {time}")

    # 방문 시간이 짧은 순서로 정렬한다 -> 오름차순
    time.sort()
    # print(f"tiem_sort: {time}")

    # 난로의 가동 시간을 계산한다
    answer = visit_time[-1]
    for i in range(k - 1):
        # print(f"answer: {answer}")
        answer -= (time[-1] - 1)
        time.pop()

    print(answer - (visit_time[0] - 1))




