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


	int n, flag;
	vector<int> A;
	cin>>n;

	f(i, n) A.pb(0);
	int	l = (int)sqrt(n);
	for(int i=0, o=n; i<=n; i+=l)
		for(int j=min(i+l-1, n-1); j>=i; A[j--]=o--);

	f(i,n) cout<<A[i]<<" ";

	return 0;
}