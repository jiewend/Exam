#include<iostream>
#include<string>
#include<istream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string temp;
	cin >> temp;
	int size = temp.size();
	vector<int>res;
	for (int i = 0; i < size; i++)
	{
		stringstream iss;
		iss << temp[i];
		int f;
		iss >> f;
		res.push_back(f);
	}
	sort(res.begin(), res.end());
	vector<int> v1;
	v1.assign(res.begin(), res.end());
	vector<int > count1(10);
	cout<<"count"<<endl;
	for (unsigned i = 0; i < 10; i++) { 
		count1[i] = count(v1.begin(), v1.end(), i);
		cout<<count1[i];
	} 
	if(count(count1.begin(), count1.end(), 0))


			
}
