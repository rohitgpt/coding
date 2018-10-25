#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(ll (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(ll (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

const ll mx=1e9+10;

int main(){
	IOS;
	int n;
	cin>>n;
	vector<int> p[n];
	frp(i, 1,n+1){
		frp(j,1, n+1){
			if((i&j)==i && i<j){
				cout<<i<<" "<<j<<endl;
				p[i].pb(j);
			}
		}
	}

	return 0;
}