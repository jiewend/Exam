#include <iostream> 
#include <string.h> 
#include <malloc.h> 
#include <stdlib.h> 
#include <string> 
using namespace std;

void fun(int x){
	if(x / 2)
		fun(x / 2);
	cout<<x;
}

void text1(){
	char string[10];
	char *str1 = "0123456789";
	strcpy(string, str1);
	for (unsigned i = 0; i < 10; i++) { 
	    cout<<string[i];
	} 
	cout<<endl;
}

void test1(){
	char str[] = "world";cout<<sizeof(str)<<": ";
	char *p = str; cout<<sizeof(p)<<": ";
	char i = 10;cout<<sizeof(i)<<": ";
	void *pp = malloc(10);cout<<sizeof(p)<<endl;
}

void temp(){
	int i = 0,sum = 1;
	do{
		sum+=i++;
	}while(i<5);
	printf("%d\n", sum);
}

void temp1(){
	string strSrc = "0123456789";
	string strDest = "";
	int nVar1;
	float fVar2;
	strDest = strSrc.left(strSrc.GetLength() - 2);
	strDest = strDest.Mid(0, 4);
	nVar1 = atoi(strDest);
	fVar2 = atof(strDest);
	cout<<nVar1<<endl;
	printf("%.3f\n", nVar1);
}
int main(){
	// fun(10);
	// text1();
	// test1();
	// temp();
	temp1();
}
