//NOT WORKING
#include <vector>
#include <iostream>
// #include <algorithm>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a)
#define debug  cout<<"hello"<<endl
#define N 10^5+777

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t;
    int a, b;
    ll cnt=0;
    cin>>t;
    f(i, t){
        cnt=0;
        cin>>a>>b;
        while (log(a)*(1/log(b)-1/log(b+1))>1 || b==1){
            cnt+=1;
            b+=1;
        }
        // cout<<b<<" ";
        while(a!=0){
            cnt+=1;
            a/=b;
        }
        cout<<cnt<<endl;
    }
    return 0;
}