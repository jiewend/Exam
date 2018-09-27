#include <iostream>
using namespace std;

int arr[] = {1,2,0,0,2,1,2,1,1,0};
int iLength;
int iZero, iOne, iTwo;
void swap(int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
void sort()
{
	while(arr[iZero] == 0)
	{
		iZero++;
		iOne++;
	}
	while(arr[iTwo] == 2)
	{
		iTwo--;
	}
	while(iOne <= iTwo)
	{
		if (arr[iOne]==2)
		{
			swap(iOne, iTwo);
			iTwo--;
			while(arr[iTwo]==2)
			{
				iTwo--;
			}
		}
		while(arr[iOne]==1)
		{
			iOne++;
		}
        cout<<iZero<<" "<<iOne<<" "<<iTwo<<endl;
		if (arr[iOne] == 0)
		{
			swap(iOne, iZero);
			iZero++;
			iOne++;
		}
	}
}

int main()
{
	iLength = sizeof(arr) / sizeof(int);
	iZero=0;
	iOne=0;
	iTwo=iLength-1;
	
	cout<<"Before..."<<endl;
	for (int i=0;i<iLength;i++)
	{
		cout<<arr[i]<<" ";
	}
    cout<<endl;
	sort();
	cout<<endl<<"After..."<<endl;
	for (int i=0;i<iLength;i++)
	{
		cout<<arr[i]<<" ";
	}
    cout<<endl;
	return 0;
}
