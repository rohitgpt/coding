#include <iostream>
#include <bits/stdc++.h>
#include <vector>

#define fr(i, n) for(int (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(int (i)=a; (i)<b; (i)++)
#define frn(i, a, b) for(int (i)=a; (i)>b; (i)--)

#define p(a) cout<<"debug "<<a<<endl;
#define PI 3.14159265358979323846

using namespace std;

int main(){
	int n, angle, ans;
	cin>>n>>angle;
	cout << "2 1 " << max(3, min(n, (n*angle+90)/180+2));
	return 0;
}
