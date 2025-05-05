# 장르당 곡의 고유 번호: 재생횟수형식의 dict 타입으로 dict에 저장 -> 2차원 dict
# 장르에 속한 곡들의 재생횟수를 합한 dict 생성
# 재생 횟수에 따라 내림차순으로 장르 정렬
# 정렬한 장르 순으로 2차원 dict에서 장르에 속하는 곡 수령
# sorted(lambda x: x[1])으로 각각의 곡 재생횟수 기준 내림차순 정렬
# 정렬된 곡 중에서 앞에 2곡을 answer에 수록

def solution(genres, plays):
    answer = []
    
    # 각 장르에 따른 고유번호와 재생횟수 
    # 장르: {고유번호: 재생횟수}
    music_genres = dict()
    for i in range(len(genres)):
        if genres[i] in music_genres:
            music_genres[genres[i]][i] = plays[i]
        else:
            music_genres[genres[i]] = {i: plays[i]}

    # print(f"music_genres: {music_genres}")
    
    # 각 장르당 재생횟수
    # 장르: 재생횟수
    music_plays = dict()
    for i in range(len(genres)):
        if genres[i] in music_plays:
            music_plays[genres[i]] += plays[i]
        else:
            music_plays[genres[i]] = plays[i]
    
    # print(f"music_plays: {music_plays}")
    
    # 재생횟수에 따른 정렬
    music_play_count = list(music_plays.items())
    music_play_count.sort(key=lambda x: x[1], reverse=True)
    
    # print(f"music_play_count: {music_play_count}")
    
    # 정렬 기준 가장 많이 재생된 장르 순으로 반복
    for key, _ in music_play_count:
        # print(f"key: {key}")
        
        # 해당 장르에 속한 곡의 재생횟수 기준 내림차순으로 정렬
        music_num_dic = list(music_genres[key].items())
        music_num_dic.sort(key=lambda x: x[1], reverse=True)
        print(music_num_dic)
        
        # 장르 내에 속한 곡 중 가장 많이 재생된 2곡을 수록
        for num, _ in music_num_dic[:2]:
            answer.append(num)
            
            # print(f"answer: {answer}")
    
    return answer