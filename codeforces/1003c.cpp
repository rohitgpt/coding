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

	int n, k, tmp, tmpk=k;
	ld maxt=0;
	vector<int> a;
	cin>>n>>k;
	f(i, n){
		cin>>tmp;
		a.pb(tmp);
	}
	frp(i, 0, n-k+1){
		tmp=0;
		frp(j, i, n){
			tmp+=a[j];
			if(j-i+1>=k){
				tmpk = j-i+1;
				if((double)tmp/tmpk>maxt) maxt=(double)tmp/tmpk;
			}
		}
	}
	cout.precision(17);
	cout<<maxt<<endl;
	return 0;
}