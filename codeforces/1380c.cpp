#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define debug  cout<<"hello"<<endl
#define N 1e5+7
#define rj n-j-1

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t;
    cin>>t;
    int n, x, c, cnt;
    f(i, t){
        cin>>n>>x;
        vector<int> a(n);
        f(j, n)
            cin>>a[j];
        sort(a.begin(), a.end());
        c=1;
        cnt=0;
        f(j, n){
            if(a[rj]*c>=x){
                cnt+=1;
                c=1;
            }
            else{
                c+=1;
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}