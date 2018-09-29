#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(ll (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(ll (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

const ll mx=1e9+10;

int positive(int a,int b){
	if(a>b) return a-b;
	else return b-a;
}
int negative(int a, int b){
	if(a>b) return b-a;
	else return a-b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, indicator=0, flag=0,t, ans=mx, sum=0;
	vector<ll>a;
	cin>>n;
	cin>>t;
	ans=abs(t);
	if(n==1){ cout<<t<<endl; return 0;}
	if(t<0) indicator=1;
	f(i, n-1){
		cin>>t;
		if(t<0 && indicator==0) flag=1;
		else if(t>0 && indicator==1) flag=1;
		if(abs(t)<abs(ans)){ sum+=abs(ans); ans=abs(t); }
 		else sum+=abs(t);
	}
	if(flag==1) cout<<sum+ans<<endl;
	else cout<<sum-ans<<endl;
	return 0;
}
