def editor(s,orders):
    """
    L: move position -1 (if pos is far left, don't move)
    D: move position +1 (if pos is far right, dont' move)
    B: delete element left position
    P $: input right position new word $
    
    """
    left = list(s)
    right = []
    for order in orders:
        if order[0]=='L':
            if left:
                right.append(left.pop())
        elif order[0]=='D':
            if right:
                left.append(right.pop())
        elif order[0]=='P':
            o = order.split(' ')
            new = o[1]
            left.append(new)
        elif order[0]=='B':
            if left:
                left.pop()
    while left:
        right.append(left.pop())
    return ''.join(right[::-1])

if __name__=="__main__":
    s = input()
    N = int(input())
    orders = []
    for _ in range(N):
        orders.append(input())
    print(editor(s,orders))
