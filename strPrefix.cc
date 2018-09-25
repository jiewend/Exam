#include<iostream>
#include<vector>
#include<string>
#include<istream> 
#include<sstream> 

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

struct Node{
    int flag;
    Node *next[27];
    Node(){
        for(int i=0;i<27;++i){
            next[i]=0;
        }
        flag=0;
    }
};

Node *root;

void init(){
    root=new Node();
}

void ins(string s)
{
    int len=s.length();
    Node *now=root;
    for(int i=0;i<len;++i){
        int to=s[i]-'a';
        if(now->next[to]==NULL){
            now->next[to]=new Node();
        }
        now=now->next[to];
        now->flag++;
    }
}

string fid(string s)
{
    string tp="";
    int len=s.length();
    Node *now=root;
    for(int i=0;i<len;++i){
        int to=s[i]-'a';
        tp+=s[i];
        now=now->next[to];
        if(now->flag==1) return tp;
    }
    return tp;
}

vector<string > strArr;
int main()
{
    init();
    string inStr;
    int N;
    getline(cin, inStr);
    vector<int > inVec = splitSpace(inStr, N);
    N = inVec[0];
    for (unsigned i = 0; i < N; i++) { 
        getline(cin, inStr);
        vector<string > stringTemp = splitSpace(inStr, inStr);
        strArr.push_back(stringTemp[0]);
        ins(stringTemp[0]);
    } 

    for(int i=0;i<strArr.size();++i)
        cout<<fid(strArr[i])<<endl;
    return 0;
}
