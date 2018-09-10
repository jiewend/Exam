#include <iostream> 
#include <vector> 
#include <istream> 
#include <sstream> 
#include <algorithm> 

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
	string n;
	string strArray1;
	stringstream issn;
	stringstream issarray;
	getline(cin, n);
	getline(cin, strArray1);
	vector<int> array1;
	array1 = splitSpace(strArray1);


	sort(array1.begin(), array1.end());

	int arraySize = array1.size();
	if(arraySize % 2 == 1){
		cout<<array1[arraySize / 2]<<endl;
	}
	else{
		if((array1[arraySize / 2] + array1[arraySize / 2 - 1]) % 2 == 0){
			cout<<((array1[arraySize / 2] + array1[arraySize / 2 - 1]) / 2)<<endl;
		}
		else{
			float mid = ((array1[arraySize / 2] + array1[arraySize / 2 - 1])) / 2.0;
			cout<<mid<<endl;
		}
	}
}
