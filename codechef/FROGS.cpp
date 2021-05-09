#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

#define f(i, n) for(int (i)=0; (i)<(n); (i)++)

int main(){
    int n, t;
    cin>>t;
    f(i, t){
        cin>>n;
        int ans=0, x;
        vector<int> w(n), l(n), ind(n);
        f(j, n) cin>>w[j];
        f(j, n) cin>>l[w[j]-1];
        f(j, n) ind[w[j]-1]=j;
        for(int j=1; j<n; j++){
            x = ind[j-1]-ind[j]+1;
            int tmp = 0;
            if(x>0){
                tmp=(x)/l[j];
                if(x%l[j]!=0) tmp+=1;
                ind[j]+=tmp*l[j];
                ans+=tmp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}