#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i, n) for(int i=0; i<(n); i++)
#define fi(i, a, b) for(int i=(a); i<(b); i++)

int main(){
	int n, t=0;
	cin>>n;
	vector<int> a(n); 
	vector<bool> b(n, 0);
	f(i, n)		cin>>a[i];
	sort(a.begin(), a.end());
	f(j, n){
		if(b[j]==1) continue;
		t++;;
		fi(i, j+1, n){
			if(b[i]==1)	continue;
			if(a[i]%a[j]==0) b[i]=1;
		}
	}
	cout<<t;

	return 0;
}