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

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

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
int d;
int visited[mx];
vector<int> *ps;

int ps_maker(graph g, int a, int p, int v, int cd){
	if(cd>=d){ 
		ps[a].push_back(v); 
		return 1;
	} 
	vector<int>tmp = g.return_adj(v);
	f(j,tmp.size()){
		if(tmp[j]==p) continue;
		if(visited[tmp[j]]==0){
			visited[tmp[j]]=ps_maker(g,a,v,tmp[j],cd+1);
		}
	}
	ps[a].push_back(v);
	return 1;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int a, b, c=0;
	int p[mx];

	graph g(mx);
	cin>>n>>m>>d;
	ps = new vector<int>[n+1];
	f(i, m)		cin>>p[i];
	f(i, n-1){
		cin>>a>>b;
		g.add_edge(a,b);
	}

	// timen start = timeNow();


	f(i, m){
		memset(visited,0,sizeof(visited));
		a = ps_maker(g, i, p[i], p[i], 0);
		sort(ps[i].begin(), ps[i].end());
		// f(j, ps[i].size()) cout<<ps[i][j]<<" ";
		// cout<<endl;
	}

	// timen stop = timeNow();
	// cout <<"process time: "<<duration(stop-start)/1000 << endl;
	

	vector<int>fps;
	vector<int>temp;
	vector<int>alpha;
	fps = ps[0];
	frp(i, 1, m){
		set_intersection(ps[i].begin(), ps[i].end(), fps.begin(), fps.end(), back_inserter(temp));
		fps=temp;
		temp=alpha;
		// p(fps.size());
		// f(j, fps.size()) cout<<fps[j]<<" ";
		// cout<<endl;
	}
	f(i,fps.size()) cout<<fps[i]<<" ";	
	cout<<fps.size();
	return 0;
}