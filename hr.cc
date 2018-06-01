#include <iostream> 
#include <vector> 
#include <string>
#include <cstdlib> 
#include <istream> 
#include <sstream> 
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

int lastOne(vector<int> ak, int num){
	vector<int> person;
	int aksize = ak.size();
	for (unsigned i = 0; i < num; i++) 
		person.push_back(i);
	int tap = 0;
	int aktap = 0;
	int aa = 1;
	while(person.size() > 1){
		tap = ((tap + ak[aktap++ % aksize] - 1) % person.size());
		vector<int>::iterator it=person.begin() + tap;
		person.erase(it);
	}
	return person[0];
}

int main(){
	int n, m, coun;
	vector<int> inputNum;
	vector<int> input;
	char aa[256];
	string str1;
	getline(cin, str1); 
	inputNum = splitSpace(str1);
	vector<int> res;
	coun = inputNum[0];
	for (int i = 0; i < coun; i++){ 
		string str2;
		getline(cin, str2);	
		input= splitSpace(str2);
		vector<int> p;
		n = input[0];
		m = input[1];
		for (unsigned i = 2; i < input.size(); i++) 
			p.push_back(input[i]);
		res.push_back(lastOne(p, n));
	} 
	for (unsigned i = 0; i < res.size(); i++) 
		cout<<res[i]<<endl;
}
