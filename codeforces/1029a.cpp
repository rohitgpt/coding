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

	string t, s;
	int n, k, t1=0;

	cin>>n>>k;
	cin>>t;

	f(i, t.size()-1)
		if(t.compare(0, i+1, t, t.size()-1-i, i+1)==0) t1=i+1;
	
	if (t1==t.size()) t1-=1;
	s = t;
	f(i, k-1)
		s.insert(s.size(), t, t1, t.size()-t1);
	
	cout<<s;
	return 0;
}