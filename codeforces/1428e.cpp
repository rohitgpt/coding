#include <vector>
#include <iostream>
#include <algorithm>
// #include <string>
using namespace std;

typedef long long ll;

#define f(i, n) for (ll (i)=0; (i)<(n); (i)++)
#define pb(a) push_back(a)
#define debug  cout<<"hello"<<endl
#define N 10^5+777
#define lc(i) 2*(i)
#define rc(i) 2*(i)+1
#define p(i) (i)/2

vector<int> a(N, 0);
int k, m;

void swap(int *a1, int *a2){
    int temp;
    // cout<<a1<<endl;
    // cout<<*a1<<endl;
    // cout<<&a1<<endl;
    temp = *a1;
    *a1 = *a2;
    *a2 = temp;
    return;
}

void heapify(int i){
    if (i>m/2) return;

    if (a[i]<   ((a[lc(i)]>a[rc(i)]) ? a[lc(i)] : a[rc(i)])) {
        if(a[i]<a[lc(i)]){
            swap(&a[i], &a[lc(i)]);
            heapify( lc(i));
        }
        else{
            swap(&a[i], &a[rc(i)]);
            heapify( rc(i));
        }
    }
    return;
}

void insertnode(int i, int x){
    a[i] = x;
    m+=1;
    while(i!=1){
        i=p(i);
        heapify(i);
    }
    return;
}

void build_heap(){
    for(int i=k/2+1; i>=1; i--){
        heapify(i);
    }
    return;
}

ll pop_head(){
    ll ans = a[1];
    a[1] = a[m];
    heapify(1);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, x, x1, x2;
    cin>>n>>k;
    f(i, n) cin>>a[i+1];
    m=n;
    build_heap();

    while(m<k){
        x = a[1];
        x1 = a[1]/2;
        x2 = a[1]-x1;
        a[1] = max(x1, x2);
        heapify(1);
        insertnode(m+1, min(x1, x2));
    }
    ll ans=0, t;
    f(i, k){
        t = pop_head();
        // cout<<t<<" ";
        ans = ans + t*t;
    }
    cout<<ans<<endl;
    return 0;
}