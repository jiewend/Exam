#include <iostream>
using namespace std;
typedef int (*pFun)(int, int);

int Max(int a , int b){
	return a > b ? a : b;
}

int Min(int a, int b){
	return a < b ? a : b;
}

int Result(pFun fun, int a, int b){
	return (*fun)(a, b);

}

int main(){
	int a = 3;
	int b = 4;
	cout<<" "<<endl;
	cout<<Result(Max, a, b)<<endl;
}
