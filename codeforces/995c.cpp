#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <chrono>
// #include <string>
// #include <algorithm>
#include <cmath>
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

const int mod=1.5e6+0;
const int mx=2e5+1000;

struct qnode
{
	int v;
	int x;
	int y;
	int s;
	int parent;
};

int cv=0;
vector<qnode> a;

int vsum(qnode p, qnode q, int s){
	if(s>0)	return sqrt(pow(p.x+q.x, 2)+pow(p.x+q.x,2));
	else 	return sqrt(pow(p.x-q.x, 2)+pow(p.x-q.x,2));	
}

int signage(int v, int s){
	// cout<<v<<" "<<s<<" "<<a[v].s<<endl;
	if(a[v].parent==-1) return s;
	return s*signage(a[v].parent, a[v].s);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, sign[mx];
	cin>>n;
	qnode temp;	
	f(i,n){
		temp.v=i;
		cin>>temp.x>>temp.y;
		temp.parent=-1;
		temp.s=1;
		a.pb(temp);
		cv+=1;
	}
	int v1, v2;
	qnode p, q;
	f(i, a.size()-1){
		qnode r={cv++,0,0,1,-1};
		p = a[i];
		q = a[i+1];
		p.s = 1;
		v1 = vsum(p,q,1);
		v2 = vsum(p,q,-1);
		cout<<abs(v1)<<" "<<abs(v2)<<endl;
		// cout<<v1<<" "<<v2<<endl;
		if(abs(v1)>abs(v2)){
			q.s=-1;
			r.x=p.x-q.x;
			r.y=p.y-q.y;
		}
		else{
			q.s=1;
			r.x=p.x+q.x;
			r.y=p.y+q.y;
		}
		// cout<<p.s<<" "<<q.s<<endl;
		p.parent=r.v;
		q.parent=r.v;
		a[i]=p;
		a[i+1]=q;
		i++;
		a.push_back(r);
	}
	// f(i,a.size()) cout<<a[i].s<<" ";
	// cout<<endl;
	// f(i,a.size()) cout<<a[i].parent<<" ";
	// cout<<endl;
	f(i, n){
		sign[i]=signage(i, a[i].s);
		cout<<sign[i]<<" ";
	}
	cout<<endl;
	temp.x=0;
	temp.y=0;
	f(i,n){
		temp.x += sign[i]*a[i].x;
		temp.y += sign[i]*a[i].y;
		if(vsum(temp, temp,1)/2>mod) cout<<a[i].v<<endl;
	}
	cout<<temp.x<<" "<<temp.y<<endl;

	return 0;
}