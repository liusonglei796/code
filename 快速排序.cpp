
//当前quickSort函数定义的返回值类型是vector<int>，
//但在函数内部其实是直接对传入的vector进行原地修改来实现排序，
//并没有真正返回一个新的vector。所以返回值类型设置为void更合适
void quickSort(int arr[], int left, int right) {
    if(left >=right) return;
    
    
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    
    while(i <= j) {
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if(i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}