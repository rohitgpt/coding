#include <vector>
#include <iostream>
#include <algorithm>
// #include <string>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a)
#define debug  cout<<"hello"<<endl
#define N 10^5+7

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first<b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin>>n;
    vector<int> a(n), l2, l3;
    f(i, n) cin>>a[i];
    // vector< vector<bool> > t(n, vector<bool> (n, 0));
    vector<pair<int, int> > x, tg;
    int ri;
    f(i, n){
        ri = n-i-1;
        if (a[ri]==1) l2.push_back(ri);
        else if (a[ri]==2){
            l3.push_back(ri);
            if (!l2.empty()){
                x.push_back(make_pair(ri, l2.back()));
                l2.pop_back();
            }
            else{
                cout<<-1<<endl;
                return 0;
            }
        }
        else if (a[ri]==3){
            if(!l3.empty()){
                x.push_back(make_pair(ri, l3.back()));
                l3.pop_back();
            }
            else if(!l2.empty()){
                x.push_back(make_pair(ri, l2.back()));
                l2.pop_back();
            }
            else{
                cout<<-1<<endl;
                return 0;
            }
            l3.push_back(ri);
        }
    }
    if (x.size())
        sort(x.begin(), x.end(), comp);
    // f(i, x.size()) cout<<x[i].first<<" "<<x[i].second<<endl;
    int j=0;

    f(i, n){
        if(a[i]==1){
            tg.push_back(make_pair(i,i));
        }
        else if(a[i]>1){
            tg.push_back(make_pair(i,i));
            tg.push_back(make_pair(i, x[j].second));
            if(a[x[j].first]+a[x[j].second]==3) 
                a[x[j].second]-=1;
            j++;
        }
    }
    
    cout<<tg.size()<<endl;
    if (tg.size())
        sort(tg.begin(), tg.end(), comp);
    f(i, tg.size()){
        cout<<tg[i].first+1<<" "<<tg[i].second+1<<endl;
        // t[tg[i].first][tg[i].second]=1;
    }
    // f(i, n){
    //     f(j, n){
    //         cout<<t[i][j];
    //     }
    //     cout<<endl;
    // }
    
    return 0;
}