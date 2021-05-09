#include<iostream>
#include<string>

using namespace std;

typedef long long ll;

#define f(i, n) for(int (i)=0; (i)<(n); (i)++)


int main(){
    int t;
    cin>>t;
    f(i, t){
        string s;
        cin>>s;
        int k;
        f(j, s.length()){
            if(j%2==0){
                if(s[j]=='a') s[j]='b';
                else  s[j]='a';
            }
            else{
                int rj = j;
                if(s[rj]=='z') s[rj]='y';
                else s[rj]='z';
            }
        }
        cout<<s<<endl;
    }
    return 0;
}