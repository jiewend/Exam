#include <iostream> 
#include "math.h" 

using namespace std;
int n_legal(string str1){
	// cout<<str1[0]<<" and "<<str1[strSize - 1]<<endl;
	if(str1.length() == 1)
		return 1;
	int n = 0;
	string str11, str12;
	for (unsigned i = 1; i <= str1.length(); i++) { 
		str11 = str1.substr(0, i);
		str12 = str1.substr(i, str1.length() - i);

		if((i == 0) && ((str12[0]) && str12.length() > 1))
			continue;
		if(str12[str12.length() - 1] == '0')
			continue;
		if((str11.length() > 1) && (str11[0] == '0'))
			continue;
		n++;
	} 
	return n;
}
int main(){

	string input;
	getline(cin, input);
	// bool a = is_legal(input, input.length(), 1);
	int num_legal = 0;
	string str1, str2;
	for (unsigned i = 1; i < input.length(); i++) { 
		str1 = input.substr(0, i);
		str2 = input.substr(i, input.length() - i);
		// cout<<n_legal(str1) << " and "<<n_legal(str2)<<endl;
		num_legal += n_legal(str1) * n_legal(str2);
		// cout<<str1<<" and "<<str2<<endl;
	} 
	cout<<num_legal<<endl;
}
