
def time(s):
    x = int(s[0:2])*100+int(s[3:5])
    if x>=1200:
        if(s[6:8]=='PM'):
            return x;
        else:
            return x-1200;
    if(s[6:8]=='PM'):
        return (1200+x)
    return x

def main():
    t = int(input())
    while t>0:
        ans = '';
        s = input()
        tm = time(s); 
        # print(tm);
        n = int(input())
        while n>0:
            n-=1;
            s = input()
            l = s[0:8]
            r = s[9:]
            lt = time(l);
            rt = time(r);
            # print(lt, rt);
            if(tm>=lt and tm<=rt):
                ans+='1'
            else:
                ans+='0'
        print(ans)
        t-=1;

main()