#include <iostream> 
#include <vector> 
#include <map> 
#include <sstream> 
#include <string.h> 
#include <algorithm> 
#include <cstdlib> 

using namespace std;

int caluPoint(char a, char b){
    string aa("qwertasdfgzxcv");
    string bb("yuiophjklbnm");
    if((aa.find(a) && aa.find(b)) || (bb.find(a) && bb.find(b)))
        return 1;
    else
        return 2;
}
int strDistance(string pp, string qq) {
    int len1 = pp.size();
    int len2 = qq.size();
    int d[len1+1][len2+1];
    int i,j;   
    for(i = 0;i <= len1;i++)   
        d[i][0] = i;
    for(j = 0;j <= len2;j++)   
        d[0][j] = j;   
    for(i = 1;i <= len1;i++)   
        for(j = 1;j <= len2;j++) {   
			if(pp[i -1] == qq[j-1]){
				d[i][j] = d[i-1][j-1];
			} else {
                int cost = caluPoint(pp[i], qq[j]);   
                int deletion = d[i-1][j] + 3;   
                int insertion = d[i][j-1] + 3;   
                int substitution = d[i-1][j-1] + cost;  
				d[i][j] = min(substitution, min(deletion, insertion));
			}
        }   
	return d[len1][len2];
}
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
    vector<string > candy = splitSpace(inStr, inStr);
    string target = candy[0];
    candy.erase(candy.begin());
    map<string, int> strScore;
    for (unsigned i = 0; i < candy.size(); i++)  
        strScore[candy[i]] = strDistance(candy[i], target);
    vector<pair<string, int> > strScoreVec;
    for (auto it = strScore.begin(); it != strScore.end(); it++)  
        strScoreVec.push_back(make_pair(it->first, it->second));

    sort(strScoreVec.begin(), strScoreVec.end(),
            [](const pair<string, int> &x, const pair<string, int> &y) -> int{
            return x.second < y.second;
            });

    for (auto it = strScoreVec.begin(); it < strScoreVec.begin() + 3; it++)  
        cout<<it->first<<" ";
    cout<<endl;
}
