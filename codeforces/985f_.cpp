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
const int MX = 2e5+100;
int n, m;

char s[MX];
int x[MX], y[MX], len[MX];
int ha[27][MX], a[27], b[27];


void init(){
	//for every char i
	f(i, 26){
		char sgn = i+'a';
		int key = 0;
		//for all char in string
		f(j, n){
			//multiply key by 2
			key=(key<<1)%mod;
			if(s[j]==sgn) key += 1;
			ha[i][j+1]=key;
		}
	}
}

inline int gethash(int c, int l, int r){
	int res = ha[c][r];
	if(l>1) res -= (ha[c][l-1]<<(r-l+1));
	res%=mod;res+=mod;res%=mod;
	return res;
}

int main(){
	cin>>n>>m;
	cin>>s;
	f(i, m){
		cin>>x[i]>>y[i]>>len[i];
		// x[i]--; y[i]--;
	}
	init();
	f(i,m){
		bool flag = true;
		f(j, 26){
			a[j]=gethash(j, x[i],x[i]+len[i]-1);
			b[j]=gethash(j, y[i],y[i]+len[i]-1);
		}
		sort(a,a+26);
		sort(b,b+26);
		f(j, 26){
			if(a[j]!=b[j]) flag=false;
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
// static_cast<char>