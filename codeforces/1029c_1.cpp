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
#define f(i, n) for(int (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(int (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(int (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

const int mod=1e9+7;
const int mx=1e3;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t1, t2, ans=0;
	vector<int> l, r, pl, pr, sl, sr;
	cin>>n;
	f(i, n){
		cin>>t1>>t2;
		l.pb(t1); r.pb(t2);
	}
	pl.pb(l[0]); pr.pb(r[0]);
	sl.pb(l[n-1]); sr.pb(r[n-1]);
	frp(i, 1, n){
		pl.pb(max(pl[i-1], l[i]));
		pr.pb(min(pr[i-1], r[i]));
		sl.insert(sl.begin(), max(sl[0], l[n-i]));
		sr.insert(sr.begin(), min(sr[0], r[n-i]));
	}

	// frn(i, n-2, -1){
	// }
	// frn(i, n-1, 1)
	// 	pl.pb(*max_element(l.begin(), l.begin()+i));
	// 	pr.pb(*min_element(r.begin(), r.begin()+i));
	// 	sl.pb(*max_element(l.begin()+i, l.end()));
	// 	sr.pb(*min_element(r.begin()+i, r.end()));

	if(sl[0]<sr[0]) ans=sr[0]-sl[0];
	f(i, n-2)
		if(min(pr[i], sr[i+1])-max(pl[i], sl[i+1])>ans) 
			ans = min(pr[i], sr[i+1])-max(pl[i], sl[i+1]);
	
	if(pr[n-2]-pl[n-2]>ans) 
		ans = pr[n-2]-pl[n-2];
	cout<<ans;
	return 0;
}
