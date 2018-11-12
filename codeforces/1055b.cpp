#include<bits/stdc++.h>
using namespace std;

#define f(i,n) for(int (i)=0; (i)<(n); (i)++)

int main(){
	int n, m, l;
	int flag=0;
	cin>>n>>m>>l;
	int q, p, t;
	vector<int> a(n);
	int ans=0;
	f(i, n){
		cin>>a[i];
		if(a[i]>l && flag==0){flag=1; ans+=1;}
		else if(a[i]<=l) flag=0;
	}		

	f(i, m){
		cin>>q;
		if(q==0){
			cout<<ans<<endl;
		}
		else if(q==1){
			flag=0;
			cin>>p>>t;
			if(a[p-1]>l) continue;
			a[p-1]+=t;
			if(a[p-1]>l){
				if(p>1 && p<n){
					if(a[p-2]>l && a[p]>l) ans-=1;
					else if(a[p-2]<=l && a[p]<=l){ans+=1;}
				}
				else{
					if(p==1 && a[p]<=l) ans+=1;
					else if(p==n && a[p-2]<=l) ans+=1;
				}
			}
		}
	}
	return 0;
}