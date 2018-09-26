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
const int mx=2e5;

vector<int> adj[mx], visited(mx), dist(mx), custack;

void addEdge(int a, int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
	return;
}

int verticesAdded=0,max_distance=2;

void travel(int node, int curDistance){
	visited[node]=1;
	// cout<<"Visiting "<<node<<" with curDistance: "<<curDistance<<endl;
	int cnode, all_visited=1;
	// stack.pop_back();
	f(i, adj[node].size()){
		cnode=adj[node][i];
		if(visited[cnode]<1){
			all_visited=0;
			// cout<<"calling node "<<cnode<<" with dist "<<dist[node]+1<<endl;
			dist[cnode]=dist[node]+1;
			travel(cnode, dist[node]+1);
		}
		if(all_visited && dist[node]>max_distance){
			// cout<<"Current Distance is more than needed for node "<<node<<endl;
			verticesAdded+=1;
			addEdge(1, node);
			// dist[cnode]=2;
			dist[node]=1;
			travel(node, 1);
		}
		if(all_visited && dist[cnode]>=max_distance){ 
			visited[node]=2;
			// cout<<dist[node]<<endl;
			// cout<<verticesAdded<<endl;
			// cout<<"Visited "<<node<<endl;
		}
	}
	// dist[cnode]=curDistance+1;
	// visited[node]=2;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ta, tb;
	cin>>n;

	f(i, n-1){
		visited[i+1]=0;
		cin>>ta>>tb;
		addEdge(ta,tb);
	}

	travel(1, 0);
	cout<<verticesAdded<<endl;

	// f(i, n){
	// 	// cout<<i+1<<" ";
	// 	f(j, adj[i+1].size())		cout<<adj[i+1][j]<<" ";
	// 	cout<<endl;
	// }

	return 0;
}