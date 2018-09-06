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
	istringstream stream(stri);  //将str传到流stream里面
	while (stream >> temp)	//将stream流里面的值传到temp，遇到空格插分
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
	string str0, str1, str2;
	vector<int>res0, res1, res2;

	getline(cin, str0);
	getline(cin, str1);
	getline(cin, str2);

	int n, k;
	res0 = splitSpace(str0);
	cout<<res0[0]<<res0[1]<<endl;




}
