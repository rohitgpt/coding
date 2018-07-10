#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <chrono>
// #include <string>
#include <algorithm>
#include <cmath>
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, tmp, ans=0, lastgood=0;
	vector<int> a, good, lg10, gotoi;

	cin>>n>>k;
	f(i,n){
		cin>>tmp;
		a.pb(tmp);
		gotoi.pb(0);
		if(tmp>1){
			if(lastgood!=0){
				lastgood=0;
				gotoi[lastgood]=i-lastgood;
			}
			good.pb(1);
		}
		else{
			if(i!=0 && good[i-1]) lastgood=i-1;
			good.pb(0);
		}
		lg10.pb(log10(tmp));
		//if i is not good i-1 is good, lastgood=i-1, if(lastgood!=0 && tmp>1) lastgood=0 gotoi[lastgood]=i;  
	}

	f(i, n){
		int count=0;
		int sum=0;
		int lg=0;
		ll product=1;
		frp(j, i, n){
			count+=good[j];
			if(count>60) break;
			sum+=a[j];
			if(good[j]){
				lg+=lg10[j];
				if(lg>17) break;
				product*=a[j];
			}
			if(product>=sum)
				if(product==k*sum){
					ans+=1;
					// if(good[j]) break;
				}
			j+=gotoi[j];
		}
	}
	cout<<ans<<endl;
	return 0;
}