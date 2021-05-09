#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define debug  cout<<"hello"<<endl
#define N 1e5+7
#define S(n) 2*(n)-1

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t;
    cin>>t;
    ll a, sum, b, x;

    f(i, t){
        cin>>a;
        sum=0;
        b=1;
        while(a/b){
            x = a&b;
            if(x>0)
                sum+=S(a&b);
            b*=2;
        }
        cout<<sum<<endl;
    }
    return 0;
}