#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <chrono>
// #include <string>
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
const int mx=2e5+1000;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, d, k;
	cin>>n>>d>>k;

	if(d>=n || (k==1 && n>2)){
		cout<<"NO"<<endl;
		return 0;
	}

	vector<int> deg(n);
	vector<pair<int, int> > ans;
	set<pair<int, int> > q;

	f(i, d){
		deg[i]++;
		deg[i+1]++;
		ans.pb(make_pair(i, i+1));
	}

	frp(i, 1, d)	q.insert(make_pair(max(i, d-i), i));
	
	frp(i, d+1, n){
		while(!q.empty() && deg[q.begin()->second]==k) q.erase(q.begin());
		if(q.empty() || q.begin()->first == d){
			cout<<"NO"<<endl;
			return 0;
		}
		deg[i]++;
		deg[q.begin()->second]++;
		ans.pb(make_pair(q.begin()->second, i));
		q.insert(make_pair(q.begin()->first+1, i));
	}

	cout<<"YES"<<endl;
	f(i, n-1)		cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
	
	return 0;
}