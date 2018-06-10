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
const int MX = 1e6+100;
int main(){
	int n, K, ans=0;
	int a[MX];
	int b[MX];
	memset(b, 0, MX);
	cin>>n>>K;
	f(i, n){
		cin>>a[i];
	}
	sort(a, a+n);
	f(i, n-1){
		int flag = 0;
		int j = i;
		while(a[j]==a[j+1]) j++;				
		if(a[j+1] - a[j]<=K && a[j+1]>a[j])	frp(k,i,j+1){b[k]=1;}
		i = j;
	}
	f(i, n)	if(!b[i])	ans+=1;
	cout<<ans<<endl;
	return 0;
}