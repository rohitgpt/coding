#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define debug  cout<<"hello"<<endl
#define N 1e9+7
#define ms map<int,priority_queue<long> >

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    ms x, y;
    int a, b;
    cin>>n;
    f(i, n){
        cin>>a>>b;
        if(x[a].empty())    x[a]=priority_queue<long> ();
        x[a].push(b);
        if(y[b].empty())    y[b]=priority_queue<long> ();
        y[b].push(a);
    }

    ms::iterator it;
    ll k, m;
    ll sum=0;
    for(it=x.begin(); it!=x.end(); it++){
        k = it->second.size();
        sum+=(k*(k-1)/2);

        m=1;
        a = it->second.top();
        it->second.pop();
        // cout<<it->first<<" "<<a<<" "<<m<<endl;
        while(!it->second.empty()){
            if(it->second.top()==a){
                m+=1;
            } 
            else{
                sum-=(m*(m-1)/2);
                m=1;
            }
            a = it->second.top();
            it->second.pop();
        }
        sum-=(m*(m-1)/2);
    }
    for(it=y.begin(); it!=y.end(); it++){
        k = it->second.size();
        sum+=(k*(k-1)/2);
        // cout<<it->first<<" "<<k<<" "<<sum<<endl;
    }
    cout<<sum<<endl;
    return 0;
}