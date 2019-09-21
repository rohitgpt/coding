#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i, n) for(int i=0; i<(n); i++)
#define fi(i, a, b) for(int i=(a); i<(b); i++)
#define pb push_back

int main(){
	int n, t,k, ans;
	cin>>t;
	string a, b;
	f(i, t){
		cin>>n;
		vector<int> c(n, 0);
		cin>>a;
		b=a;
		sort(a.begin(), a.end());
		ans=0;
		if(a.begin()!=b.begin()) ans=2;
		k=0;
		f(j, a.size()){
			if(a[k]==b[j]){
				k++;
				c[j] = ans%2+1;
			}
		}
		f(j, a.size()){
			if(c[j]==ans%2+1);
			else if(a[k]==b[j]){
				k++;
				c[j]=ans%2+2; 
			}
			if(c[j]==0) ans=-1;
		}
		if(ans==-1) cout<<"-1";
		else{
			f(i, n) cout<<c[i];
		}
		cout<<endl;
	}

	return 0;
}