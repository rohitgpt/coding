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

    int n, m;
    cin>>n>>m;
    int cnt=0;
    if(n>m){
        cout<<n-m<<endl;
    }
    else{
        while(m!=n){
            if(m%2==0){
                if(n<=m/2){
                    cnt+=1;
                    m/=2;
                }
                else{
                    cnt+=(n-m/2+1);
                    m=n;
                }
            }
            else{
                if(n<=m/2){
                    cnt+=2;
                    m = (m+1)/2;
                }
                else{
                    cnt+=(2+n-(m+1)/2);
                    m=n;
                }
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}