#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)

int main(){
	int n, k;
	cin>>n>>k;
	vector<int> a;
	int cnt=0;
	while(n){
		if(n&1) a.push_back(pow(2, cnt-1+(n&1)));
		n>>=1;
		cnt+=1;
	}
	int i=0;
	while(a.size()<k){
		if(a[i]>1){
			a.push_back(a[i]/2);
			a.push_back(a[i]/2);
			a.erase(a.begin()+i);
		}
		i++;
	}
	f(j, a.size()) cout<<a[j]<<" ";
	return 0;
}