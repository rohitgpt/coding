
t = int(input());
while (t>0):
    t-=1;
    a = [set() for i in range(26)]
    n = int(input())
    s = input();
    l = s.split(' ');
    # print(l);
    for i in l:
        a[ord(i[0])-ord('a')].add(i[1:]);
    ans=0;
    for i in range(len(a)-1):
        # print(a[i]);
        if len(a[i])==0: 
            continue;
        for j in range(i+1, len(a)):
            if len(a[j])==0:
                continue;
            tmp = a[i].intersection(a[j])
            # print(i, j, tmp);
            ans += 2*(len(a[i])-len(tmp))*(len(a[j])-len(tmp))
    # print(ans);
    print(ans);
