#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;


#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a);

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


    int t;
    int* a;
    cin>>t;
    f(i, t){
        int n, x, sum=0, ans=0;
        cin>>n>>x;
        a = (int*)calloc(n, sizeof(int));

        f(j, n){
            cin>>a[j];
            sum+=a[j];
            a[j]=a[j]%x;
        }
        if (sum%x==0){
            ans = n;
            f(j, (n+1)/2){
                if (a[j]!=0 || a[n-j-1]!=0){
                    cout<<n-j-1<<endl;
                    break;
                }
                if (j==(n+1)/2-1){
                    cout<<-1<<endl;
                    break;
                }
            }
        }
        else{
            cout<<n<<endl;
        }
        free(a);
    }
    return 0;
}