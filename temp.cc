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
