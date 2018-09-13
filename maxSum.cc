#include <iostream> 
#include <istream> 
#include <sstream> 
#include <string> 
#include <vector> 

using namespace std;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high, int *marker) 
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
			swap(&marker[i], &marker[j]);
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
	swap(&marker[i+1], &marker[high]);
    return (i + 1); 
} 

void quicksort(int arr[], int low, int high, int *marker) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high, marker); 
  
        // Separately sort elements before 
        // partition and after partition 
        quicksort(arr, low, pi - 1, marker); 
        quicksort(arr, pi + 1, high, marker); 
    } 
} 

template <typename T>
vector<T> splitSpaceT(std::string stri, T outType){
	string temp;
	vector<T>res;
	istringstream stream(stri);
	while (stream >> temp)
	{
		stringstream iss;
		iss << temp;
		T f;
		iss >> f;
		res.push_back(f);
	}
	return res;
}

int main(){

	string inStr;
	getline(cin, inStr);
	inStr = inStr.replace(inStr.find("-"), 1, " ");
	inStr = inStr.replace(inStr.find(":"), 1, " ");
	vector<string> inSplitStr = splitSpaceT(inStr, inStr);
	string arr1Str = inSplitStr[0];
	string arr2Str = inSplitStr[1];
	string KStr = inSplitStr[2];

	cout<<arr1Str<<"=="<<arr2Str<<"=="<<KStr<<endl;

	for (unsigned i = 0; i < arr1Str.size(); i++){  
		if(arr1Str[i] == ',')
			arr1Str[i] = ' ';
	}
	 
	for (unsigned i = 0; i < arr2Str.size(); i++)  {
		if(arr2Str[i] == ',')
			arr2Str[i] = ' ';
	}
	int a;
	vector<int> arrVec1 = splitSpaceT(arr1Str, a);
	vector<int> arrVec2 = splitSpaceT(arr2Str, a);
	vector<int> is1(arrVec1.size(), 1);
	vector<int> is2(arrVec2.size(), -1);

	vector<int> arr;
	arr.insert(arr.end(), arrVec1.begin(), arrVec1.end());
	arr.insert(arr.end(), arrVec2.begin(), arrVec2.end());
	vector<int> marker;
	marker.insert(marker.end(), is1.begin(), is1.end());
	marker.insert(marker.end(), is2.begin(), is2.end());

	int *arry = &arr[0];
	int *mark = &marker[0];

	for (unsigned i = 0; i < arrVec1.size() + arrVec2.size(); i++)  
		cout<<arry[i]<<" ";
	cout<<endl;
	for (unsigned i = 0; i < arrVec1.size() + arrVec2.size(); i++)  
		cout<<mark[i]<<" ";
	cout<<endl;
	// quickSort(arry, 0, arrVec1.size() + arrVec2.size(), mark);
	quicksort(arry, 0, arrVec1.size() + arrVec2.size() - 1, mark);

	for (unsigned i = 0; i < arrVec1.size() + arrVec2.size(); i++)  
		cout<<arry[i]<<" ";
	cout<<endl;
	for (unsigned i = 0; i < arrVec1.size() + arrVec2.size(); i++)  
		cout<<mark[i]<<" ";
	cout<<endl;
}
