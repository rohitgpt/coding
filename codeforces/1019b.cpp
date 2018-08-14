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

bool comp(int a, int b){
	if(a>b) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, f, count;

	cin>>n;

	vector<int> adj(n), visited, q;
	f(i, n){
		cin>>f;
		visited.pb(0);
		adj[i]=f-1;
	}

	f(i, n){
		q.pb(i);
		count=0;
		while(count<q.size()){
			f = q[count];
			if(visited[f]){
				cout<<f+1<<" ";
				break;
			}
			visited[f]=1;
			q.pb(adj[f]);
			count+=1;
		}
		vector<int>().swap(q);
		f(j, n) visited[j]=0;
	}
	return 0;
}