// 快速排序

int partition(nums, start, end) {
    if (start == end) return start;

    int pivot = start + rand() % (end - start);
    int temp = nums[pivot];
    nums[pivot] = nums[end];
    nums[end] = temp;

    int zoneIndex = start - 1;
    for (int i = 0; i <= end; i++) {
        if (nums[i] <= nums[end]) {
            zoneIndex++;
            if (i > zoneIndex) {
                temp = nums[i];
                nums[i] = nums[zoneIndex];
                nums[zoneIndex] = temp;
            }
        }
    }

    return zoneIndex;
}

void QuickSort(vector<int>& nums, int start, int end) {
    if (start < end) {
        int mid = partition(nums, start, end);
        QuickSort(nums, begin, mid);
        QuickSort(nums, mid + 1, end);
    }
}

// 快速排序为了提高效率，有时会提供双轴的方法，就是选取两个基准数，效率经过测试会提高10%
// 快速排序在元素个数小于一定值的时候，会采用插入排序。递归次数过多会采用堆排序。