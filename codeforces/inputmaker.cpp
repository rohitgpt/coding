#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	ofstream file;
	file.open("input.txt");
	file<<n<<endl;
	for (int i = 0; i < n; ++i)
	{
		long long a=rand();
		long long b=rand();
		if(a>b) file<<b<<" "<<a<<endl;
		else file<<a<<" "<<b<<endl;
	}
	file.close();
	return 0;
}