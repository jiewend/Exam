void bubbleSort(int arr[], int n)
{
    for(int i = 0;i < n;i++){  
        //比较两个相邻的元素   
        for(int j = 0;j < n-i-1;j++){  
            if(arr[j] > arr[j+1]){  
                int t = arr[j];  
                arr[j] = arr[j+1];  
                arr[j+1] = t;
            }
        }
    }
}
