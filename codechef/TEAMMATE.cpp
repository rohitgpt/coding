#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mx=1e5+10;
const ll mod=1000000007;

bool comp(int a, int b){
	return a>b;
}

ll ans(ll cur, ll n){
	for(int i=1; i<=n; i++){
		if(i%2==0) cur = (cur*i/2)%mod;
		else cur = (cur*i)%mod;
	}
	return cur;
}

int main(){
	int t, n;
	ll cur=0;
	vector<ll> s(mx);
	map<int, int> a;
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>n;
		for(int j=0; j<n;j++){
			cin>>s[j];
			if(a[s[j]]) a[s[j]]+=1;
			else a[s[j]]=1;
		}
		cur=1;
		for(map<int, int>::iterator it=a.begin(); it!=a.end(); it++){
			if(it->second>1) cur = ans(cur, it->second);
		}
		cout<<cur<<endl;
		a.clear();
	}
	return 0;
}