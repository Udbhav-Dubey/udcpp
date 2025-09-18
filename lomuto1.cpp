void partition(int arr[],int n){
    int pivot=arr[n-1];
    int i=-1;
    for (int j=0;j<n;j++){
        if (arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[n-1]);
}
