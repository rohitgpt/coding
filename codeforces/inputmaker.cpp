#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;

int main(){
	int n;
	cin>>n;
	ofstream file;
	file.open("input.txt");
	long long temp=2;
	int i=0;
	for(i=0; temp<mod; i++) temp*=2;
	file<<i<<endl;

	// file<<n<<" "<<n/2<<endl;
	// for (int i = 0; i < n; ++i)
	// {
	// 	file<<1000000000<<" ";
	// }
	file.close();
	return 0;
}