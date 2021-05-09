#include<iostream>

using namespace std;

typedef long long ll;

#define f(i, n) for(int (i)=0; (i)<(n); (i)++)


int main(){
    int n, t, c;
    cin>>n>>t>>c;

    int prev=-1, cur, ans=0;
    f(i, n){
        cin>>cur;
        if (cur<=t){
            if(prev>0) prev+=1;
            else prev=1;
        }
        else{
            if(prev>=c) ans+=(prev-c+1);
            prev = -1;
        }
    }
    if(prev>=c) ans+=(prev-c+1);
    cout<<ans<<endl;
    return 0;
}