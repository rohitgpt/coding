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

vector<int> p;
// { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };

bool isprime(int n)
{
  int i;
  bool isPrime = true;

  for(i = 2; i <= n / 2; ++i)
  {
      if(n % i == 0)
      {
          isPrime = false;
          break;
      }
  }

  return isPrime;
}

bool isprod(int n){
	f(k, p.size()){
		if(n%p[k]==0){
			if(isprime(n/p[k])) return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n=1000, count=0, flag=0, a,b;
	// static const int arr[] = 
	// cout<<p.size()<<endl;
	frp(i, 2, 	n+1) 
		if(isprime(i)) p.pb(i);
	vector<int> sum(2*n);

	// f(i, p.size()){
	// 	frp(j,)
	// }
	frp(i, 2, 2*n){
		if(!isprod(i-1)) continue;
		frn(j, i/2, 1){
			if(j>n-1 || (i-j)>n-1) continue;
			if(isprime(j) && isprime(i-j)){
				flag=1;
				break;
			}
		}
		if(flag==0){ sum[i]+=1;}
		flag=0;
	}

	f(i, sum.size()){
		if(sum[i]>0){
			f(k, p.size()){
				if((i-1)%p[k]==0){
					if(isprime((i-1)/p[k])){
						// cout<<p[k]<<" "<<n/p[k]<<endl;
						a=p[k];b=(i-1)/p[k];
						break;
					}
				}
			}
			if(!isprime(a+b-1) && isprod(a+b-1)){
			// if(sum[a+b]==0){
				count++;
				// cout<<b-a<<" "<<
				cout<<a<<" "<<b<<" "<<a*b+1<<" "<<a*b<<endl;
			}
		}
	}


	// f(i, sum.size()) if(sum[i]>0) cout<<i<<endl;
	cout<<count<<endl;
	// f(i, p.size()){
	// 	frp(j, i+1, p.size()){
	// 		if(p[i]*p[j]<=1000){
	// 			sum[p[i]*p[j]+1]+=1;
	// 			if(sum[p[i]*p[j]+1]>1) cout<<p[i]*p[j]+1<<endl;
	// 			count++;
	// 		}
	// 		if(!isprime(p[i]+p[j]-1) && (p[i]*p[j])<n+1){
	// 			// cout<<p[i]<<" "<<p[j]<<endl; 
	// 		}
	// 	}
	// }
	// cout<<count<<endl;

	return 0;
}
