#include <bits/stdc++.h>

#define f(i, n) for(int i=0; i<(n); i++)
#define mx 15;
using namespace std;

int n;
vector<int> a;
int flag=0;
int dp(int i, int sum){
	return dp(i+1, sum+a[i]) + dp(i+1, sum-a[i]);
	if(i==n-1)
		if((sum+a[i])%360==0 || (sum-a[i])%360==0) flag==0; 
	if(flag==1){
		return 1;
	}
}

int main(){
	cin>>n;
	a.resize(n);
	f(i, n) cin>>a[i];
	if(flag==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}