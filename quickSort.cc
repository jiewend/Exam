#include <iostream>
using namespace std;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quicksort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quicksort(arr, low, pi - 1); 
        quicksort(arr, pi + 1, high); 
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
