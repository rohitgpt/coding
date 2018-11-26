#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i, n) for(int i=0; i<(n); i++)

struct node{
	int v;
	struct node* next;
};

void swap(int *a, int *b){
	int c=*a;
	*a=*b;
	*b=c;
	return;
}

struct node* partition(struct node **head, struct node **tail){
	int pivot = (*tail)->v;
	struct node *i, *cur=new node;
	i->v=0;
	i->next=(*head);
	cur=(*tail);
	for(struct node *j=i; j->next!=(*tail); j=j->next){
		if(j->next->v<pivot){
			cur=i;
			swap(&(j->next->v), &(i->next->v));
			// struct node *t=j->next;
			// t->next=i->next->next;
			// j->next=i->next;
			// i->next->next=j->next->next;
			// i->next=t;
			i=i->next;
		}
	}
	struct node *j=(*tail);
	struct node *t=j->next;
	swap(&(j->next->v), &(i->next->v));

	// t->next=i->next->next;
	// j->next=i->next;
	// i->next->next=j->next->next;
	// i->next=t;

	// int c=i->v;
	// i->v=(*tail)->v;
	// (*tail)->v=c;
	return cur;
}

void quicksort(struct node **head, struct node **tail){
	cout<<"hello"<<endl;
	// if()
	struct node *cur=(*head);
	while(cur->next!=NULL){
		if(cur==(*tail)){
		struct node *p = partition(head, tail);
		cout<<p->v<<endl;
		quicksort(head, &p);
		quicksort(&(p->next->next), tail);
		}
		cur=cur->next;
	}
}


int main(){
	int n,t;
	cin>>n;
	struct node* first = new node;
	cin>>t;
	first->v=t;
	first->next=NULL;
	struct node* cur = first; 
	f(i, n-1){
		cin>>t;
		struct node* nw = new node;
		nw->v=t;
		nw->next=NULL;
		cur->next = nw;
		cur=nw;
	}
	quicksort(&first, &cur);
	cur=first;
	while(cur){
		cout<<cur->v;
		cur = cur->next;
	}
	return 0;
}