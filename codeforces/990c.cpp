#include <iostream>
// #include <chrono>
#include <bits/stdc++.h>
#include <vector>
#include <string>
// #include <algorithm>
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

#define p(aaa) cout<<"debug "<<aaa<<" ";
#define PI 3.14159265358979323846


const int mod = 1e9+7;
const int mx = 3e5+100;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll  n,ans=0;
	vector<string> tmp;
	string t;
	int value[mx];
	int minv[mx];
	int cnt[mx], temp;
	memset(minv, mod, sizeof(minv));
	memset(value, 0, sizeof(value));
	memset(cnt, 0, sizeof(cnt));
	cin>>n;

	// timen start = timeNow();

	f(i, n){
		cin>>t;
		tmp.push_back(t);
	}
	f(i, n){
		f(j, tmp[i].size()){
			if(tmp[i][j]=='(') value[i]+=1;
			else value[i]-=1;
			if(value[i]<minv[i]) minv[i]=value[i];
		}
		if(value[i]<=0 && value[i]==minv[i])	cnt[-value[i]] += 1;
	}
	f(i, n){
		if(minv[i]>=0){
			ans+=cnt[value[i]];
		}
	}

	// stop = timeNow();
	// cout <<"process time: "<<duration(stop-start)/1000 << endl;
	cout<<ans<<endl;
	return 0;
}
