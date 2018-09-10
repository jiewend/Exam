#include <iostream> 
#include <vector> 
#include <string>
#include <cstdlib> 
#include <istream> 
#include <sstream> 

using namespace std;
template <typename T>
vector<T> splitSpaceT(std::string stri, T outType){
	string temp;
	vector<T>res;
	istringstream stream(stri);
	while (stream >> temp)
	{
		stringstream iss;
		iss << temp;
		T f;
		iss >> f;
		res.push_back(f);
	}
	return res;
}

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
	
	int maxlen = 100;
	int lenMap[26];
	string charMap;
	string temp;

	vector<int>res;
	string str;
	getline(cin, str);  //会吧已经有的数据读进去
	/* istringstream stream(str);  //将str传到流stream里面 */
	// while (stream >> temp)	//将stream流里面的值传到temp，遇到空格插分
	// {
		// stringstream iss;
		// iss << temp;
		// int f;
		// iss >> f;
		// res.push_back(f);
	/* } */
	res = splitSpace(str);

	string content;
	getline(cin, content);
	for (unsigned i = 0; i < res.size(); i++) { 
		lenMap[i] = res[i];
	} 
	int lineNum = 1;
	int currentLen = 0;
	if(content.size() == 0){
		cout<<0<<" "<<0;
	} else {
	for(int i = 0; i<content.size();i++){
		if (currentLen + res[(int)content.c_str()[i] - 97] <= maxlen) { 
			currentLen = currentLen + res[(int)content.c_str()[i] - 97];
		} else {
			currentLen = res[(int)content.c_str()[i] - 97];
			lineNum++;
		}
	}
	cout<<lineNum<<" "<<currentLen;
	}
}
