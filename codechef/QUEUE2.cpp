#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld; 
#define all(c) (c).begin(), (c).end();
#define tr(c, it) for(__typeof__((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define f(i, a) for(ll (i)=0; (i)<(a); (i)++)
#define pb push_back

const ll mx=1e9;
const ll mod=1e9+7;

int main(){
	int t, l, n, k, m, tmp, cnt;
	cin>>t;
	vector<int> a;
	f(i, t){
		cin>>n>>m>>k>>l;
		int ct = l*m;
		int tamp = 0, mint=1e9, mini=-1;
		f(j, n){
			cin>>tmp;
			a.pb(tmp);
		}
		sort(a.begin(), a.end());
		if(max(a[0]+l, 2*l)>k){
			cout<<min(k, a[0])<<endl;
			continue;
		}
		int last=max(a[0]+l,2*l);
		int j=0;
		while(last<=k && j<a.size()){
			j++;
			if(mint>(last-a[j])){
				mint=last-a[j];
				mini=j;
			}
			last=max(a[i]+l, 2*l);
		}
		if(last<=k) cout<<k<<endl;
		else cout<<a[mini]<<endl;
		a.clear();
	}
	return 0;
}