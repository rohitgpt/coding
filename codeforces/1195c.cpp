#include <vector>
#include <iostream>
// #include <cmath>
using namespace std;

typedef int ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define debug  cout<<"hello"<<endl
#define N 1e5+7

int n;
vector<ll> a(N,0), b(N,0), dp(5*N,0);

// ll cdp(vector<vector<ll> > dp,  int i, int j){
ll cdp(int i, int j){
    if(i>=n || j>=n) return 0;
    if(abs(i-j)<=2){
        if(i-j==1 && dp[5*j+1]!=0) return dp[5*j+1];
        else if(j-i==1 && dp[5*i+2]!=0) return dp[5*i+2];
        else if(i-j==2 && dp[5*i+3]!=0) return dp[5*i+2];
        else if(j-i==2 && dp[5*i+4]!=0) return dp[5*i+2];
        else if(dp[5*i]!=0) return dp[5*i];
    // if(dp[i][j]!=0) return dp[i][j];
    }

    ll p, q, r, t;
    if(i==n-1 && j==n-1){
        // dp[i][j] = max(a[i], b[j]);
        dp[i] = max(a[i], b[j]);
        return dp[i];
    }
    else if(i==j){
        p = max(a[i]+cdp(i+2, j+1), b[j]+cdp(i+1, j+2));    //use one
        q = max(cdp(i, j+1), cdp(i+1, j));                  //use neither
        // dp[i][j] = max(p, q);
        dp[3*i] = max(p, q);
        return dp[5*i];
    }
    else{
        p = max(a[i]+cdp(i+2, j), b[j]+cdp(i, j+2));    //use one
        q = max(cdp(i, j+1), cdp(i+1, j));              //use neither
        r = a[i]+b[j]+cdp(i+2, j+2);                        //use both
        // dp[i][j] = max(p, max(q, r));
        t = max(p, max(q, r));
        if(i-j==1) dp[5*j+1]=t;
        else if(j-i==1) dp[5*i+2]=t;
        else if(i-j==2) dp[5*i+3]=t;
        else if(j-i==2) dp[5*i+4]=t;
        return t;
    }
    // cout<<5<<" "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    // return dp[i][j];
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