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

	string a, b, e;
	string c, d;
	int len, flag, m, s;
	cin>>a;
	cin>>b;

	if(b.size()<a.size()) {
		e=a;
		a=b;
		b=e;
	}
	m=(a.size()+1)/2;
	s=m;
	int p=0;
	flag=1;
	while(flag){
		c=a.substr(a.size()-m, m);
		d=b.substr(b.size()-m, m);
		// cout<<c<<" "<<d<<endl;
		if(c.compare(d)==0) m+=(s+1)/2;
		else m-=(s+1)/2;
		if(p==m){
			// cout<<m<<endl;
			cout<<(a.size()+b.size()-2*m)<<endl;
			// if()
			return 0;
		}
		p=m;
		s=(s-1)/2;
	}
	return 0;
}