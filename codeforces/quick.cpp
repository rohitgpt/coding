#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i, n) for(int i=0; i<(n); i++)
vector<int> arr;

void swap(int& a, int& b){
	int c;
	c=a;
	a=b;
	b=c;
	return;
}

int partition(int a, int b){
	int pivot=arr[b];
	int i=a;
	for(int j=a; j<b; j++){
		if(arr[j]<pivot){ swap(arr[j], arr[i]); i++;}
	}
	swap(arr[i], arr[b]);
	return i;
}

void quicksort(int a, int b){
	if(a<b){
		int p = partition(a, b);
		quicksort(a, p-1);
		quicksort(p+1, b);
	}
}

int main(){
	int n;
	cin>>n;
	arr.resize(n);
	f(i, n)	cin>>arr[i];
	quicksort(0, n-1);
	f(i, n) cout<<arr[i]<<" ";
	cout<<endl;
}