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
#define N 10^5+777

int query(int l, int r){
    int ans;
    cout<<"? "<<l<<" "<<r;
    cout<<endl;
    // endl;
    // '\n';
    cout.flush();
    cin>>ans;
    // cout<<ans;
    return ans;
}

void inquire(int q, int l, int r){
    int a, b;
    a = query(l, (l+r)/2);
    b = query((l+r)/2, r);
    if (r-l==1){
        if(a==l){
            cout<<"! "<<r<<"\n";
            // cout<<"! "<<r<<endl;
        }
            // printf("! %d", r);
            // fflush(stdout);
        else{
            cout<<"! "<<l<<"\n";
            // cout<<"! "<<l<<endl;
        }
            // printf("! %d", l);
            // fflush(stdout);
        exit(0);
        // return;
    }
    if(q==l){
        if(a==q)
            inquire(a, l, (l+r)/2);
        else{
            inquire(b, (l+r)/2, r);
        }
    }
    else if(q==r){
        if(b==q)
            inquire(b, (l+r)/2, r);
        else
            inquire(a, l, (l+r)/2);

    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin>>n;

    int l, r, q;
    l = 1;
    r = n;
    q = query(l, r); // either 1 to q or q to r
    
    inquire(q, l, r);
    return 0;
}