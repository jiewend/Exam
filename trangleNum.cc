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
bool isTriangle(int a, int b, int c){
    return ((a+b)>c && (b+c)>a && (a+c)>b);

}

long long rawTriangleNum(int X, int Y, int Z){
    long long tNum = 0;
    for (unsigned i = 1; i <= X; i++) { 
        for (unsigned j = 1; j <= Y; j++) { 
            for (unsigned k = 1; k <= Z; k++) { 
                tNum += isTriangle(i, j, k);
            } 
        } 
    } 
    return tNum;
}
long long numT(int minA){
    long long tNum;
    if(minA % 2 == 0){
        tNum = (minA / 2 + 1) * (minA / 2)  * 3;
    } else {
        tNum = (minA / 2 + 1)* (minA / 2 + 1) * 3; 
    }
    return tNum;
}
long long triangleNum(int x, int y, int z){
    int minA = min(z, min(x, y));
    int tNum = 0;
    if(minA % 2 == 0){
        tNum = (minA / 2 + 1) * (minA / 2)  * 3;
    } else {
        tNum = (minA / 2 + 1)* (minA / 2 + 1) * 3; 
    }
    
    return tNum;
    

}

int main(){
    string inStr;
    int inType;
    vector<int > inVec;
    getline(cin, inStr);
    inVec = splitSpace(inStr, inType);
    int aa = inVec[0];
    int bb = inVec[1];
    int cc = inVec[2];
    
    long long res = rawTriangleNum(inVec[0], inVec[1], inVec[2]);
    cout<<aa<<" "<<numT(aa)<<endl;
    cout<<bb<<" "<<numT(bb)<<endl;
    cout<<cc<<" "<<numT(cc)<<endl;
    cout<<res<<endl;
}
