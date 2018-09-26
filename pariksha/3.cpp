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
const ll mx=7e3;
#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(ll (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(ll (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll tmp=0, cnt=0;
	double o=24;
	vector<ll> a;
	f(i, o){
		f(j, (o-i)*(log(5)/log(3))){
			f(k, ((o-i)*(log(5)/log(3))-j)*(log(3)/log(2))){
				tmp = (ll)pow(2,k);
				tmp*=(ll)pow(3,j);
				tmp*=(ll)pow(5,i);
				// cout<<tmp<<" ";
				// cout<<i<<j<<k<<" "<<tmp<<endl;
				a.pb(tmp);
				cnt+=1;
				if(cnt>mx) break;
			}
			if(cnt>mx) break;
		}
		if(cnt>mx) break;
	}
	// cout<<o+1<<" "<<pow(5,o)<<endl;
	// cout<<(ll)(o*log(5)/log(3)+1)<<" "<<pow(3,(ll)(o*log(5)/log(3)+1))<<endl;
	// cout<<(ll)(o*log(5)/log(2)+1)<<" "<<pow(2,(ll)(o*log(5)/log(2)+1))<<endl;
	// cout<<a.size()<<endl;
	sort(a.begin(), a.end());
	// f(i, a.size()) cout<<a[i]<<" ";
	int t, n;
	cin>>t;
	f(i, t){
		cin>>n;
		cout<<a[n-1]<<endl;
	}
	return 0;
}