#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <chrono>
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
const int mx=2e5+1000;

int n, m, q, t1, t2, ans=0, cnt=0;
vector<int> V[mx], v(6), flag(5);

void r(int r1, int c1, int r2, int c2){
	if(c2-c1==0 || r2-r1==0){
		ans+=n*m-q;
		return;
	}
	if(c2-c1==1 && r2-r1==1){
		vector<int>(5).swap(flag);
		v[1]=V[r1][c1], v[2]=V[r1][c2], v[3]=V[r2][c1] ,v[4]=V[r2][c2];
		// cout<<"Looking at"<<endl;
		// cout<<v[1]<<" "<<v[2]<<endl;
		// cout<<v[3]<<" "<<v[4]<<endl;
		v[5]=v[1]+v[2]+v[3]+v[4];
		if(v[5]==4) return;
		else if(v[5]==3){
			frp(i, 1, 5) 
				if(v[i]!=1){
					flag[i]=1;
					break;
				}
		}
		else if(v[5]==2){
			cnt=0;
			frp(i, 1, 5)
				if(v[i]!=1){
					flag[i]=1;
					cnt+=1;
					if(cnt>1) break;
					ans+=1;
					// cout<<"Adding"<<endl;
				}
			
		}
		else if(v[5]==1){
			cnt=0;
			frp(i, 1, 5)
				if(v[i]!=1){
					flag[i]=1;
					cnt+=1;
					if(cnt>2) break;
					ans+=1;
					// cout<<"Adding"<<endl;
				}
		}
		else{
			cnt=0;
			frp(i, 1, 5)
				if(v[i]!=1){
					flag[i]=1;
					cnt+=1;
					if(cnt>3) break;
					ans+=1;
					// cout<<"Adding"<<endl;
				}
		}
		if(flag[1]==1) V[r1][c1]=1;
		if(flag[2]==1) V[r1][c2]=1;
		if(flag[3]==1) V[r2][c1]=1;
		if(flag[4]==1) V[r2][c2]=1;
		return;
	}
	else{
		if(c2-c1>1){
			r(r1, c1, r2, c2-1);
			r(r1, c1+1, r2, c2);
		}
		if(r2-r1>1){
			r(r1, c1, r2-1, c2);
			r(r1+1, c1, r2, c2);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m>>q;
	f(i, n)
		f(j, m)
			V[i].pb(0);
	
	f(i, q){
		cin>>t1>>t2;
		V[t1-1][t2-1]=1;
	}


	r(0, 0, n-1, m-1);

	cout<<ans<<endl;
	return 0;
}

