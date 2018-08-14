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
bool comp(int a, int b){
	if(a>b) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t1, t2, thomas_score;
	vector<int> score;
	cin>>n;
	f(i, n+1){
		t2=0;
		f(j,3){
			cin>>t1;
			t2+=t1;
		}
		if(i==0) thomas_score=t2;
		score.pb(t2);
	}
	sort(score.begin(), score.end(), comp);

	int first, mid, last;
	first = 0;
	last = score.size();
	while(first<last-1){
		mid = (first+last)/2;
		if(score[mid]<=thomas_score)
			last = mid;
		else
			first = mid;
	}

	cout<<first + 1<<endl;
	return 0;
}