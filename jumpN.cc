#include <iostream> 
using namespace std;

int jumpFloorII(int number) {
	number--;
	int res[number + 1] = {0}; 
	res[0] = 1; res[1] = 2;
	if (number < 2)
		return res[number];

	for(int i = 1; i < number; i++){
		for(int j = 0; j < i + 1; j++){
			cout<<res[i + 1]<<endl;
			cout<<j<<endl;
			res[i + 1] = res[j] + res[i + 1];
		}
	}
	for (unsigned i = 0; i < number + 2; i++) { 
		cout<<res[i]<<", ";
	} 
	return res[number];
}

int main(){
	jumpFloorII(3);
}
