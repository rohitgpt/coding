#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;


#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a);

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


    ll a, out=0, t=1;
    cin>>a;
    vector<int> b;
    while(a){
        b.pb(a%10);
        a/=10;
    }
    vector<int>::iterator it =  b.begin();
    for (; it!=b.end(); ++it){
        if (it==b.end()-1 && *it==9) out+=*it*t;
        else if(*it>4) out+=(9-*it)*t;
        else
        out+=*it*t;
        t*=10;
    }
    cout<<out;
    return 0;
}