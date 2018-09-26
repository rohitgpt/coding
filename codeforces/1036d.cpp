#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll mx=1e3+10;
#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(ll (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(ll (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

vector<ll>a, b;
int p, q, m, n, flag=0;
void makemequal(ll a1, ll b1){
	if(a1==b1){
		p+=1; q+=1;
		return;
	}
	else if(a1<b1){
		if(p+1>m){ flag=1; return;}
		a1+=a[++p];
		makemequal(a1, b1);
	}
	else{
		if(q+1>n){flag=1; return;}
		b1+=b[++q];
		makemequal(a1, b1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int acount=0, bcount=0;
	ll tmp, tmp_sum;
	cin>>m;
	f(i, m){
		cin>>tmp;
		a.pb(tmp);
	}
	cin>>n;
	f(i, n){
		cin>>tmp;
		b.pb(tmp);
	}
	for(p=0, q=0; p<m && q<n;){
		acount+=1;
		bcount+=1;
		if(a[p]==b[q]){
			p++;
			q++;
		}
		else	makemequal(a[p], b[q]);
		if(flag==1){
			cout<<-1<<endl; 
			return 0;
		}
	}
	if(p!=m || q!=n) cout<<-1<<endl;
	else if(acount==bcount) cout<<(int)acount<<endl;
	return 0;
}