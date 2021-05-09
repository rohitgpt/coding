#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

typedef long long ll;

#define fi(i, a, n) for(int (i)=(a); (i)<(n); (i)++)
#define f(i, n) for(int (i)=0; (i)<(n); (i)++)
#define N 1e2+8

vector<int> primes(int a){
    set<int> p;
    int j=2;
    while(a!=1){
        if(a%j==0){
            a/=j;
            p.insert(j);
        }
        else{
            j+=1;
        }
    }
    vector<int> ans(p.begin(), p.end());
    return ans;
}

int main(){
    int t, n,flag=0;
    cin>>t;
    vector<int> p;
    p = primes(t);
    f(i, p.size()){
        cout<<p[i]<<" ";
    }
    // fi(i, 2, N){
    //     flag=0;
    //     f(j, min((int)p.size(), (int)sqrt(i))){
    //         if (i%p[j]==0){
    //             flag=1;
    //             break;
    //         }
    //         else if (p[j]>(int)sqrt(i)){
    //             break;
    //         }
    //     }
    //     if (flag==0) p.push_back(i);
    // }

    // f(i, t){
    //     // cin>>n;
    //     n = i+1;
    //     set<int> divisors;
    //     int j = 0;
    //     while(n!=1){
    //         if(n%p[j]==0){
    //             n/=p[j];
    //             divisors.insert(p[j]);
    //         }
    //         else{
    //             j+=1;
    //         }
    //     }
        // for(set<int>::iterator i=divisors.begin(); i!=divisors.end(); i++){
        //     cout<<*i<<" ";
        // }
        // cout<<i+1<<" "<<divisors.size()<<endl;
    // }
    return 0;
}