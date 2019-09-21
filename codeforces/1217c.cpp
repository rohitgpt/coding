#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i, n) for(int i=0; i<(n); i++)
#define fi(i, a, b) for(int i=(a); i<(b); i++)
#define pb push_back

int main(){
	int t;
	int countone=0;
	string a;
	cin>>t;
	f(i, t){
		vector<int> b;
		countone = 0;
		cin>>a;
		f(j, a.size()){
			if(a[j]=='1'){
				countone++;
				if(a[j+1]=='0') b.pb(j);
			}
		}
		f(j, b.size()) cout<<b[j]<<" ";
		cout<<countone;
		cout<<endl;

	}
	return 0;
}