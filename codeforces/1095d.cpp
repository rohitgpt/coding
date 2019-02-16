#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)

int main(){
	int n, p, q;
	cin>>n;
	vector<pair<int, int> > a(n);
	vector<int> b(n);
	f(i, n){
		cin>>p>>q;
		a[i]=make_pair(p-1, q-1);
	}
	b[0]=0;
	int j=0, f, g;
	cout<<1<<endl;
	while(j<n){
		f=a[b[j]].first;
		g=a[b[j]].second;
		if(a[f].first!=g && a[f].second!=g){
			b[j+1]=g;
			b[j+2]=f;
		}
		else{
			b[j+1]=f;
			b[j+2]=g;
		}
		j+=2;
	}
	f(i, n-1){
		cout<<b[i+1]+1<<endl;
	}

	return 0;
}