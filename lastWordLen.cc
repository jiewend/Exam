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

int main(){
    string inStr;
    getline(cin, inStr);
    vector<string > stringVec =splitSpace(inStr, inStr);
    cout<<stringVec.back().size()<<endl;
}
