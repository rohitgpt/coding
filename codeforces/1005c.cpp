#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <chrono>
#include <cmath>
#include <map>
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
const int mx=1e3;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp, ans=0;
	vector<int> a;
	map<int, int> c;

	cin>>n;
	ans=n;
	f(i, n){
		cin>>tmp;
		a.pb(tmp);
	}

	sort(a.begin(), a.end());
	
	map<int, int>::iterator it;
	f(i, n){
		it=c.find(a[i]);
		if(it!=c.end()) it->second+=1;
		else c.insert(make_pair(a[i], 1));
	}

	int ub = log2(a[a.size()-1]);
	f(i, n){
		frp(j, 1,ub+2){
			it=c.find(pow(2, j)-a[i]);
			if(it!=c.end()){
				if(it->second>=2 || (it->second==1 && pow(2, j)-a[i]!=a[i])){
					ans-=1;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}