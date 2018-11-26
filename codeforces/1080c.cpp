#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f(i,n) for(int (i)=0; (i)<(n); (i)++)

struct rect
{
	int x1, y1, x2, y2;
};

struct rect intersect(struct rect c, struct rect d){
	return rect{max(c.x1, d.x1), max(c.y1, d.y1), min(c.x2, d.x2), min(c.y2, d.y2)};
}

pair<ll, ll> whit(struct rect a){
	if(a.y1>a.y2 || a.x1>a.x2) return make_pair(0, 0);
	ll ans=0;
	ans = (a.y2-a.y1+1)*(a.x2-a.x1+1);
	if(ans%2==0) return make_pair(ans/2, ans/2);
	else{
		if((a.x1+a.y1)%2==0) return make_pair((ans+1)/2, (ans-1)/2);
		else return make_pair((ans-1)/2, (ans+1)/2);
	}
}

ll areas(struct rect a){
	ll ans=0;
	ans = (a.y2-a.y1+1)*(a.x2-a.x1+1);
	if(a.y1>a.y2 || a.x1>a.x2) return 0;
	else return ans;
}

int main(){
	int t, a, b;
	int x1, y1, x2, y2;
	pair<ll, ll> wb, wbb, wbw, wbe, ans;
	cin>>t;
	f(i, t){
		cin>>a>>b;
		cin>>x1>>y1>>x2>>y2;
		rect c={x1, y1, x2, y2};
		cin>>x1>>y1>>x2>>y2;
		rect d={x1, y1, x2, y2};
		rect e = intersect(c, d);
		wb = whit({1, 1, a, b});
		wbw = whit(c);
		wbb = whit(d);
		wbe = whit(e);
		cout<<wb.first-wbw.first-wbb.first+wbe.first+areas(c)-areas(e)<<" "<<wb.second-wbw.second-wbb.second+wbe.second+areas(d)<<endl;
	}
	return 0;
}