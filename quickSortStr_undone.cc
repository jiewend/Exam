#include <iostream> 
using namespace std;

bool ifin(char * vowel, char t){
	for (unsigned i = 0; i < 5; i++) 
		if(t == vowel[i])
			return true;
	return false;

}
void quickSort(char *arr, int l){
	char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
	int i = 0, j = l - 1;
	while(i<j){
		for( ; ; )
			if(ifin(vowel, arr[i])){
				i++;
				break;
			} else 
				i++;
		for( ; ; )
			if(ifin(vowel, arr[j])){
				j--;
				break;
			}else
				j--;
		cout<<i<<"  "<<j<<endl;
		char temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;

	}

	
}

int main(){
	char aa[6] = {"hello"};
	for (unsigned i = 0; i < 9; i++) 
		cout<<aa[i];
	cout<<endl;
	// getline(cin, aa);
	quickSort(aa, 9); 

	for (unsigned i = 0; i < 9; i++) 
		cout<<aa[i];
	cout<<endl;

}
