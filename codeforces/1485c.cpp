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
    int x, y, ans=0;
    cin>>t;
    f(i, t){
        cin>>x>>y;
        ans=0;
        for(int j=2; j<=y && x>=j; j++){
            ans+=min(x/(j+1), j-1);
        }
        cout<<ans<<endl;
    }


    return 0;
}