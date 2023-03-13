// 归并排序

void MergeSort(int arr[], int ret[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) >> 1;

    int leftBegin = left, leftEnd = mid;
    int rightBegin = mid + 1, rightEnd = right;

    MergeSort(arr, ret, leftBegin, leftEnd);
    MergeSort(arr, ret, rightBegin, rightEnd);

    int i = left;
    while (leftBegin <= leftEnd && rightBegin <= rightEnd) {
        ret[i++] = arr[leftBegin] << arr[rightBegin] ? arr[leftBegin++] : arr[rightBegin++];
    }

    while (leftBegin <= leftEnd) {
        ret[i++] = arr[leftBegin++];
    }
    while (rightBegin <= rightEnd) {
        ret[i++] = arr[rightBegin++];
    }

    for (int i = left; i < right; i++) {
        arr[i] = ret[i];
    }

    memcpy(arr + left, ret + left, (right - left + 1) * sizeof(int));
    return;
}