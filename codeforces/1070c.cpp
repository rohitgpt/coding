#include<bits/stdc++.h>

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

bool cmp(const pair< int, int> &a, const pair<int, int> &b){
	if(a.first==b.first){
		return a.second>b.second;
	}
	return a.first<b.first;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, m;
	cin>>n>>k>>m;
	vector<int> l(m), r(m), c(m), p(m);
	vector<vector<pair<int, int> > > plans(n), endplans(n);
	f(i, m){
		cin>>l[i]>>r[i]>>c[i]>>p[i];
		plans[l[i]-1].push_back(make_pair(p[i], c[i]));
		if(r[i]<n) endplans[r[i]].push_back(make_pair(p[i], c[i]));
	}
	int ans=0, cc=0, ccnt=1, cn=0;
	f(i,n){
		sort(all(plans[i]), cmp);
	}
	vector<pair<int, int> > temp(plans[0]), tmp1, tmp2;
	__typeof__(temp.begin()) it1;
	
	f(i, n){
		tmp1.clear();	
		tmp2.clear();
		if(plans[i].empty() && endplans[i].empty()) ccnt+=1;
		else{
			if(!plans[i].empty() && i>0){
				sort(all(plans[i]),cmp);
				merge(all(temp), all(plans[i]), back_inserter(tmp1), cmp);
				temp.swap(tmp1);
			}
			if(!endplans[i].empty() && i>0){
				sort(all(endplans[i]),cmp);
				set_difference(all(temp), all(endplans[i]), inserter(tmp2, tmp2.begin()),cmp);
				temp.swap(tmp2);
			}
			ans+=cc*ccnt;
			cc=0;
			ccnt=1;
			cn=0;
			tr(temp, it){
				cn+=it->second;
				if(cn>k){
					cc+=(it->first)*(k+it->second-cn);
					break;
				}
				else{
					cc+=(it->first)*(it->second);
				}
			}
		}
	}
	ans+=cc*ccnt;
	cout<<ans;
	return 0;
}