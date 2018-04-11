#include <iostream> 
using namespace std;

int foo(int n){
	if(n<2)
		return n; 
	else
		return 2*foo(n-1) + foo(n-2);
}

int main(){
	cout<<foo(5);

}
