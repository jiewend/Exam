#include <iostream>
using namespace std;

void quickSort(int *arr,int l,int r)
{
	//此处编写代码实现快速排序
	int i,j,x,temp;
	if(l<r)
	{
		i=l;
		j=r;
		x=arr[(l+r)/2]; 
		//以中间元素为轴 
		while(1)
		{
			while(i<=r&&arr[i]<x)
				i++;
			while(j>=l&&arr[j]>x)
				j--;
			if(i>=j){ //相遇则跳出 
				cout<<"i : "<<i<<" j : "<<j<<endl;
				break;
			}
			else
			{
				cout<<"["<<i<<"]"<<arr[i]<<"< "<<x<<" >"<<arr[j]<<"["<<j<<"]"<<endl;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp; 
				//交换 
			}
		}
		quickSort(arr,l,i-1); //对左半部分进行快排 
		quickSort(arr,j+1,r); //对右半部分进行快排 
	}
}

int main(){
	cout<<"输入数组长度"<<endl;
	int len;
	cin>>len;
	cout<<"输入数组，以空格分隔"<<endl;
	int arr[len];
	for (unsigned i = 0; i < len; i++)  
	    cin>>arr[i];
	
	
	quickSort(arr, 0, len);

	for (unsigned i = 0; i < len; i++)  
		cout<<arr[i]<<" ";
	cout<<endl;

}
