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

const int mod=1e6;
const ll mx=1e10;

vector<int> c;


int numbers(ll a){
	int count=0;
	while(a){
		count+=c[a%mod];
		a-=a%mod;
		a/=mod;
	}
	return count;
}
int init(ll a){
	int count=0;
	while(a){
		if(a%10!=0)count+=1;
		a-=a%10;
		a/=10;
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t, l, r, ans;
	cin>>t;
	f(i, mod) c.pb(init(i));
	f(i, 1000002) if(numbers(i)<=3) ans+=1;
	cout<<ans<<endl;
	// f(j, t){
	// 	ans=0;
	// 	cin>>l>>r;
	// 	frp(i, l, r+1){
	// 		// if(i/(int)pow(10,log(sqrt(mod))/log(10))>1000)		cout<<i/(int)pow(10,log(sqrt(mod))/log(10))<<endl;
	// 		if(numbers(i)<=3) ans+=1;
	// 		if(numbers(i/(int)pow(10,3*log(mod)/log(10)))>3){		i+=pow(10,3*(int)log(mod)/log(10)); continue;}
	// 		if(numbers(i/(int)pow(10,2*log(mod)/log(10)))>3){		i+=pow(10,2*(int)log(mod)/log(10)); continue;}
	// 		if(numbers(i/(int)pow(10,log(mod)/log(10)))>3){			i+=pow(10,(int)log(mod)/log(10)); continue;}
	// 	} 
	// 	cout<<ans<<endl;
	// }
	return 0;
}