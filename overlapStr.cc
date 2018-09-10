#include <iostream> 
#include <string> 
#include <vector> 
#include <istream> 
#include <sstream> 
#include <string.h> 

using namespace std;

template <typename T>
vector<T> splitSpace(std::string stri, T outType){
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

int overLabNum(string aa, string bb){
	int aaSize = aa.size();
	int bbSize = bb.size();
	int minSize;
	if(aaSize > bbSize)
		minSize = bbSize;
	else
		minSize = aaSize;
	int res = 0;
	for (unsigned i = 0; i < minSize + 1; i++) { 
		if(aa.substr(aaSize - i, aaSize) == bb.substr(0, i)){
			res = i;
		}
	} 
	return res;
}
int main(){
	string inStr;
	getline(cin, inStr);
	vector<string> inVec = splitSpace(inStr, inStr);
	int res = overLabNum(inVec[0], inVec[1]);
	cout<<res<<endl;
}

