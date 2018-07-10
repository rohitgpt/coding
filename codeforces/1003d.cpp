#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <chrono>
// #include <string>
#include <algorithm>

using namespace std;
// using namespace std::chrono;

// typedef std::chrono::high_resolution_clock::time_point timen;
typedef long long ll;
typedef long double ld;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()
#define f(i, n) for(int (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(int (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(int (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

const int mod=1e9+7;
const int mx=2e5+1000;


int powerof2(int a){
	int i=0, tmp=1;
	for(i=0; tmp<=a; i++) tmp*=2;
	return i-1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp, tmp1, q, qi, ans;
	int a[32], b[32];
	memset(a,0,sizeof(a));
	cin>>n>>q;
	f(i, n){
		cin>>tmp;
		a[powerof2(tmp)]+=1;
	}
	
	copy(a, a+32, b);
	
	f(i, q){
		copy(b, b+32, a);
		cin>>qi;
		ans=0;
		tmp=powerof2(qi);

		while(tmp!=0 && qi>0){
			if(a[tmp]>0){
				tmp1=qi/pow(2,tmp);
				if(tmp1>a[tmp]) tmp1=a[tmp];
				qi-=tmp1*pow(2,tmp);
				a[tmp]-=tmp1;
				tmp=powerof2(qi);
				ans+=tmp1;
			}
			else{
				tmp--;
			}
		}
		if(tmp==0 && a[tmp]>=qi) cout<<ans+qi<<endl;
		else if(qi>0) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}