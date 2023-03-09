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