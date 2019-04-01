#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i,n) for(int (i)=0; (i)<(n); (i)++)

int main(){
	ll n, m, flag, cur=1;
	vector<ll> a, b, c;
	cin>>n>>m;
	a.resize(m);
	b.resize(m, 0);
	c.resize(n, 0);
	f(i, m) cin>>a[i];
	f(i, m){
		c[a[i]-1]+=1;
		if(i<cur*(n-1)) continue;
		vector<ll>::iterator p = min_element(c.begin(), c.end());
		if(*p>=cur){
			cur++;
			b[i] = 1;
		}
	}
	f(i,m) cout<<b[i];
	return 0;
}	