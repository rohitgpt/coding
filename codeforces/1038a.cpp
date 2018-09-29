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

	int n, k, ans=mx;
	vector<int> cnt(26,0);
	string s;
	cin>>n>>k;
	cin>>s;
	f(i, n)	cnt[(int)s[i]-65]++;
	f(i, k)	if(cnt[i]<ans) ans=cnt[i];
	cout<<ans*k<<endl;
	return 0;
}