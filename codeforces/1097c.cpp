#include <bits/stdc++.h>

#define f(i, n) for(int i=0; i<(n); i++)
#define fi(i, a, b) for(int i=(a); i<(b); i++)
#define mx 15;
using namespace std;

int main(){
	int n, ans=0;
	vector<string> s;
	cin>>n;
	s.resize(n);
	f(i, n) cin>>s[i];
	vector<int> sum(n, 0), a(n,-1), b(n,1);
	f(i, n){
		int temp=s[i].size();
		f(j, temp){
			if(s[i][j]=='(') sum[i]++;
			else sum[i]--;
		}
		if(s[i][0]=='(' && sum[i]>=0) a[i]=sum[i];
		if(s[i][s[i].size()-1]==')') b[i]=sum[i];
	}
	f(i, n){
		fi(j, i+1, n){
			if(i==j || !(a[i]>-1 && b[j]<1)) continue;
			if(a[i]+b[j]==0) ans++;
		}
	}
	int ans1=0;
	f(j, n){
		fi(i, j+1, n){
			if(i==j || !(a[i]>-1 && b[j]<1)) continue;
			if(a[i]+b[j]==0) ans1++;
		}
	}
	
	cout<<max(ans1,ans)<<endl;
	return 0;
}