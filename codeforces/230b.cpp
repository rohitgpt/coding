#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a)
#define debug  cout<<"hello"<<endl
#define N 1e5+777

bool isprime(ll a){

    for(int j=2; j<=sqrt(a); j++){
        if(a%j==0) return false;
    }
    return true;
}
bool divisor(ll a){
    if(a<2) return false;
    int i = sqrt(a);
    if(a%i==0 && a/i==i)
        if(isprime(i))
            return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin>>n;
    ll a;
    bool d;
    f(i, n){
        cin>>a;
        d = divisor(a);
        if(d) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}