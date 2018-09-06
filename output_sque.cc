#include <iostream> 
#include "math.h" 

using namespace std;


// abcdefghijklnmop


int main(){
	string input;
	getline(cin, input);
	int sque_size = (input.length() + 4) / 4;


	for (unsigned i = 0; i < sque_size; i++) { 
		if(i == 0){
			for (unsigned j = 0;  < sque_size; j++) { 
				cout<<input[j];
			} 
			cout<<endl;
		}
		if (i == sque_size - 1){
			for (unsigned j = 0;  j < sque_size; j++) { 
				// undone


			} 
		}

	} 


	cout<<"length : "<<input.length()<<endl;
	cout<<sque_size<<endl;

}
