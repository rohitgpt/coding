#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	ofstream file;
	file.open("input.txt");
	file<<n<<" "<<n/2<<endl;
	for (int i = 0; i < n; ++i)
	{
		file<<1000000000<<" ";
	}
	file.close();
	return 0;
}