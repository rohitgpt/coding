#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f(i, n) for(ll (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(ll (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(ll (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)
#define all(c) (c).begin(), (c).end()
#define tr(c, it) for(__typeof__((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define present(c, x) ((c).find(x)!=(c).end())
#define cpresent(c, x) (find(all(c), x)!=(c).end())

const int mod=1e9+7;
const ll mx=1e14;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int a;
    vector<int>b(10, 0);

    f(i, 6){
        cin>>a;
        b[a]+=1;
    }

    if (*max_element(b.begin(), b.end()) < 4){
        cout<<"Alien";
        return 0;
    }
    else if (*max_element(b.begin(), b.end()) == 6){
        cout<<"Elephant";
        return 0;
    }
    else{
        f(i, 6){
            if (b[i]==2) {
                cout<<"Elephant";
                return 0;
            }
        }
        cout<<"Bear";
        return 0;
    }
}
