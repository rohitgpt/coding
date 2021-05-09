#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

#define f(i, n) for(int (i)=0; (i)<(n); (i)++)

int main(){
    int n, t;
    cin>>t;
    f(i, t){
        cin>>n;
        ll ans=0;
        int tmp;
        // vector<ll> x(n, 0);
        ll smin=1e10, smax=-1e10;
        f(j, n){
            cin>>tmp;
            if(tmp<smin) smin=tmp;
            if(tmp>smax)    smax=tmp;
        }
        // sort(x.begin(), x.end());
        // f(j, n) cout<<x[j]<<" ";

        // for(j=1;j<n-1;j++){
        //     if (ans<(a[n-1]))
        // }
        // ans = max(abs(x[n-1]-x[0])+abs(x[0]-x[n/2])+abs(x[n-1]-x[(n)/2]),
        //           abs(x[0]-x[n-1])+abs(x[0]-x[(n-1)/2])+abs(x[n-1]-x[(n-1)/2]));
        cout<<2*(smax-smin)<<endl;
    }
    return 0;
}