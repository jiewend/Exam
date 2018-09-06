#include <iostream> 
#include <stdlib.h> 
#include <unistd.h> 
#include <time.h> 

using namespace std;

int RandomInRange(int start, int end){
	if(start > end)
		return -1;
	srand((unsigned)time(NULL));
	return rand() % (end - start) + start;
}

void Swap(int &a, int &b){
	int t;
	t = a; a = b; b = t;
}

int Partition(int *data, int length, int start, int end){
	if(data == nullptr || length <= 0 || start < 0 || end >= length)
		return -1;
	int index = RandomInRange(start, end);
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
	Swap(data[end], data[small]);
	return small;
}

bool CheckMoreThanHalf(int* nums, int len, int num){
	cout<<"num : "<<num<<endl;
	int times = 0;
	for (unsigned i = 0; i < len; i++) { 
		if(nums[i] == num)
			times++;
	} 
	cout<<"times : "<<times<<endl;
	if(times * 2 <= len)
		return false;
	else 
		return true;
}

int MoreThanHalfNum(int* num, int len){
	if(num == nullptr || len <= 0)
		return 0;
	int mid = len >> 1;
	int start = 0;
	int end = len - 1;
	int index = Partition(num, len, start, end);
	while(index != mid){
		if(index > mid){
			end = index - 1;
			index = Partition(num, len, start, end);
		} else {
			start = index + 1;
			index = Partition(num, len, start, end);
		}
	}
	int res = num[mid];
	if(!CheckMoreThanHalf(num, len, res)){
		res = 0;
		cout<<"less than half"<<endl;
	}
	return res;
}

int MoreThanHalfNum1(int* nums, int len){
	if(nums == nullptr || len <= 0)
		return 0;
	int res, times = 0;
	for (unsigned i = 0; i < len; i++) { 
		if(times == 0){
			res = nums[i];
			times++;
		}
		else {
			if(res == nums[i])
				times++;
			else
				times--;
		}
	} 
	if(!CheckMoreThanHalf(nums, len, res))
		res = 0;
	return res;
}
int main(){
	int num[11] = {1, 2, 2, 3, 2, 1, 1 ,1, 7, 7, 2};
	int res = MoreThanHalfNum1(num, 11);
	cout<<res<<endl;
}
