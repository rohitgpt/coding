#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>

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
	int n;
	int indices[mx];
	char a[mx];
	cin>>n;
	indices[0] = 0;
	f(i, n){
		char* tmp = &a[indices[i]];
		cin>>tmp;
		indices[i+1] = indices[i]+strlen(tmp);
	}
	f(i, n)cout<<a[indices[i]]<<" "<<indices[i]<<endl;
	// f(i, n) cin>>a[i];
	// p(a[0]);
	return 0;
}
