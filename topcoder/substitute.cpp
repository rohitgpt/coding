#include<iostream>
#include<sstream>
#include<string>
using namespace std;


class Substitute{
public:
	long int getValue(string key, string code){
		long int output;
		string out;
		for (int i = 0; i < code.size(); i++)
		{
			int count=0;
			for (int j = 0; j < key.size(); j++)
			{
				count++;
				if (count >9) count=0;
				if (code[i]==key[j]) out += to_string(count);
			}
		}
		stringstream temp(out);
		temp >> output;
		return output;
	}
};

int main(){
	Substitute alpha;
	cout << alpha.getValue("TRADINGFEW","LGXWEV") << endl;
	return 0;
}