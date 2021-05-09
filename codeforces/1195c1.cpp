//solution is correct but exceeding memory limit
//need to find a better algo
#include <vector>
#include <iostream>
// #include <cmath>
using namespace std;

typedef int ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define debug  cout<<"hello"<<endl
#define N 1e5+7

int n;
vector<ll> a(N,0), b(N,0), dp(N*N);

// ll cdp(vector<vector<ll> > dp,  int i, int j){
ll cdp(int i, int j){
    if(i>=n || j>=n) return 0;
    if(dp[n*i+j]!=0){
        return dp[n*i+j];
    // if(dp[i][j]!=0) return dp[i][j];
    }

    ll p, q, r, t;
    if(i==n-1 && j==n-1){
        // dp[i][j] = max(a[i], b[j]);
        dp[n*i+j] = max(a[i], b[j]);
        // return dp[i*i];
    }
    else if(i==j){
        p = max(a[i]+cdp(i+2, j+1), b[j]+cdp(i+1, j+2));    //use one
        q = max(cdp(i, j+1), cdp(i+1, j));                  //use neither
        // dp[i][j] = max(p, q);
        dp[n*i+j] = max(p, q);
        // return dp[i*j];
    }
    else{
        p = max(a[i]+cdp(i+2, j), b[j]+cdp(i, j+2));    //use one
        q = max(cdp(i, j+1), cdp(i+1, j));              //use neither
        r = a[i]+b[j]+cdp(i+2, j+2);                        //use both
        // dp[i][j] = max(p, max(q, r));
        dp[n*i+j] = max(p, max(q, r));
        // return dp[i*j];
    }
    // cout<<5<<" "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    return dp[n*i+j];
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>n;
    f(i, n) cin>>a[i];
    f(i, n) cin>>b[i];

    // vector<ll> dp(n);
    cout<<cdp(0,0)<<endl;
    return 0;
}