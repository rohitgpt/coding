#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <chrono>
// #include <string>
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

struct node
{
	int pwr;
	int prc;
	int cnt;
	double ppp;
};

bool comp_ppp(const node &a, const node &b){
	return a.ppp<b.ppp;
}

bool comp_pwr(const node &a, const node &b){
	return a.pwr<b.pwr;
}

vector<node> a;
inline int bs(int begin, int end, int b){
	int mid = (begin+end)/2;
	if(end-begin<=1) return begin;
	else if(b>a[mid].pwr) return bs(mid, end, b);
	else return bs(begin, mid, b);
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;

	node temp;
	f(i,n){
		cin>>temp.pwr;
		a.pb(temp);
	}
	f(i,n){
		cin>>a[i].prc;
		a[i].cnt=0;
		a[i].ppp=(double)a[i].pwr/(double)a[i].prc;
	}
	sort(a.begin(), a.end(), comp_ppp);
	
	double total_pwr=0.0, total_prc=0.0;
	// int cnt[mx], pair[mx], tmp;
	// memset(cnt,0,sizeof(cnt));
	
	int x = a.size(), y=0;
	vector<node>::iterator it;	
	it = a.begin();
	while(x>1){
		sort(it, it+x/2, comp_pwr);
		it+=x/2;
		frp(i, y, y+x/2){
			if(a[i].cnt!=0) continue;
			a[i].cnt=1;
			total_prc+=a[i].prc;
			total_pwr+=a[i].pwr;
			frn(j, a.size()-1, y+x/2-1){
				if(a[i].pwr>a[j].pwr && a[j].cnt==0){
					a[j].cnt=1;
					break;
				}
			}
		}
		y+=x/2;
		x/=2;		
	}
	// ofstream file;
	// file.open("input1.txt");
	// f(i, a.size()) file<<a[i].pwr<<"\t";
	// file<<endl;
	// f(i, a.size()) file<<a[i].prc<<"\t";
	// file<<endl;
	// // f(i, a.size()) file<<pair[i]<<"\t";
	// // file<<endl;
	// f(i, a.size()) file<<(int)(a[i].ppp*100)<<"\t";
	// file<<endl;
	// file.close();

	cout<<(int)(total_pwr/total_prc*1000)<<endl;
	return 0;
}