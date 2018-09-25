#include <iostream> 
#include <stdio.h>
#include <string.h> 
#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector> 
#include <math.h> 
#include <cstring> 

using namespace std;

class shape{
	public:
		virtual int area()=0;

};
class retangle:public shape{
	public:
		int a, b;
		void setLength(int x, int y){a=x;b=y;};
		int area(){return a*b;};
};

template <class T>

void S(T &x, T &y){
	T temp;
	temp = x;
	x = y;
	y = temp;
}

template <class T>
void SS(T A[], int n){
	int i, j;
	int min;
	for (unsigned i = 0; i < n-1; i++) { 
		min = i;
		for (unsigned j = i+1;   j< n; j++) { 
			if(A[j] < A[min]) min=j;
			S(A[i], A[min]);
		} 

	} 
}
class Base{
	public:
		int Bar(char x){
			return (int)(x);
		}
		virtual int Bar(int x){
			return (2 * x);
		}
};
class Derived:public Base{
	public:
		int Bar(char x){
			return (int)(-x);
		}
		int Bar(int x){
			return (x/2);
		}
};

class M {
	public:
		char * str;
		M(const char*s){
			str = new char[10];
			strcpy(str, s);
		}
		M &operator += (M a){

			// strcpy(str, a.str);
			// str = str + a.str;
			// strcmp(str, a.str);
			strcat(str, a.str);
			return *this;
		}
		void show(){
			cout<<str;
		}
};


struct A{
	void foo(){
		printf("foo");
	}
	virtual void bar(){
		printf("bar");
	}
	A(){
		bar();
	}
};
struct B:A{
	void foo(){
		printf("b_foo");
		}
	void bar(){
		printf("b_bar");
	}
};
typedef int (*pFun)(int, int);

float aa(int x){
    float res;
    if(x == 1)
        res = 1.0;
    else
        res = (1000000 - aa(x - 1)) / (1000000.0) + aa(x -  1);
    return res;
}

int main(){
    cout<<aa(1000000)<<endl;

}
