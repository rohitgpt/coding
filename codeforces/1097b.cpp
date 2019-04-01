#include <bits/stdc++.h>

#define f(i, n) for(int i=0; i<(n); i++)
#define mx 15;
using namespace std;

int n, flag=0;
vector<int> a;
int dp(int i, int sum){
	if(flag==1)	return 1;
	if(i==n-1){
		if((sum+a[i])%360==0 || (sum-a[i])%360==0) flag=1; 
		return 0;
	}
	return dp(i+1, sum+a[i]) + dp(i+1, sum-a[i]);
}

int main(){
	cin>>n;
	a.resize(n);
	f(i, n) cin>>a[i];
	dp(0,0);
	if(flag==1)	cout<<"YES"<<endl;
	else	cout<<"NO"<<endl;
	return 0;
}