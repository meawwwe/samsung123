
T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):

    k = int(input())
    scores = list(map(int, input().split()))

    possible_score = [0]

    for score in scores:
        for i in range(len(possible_score)):
            if possible_score[i]+score not in possible_score:
                possible_score.append(possible_score[i]+score)
    ans = len(possible_score)
    print(f"#{test_case} " + str(ans))


    

