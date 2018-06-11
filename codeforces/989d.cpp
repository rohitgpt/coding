#include <iostream>
#include <bits/stdc++.h>
// #include <vector>
#include <string>
// #include <algorithm>

typedef long long ll;
typedef long double ld;

#define f(i, n) for(int (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(int (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(int (i)=a; (i)>(b); (i)--)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

using namespace std;

const int mod = 1e9+7;
const int mx = 1e5+100;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,l,w_max;
	double x[mx], v[mx];
	int ans=0;
	cin>>n>>l>>w_max;
	f(i,n){
		cin>>x[i]>>v[i];
		x[i]+=(double)l/2;
	}
	double den, frac;
	f(i,n){
		frp(j,i,n){
			den = 1/x[i]-1/x[j];
			if(!den) continue;
			frac = (v[j]/x[j]-v[i]/x[i])/den;
			if(frac+v[i]==0 || frac+v[j]==0 || -x[i]/(frac+v[i])<0) continue;
			// cout<<i+1<<j+1<<frac<<endl;
			if(abs(frac)<=w_max) ans+=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}