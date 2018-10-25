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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, count=0;
	string s;
	cin>>n;
	cin>>s;
	f(i, s.size()){
		// cout<<s[i];
		if(s[i]=='8'){
			count+=1;
		}
	}
	// cout<<n<<" "<<count<<endl;
	if(n>=11 && count>0){
		cout<<min(count, n/11);
	}
	else{
		cout<<0<<endl;
	}
	return 0;
}