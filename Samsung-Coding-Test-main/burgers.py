from itertools import combinations
T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N,M = map(int,input().split())
    stack = []
    possible_burgers = []
    ans = 1
    ingredients = []
    for ingredient in range(1,N+1):
        ingredients.append(ingredient)

    for i in range(M):
        stack.append(tuple((map(int,input().split()))))
    stack = list(set(stack))
    
    for j in range(1,N+1):
        for k in list(combinations(ingredients,j)):
            possible_burgers.append(k)

    possible_burgers2 = possible_burgers.copy()
    
    for i in range(len(possible_burgers)):
        for j in range(len(stack)):
            if stack[j][0] in possible_burgers[i] and stack[j][1] in possible_burgers[i]:
                if possible_burgers[i] in possible_burgers2:
                    possible_burgers2.remove(possible_burgers[i])
    print(stack)
    print(possible_burgers)
    print(possible_burgers2)
    print(f"#{test_case} " + str(len(possible_burgers2)+1))
                



    

