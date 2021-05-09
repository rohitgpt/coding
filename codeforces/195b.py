def func(i):
    return abs((m+1)/2-i)

a = input()
[n, m] = a.split(' ')
[n, m] = [int(n), int(m)];
a = [i for i in range(1, m+1)]
a.sort(key=func)
i = 0;
while(i<n):
    print(a[i%m])
    i+=1;
# print(a)
