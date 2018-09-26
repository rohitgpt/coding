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

	int n, tmp, ans=0;
	string a, b;
	cin>>n;
	cin>>a>>b;
	f(i, n){
		if(a[i]!=b[i]){
			ans+=1;
			if(i+1<n && a[i+1]!=b[i+1] && b[i]!=b[i+1]){
				i+=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}