#include <iostream>
using namespace std;


int coun = 0;
void quickSort(int *arr,int l,int r)
{
	for (unsigned i = 0; i < r; i++)  
		cout<<arr[i]<<" ";
	cout<<endl;
	int i,j,temp;
	if(l<r)
	{
		i=l;
		j=r;
		while(1)
		{
			while(i<=r&&arr[i] == 0)
				i++;
			while(j>=l&&arr[j] == 1)
				j--;
			if(i>=j){
				cout<<"i : "<<i<<" j : "<<j<<endl;
				break;
			}
			else
			{
				cout<<"before swap"<<endl;
				for (unsigned jj = 0; jj < r; jj++)  
					cout<<arr[jj]<<" ";
				cout<<endl;
				cout<<"["<<i<<"]"<<arr[i]<<"< "<<" >"<<arr[j]<<"["<<j<<"]"<<endl;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp; 
				cout<<"after swap"<<endl;
				for (unsigned k = 0; k < r; k++)  
					cout<<arr[k]<<" ";
				cout<<endl;
				coun++;
			}
		}
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
	
	
	quickSort(arr, 0, len - 1);

	for (unsigned i = 0; i < len; i++)  
		cout<<arr[i]<<" ";
	cout<<endl;
	cout<<coun<<endl;

}
