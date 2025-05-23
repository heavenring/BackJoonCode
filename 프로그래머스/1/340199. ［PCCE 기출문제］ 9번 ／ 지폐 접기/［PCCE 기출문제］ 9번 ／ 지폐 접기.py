def solution(wallet, bill):
    answer = 0
    
    while True:
        if wallet[0] >= bill[0] and wallet[1] >= bill[1]:
            break
        elif wallet[0] >= bill[1] and wallet[1] >= bill[0]:
            break
        
        if bill[0] > bill[1]:
            bill[0] //= 2
        else:
            bill[1] //= 2
        
        answer += 1
        print(f"answer = {answer}")
        print(f"bill[0] = {bill[0]} bill[1] = {bill[1]}")
        print("-----------------------------------------")
        
    return answer