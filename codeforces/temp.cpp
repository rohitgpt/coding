#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main(){
	int n;
	int g[100];
	// memset(g, 1, sizeof(g));
	cout<<*g<<endl;
	g[*g=n=1]=1;
	cout<<"gn12"<<endl;
	cout<<*g<<n<<g[1]<<g[2]<<endl;
	g[++*g]=4;
	cout<<*g<<n<<g[1]<<g[2]<<endl;
	return 0;
}