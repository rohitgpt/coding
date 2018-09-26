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

const int mod=1e9+7;
const ll mx=1e14;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, tmp, tmp1, longest=0, curlen=0;
	vector<int> a;

	cin>>t;
	f(i, t){
		longest=0;
		curlen=0;
		cin>>n;
		cin>>tmp;
		f(j, n-1){
			cout<<tmp<<" ";
			cin>>tmp1;
			if(abs(tmp1-tmp)==1) curlen+=1;
			else curlen=1;
			tmp=tmp1;
			if(curlen>longest) longest=curlen;
		}
		cout<<longest<<endl;
	}
	return 0;
}