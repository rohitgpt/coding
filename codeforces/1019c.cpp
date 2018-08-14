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

int main(){
	int n, m, ans=1, t1, t2, flag=0;
	cin>>n>>m;
	vector<int> adj[n], q, removed, saved, has_neighbor, answer_set;
	f(i, n){
		removed.pb(0);
		has_neighbor.pb(0);
	} 
	f(i, m){
		cin>>t1>>t2;
		adj[t1-1].pb(t2-1);
		has_neighbor[t1-1]=1;
	} 
	f(i, n){
		if(!removed[i] ){
			saved.pb(i);
			// cout<<i<<endl;
			removed[i]=1;
			if(has_neighbor[i])
				f(j, adj[i].size())
					removed[adj[i][j]]=1;
		}
	}
	answer_set.pb(saved[saved.size()-1]);
	// cout<<saved.size()<<endl;
	frn(i, saved.size()-2, -1){
		f(j, answer_set.size()){
			if(has_neighbor[answer_set[j]])
				f(k, adj[answer_set[j]].size())
					if(saved[i]==adj[answer_set[j]][k]){
						flag=1;
						break;
					}
			if(flag==1) break;
		}
		if(flag==0) answer_set.pb(saved[i]);
		flag=0;
	}
	cout<<answer_set.size()<<endl;
	f(i, answer_set.size()) cout<<answer_set[i]+1<<" ";
	return 0;
}

//
//My solution not working

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	int n, m, ans=1, t1, t2, f, count=0;

// 	cin>>n>>m;

// 	vector<int> adj[n+1], q, visited, visiting, set, has_neighbor;
// 	f(i, n){ visited.pb(0); set.pb(0); has_neighbor.pb(0); visiting.pb(0);}
// 	f(i, m+1){
// 		cin>>t1>>t2;
// 		adj[t1].pb(t2);
// 		adj[t2].pb(t1);
// 		has_neighbor[t1]=1;
// 	}

// 	q.pb(1);
// 	set[1] = 1;
// 	while(count<q.size()){
// 		f = q[count];
// 		visiting[f]=1;
// 		if(!visited[f]){
// 			if(has_neighbor[f]){
// 				f(i, adj[f].size()){
// 					t1=adj[f][i];
// 					if(!visiting[t1]){
// 						q.pb(t1);
// 						visiting[t1]=1;
// 						if(set[f]!=1){ set[t1]=1; ans+=1;}
// 						else set[t1]=2;
// 					}
// 				}
// 			}
// 			visited[f]=1;
// 			count+=1;
// 		}
// 	}
// 	cout<<ans<<endl;
// 	f(i, n+1) if(set[i]==1) cout<<i<<" ";
// 	return 0;
// }