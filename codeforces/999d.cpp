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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,r,s=0, t;
	ll ans=0, a[mx];
	int b[mx],c[mx];
	memset(c,0,sizeof(c));
	cin>>n>>m;
	int flag=0;
	t=m-1;
	f(i,n){
		cin>>a[i];
		r = a[i]%m;
		c[r]+=1;
		if(c[r]>n/m){
			c[r]-=1;
			frp(j,max(r,s),m){
				if(c[j]<n/m){
					a[i]=j-r+a[i]; ans+=j-r;
					// if(r>j){	a[i]=m+j-r+a[i]; ans+=m+j-r;}
					// else{	a[i]=j-r+a[i]; ans+=j-r;}
					c[j]+=1;
					if(c[j]==n/m) s=j;
					break;
				}
				if(j==m-1) flag=1;	
			}
			if(flag==1){
				s=0;
				flag=0;
				frp(j,s,m)
					if(c[j]<n/m){
						a[i]=m+j-r+a[i]; ans+=m+j-r;
						// if(r>j){	a[i]=m+j-r+a[i]; ans+=m+j-r;}
						// else{	a[i]=j-r+a[i];	ans+=j-r;}
						c[j]+=1;
						if(c[j]==n/m) s=j;
						break;
					}
			}
		}
	}
	cout<<ans<<endl;
	f(i,n)cout<<a[i]<<" ";
	return 0;
}
