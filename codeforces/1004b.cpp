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
const int mx=1e9;

struct s
{
	int v;
	int len;
	int rose;
	int lily;
	vector<int> adj;
};

vector<s> a;
vector<int> g;
vector<int> l, r, fri;

bool complen(const s &a, const s &b){
	return a.len<b.len;
}

void putflowers(int t, int p){
	while(!a[t].adj.empty()){
		putflowers(a[t].adj.back(), t);
		a[t].adj.pop_back();
	}
	//check which location are filled, fill the remaining
	//subtract from a[p].rose and a[p].lily
	//check which locations are filled fill the remaining with a[p].rose and a[p].lily
	frp(i, l[a[t].v], r[a[t].v]+1){
		if(g[i]==0) a[t].rose-=1;
		else if(g[i]==1) a[t].lily-=1;
		else{
			if(a[t].rose>0) g[i]=0;
			else g[i]=1;
		}
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout<<"hello";
	int n, m, tl, tr;
	s tmp;
	f(i, n) g.pb(-1);

	cin>>n>>m;
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
			if(r[a[i].v]<r[a[j].v] && l[a[i].v]>l[a[j].v]){
				a[j].adj.pb(a[i].v);
				flag=1;
				break;
			}
		}
		if(flag==0) fri.pb(i);
	}
	fri.pb(m-1);

	f(i, fri.size()){
		putflowers(fri[i], -1);
	}
	f(i, n) cout<<g[i]<<" ";
	cout<<endl;
	return 0;
}
