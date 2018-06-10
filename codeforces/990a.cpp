#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>

typedef long long ll;
typedef long double ld;

#define fr(n) for(int (i)=0; (i)<(n); (i)++)
#define Fr(i, n) for(int i=0; i<n; i++)
#define frp(a, b) for(int (i)=a; (i)<(b); (i)++)
#define frn(a, b) for(int (i)=a; (i)>(b); (i)--)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

using namespace std;

int main(){
	ll n, m; 
	ll a, b;
	ll ans;
	cin>>n>>m>>a>>b;
	if(n%m==0 || n*m==0){
		ans=0; 
		cout<<ans<<endl;
		return 0;
	}
	if(b*(n%m)>a*(m*(n/m+1)-n)){
		ans = a*(m*(n/m+1)-n);
	}
	else ans = b*(n%m);

	cout<<ans<<endl;
	return 0;
} 