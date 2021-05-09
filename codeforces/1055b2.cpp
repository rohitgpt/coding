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

    int n,m,l;
    cin>>n>>m>>l;
    vector<ll> h(n);
    vector<int> c;
    f(i, n) cin>>h[i];
    int flag=0;
    f(i, n){
        if(h[i]>l && flag==0){
            c.push_back(i);
            flag=1;
        }
        else if(h[i]<=l && flag==1){
            c.push_back(i-1);
            flag=0;
        }
    }
    // f(k, c.size()) cout<<c[k];
    // cout<<endl;

    // cout<<c.size()<<endl;
    if(flag==1) c.push_back(n-1);
    int a,b, q;
    f(i, m){
        cin>>q;
        if(q==1){
            cin>>a>>b;
            a-=1;
            if(h[a]>l){
                h[a]+=b;
                continue;
            }
            h[a]+=b;
            if(h[a]<=l) continue;
            int j=0, flag=0;
            for(; !c.empty() && j<c.size() && c[j]<a; j++) flag=1;
            // cout<<a<<b<<endl;
            // cout<<j<<" hello"<<endl;
            if (flag==0){
                if(!c.empty() && c[j]-a==1) c[j]-=1;
                else{
                    vector<int> temp(2, a);
                    c.insert(c.begin(), temp.begin(), temp.end());
                }
            }
            else if(j%2==0){
                j-=1;
                if(a-c[j]==1 && c[j+1]-a==1){
                    c.erase(c.begin()+j, c.begin()+j+2);
                }
                else if (a-c[j]==1){
                    c[j]+=1;
                }
                else if(c[j+1]-a==1 ){
                    c[j+1]-=1;
                }
                else{
                    vector<int> temp(2, a);
                    c.insert(c.begin()+j+1, temp.begin(), temp.end());
                }
            }
            // f(k, c.size()) cout<<c[k];
            // cout<<endl;
            continue;
        }
        cout<<c.size()/2<<endl;
    }

    return 0;
}