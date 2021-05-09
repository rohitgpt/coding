#include <vector>
#include <iostream>
#include <iomanip>      // std::setprecision
#include <cmath>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a)
#define debug  cout<<"hello"<<endl
#define N 1e5+777

vector<int> dn(10);

vector<int> cdn(int a){
    vector<int> tdn(10,0);
    while(a){
        tdn[a%10]+=1;
        a/=10;
    }
    return tdn;
}

bool comparecdn(int n, int i){
    vector<int> idn = cdn(i);
    int sum=0;
    f(i, 10){
        
        sum+=dn[i] && idn[i];
    }
    if(sum>0) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin>>n;
    dn = cdn(n);
    vector<int> d;
    int cnt=0;
    // vector<int> skip(n, 0);

    int x = ceil(sqrt(n));
    d.push_back(1);
    for(int i=2; i<=x && i<n; i++){
        if(n%i==0){
            // cout<<i<<endl;
            d.push_back(i);
            if(i!=x)
                d.push_back(n/i);
        }
    }
    // f(i, d.size()) cout<<d[i]<<endl;

    f(i, d.size()){
        if(comparecdn(n, d[i])) cnt+=1;
    }
    if(n>1) cnt+=1;
    cout<<cnt<<endl;

    return 0;
}