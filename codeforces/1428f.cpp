//NOT WORKING
#include <vector>
#include <iostream>
// #include <algorithm>
#include <string>
#include <map>
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

    string a;
    int n;
    cin>>n;
    cin>>a;
    map<int, vector<int> > pos;

    ll ans=0, cnt=0;
    int l=0,len=0;
    f(i, n){
        if(a[i]=='1'){
            len+=1;
            if(l==0)
                l=i;
        }
        else{
            if(l!=0){
                if(pos[len][0]){
                    pos[len].push_back(l);
                }
                else
                    pos[len] =  vector<int> (0);
            }
            l=0;
            len=0;
        }
    }

    map<int, vector<int> >::iterator it;

    for(it=pos.begin(); it!=pos.end(); it++){
        f(i, *it.length()){
            cout<<*it[i]<<endl;
        }
    }
    // f(i, n){
    //     for(int j=i; j<n; j++){
    //         lp = lp(i);
    //         rp = rp(j);
    //         max = max()
    //     }
    // }

    //     cnt+=(n-i)*(i+1);
    //     if (a[i]=='0')
    //         ans+=(n-i)*(i+1);
    // }
    // cout<<cnt-ans<<endl;
    return 0;
}