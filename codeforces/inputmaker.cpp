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
		file<<"()"<<endl;
		/* code */
	}
	file.close();
	return 0;
}