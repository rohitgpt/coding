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

const ll mx=2e6+10;

int flag, index=1;
vector<ll> adj[mx], c, e, used(mx, 0);
queue<ll> q;
void add_edge(ll a, ll b){
	adj[a].pb(b);
}

void check_bfs(){
	while(q.size()!=0){
		ll a = q.front();
		q.pop();
		while(e[a]){
			flag=1;
			f(i, adj[a].size()){
				if(!used[adj[a][i]] && adj[a][i]==c[index]){
					used[adj[a][i]]=1;
					q.push(adj[a][i]);
					index+=1;
					e[a]--;
					flag=0;	
					break;
				}
			}
			if (flag==1) return;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll ta, tb, n;
	cin>>n;
	f(i, n-1){
		cin>>ta>>tb;
		add_edge(ta, tb);
	}
	f(i, n){
		cin>>ta;
		c.pb(ta);
	}
	f(i, n){
		e.pb(adj[i].size());
	}
	q.push((ll)1);
	used[1]=(ll)1;
	check_bfs();
	if(q.size()!=0) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;

	return 0;
}