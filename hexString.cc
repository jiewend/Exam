#include <iostream> 
#include <vector> 
#include <string> 
#include <cstdlib> 
#include <math.h> 
#include<istream>
#include<sstream>
// #include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main(){
	string aa;
	string cc("");
	getline(cin, aa);
	for (unsigned i = 0; i < aa.size(); i++) { 
		int t =	int(aa.c_str()[i]);
		if( t>47 && t<58)
			cc += aa.c_str()[i];
	} 
	unsigned long long dd = atoll(cc.c_str());

	if (dd > (pow(2, 32)- 1)) 
		cout<<0<<endl;
	else{
		string ee;
		stringstream iss;
		iss << hex<<dd;
		iss >> ee;
		string ff;
		for (unsigned i = 0; i < ee.size(); i++) { 
			if((ee.c_str()[i] >96) && (ee.c_str()[i] < 123))
				ff += ee.c_str()[i] - 32;
			else
				ff += ee.c_str()[i];
		} 
		cout<<ff<<endl;

	}
}
