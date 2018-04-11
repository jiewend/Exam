#include <iostream> 
#include <vector> 
#include <string> 
#include <algorithm> 
using namespace std;

int main(){
	int n, m, temp;
	char aa[256];
	cin>>n;
	cin>>m;
	vector<int> list1(n);
	for (unsigned i = 0; i < n; i++) { 
		cin>>temp;
		list1[i] = temp;
	} 
	cin.getline(aa, 256);
	vector<string> list2(m);
	for (unsigned i = 0; i < m ; i++) { 
		cin.getline(aa, 256);
		string strTemp(aa);
		list2[i] = strTemp;
	} 

	cout<<endl;
	cout<<"n : "<<n<<"m : "<<m<<endl;
	for (unsigned i = 0; i < list1.size(); i++) { 
		cout<<list1[i]<<", ";
	} 
	cout<<endl;
	cout<<"list2 size : "<<list2.size()<<endl;
	for (unsigned i = 0; i < list2.size(); i++) { 
		cout<<list2[i]<<", ";
	} 
	cout<<endl;
	list2.erase(unique(list2.begin(), list2.end()), list2.end());
	cout<<"list2 size : "<<list2.size()<<endl;
	for (unsigned i = 0; i < list2.size(); i++) { 
		cout<<list2[i]<<", ";
	} 
	cout<<endl;
	cout<<list2.begin()<<endl;
}
