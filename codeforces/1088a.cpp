#include <bits/stdc++.h>
using namespace std;

#define f(i, n) for(int (i)=1; (i)<=(n); (i)++)

typedef long long ll;


int main(){
	int n, t;
	cin>>n;
	f(i, n){
		f(j, n){
			if(i%j==0 && i*j > n && ((double)i/j) < n){
			cout<<i<<" "<<j<<endl;
			return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}