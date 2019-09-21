#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i, n) for(int i=0; i<(n); i++)
vector<int> arr;

int main(){
	int s, t, a, e;
	cin>>t;
	f(i, t) {
	cin>>s>>a>>e;
	int ans = (e+a-s+2)/2;
	if(ans<0) ans=0;
	if(e-ans+1>0) cout<<e-ans+1<<endl;
	else cout<<0<<endl;
	}
	return 0;
}