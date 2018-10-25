#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(ll (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(ll (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

const ll mx=1e9+10;
const int N=100;
const int M=10;
vector<int> capList[N+1];
int dp[1<<M+1][N+1], allmask;
ll countWays(int mask, int i){
	if(mask==allmask) return 1;

	if(i>100) return 0;
	if(dp[mask][i]!=-1)return dp[mask][i];

	ll ways = countWays(mask, i+1);
	int size=capList[i].size();
	f(j, size){
		if(mask&(1<<capList[i][j])) continue;
		else ways+=countWays(mask|(1<<capList[i][j]), i+1);
		ways%=MOD;
	}
	return dp[mask][i]=ways;
}

int main(){
	IOS;

	int n, x, t;
	string str;
	cin>>n;
	getline(cin, str);
	f(i, n){
		getline(cin, str);
		stringstream ss(str);
		while(ss>>x){
			// cout<<x<<endl;
			capList[(int)x].push_back(i);
		}
	}
	allmask = (1<<n)-1;
	memset(dp, -1, sizeof(dp));
	cout<<countWays(0, 1)<<endl;
	return 0;
}
