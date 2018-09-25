
#include <istream> 
#include <sstream> 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector> 
using namespace std;
 
// 计算图里所有定点的入度和出度
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
 
vector<int> Print_In_Degree(vector<vector<int> > Edge, int cityNum)  //输出有向图各顶点的入度；
{
    vector<int> res;
	for(int i=0; i<cityNum; i++) {
		int Mc = 0;
		for(int j=0; j<cityNum; j++) Mc += Edge[i][j];
        res.push_back(Mc);
	}
    return res;
}
 
vector<int> Print_Out_Degree(vector<vector<int> > Edge, int cityNum)  //输出有向边各顶点的出度;
{
    vector<int> res;
	for(int i=0; i<cityNum; i++) {
		int Md = 0;
		for(int j=0; j<cityNum; j++) Md += Edge[j][i];
        res.push_back(Md);
	}
    return res;
}
 
int main()
{
    int Mc, Md;
    string inStr;
    vector<int > inVec;
    int inInt;
    getline(cin, inStr);
    inVec = splitSpace(inStr, inInt);

    int cityNum = inVec[0];
    int pathNum = inVec[1];
    vector<int > vec(cityNum, 0);
    vector< vector<int> > Edge;
    for (unsigned i = 0; i < cityNum; i++) { 
        Edge.push_back(vec);
    } 
        
    for (unsigned i = 0; i < pathNum; i++) { 
        getline(cin, inStr);
        inVec = splitSpace(inStr, inInt);
        Edge[inVec[0] - 1][inVec[1] - 1] = 1;
    } 
    vector<int> inDegree, outDegree;

    inDegree = Print_In_Degree(Edge, cityNum);
    outDegree = Print_Out_Degree(Edge, cityNum);
    
    int res = 0;
    for (unsigned i = 0; i < cityNum; i++) { 
        if(inDegree[i] > outDegree[i])
            res++;
    }
    cout<<res<<endl; 
    return 0;
}

