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
const int mx=1e3;

struct seg
{
	int a;
	int b;
	int n;
} tmp;

vector<seg> linseg;

bool comp(struct seg one, struct seg two){
	return one.n<two.n;
}

seg intersection(seg one, seg two){
	seg ans;
	ans.a = -1; ans.b = -1; ans.n=0;
	if(one.a<two.a){
		if(two.a<=one.b){
			ans.a = two.a;
			if(two.b<=one.b){ 
				ans.b = two.b;
				ans.n = two.n;
			}
			else{ 
				ans.b = one.b;
				ans.n = one.b-two.a;
			}
			return ans;
		} 
		return ans;
	}
	if(one.a<=two.b){
		ans.a = one.a;
		if(one.b<=two.b){ 
			ans.b = one.b;
			ans.n = one.n;
		}
		else{
			ans.b = two.b;
			ans.n = two.b-one.a;
		}
		return ans;
	}
	return ans;
}

int findint(int x){
	seg one;
	if(x!=0)	one = linseg[0];
	else one = linseg[1];
	frp(j, 1, linseg.size()){
		if(j==x) continue;
		// cout<<j<<" ";
		one = intersection(one, linseg[j]);
		// cout<<one.a<<" "<<one.b<<endl;
		if(one.a<0) return 0;
	}

	// cout<<x<<" "<<one.a<<" "<<one.b<<" ";
	return one.n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ta, tb, tn=0;
	cin>>n;
	f(i, n){
		cin>>ta>>tb;
		tmp.a = ta;
		tmp.b = tb;
		tmp.n = tb-ta;
		linseg.pb(tmp);
	}
	sort(linseg.begin(), linseg.end(), comp);
	// f(i, linseg.size()){
	// 	cout<<linseg[i].a<<" "<<linseg[i].b<<" "<<linseg[i].n<<endl;
	// }
	// tn = intersection(linseg[0], linseg[1]).n;
	// cout<<tn<<endl;

	// cout<<linseg[0].n<<endl;

	f(i, linseg.size()){
		int max_seg = findint(i);
		if(tn<max_seg) tn=max_seg;
		// cout<<tn<<endl;
	}
	cout<<tn;
	return 0;
}