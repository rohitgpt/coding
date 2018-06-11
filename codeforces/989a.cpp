#include <iostream>
#include <bits/stdc++.h>
// #include <vector>
#include <string>
// #include <algorithm>

typedef long long ll;
typedef long double ld;

#define f(i, n) for(int (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(int (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(int (i)=a; (i)>(b); (i)--)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

using namespace std;

const int mod = 1e9+7;
const int mx = 3e5+100;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a;
	cin>>a;
	// cout<<a.find("BAC")<<endl;
	if(a.find("ABC")<101 || a.find("BAC")<101 || a.find("CAB")<101 || a.find("ACB")<101 || a.find("BCA")<101 || a.find("CBA")<101) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
	// f(i, a.size()-2){
	// 	if(!i) continue;
	// 	if(a[i]!=)
	// }
}
