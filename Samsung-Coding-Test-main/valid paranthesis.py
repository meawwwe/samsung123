def isValid(s):
    stack = []
    for s in expr:
        if s == '{' or s == '[' or s == '(' or s == '<':
            stack.append(s)
        elif s == '}' and stack[-1] == '{':
            stack.pop()
        elif s == ']' and stack[-1] == '[':
            stack.pop()
        elif s == ')' and stack[-1] == '(':
            stack.pop()
        elif s == '>' and stack[-1] == '<':
            stack.pop()
        else:
            return False
    if stack:
        return False
    else:
        return True

for test_case in range(1, 2):
    L = int(input())
    expr = input()

    if isValid(expr) == True:
        print("#{} 1".format(test_case))
    else:
        print("#{} 0".format(test_case))
    #print(stack)
    #{[<(({[{(({[(({{{]{<[([[({[[[[<>]]]{}]{}})]]()<>{}{}<>()<>)()<>{}[]<>]>{}})<>()<><><>}{}}}())){}]}))}()<>()[]{}]})<><><><>)>[][][]]}<>[]{}
        
        
        

