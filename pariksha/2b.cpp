#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// using namespace std::chrono;
// typedef std::chrono::high_resolution_clock::time_point timen;
// #define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
// #define timeNow() std::chrono::high_resolution_clock::now()

typedef long long ll;
typedef long double ld;
const ll mx=1e3;
#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(ll (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(ll (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, even_sum, odd_sum, tmp;
	vector<int>a;

	cin>>t;
	f(i, t){
		odd_sum=0;
		even_sum=0;
		cin>>n;
		f(j, n){
			cin>>tmp;
			a.pb(tmp);
		}
		f(j, n){
			odd_sum+=a[j];
			j+=1;
		}
		frp(j, 1, n){
			even_sum+=a[j];
			j+=1;
		}

		frp(j,1,n-1){
			if(a[j]>=a[j-1]+a[j+1]){
				odd_sum+=(a[j]-a[j-1]-a[j+1]);
			}
			j+=1;
		}
		if(n%2==0) if(a[n-1]>a[n-2]) odd_sum+=(a[n-1]-a[n-2]);
		if(a[0]>a[1]) even_sum+=(a[0]-a[1]);
		frp(j, 2, n-1){	
			if(a[j]>=a[j-1]+a[j+1]){
				even_sum+=(a[j+1]-a[j]-a[j+2]);
			}
			j+=1;
		}	
		if(n%2==0) if(a[n-1]>a[n-2]) odd_sum+=(a[n-1]-a[n-2]);
		vector<int>().swap(a);
		cout<<max(odd_sum,even_sum)<<endl;
	}
	return 0;
}