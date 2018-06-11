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
	int n, p;
	string a;
	cin>>n>>p;
	cin>>a;
	bool flag=true;
	f(i, n-p){
		if(a[i]!='.' && a[i+p]!='.') if(a[i]==a[i+p]) continue;
		flag=false;
		break;
	}
	if(flag){
		cout<<"NO"<<endl;
		return 0;
	}
	f(i, n){
		if(a[i]=='.'){
			if(flag){ 
				a[i]='0';
				continue;
			}
			else if(a[i+p]!='1')
					a[i]='1';
			else
				a[i]='0';
			flag=true;
		}
	}
	cout<<a<<endl;
	return 0;
}