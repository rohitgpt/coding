#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <chrono>
#include <string>
#include <algorithm>

using namespace std;
// using namespace std::chrono;

// typedef std::chrono::high_resolution_clock::time_point timen;
typedef long long ll;
typedef long double ld;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()
#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(ll (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(ll (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

const int mod=1e9+7;
const ll mx=1e14;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll a, b, n, m, ans=4*mx, min_a=mx, min_b=mx, c=0,min_c, max_c;
	cin>>a>>b;
	n=a+b;
	m=sqrt(n);
	vector<ll> da,db,dc;
	frp(i, 1, (ll)sqrt(a)+1)	if(a%i==0) da.pb(i);
	frp(i, 1, (ll)sqrt(b)+1)	if(b%i==0) db.pb(i);
	frp(i, 1, m+1) if(n%i==0) dc.pb(i);

	f(i, dc.size()){
		ll max_j=-1;
		f(j, da.size())
			if(da[j]>dc[i]){
				max_j=j;
				break;
			}
		if(max_j==-1) max_j=da.size();
		if(n/dc[i]>=a/da[max_j-1] && ans>2*(dc[i]+n/dc[i])) ans=2*(dc[i]+n/dc[i]);
	}
	f(i, dc.size()){
		ll max_j=-1;
		f(j, db.size()){
			if(db[j]>dc[i]){
				max_j=j;
				break;
			}
		}
		if(max_j==-1) max_j=db.size();
		if(n/dc[i]>=b/db[max_j-1] && ans>2*(dc[i]+n/dc[i])) ans=2*(dc[i]+n/dc[i]);
	}
	cout<<ans<<endl;
	return 0;
}
