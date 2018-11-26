#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i, n) for(int (i)=0; (i)<(n); (i)++)

vector<int> x;

// void swap(int *a, int *b){
// 	int c=*a;
// 	*a=*b;
// 	*b=c;
// 	return;
// }

void bitonicMerge(int a, int b, int dir){
	// cout<<a<<" "<<b<<endl;
	if(a==b){
		// cout<<x[a]<<endl; 
		return;
	}
	int t = (b-a+1)/2;
	int c = (a+b)/2;
	// cout<<t<<endl;
	f(i, t)	if((x[a+i]>x[c+i])==dir) swap(x[a+i],x[c+i]);
	// bitonicMerge(a, c, dir);
	// bitonicMerge(c+1, b, dir);
}

void bitonicSort(int a, int b, int dir){
	if(a==b) return;
	int c=(a+b)/2;
	// cout<<c<<endl;
	bitonicSort(a,c, 0);
	bitonicSort(c+1, b, 0);
	bitonicMerge(a,b, dir);
	// cout<<endl;
	return;
}

int main(){
	int n, t;
	cin>>n;
	x.resize(n);
	f(i, n){
		cin>>x[i];
	}
	bitonicSort(0, n, 0);
	f(i, n) cout<<x[i]<<endl;
}