// 堆排序

int[] HeapSort(int array[]) {
    len = array.size();
    if (len < 1) return array;
    // 构建最大堆
    BuildMaxHeap(array);
    // 循环将堆首位(最大值)与未排序数据末位交换，然后重新调整为最大堆
    while (len > 0) {
        swap(array[0], array[len - 1]);
        len--;
        AdjustHeap(array, 0);
    }
    return array;
}

void BuildMaxHeap(int array[], int len) {
    for (int i = (len/2 - 1); i >= 0; i--) {
        AdjustHeap(array, i);
    }
}

void AdjustHeap(int array[], int i, int len) {
    int maxIndex = i;
    int left = 2 * i + 1;
    int right = 2 * (i + 1);
    // 如果有左子树，且左子树大于父节点，则将最大指针指向左子树
    if (left < len && array[left] > array[maxIndex]) {
        maxIndex = left;
    }
    // 如果有右子树，且右子树大于父节点且大于左子树，则将最大指针指向右子树
    if (right < len && array[right] > array[maxIndex] && array[right] > array[left]) {
        maxIndex = right;
    }
    // 如果父节点不是最大值，则将父节点与最大值交换，并且递归调整与父节点交换的位置
    if (maxIndex != i) {
        swap(array[maxIndex], array[i]);
        AdjustHeap(array, maxIndex);
    }
}