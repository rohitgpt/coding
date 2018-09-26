#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// using namespace std::chrono;

// typedef std::chrono::high_resolution_clock::time_point timen;
typedef long long ll;
typedef long double ld;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()
#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(ll (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(ll (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

const int mod=1e9+7;
const ll mx=1e3;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	string a, b;
	vector<int> cmp1(mx, 0), cmp2(mx, 0),uniq;
	cin>>t;
	f(i, t){
		cin>>a;
		cin>>b;
		auto it = unique(a.begin(), a.end());
		a.resize(distance(a.begin(), it));
		it = unique(b.begin(), b.end());
		b.resize(distance(b.begin(), it));
		f(j, a.size()){
			cmp1[a[j]]=1;
		}
		f(j, b.size()){
			cmp2[b[j]]=1;
		}
		f(j, cmp1.size()){
			if(cmp1[j]!=cmp2[j]){
				uniq.pb(j);
			}
		}
		sort(uniq.begin(), uniq.end());
		f(j, uniq.size()){
			cout<<(char)uniq[j];
		}
		vector<int>(mx,0).swap(cmp1);
		vector<int>(mx,0).swap(cmp2);
		vector<int>().swap(uniq);
		cout<<endl;
	}
	return 0;
}