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
	int t, n;
	cin>>t;
	f(i, t){
		cin>>n;
		if(n==2010 || n==2019 || (n>=2015 && n<=2017)) cout<<"HOSTED"<<endl;
		else cout<<"NOT HOSTED"<<endl;
	}
	return 0;
}