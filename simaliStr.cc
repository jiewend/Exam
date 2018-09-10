#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <istream> 
#include <sstream> 

using namespace std;

string format(string aa){
	string res("");
	for (unsigned i = 0; i < aa.size() - 1; ) { 
		char t = aa[i];
		int coun = 1;
		while (aa.c_str()[i + 1] == aa.c_str()[i] && (i + 1) < aa.size()){
			i++;
			coun++;
		}	
		stringstream iss;
		string temp;
		iss << coun;
		iss >> temp;
		res += temp;

		i++;
	} 
	
	return res;
}
int main(){
	string aa("jjjjaaabbcc");
	string res = format(aa);

	cout<<res<<endl;
	
}
