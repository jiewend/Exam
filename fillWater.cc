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

long long fillWater(vector<long long > wood){
    long long count = 0;
    int i = 0;
    int temp = 0;
    int ii = 1;
    while((i + ii) < wood.size()){
        // cout<<"wood[i]:"<<wood[i]<<" wood[i+ii]:"<<wood[i+ii]<<endl;
        // cout<<"i: "<<i<<" ii:"<<ii<<endl;
        if(wood[i] < wood[i+ii]){
            count += ii * wood[i];
            count -= temp;
            i += ii;
            temp =0;
            ii = 1;

        } else {
            temp += min(wood[i+ii], wood[i+ii-1]);
            count += temp;
            ii++;
        }
        // cout<<"temp: "<<temp<<endl;
        // cout<<"count: "<<count<<endl;
    }
    return count;
}

int main(){

    string tempStr;
    int intType;
    long long longLongType;
    getline(cin, tempStr);
    vector<long long > T = splitSpace(tempStr, longLongType);
    vector<long long > res;
    for (long long i = 0; i < T[0]; i++) { 
        getline(cin, tempStr);
        getline(cin, tempStr);
        vector<long long > wood = splitSpace(tempStr, longLongType);
        res.push_back(fillWater(wood));
    } 
    for (long long i = 0; i < res.size(); i++) { 
        cout<<res[i]<<endl;
    } 
}
