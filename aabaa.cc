#include <iostream> 
#include <string> 
#include <string.h> 
#include <vector> 
using namespace std;


int is_palindrome(const char *s) {
  int i, len;
  
  len = strlen(s);
  
  for(i = 0; i < (len /2); i++) {
    if (s[i] != s[len-i-1])
      return 0;
  }
  
  if (i >= len/2)
    return 1;
  else
    return 0;
}
int main(){

	string strin;
	cin>>strin;
	cout<<strin<<endl;
	vector<string> cutSoluting;


	for (unsigned cutNum = 0; cutNum < strin.size(); cutNum++) { 
		for (unsigned i = 0; i < strin.size(); i++) { 
		    TODO 
		} 
	} 

	cout<<is_palindrome(strin.c_str())<<endl;
}
