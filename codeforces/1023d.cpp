#include <iostream>
#include <bits/stdc++.h>
#include <vector>
// #include <chrono>
#include <string>
#include <algorithm>

using namespace std;
// using namespace std::chrono;

// typedef std::chrono::high_resolution_clock::time_point timen;
typedef long long ll;
typedef long double ld;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()
#define f(i, n) for(int (i)=0; (i)<(n); (i)++)
#define frp(i, a, b) for(int (i)=a; (i)<(b); (i)++)
#define frn(i, a, b) for(int (i)=a; (i)>(b); (i)--)
#define pb(a) push_back(a)

#define p(aaa) cout<<"debug "<<aaa<<endl;
#define PI 3.14159265358979323846

const int mod=1e9+7;
const int mx=1e3;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q, t1;
	vector<int> a;
	cin>>n>>q;
	f(i, n){
		cin>>t1;
		a.pb(t1);
	}

	t1=0;
	frp(i, 1, n){
		if(a[i]!=0){
			if(a[i]<a[i-1] && t1==0)	t1=1;
			else if(a[i]>a[i-1] && t1==1){
				t1=i;
				break;
			}
		}
		// else if(a[i+1]!=0)	a[i]=a[i+1];
	}

	if(t1<=1){
		cout<<"YES"<<endl;
		int t2=-1, t3=-1, t4, min, max, counting=0;
		t1=0;
		f(i, n){
			if(a[i-1]==q) t1=1;
			if(((a[i]!=0 && a[i]<a[i-1]) || i==n-1) && t1==0) t1=2;
			if(a[i]==0 && counting==0){
				t2=i; 
				counting=1;
			}
			else if(a[i]!=0 && counting==1){
				t3=i-1; 
				counting=0;
			}
			else if(i==n-1 && counting){ t3=i; counting=0;}
			// cout<<t1<<" "<<t2<<" "<<t3<<" "<<counting<<endl;
			if(t3>=t2 && t2>=0 && counting==0){
				if(t1==1){
					if(t3>n-1) min=a[t3+1];
					else min=1;
					if(t2>0)max=a[t2-1];
					else max=q;
					t4=max;
					frp(j, t2, t3+1){
						if(t4>min)	a[j]=t4--;
						else a[j]=t4;
					}
				}
				else if(t1==0){
					if(t2>0) min=a[t2-1];
					else min=1;
					if(t3<n-1) max=a[t3+1];
					else max=q;
					t4=max;
					frn(j, t3, t2-1){
						if(t4>min)	a[j]=--t4;
						else a[j]=min;
					}
				}
				else if(t1==2){
					if(t2>0) min=a[t2-1];
					else min=1;
					if(t3<n-1)max=a[t3+1];
					else max=1;
					t4=q;
					frn(j, (t3+t2)/2, t2-1){
						if(t4>min)	a[j]=t4--;
						else a[j]=min;
					}
					t4=q-1;
					frp(j, (t3+t2)/2+1, t3+1){
						if(t4>max)	a[j]=t4--;
						else a[j]=max;
					}
				}
				t2=-1, t3=-1;
			}
		}
		f(i, n) cout<<a[i]<<" ";
	}
	else cout<<"NO"<<endl;
	return 0;
}