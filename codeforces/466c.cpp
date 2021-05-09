#include <vector>
#include <iostream>
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

    int n;
    cin>>n;
    vector<int> a(n), b(n+2, 0), c(n+1, 0);

    f(i, n) cin>>a[i];
    f(i, n){
        c[i+1] = c[i]+a[i];
        int ri = n-i-1;
        b[ri+1] = b[ri+2]+a[ri];
    }
    
    if (b[1]%3!=0){
        cout<<0<<endl;
        return 0;
    }
    int d = b[1]/3;
    
    // cout<<d<<endl;
    ll sum=0, j, last=0;

    f(i, n){
        if(i<2) continue;
        if(b[i+1]==d) last+=1;
    }

    // cout<<last<<endl;

    f(i, n){
        if(c[i+1]==d){ //if c_i == d and i>1, j>=i
            for(; j<i+1; j++)
                if (b[j+1]==d) last-=1;
            sum+=last;
            j=i+1;
        }
        // cout<<j<<" ";
        cout<<sum<<" ";
    }
    cout<<endl;
    cout<<sum<<endl;
    return 0;
}