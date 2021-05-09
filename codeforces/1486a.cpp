#include <vector>
#include <iostream>
// #include <algorithm>
// #include <string>
// #include <map>
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
    cin>>t;
    int n, temp, flag;
    ll sum;
    f(i, t){
        cin>>n;
        sum = 0;
        flag=1;
        f(j, n){
            cin>>temp;
            sum+=temp-j;
            // sum-=j;
            if(sum<0){
                cout<<"NO"<<endl;
                flag=0;
                break;
            }
        }
        if (flag==1) cout<<"YES"<<endl;
    }
    return 0;
}