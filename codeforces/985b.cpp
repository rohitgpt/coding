#include <iostream>
#include <bits/stdc++.h>
#include <vector>


#define fr(i, n) for(int (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(int (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(int (i)=a; (i)>(b); (i)--)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

using namespace std;
// int i, j;
int main(){
	// printf("Hello\n");
	char ac[2001][2001];
	int b[2001], c[2001], n, m;
	memset(b, 0, 2000);
	memset(c, 0, 2000);
	cin>>n>>m;
	fr(i, n){
		fr(j, m){
			cin>>ac[i][j];
			b[j] += (ac[i][j] - 48);
		}
	}
	int flag = 0;
	int jcnt=0;	
	fr(i, n){
		fr(j, m){
			c[j] = b[j] - (ac[i][j] - 48);
			if(!c[j]) break;
			jcnt += 1;
		}
		// printf("%d\n", jcnt);
		if(jcnt==m) flag = 1;
		if (flag){
			printf("YES\n");
			return 0;
		}
		// fr(j, m){
		// 	b[j] += (ac[i][j] - 48);
		// }
		jcnt=0;
	}
	printf("NO\n");
	return 0;
}
