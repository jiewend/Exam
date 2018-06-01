#include <iostream> 
#include <vector> 
#include <cmath> 

using namespace std;

int is_palindrome(vector<char> s) {
  int i, len = s.size();
  for(i = 0; i < (len /2); i++) {
    if (s[i] != s[len-i-1])
      return 0;
  }
  if (i >= len/2)
    return 1;
  else
    return 0;
}

vector<char> printbinary(const unsigned long long val)
{
	vector<char> res;
	int fla = log10(val) / log10(2);
    for(int i = fla; i >= 0; i--)
    {
        if(val & (1 << i)){
			res.push_back('1');
			// cout<<'1';
		}
        else{
			res.push_back('0');
			// cout<<'0';
		}
    }
	return res;
}  

int main(){
	unsigned long long N;
	cin>>N;
	int coun = 0;
	// printbinary(N);
	for (unsigned i = 0; i < N + 1; i++) { 
		if(is_palindrome(printbinary(i)) == 1)
			coun++;
	} 
	cout<<coun<<endl;
}
