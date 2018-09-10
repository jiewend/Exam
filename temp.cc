#include <iostream> 
#include <stdio.h>
#include <string.h> 
#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector> 

using namespace std;


void quickSort(int *arr, int l, int r){
	int i, j, x, temp;
	if (l < r) { 
		i = l;j = r;x = arr[(r + l) / 2];
		while (1) { 
			while(i <= r && arr[i] < x)
				i++;
			while(j >= l && arr[j] > x)
				j--;
			if(i >= j)
				break;
			else{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

		}
	   quickSort(arr, l, i-1);	
	   quickSort(arr, j + 1, r);
	} 
}
class shape{
	public:
		virtual int area()=0;

};
class retangle:public shape{
	public:
		int a, b;
		void setLength(int x, int y){a=x;b=y;};
		int area(){return a*b;};
};

template <class T>

void S(T &x, T &y){
	T temp;
	temp = x;
	x = y;
	y = temp;
}

template <class T>
void SS(T A[], int n){
	int i, j;
	int min;
	for (unsigned i = 0; i < n-1; i++) { 
		min = i;
		for (unsigned j = i+1;   j< n; j++) { 
			if(A[j] < A[min]) min=j;
			S(A[i], A[min]);
		} 

	} 
}
int main(){
	vector<int> vint(1);
	cout<<vint[1]<<endl;;
	cout<<vint.at(1);


}
