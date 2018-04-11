#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

int main(){
	int data[10] = {13, 45, 78, 2, 46, 789, 12, 78, 2, 13};
	vector<int> array1(10);
	for (unsigned i = 0; i < 10; i++) { 
		array1[i] = data[i];
		cout<<array1[i]<<", ";
	} 
	cout<<endl;
	sort(array1.begin(), array1.end());
	array1.erase(unique(array1.begin(), array1.end()), array1.end());
}
