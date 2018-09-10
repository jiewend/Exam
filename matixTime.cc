#include <iostream> 
#include<istream>
#include<sstream>
#include <vector> 
#include <numeric> 

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

bool leftEquRight(vector<int> l, vector<int> r){
	int matSize = l.size();
	vector<int> oo(matSize, 1);
	int pp = 0;
	int rr = 0;
	vector<int>::iterator itl = l.begin();
	int tt;
	int count1 = 0;
	for (unsigned i = 0; i < matSize; i++) { 
		tt = r[i];
		r[i] = -1;
		for (unsigned j = 0; j < matSize; j++) { 
			if(l[i] == r[j]){
				l[i] = -1;
				r[j] = -1;
				
				oo[i] = 0;
				break;
			} 
		} 
		r[i] = tt;

	} 
	if(accumulate(oo.begin(), oo.end(), 0) > 2)
		return false;
	else
		return true;
}

int main(){
	int N;
	string temp;
	stringstream iss;
	getline(cin, temp);
	iss<<temp;
	iss>>N;
	int res[N];
	for (unsigned i = 0; i < N; i++) { 
		// cout<<"N : "<<i<<endl;
		int matixNum;
		string tt;
		stringstream iss1;
		getline(cin, tt);
		iss1 << tt;
		iss1 >> matixNum;
		vector<int> left;
		vector<int> right;
		vector<int> aa;
		for (unsigned j = 0; j < matixNum; j++) { 
			// cout<<"matixNum : "<<j<<endl;
			string t1;
			getline(cin, t1);
			aa = splitSpace(t1);
			left.push_back(aa[0]);
			right.push_back(aa[1]);
		}
		if(leftEquRight(left, right))
			res[i] = 1;
				// cout<<"yes"<<endl;
			else
			res[i] = 0;
				// cout<<"no"<<endl;
	} 
	for (unsigned i = 0; i < N; i++) { 
		if(res[i] == 1)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	} 
}
