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
	file<<n<<endl;
	for (int i = 0; i < n; ++i)
	{
		file<<i+1<<" ";
	}
	file.close();
	return 0;
}