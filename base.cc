#include <iostream> 
using namespace std;

class base{
	public:
		virtual void func(){cout<<"base"<<endl;}
};

class derived:public base{
	public:
		void func(){cout<<"derived"<<endl;}
}p

int main(){
	derived dr;
	base *pbs = &dr;
	pbs->func();
}
