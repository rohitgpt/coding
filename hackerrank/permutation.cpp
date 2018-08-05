#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <chrono>
// #include <cmath>
// #include <map>
#include <string>
#include <sstream>
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
const int mx=2e5+100;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp, ans;
	vector<int> q, p;
	string input, t;
	vector<string> ts;

	input="1 -2 3#1 1 1";
	stringstream s( input );

	cout<<input<<endl;
	while(getline(s, t, '#'))
		ts.pb(t);

		// cout<<ts[0]<<endl;

	stringstream qs( ts[0] );
	stringstream ps( ts[1] );

	// f(i, qs.size()) cout<<qs[i]<<endl;

	// vector<int>qp(istream_iterator<int>( is ), istream_iterator<int>() );
	// f(i, qp.size()){
	// 	cout<<qp[i]<<endl;
	// }

	while(qs>>tmp){
		cout<<tmp<<endl;
		q.pb(tmp);
	}
	while(ps>>tmp){
		cout<<tmp<<endl;
		p.pb(tmp);
	}

	sort(q.begin(), q.end());
    sort(p.begin(), p.end());
    
    for(int i=0; i<q.size(); i++){
        ans+=q[i]*p[i];
    }
    
    cout<<ans;

	// cout<<s;
	return 0;
}