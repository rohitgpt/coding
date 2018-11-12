#include<bits/stdc++.h>
using namespace std;

#define f(i,n) for(int (i)=0; (i)<(n); (i)++)

int main(){
	int n, s;
	cin>>n>>s;
	vector<int> a(n), b(n);
	f(i, n)	cin>>a[i];
	f(i, n) cin>>b[i];
	if(a[0]==0 || (a[s-1]==0 && b[s-1]==0)){cout<<"NO"<<endl; return 0;}
	if(a[s-1]==1){ cout<<"YES"<<endl; return 0;}
	else{
		int flag=0;
		for(int i=s; i<n; i++) if(a[i]==1 && b[i]==1) flag=1;
		if(flag==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}