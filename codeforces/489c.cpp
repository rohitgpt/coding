#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a)
#define debug  cout<<"hello"<<endl
#define N 1e5+777

bool isprime(ll a){

    for(int j=2; j<=sqrt(a); j++){
        if(a%j==0) return false;
    }
    return true;
}
bool divisor(ll a){
    if(a<2) return false;
    int i = sqrt(a);
    if(a%i==0 && a/i==i)
        if(isprime(i))
            return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int m, s;
    cin>>m>>s;
    vector<int> smallest(m), largest(m);
    if(s>9*m || (s==0 && m>1)) cout<<-1<<" "<<-1<<endl;
    else if(s==9*m){
        int t=m;
        while(m){
            cout<<9;
            m-=1;
        }
        cout<<" ";
        while(t){
            cout<<9;
            t-=1;
        }
        cout<<endl;
    }
    else{
        int sum = 0, cnt=0, t;
        while(sum<s){
            if(s-sum<=9 && m-cnt>1){
                t = s-sum-1;
                smallest[cnt]=t;
                cnt=m-1;
                smallest[cnt]=1;
                sum=s;
            }
            else{
                t = min(9, s-sum);
                smallest[cnt]=t;
                cnt+=1;
                sum+=t;
            }
        }
        f(i, smallest.size()) cout<<smallest[smallest.size()-1-i];
        cout<<" ";
        sum=0, cnt=0;
        while(sum<s){
            t = min(9, s-sum);
            largest[cnt]=t;
            cnt+=1;
            sum+=t;
        }
        f(i, largest.size()) cout<<largest[i];
        cout<<endl;
    }
    return 0;
}