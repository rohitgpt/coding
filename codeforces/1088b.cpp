#include <bits/stdc++.h>
using namespace std;

#define f(i, n) for(int (i)=0; (i)<(n); (i)++)

typedef long long ll;


int main(){
	int n, k;
	cin>>n>>k;
	vector<int>a(n);
	f(i, n){
		cin>>a[i];
	}
	int sum=0;
	sort(a.begin(), a.end());
	int j=0;
	f(i, k){
		while(a[j]<=sum && j<n) j++;
		// cout<<j<<endl;
		if(j==n) cout<<0<<endl;
		else{
			// cout<<a[j]<<endl;
			cout<<a[j]-sum<<endl;
			sum+=a[j++]-sum;
			// if(j>n) j=n;
		}

	}
	return 0;
}