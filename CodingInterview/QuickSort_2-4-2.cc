#include <iostream> 
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h> 

using namespace std;

int RandomInRange(int start, int end){
	if(start > end)
		return -1;
	// cout<<(unsigned)time(NULL)<<endl;
	srand((unsigned)time(NULL));
	return rand() % (end - start) + start;
}

void Swap(int &a, int &b){
	int temp;
	temp = a; a = b; b = temp;
}
int Partition(int* data, int length, int start, int end){
	if(data == nullptr || length <= 0 || start < 0 || end >= length)
		return 0;
	int index = RandomInRange(start, end);
	cout<<"index : "<<index<<endl;
	Swap(data[index], data[end]);
	int small = start - 1;
	for(index = start; index < end; ++index){
		if(data[index] < data[end]){
			++small;
			if(small != index)
				Swap(data[small], data[index]);
		}
	}
	++small;
	Swap(data[small], data[end]);
	return small;
}
void QuickSort(int* data, int length, int start, int end){
	if(start == end)
		return;
	int index = Partition(data, length, start, end);
	if(index > start)
		QuickSort(data, length, start, index - 1);
	if(index < end)
		QuickSort(data, length, index + 1, end);
}

int main(){
	int arr[10] = {1, 4, 3, 2, 6 ,5 ,9 , 8, 7, 0};
	for (unsigned i = 0; i < 10; i++)  
		cout<<arr[i]<<", ";
	cout<<endl;
	QuickSort(arr, 10, 0, 9);
	for (unsigned i = 0; i < 10; i++)  
		cout<<arr[i]<<", ";
	cout<<endl;
}
