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

long maxCandies(vector<long> bags, long candiesLimit) {
    long candies=0, lastbag=2*candiesLimit;
    sort(bags.begin(), bags.end());
    int mid=(bags.size()+1)/2;
    while(bags[mid-1]<=candiesLimit-candies){
        // cout<<mid<<" "<<bags[mid]<<endl;
        if(bags[mid]<=candiesLimit-candies){
            candies+=bags[mid];
            bags.erase(bags.begin()+mid);
        }
        else{
            candies+=bags[mid-1];
            bags.erase(bags.begin()+mid-1);
        }
        mid=(bags.size()+1)/2;
    }
    
    return candies;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long tmp, cl;
	vector<long> a;

	cin>>n;
	f(i, n){
		cin>>tmp;
		a.pb(tmp);
	}
	cin>>cl;

	sort(a.begin(), a.end());

	cout<<maxCandies(a, cl)<<endl;
	return 0;
}