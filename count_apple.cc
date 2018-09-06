#include <iostream> 
#include <vector> 
#include <string>
#include <cstdlib> 
#include <istream> 
#include <sstream> 
#include <numeric> 

using namespace std;

vector<int> splitSpace(std::string stri){

	string temp;
	vector<int>res;
	istringstream stream(stri);
	while (stream >> temp)
	{
		stringstream iss;
		iss << temp;
		int f;
		iss >> f;
		res.push_back(f);
	}
	return res;
}


int main(){
	string str0, str1, str2, str3;
	vector<int>res0, res1, res2, res3;

	getline(cin, str0);
	getline(cin, str1);
	getline(cin, str2);
	getline(cin, str3);

	// res0 = splitSpace(str0);
	res1 = splitSpace(str1);
	// res2 = splitSpace(str2);
	res3 = splitSpace(str3);

	vector<int> apple_sum;
	for (unsigned i = 0; i < res1.size(); i++) { 
		apple_sum.push_back(accumulate(res1.begin(), res1.begin() + i + 1, 0));
	} 

	for (unsigned i = 0; i < res3.size(); i++) { 
		for (unsigned j = 0; j < res1.size(); j++) { 
			if(res3[i] <= apple_sum[j]){
				cout<<j + 1<<endl;
				break;
			}

		} 

	} 
}

