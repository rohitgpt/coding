#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i,n) for(int (i)=0; (i)<(n); (i)++)
#define fi(i,a,b) for(int (i)=(a); (i)<(b); (i)++)

int main(){
	ll n, m, flag, cur=1;
	vector<ll> a, b, c;
	cin>>n>>m;
	a.resize(m);
	b.resize(m, 0);
	c.resize(n, 0);
	f(i, m) cin>>a[i];
	if(n<m) f(i, n-1) c[a[i]-1]+=1;
	vector<ll>::iterator p = min_element(c.begin(), c.end());
	fi(i, n-1, m){
		c[a[i]-1]+=1;
		if(*p>=cur){
			p = min_element(c.begin(), c.end());
			if(*p>=cur){
				cur++;
				b[i] = 1;
			}
		}
	}
	f(i,m) cout<<b[i];
	return 0;
}	