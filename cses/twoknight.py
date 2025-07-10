def solve(n):
    total=int(((n*n)*(n*n -1))/2)
    attack=int((4*(n-1)*(n-2)))
    print(total-attack)

a=int(input())
for i in range(1,a+1):
    solve(i)
