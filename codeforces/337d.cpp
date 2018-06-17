#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <string>
#include <algorithm>

typedef long long ll;
typedef long double ld;

#define f(i, n) for(int (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(int (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(int (i)=a; (i)>(b); (i)--)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

using namespace std;

const int mod = 1e9+7;
const int mx = 1e5+100;

class graph{
	int v;
	vector<int> *adj;
public:
	graph(int v);
	void add_edge(int v, int w);
	vector<int> return_adj(int v);
};

graph::graph(int a){
	this->v = a;
	adj = new vector<int>[a];
}

void graph::add_edge(int a, int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}

vector<int> graph::return_adj(int a){
	return adj[a];
}
int d,cd;
int visited[mx];
vector<int> *ps;
vector<int> tmp;
void ps_maker(graph g, int a, int parent, int v){
	// base case
	// if we at depth d return
	// else keep going
	p(v);
	
	visited[v] = 1;
	ps[a].push_back(v);
	if(cd>=d) return;

	tmp = g.return_adj(v);
	f(k, tmp.size()){
		cd+=1;
		if(!visited[tmp[k]] && tmp[k]!=parent) ps_maker(g,a,v,tmp[k]);
		cd-=1;
		if(k==tmp.size()) ps_maker(g, a, parent, parent);

	}
	// ps_maker(g,a,parent,parent);

	// if(cd>=d || visited[v]){
	// 	visited[v]=1;
		
	// 	cout<<v<<" visitied"<<endl;
	// 	return v;
	// }
	// // repetitive case
	// tmp = g.return_adj(v);
	// f(k, tmp.size()){
	// 	cd+=1;

	// 	cout<<tmp[k]<<" with "<<k<<" is being processed"<<endl;
	// 	if(!visited[tmp[k]] && tmp[k]!=parent && tmp[k]!=v){
	// 		ps[a].push_back(ps_maker(g,a,v,tmp[k]));
	// 	}
	// 	cd-=1;
	// 	// if(k==tmp.size()) visited[v]=1;
	// }
	// cout<<v<<" visited"<<endl;
	// visited[v]=1;


	// visited[v]=1;
	// // p(v);
	// ps[a].push_back(v);
	// if(cd>=d){
	// 	// cd-=1; 
	// 	return;
	// }
	// tmp = g.return_adj(v);
	// // cout<<tmp.size()<<" "<<v<<endl;	
	// f(k, tmp.size()){ 
	// 	// p(k);
	// 	// p(tmp.size());
	// 	if(!visited[tmp[k]]){
	// 		cd+=1;
	// 		p(v);
	// 		ps_maker(g, a, tmp[k]);
	// 		cd-=1;
	// 	}
	// }
	// return ps_maker(g, a, v);
	// // cd-=1;
	// // return;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int a, b, c=0;
	int p[mx];
	// memset(visited, 0, sizeof(visited));
	graph g(mx);
	cin>>n>>m>>d;
	ps = new vector<int>[n+1];
	f(i, m)		cin>>p[i];
	f(i, n-1){
		cin>>a>>b;
		// if()
		g.add_edge(a,b);
	}
	// tmp = g.return_adj(14);
	// f(i, tmp.size()) cout<<tmp[i]<<endl;

	// ps_maker(g,0,p[0]);
	// sort(ps[0].begin(),ps[0].end());
	f(i, m){
		memset(visited,0,sizeof(visited));
		cd = 0;
		ps_maker(g, i, p[i], p[i]);
		sort(ps[i].begin(), ps[i].end());
		f(j, ps[i].size()) cout<<ps[i][j]<<" ";
		cout<<endl;
	}
	vector<int>fps;
	fps = ps[1];
	// f(i, fps.size()) cout<<fps[i]<<endl;
	f(i, m){
		// f(j, ps[i].size()) cout<<ps[i][j]<<" ";
		// vector<int> alpha;
		set_intersection(ps[i].begin(), ps[i].end(), fps.begin(), fps.end(), tmp.begin());
		fps =tmp;
		// cout<<tmp.size()<<endl;
		// f(j, tmp.size()+1) cout<<tmp[j]<<" ";
	}
	// cout<<fps.size()+1;
	return 0;
}