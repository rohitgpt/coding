#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld; 
#define all(c) (c).begin(), (c).end();
#define tr(c, it) for(__typeof__((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define f(i, a) for(ll (i)=0; (i)<(a); (i)++)
#define pb push_back

const ll mx=1e9;
const ll mod=1e9+7;

int main(){
	int t, n, k, tmp, cnt;
	cin>>t;
	f(i, t){
		cin>>n>>k;
		cnt=0;
		f(j,n){
			cin>>tmp;
			if(tmp>1) cnt+=1;
		}
		if(cnt<=k) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}