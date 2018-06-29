#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

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

vector<ll> log_coord;
inline int binary_search(int begin, int end, ll a){
	int mid = (begin+end)/2;
	if(a==log_coord[mid]) return mid;
	else if(a>log_coord[mid]) return binary_search(mid, end, a);
	else return binary_search(begin, mid, a);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, log_cnt[2*mx], cnt[2*mx];
	ll l[mx], r[mx], ans_cnt[mx];

	cin>>n;
	f(i, n){ 
		cin>>l[i]>>r[i];
		r[i]+=1;
		log_coord.pb(l[i]);
		log_coord.pb(r[i]);
	}
	
	vector<ll>::iterator it;
	sort(log_coord.begin(), log_coord.end());
	it = unique(log_coord.begin(), log_coord.end());
	log_coord.resize(distance(log_coord.begin(), it));

	int logl, logr;
	f(i, n){
		
		logl = binary_search(0, log_coord.size(), l[i]);
		logr = binary_search(0, log_coord.size(), r[i]);
		cnt[logl]+=1;
		cnt[logr]-=1;
	}

	f(i, log_coord.size()){
		if(i>0)	log_cnt[i]+=log_cnt[i-1]+cnt[i];
		else log_cnt[i]+=cnt[i];
		ans_cnt[log_cnt[i]]+=log_coord[i+1]-log_coord[i];
	}

	frp(i,1,n+1) cout<<ans_cnt[i]<<" ";
	return 0;
}
