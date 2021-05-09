#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a)
#define debug  cout<<"hello"<<endl
#define N 1e6+7

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,m,l;
    cin>>n>>m>>l;
    vector<ll> h(n);
    f(i, n) cin>>h[i];

    int sum=0;
    int flag=0, a, b, q;
    f(i, n){
        if(h[i]>l && flag==0){
            sum+=1;
            flag=1;
        }
        if(h[i]<=l && flag==1){
            flag=0;
        }
    }

    f(i, m){
        cin>>q;
        if(q==1){
            cin>>a>>b;
            a-=1;
            // cout<<a<<" "<<b<<endl;
            if(h[a]>l) continue;
            h[a]+=b;
            if(h[a]<=l) continue;
            if(a==0){
                if(h[a+1]<=l || h.size()==1) sum+=1;
            }
            else if(a==n-1){
                if(h[a-1]<=l) sum+=1;
            }
            else{
                if(h[a-1]>l && h[a+1]>l) sum-=1;
                else if(h[a-1]<=l && h[a+1]<=l) sum+=1; 
            }
        }
        else
            cout<<sum<<endl;
    }

    return 0;
}