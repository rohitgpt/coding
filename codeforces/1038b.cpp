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

const ll mx=2e5+10;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;
	if(n<3) cout<<"No"<<endl;
	else{
		cout<<"Yes"<<endl;
		cout<<(n+1)/2<<" ";
		f(i,n){
			cout<<++i<<" ";
		}
		cout<<endl<<(n)/2<<" ";
		frp(i, 1, n){
			cout<<++i<<" ";
		}
		cout<<endl;
	}
	return 0;
}