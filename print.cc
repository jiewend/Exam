#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
using namespace std;

class Foo{
	public:
		virtual void func1(){}
		void func2(){}
		int data1;
		static int data2;
};
int Foo::data2 = 1;


int main(){
	char* string1 = "tencent2018";
	int size1 = sizeof(string1);
	int size2 = sizeof(*string1);
	char string2[100] = "tentcent2018";
	int size3 = sizeof(string2);

	int start = 1;
	int end = 10;
	cout<<(16>>3)<<endl;

	char str1[10];
	strcpy(str1, "0123456789");

	cout<<size1<<" , "<<size2<<", "<<size3<<endl;
	cout<<*string1<<endl;


}

