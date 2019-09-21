#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i, n) for(int i=0; i<(n); i++)

int main(){
	int t, x, n, ans=1, td, th;
	cin>>t;
	f(i, t){
		cin>>n>>x;
		int diff=INT_MIN, dmax=0;
		f(j, n){
			cin>>td>>th;
			if(td>dmax) dmax=td;
			if(td-th>diff) diff=td-th;
		}
		if(dmax<x && diff<=0) cout<<-1<<endl;
		else if(dmax>=x) cout<<1<<endl;
		else cout<<(x-dmax+diff-1)/diff+1<<endl;
	}
	return 0;
}