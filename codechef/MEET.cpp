#include<iostream>
#include<vector>
// #include<algorithm>
#include<string>
using namespace std;

typedef long long ll;

#define f(i, n) for(int (i)=0; (i)<(n); (i)++)

int main(){
    int n, t;
    cin>>t;
    int tm;
    f(i, t){
        string s;
        cin>>s;
        tm = stoi(s);
        cout<<tm<<endl;
        cin>>n;
        f(j, n){
            cin>>s;
            cout<<s<<endl;
        }
    }
    return 0;
}