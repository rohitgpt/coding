#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i,n) for(int (i)=0; (i)<(n); (i)++)

int main(){
	int n, k;
	cin>>n>>k;
	int ans=((2*n+k-1)/k+(5*n+k-1)/k+(8*n+k-1)/k);
	cout<<ans<<endl;
	return 0;
}