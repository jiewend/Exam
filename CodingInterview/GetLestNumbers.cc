#include <iostream> 
#include <stdlib.h> 
#include <unistd.h> 
#include <time.h> 

using namespace std;

int RandomInRange(int start, int end){
	if(start > end)
		return -1;
	srand((unsigned)time(NULL));
	return rand() % (start - end) + start;
}

void Swap(int &a, int &b){
	int t;
	t = a; a = b; b = t;
}
int Partition(int* nums, int len, int start, int end){
	if(nums == nullptr || len <= 0 || start < 0 || end > len)
		return -1;
	int index = RandomInRange(start, end);
	cout<<index<<endl;
	Swap(nums[index], nums[end]);
	int small = start - 1;
	for(index = start; index < end; index++){
		if(nums[index] < nums[end]){
			small++;
			if(small != index)
				Swap(nums[small], nums[index]);
		}
	}
	small++;
	Swap(nums[small], nums[end]);
	return small;
}

void GetLeastNumbers(int* nums, int len, int* LeastK, int k){
	if(nums == nullptr || len <= 0 || k > len || k <= 0)
		return;
	int start = 0;
	int end = len - 1;
	int index = Partition(nums, len, start, end);
	while(index != k){
		if(index < k){
			start = index + 1;
			index = Partition(nums, len, start, end);
		} else {
			end = index - 1;
			index = Partition(nums, len, start, end);
		}
			
	}
	for (unsigned i = 0; i < k; i++) 
		cout<<nums[i]<<", ";
	cout<<endl;
}

int main(){
	// int num[11] = {1, 2, 2, 3, 2, 1, 1 ,1, 7, 7, 2};
	int num[11] = {1, 2, 5, 1, 9, 4, 7 ,2, 5, 7, 2};
	
	// GetLeastNumbers(num, 11, 0, 10);
	for (unsigned i = 0; i < 11; i++) 
		cout<<num[i]<<", ";
	cout<<endl;
	int index = Partition(num, 11, 0, 10);
	for (unsigned i = 0; i < 11; i++) 
		cout<<num[i]<<", ";
	cout<<endl;

}
