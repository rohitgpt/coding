#include <vector>
#include <iostream>
#include <stdio.h>
// #include <algorithm>
// #include <string>
// #include <map>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a)
#define debug  cout<<"hello"<<endl
#define N 1e6+2007

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,q, t,k, d;
    cin>>n;
    cin>>q;
    vector<int> s(n+1, 0), c(N, n);
    int sum=0, cnt=0;
    f(i, q){
        cin>>t>>k>>d;
        sum=0;
        if(c[t]>=k){
            for(int j=t; j<t+d; j++) c[j]-=k;
            cnt=0;
            f(j, n){
                if (cnt<k && s[j]<t){
                    s[j]=t+d-1;
                    sum+=j+1;
                    cnt+=1;
                }
            }
        }
        if(sum==0) sum=-1;
        cout<<sum<<endl;
    }
    return 0;
}