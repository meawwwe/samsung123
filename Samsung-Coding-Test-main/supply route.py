T = int(input())
for test_case in range(1, T + 1):
    N = int(input())
    grid = []
    for _ in range(N):
        grid.append(list(map(int, input().split())))
    print(grid)