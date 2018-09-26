#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll mx=1e3+10;
#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(ll (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(ll (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, ans=0, tmp,s,i, mid;
	vector<ll>a;
	cin>>n>>s;
	f(i, n){
		cin>>tmp;
		a.pb(tmp);
	}
	sort(a.begin(), a.end());
	mid = (n-1)/2;
	i=mid;
	if(s>a[mid]){
		while(a[i]<s && i<n){
			ans+=(s-a[i]);
			i++;
		}
	}
	else if(s<a[mid]){
		while(a[i]>s && i>=0){
			ans+=(a[i]-s);
			i--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
