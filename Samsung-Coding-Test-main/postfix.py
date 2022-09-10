def to_postfix(tokens):   
    lst = []
    stack = []     
    prior = {'*':3,'/':3,'+':2,'-':2,'(':1}   
    for n in range(len(tokens)):   
        if tokens[n].isdigit(): 
            lst.append(tokens[n])
        elif tokens[n] == '(':  
                stack.append(tokens[n])
        elif tokens[n] == ')':  
            while stack[-1] != '(':
                lst.append(stack.pop())
            stack.pop() 
        else:  
            while stack and prior[tokens[n]] <= prior[stack[-1]]:
                lst.append(stack.pop())  
            stack.append(tokens[n]) 

    while len(stack) != 0:
        lst.append(stack.pop())

    ans = ''.join(lst)
    return ans

for test_case in range(1,11):
    l = int(input())
    expression = input()  
    stack = []
 
    post_ex = to_postfix(expression)
 
    for s in post_ex:
      if s.isnumeric():
            stack.append(s)
      if s == '+':
            a = stack.pop()
            b = stack.pop()
            stack.append(int(a)+int(b))
      elif s == '*':
            a = stack.pop()
            b = stack.pop()
            stack.append(int(a)*int(b))
       
    ans = stack[0]
    print(f"#{test_case} " + str(ans))

      
