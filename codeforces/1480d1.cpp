#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;

#define f(i, n) for(int (i)=0; (i)<(n); (i)++)


int main(){
    int t;
    cin>>t;
    vector<int> a(t);
    f(i, t){
        cin>>a[i];
    }
    int flag=0, ans=0;
    f(i, t-1){
        if (i==0) ans+=1;

        if (a[i]==a[i+1]){
            if (flag==1) continue;
            else{
                flag=1;
                ans+=1;
            }
        }
        else{
            if (flag==1) flag=0;
            ans+=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}