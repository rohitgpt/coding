#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	ofstream file;
	file.open("input.txt");
	file<<n<<" 1758 "<<n/2<<endl;
	// file<<n<<" "<<25<<" "<<n/3<<endl;
	for (int i = 1; i <= 1758; ++i)
	{
		file<<i*n/1758<<" ";
		// if((i%(n/4))==0)		file<<i<<" ";
		/* code */
	}
	file<<endl;
	for (int i = 1; i < n+1; ++i)
	{
		file<<i<<" "<<i+1<<endl;
		/* code */
	}

	file.close();
	return 0;
}