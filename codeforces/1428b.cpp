#include <vector>
#include <iostream>
#include <algorithm>
// #include <string>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a)
#define debug  cout<<"hello"<<endl
#define N 10^5+7

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t, n;
    char c;
    cin>>t;
    f(i, t){
        cin>>n;
        string s;
        cin>>s;
        int countd=0, counta=0, countb=0;
        int ans=0;
        f(j, s.length()){
            c = s[j];
            if (c=='-'){
                if (s[(j+1)%n]!='-') ans+=1;
                ans++;
            }
            else if (c=='<') counta++;
            else if (c=='>') countb++;
        }
        if ((counta==0)^(countb==0)) ans=n;
        cout<<ans<<endl;
    }
    return 0;
}