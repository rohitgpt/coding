#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <chrono>
#include <string>
#include <algorithm>

using namespace std;
// using namespace std::chrono;

// typedef std::chrono::high_resolution_clock::time_point timen;
typedef long long ll;
typedef long double ld;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()
#define f(i, n) for(int (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(int (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(int (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

const int mod=1e9+7;
const int mx=2e5+1000;

string a[300], b[300],c;

bool reql(int a1, int a2, int len){
	string t1, t2;
	f(i, len){
		t1+=a[a1+i];
		t2+=a[a2+i];
		if(t1.compare(t2)!=0) return false;
	}
	return true;
}

int retlen(int a1, int l){
	int ans=0;
	f(i, l){
		ans+=a[i+a1].size();
		ans+=1;
	}
	return ans-1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, maxlen=0, len, tmplen, count=0, cor=0, now=0;
	vector<int> maxin(300), tmp(300);
	char ab[300];

	cin>>n;
	f(i, n){
		cin>>a[i];
		ab[i]=a[i][0]-32;
		c+=a[i];
		c+=" ";
	}

	c.erase(c.size()-1);

	frn(i, (n-1)/2,-1){
		frp(j, 0, n-2*i){
			count=0;
			len=0;
			tmplen=0;
			tmp[count]=j;
			frp(k, j+i+1, n-i){
				// cout<<"Comparing "<<j+1<<" "<<j+1+i<<" with "<<k+1<<" "<<k+1+i<<endl;
				if(reql(j, k, i+1)){
					len=retlen(j, i+1);
					count++;
					// if(count>=3 && len>10) cout<<j+1<<" "<<j+1+i<<" and "<<k+1<<" "<<k+1+i<<" are equal"<<endl;
					tmp[count]=k;
					k+=i+1;
				}
			}
			tmplen=len*(count+1);
			if(maxlen<tmplen){
				// cout<<j+1<<" "<<j+1+i<<" "<<count<<" are equal"<<endl;
				maxlen=tmplen;
				cor=count+1;
				maxin=tmp;				
				now=i+1;
			}
		}
	}

	count=c.size()-maxlen+(cor)*now;
	cout<<count<<endl;
	return 0;
}