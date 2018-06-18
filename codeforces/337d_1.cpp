#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <chrono>
// #include <string>
// #include <algorithm>
using namespace std;
// using namespace std::chrono;

// typedef std::chrono::high_resolution_clock::time_point timen;
typedef long long ll;
typedef long double ld;

#define duration(a) std::chrono::duration_cast<std::chrono::microseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()
#define f(i, n) for(int (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(int (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(int (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

const int mod=1e9+7;
const int mx=1e5+10;

class graph{
	int v;
	vector<int> *adj;
public:
	graph(int v);
	void add_edge(int v, int w);
	vector<int> return_adj(int v);
};

graph::graph(int a){
	this->v=a;
	adj = new vector<int>[a];
}

void graph::add_edge(int a, int b){
	adj[a].pb(b);
	adj[b].pb(a);
}

vector<int> graph::return_adj(int a){
	return adj[a];
}


int n,m,d;
int a, b, mark[mx], marked[mx]={0}, parent[mx], downdist[mx], updist[mx];
graph g(mx);

int dfs2(int v){
	if(marked[parent[v]]==1) return 0;

	vector<int> tmp = g.return_adj(parent[v]);
	int maxd = -mx;
	f(i, tmp.size()){
		if(tmp[i]==v || tmp[i]==parent[parent[v]]) continue;
		if(downdist[tmp[i]]>maxd) maxd=downdist[tmp[i]];
	}
	maxd+=2;
	int maxu=dfs2(parent[v])+1;
	updist[v] = max(maxu, maxd);
	return updist[v];
}

int dfs(int p, int v){
	parent[v]=p;
	vector<int> tmp;
	// p("hello");
	tmp = g.return_adj(v);
	// cout<<p<<" "<<" "<<tmp.size()<<" "<<tmp[0]<<" "<<tmp[1]<<endl;
	if(tmp.size()==1){
		dfs2(v);
		if(marked[v]==1)	return 0;
		else return -mx;
	} 
	int maxv=-mx;
	f(i, tmp.size()){
		if(tmp[i]==p) continue;
		downdist[tmp[i]] = dfs(v, tmp[i]);
		if (downdist[tmp[i]]>maxv) maxv=downdist[tmp[i]];
	}
	return maxv+1;
}

void calldfs2(int p, int v){
	vector<int> tmp = g.return_adj(v);
	if(tmp.size()==1){
		dfs2(v);
	}
	f(i,tmp.size()){
		if(tmp[i]==p) continue;
		calldfs2(v, tmp[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m>>d;
	f(i,m){ 
		cin>>mark[i];
		marked[mark[i]]=1;
	}
	// memset(updist, -mx, sizeof(updist));
	// memset(downdist, -mx, sizeof(downdist));

	f(i,n-1){
		cin>>a>>b;
		g.add_edge(a,b);
	}
	dfs(mark[0], mark[0]);
	
	calldfs2(mark[0], mark[0]);
	int ans=0;
	f(i, n){
		// cout<<i<<" "<<downdist[i]<<" "<<updist[i]<<endl;
		if(!marked[i] && downdist[i]<d && updist[i]<d){ ans+=1;}
	}

	cout<<ans<<endl;
	return 0;
}