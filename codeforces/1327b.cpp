#include <vector>
#include <iostream>
#include <algorithm>
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

    int t, n, m, husband;
    int *l;
    cin>>t;
    f(i, t){
        cin>>n;
        vector<int> kings(n, 0), married(n, -1);
        f(j, n){
            cin>>m;
            f(k, m){
                cin>>husband;
                husband-=1;
                if(kings[husband]==0 && married[j]==-1){
                    married[j]=husband;
                    kings[husband]=1;
                    continue;
                }
            }
        }
        int count=0;
        f(j, n){
            if (married[j]==-1){
                f(k, n){
                    if(kings[k]==0){
                        cout<<"IMPROVE"<<endl;
                        cout<<j+1<<" "<<k+1<<endl;
                        break;
                    }
                }
                break;
            }
            count+=1;
        }
        if (count==n) cout<<"OPTIMAL"<<endl;
    }
    return 0;
}