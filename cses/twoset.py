
def solve(n):
    total=int((n*(n+1))/2)
    if total%2!=0:
        print("NO")
        return
    print("YES")
    sum=0
    target=total/2
    d={}
    for k in range(1,n+1):
        sum+=k
        if d.get(sum-target):
            start=d[sum-target]+1
            end=k
            print(end-start+1)
            for i in range(start,end+1):
                print(i,end=" ")
            print()
            print(n-(end-start+1))
            for i in range(1,start):
                print(i,end=" ")
            for i in range(end+1,n+1):
                print(i,end=" ")
            print()
            return
        d[sum]=k

n=int(input())
solve(n)
