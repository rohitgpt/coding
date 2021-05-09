#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

#define f(i, n) for(int (i)=0; (i)<(n); (i)++)

int main(){
    int n;
    cin>>n;
    int i=10;
    while(n%i!=0) i--;
    cout<<i<<endl;
    return 0;
}