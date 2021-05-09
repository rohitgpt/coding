#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a)
#define debug  cout<<"hello"<<endl
#define N 1e5+777

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin>>n;
    int cnt=1, t;
    vector<int> y;
    f(i, n){
        cin>>t;
        if(cnt==t){
            cnt+=1;
            y.push_back(2001+i);
        }
    }
    if(y.empty()) cout<<0<<endl;
    else{
        cout<<y.size()<<endl;
        f(i, y.size()) cout<<y[i]<<" ";
        cout<<endl;
    }
    return 0;
}