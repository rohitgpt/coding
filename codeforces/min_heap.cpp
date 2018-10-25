#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
tyepdef long double ld; 
#define all(c) (c).begin(), (c).end();
#define tr(c, it) for(__typeof__((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define f(i, a) for(ll (i)=0; (i)<(a); (i)++)
#define pb push_back

const ll mx=1e9;
const ll mod=1e9+7;

vector<int> b;
int parent(int i){ return (i-1)/2;}
int lchild(int i){ return 2*i+1;}
int rchild(int i){ return 2*i+2;}

void swap(int* a, int* b){
	int temp;
	temp=b;
	b=a;
	a=temp;
	return;
}
void insert(int a){
	b.pb(a);
	s = b.size()-1;
	while(b[s]>b[parent(b)]){

	}
}

void heapify(const vector<int>& a){
	for()
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;
	vector<int> a(n);
	f(i, n)		cin>>a[i];
	
	heapify(a);
	f(i, n) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}