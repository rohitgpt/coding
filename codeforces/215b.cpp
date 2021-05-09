#include <vector>
#include <iostream>
#include <iomanip>      // std::setprecision
#include <cmath>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a)
#define debug  cout<<"hello"<<endl
#define N 1e5+777

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, m, k; 
    float x=0,y=0,z=6000, t;
    
    cin>>n;
    f(i, n){
        cin>>t;
        if(t>x) x=t;
    }
    cin>>m;
    f(i, m){
        cin>>t;
        if(t>y) y=t;
    }
    cin>>k;
    f(i, k){
        cin>>t;
        if(t<z) z=t;
    }
    float A, B;
    cin>>A>>B;
    // cout<<A<<" "<<B<<endl;
    float r,p,c, ans=0;
    r = x;
    p = y/z;
    c = B/A;
    // c = (float) B/(float)A;
    // cout<<r<<" "<<p<<" "<<c<<endl;
    ans = r*sqrt(p*c/(1+p*c));
    cout<<fixed;
    cout<<setprecision(6)<<ans<<endl;
    return 0;
}