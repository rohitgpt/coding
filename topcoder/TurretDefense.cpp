#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class TurretDefense{
	public:
	int firstMiss(vector<int> x, vector<int> y, vector<int> t){
		int xt=0, yt=0, time=0;
		int timeDifference = 0;
		int i=0;
		while(timeDifference >= 0){
			time += abs(x[i]-xt)+abs(y[i]-yt);
			timeDifference = t[i]-time;
			if(timeDifference>=0){
				time = t[i];
				xt = x[i];
				yt = y[i];
			}
			// cout << timeDifference << endl;
			i++;
			if (i>x.size()) return -1;
		}
		return i-1;
	}
};

int main(){
	TurretDefense alpha;
	cout << alpha.firstMiss({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},{2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,31}) << endl;
	// cout << alpha.firstMiss({3,5,6}, {7,5,6} , {11,15,16}) << endl;
	return 0;
}