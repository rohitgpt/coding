#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ASeries{
public:
	int longest(vector<int> a){
		sort(a.begin(), a.end());
		int diff = a[1] - a[0], currentLongest=1;
		int tmpDiff, tmpLength=1;
		for (int i = 1; i < a.size(); i++){
			tmpDiff = a[i] - a[i-1];
			cout << tmpDiff << endl;
			if(tmpDiff != diff){
				diff = tmpDiff;
				if (tmpLength > currentLongest) currentLongest=tmpLength;
				tmpLength = 1;
			}
			else tmpLength +=1;
		}
		return currentLongest;
	}
};

int main(){
	ASeries alpha;
	cout << alpha.longest({3,8,4,5,6,2,2}) << endl;
	// cout << alpha.longest({-10,-20,-10,-10}) << endl;
	return 0;
}