#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mx=1e5+10;
bool comp(int a, int b){
	return a>b;
}

int main(){
	int t, tmp, n, ans=0, k, flag=0, count;
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>n>>k;
		ll s[n];
		for(int j=0;j<n;j++) cin>>s[j];
		
		sort(s,s+n, comp);
		tmp=s[k-1];
		for(count=k-1; s[count]==tmp; count++);
		cout<<count<<endl;
	}
	return 0;
}