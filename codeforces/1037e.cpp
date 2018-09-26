#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(ll (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(ll (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

const ll mx=2e5+10;

vector<int> adj[mx];
void add_edge(ll a, ll b){
	adj[a].pb(b);
	adj[b].pb(a);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a,b,ta, tb, n,m,k, count=0, icount, qc=0;
	cin>>n>>m>>k;
	vector<int> lst, q, todelete(n, 0), deleted(n, 0);
	f(i, m){
		cin>>ta>>tb;
		add_edge(ta, tb);
		f(j, n+1){
			lst.pb(adj[j].size());
			if(adj[j].size()<k){ q.pb(j); todelete[j]=1;}
		}
		// frp(j, 1,lst.size()){
		// 	cout<<lst[j]<<" ";
		// }
		while(qc<q.size()){
			a = q[qc];
			f(j, lst[a]){
				b=adj[a][j];
				lst[b]--;
				if(lst[b]<k && !todelete[b]){ q.pb(b); todelete[b]=1;}
			}
			lst[a]=0;
			qc++;
		}
		qc=0;
		// cout<<endl;
		frp(j, 1,n+1){
			if(lst[j]>=k) count+=1;
		}
		cout<<count<<endl;
		count=0;
		vector<int>(n,0).swap(todelete);
		vector<int>().swap(lst);
		vector<int>().swap(q);
	}
	return 0;
}