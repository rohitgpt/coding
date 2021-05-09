#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a)
#define debug  cout<<"hello"<<endl
#define N 1e5+777



int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


    int n;
    cin>>n;
    vector<vector<int> > a(4, vector<int>(n, -1));
    int t=0, cnt=0;
    while(t<=n){
        if(a[2][t]==-1 && a[0][t]==-1){
            a[0][t]=cnt; a[1][t]=cnt; //vertical
            cnt+=1; cnt%=5;
        }
        else if(a[0][t]==-1 && a[2][t]!=-1){
            if(n-t==1){
                a[0][t]=cnt; a[1][t]=cnt; //vertical
                cnt+=1; cnt%=5;
            }
            else{
                a[0][t]=cnt; a[0][t+1]=cnt; //horizontal
                cnt+=1; cnt%=5;
                a[1][t]=cnt; a[1][t+1]=cnt; //horizontal
                cnt+=1; cnt%=5;
            }
            t+=1;
            continue;
        }

        if(n-t>=2){
            a[2][t]=cnt; a[2][t+1]=cnt; //horizontal
            cnt+=1; cnt%=5;
            a[3][t]=cnt; a[3][t+1]=cnt; //horizontal
            cnt+=1; cnt%=5;
        }
        else if(n-t==1){
            a[2][t]=cnt; a[3][t]=cnt; //vertical
            cnt+=1; cnt%=5;
        }
        t+=1;
    }
    
    f(i, 4){
        f(j, n){
            cout<<(char)(a[i][j]+'a');
        }
        cout<<endl;
    }

    return 0;
}