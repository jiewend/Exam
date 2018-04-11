#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 
 #include <stdlib.h>

using namespace std;


vector<int> genArray(int n)
{
	vector<int> array1;
 int i,j;
 for(i=1;i!=n+1;i++)
 {

	 string num;
  for(j=1;j!=i+1;j++)
  {

	 stringstream ss; 
	 string strt;
	 ss<<j;
	 ss>>strt;
	 num = num + strt;
  }
  // cout<<num;
  // cout<<endl;
 }

 return array1;
}

int main(){

	int l, r;
	cin>>l;
	cin>>r;
	vector<int> array1(r);
	int i,j;
 for(i=1;i!=r+1;i++)
 {
	 cout<<"j : "<<j;

	 string num;
	 int number;
  for(j=1;j!=i+1;j++)
  {

	 stringstream ss; 
	 string strt;
	 ss<<j;
	 ss>>strt;
	 num = num + strt;
	 number = atoi(num.c_str());
	array1[j] = number;
  }
  cout<<array1[i];
  
  cout<<endl;
 }

 for (unsigned i = 0; i < array1.size(); i++) { 
	 cout<<array1[i]<<endl;
 } 


}
