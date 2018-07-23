#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <chrono>
// #include <cmath>
// #include <map>
#include <string>
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
const int mx=2e5+100;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, tmp, ans=0, div[mx];
	vector<int> cuts, len, a;
	char *t;
	string s;

	cin>>s;
	memset(div, 0, sizeof(div));
	tmp=0;
	f(i, s.size()){
		a.pb(s[i]-'0');
		if(a[i]%3==0){
			ans+=1;
			div[i]=1;
			if(tmp>0){
				len.pb(tmp);
				tmp=0;
			}
			continue;
		}
		if(tmp==0) cuts.pb(i);
		tmp+=1;
	}
	if(tmp>0)	len.pb(tmp);
	tmp=0;

	f(j, cuts.size()){
		frp(i, 2, len[j]+1){
			int tmp_index=0;
			while(tmp_index<=len[j]-i){
				frp(k, cuts[j]+tmp_index, cuts[j]+tmp_index+i) tmp+=a[k];
				// cout<<tmp<<endl;
				if(tmp%3==0){ 
					ans+=1;
					frp(k, cuts[j]+tmp_index, cuts[j]+tmp_index+i){
						div[k]=1;
					}
					tmp_index+=i;
				}
				else tmp_index+=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}