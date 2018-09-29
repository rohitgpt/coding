#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(ll (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(ll (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

const ll mx=2e5+10;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, t, a_sum=0, b_sum=0;
	vector<ll> a, b;
	cin>>n;
	f(i, n){
		cin>>t;
		a.pb(t);
	}
	f(i, n){
		cin>>t;
		b.pb(t);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for(ll i=n-1, j=n-1; i>=0 || j>=0;){
		if(i<0){
			j--;
		}
		else if(a[i]>b[j] || j<0){
			// cout<<a[i]<<endl;
			a_sum+=a[i];
			i--;
		}
		else{
			j--;
		}
		if(j<0){
			i--;
		}
		else if(b[j]>a[i] || i<0){
			b_sum+=b[j];
			j--;
		}
		else{
			i--;
		}
	}
	cout<<a_sum-b_sum<<endl;
	return 0;
}