#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define debug  cout<<"hello"<<endl
#define N 1e5+7
#define aj (j+1)%2
int n;
vector<ll> a(2*N,0), dp(2*N, 0);

ll cdp(int i, int j){

    if(dp[2*i+j]!=0) return dp[2*i+j];
    if(i>=n) return 0;

    ll p,q,r;
    p = a[2*i+j]+cdp(i+2, j);   //current one
    q = a[2*i+j]+cdp(i+1, aj);   //using the other layer
    r = max(cdp(i+1, j), cdp(i+1, aj));        //not using anyone
    dp[2*i+j] = max(r, max(p,q));
    return dp[2*i+j];
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>n;
    f(i, n) cin>>a[2*i];
    f(i, n) cin>>a[2*i+1];

    cout<<max(cdp(0,0), cdp(0,1))<<endl;
    return 0;
}