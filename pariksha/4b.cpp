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

vector<int> sqr;
int min_sq(int a){
	if(a<3) return a;

	int r = n;
	f(i, n){
		int tmp=i*i;
		if(tmp>n) break;
		else
			r = min(n, 1+min_sq(n-temp));
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, ans=0;

	// f(i, sqrt(mx)+1){
	// 	sqr.pb(i*i);
	// }

	cin>>t;
	f(i, t){
		cin>>n;
		cout<<min_sq(n);
	}
	return 0;
}