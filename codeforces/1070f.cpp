#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i,n) for(int (i)=0; (i)<(n); (i)++)

int main(){
	int n, t, u;
	vector<int> a,b,c,d;
	cin>>n;
	int cnt=0;
	ll ans=0;
	f(i, n){
		cin>>t>>u;
		if(t==11){
			ans+=u;
			cnt+=1;
		}
		else if(t==1){
			b.push_back(u);
		}
		else if(t==10){
			a.push_back(u);
		}
		else if(t==0){
			c.push_back(u);
		}
	}
	t=min(a.size(), b.size());
	if(t==0 && cnt==0) cout<<0<<endl;
	else{
		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());
		sort(c.rbegin(),c.rend());
		c.resize(cnt+a.end()-a.begin()-t+b.end()-b.begin()-t);
		copy(a.begin()+t, a.end(), c.begin()+cnt);
		copy(b.begin()+t, b.end(), c.begin()+cnt+(a.end()-a.begin())-t);
		sort(c.rbegin(), c.rend());
		// f(i, c.size()) cout<<c[i]<<" ";
		f(i, cnt)	ans+=c[i];
		f(i, t) ans+=a[i]+b[i];
		cout<<ans<<endl;
	}
	return 0;
}