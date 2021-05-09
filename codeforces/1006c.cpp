#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

#define f(i, n) for(int (i)=0; (i)<(n); (i)++)


int main(){

    int n;
    cin>>n;
    vector<int> a(n);
    f(i, n) cin>>a[i];

    ll sum1=a[0], sum3=a[n-1], ans=0;
    for(int i=0, j=n-1; i<=(n-1) && j>=1 && i<j; ){
        if(sum1>sum3){
            j-=1;
            sum3+=a[j];
        }
        else if (sum3>sum1){
            i+=1;
            sum1+=a[i];
        }
        else if(sum1>ans){
            ans=sum1;
            i+=1;
            sum1+=a[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}