#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;

#define f(i, n) for(int (i)=0; (i)<(n); (i)++)


int main(){
    int t;
    cin>>t;
    f(i, t){
        int A, B, n;
        cin>>A>>B>>n;
        vector<int> a(n), b(n);
        f(j, n) cin>>a[j];
        f(j, n) cin>>b[j];
        int flag=0;
        f(j, n){
            ll nah = b[j]/A+(b[j]%A!=0), nam=B/a[j]+(B%a[j]!=0);
            // cout<<nah<<" "<<nam<<endl;
            if (nah>nam && b[j]-A>0){
                // cout<<b[j]<<" "<<A<<" "<<B<<" "<<a[j]<<endl;
                cout<<"NO"<<endl;
                flag=1;
                B-=nam*a[j];
                break;
            }
            B -= nah*a[j];
            
        }
        if (flag==0) cout<<"YES"<<endl;
    }
    return 0;
}