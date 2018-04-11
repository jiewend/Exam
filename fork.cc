#include <iostream> 
#include <unistd.h> 
using namespace std;

int main(){
	fork();
	fork();
	fork();
	cout<<"hello"<<endl;

}
