#include <iostream>
#include <bits/stdc++.h>
#include <vector>

typedef long long ll;
typedef long double ld;

#define fr(n) for(long long int (i)=0; (i)<(n); (i)++)
#define frp(a, b) for(int (i)=a; (i)<(b); (i)++)
#define frn(a, b) for(int (i)=a; (i)>(b); (i)--)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

using namespace std;
ll n, H;

int main(){
	cin>>n>>H;
	ll a=sqrt(n)-1, b=2*sqrt(n)+1, s;
	while(b-a>1){
		s = (a+b)/2;
		ll h = min(s,H);
		if((s*s - h*(h-1)/2) > n) b=s;
		else a=s;
	}
	ll h = min(H,a);
	ll diff = n - a*a + h*(h-1)/2;
	if(diff%a) cout<<2*a-h+diff/a+1<<endl;
	else cout<<2*a-h+diff/a<<endl;
	return 0;
}