#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(ll (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(ll (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)
#define all(c) (c).begin(), (c).end()
#define tr(c, it) for(__typeof__((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define present(c, x) ((c).find(x)!=(c).end())
#define cpresent(c, x) (find(all(c), x)!=(c).end())

const int mod=1e9+7;
const ll mx=1e14;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin>>n>>k;
	ll carryover=0, ans=0, a, count=0;
	f(i,n){
		cin>>a;
		if(count==1){
			if((a+carryover)/k==0){
				ans+=1;
				carryover=0;
				count=0;
				continue;
			}
			else{
				count=0;
			}
		}
		if((a+carryover)/k==0 && a>0) count=1;
		ans+=(a+carryover)/k;
		carryover=(a+carryover)%k;
		// cout<<count<<endl;
			// cout<<i<<" "<<ans<<carryover<<endl;
	}
	if(carryover>0) ans+=1;
	cout<<ans<<endl;
}