#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a)
#define debug  cout<<"hello"<<endl

ll total(ll** dp, int l, int r){
    if (dp[l][r]!=0) return dp[l][r];
    else{
        dp[l][r] = total(dp, l, (l+r)/2) + total(dp, (l+r)/2, r);
        return dp[l][r];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, m, s, l, r, p, q;
    cin>>n;
    ll **dp, **sdp;
    if(n>20){
        dp = (ll**)calloc(n/10+1, sizeof(ll*));
        f(i, n/10) dp[i] = (ll*)calloc(n/10+1, sizeof(ll));
        sdp = (ll**)calloc(n/10+1, sizeof(ll*));
        f(i, n/10) sdp[i] = (ll*)calloc(n/10+1, sizeof(ll));
    }
    vector<int> a(n);
    ll sum = 0;
    f(i, n){
        cin>>a[i];
        if (i%10==0 && i>0){
            dp[i/10-1][i/10] = sum;
            sum=0;
        }
        sum+=a[i];
    }
    f(i, n/10){
        cout<<dp[i][i+1]<<" ";
    }
    vector<int> b(a);
    sort(b.begin(), b.end());
    sum = 0;
    f(i, n){
        sum+=b[i];
        if (i%10==0 && i>0){
            sdp[i/10-1][i/10] = sum;
            sum=0;
        }
    }
    ll ans = 0;
    cin>>m;
    f(t, m){
        cin>>s>>l>>r;
        l=l-1;
        r=r-1;
        if (r-l>20){
            p = (l+10)/10;
            q = r/10;
        }
        if (s ==1){
            ans = 0;
            if (r-l>20){
                for(int i=l; i<p*10; i++) ans+=a[i];
                ans+=total(dp, p, q);
                for(int i=q*10; i<=r; i++) ans+=a[i];
                cout<<ans<<endl;
            }
            else{
                for(int i=l; i<=r; i++) ans+=a[i];
                cout<<ans<<endl;
            }
        }
        else{
            ans = 0;
            if (r-l>20){
                for(int i=l; i<p*10; i++) ans+=b[i];
                ans+=total(sdp, p, q);
                for(int i=q*10; i<=r; i++) ans+=b[i];
                cout<<ans<<endl;
            }
            else{
                for(int i=l; i<=r; i++) ans+=b[i];
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}