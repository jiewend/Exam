#include <iostream> 
#include <algorithm> 
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

int main(){
	string inStr;
	int aa;
	getline(cin, inStr);
	vector<int> rawArray = splitSpace(inStr, aa);
	vector<int> single, doubl;
	for (unsigned i = 0; i < rawArray.size(); i++)  
		if(rawArray[i] % 2 == 0)
			doubl.push_back(rawArray[i]);
		else
			single.push_back(rawArray[i]);

	sort(single.begin(), single.end());
	sort(doubl.begin(), doubl.end());
	reverse(doubl.begin(), doubl.end());
	for (unsigned i = 0; i < single.size(); i++) 
		cout<<single[i]<<" ";
	for (unsigned i = 0; i < doubl.size(); i++)  
		cout<<doubl[i]<<" ";
	cout<<endl;
}
