num = int(input())
rocks = input().split(' ')

answer = 0
rock_nums = ['1', '2']
for rock_num in rock_nums:
    count = 0
    for forward in rocks:
        if forward == rock_num:
            count += 1
        else:
            count -= 1

            if count < 0:
                count = 0

        if answer < count:
            answer = count


print(answer)