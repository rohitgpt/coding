
N = 10**6+7
p = [1 for i in range(N)]
p[0]=0
p[1]=0
cnt = [0 for i in range(N)]
for i in range(N):
    if(p[i]==1):
        for j in range(2*i, N, i):
            p[j]=0;
    cnt[i]=cnt[i-1]+p[i]

t = int(input())
while(t):
    s = input()
    [x, y] = s.split(' ')
    x = int(x)
    y = int(y)
    if(cnt[x]>y): 
        print('Divyam')
    else:
        print('Chef')
    t-=1