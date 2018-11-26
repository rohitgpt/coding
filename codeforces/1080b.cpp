#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i,n) for(int (i)=0; (i)<(n); (i)++)

ll findsum(ll n){
	if(n==0) return 0;
	if(n%2==1){
		return -(n/2+1)*(n/2+1)+((n-1)/2+1)*(n-1)/2;
	}
	else{
		return (n/2)*(n/2+1)-((n-1)/2+1)*((n-1)/2+1);
	}
}

int main(){
	ll n, a,b;
	cin>>n;
	f(i, n){
		cin>>a>>b;
		// cout<<findsum(b)<<" ";
		cout<<findsum(b)-findsum(a-1)<<endl;
	}
	return 0;
}