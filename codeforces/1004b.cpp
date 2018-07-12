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
const int mx=1e3;

struct s
{
	int v;
	int len;
	int rose;
	int lily;
	vector<int> adj;
};

int n, m, tl, tr;
vector<struct s> a;
vector<int> g;
vector<int> l, r, fri;

bool complen(const s &a, const s &b){
	return a.len<b.len;
}

void putflowers(int t, int p){

	while(!a[t].adj.empty()){
		// cout<<a[t].adj.back()<<endl;
		putflowers(a[t].adj.back(), t);
		a[t].adj.pop_back();
	}
	// check which location are filled, fill the remaining
	// subtract from a[p].rose and a[p].lily
	// check which locations are filled fill the remaining with a[p].rose and a[p].lily
	frp(j, l[a[t].v]-1, r[a[t].v]){
		// cout<<g[j]<<" "<<a[t].rose<<endl;
		if(g[j]==0) a[t].rose-=1;
		else if(g[j]==1) a[t].lily-=1;
	}
	frp(j, l[a[t].v]-1, r[a[t].v]){
		if(a[t].rose+a[t].lily>0 && g[j]==-1){
			if(a[t].rose>0){g[j]=0; a[t].rose-=1;}
			else {g[j]=1; a[t].lily-=1;}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	s tmp;
	

	cin>>n>>m;
	f(i, n) g.pb(i%2);
	f(i, n) cout<<g[i];
	return 0;
	
	f(i, m){
		cin>>tl>>tr;
		l.pb(tl);
		r.pb(tr);
		tmp.v=i;
		tmp.len=r[i]-l[i]+1;
		tmp.rose=(r[i]-l[i]+1)/2;
		tmp.lily=(r[i]-l[i]+2)/2;
		a.pb(tmp);
	}
	sort(a.begin(), a.end(), complen);

	f(i, m-1){
		int flag=0;
		frp(j, i+1, m){
			if(r[a[i].v]<=r[a[j].v] && l[a[i].v]>=l[a[j].v]){
			// cout<<r[a[i].v]<<" "<<r[a[j].v]<<" "<<l[a[i].v]<<" "<<l[a[j].v]<<endl;
				a[j].adj.pb(a[i].v);
				flag=1;
				break;
			}
		}
		if(flag==0) fri.pb(i);
	}
	fri.pb(m-1);
	// cout<<"hello"<<endl;
	f(i, fri.size()){
		// cout<<fri[i]<<endl;
		putflowers(fri[i], -1);
	}

	f(i, n) if(g[i]==-1) g[i]=1;
	f(i, n) cout<<g[i];
	cout<<endl;
	return 0;
}
