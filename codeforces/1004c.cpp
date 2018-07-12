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
const int mx=1e5+100;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp=0;
	ll ans=0;
	cin>>n;

	vector<int> a, count(mx), first, last;

	f(i, n){
		cin>>tmp;
		a.pb(tmp);
		if(count[a[i]]==0){
			count[a[i]]+=1;
			first.pb(i);
		}
	}
	fill(count.begin(), count.end(), 0);
	frn(i, n-1, 0){
		if(count[a[i]]==0){
			tmp+=1;
			count[a[i]]+=1;
			last.pb(i);
		}
	}


	sort(first.begin(), first.end());
	sort(last.begin(), last.end());
	vector<int>::iterator it;
	f(i, first.size()){
		it=upper_bound(last.begin(), last.end(), first[i]);
		ans+=last.end()-it;
	}
	cout<<ans;
	return 0;
}