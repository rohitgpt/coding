#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i, n) for(int i=0; i<(n); i++)

struct node{
	int v;
	struct node* next;
}

int main(){
	int n;
	cin>>n;
	struct node* first = new node;
	cin>>t;
	first->v=t;
	first->next=NULL;
	struct node* cur = first; 
	f(i, n){
		cin>>t;
		struct node* nw=new node;
		nw->v=t;
		nw->next=NULL;
		cur->next=nw;
	}
	cur=first;
	while(cur->next!=NULL){
		cout<<cur->v;
		cur=cur->next;
	}
	return 0;
}