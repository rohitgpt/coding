#include <bits/stdc++.h>

using namespace std;
int main(){
	int t=0, n=0;
	long pak=1, pbt=0,days=0;
	long a[100009];
	memset(a, 0, sizeof(a));
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>n;
		for(int j=0; j<n; j++)cin>>a[j]; 
		pbt=a[0];
		while(pak<n){
			days+=1;
			pak+=pbt;
			for(int k=pak-pbt; k<pak && k<n; k++)pbt+=a[k]; 
		}
		cout<<days<<endl;
		days=0;
		pak=1;
	}
	return 0;
}