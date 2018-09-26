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

	ll q, n, m, k;

	cin>>q;
	f(i, q){
		cin>>n>>m>>k;
		n=abs(n); m=abs(m);
		if(max(n, m)>k) cout<<-1<<endl;
		else if((n+m)%2==0 && (k-max(n,m))%2==1) cout<<k - 2<<endl;
		else if((n+m)%2==0) cout<<k<<endl;
		else if((n+m)%2==1) cout<<k-1<<endl;
	}
	return 0;
}