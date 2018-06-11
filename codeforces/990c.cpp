#include <iostream>
#include <bits/stdc++.h>
// #include <vector>
// #include <string>
// #include <algorithm>

typedef long long ll;
typedef long double ld;

#define f(i, n) for(int (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(int (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(int (i)=a; (i)>(b); (i)--)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

using namespace std;

const int mod = 1e9+7;
const int mx = 3e5+100;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll  n,ans=0;
	// char a[mx];
	char tmp[mx];
	int value[mx];//,indices[mx], len[mx];
	int minv[mx];
	memset(minv, 0, sizeof(minv));
	memset(value, 0, sizeof(value));
	cin>>n;
	// indices[0] = 0;
	f(i, n){
		// char* tmp = &a[indices[i]];
		cin>>tmp;
		f(j, strlen(tmp)){
			if(tmp[j]=='(') value[i]+=1;
			else value[i]-=1;
			// else if(tmp[j]==')') value[i]-=1;
			if(value[i]<minv[i]) minv[i]=value[i];
		}
		// indices[i+1] = indices[i]+strlen(tmp);
		// len[i] = strlen(tmp);
	}
	f(i, n){
		if(minv[i]>=0){
			f(j,n){
				if(value[i]+value[j]==0) if(value[i]+minv[j]>=0) ans+=1;
				// p(value[i]+value[j]);
				// if(value[i]+value[j]) continue;
				// if(value[i]+minv[j]<0) continue; 
				// cout<<i<<j<<endl;
				// ans+=1;
			}
		}

	}
	cout<<ans<<endl;
	return 0;
}
