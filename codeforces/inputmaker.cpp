#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	ofstream file;
	file.open("input.txt");
	file<<2<<endl;
	for (int i = 0; i < n/2-1; ++i)
	{
		file<<"(";
		/* code */
	}
	file<<endl;
	for (int i = 0; i < n/2-1; ++i)
	{
		file<<"(";
		/* code */
	}

	file.close();
	return 0;
}