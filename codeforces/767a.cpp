#include <vector>
#include <iostream>
#include <algorithm>
// #include <string>
#include <queue>

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

    if (a[i] < ((a[lc(i)]>a[rc(i)]) ? a[lc(i)] : a[rc(i)])) {
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

    priority_queue<int> pq;

    int n, t;
    cin>>n;
    int m = n;
    f(i, n){
        cin>>t;
        pq.push(t);
        while (pq.top()==m){
            cout<<m<<" ";
            m--;
            pq.pop();
        }
        cout<<endl;
    }
    return 0;
}