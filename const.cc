#include <iostream>
using namespace std;

int abc(const int a){
	// return a++;
}

int main(){
	const int a = 10;
	int const b = 9;
	int k = 0, j = 0;
	for (unsigned i = 0; i < 10; i++) { 
		cout<<i<<endl;
		// cout<<k++<<", "<<++j<<endl;
	} 
	for (unsigned i = 0; i < 10; ++i) { 
		cout<<i<<endl;
		// cout<<k++<<", "<<++j<<endl;
	} 
}
