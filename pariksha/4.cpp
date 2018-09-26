#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// using namespace std::chrono;
// typedef std::chrono::high_resolution_clock::time_point timen;
// #define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
// #define timeNow() std::chrono::high_resolution_clock::now()

typedef long long ll;
typedef long double ld;
const ll mx=1e3+10;
#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(ll (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(ll (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

bool valid(int a){
	int isvalid=1, cur;
	cur = a%10;
	if(cur==0) isvalid=0;
	while(a){
		cur = a%10;
		if(cur==0) isvalid=0;
		if(cur>5) isvalid=0;
		a = (a-cur)/10;
	}
	return isvalid==1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, ans=0;
	vector<int> cnt;


	f(i, mx){
		if(valid(i)) ans+=1;
		cnt.pb(ans);
	}
	// frp(i, 100, 120){
	// 	cout<<cnt[i]<<endl;
	// }
	// cout<<cnt[1000]<<endl;
	cin>>t;
	f(i, t){
		cin>>n;
		cout<<cnt[n]<<endl;
	}
	return 0;
}