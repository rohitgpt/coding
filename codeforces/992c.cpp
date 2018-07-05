#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <chrono>
// #include <string>
#include <algorithm>
#include <cmath>
using namespace std;
// using namespace std::chrono;

// typedef std::chrono::high_resolution_clock::time_point timen;
typedef long long ll;
typedef long double ld;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()
#define f(i, n) for(int (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(int (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(int (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

const int mod=1e9+7;
const int mx=2e5+1000;

int fp(int a, int b){
	if(b==0) return 1;
	int t = fp(a, b/2);
	if(b==2) return (t*t)%mod;
	else return ((t*t)%mod*a)%mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll x, k, ans;
	cin>>x>>k;

	ans=x;

	if(x==0){
		cout<<0<<endl;
	}
	else if(k==0) cout<<(2*x)%mod<<endl;
	else{
		int a = (2*x-1)%mod;
		cout<<(2*a*fp(2, k-1)+1)<<endl;
	}
	return 0;
}