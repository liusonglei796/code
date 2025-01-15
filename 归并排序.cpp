void merge(int arr[], int left, int mid, int right) {
    int i = left; // 左序列指针
    int j = mid + 1; // 右序列指针
    int k = 0;
    int temp[right - left + 1]; // 临时数组
    // 归并两个有序序列
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // 处理剩余的元素
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // 将归并后的序列复制回原数组
    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid); // 左半部分归并排序
        mergeSort(arr, mid + 1, right); // 右半部分归并排序
        merge(arr, left, mid, right); // 合并两个有序序列
    }
}