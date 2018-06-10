#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>

typedef long long ll;
typedef long double ld;

#define fr(n) for(int (i)=0; (i)<(n); (i)++)
#define Fr(i, n) for(int i=0; i<n; i++)
#define frp(a, b) for(int (i)=a; (i)<(b); (i)++)
#define frn(a, b) for(int (i)=a; (i)>(b); (i)--)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

using namespace std;

int main(){
	int n, m;
	string s, a, b;
	int x[200001], y[200001], len[200001], an, bn, flag=0;
	char at[200001], bt[200001];
	memset(at, 0, 200001);
	memset(bt, 0, 200001);
	cin>>n>>m;
	cin>>s;
	fr(m) cin>>x[i]>>y[i]>>len[i];
	fr(m){
		an=0;
		bn=0;
		a = s.substr(x[i]-1, len[i]);
		b = s.substr(y[i]-1, len[i]);
		Fr(j,len[i]){
			flag = 0;
			Fr(k, an){
				if(a[j]==at[k]){
					a[j] = k+48;
					flag = 1;
				}
			}
			if(flag==0){
				at[an++] = a[j];
				a[j] = an-1+48;
			}
		}
		Fr(j,len[i]){
			flag = 0;
			Fr(k, bn){
				if(b[j]==bt[k]){
					b[j] = k+48;
					flag = 1;
				}
			}
			if(flag==0){
				bt[bn++] = b[j];
				b[j] = bn-1+48;
			}
		}
		if (a.compare(b)!= 0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
// static_cast<char>