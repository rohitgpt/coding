#include <vector>
#include <iostream>
// #include <algorithm>
// #include <cmath>
#include <string>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a)
#define debug  cout<<"hello"<<endl
#define N 10^5+7

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin>>n;
    f(i, n){
        string a;
        cin>>a;
        vector<int> b(a.length(), 0);
        int rj;
        f(j, a.length()){
            rj = a.length()-j-1;
            if (a[j]=='A'){
                if (j>0 && b[j-1]>0){
                    b[j]=b[j-1]+1;
                }
                else
                    b[j]=1;
            }
            if (a[rj]=='B'){
                if(rj<a.length()-1 && b[rj+1]<0){
                    b[rj] = b[rj+1] - 1;
                }
                else 
                    b[rj]=-1;
            }
        }
        int bsum=0, ans=0, t=0;
        f(j, a.length()){
            rj = a.length()-j-1;
            if(b[rj]<0 && b[rj-1]>0){
                bsum+=b[rj];
                t = int((b[rj-1]>-1*bsum)?-1*bsum:b[rj-1]);
                j+=t+1;
                bsum+=t;
                ans=ans+2*t;
            }
        }
        if (b[0]<0)
            bsum+=b[0];
        if(bsum%2==0)
            ans=ans-bsum;
        else 
            ans=ans+(-1-bsum);
        cout<<int(a.length())-int(ans)<<endl;
    }
    return 0;
}