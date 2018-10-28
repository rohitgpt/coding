#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld; 
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
	int* temp;
	temp=b;
	b=a;
	a=temp;
	return;
}
void insert(int a){
	b.pb(a);
	int s = b.size()-1;
	while(b[s]<b[parent(s)]){
		swap(b[s], b[parent(s)]);
		s=parent(s);
	}
	return;
}

int pop(int i, int flag){
	int ans=b[i];
	if(flag==1){
		swap(b[0], b[b.size()-1]);
		b.resize(b.size()-1);
	}
	int smallest=i;
	int left=lchild(i);
	int right=rchild(i);
	if(left<b.size() && b[smallest]>b[left]) smallest=left;
	if(right<b.size() && b[smallest]>b[right]) smallest=right;
	if(smallest!=i){
		swap(b[smallest], b[i]);
		pop(smallest, 0);
	}
	return ans;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;
	vector<int> a(n);
	f(i, n){
		cin>>a[i];
		insert(a[i]);
	}
	f(i, n)	cout<<pop(0, 1);
	return 0;
}